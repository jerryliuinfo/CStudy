
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#include <stddef.h>

//sig_atomic_t : 是 int 类型，在信号处理程序中作为变量使用。它是一个对象的整数类型，该对象可以作为一个原子实体访问，即使存在异步信号时，该对象可以作为一个原子实体访问。
volatile sig_atomic_t stop = 0;

void handle_sigint(int sig)
{
    printf("Caught sign %d\n", sig);
    // 设置退出标记
    stop = 1;
}

void signalTest()
{
    // 将 SIGINT 信号的处理程序设置为 handle_sigint 函数
    signal(SIGINT, handle_sigint);
    while (!stop)
    {
        printf("Running...\n");
        sleep(1);
    }
    printf("Exiting...\n");
}

/**
 * ptrdiff_t 是一种有符号整数类型，用于表示两个指针之间的差值。其定义同样依赖于实现，
 * 通常是 int 或 long。
 */
void ptrdiffTest(){
    int arr[10];
    int *ptr1 = &arr[0];
    int *ptr2 = &arr[9];
     // 计算两个指针之间的差值: 9
    ptrdiff_t difference = ptr2 - ptr1;
    printf("Pointer difference:%ld\n",difference);
    
}


void pthreadCreateTest(){
    
}



int main(int argc, char const *argv[])
{
    signalTest();
    ptrdiffTest();
    return 0;
}
