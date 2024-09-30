/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-04 15:20:38
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-07 15:23:37
 * @FilePath: /Hello/CainiaoC/Union.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * https://www.runoob.com/cprogramming/c-unions.html
 * 共用体是一种特殊的数据类型，允许您在相同的内存位置存储不同的数据类型。您可以定义一个带有多成员的共用体，但是任何时候只能有一个成员带有值。共用体提供了一种使用相同的内存位置的有效方式。
 */

/**
 * 现在，Data 类型的变量可以存储一个整数、一个浮点数，或者一个字符串。这意味着一个变量（相同的内存位置）
 * 可以存储多个多种类型的数据。您可以根据需要在一个共用体内使用任何内置的或者用户自定义的数据类型。
  共用体占用的内存应足够存储共用体中最大的成员。例如，在上面的实例中，Data 将占用 20 个字节的内存空间，
  因为在各个成员中，字符串所占用的空间是最大的。下面的实例将显示上面的共用体占用的总内存大小：
 */
union Data
{
    int i;
    float f;
    char str[20];
} data;

void defineUnion()
{
    union Data data;
    printf("Memofy size occupied by data:%lu\n", sizeof(data));
    

    data.i = 10;
    data.f = 15.1;
    strcpy(data.str, "C Programming");
    // 这里输出可以看到 data.i 和 data.f 的值是不符合预期的
    printf("data.i:%d, data.f:%f,data.str:%s\n", data.i, data.f, data.str);


    //在这里，所有的成员都能完好输出，因为同一时间只用到一个成员。
    data.i = 20;
    printf("data.i:%d\n", data.i);

    data.f = 4;
    printf("data.f:%f\n", data.f);
}

int main(int argc, char const *argv[])
{
    defineUnion();
    return 0;
}
