#include <stdio.h>

int strCmp(char *s, char *t);


int main()
{
    char str1[] = "hello, world";
    char str2[] = "hello, linkay";

    printf("str1 compare str2 is: %d\n", strCmp(str1, str2));
}


int strCmp(char *s, char *t)
/* 逐个比较两个字符串中的字符（指针版）*/
{
    for (; *s == *t; s++, t++)
        if (*s == '\0')
            return 0;
    return *s - *t;
}
