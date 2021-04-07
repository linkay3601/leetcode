#include <stdio.h>

void shellSort(int v[], int n);


int main()
{
    int number[] = {1, 4, 6, 2, 8, 5, 7, 8, 3, 2, 4, 1};
    int i;

    shellSort(number, 12);
    printf("sort number result is: ");
    for (i = 0; i < 12; i++)
        printf("%d ", number[i]);
    printf("\n");
}


void shellSort(int v[], int n)
/* 希尔排序（高阶插入排序）*/
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)  // 计算增量值 gap 的序列
        for (i = gap; i < n; i++)         // 依据增量值 gap 对数组进行分组并进行简单插入排序
            for (j = i - gap; j >= 0 && v[j] > v[j + gap]; j-= gap) {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}
