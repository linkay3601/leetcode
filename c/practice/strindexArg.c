#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getLine(char s[], int lim);

/* 简易 grep 改进版（带参数） */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;

    if (argc != 2)
        printf("Usage: find pattern");
    else
        while (getLine(line, MAXLINE) > 0)
            if (strstr(line, argv[1]) != NULL) {
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
