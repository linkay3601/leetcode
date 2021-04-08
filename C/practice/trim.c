#include <stdio.h>
#include <string.h>

int trim(char s[]);


int main()
{
    char string[] = "hello, world     \n  ";
    int n;

    n = trim(string);
    printf("remove white space result is: %s, index is %d\n", string, n);
}


int trim(char s[])
/* 清除字符串末尾的空白符 */
{
    int n;

    for (n = strlen(s) - 1; n >= 0; n--)
        if (s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
            break;
    s[n + 1] = '\0';
    return n;
}
