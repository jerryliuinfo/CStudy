#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>
int i = 0;

/**
 * sizeof(i) 得到的是 unsigned int， i 为负数，与 unsigned
 * i 是有符号整型， 有符号整型和无符号整型比较时，会把无符号整型转换成
 * 有符号数， -1转换成有符号 会变成一个很大的数字
 *
 * 输出 >
 */
void unsignedIntCompare()
{
    i--;
    if (i > sizeof(i))
    {
        printf(">\n");
    }
    else
    {
        printf("<\n");
    }
}

/**
 * 通过指针打印数组
 */
void printArrayByPoint()
{
    printf("printArrayByPoint start--->");
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // p为数组首元素地址
    int *p = arr;
    int sz = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < sz; i++)
    {
        // p + i 是第 i 个元素的地址
        printf("%d ", *(p + i));
    }
    printf("\n");
}

void printArrayByPoint2()
{
    printf("printArrayByPoint2 start--->");

    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int sz = sizeof(arr) / sizeof(arr[0]);
    // p为数组首元素地址
    int *p = arr;
    // 最后一个元素地址
    int *pend = arr + sz - 1;
    while (p <= pend)
    {
        printf("%d ", *p);
        p++;
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    unsignedIntCompare();

    printArrayByPoint();
    printArrayByPoint2();
    return 0;
}
