/*
 * @Author: jerry liuxiangxiang1234@163.com
 * @Date: 2024-09-04 10:17:50
 * @LastEditors: jerry liuxiangxiang1234@163.com
 * @LastEditTime: 2024-09-04 15:08:10
 * @FilePath: /Hello/CainiaoC/Struct.c
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * 结构体模板
 * struct tag {
    member-list
    member-list
    member-list
    ...
} variable-list ;

    tag: 结构体标签
    member-list：变量定义
    variable-list:结构变量，定义在结构的末尾，
    最后一个分号，可以指定一个或多个结构变量

 *
 */

struct Book
{
    char title[50];
    char author[50];
    int bookId;
} book;

/**
 * 结构体的成员可以包含其他结构体，也可以包含指向自己结构体类型的指针，而通常这种指针的应用是为了实现一些更高级的数据结构如链表和树等。
 */
struct COMPLEX
{
    char string[100];
    struct Book book;
};

struct Book2
{
    char title[50];
    char author[50];
    int bookId;
} book2 = {
    "C 语言",
    "Runoob",
    100};

void structAssignValue()
{
    struct Book book = {"zhangsan", "C 语言设计", 100};

    printf("title:%s,author:%s,bookId:%d\n", book.title, book.author, book.bookId);

    printf("title:%s,author:%s,bookId:%d\n", book2.title, book2.author, book2.bookId);

    struct Book book1;

    struct Book book2;

    strcpy(book1.title, "Java 程序设计");
    strcpy(book1.author, "lisi");
    book1.bookId = 2000;
    printf("after modify title:%s,author:%s,bookId:%d\n", book1.title, book1.author, book1.bookId);
}

/**
 * 结构作为函数参数
 */
void structAsFunctionParam(struct Book book)
{
    printf("structAsFunctionParam title:%s,author:%s,bookId:%d\n", book.title, book.author, book.bookId);
}

/**
 * 通过指针地址访问结构体属性
 */
void printBook(struct Book *book)
{
    printf("Book title:%s,author:%s,bookId:%d\n", book->title, book->author, book->bookId);
}

/**
 * 指向结构的指针
 */
void pointToStructPointer()
{
    struct Book book = {"zhangsan", "C 语言设计", 100};
    printBook(&book);
}

/**
 * 结构体大小计算
 */
void calculateStructSize()
{
    struct Book book = {"zhangsan", "C 语言设计", 100};
    printf("结构体 Book 大小为:%zu 字节\n", sizeof(book));

    struct Book book2;
    printf("结构体 book2 大小为:%zu 字节\n", sizeof(book));
}

#define MAX_TITLE 41
#define MAX_AUTHOR 31
#define MAX_BKS 100

/**
 * 结构体数组
 */
void structArray()
{
    struct Book library[MAX_BKS];
}

void structInit()
{
    struct Book book1 = {
        "C 语言", "李晓明", 10};
    struct Book book2;
    printf("title:\n");
    scanf("%s",book2.title);

    printf("author:\n");
    scanf("%s", book2.author);

    printf("bookId:\n");
    scanf("%d", &book2.bookId);

    printf("book1 title:%s, author:%s,bookId:%d\n", book1.title, book1.author, book1.bookId);
    printf("book2 title:%s, author:%s,bookId:%d\n", book2.title, book2.author, book2.bookId);
}

int main(int argc, char const *argv[])
{
    structAssignValue();

    struct Book book = {"zhangsan", "C 语言设计", 100};
    structAsFunctionParam(book);

    pointToStructPointer();

    calculateStructSize();

    structInit();

    return 0;
}
