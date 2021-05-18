#include <string.h>
#include <stdio.h>

void reverse(char s[]);


int main()
{
    char string[] = "hello, world";

    reverse(string);
    printf("reversed string is: %s\n", string);
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
