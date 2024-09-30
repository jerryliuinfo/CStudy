#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stddef.h>
#include <pthread.h>
#include <unistd.h> // 包含 usleep
#include <time.h>
#include <errno.h>

/**
 * pthread_cond_timedwait 函数是 POSIX 线程（Pthreads）库中的一个函数，它用于使线程在指定的时间内等待某个条件变量。
 * 如果在指定的时间内条件变量被触发，线程将继续执行；如果超时，线程将被唤醒并继续执行。
 *
 * 函数原型:
 * int pthread_cond_timedwait(pthread_cond_t *restrict cond,
                          pthread_mutex_t *restrict mutex,
                          const struct timespec *restrict abstime);
参数
 * cond：指向条件变量的指针。
    mutex：指向与条件变量关联的互斥锁的指针。
    abstime：指向 struct timespec 结构的指针，该结构指定了绝对超时时间。

    返回值
    成功时返回 0。
    如果超时，返回 ETIMEDOUT。
    如果发生错误，返回其他错误码。
 *
 */

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;

void *waiter(void *args)
{

    struct timespec ts;
    clock_gettime(CLOCK_REALTIME, &ts);
    // 当前时间 5 秒后
    ts.tv_sec += 5;
    pthread_mutex_lock(&lock);
    printf("waiter run, begin wait\n");
    // 等待信号，最多等待 5s
    int result = pthread_cond_timedwait(&cond, &lock, &ts);
    printf("pthread_cond_timedwait result:%d\n", result);
    if (result == ETIMEDOUT)
    {
        printf("Condition wait time out.\n");
    }
    else
    {
        printf("Condition was signaled\n");
    }
    pthread_mutex_unlock(&lock);
    return NULL;
}

void *notify(void *args)
{
    printf("notify run, begin sleep\n");

    sleep(6);
    pthread_mutex_lock(&lock);

    printf("notify send signal\n");

    // 发送信号
    pthread_cond_signal(&cond);
    pthread_mutex_unlock(&lock);
    return NULL;
}

int main(int argc, char const *argv[])
{
    pthread_t t1, t2;
    pthread_create(&t1, NULL, waiter, NULL);
    pthread_create(&t2, NULL, notify, NULL);

    //第一个参数：线程的名字，也就是线程句柄 pthrad_t， 第 二个参数: 线程的返回值放到哪个地址
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}
