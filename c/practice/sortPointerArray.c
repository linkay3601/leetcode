#include <stdio.h>
#include <string.h>

#define MAXLINES 5000  // 最大可排序的行数

char *lineptr[MAXLINES];  // 文本行的指针数组

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);  // 快速排序

int main()
{
    int nlines;

    if ((nlines = readlines(lineptr, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}

/* -------------------------------------------------------------------------- */

#define MAXLEN 1000  // 输入行的最大长度
int getLine(char *, int);
char *alloc(int);

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getLine(line, MAXLEN)) > 0)
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
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

#define ALLOCSIZE 10000  // 可用的空间

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
/* 分配空间 */
{
    if (allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp += n;
        return allocp - n;
    } else
    {
        return 0;
    }
}

/* -------------------------------------------------------------------------- */

/**
 * * 写法一
 * // void writelines(char *lineptr[], int nlines)
 * // {
 * //     int i;
 * // 
 * //     for (i = 0; i < nlines; i++)
 * //         printf("%s\n", lineptr[i]);
 * // }
 */

/* 写法二 */
void writelines(char *lineptr[], int nlines)
{
    while (nlines-- > 0)
        printf("%s\n", *lineptr++);
}

/* -------------------------------------------------------------------------- */

void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 1);  // 将基准值放到最左边，方便进行比较
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)  // 比较两个字符串中的字符
            swap(v, ++last, i);
    swap(v, left, last);  // 将基准值与最右边小于它的值调换位置
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
