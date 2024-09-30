#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * strchr 函数是用来在一个字符串中查找给定字符第一次出现的位置的。
 * 如果找到了该字符，函数返回指向字符串中第一次出现该字符的指针；如果没有找到，函数返回 NULL。
 */
void strchrTest()
{
    const char *greeting = "You are welcome";
    char ch = 'a';
    // 返回一个指针，指向字符串 s1 中字符 ch 的第一次出现的位置。
    char *strchrResult = strchr(greeting, ch);
    printf("greeting:%p, strchrResult:%p\n", greeting, strchrResult);
    if (strchrResult != NULL)
    {
        printf("Character %c found at position: %ld\n", ch, (strchrResult - greeting));
    }
    else
    {
        printf("Character %c not found.\n", ch);
    }
}

/**
 * strstr 函数用于在一个字符串中查找第一次出现的一个子字符串。
 * 如果找到了该子字符串，函数返回指向子字符串第一次出现位置的指针；如果没有找到，函数返回 NULL。
 */
void strstrTest()
{
    const char *str1 = "hello world";
    const char *str2 = "llo";
    char *result = strstr(str1, str2);
    if (result != NULL)
    {
        printf("SubString %s found at position: %ld\n", str2, (result - str1));
    }
    else
    {
        printf("Substring %s not found.\n", str2);
    }
}
/**
 * 截取字符串
 */
char *extractSubstring(const char *src, int start, int len)
{
    char *str = NULL;

    // 确保开始位置和长度是有效的
    if (start < 0 || len < 0 || start + len > strlen(src))
    {
        printf("Invalid parameters for substring extraction.\n");
        return NULL;
    }
    /// 动态分配足够的内存来存储子字符串和空终止符
    str = (char *)malloc(len + 1);
    if (str == NULL)
    {
        printf("内存分配失败\n");
        return NULL;
    }
    // 复制子字符串
    // strncpy(str, src + start, len);

    // 使用 snprintf 截取子字符串
    snprintf(str, sizeof(str), "%*.*s", len, len, src + start);

    str[len] = '\0'; // 手动添加空终止符

    printf("Extracted substring: %s\n", str);
    return str;
}

void subStringTest()
{
    const char *str = "Hello, World!";
    int start = 7; // 从索引7开始（"World"的开始）
    int len = 5;   // 截取5个字符

    char *result = extractSubstring(str, start, len);
    printf("substring str:%s\n", result);
}

/**
 * strcmp 函数用于比较两个字符串(区分大小写)。它返回一个整数，表示两个字符串的比较结果
 * int strcmp(const char *s1, const char *s2);
 * 参数说明：

s1：指向第一个字符串的指针。
s2：指向第二个字符串的指针。
返回值：

如果 s1 小于 s2，返回负整数。
如果 s1 等于 s2，返回 0。
如果 s1 大于 s2，返回正整数。

    strcasecmp: 区分大小写的比较

 */
void strcmpTest()
{
    const char *str1 = "Hello";
    const char *str2 = "World";
    const char *str3 = "Hello";
    // str1 小于 str2,返回 负整数
    int result1 = strcmp(str1, str2);
    // str1 等于 str2,返回 0
    int result2 = strcmp(str1, str3);
    // str2 大于 str1,返回 正整数
    int result3 = strcmp(str2, str1);
    printf("strcmp(str1,str2):%d\n", result1);
    printf("strcmp(str1,str3):%d\n", result2);
    printf("strcmp(str2,str1):%d\n", result3);

    strcacecmpTest();
}

/**
 * 修改原始字符串为小写
 */
void my_strlwr(char *src)
{
    while (*src)
    {
        *src = tolower((unsigned char)*src);
        src++;
    }
}

char *my_strlwr2(const char *src)
{
    if (src == NULL)
    {
        return NULL;
    }

    const char *temp = src;
    printf("src address:%p, temp address:%p\n", src, temp);
    // 遍历到指针末尾
    while (*temp)
    {
        temp++;
    }
    // 计算原始字符串的长度（末地址-起始地址）
    size_t len = temp - src;
    //+1 的原因是在末尾添加空字符 \0
    char *lowercase_str = (char *)malloc(len + 1);
    if (lowercase_str == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL;
    }
    for (size_t i = 0; i < len; i++)
    {
        // 为了避免潜在的负值问题，我们将字符强制转换为 (unsigned char)。
        lowercase_str[i] = tolower((unsigned char)src[i]);
        // lowercase_str[i] = toupper((unsigned char)src[i]);
    }
    // 添加空终止符
    lowercase_str[len] = '\0';
    return lowercase_str;
}

/**
 * 函数用于将字符串中的所有大写字母转换为小写字母。
 */
void strlwrTest()
{
    char str[] = "Hello World";
    // 会修改原始值
    my_strlwr(str);
    printf("Original string:%s\n", str);

    const char *src = "You are welcome";
    char *lowcase_str = my_strlwr2(src);
    if (lowcase_str != NULL)
    {
        printf("orginal string:%s\n", src);
        printf("lowcase string:%s\n", lowcase_str);

        // free(lowcase_str);
    }
}


void commonError(){
    char greeting[6] = {'H','e','l','l','o'};
    //种写法是错的 
    char greeting2[5] = {'H','e','l','l','o'};
    //在使用不定长数组初始化字符串时默认结尾为 \0
    char greeting3[] = "Hello";
    printf("greeting:%s, sizeof:%lu,len:%lu\n",greeting,sizeof(greeting),strlen(greeting));
    //会暑促 Hello烫烫烫?侵7(?╔?╚╔╔
    printf("greeting2:%s, sizeof:%lu,len:%lu\n",greeting2,sizeof(greeting2),strlen(greeting2));
    printf("greeting3:%s, sizeof:%lu,len:%lu\n",greeting3,sizeof(greeting3),strlen(greeting3));
}

/**
 * 不区分大小写的比较两个字符串。
 */
void strcacecmpTest(){
    const char *str1 = "Hello";
    const char *str2 = "hello";
    const char *str3 = "HELLO";
    const char *str4 = "hello world";
     // 比较 str1 和 str2，不区分大小写 
    if (strcasecmp(str1, str2) == 0) {
        printf("'%s' and '%s' are equal (case insensitive).\n", str1, str2);
    }

    // 比较 str1 和 str3，不区分大小写
    if (strcasecmp(str1, str3) == 0) {
        printf("'%s' and '%s' are equal (case insensitive).\n", str1, str3);
    } else {
        printf("'%s' and '%s' are not equal (case insensitive).\n", str1, str3);
    }

    // 比较 str2 和 str4，不区分大小写
    if (strcasecmp(str2, str4) == 0) {
        printf("'%s' and '%s' are equal (case insensitive).\n", str2, str4);
    } else {
        printf("'%s' and '%s' are not equal (case insensitive).\n", str2, str4);
    }
    
}

void testString()
{
    char str1[20] = "hello";
    char str2[] = "world";
    char str3[14];
    // 字符串 1 拷贝到 字符串 3
    strcpy(str3, str1);
    printf("strcpy(str3, str1): %s\n", str3);
    // 连接字符串 s2 到字符串 s1 的末尾。
    strcat(str1, str2);
    printf("strcat(str1,str2): %s\n", str1);
    // 字符串 str1 的长度
    int len = strlen(str1);
    printf("strlen(str1):%d\n", len);

    strchrTest();

    strstrTest();

    subStringTest();

    strcmpTest();

    strlwrTest();

    commonError();

}

int main(int argc, char const *argv[])
{
    testString();
    return 0;
}
