#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>

/**
 * https://www.runoob.com/cprogramming/c-error-handling.html
 * 
 */


/**
 * C 语言提供了 perror() 和 strerror() 函数来显示与 errno 相关的文本消息。
    perror() 函数显示您传给它的字符串，后跟一个冒号、一个空格和当前 errno 值的文本表示形式。
    strerror() 函数，返回一个指针，指针指向当前 errno 值的文本表示形式。
 * 
 */
void printError(){
    FILE * fp;
    int errnum;
    fp = fopen("unexist.xt", "rb");
    if (fp == NULL)
    {
       errnum = errno;
       fprintf(stderr, "错误号:%d\n",errno);
       perror("通过 perror 输出错误");
       //strerror(errno): 根据错误码获取错误信息
       fprintf(stderr, "打开文件错误:%s\n",strerror(errno));
    }
    

    int dividend = 20;
    int divisor = 5;
    if (divisor == 0)
    {
       fprintf(stderr,"除数为 0 退出运行\n");
    //    exit(-1);
       exit(EXIT_FAILURE);
    }
    int quotient = dividend / divisor;
    fprintf(stderr, "quotient 变量的值为: %d\n",quotient);
    
}



int main(int argc, char const *argv[])
{
    printError();
    return 0;
}
