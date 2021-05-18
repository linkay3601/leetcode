#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int c);
int getint(int *pn);


int main()
{
    int n;
    int array[3];

    for (n = 0; n < 3 && getint(&array[n]) != EOF; n++)
        ;
    printf("the end result is: ");
    for (n = 0; n < 3; n++)
        printf("%d ", array[n]);
    printf("\n");

    return 0;
}


int getint(int *pn)
/* 从标准输入获取数字值并给指定目标赋值 */
{
    int c, sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-')? -1: 1;
    if (c == '+' || c == '-')
        c = getch();
    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');
    *pn *= sign;
    if (c != EOF)
        ungetch(c);

    return c;
}


#define BUFSIZE 100

char buf[BUFSIZ];  // ungetch 的缓存
int bufp = 0;      // 缓存的下一个空闲位置


int getch(void)
/* 反读 字符 */
{
    return (bufp > 0)? buf[--bufp]: getchar();
}


void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
