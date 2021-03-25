#include <stdio.h>

int atoi(char s[]);

int main()
{
    char string[] = "1212121";
    printf("%d\n", atoi(string));
}


int atoi(char s[])
/* 字符数组转换为数值型 */
{
    int i, n;

    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; i++) {
        n = 10 * n + (s[i] - '0');
    }

    return n;
}
