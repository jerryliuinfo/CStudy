
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void reverseStr2(char *str);
/**
 * 判断是否是字母
 */
void isAlphabet()
{
    char c = 'a';
    // printf("请输入一个字符:");
    // scanf("%c", &c);
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    {
        printf("%c 是字母\n", c);
    }
    else
    {
        printf("%c 不是字母\n", c);
    }
}

/**
 * 循环输出 26 个字母
 */
void outputAlphabet()
{
    // ASCII码中'A'的值为65
    char letter = 'A';
    for (size_t i = 0; i < 26; i++)
    {
        printf("%c ", letter);
        letter++;
    }
    printf("\n");
}

int convertBinaryToDecimal(long long n)
{
    int decimalNumber = 0, i = 0, remainder;
    while (n != 0)
    {
        remainder = n % 10;
        n /= 10;
        decimalNumber += remainder * pow(2, i);
        ++i;
    }
    return decimalNumber;
}

/**
 * 二进制转换为 十进制
 */
void binaryToDecimal()
{
    long long n;
    printf("请输入二进制数:");
    scanf("%lld", &n);
    printf("二进制 %lld 转换为 10 进制数为 %d\n", n, convertBinaryToDecimal(n));
}

void reverseStr()
{
    char c;
    scanf("%c", &c);
    if (c != '\n')
    {
        reverseStr();
        printf("%c", c);
    }
}

void reverseStrTest()
{
    printf("请输入一个字符串:");
    reverseStr();
}

void reverseStr2Test()
{
    printf("\n输入一个字符串:");
    char str[100];
    // 使用fgets读取一行文本
    fgets(str, sizeof(str), stdin);
    reverseStr2(str);
    printf("\n");
}

void reverseStr2(char *str)
{
    int len = 0;
    // 计算字符串长度
    len = strlen(str);
    for (int i = len - 1; i >= 0; i--)
    {
        printf("%c", str[i]);
    }
}

char *reverseStr3(const char *str)
{
    if (str == NULL)
    {
        return NULL;
    }

    int len = 0;
    // 计算字符串长度
    len = strlen(str);
    //+1 的原因是要添加结束符
    char *reversed = (char *)malloc(len + 1);
    if (reversed == NULL)
    {
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        reversed[i] = str[len - i - 1];
    }
    reversed[len] = '\0';
    return reversed;
}

void reverseStr3Test()
{
    printf("\n输入一个字符串:");
    char str[100];
    // 使用fgets读取一行文本
    fgets(str, sizeof(str), stdin);
    char *newText = reverseStr3(str);
    printf("origin text:%s, reversedText:%s\n", str, newText);
}

void printArray(int *arr, int sz)
{
    for (size_t i = 0; i < sz; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");
}

/**
 * 数组拷贝
 */
void copyArray()
{
    int src[] = {1, 2, 3, 4, 5};
    int sz = sizeof(src) / sizeof(src[0]);
    // dest 必须初始化大小
    int dest[5] = {};
    // 拷贝数组
    memcpy(dest, src, sizeof(src));

    printf("输出原始数组:");
    // 数组默认就是首地址，也就是指针
    printArray(src, sz);
    printf("输出新的数组:");
    printArray(dest, sz);

    dest[1] = 6;

    printf("输出原始数组2:");
    // 数组默认就是首地址，也就是指针
    printArray(src, sz);
    printf("输出新的数组2:");
    printArray(dest, sz);

    printf("\n");

    //  int srcArray[5] = {1, 2, 3, 4, 5};
    // int destArray[5];

    // memcpy(destArray, srcArray, sizeof(srcArray));

    // for (int i = 0; i < 5; i++) {
    //     printf("%d ", destArray[i]);
    // }
    // printf("\n");
}

/**
 * 使用指针访问数组
 * https://www.runoob.com/cprogramming/c-examples-access-array-pointer.html
 *
 */
void accessArrayByPointer()
{
    int data[5], i;
    printf("输入元素:");
    for (int i = 0; i < 5; i++)
    {
        // 读取用户输入的整数，并将其存储在数组 data 的第 i 个位置。data + i 是第 i 个元素的地址。
        printf("第 %d 个元素，地址位:%p\n", i, data + i);
        scanf("%d", data + i);
    }
    printf("你输入的是:");
    for (size_t i = 0; i < 5; i++)
    {
        printf("%d\n", *(data + i));
    }
}

void findMaxValue()
{
    float *data;
    int num = 0;
    printf("输入元素个数(1 ~5)");
    scanf("%d", &num);
    data = calloc(num, sizeof(float));
    if (data == NULL)
    {
        perror("Error, failed to allocate memory\n");
        exit(0);
    }
    printf("\n");
    for (int i = 0; i < num; i++)
    {
         printf("输入第 %d 个元素: ", i + 1);
        // 将输入的字符放到 data 指针的第 i 个位置
        scanf("%f", data + i);
    }
    for (int i = 0; i < num; i++)
    {
        //将首地址与第 i 个位置的元素做比较
        if (*data < *(data + i))
        {
            *data = *(data + i);
        }
    }
    printf("最大元素: %.2f\n", *data);
}

int main(int argc, char const *argv[])
{
    isAlphabet();
    outputAlphabet();
    // binaryToDecimal();
    // reverseStrTest();

    // reverseStr2Test();

    // reverseStr3Test();
    copyArray();

    accessArrayByPointer();

    findMaxValue();
    return 0;
}
