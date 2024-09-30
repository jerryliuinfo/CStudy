/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-05 11:26:35
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-05 15:27:18
 * @FilePath: /Hello/CainiaoC/MemoryAdmin.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * 内存管理
 * https://www.runoob.com/cprogramming/c-memory-management.html
 */

/**
 * 内存管理
 * 动态分配内存
 * 编程时，如果您预先知道数组的大小，那么定义数组时就比较容易。例如，一个存储人名的数组，它最多容纳 100 个字符，
 * 所以您可以定义数组，如下所示：

char name[100];
但是，如果您预先不知道需要存储的文本长度，例如您想存储有关一个主题的详细描述。
在这里，我们需要定义一个指针，该指针指向未定义所需内存大小的字符，后续再根据需求来分配内存，
 */
void memoryMgr()
{
    char name[100];
    char *description;
    // 拷贝 hello 到 name 中
    strcpy(name, "Hello");
    // malloc： 在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的。
    //  description =(char *) malloc(200 * sizeof(char));
    description = (char *)calloc(200, sizeof(char));

    if (description == NULL)
    {
        fprintf(stderr, "Error-unable to allocated requeired memory\n");
    }
    else
    {
        // 拷贝 "world" 到 description 中
        strcpy(description, "world");
    }
    // 输出 hello
    printf("name:%s\n", name);
    // 输出 word
    printf("description:%s\n", description);
    printf("sizeof(description):%lu\n", sizeof(description));

    // 重新分配内存 为 300*sizeof(char)
    description = realloc(description, 300 * sizeof(char));
    if (description == NULL)
    {
        fprintf(stderr, "Error-unable to allocated requeired memory\n");
    }
    else
    {
        strcat(description, " add a long desc");
    }
    printf("after realloc description:%s\n", description);
    printf("after realloc  sizeof(description):%lu\n", sizeof(description));

    free(description);
}

int main(int argc, char const *argv[])
{
    memoryMgr();
    return 0;
}
