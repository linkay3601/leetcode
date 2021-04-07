#include <stdio.h>

int binsearch(int x, int v[], int n);


int main()
{
    int array[] = {1, 2, 8, 9, 10, 11, 13, 15, 19};
    printf("binsearch return %d\n", binsearch(8, array, 5));
}


int binsearch(int x, int v[], int n)
/* 折半查找法查找对应元素 */
{
    int low, high, mid;

    low = 0;
    high = n - 1;  // 这里 n 指的是查找范围
    while (low <= high) {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}
