#include <stdio.h>
#include <string.h>

void reverse(char s[]);
void itoa(int n, char []);


int main()
{
    int n = -233431;
    char string[10];

    itoa(n, string);
    printf("digits to string is: %s\n", string );
}


void itoa(int n, char s[])
/* 数字转字符串 */
{
    int i, sign;

    i = 0;
    if ((sign = n) < 0)
        n = -n;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}


void reverse(char s[])
/* 反转字符串 */
{
    int c, i, j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
