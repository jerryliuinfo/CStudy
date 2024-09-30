/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-05 14:13:49
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-05 14:58:27
 * @FilePath: /Hello/CainiaoC/UndefinedBehavior.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%A
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

/**
 * 参考:https://www.runoob.com/cprogramming/undefined-behavior.html
 *
 */

void undefineBehaviorTest()
{
    int arr[3] = {1, 2, 3};
    // 数组越界
    //  printf("%d\n",arr[5]);

    // 解引用空指针
    int *ptr = NULL;
    // 解引用空指针，结果未定义
    //  printf("%d\n", *ptr);

    // 未初始化的局部变量
    int x;
    // printf("x:%d\n",x);

    // 正数除以 0
    int a = 10;
    // 整数除以0，结果未定义
    // int b = a / 0;

    // 符号溢出
    signed char ch = 126;
    // 位移操作数太大，结果未定义
    ch = ch + 1;
    printf("%d\n", ch);

    // 错误的类型转换
    int *ptr2 = malloc(sizeof(int));
    float *fptr2 = (float *)ptr2;
    printf("fptr: %p\n", fptr2);

    // 内存越界
    int *ptr3 = (int *)malloc(sizeof(int));
    if (ptr3 == NULL)
    {
        perror("failed to allocate memory");
        return;
    }
    free(ptr3);
    // 避免悬挂指针
    // ptr3 = NULL;
    // 内存越界，结果未定义
    *ptr3 = 10;
    printf("ptr3: %d\n", *ptr3);

    // 未定义的浮点数行为 x1 和 y1 的值都是 nan
    float x1 = sqrt(-1);
    float y1 = sqrt(-1);
    printf("x1:%f, x2:%f\n", x1, y1);
    // if (x1 == y1)
    // {
    //     printf("NaN values are equal\n");
    // }

    // 修改字符串字面量：
    char *str = "Hello";
    // error: str 是一个指向字符串字面量 "Hello" 的指针。在C语言中，字符串字面量是存储在程序的只读数据段中的，尝试修改字符串字面量的内容会导致未定义行为，通常是程序崩溃。
    //  str[0] = 'h';
    printf("str:%s\n", str);
    //str 是一个字符数组，它包含了字符串 "Hello" 的副本。修改数组的内容是安全的，因为数组是在程序的可读写数据段中分配的。这样，当你修改 str[0] 时，你只是在修改数组的第一个元素，这不会影响程序的其他部分，也不会导致未定义行为
    char str2[] = "Hello";
    str2[0] = 'h';
    printf("str2:%s\n", str2);
}

int main(int argc, char const *argv[])
{
    undefineBehaviorTest();
    return 0;
}
