#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stddef.h>
#include <pthread.h>
#include <time.h>
#include <sys/time.h>

void *fun1(float a, float b)
{
    float *result;
    result = (float *)malloc(sizeof(float) * 2);
    for (int i = 0; i < 10000000; i++)
    {
        result[0] = a + b;
        result[1] = a - b;
    }
    return result;
}

void *fun2(float a, float b)
{
    float *result;
    result = (float *)malloc(sizeof(float) * 2);
    for (int i = 0; i < 10000000; i++)
    {
        result[0] = a + b;
        result[1] = a - b;
    }
    return result;
}

/**
 * 常规方式运行两个线程耗时
 */
void normal_thread_cost_time()
{
    float a = 1.1;
    float b = 2.2;

    float *result1, *result2;

    result1 = (float *)malloc(sizeof(float) * 2);
    result2 = (float *)malloc(sizeof(float) * 2);

    struct timeval start, end;

    float during;
    // 计算开始的时候,获取当前时间点
    gettimeofday(&start, NULL);
    // 先执行 fun1 才会执行 fun2
    result1 = fun1(a, b);
    result2 = fun2(a, b);

    // 计算结束的时候,获取当前时间点
    gettimeofday(&end, NULL);

    during = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
    printf("result1[0]:%f,result1[1]:%f\n", result1[0], result1[1]);
    printf("result2[0]:%f,result1[1]:%f\n", result2[0], result2[1]);
    printf("during:%f\n", during);
}

struct Args
{
    float a;
    float b;
};

void *pthread_func1(void *arg)
{
    struct Args *args = (struct Args *)arg;
    return fun1(args->a, args->b);
}

void *pthread_func2(void *arg)
{
    struct Args *args = (struct Args *)arg;
    return fun2(args->a, args->b);
}

void pthread_cost_time()
{
    float a = 1.1;
    float b = 2.2;

    struct Args param;
    param.a = 1.1;
    param.b = 2.2;

    pthread_t t1, t2;
    float *result1;
    float *result2;
    // 存储 pthread 的结果
    void *r1, *r2;
    result1 = (float *)malloc(sizeof(float) * 2);
    result2 = (float *)malloc(sizeof(float) * 2);

    struct timeval start, end;

    float during;
    // 计算开始的时候,获取当前时间点
    gettimeofday(&start, NULL);
    // 第 4个参数会传递到 第 3 个参数中
    pthread_create(&t1, NULL, pthread_func1, &param);

    pthread_create(&t2, NULL, pthread_func2, &param);

    // 第1个参数：线程名字 ，第 2 个参数:线程返回的结果放到哪个地址，地址必须是 void*类型
    pthread_join(t1, &r1);
    pthread_join(t2, &r2);

    result1 = (float *)r1;
    result2 = (float *)r2;

    // 计算结束的时候,获取当前时间点
    gettimeofday(&end, NULL);
    during = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec);
    printf("result1[0]:%f,result1[1]:%f\n", result1[0], result1[1]);
    printf("result2[0]:%f,result1[1]:%f\n", result2[0], result2[1]);
    printf("during:%f\n", during);
}

int main(int argc, char const *argv[])
{
    //串行运行
    normal_thread_cost_time();
    // 运行时间约为 normal_thread_cost_time 的一半
    pthread_cost_time();
    return 0;
}
