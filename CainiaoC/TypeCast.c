#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 *  强制类型转换
 * https://www.runoob.com/cprogramming/c-type-casting.html
 * 强制类型转换是把变量从一种类型转换为另一种数据类型。例如，如果您想存储一个 long 类型的值到一个简单的整型中，
 * 您需要把 long 类型强制转换为 int 类型。您可以使用强制类型转换运算符来把值显式地从一种类型转换为另一种类型，如下所示：
 * 
 */


void typeCast(){
    int sum = 17, count = 5;
    double mean = (double) sum / count;
    //输出 3 和 3.4
    printf("Value of not cast to double:%d, mean:%f\n", (sum / count), mean);
}

/**
 * 整数提升是指把小于 int 或 unsigned int 的整数类型转换为 int 或 unsigned int 的过程
 */
void intPromte(){
    int i = 17;
    char c = 'c';
    int sum = i + c;
    printf("Value of sum:%d\n",sum);
}

int main(int argc, char const *argv[])
{
    typeCast();
    intPromte();
    return 0;
}
