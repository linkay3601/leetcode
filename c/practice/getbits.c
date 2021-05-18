#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);

int main()
{
    unsigned int n1 = 255;
    printf("%d\n", getbits(n1, 5, 3));
}


unsigned getbits(unsigned x, int p, int n)
/*
    返回指定位范围的值，从右往左数第 p 位开始（假定最右边位为第 0 位）连续 n 位的值

    解析
        ~(~0 << n) ：    是为了屏蔽 x 的高位
        x >> (p + 1 -n)：是为了将指定的范围位移动到最右端

*/
{
    return (x >> (p + 1 -n) & ~(~0 << n));
}
