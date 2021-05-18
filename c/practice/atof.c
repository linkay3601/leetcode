#include <ctype.h>
#include <stdio.h>

double atof(char s[]);


int main()
{
    char string[] = "           -123443.3234";
    double n;

    n = atof(string);
    printf("string to double number is: %f\n", n);
}


double atof(char s[])
/* 字符串转浮点型数 */
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-')? -1: 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (val = 0.0; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');
    if (s[i] == '.')
        i++;
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10;
    }

    return sign * val / power;
}
