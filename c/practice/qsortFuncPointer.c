/**
 * 目前无法编译成功！
 */
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000

char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
int numcmp(char *, char *);

void writelines(char *lineptr[], int nlines);
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

/* sort 命令改进（函数指针实现） */
int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;  // 是否根据数值排序

    if (argc > 1 && strcmp(argv[1], "-n") >= 0) {
        qsort((void**) lineptr, 0, nlines - 1, (int (*)(void*, void*))(numeric? numcmp: strcmp));
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("input too big to sort\n");
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
/* 快速排序 */
void qsort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;

    void swap(void *v[], int, int);

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = right;
    for (i = left + 1; i <= right; i++)
        if ((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1, comp);
    qsort(v, last + 1, right, comp);
}


#include <stdlib.h>

/* 字符串数值比较 */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if (v1 > v2)
        return 1;
    else
        return 0;
}


/* 交换函数 */
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
