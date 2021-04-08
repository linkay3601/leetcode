#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100

double atof(char s[]);
int getLine(char s[], int lim);


int main()
/* 简易计算簿 */
{
    double sum;
    char line[MAXLINE];

    sum = 0;
    while (getLine(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));

    return 0;
}


double atof(char s[])
/* 字符串转浮点型数 */
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-')? -1: 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    return sign * val / power;
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
