#include <stdio.h>

void printd(int n);


int main()
{
    int n = -12334;

    printd(n);
}


void printd(int n)
/* 数字转字符串（递归实现）*/
{
    if (n < 0)
    {
        putchar('-');
        n = -n;
    }
    if (n / 10)
        printd(n / 10);

    putchar(n % 10 + '0');
}
