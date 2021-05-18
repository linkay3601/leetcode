#include <stdio.h>

int lower(char c);

int main()
{
    char c = 'M';
    printf("%c\n", lower(c));
}


int lower(char c)
/* 大写字符转小写字符 */
{
    if (c >= 'A' && c<= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
