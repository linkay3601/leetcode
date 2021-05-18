#include <stdio.h>

int main()
/* 拷贝输入流 */
{
    int c;

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }
    
}
