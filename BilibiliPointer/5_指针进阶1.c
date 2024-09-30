#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

/**
 * 字符指针
 */
void charPointer()
{
    // 本质上是把 "hello world"这个字符串的首字符的地址存放到了 pc 中
    char *ps = "hello world";
    // Error: ps  的值是常量字符串，常量值是不能改的，因此下面的代码会报错
    //    *ps = 'w';

    // 输出: h *pc 是对指针 pc 进行解引用操作，得到的是指针指向的第一个字符的值，即字符串 "hello world" 的第一个字符 'h'。
    printf("%c\n", *ps);
    // %s，它用于打印以 null 字符（'\0'）结尾的字符串。 pc 是一个指向字符串 "hello world" 的指针，没有进行解引用操作。
    // 因此，这行代码打印的是指针 pc 指向的整个字符串，即 "hello world"。
    printf("%s\n", ps);

    // 把整个 hello bit 放到字符数组中
    char arr[] = "hello bit";
    printf("arr: %c\n", *arr);
    printf("arr: %s\n", arr);

    // str1 和 str2 是两个字符数组，它们分别被初始化为字符串 "hello world"。在C语言中，当使用双引号初始化字符数组时，每个数组都会在内存中占据不同的位置，即使它们的内容相同。因此，str1 和 str2 实际上是指向不同内存地址的两个指针
    char str1[] = "hello world";
    char str2[] = "hello world";

    // str3 和 str4 是两个指向字符串常量的指针，它们都指向同一个字符串字面量 "hello world"。在C语言中，所有的字符串字面量通常存储在程序的只读数据段中，并且相同的字符串字面量会指向相同的内存地址。
    //  加上 const 的原因是从语法层面不让修改，因为常量字符串本身时不能修改的
    const char *str3 = "hello world";
    const char *str4 = "hello world";

    printf("str1:%s,str2:%s,str3:%s,str4:%s\n", str1, str2, str3, str4);
    printf("str1:%p,str2:%p,str3:%p,str4:%p\n", str1, str2, str3, str4);

    if (str1 == str2)
    {
        printf("str1 and str2 are the same\n");
    }
    else
    {
        printf("str1 and str2 are not the same\n");
    }

    if (str3 == str4)
    {
        printf("str3 and str4 are the same\n");
    }
    else
    {
        printf("str3 and str4 are not the same\n");
    }
}

void chapterArray()
{
    int a = 10;
    int b = 20;
    int c = 30;
    // 注意，不推荐用这种写法
    int *arr[] = {&a, &b, &c};
    for (size_t i = 0; i < 3; i++)
    {
        printf("%d ", *(arr[i]));
    }
}

/**
 * 二维数组
 */
void erweiArray()
{
    printf("erweiArray start \n");
    int a[] = {1, 2, 3, 4, 5};
    int b[] = {2, 3, 4, 5, 6};
    int c[] = {3, 4, 5, 6, 7};

    int *arr[] = {a, b, c};
    int len = sizeof(arr) / sizeof(arr[0]);
    for (size_t i = 0; i < len; i++)
    {
        for (size_t j = 0; j < 5; j++)
        {
            // printf("%d ", *(arr[i] + j));
            //*(arr[i] + j) 等价于 arr[i][j]
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    charPointer();

    chapterArray();
    erweiArray();
    return 0;
}
