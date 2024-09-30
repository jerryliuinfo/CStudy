#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

void testPointType()
{
    int num = 10;
    int *p = NULL;
    p = &num;

    // 指针变量的跨度, p是 int 型, p+1 跳过的是 int 占用的 4个字节空间
    printf("&num=%u\n", &num);
    // p1 +1 比 p1 的值大 4
    printf("p=%u\n", p);
    printf("p+1=%u\n", p + 1);

    char *p1 = &num;
    // p1 +1 比 p1 的值大 1
    printf("p1=%u\n", p1);
    printf("p1+1=%u\n", p1 + 1);
}

void testPointType2()
{
    // 内存中村方式为 04 03 02 01
    int num = 0x01020304;
    int *p1 = &num;
    // 输出 0x01020304
    printf("*p1=%#x\n", *p1);

    short *p2 = &num;
    // 由于 short 类型是 2 个字节，因此 *p2智能取出前两个字节，输出 0x0304
    printf("*p2=%#x\n", *p2);

    char *p3 = &num;
    // 由于 char 类型是 1 个字节，因此 *p3智能取出前 1 个字节，输出 0x04
    printf("*p3=%#x\n", *p3);

    // 如何取出 0x0102
    short *p4 = &num;
    // p4指向的变量类型是 short，占两个字节，因此 +=1 跳两个字节，由 04 的位置调到 01
    p4 += 1;
    printf("*p4=%#x\n", *p4);

    // 如何取出 0x0203
    char *p5 = &num;
    // 指向 03
    p5 += 1;
    // 利用 short * 取 2 个字节
    printf("*p5=%#x\n", *(short *)p5);
}

int main(int argc, char const *argv[])
{
    testPointType();

    testPointType2();

    return 0;
}
