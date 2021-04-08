#include <stdio.h>

#define MAXLINE 1000

int getLine(char s[], int lim);
int strindex(char s[], char t[]);

char pattern[] = "ould";


int main()
/* 简单 grep 命令实现 */
{
    char line[MAXLINE];
    int found = 0;

    while (getLine(line, MAXLINE))
        if (strindex(line, pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }

    return found;
}


int getLine(char s[], int lim)
/* 获取下一行输入 */
{
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';

    return i;
}


int strindex(char s[], char t[])
/* 字符串中匹配指定模式 */
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] == '\0')
            return i;
    }

    return -1;
}
