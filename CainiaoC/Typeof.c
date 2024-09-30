/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-04 17:05:52
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-04 20:49:40
 * @FilePath: /Hello/CainiaoC/Typeof.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-04 17:05:52
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-04 17:48:54
 * @FilePath: /Hello/CainiaoC/Typeof.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 * https://www.runoob.com/cprogramming/c-typedef.html
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * 在C语言中，typedef 是一个关键字，用于为现有的数据类型创建一个新的名称，
 * 这个过程称为类型定义。使用 typedef 可以提高代码的可读性和可维护性，同时也便于修改和扩展。

 */
typedef unsigned char BYTE;

// typedef 定义结构体
typedef struct Books
{
    char title[50];
    int book_id;
} Book;

// typedef 定义 枚举
typedef enum
{
    RED,
    GREEN,
    BULUE
} Color;

// 用 unit 代指 unsigned int
typedef unsigned int uint;

// 用 pchar 代指 char*
typedef char *pchar;
// func 被定义为一个函数指针，该函数接受两个 int 参数并返回一个 int。
typedef int (*func)(int, int);

void typedefTest()
{
    unsigned char ch1 = 'w';

    BYTE ch2 = 'a';
    printf("ch1:%c,ch2:%c", ch1, ch2);

    //  没有 typedf 时必须这么写
    struct Books book1;
    // 使用 typedef 之后就可以使用以下方式
    Book book2;

    strcpy(book2.title, "C 语言");
    book2.book_id = 200;

    printf("书标题: %s, ID:%d\n", book2.title, book2.book_id);

    // pchar t = &ch1;
    char ch3 = 'a';
    char *p1 = &ch3;
    // 使用 pchar 替代 char *
    pchar p2 = &ch3;
    printf("pchar:%p, p2:%p\n", p1, p2);
}

#define TRUE 1
#define FALSE 0

// 使用 PTR_INT 代指 int *
#define PTR_INT int *

// 将 int *（整型指针）重命名为 PRT_INT2
typedef int *PRT_INT2;

/**
 * #define 是 C 指令，用于为各种数据类型定义别名，与 typedef 类似，但是它们有以下几点不同：
 * typedef 仅限于为类型定义符号名称，#define 不仅可以为类型定义别名，也能为数值定义别名，比如您可以定义 1 为 ONE。
 * typedef 是由编译器执行解释的，#define 语句是由预编译器进行处理的。
 */
void typedefVsDefine()
{
    printf("TRUE 的值为: %d\n", TRUE);
    printf("FALSE 的值为: %d\n", FALSE);

    PTR_INT p1, p2;
}

int add(int a, int b)
{
    return a + b;
}

int substract(int a, int b)
{
    return a - b;
}

void displayResult(func operation, int a, int b)
{
    int result = operation(a, b);
    printf("displayResult result:%d\n", result);
}

void typeofDefineFunc()
{
    func ptr_add = add;
    func ptr_substract = substract;

    int a = 10;
    int b = 5;

    int result_add = ptr_add(a, b);
    int result_substract = ptr_substract(a, b);
    printf("%d + %d = %d\n", a, b, result_add);
    printf("%d - %d = %d\n", a, b, result_substract);

    displayResult(ptr_add, a, b);
    displayResult(ptr_substract, a, b);
}

int main(int argc, char const *argv[])
{
    typedefTest();
    typedefVsDefine();
    typeofDefineFunc();
    return 0;
}
