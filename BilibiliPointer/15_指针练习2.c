#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

typedef struct Stu
{
    char name[20];
    int age;
} stu;

void test1()
{
    stu stu1 = {"zhangsan", 18};
    printf("stu1: %p\n", &stu1);
    // stu1 的 size 为 24个字节
    printf("size: %zu\n", sizeof(stu1));
    stu *ptr = &stu1;
    printf("ptr: %p\n", ptr);
    // ptr 地址 +24个字节
    printf("111 : %p\n", ptr + 0x1);
    printf("222 : %lu\n", (unsigned long)ptr + 0x1);
    // ptr 地址 +4个字节
    printf("333 : %p\n", (unsigned int *)ptr + 0x1);
}

void test2()
{
    int arr[4] = {1, 2, 3, 4};
    //&arr 指向的是整个数组， +1 ，指向的是数组末尾的下一个内存单元
    int *ptr1 = (int *)(&arr + 1);
    // arr  指向数组第一个元素，(int)arr + 1) 指向数组首元素之后的第一个字节
    int *ptr2 = (int *)((int)arr + 1);
    // ptr1[-1] ，移动的是 4 个字节，指向的是数组最后一个元素 4
    printf("%x %x\n", ptr1[-1], *ptr2);
}

void test3()
{
}

void test4()
{
    int aa[2][5] = {1, 2, 3, 4, 5, 6, 7, 8, 9,10};
    /**
     * 1、&aa 二维数组地址
     * 2、&aa +1，跳过整个数组的大小， 也就是数组的最后元素(10)的下一个内存地址
     * 3、ptr1 - 1: 指向 10 这个元素的内存地址
     * 4、*(ptr1 - 1): 对元素 10 这个内存地址解引用，得到 10
     * 
     * 
     */
    int *ptr1 = (int *)(&aa + 1);
    //ptr1 -1 是指到 10 这个地址 ,*(ptr1 - 1) 解引用10这个地址，得到 10
    printf("%d\n", *(ptr1 - 1));

    /**
     * 1、aa:     数组名，表示首元素地址，也就是第一行的地址, 
     * 2、aa +1:  跳转到第 2行地址，*(aa +1)相当于对第2行解引用,拿到了第 2行， 等价于 aa[1], 
     * 3、*(aa +1):  对第 2 行解引用，相当于是拿到了整个第2行，第 2 行数组名默认是指向首元素地址，
     * 也就是 6 的地址， 对 6 这个地址用 * 解引用，得到的是 6
     * 4、（int *） (*(aa +1)): 使用 int * 强转没有意义，因为  (*(aa +1)) 本来就是一个整型
     * 5、ptr2 -1 : 指向 6 前面一个元素的地址，也就是 5 的地址
     * 6、*(ptr2 -1): 对 5 的地址解引用，得到 5 
     */
    int *ptr2 = (int *)(*(aa + 1));
    //输出 5
    printf("%d\n", *(ptr2 - 1));
}

int main(int argc, char const *argv[])
{
    // test1();
    // test2();
    test4();
    return 0;
}
