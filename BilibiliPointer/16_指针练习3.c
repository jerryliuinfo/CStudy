/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-26 09:19:13
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-27 20:33:51
 * @FilePath: /Hello/BilibiliPointer/16_指针练习3.c
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

void test1()
{
    /**
     * 1、a 是一个素组，数组中的每个元素是 char* （”work“中的 "w", "at"中的 a, "alibaba"中的 a ）这3个字符的地址放到了 a 中
     * 2、char** p = a:  a 是数组，默认是指向首元素地址，由于元素类型是 char *, 对 char* 取地址，就是 2级指针，赋值给 har** p 这个二级指针
     * 3、pa++:  pa 本来是指向 "work"这个字符指针的地址，+！：只想 at这个字符指针的地址
     * 4、*pa: 对 pa 解引用，得到的是一级指针，指向 ”at“中的 字符 a 的地址
     * 5、%s打印: 打印从 a 开始的字符串， 输出: at
     */
    char *a[] = {"work", "at", "alibaba"};
    char **pa = a;
    // 指向 at 这个字符指针的地址
    pa++;
    printf("%s\n", *pa);
}

void test2()
{
    /**
     * 1、c 是字符指针数组, 数组里面的元素都是 字符串的首字符地址，例如 E、N 的地址
     * 2、cp 是二级指针
     *    c +3 指向的是 存放 First 的 首字符 F 的内存地址,
     *    c +2 指向的是 存放 Point 的 首字符 P 的内存地址,
     *    c +1 指向的是 存放 New 的 首字符 N 的内存地址,
     *    c    指向的是 存放 FIRST 的 首字符 F 的内存地址,
     * 3、cpp 存放的是 cp 这个二级指针的地址，也就是三级指针 ,所以是 3 个 *
     *
     *
     */
    char *c[] = {"ENTER", "NEW", "POINT", "FIRST"};
    char **cp[] = {c + 3, c + 2, c + 1, c};
    char ***cpp = cp;
    // 4、++cpp 只想的是 cp 中的 c +2 的地址，* 解引用拿到的是 c+2这个地址的内容，c+2 的内容为 POINT首字符 P 的地址，再对P的地址做解引用，得到的是 P 的内容: P, %s 打印出从 P开始的内容

    printf("%s\n", **++cpp);
    /**
     * 输出 ER （POINT的第三个字符开始）
     *1、 ++cpp：指向的是 c+2的地址（前面 cpp已经自增了一次）
     */
    printf("%s\n", *--*++cpp + 3);
    // 输出 ST （FIRST 从第 3个字符开始）
    printf("%s\n", *cpp[-2] + 3);
    printf("%s\n", *cpp[-1][-1] + 1);
}

void charTest()
{
    char *p = "hello world";
    printf("%p:%c\n", p, *p);
    p++;
    printf("%p:%c", p, *p);
}

void testCharEquals()
{
    char str1[] = "hello world";
    char str2[] = "hello world";
    if (str1 == str2)
    {
        printf("str1 and str2 are the same\n");
    }
    else
    {
        printf("str1 and str2 are not the same\n");
    }
    printf("str1:%p, str2: %p\n", str1, str2);
    // printf("%c %c\n", str1, str2);

    char *str3 = "hello world";
    char *str4 = "hello world";

    if (str3 == str4)
    {
        printf("str3 and str4 are the same\n");
    }
    else
    {
        printf("str3 and str4 are not the same\n");
    }
    printf("str3:%p,str4: %p\n", str3, str4);
    printf("%c %c\n", *str3, *str4);
}

int main(int argc, char const *argv[])
{
    // test1();

    // test2();

    charTest();
    testCharEquals();

    return 0;
}
