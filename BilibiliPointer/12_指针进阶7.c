#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

int cmp_int(const void *e1, const void *e2)
{
    // 先对 e1 使用 int * 强制换成整型指针，然后再 * 解引用得到值
    int e1Value = *(int *)e1;
    int e2Value = *(int *)e2;
    return e1Value - e2Value;
}

void swap(char *buf1, char *buf2, int width)
{
    for (size_t i = 0; i < width; i++)
    {
        char temp = *buf1;
        *buf1 = *buf2;
        *buf2 = temp;

        buf1++;
        buf2++;
    }
}

// 模仿 qsort 实现冒泡排序的通用算法

void my_qsort(void *base, int sz, int width, int (*cmp)(const void *e1, const void *e2))
{
    for (size_t i = 0; i < sz; i++)
    {
        for (size_t j = 0; j < (sz - 1 - i); j++)
        {
            // 找出下标 j 和 下标 j+1 的地址
            // j的位置: (char*)base + j * wdith,  j +1 的位置: (char*)base + ( j+1) * wdith
            char *jAddress = (char *)base + j * width;
            char *nextAddress = (char *)base + (j + 1) * width;
            if (cmp(jAddress, nextAddress))
            {
                // 交互元素
                swap(jAddress, nextAddress, width);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {9, 8, 7, 6, 5};
    int sz = sizeof(arr) / sizeof(arr[0]);
    my_qsort(arr, sz, sizeof(arr[0]), cmp_int);
    for (size_t i = 0; i < sz; i++)
    {
        printf("%d ",arr[i]);
    }
    
    int a = 10;
    char ch = 'w';
    void *p = &a;

    void *p2 = &ch;
    printf("%p", p);

    return 0;
}
