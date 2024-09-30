#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

#define N_VALUES 5

void printArray(float *arr, int sz)
{
    for (size_t i = 0; i < sz; i++)
    {
        printf("%f ", arr[i]);
    }
    printf("\n");
}

/**
 *  指针的运算：
 *  指针 +- 正数
 *  指针 - 指针
 *  指针的关系运算符
 */
void pointerOperation()
{
    printf("pointerOperation --->");
    float values[N_VALUES];
    float *vp;
    int len = sizeof(values) / sizeof(values[0]);
    printf("从前往后遍历赋值\n");

    for (vp = &values[0]; vp < &values[N_VALUES];)
    {
        *vp++ = 1;
    }

    printArray(values, len);
    printf("从后往前遍历赋值\n");
    for (vp = &values[N_VALUES]; vp > &values[0];)
    {
        *--vp = 0;
    }
    printArray(values, len);

    /**
     * 这种方式在绝大部分编译器上可以正常运行，然后还是应该避免这么写，因为标准并不保证它可行
     * C 语言标准规定：
     * 允许指向数组元素的指针与指向数组最后一个元素后面的那个内存位置
     * 的指针比较，但是不允许与指向第一个元素之前的那个内存位置的指针进行
     * 比较
     */
    printf("方式 3 遍历\n");
    for (vp = &values[N_VALUES - 1]; vp > &values[0]; vp--)
    {
        *vp = 0;
    }
    printArray(values, len);
}

void arrayAddresTest()
{
    int arr[10] = {0};
    int *p = arr;
    int len = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < len; i++)
    {
        *(p + i) = i;
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ", *(p + i));
    }
    printf("\n");
    // arr[2] <==> *(p+2) <==> *(2+p)
}

void secondPointer()
{
    int a = 9;
    // pa 是指针变量，一级指针
    int *pa = &a;
    // ppa 是二级指针变量:  pa 也是个变量，&pa取出 pa 在内存中的起始地址
    int **ppa = &pa;
    printf("pa address:%p\n", pa);
    printf("ppa address:%p\n", ppa);
    printf("*paa:%p\n", *ppa);
    printf("**paa:%p\n", **ppa);

    // 对二级指针解引用
    **ppa = 20;
    printf("修改后的a:%d\n", a);
}


/**
 * 指针数据
 */
void pointerArray(){
    //整型指针数组
    int * piArra[5];
    // 字符指针数组
    char * pcArra[5];
}

int main(int argc, char const *argv[])
{

    pointerOperation();

    arrayAddresTest();

    secondPointer();

    return 0;
}
