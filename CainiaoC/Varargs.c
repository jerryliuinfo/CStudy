/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-05 11:09:45
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-05 11:24:17
 * @FilePath: /Hello/CainiaoC/Varargs.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

/**
 * 可变参数（Variadic arguments）允许函数接受不定数量的参数。这通常是通过在函数定义中使用省略号（...）来实现的。可变参数函数在C标准库中广泛使用，如 printf 和 scanf 函数。

要使用可变参数，你需要包含头文件 <stdarg.h>，它定义了操作可变参数的一系列宏
 *
 * count： 可变参数的数量
 */

int sum(int count, ...)
{
    int total = 0;
    va_list args;
    // 初始化 args 为可变参数列表
    va_start(args, count);
    for (int i = 0; i < count; i++)
    {
        //va_arg(args, int): 从 va_list 对象中按给定类型获取下一个参数。
        total += va_arg(args, int);
    }
    // 清理工作 清理 va_list 对象，完成可变参数的处理。
    va_end(args);
    return total;
}

int main(int argc, char const *argv[])
{
    int result = sum(3, 2, 3, 4);
    printf("The sum is %d\n", result);
    return 0;
}
