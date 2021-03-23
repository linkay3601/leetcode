#include <stdio.h>

#define MAXLINE 1000

int getLine(char line[], int maxLine);
void copy(char to[], char from[]);

int main()
/* 获取最长的字符数组并打印 */
{
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longest, line);
        }
    }
    if (max > 0)
    {
        printf("%s", longest);
    }
    return 0;
}


int getLine(char s[], int lim)
{
    int c;
    int i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;  // 字符数组赋值
    }
    if (c == '\n')
    {
        s[i] = c;  // 紧接添加换行符
        ++i;
    }
    s[i] = '\0';   // 结尾添加字符数组结束符
    return i;
}


void copy(char to[], char from[])
{
    int i;

    i = 0;
    /* 字符数组拷贝操作，方式很新颖 */
    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
    
}
