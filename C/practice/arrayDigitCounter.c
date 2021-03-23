#include <stdio.h>

int main()
/* 数组计数 */
{
    int c;
    int i;
    int nwhite;
    int nother;
    int ndigit[10];

    nwhite = nother = 0;
    for (i = 0; i < 10; i++)
    {
        ndigit[i] = 0;
    }
    
    while ((c = getchar()) != EOF)
    {
        if (c >= '0' && c <= '9')
        {
            ++ndigit[c-'0'];
        } else if (c == ' ' || c == '\n' || c == '\t')
        {
            ++nwhite;
        } else
        {
            ++nother;
        }
    }
    
    printf("dights =");
    for (i = 0; i < 10; i++)
    {
        printf(" %d", ndigit[i]);
    }
    printf(", white space = %d, other = %d\n", nwhite, nother);
}
