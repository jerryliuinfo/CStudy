/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-15 15:54:23
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-16 10:40:57
 * @FilePath: /Hello/contacts/Bilbili/指针初阶2.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

void printArray(float *arr, int sz)
{
    for (size_t i = 0; i < sz; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

void illegalAccess()
{
    int *p; // p 是一个局部的指针变量，局部变量不初始化的话，默认是随机值
    // 场景1 非法访问内存
    *p = 20;
    printf("%p\n", p);
}

void outofIndexArray()
{
    int arr[10] = {0};
    int *p = arr;
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i <= len; i++)
    {
        // i = 10时，解引用访问的是一个非法的指针，也就是野指针
        *p++ = i;
    }
}

int *test()
{
    int a = 10;
    return &a;
}

/**
 * 访问已经被释放的空间
 */
void accessFreeedMemory()
{
    //  执行完这行代码后，a 就已经被系统回收了
    int *p = test();
    // 此时通过 *p 访问 a 属于野指针
    *p = 20;
}

void yezhizhen()
{
    // 场景1： 非法访问内存
    //  illegalAccess();

    //  场景2：数组越界
    // outofIndexArray();

    // 场景3：访问呢已经被释放的指针
    accessFreeedMemory();
}

/**
 * 避免野指针
 */
void avoidIllegalPointer()
{
    // 当前不着调应该初始化什么地址的时候，初始化为 NULL
    int *p = NULL;
}

#define N_VALUES 5

/**
 *  指针的运算：
 *  指针 +- 正数
 *  指针 - 指针
 *  指针的关系运算符
 */
void pointerOperation()
{
    printf("pointerOperation --->");
    float values[N_VALUES];
    float *vp;
    int len = sizeof(values) / sizeof(values[0]);
        printf("从前往后遍历赋值\n");

    for (vp = &values[0]; vp < &values[N_VALUES];)
    {
        *vp++ = 1;
    }

    printArray(values, len);
    printf("从后往前遍历赋值\n");
    for (vp = &values[N_VALUES]; vp > &values[0];)
    {
        *--vp = 0;
    }
    printArray(values, len);

    /**
     * 这种方式在绝大部分编译器上可以正常运行，然后还是应该避免这么写，因为标准并不保证它可行
     * C 语言标准规定：
     * 允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置
     * 的指针比较，但是不允许与指向第一个元素之前的那个内存位置的指针进行
     * 比较
     */
     printf("方式 3 遍历\n");
    for (vp = &values[N_VALUES -1]; vp > &values[0]; vp--)
    {
        *vp = 0;
    }
    printArray(values, len);
}

void iterateArrayByPointer()
{
    printf("\niterateArrayByPointer start ----->\n");
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int len = sizeof(arr) / sizeof(arr[0]);
    int *p = arr;
    int *pEnd = &arr[len - 1];
    while (p <= pEnd)
    {
        printf("%d ", *p);
        p++;
    }
    int diff = &arr[9] - &arr[0];
    printf("\n&arr[9] - &arr[0]: %d\n", diff);
}

void pointerStep()
{
    printf("\n pointerStep start ----->\n");
    int arr[10] = {1, 2, 3, 4, 5};
    // arr  指向的是首元素地址
    printf("arr address:%p\n", arr);
    //&arr 指向数组整体的指针
    printf("&arr address:%p\n", &arr);
}

/**
 * 计算器计算字符串长度
 */
int my_strlen(char *str)
{
    int count = 0;
    while (*str != '\0')
    {
        count++;
        str++;
    }
    return count;
}

/**
 * 通过指针-指针的方式计得到元素的个数
 */
int my_strlen2(char *str)
{
    char *start = str;
    while (*str != '\0')
    {
        str++;
    }
    // 两个指针相减，得到 2 个指针之间元素的个数
    return str - start;
}

void strlenTest()
{
    int len = my_strlen("abc");
    printf("my_strlen len:%d\n", len);

    len = my_strlen2("abc");
    printf("my_strlen2 len:%d\n", len);
}

/**
 *
 * https://www.bilibili.com/video/BV1pP4y1f7ts/?p=3&spm_id_from=pageDriver&vd_source=a388517dec16c9a07d40650d29919d69
 *
 */
int main(int argc, char const *argv[])
{
    // yezhizhen();

    pointerOperation();

    iterateArrayByPointer();

    pointerStep();

    strlenTest();

    return 0;
}
