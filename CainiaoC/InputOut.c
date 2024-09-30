#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * 参考:https://www.runoob.com/cprogramming/c-input-output.html
 *
 */

void scanfTest()
{
    printf("scanfTest Enter a number: ");
    float f;
    scanf("%f", &f);
    printf("Value = %f", f);
}

void getCharTest()
{
    int c;
    // 键盘输入 Ctrl + D 发送 EOF
    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
}

/**
 * puts() 函数用于将一个字符串输出到标准输出（stdout），并在字符串的末尾自动添加换行符（'\n'）。
 */
void putcharTest()
{
    char msg[] = "Hello, World";
    int i = 0;
    for (i = 0; msg[i] != '\0'; i++)
    {
        putchar(msg[i]);
    }
}

/**
 * fgets() 函数用于从指定的文件流中读取字符串，直到遇到换行符（'\n'）或者达到指定的字符数。
 * 它比 gets() 更安全，因为它允许你指定缓冲区的大小，从而避免缓冲区溢出的问题。
 * char *fgets(char *str, int num, FILE *stream);
 * str：指向字符数组的指针，用于存储读取的数据。
    num：最大读取字符数，包括空终止符 '\0'。
    stream：指向 FILE 对象的指针，该 FILE 对象标识了要从中读取数据的文件流。
 * 返回值：

    成功时返回指向 str 的指针。
    如果发生错误或到达文件末尾（EOF），返回 NULL。
 */
void getsTest()
{
    char buffer[100];
    printf("\nEnter a string:");
    //
    char *result = fgets(buffer, sizeof(buffer), stdin);

    printf("You entered:%s", buffer);
}

/**
 * puts() 函数用于将一个字符串输出到标准输出（stdout），并在字符串的末尾自动添加换行符（'\n'）。
 * int puts(const char *str);
 * str：指向要输出的字符串的指针。
 * 返回值：

    成功时返回一个非负整数。
    失败时返回 EOF。
 *
 */
void putTest()
{
    // puts 会在字符串末尾添加换行符
    puts("Hello world");
    printf("output finished\n");
}

/**
 * int getchar(void) 函数从屏幕读取下一个可用的字符，并把它返回为一个整数。这个函数在同一个时间内只会读取一个单一的字符。您可以在循环内使用这个方法，以便从屏幕上读取多个字符。

int putchar(int c) 函数把字符输出到屏幕上，并返回相同的字符。这个函数在同一个时间内只会输出一个单一的字符。您可以在循环内使用这个方法，以便在屏幕上输出多个字符。
 */
void getCharPutchar()
{
    /*  int c;
     printf("getCharPutchar test Enter a value:");
     c = getchar();

     printf("\nYou entered: ");
     putchar(c);
     printf("\n"); */

    // getCharTest();

    putcharTest();
}

/**
 * name 是一个字符数组（char 类型的数组），用于存储字符串。在C语言中，
 * 数组名本身在大多数情况下会被解析为数组首元素的地址。因此，当你传递 name 给 scanf 时，
 * 编译器会自动将其视为数组首元素的地址。因此使用 scanf 接收 name 的时候不用加 &
 */
void scanfTest2()
{
    char str[100];
    int i;
    printf("Scanf Enter a value:");
    scanf("%s %d", str, &i);
    printf("\nYou entered: %s %d", str, i);
    printf("\n");
}

int main(int argc, char const *argv[])
{
    // scanfTest();

    getCharPutchar();

    getsTest();

    putTest();

    scanfTest2();
    return 0;
}
