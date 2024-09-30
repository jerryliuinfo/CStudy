/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-21 10:25:35
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-21 11:51:52
 * @FilePath: /Hello/contacts/Bilbili/11_指针进阶6.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-21 10:25:35
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-21 11:39:42
 * @FilePath: /Hello/contacts/Bilbili/11_指针进阶6.c
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

void qsort2(
    void *__base,                                 // 待排序数组中第一个对象的地址
    size_t num,                                   // 排序数据中元素个数
    size_t size,                                  // 每个元素的大小，int 和 char 的元素大小是不同的
    int (*__compar)(const void *, const void *)); // 用来比较排序数据中2额元素的函数

void bubbleSort(int arr[], int sz)
{
    for (size_t i = 0; i < sz - 1; i++)
    {
        for (size_t j = 0; j < sz - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int sz)
{
    int *p = arr;
    for (size_t i = 0; i < sz; i++)
    {
        printf("%d ", *(p + i));
    }
}

int cmp_int(const void *e1, const void *e2)
{
    // 先对 e1 使用 int * 强制换成整型指针，然后再 * 解引用得到值
    int e1Value = *(int *)e1;
    int e2Value = *(int *)e2;
    return e1Value - e2Value;
}

int cmp_char(const void *e1, const void *e2)
{
    // 先对 e1 使用 int * 强制换成整型指针，然后再 * 解引用得到值
    char e1Value = *(char *)e1;
    char e2Value = *(char *)e2;
    return e1Value - e2Value;
}

typedef struct Stu
{
    char name[20];
    int age;
} stu;

int sortByAge(const void *e1, const void *e2)
{
    stu stu1 = *(stu *)e1;
    stu stu2 = *(stu *)e2;
    return stu1.age - stu2.age;
}

int sortByName(const void *e1, const void *e2)
{
    stu stu1 = *(stu *)e1;
    stu stu2 = *(stu *)e2;
    return strcmp(stu1.name, stu2.name);
}

/**
 * 对结构体排序
 */
void sortStruct()
{
    stu list[3] = {{"zhangsan", 28}, {"lisi", 18}, {"wangwu", 10}};
    int sz = sizeof(list) / sizeof(list[0]);
    printf("按年龄排序:\n");

    qsort(list, sz, sizeof(list[0]), sortByAge);
    for (size_t i = 0; i < sz; i++)
    {
        printf("%s %d\n", list[i].name, list[i].age);
    }
    printf("按名字排序:\n");
    qsort(list, sz, sizeof(list[0]), sortByName);
    for (size_t i = 0; i < sz; i++)
    {
        printf("%s %d\n", list[i].name, list[i].age);
    }
}

void bublleTest()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int sz = sizeof(arr) / sizeof(arr[0]);
    printf("传统方式排序--->\n");
    bubbleSort(arr, sz);
    printArray(arr, sz);

    printf("\nqsort 方式排序--->");
    int arr2[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    qsort(arr2, sz, sizeof(arr2[0]), cmp_int);
    printArray(arr2, sz);

    printf("\n 对字符串排序\n");
    char str[] = "cba";
    qsort(str, strlen(str), sizeof(char), cmp_char);
    printf("%s\n", str);

    sortStruct();
}

int main(int argc, char const *argv[])
{
    bublleTest();
    return 0;
}
