/**
 * 文件读写: https://www.runoob.com/cprogramming/c-file-io.html
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
 * 您可以使用 fopen( ) 函数来创建一个新的文件或者打开一个已有的文件，
 * 这个调用会初始化类型 FILE 的一个对象，类型 FILE 包含了所有用来控制流的必要的信息。
 * FILE *fopen(const char *filename, const char *mode);
 * filename：指向以null结尾的字符串的指针，该字符串包含了要打开的文件的名称。
 *  mode：指定文件打开方式的字符串。
 *
 * 返回值
成功时，fopen 返回一个指向 FILE 对象的指针。
失败时，返回 NULL。
 *
 */
void openFile()
{
    FILE *fp;
    char filename[] = "test.txt";
    char mode[] = "w";
    // 打开文件
    fp = fopen(filename, mode);
    if (fp == NULL)
    {
        perror("Error write file");
        return;
    }
    char buffer[256];
    // 分配内存以存储输入
    char input[256];
    printf("Enter a string (type 'exit' to stop):");
    //
    /**
     * 在 scanf 中使用 %255s 是为了限制读取的字符数，防止缓冲区溢出。这里的 255 是因为数组 input 的大小是 256，我们需要留一个位置给空终止符 \0。
     * scanf("%255s", input) == 1  代表能读取到数据
     * 。如果 scanf 成功读取了一个数据项（字符串），则表达式的值为 1（真），否则为 0（假），表示读取操作失败或到达了输入的末尾（例如，如果用户输入了一个文件末尾符 Ctrl+D 或 Ctrl+Z）。
     */
    while (scanf("%255s", input) == 1 && strcmp(input, "exit") != 0)
    {
        // 吸入字符串到文件 fprintf 在使用格式字符串写入字符串时，不会自动添加换行符。如果你需要换行，必须在格式字符串中明确包含 \n。
        fprintf(fp, "%s", input);
        // fputs(input,fp);
    }
    // 关闭文件
    fclose(fp);

    // 打开文件用于读取
    fp = fopen(filename, "r");
    {
        perror("Error read file");
        return;
    }
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
    }
    // 关闭文件
    fclose(fp);
}

/**
 * 格式化能力：
 *     fprintf 支持格式化输出，类似于 printf 函数，可以使用格式字符串来控制输出的格式，如整数、浮点数、字符等。
 *     fputs 不支持格式化，它只简单地将字符串写入文件，不会解释字符串中的任何格式说明符。
 *换行符：
    fprintf 在使用格式字符串写入字符串时，不会自动添加换行符。如果你需要换行，必须在格式字符串中明确包含 \n。
    fputs 会将字符串原样写入文件，如果字符串以换行符结尾，那么换行符也会被写入。
 *
 返回值：
    fprintf 返回一个非负整数，表示成功写入的字符数。如果发生错误，返回一个负数。
    fputs 成功时返回一个非负整数，失败时返回 EOF。

使用场景：
    当你需要输出格式化的数据时，使用 fprintf。
    当你需要快速写入一个字符串而不关心格式化时，使用 fputs。
 */
void printfAndFputs()
{
    printf("hello %s\n", "jerry");
    FILE *fp = fopen("test.txt", "w");
    if (fp == NULL)
    {
        perror("error wirite file");
        return;
    }
    fputs("hello tom", fp);
    fclose(fp);
}

void demo_file_operations()
{
    FILE *fp;
    char filename[] = "demo_file.txt";
    char mode[] = "w+"; // 读写模式，文件不存在则创建
    char buffer[100];
    int c;

    // 创建并打开文件
    fp = fopen(filename, mode);
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }

    // 写入字符串到文件
    fputs("Hello, World!\n", fp);
    fprintf(fp, "This is a demo file.\n");

    // 移动文件指针到文件开头
    rewind(fp);

    // 读取文件内容并打印
    while (fgets(buffer, sizeof(buffer), fp) != NULL)
    {
        printf("%s", buffer);
    }

    // 用于获取当前文件流的读写位置。
    long position = ftell(fp);
    printf("Current file position: %ld\n", position);

    // 移动文件指针到文件开头
    fseek(fp, 0, SEEK_SET);

    // 读取单个字符并打印
    printf("Reading characters from file:\n");
    while ((c = fgetc(fp)) != EOF)
    {
        putchar(c);
    }

    // 清除文件末尾标志
    clearerr(fp);

    // 关闭文件
    fclose(fp);

    // 删除文件
    // remove(filename);
}

void createRemoveRenameFile()
{
    FILE *tmp_fp;
    char temp_filename[] = "tempfile.txt";
    char new_filename[] = "newfile.txt";
    char buffer[100];
    int c;
    // 创建一个临时文件
    tmp_fp = tmpfile();
    if (tmp_fp == NULL)
    {
        perror("Error createing temporary file");
        return;
    }
    fputs("This is a temporary file.\n", tmp_fp);
    // 重置临时文件的文件指针，以便重新读取
    rewind(tmp_fp);
    // 从临时文件读取数据并打印
    while (fgets(buffer, sizeof(buffer), tmp_fp) != NULL)
    {
        printf("%s", buffer);
    }
    // 关闭临时文件，关闭后文件自动删除
    fclose(tmp_fp);

    // 创建一个普通文件
    FILE *fp = fopen(temp_filename, "w");
    if (fp == NULL)
    {
        perror("Error opening file");
        return;
    }
    //写入数据到普通文件
    fputs("This is a regular file.\n",fp);
    //关闭普通文件
    fclose(fp);
    //rename 为 0 代表重命名成功
    if (rename(temp_filename,new_filename) != 0)
    {
        perror("Error renaming file");
        return;
    }
    printf("File rename to %s\n",new_filename);

    if (remove(new_filename) != 0)
    {
        perror("Error remove file");
        return;
    }
     // 验证文件删除
    printf("File %s has been deleted.\n", new_filename);
    
}

int main(int argc, char const *argv[])
{
    openFile();

    printfAndFputs();

    demo_file_operations();

    createRemoveRenameFile();
    return 0;
}
