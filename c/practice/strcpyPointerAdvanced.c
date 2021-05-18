#include <stdio.h>

void strCpy(char *s, char *t);


int main()
{
    char str1[] = "hello, world";
    char str2[16];

    strCpy(str2, str1);
    printf("now the str2 is: %s\n", str2);
}


void strCpy(char *s, char *t)
/* 字符串复制（指针高阶版）*/
{
    while ((*s++ = *t++))  // 因为 '\0' 的对应 ASCII 为 0，所以可以简化成这样
        ;
}
