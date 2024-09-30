/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-06 08:28:58
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-06 08:31:43
 * @FilePath: /Hello/CainiaoC/Limits.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int main(int argc, char const *argv[])
{

    printf("Character types:\n");
    // char 类型的位数
    printf("ChAR_BIT:%d\n", CHAR_BIT);
    // char 类型的最小值（有符号或无符号）
    printf("ChAR_MIN:%d\n", CHAR_MIN);
    // char 类型的最大值（有符号或无符号）
    printf("ChAR_MAX:%d\n", CHAR_MAX);

    printf("SCHAR_MIN: %d\n", SCHAR_MIN);
    printf("SCHAR_MAX: %d\n", SCHAR_MAX);
    printf("UCHAR_MAX: %u\n", UCHAR_MAX);

    return 0;
}
