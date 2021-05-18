#include <stdio.h>

void squeeze(char s[], int c);

int main()
{
    char string[] = "hello, world";

    squeeze(string, 'l');
    printf("%s\n", string);
}


void squeeze(char s[], int c)
/* 删除字符数组中的指定字符 */
{
    int i, j;

    for (i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c) {
            s[j++] = s[i];  // 这个 j 变量用的很刁钻
        }
    s[j] = '\0';
}
