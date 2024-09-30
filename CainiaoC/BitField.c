
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
/**
 * https://kimi.moonshot.cn/chat/cragb21mqu03ngek15tg
 *
 在C语言中，位域（Bit Fields）是一种数据结构，它允许程序员访问和操作内存中的单个位。位域通常用于打包数据结构，以便节省空间或者模拟硬件设备的寄存器。

位域是结构体（struct）的一部分，它允许在结构体定义中指定成员的位数。位域主要用于底层编程，如硬件接口、通信协议、嵌入式系统等领域。

以下是位域的一些关键点：

定义位域：在结构体定义中，可以在成员后面指定一个冒号（:），然后指定所需的位数。

存储：位域可以存储在内存中的一个或多个字节中，具体取决于位数和编译器的实现。

访问：可以像访问结构体的其他成员一样访问位域。

限制：位域只能用于整数类型的成员，如 signed int、unsigned int、char 等。

对齐：位域的对齐和打包可能受到编译器和硬件架构的影响。

端口性：位域在不同的编译器和平台上可能有不同的表现，因此使用位域编写的代码可能不具备很好的可移植性。
 *
 *
 */

struct
{
    unsigned int widthValidated;
    unsigned int heightValidated;
} status1;

struct
{
    /**
     * 位域的定义和位域变量的说明
     * type [member_name] : width ;
     * 元素	描述
        type	只能为 int(整型)，unsigned int(无符号整型)，signed int(有符号整型) 三种类型，决定了如何解释位域的值。
        member_name	位域的名称。
        width	位域中位的数量。宽度必须小于或等于指定类型的位宽度。
     */
    unsigned int widthValidated : 1;
    unsigned int heightValidated : 1;
} status2;

struct packed_struct2
{
    unsigned int f1;     // 1位的位域
    unsigned int f2;     // 1位的位域
    unsigned int f3;     // 1位的位域
    unsigned int f4;     // 1位的位域
    unsigned int type;   // 4位的位域
    unsigned int my_int; // 9位的位域
} struct1;

struct packed_struct
{
    unsigned int f1 : 1;     // 1位的位域
    unsigned int f2 : 1;     // 1位的位域
    unsigned int f3 : 1;     // 1位的位域
    unsigned int f4 : 1;     // 1位的位域
    unsigned int type : 4;   // 4位的位域
    unsigned int my_int : 9; // 9位的位域
} struct2;

struct BitField
{
    unsigned int is_enable : 1;   // 1位
    unsigned int has_feature : 1; // 1位
    unsigned int error_code : 4;  // 4位
    unsigned int type : 2;        // 2位
} bit, *pbit;

/**
 * 设置位域的值
 */
void setBifFieldValue()
{
    struct BitField device;
    device.is_enable = 1;
    device.has_feature = 0;
    device.error_code = 7;
    device.type = 3;
    // 占用的字节大小占用空间是 8 位(1+1+4+2)
    printf("sizeof device:%lu\n", sizeof(device));
    printf("is_enable:%d\n", device.is_enable);
    printf("has_feature:%d\n", device.has_feature);
    printf("error_code:%d\n", device.error_code);
    printf("type:%d\n", device.type);

    pbit = &bit;
    pbit->error_code = 9;
    printf("pbit.error_code:%d\n", pbit->error_code);
}

void bitFieldSizeTest()
{

    struct 
    {
        unsigned int age : 3;
    } Age;
    /*age 变量将只使用 3 位来存储这个值，如果您试图使用超过 3 位，则无法完成*/
    Age.age = 4;
    printf("Sizeof ( Age ):%lu\n",sizeof(Age));
    //error: 8 二进制表示为 10000 四位，超过了 3 位的限制，赋值会失败
     Age.age = 8;
    printf("Sizeof ( Age ):%lu\n",sizeof(Age));
}

int main(int argc, char const *argv[])
{
    // 输出:8 ,每个属性占用 4 个字节，2 个属性共占用 8 个字节
    printf("Memofy size occupied by status1:%lu\n", sizeof(status1));
    // 输出:4 位域总共占用了 2 位(1+1), int 类型的变量占用 4 个字节，因此占用大小为 4
    printf("Memofy size occupied by status2:%lu\n", sizeof(status2));

    // 对于 struct1，没有使用位域，所以每个成员都会占用其自身的大小。unsigned int 通常是 4 个字节，所以这个结构体将占用 4 * 6 = 24 个字节。
    printf("Memofy size occupied by struct1:%lu\n", sizeof(struct1));

    // 对于 struct2，位域总共占用了 16 位（1+1+1+1+4+9=17，但是通常会被对齐到 32 位的边界）。因此，struct1 可能会占用 4 个字节。
    printf("Memofy size occupied by struct2:%lu\n", sizeof(struct2));

    setBifFieldValue();

    bitFieldSizeTest();

    return 0;
}
