#include <stdio.h>

int main()
/* 华氏温度与摄氏温度对照表 */
{
    float fahr;
    float celsius;

    float lower;
    float upper;
    float step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper)
    {
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%3.0f\t%6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
    
}
