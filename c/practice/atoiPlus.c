#include <ctype.h>
#include <stdio.h>

int atoi(char s[]);


int main()
{
    char string[] = "       -12345";
    printf("string to number is: %d\n", atoi(string));
}


int atoi(char s[])
/* 字符串转整型（带符号位）*/
{
    int i, n, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-')? -1: 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');

    return sign * n;
}
