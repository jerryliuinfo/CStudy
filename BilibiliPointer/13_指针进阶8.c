#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

void sizeofTest()
{
    // int a[] = {1, 2, 3, 4, 5};
    // printf("%zu \n", sizeof(a));     // 20  :  sizeof(a) 计算的是整个元素的地址
    // printf("%zu \n", sizeof(a + 0)); // 4/8 :  a +0 是首1个元素地址
    // printf("%zu \n", sizeof(*a));    // 4   :  a 是首元素地址, *a 解引用得到的首元素,sizeof(*a) 计算的是首元素大小
    // printf("%zu \n", sizeof(a + 1)); // 4/8 :  a + 1 是第 2 个元素地址, sizeof(a +!) 计算的是第 2 个元素大小
    // printf("%zu \n", sizeof(a[1]));  // 4   :  a[1] 计算的是第 2 个元素大小

    // printf("%zu \n", sizeof(&a));        // 4/8 :  &a 是整个数组的地址，也是地址, sieof(地址)计算的是地址大小
    // printf("%zu \n", sizeof(*&a));       // 16  :  &a: 数组的地址, *&a 解引用得到的是数组
    // printf("%zu \n", sizeof(&a + 1));    // 4/8 :      &a:数据地址, &a +1 是数组后面空间的地址，地址的大小是 4/8个字节
    // printf("%zu \n", sizeof(&a[0]));     // 4/8 :  第一个元素地址
    // printf("%zu \n", sizeof(&a[0] + 1)); // 4/8 :  &a[0]是第一个元素地址，+！ 是第 2 个元素地址
}

void sizeofChar()
{
    //[a,b,c,d,e,f,\0]
    char arr[] = "abcdef";
    printf("1、%zu \n", sizeof(arr));         // 7
    printf("2、%zu \n", sizeof(arr + 0));     // 4/8
    printf("3、%zu \n", sizeof(*arr));        // 1
    printf("4、%zu \n", sizeof(arr[1]));      // 1
    printf("5、%zu \n", sizeof(&arr));        // 4/8
    printf("6、%zu \n", sizeof(&arr + 1));    // 4/8
    printf("7、%zu \n", sizeof(&arr[0] + 1)); // 4/8
}

int main(int argc, char const *argv[])
{
    // sizeofTest();

    sizeofChar();
    return 0;
}
