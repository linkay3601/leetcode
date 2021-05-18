#include <stdio.h>

int strLen(char *s);


int main()
{
    char string[] = "hello, world";
    printf("this char arrary len is: %d\n", strLen(string + 2));
}


int strLen(char *s)
/* 计算字符数组（字符串）的长度 */
{
    int n;

    for (n = 0; *s != '\0'; s++)
        n++;
    return n;
}
