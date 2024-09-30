#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

/**
 *  // ABCDEF -> BCDEFA -> CDEFAB
 * 每次左旋转一个字符,
 */
void string_left_rotate(char *str, int k)
{
    int i = 0;
    int n = strlen(str);
    k = k % n; // 如果 k 大于字符串长度，则取余数

    for (int i = 0; i < k; i++)
    {
        // 首字符取出来
        char temp = *str;
        for (int j = 0; j < n - 1; j++)
        {
            // 将第 j 个位置的内容，替换为 第 j +1个位置的内容
            *(str + j) = *(str + j + 1);
        }
        // temp 放在最后
        *(str + n - 1) = temp;
    }
}

char *string_left_rotate_by_return(const char *str, int k)
{
    int n = strlen(str);
    k = k / n;
    //+1是为了添加空字符 '\0'
    char *newStr = (char *)malloc(n + 1);
    if (newStr == NULL)
    {
        perror("allocate memory failed  for newStr");
        return NULL;
    }
    // 复制原始字符串到新的字符串
    strcpy(newStr, str);
    for (int i = 0; i < k; i++)
    {
        // 首字符取出来
        char temp = newStr[0];
        for (int j = 0; j < n - 1; j++)
        {
            // 将第 j 个位置的内容，替换为 第 j +1个位置的内容
            newStr[j] = newStr[j + 1];
        }
        // temp 放在最后
        newStr[n - 1] = temp;
    }
    return newStr;
}

void reverse(char *left, char *right)
{
    assert(left);
    assert(right);
    while (left < right)
    {
        // 交换元素位置
        char temp = *left;
        *left = *right;
        *right = temp;
        left++;
        right++;
    }
}

/**
 * 三步反转法
 * ABCDEF
 * 1、左边逆序：对 左边的  AB 进行逆序，得到 BACDEF
 * 2、右边逆序：对 右边的  CDEF 进行逆序，得到 BAFEDC
 * 3、整体逆序：对第 2 步的 BAFEDC 整体进行逆序，得到 CDEFAB
 *
 *
 */
void string_left_rotate2(char *str, int k)
{
    int n = strlen(str);
    // 对左边逆序
    reverse(str, str + k - 1);
    // 对右边逆序:str + k 第 k 个元素地址, str + n - 1 最后一个元素地址
    reverse(str + k, str + n - 1);
    //整体逆序
    reverse(str,str + n -1);
    printf("string_left_rotate2 %s\n",str);
}

int main(int argc, char const *argv[])
{

    char arr[10] = "ABCDEF";
    int k = 2;
    // ABCDEF -> BCDEFA -> CDEFAB
    string_left_rotate(arr, k);

    printf("string_left_rotate %s,len:%lu\n", arr, strlen(arr));

    char arr2[10] = "ABCDEF";

    char *result = string_left_rotate_by_return(arr2, k);
    printf("string_left_rotate_by_return %s,len:%lu\n", arr, strlen(result));

     string_left_rotate2(arr2, k);
    printf("string_left_rotate2 %s,len:%lu\n", arr, strlen(result));

    return 0;
}
