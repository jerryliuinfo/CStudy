#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

int main(int argc, char const *argv[])
{
    int a[5] = {1, 2, 3, 4, 5};
    //
    int *ptr = (int *)(&a + 1);
    //输出 2 5 解释: ptr -1 指向 a 的最后一个元素地址
    printf("%d %d", *(a + 1), *(ptr - 1));

    return 0;
}
