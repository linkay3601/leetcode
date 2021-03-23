#include <stdio.h>

int main()
/* 行计数 */
{
    int c;
    int nl;

    nl = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
        {
            ++nl;
        }
    }
    printf("%d\n", nl);
}
