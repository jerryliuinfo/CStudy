#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

void (*signal(int, void (*)(int)))(int);

typedef void (*pfun_t)(int);

pfun_t signal(int, pfun_t);

int add(int x, int y)
{
    return x + y;
}

int sub(int x, int y)
{
    return x - y;
}

int mul(int x, int y)
{
    return x * y;
}

int division(int x, int y)
{
    return x / y;
}

/**
 * 函数指针数组
 */
void funcPointerArray()
{
    int (*pfAdd)(int, int) = add;
    int (*pfSub)(int, int) = sub;
    // pfArr 是函数指针数组,存放同类型的函数指针
    int (*pfArr[2])(int, int) = {add, sub};
}

void menu()
{
    printf("************************\n");
    printf("**********请选择**************\n");
    printf("*******1、add     2、sub ********\n");
    printf("*******3、mul     4、div ********\n");
    printf("********0、 exit  5、重新选择 ****************\n");
}

void calcNormal()
{
    int input = 0;
    do
    {
        menu();
        int x = 0;
        int y = 0;
        int ret = 0;
        printf("请选择:>");
        scanf("%d", &input);
        switch (input)
        {
        case 1:
            printf("请输入2个操作数>:");
            scanf("%d %d", &x, &y);
            ret = add(x, y);
            break;
        case 2:
            printf("请输入2个操作数>:");
            scanf("%d %d", &x, &y);
            ret = sub(x, y);
            break;
        case 3:
            printf("请输入2个操作数>:");
            scanf("%d %d", &x, &y);
            ret = mul(x, y);
            break;
        case 4:
            printf("请输入2个操作数>:");
            scanf("%d %d", &x, &y);
            ret = division(x, y);
            break;
        case 5:
            printf("输入错误，请重新选择:\n");

            break;
        case 0:
            printf("退出");
            break;

        default:
            break;
        }

    } while (input);
}

/**
 * 函数指针数组
 */
void calcByFuncPointerArray()
{
    int input = 0;
    do
    {
        int (*parr[5])(int, int) = {NULL, add, sub, mul, division};

        menu();
        int x = 0;
        int y = 0;
        int ret = 0;
        printf("请选择:>");
        scanf("%d", &input);
        if (input >= 1 && input <= 4)
        {

            printf("请输入2个操作数>:");
            scanf("%d %d", &x, &y);

            ret = parr[input](x, y);
            printf("ret: %d \n", ret);
        }
        else if (input == 0)
        {
            printf("退出程序\n");
            break;
        }
        else
        {
            printf("选择错误，请重新输入\n");
        }

    } while (input);
}





int main(int argc, char const *argv[])
{

    // calcNormal();
    calcByFuncPointerArray();

    return 0;
}
