#include <stdio.h>

int strCmp(char *s, char *t);


int main()
{
    char str1[] = "hello, world";
    char str2[] = "hello, linkay";

    printf("str1 compare str2 is: %d\n", strCmp(str1, str2));
}


int strCmp(char *s, char *t)
/* 逐个比较两个字符串中的字符（数组实现）*/
{
    int i;

    for (i = 0; s[i] == t[i]; i++)
    {
        if (s[i] == '\0')
            return 0;
    }

    return s[i] - t[i];
}
