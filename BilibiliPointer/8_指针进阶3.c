/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-20 12:37:19
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-20 19:55:20
 * @FilePath: /Hello/contacts/Bilbili/8_指针进阶3.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AEpo
 */
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

/**
 * 一级指针传承
 */
void one_level_asParam(char *p)
{

    printf("%s\n", p);
}

void test(int **p2)
{

    **p2 = 20;
}

/**
 * 二级指针传承
 */
void second_level_asParam()
{
    int a = 10;
    // 一级指针
    int *pa = &a;
    // 二级指针
    int **ppa = &pa;
    // 传一级指针地址
    test(&pa);
    printf("%d \n", a);
}

int add(int x, int y)
{
    return x + y;
}

void testStr(char *str)
{
    printf("%s\n", str);
}

/**
 * 函数指针
 */
void funcPointer()
{
    printf("add address:%p\n", add);
    printf("&add address:%p\n", &add);

    // pa 是函数指针, 参数是 int,int, 返回值是 int
    int (*pa)(int, int) = &add;
    int result = pa(2, 3);
    int result2 = (*pa)(2, 3);

    printf("result:%d,result2:%d \n", result, result2);
    // pa 是函数指针,参数是 char *, 返回值是 void
    void (*pt)(char *) = &testStr;
    pt("hello");
}

int main(int argc, char const *argv[])
{
    char w = 'w';
    char *p = &w;
    one_level_asParam(&w);
    one_level_asParam(p);
    second_level_asParam();
    funcPointer();
    return 0;
}
