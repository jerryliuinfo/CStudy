/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-05 08:22:13
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-05 10:38:11
 * @FilePath: /Hello/CainiaoC/PreProcessor.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * 参考:https://www.runoob.com/cprogramming/c-preprocessors.html
 * C 预处理器不是编译器的组成部分，但是它是编译过程中一个单独的步骤。简言之，C 预处理器只不过是一个文本替换工具而已，它们会指示编译器在实际编译之前完成所需的预处理。
 * 我们将把 C 预处理器（C Preprocessor）简写为 CPP。

所有的预处理器命令都是以井号（#）开头。它必须是第一个非空字符，为了增强可读性，预处理器指令应从第一列开始。

 */

#define MAX_ARRAY_LENGTH 20
// 告诉 CPP(预编译器)从系统中获取 ctype.h
#include <ctype.h>

// 这个指令告诉 CPP 取消已定义的 FILE_SIZE，并定义它为 42。
#undef FILE_SIZE
#define FILE_SIZE 42

// ifdef
#ifdef MAX_COUNT
#undef MAX_COUNT
#endif
#define MAX_COUNT 10

// ifndef
#ifndef MESSAGE
#define MESSAGE "Hello"
#endif

/**
 * 这个指令告诉 CPP 如果定义了 DEBUG，则执行处理语句。在编译时，如果您向 gcc 编译器传递了 -DDEBUG 开关量，这
 * 个指令就非常有用。它定义了 DEBUG，您可以在编译期间随时开启或关闭调试。
 */
#ifdef DEBUG
printf("print message");
#endif

/**
 * 预定义宏
 * __DATE__:	当前日期，一个以 "MMM DD YYYY" 格式表示的字符常量。
 * __TIME__:	当前时间，一个以 "HH:MM:SS" 格式表示的字符常量。
 * __FILE__:	这会包含当前文件名，一个字符串常量。
 * __LINE__:	这会包含当前行号，一个十进制常量。
 * __STDC__:	当编译器以 ANSI 标准编译时，则定义为 1。
 */
void predefineMaro()
{
    // 输出：PreProcessor.c
    printf("File:%s\n", __FILE__);
    // Sep  5 2024 当前日期，一个以 "MMM DD YYYY" 格式表示的字符常量。
    printf("Date:%s\n", __DATE__);
    // 08:38:13 当前时间，一个以 "HH:MM:SS" 格式表示的字符常量。
    printf("Time:%s\n", __TIME__);
    printf("Line:%d\n", __LINE__);
    printf("ANSI:%d\n", __STDC__);

    char data_time[100];
    snprintf(data_time, sizeof(data_time), "%s:%s", __DATE__, __TIME__);
    printf("时间日期:%s\n", data_time);
}

// 宏延续运算符（\）  一个宏通常写在一个单行上。但是如果宏太长，一个单行容纳不下，则使用宏延续运算符（\）。例如：
#define message_for(a, b) \
    printf(#a " and " #b ":you are welcome\n")

/**
 * 标记粘贴运算符（也称为标记连接运算符或token pasting operator）是 ##。这个运算符用于在预处理阶段将两个标记（tokens）连接成一个单一的标记。
 * 这通常用于宏定义中，以创建基于参数的类型安全枚举、类型安全位字段操作、类型安全函数调用等。
 */
#define tokenpaster(n) printf("token" #n " = %d", token##n)

#define MAKE_ENUM(x) (1 << x)

enum
{
    RED = MAKE_ENUM(0),
    GREEN = MAKE_ENUM(1),
    BLUE = MAKE_ENUM(2)
};

enum
{
    APPLE = MAKE_ENUM(0),
    BANANA = MAKE_ENUM(1),
    CHERRY = MAKE_ENUM(2)
};

/**
 * 标记粘贴运算符:
 * 标记粘贴运算符（也称为标记连接运算符或token pasting operator）是 ##。这个运算符用于在预处理阶段将两个标记（tokens）连接成一个单一的标记。
 * 这通常用于宏定义中，以创建基于参数的类型安全枚举、类型安全位字段操作、类型安全函数调用等。
 */
void markPasterOperator()
{
    // 正确的枚举值
    int color = RED;
    // 正确的枚举值
    int fruit = APPLE;
    color = APPLE;
    printf("color:%d\n", color);
}

#if !defined(GREETING)
#define GREETING "You are welcome"
#endif

/**
 * 预处理器 defined 运算符是用在常量表达式中的，用来确定一个标识符是否已经使用 #define 定义过。
 * 如果指定的标识符已定义，则值为真（非零）。如果指定的标识符未定义，则值为假（零）
 */
void definedOperator()
{
    printf("Here is the message:%s\n", GREETING);
}

// 常规方式
int square(int x)
{
    return x * x;
}

#define square2(x) ((x) * (x))

#define MAX(x, y) ((x > y) ? (x) : (y))

/**
 * 参数化的宏
 * 参数化宏（也称为宏函数）是通过预处理器创建的，允许你将输入参数传递给宏，并在预处理阶段进行文本替换。
 * 参数化宏非常有用，因为它们可以在编译前执行计算和文本操作，从而减少代码重复并提高代码的可读性。
 */
void paramMacros()
{
    printf("%d,%d\n", square2(2), square2(3));
    printf("%f\n", square2(2.1));
    printf("Max between 20 and 10 is:%d\n", MAX(20, 10));
    printf("Max between 4.1 and 5.2 is:%f\n", MAX(4.1, 5.2));
}

/**
 * 预处理器运算符
 *
 */
void preprocesOperator()
{
    message_for("zhangsan", "lisi");
    message_for(10, 100);

    int token34 = 40;

    markPasterOperator();

    definedOperator();

    paramMacros();
}

int main(int argc, char const *argv[])
{
    predefineMaro();

    preprocesOperator();
    return 0;
}
