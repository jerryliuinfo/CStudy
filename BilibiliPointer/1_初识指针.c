
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

void sizeOfTest()
{
    printf("sizeof char*: %zu\n", sizeof(char *));
    printf("sizeof short*: %zu\n", sizeof(short *));
    printf("sizeof int*: %zu\n", sizeof(int *));
    printf("sizeof long*: %zu\n", sizeof(long *));
    printf("sizeof long long*: %zu\n", sizeof(long long *));
    printf("sizeof float*: %zu\n", sizeof(float *));
    printf("sizeof double*: %zu\n", sizeof(double *));
}

void basicUsage()
{
    int a = 10;
    // pa  还指向指针变量，pa 存的是 a 的地址
    int *pa = &a;
    *pa = 20; // 通过 pa 里面的地址，找到 a
    printf("整型指针-------->");

    for (size_t i = 0; i < 5; i++)
    {
        printf("pa i:%zu,%p\n", i, pa);
        pa++;
    }
    printf("字符指针-------->");
    char c = 'w';
    char *pc = &c;
    for (size_t i = 0; i < 5; i++)
    {
        printf("pc i:%zu,%p\n", i, pc);
        pc++;
    }
}
int main(int argc, char const *argv[])
{
    basicUsage();

    sizeOfTest();

  
    return 0;
}
