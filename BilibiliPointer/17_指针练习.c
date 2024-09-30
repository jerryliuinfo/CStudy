/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-27 20:42:00
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-28 10:44:21
 * @FilePath: /Hello/BilibiliPointer/17_指针练习.c
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

/**
 * 找到了 return 1；找不到 return 0
 */
int find_num(int arr[3][3], int r, int c, int k)
{
    int x = 0;
    int y = c - 1;
    while (x < r && y >= 0)
    {
        if (arr[x][y] < k)
        {
            // 往下挪动一行
            x++;
        }
        else if (arr[x][y] > k)
        {
            y--;
        }
        else
        {
            printf("找到了: %d\n", k);
            return 1;
        }
    }
    printf("没找到: %d\n", k);
    return 0;
}

/**
 * 找到了 return 1；找不到 return 0
 */
int find_num2(int arr[3][3], int *px, int *py, int k)
{
    int x = 0;
    int y = *py - 1;
    while (x < *px && y >= 0)
    {
        if (arr[x][y] < k)
        {
            // 往下挪动一行
            x++;
        }
        else if (arr[x][y] > k)
        {
            // 往左边挪动一行
            y--;
        }
        else
        {
            *px = x;
            *py = y;
            printf("找到了: %d\n", k);
            return 1;
        }
    }
    printf("没找到: %d\n", k);
    return 0;
}

/**
 *
 */
void test()
{
    int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int x = 3;
    int y = 3;

    int target = 7;
    find_num(arr, x, y, target);

    // 传入值，带回值
    find_num2(arr, &x, &y, target);
    printf("find_num2 x:%d,y:%d, %d\n", x, y, arr[x][y]);
}

int main(int argc, char const *argv[])
{
    test();
    return 0;
}
