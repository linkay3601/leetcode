#include <stdio.h>

static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day);
int month_day(int year, int yearday, int *pmonth, int *pday);

int main()
{
    //// int year = 2008;
    //// int month = 3;
    //// int day = 30;

    //// int yearday;

    //// yearday = day_of_year(year, month, day);
    //// printf("%dth of a year\n", yearday);

    int year = 2008;
    int yearday = 61;

    int pmonth;
    int pday;

    month_day(year, yearday, &pmonth, &pday);
    printf("%d month %d day\n", pmonth, pday);
}

// x 月 x 日 => 第 x 天
int day_of_year(int year, int month, int day)
{
    int i, leap;
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; i < month; i++)
    {
        day += daytab[leap][i];
        return day;
    }
}

// 第 x 天 => x 月 x 日
int month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;

    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}
