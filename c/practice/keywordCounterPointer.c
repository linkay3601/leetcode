/* 关键字必须按照升序存储（因为这里使用的是“折半查找”）*/
struct key {
    char *word;
    int count;
} keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0
};

#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXWORD 100
#define NKEYS (sizeof keytab / sizeof(keytab[0]))

int getword(char *, int);
struct key *binsearch(char *, struct key *, int);

/* 关键字计数（结构指针实现） */
int main()
{
    char word[MAXWORD];
    struct key *p;

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((p = binsearch(word, keytab, NKEYS)) != NULL)
                p->count++;
    for (p = keytab; p < keytab + NKEYS; p++)
        if (p->count > 0)
            printf("%4d %s/n", p->count, p->word);
    return 0;
}


/* 折半查找 */
struct key *binsearch(char *word, struct key *tab, int n)
{
    int cond;
    struct key *low = &tab[0];
    struct key *high = &tab[n];
    struct key *mid;

    while (low < high) {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return NULL;
}


/* -------------------------------------------------------------------------- */
/* 从输入中读取下一个单词 */
int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);

    char *w = word;

    while (isspace(c = getch()))
        ;
    if (c != EOF)
        *w++ = c;
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++)
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    *w = '\0';
    return word[0];
}


/**
 * getch 和 ungetch 作用？
 * 
 * 程序不能确定它已经读入的输入是否足够，除非超前读入一些输入。
 */
#define BUFSIZE 100

char buf[BUFSIZE];  // 缓存空间
int bufp = 0;

int getch(void)
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
