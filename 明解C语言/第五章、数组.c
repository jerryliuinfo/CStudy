/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-30 22:06:46
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-30 22:10:12
 * @FilePath: /CStudy/明解C语言/第五章、数组.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */

#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

#define COUNT  5

void tensuTest()
{
    int sum = 0;
    int socore[COUNT] = {0};
    for (size_t i = 0; i < COUNT; i++)
    {
        printf("%2lu 号:", (i + 1));
        scanf("%d", &socore[i]);
        sum += socore[i];
    }
    printf("总分:%5d\n", sum);
    printf("平均分分:%5.1f\n", (double)sum / COUNT);
}

int main(int argc, char const *argv[])
{
    tensuTest();
    return 0;
}
