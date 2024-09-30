#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

void test(const char *str)
{
    printf("%s\n", str);
}

/**
 * 函数指针：指向函数指针数组的 指针
 */
void pointToFuncPointerArray()
{
    // pfun 是函数指针
    void (*pfun)(const char *) = test;
    // 函数指针数组 初始化所有元素为NULL
    void (*pfunArr[5])(const char *) = {0};
    pfunArr[0] = test;
    // 对函数指针数组 pfunArr  取地址，得到指向函数指针数组的 指针: ppfunArr
    void (*(*ppfunArr)[5])(const char *) = &pfunArr;
    // void (*ppfunArr[5])(const char*) = &pfunArr; // 指向函数指针数组的指针
    (*ppfunArr[0])("Hello, World!");
}

void menu()
{
    printf("************************\n");
    printf("**********请选择**************\n");
    printf("*******1、add     2、sub     ********\n");
    printf("*******3、mul     4、div     ********\n");
    printf("*******0、exit    5、重新选择 ********\n");
}

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mul(int x, int y)
{
    return x * y;
}

int division(int x, int y)
{
    return x / y;
}

/**
 * 回调函数是一个通过函数指针调用的函数，如果你把函数指针（地址）作为参数传递给另一个函数，
 *当这个指针被用来调用其所指向的函数时，我们称这为回调函数。回调函数不是由该函数的实现方直接调用，
 * 而是在特定的事件或条件发生时由另一方调用，用于对该事件或条件进行响应。
 */

int calc(int (*p)(int, int))
{
    int x = 0;
    int y = 0;
    printf("请输入2个操作数>:");
    scanf("%d %d", &x, &y);
    //通过函数指针调用函数，这种机制称为回调函数
    int ret = p(x, y);
    printf("结果: %d \n", ret);
    return ret;
}

void calcTest()
{
    int input = 0;
    do
    {
        menu();
        int x = 0;
        int y = 0;
        int ret = 0;
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            //把函数的地址 add 传给 calc 
            ret = calc(add);

            break;
        case 2:
            ret = calc(sub);
            break;
        case 3:
            ret = calc(mul);
            break;
        case 4:
            ret = calc(division);
            break;
        case 5:
            printf("输入错误，请重新选择:\n");

            break;
        case 0:
            printf("退出");
            break;

        default:
            break;
        }

    } while (input);
}

/**
 * 回调函数是一个通过函数指针调用的函数，如果你把函数指针（地址）作为参数传递给另一个函数，
 *当这个指针被用来调用其所指向的函数时，我们称这为回调函数。回调函数不是由该函数的实现方直接调用，
 * 而是在特定的事件或条件发生时由另一方调用，用于对该事件或条件进行响应。
 */
void callback()
{
}

int main(int argc, char const *argv[])
{
    pointToFuncPointerArray();

    calcTest();

    return 0;
}
