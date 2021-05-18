#include <stdio.h>

int bitcount(unsigned x);

int main(void)
{
    unsigned int x = 255;

    printf("%d\n", bitcount(x));
    return 0;
}


int bitcount(unsigned x)
/* 计无符号整数值中值为 1 的二进制位的个数 */
{
    int b;
    for (b = 0; x != 0; x >>= 1) {
        if (x & 01)  // 这里的 01 是八进制 1
        {
            b++;
        }
    }

    return b;
}
