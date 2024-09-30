/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-18 21:45:53
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-20 12:48:33
 * @FilePath: /Hello/contacts/Bilbili/指针进阶2.c
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

void pointerArrayAddress()
{
    int arr[10] = {1, 2, 3, 4, 5};
    // parr是，一个指针，存放数组地址的指针
    int(*parr)[10] = &arr;

    //&arr: 是数组地址，
    printf("%p\n", &arr);
    // arr:数组名 默认是首元素地址
    printf("数组首元素地址:%p\n", arr);

    printf("%p\n", parr);

    double *d[5];
    // pd 是一个数组指针 ，
    // 1、 *首先和 pd 结合说明是一个指针，
    // 2、指针指向的是数组，数组中的每个元素为 double *, 因此变成 double *(*pd)
    // 3、数组有5个元素，因此后面添加 [5],
    double *(*pd)[5] = &d;
}

void addressOperation()
{
    printf("addressOperation start --->\n");
    int arr[5] = {1, 2, 3, 4, 5};
    // p1 首元素地址
    int *p1 = arr;
    // p2是数组指针,存的是数组地址
    int(*p2)[5] = &arr;

    printf("%p\n", p1);
    // p1 +1 的地址比 p1 大 4个字节
    printf("%p\n", p1 + 1);

    // p2 +1 的地址比 p2 大 （5 * 4）个字节
    printf("%p\n", p2);
    printf("%p\n", p2 + 1);
}

void pointerIterator()
{
    printf("pointerIterator start --->\n");

    int arr[5] = {1, 2, 3, 4, 5};
    // 数组指针,指向的是数组的地址
    int(*pa)[5] = &arr;
    // 不推荐的写法
    for (int i = 0; i < 5; i++)
    {
        //*pa 相当于对数组指针解引用，得到的是 arr， 也就是首元素地址
        printf("%d ", *((*pa) + i));
    }
    printf("\n");
}

/**
 * 常规方式打印二维数组
 */
void printErweiArray1(int arr[3][5], int row, int column)
{
    printf("printErweiArray1 start --->\n");
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

/**
 *  数组指针方式打印
 * p 是一个指针，指向的是一个一维数组，每行有5个元素
 */
void printErweiArray2(int (*p)[5], int row, int column)
{
    printf("printErweiArray2 start --->\n");
    for (size_t i = 0; i < row; i++)
    {
        for (size_t j = 0; j < column; j++)
        {
            // *(p + i) 是定位到某一行,也即是该行的首地址， + j 是定位到该行的 第 j 个元素地址， 最后加 * 解引用，得到第 i 行第 j 列的值
            printf("%d ", *(*(p + i) + j));
        }
        printf("\n");
    }
}

void test1_1(int arr[])
{
}

void test1_2(int arr[10])
{
}

void test1_3(int *arr)
{
}

void test2_1(int *arr[10])
{
}

void test2_2(int **arr)
{
}

/**
 *  一维数组传承
 */
void arrayAsParamter()
{
    int arr[10] = {0};
    // 指针数组
    int *arr2[20] = {0};
    // ok
    test1_1(arr);
    // ok
    test1_2(arr);
    // ok
    test1_3(arr);

    test2_1(arr2);
    test2_2(arr2);
}
/**
 * 字符串翻转，流入 abcdef 变成 fedcba
 */
void reverse(char *str)
{
    assert(str);
    int len = strlen(str);
    char *left = str;
    char *right = str + len -1;
    while (left < right)
    {
       int temp = *left;
       *left = * right;
       *right = temp;
       left++;
       right--;
    }
}

int main(int argc, char const *argv[])
{
    pointerArrayAddress();

    addressOperation();

    pointerIterator();

    int arr[3][5] = {{1, 2, 3, 4, 5}, {2, 3, 4, 5, 6}, {3, 4, 5, 6, 7}};
    // arr数组名是首元素地址
    printErweiArray1(arr, 3, 5);

    printErweiArray2(arr, 3, 5);

    arrayAsParamter();

    char str[] = "abcdef";
    //这种写法不行，因为 abcdef 是常量字符串不允许修改
    // char *str = "abcdef";
    reverse(str);
    printf("reverse arr:%s\n",str);

    return 0;

}
