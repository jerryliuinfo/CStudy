#include <stdio.h>
#include <stdlib.h>

#include <string.h>
#include <assert.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <stddef.h>

void print_stars(int n)
{
    while (n-- > 0)
    {
        putchar('*');
    }
}

int main(int argc, char const *argv[])
{
    for (size_t i = 0; i < 5; i++)
    {
        print_stars(i);
        putchar('\n');
    }
    
    return 0;
}
