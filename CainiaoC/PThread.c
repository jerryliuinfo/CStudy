/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-06 09:48:29
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-06 15:59:30
 * @FilePath: /Hello/CainiaoC/PThread.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

/**
 * pthread 是 POSIX 线程（POSIX Threads，通常简称为 Pthreads）库的一部分，
 * 它提供了多线程编程的API。pthread 允许你创建和管理线程，这些线程可以并行执行，从而提高程序的效率和性能。
 *
 *
 * pthread_t：线程标识符，用于区分不同的线程。
    pthread_create：创建新线程。
    pthread_join：等待线程结束。
    pthread_detach：分离线程，线程结束后资源自动回收。
    pthread_exit：线程退出。
    pthread_mutex_t：互斥锁，用于同步线程间的访问。
    pthread_mutex_lock 和 pthread_mutex_unlock：锁定和解锁互斥锁。
    pthread_cond_t：条件变量，用于线程间的同步。
    pthread_barrier_t：屏障，用于线程间的同步。
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stddef.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

pthread_t threads[2];
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *threadFunc(void *arg)
{
    // printf("Hello from thread:%ld\n", pthread_self());
    printf("Hello from thread %p\n", pthread_self());

    return NULL;
}

void pthreadCreateTest()
{
    pthread_t thread1, thread2;

    // 创建两个线程 第1个参数，线程的句柄，第2个参数：线程参数，一般传 Null, 第 3 个参数为要执行的函数，第 4 个参数为要传给第 3个参数所在函数的参数
    if (pthread_create(&thread1, NULL, threadFunc, NULL) != 0)
    {
        perror("Failed to create thread1");
        return;
    }
    if (pthread_create(&thread2, NULL, threadFunc, NULL) != 0)
    {
        perror("Failed to create thread2");
        return;
    }
    // 第一个参数：线程的名字，也就是线程句柄 pthrad_t， 第 二个参数: 线程的返回值放到哪个地址
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
}

/**
 * 用于等待一个线程结束。当你创建一个线程后，它可以并行地执行其任务。如果你想在主线程
 * （或任何其他线程）中等待这个线程完成其工作，你可以使用 pthread_join 函数。
 * 参数
        thread：要等待的线程的线程标识符，由 pthread_create 函数返回。
        retval：一个指向 void* 类型的指针的指针，用于存储线程的退出值。如果不需要线程的退出值，这个参数可以设置为 NULL。
 * 返回值
        如果成功，返回 0。
        如果失败，返回一个错误码。

        注意事项
        死锁：如果不当使用 pthread_join，可能会导致死锁。例如，如果两个线程相互等待对方结束，它们将永远阻塞。

        资源回收：使用 pthread_join 可以确保线程资源被正确回收，避免资源泄漏。

        线程退出值：如果线程需要返回值，应该使用 pthread_exit 函数，并确保调用 pthread_join 来获取退出值。

        多次加入：一旦线程被 pthread_join 回收，它就不能再被加入。尝试对同一个线程进行多次 pthread_join 将导致错误。
 *
 */

void *threadFunction(void *arg)
{
    printf("Thread is running.\n");
    sleep(2);
    // 线程退出
    pthread_exit(NULL);
}
void pthreadJoinTest()
{
    pthread_t threadId;
    int result;
    result = pthread_create(&threadId, NULL, threadFunction, NULL);
    if (result != 0)
    {
        perror("pthread create failed\n");
        return;
    }
    // 如果没有 pthread_join 这行代码，会先输出 Thread has finished， 后输出 Thread is running
    result = pthread_join(threadId, NULL);
    if (result != 0)
    {
        perror("pthread join failed\n");
        return;
    }
    printf("Thread has finished.\n");
}

#define MAX 10

int number = 0;
void *threadFun1Mutex(void *args)
{
    printf("thrad1 starting running\n");
    for (size_t i = 0; i < MAX; i++)
    {
        printf("thread1 number:%d\n", number);
        pthread_mutex_lock(&mutex);
        printf("thread1 %p got the mutex lock \n", pthread_self());
        number++;
        pthread_mutex_unlock(&mutex);
    }

    return NULL;
}

void *threadFun2Mutex(void *args)
{
    printf("thrad2 starting running\n");
    for (size_t i = 0; i < MAX; i++)
    {
        printf("thread2 number:%d\n", number);
        pthread_mutex_lock(&mutex);
        printf("thread2 %p got the mutex lock \n", pthread_self());
        number++;
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

/**
 * pthread_mutex_t 是 POSIX 线程库（Pthreads）中用于线程同步的一种数据类型。它代表了一个互斥锁（mutex），
 * 可以用来保护共享数据不被多个线程同时访问，从而避免竞态条件和数据不一致的问题。
 *
 * 互斥锁的作用
        互斥锁是一种同步机制，它确保任何时候只有一个线程可以持有锁并访问受保护的资源。当一个线程获取了互斥锁，其他尝试获取同一互斥锁的线程将被阻塞，直到锁被释放。

    互斥锁的操作
        使用 pthread_mutex_t 通常涉及以下操作：

        初始化：在线程使用互斥锁之前，需要对其进行初始化。
        锁定：当线程需要访问共享资源时，它会尝试锁定互斥锁。
        解锁：当线程完成对共享资源的访问后，它会释放互斥锁。
        销毁：当互斥锁不再需要时，应该销毁它以释放资源。
 *
 */
void pthreadMutexTest()
{
    printf("pthreadMutexTest start ----->\n");
    /**
     * memset 函数是用来设置内存块的内容的。它定义在 <string.h> 头文件中，可以用来快速初始化或重置一段内存区域。
     * 参数
        s：指向要设置的内存块的指针。
        c：是要设置的值，用来填充内存块。这个值会被转换为无符号字符，然后扩展到一个字节的大小。
        n：是要设置的字节数。
     */
    memset(&threads, 0, sizeof(threads));

    pthread_create(&threads[0], NULL, threadFun1Mutex, NULL);
    pthread_create(&threads[1], NULL, threadFun2Mutex, NULL);
    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);
    printf("pthreadMutexTest finished----->\n");
    pthread_mutex_destroy(&mutex);
}

// 用于通知的条件
int ready = 0;

void *producerFunc(void *arg)
{
    printf("producerFunc run ready:%d\n", ready);

    pthread_mutex_lock(&mutex);
    // 模拟生产者耗时
    sleep(3);
    // 生产者准备消费数据
    ready = 1;
    // 唤醒消费者（调用 pthread_cond_wait()而进入睡眠的线程）
    pthread_cond_signal(&cond);

    pthread_mutex_unlock(&mutex);

    return NULL;
}

void *consumerFunc(void *arg)
{
    printf("consumerFunc run ready:%d\n", ready);
    pthread_mutex_lock(&mutex);

    // 一致等待生产者把 ready 改为 1
    while (ready == 0)
    {
        // 等待条件变量的特殊条件发生
        pthread_cond_wait(&cond, &mutex);
    }
    // 消费者消费数据
    printf("Consumer process data\n");
    pthread_mutex_unlock(&mutex);
    return NULL;
}

/**
 * pthread_cond_wait 函数用于线程间的同步，它允许一个线程在特定条件下挂起执行，直到另一个线程发出信号。
 *
 *
 */
void pthreadConditionTest()
{
    printf("\n pthreadConditionTest start ------>\n");
    pthread_t producer, consumer;

    pthread_create(&consumer, NULL, consumerFunc, NULL);

    pthread_create(&producer, NULL, producerFunc, NULL);

    pthread_join(producer, NULL);
    pthread_join(consumer, NULL);

    pthread_mutex_destroy(&mutex);
    pthread_cond_destroy(&cond);
    printf("\n pthreadConditionTest end ------>\n");
}

int main(int argc, char const *argv[])
{
    pthreadCreateTest();
    pthreadJoinTest();
    pthreadMutexTest();
    pthreadConditionTest();

    return 0;
}
