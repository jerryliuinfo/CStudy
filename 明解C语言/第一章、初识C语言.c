/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-30 15:50:35
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-30 18:35:49
 * @FilePath: /CStudy/明解C语言/第一章、初识C语言.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AEpr
 */
#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

void putsTest()
{
    int n1, n2;
    // 在需要换行且不需要格式化输出的时候，可以使用 puts 函数来代替 printf 函数，puts 末尾 的 s取自 string
    puts("输入连个整数。");
    printf("整数1:");
    scanf("%d", &n1);
    printf("整数2:");
    scanf("%d", &n2);
    printf("它们的和是：%d\n", n1 + n2);
}

void testOperate()
{
    // 整数 /整数 运算，商的小数部分会被舍弃，但是浮点数之间的运算，就不会进行舍弃处理

    int n1, n2, n3, n4;
    double d1, d2, d3, d4;

    n1 = 5 / 2;
    n2 = 5.0 / 2.0;
    n3 = 5.0 / 2;
    n4 = 5 / 2.0;

    d1 = 5 / 2;
    d2 = 5.0 / 2.0;
    d3 = 5.0 / 2;
    d4 = 5 / 2.0;

    // 2
    printf("n1=%d\n", n1);
    // 2: 2.5 赋值给 int 型变量会舍弃小数部分，变成 2
    printf("n2=%d\n", n2);
    // 2: 2.5 赋值给 int 型变量会舍弃小数部分，变成 2
    printf("n3=%d\n", n3);
    // 2: 2.5 赋值给 int 型变量会舍弃小数部分，变成 2
    printf("n4=%d\n", n4);

    printf("d1=%f\n", d1);
    printf("d2=%f\n", d2);
    printf("d3=%f\n", d3);
    printf("d4=%f\n", d4);
}

void testFormatOutput()
{
    int a = 10;
    double pi = 3.14;
    // %5d 显示至少5位的 10进制数
    printf("testFormatOutput %5d\n", a);
    //%5.1f 显示至少 5 位的浮点数，但是小数点后只显示 1 位
    printf("testFormatOutput %05.1f\n", pi);
}

int main(int argc, char const *argv[])
{
    printf("Hello world \a\a\a\n");
    double x = 3.14;
    printf("x:%.2f\n", x);
    // double 类型的变量通过 scanf 函数赋值的时候需要使用格式字符串 %lf (l 是小写字母 l)
    // scanf("%lf", &x);

    // putsTest();

    testFormatOutput();
    return 0;
}
