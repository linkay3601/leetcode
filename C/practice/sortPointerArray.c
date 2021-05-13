#include <stdio.h>
#include <string.h>

#define MAXLINES 5000  // 存储的最大行数

char *lineptr[MAXLINES];  // 指向问本行的指针数组

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);
void qsort(char *lineptr[], int left, int right);

int main()
/* 简化版 sort 命令（指针数组实现） */
{
    int nlines;  // 读取到的输入行数量

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else
    {
        printf("error: input too big to sort\n");
        return 1;
    }
}


/* -------------------------------------------------------------------------- */
#define MAXLINE 1000  // 输入行的最大长度

int getLine(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
/* 读取每一行 */
{
    int len, nlines;
    char *p, line[MAXLINE];

    nlines = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';  // 删除换行符
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return  nlines;
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


void writelines(char *lineptr[], int nlines)
/* 打印每一行 */
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}


/* -------------------------------------------------------------------------- */
void swap(char *v[], int i, int j);

void qsort(char *v[], int left, int right)
{
    int i, last;

    if (left >= right)
        return;
    swap(v, left, right);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, right);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}


void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[j] = v[i];
    v[j] = temp;
}
