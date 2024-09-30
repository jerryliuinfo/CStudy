#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * https://www.runoob.com/cprogramming/c-header-files.html
 * C 或 C++ 程序中，建议把所有的常量、宏、系统全局变量和函数原型写在头文件中，在需要的时候随时引用这些头文件。
 */

// 有条件引用
#if SYSTEM_1
   # include "system_1.h"
#elif SYSTEM_2
   # include "system_2.h"
#elif SYSTEM_3
   ...
#endif


// 但是如果头文件比较多的时候，这么做是很不妥当的，预处理器使用宏来定义头文件的名称。这就是所谓的有条件引用。它不是用头文件的名称作为 #include 的直接参数，您只需要使用宏名称代替即可：

#define SYSTEM_H "system_1.h"

int main(int argc, char const *argv[])
{
    
    return 0;
}
