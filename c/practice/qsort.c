#include <stdio.h>

void qsort(int v[], int left, int right);
void swap(int v[], int i, int j);


int main()
{
    int n[] = {6, 4, 8, 2, 9, 1, 2, 1};
    int i;

    qsort(n, 0, 7);
    printf("quick sort number result is: ");
    for (i = 0; i <= 7; i++)
        printf("%d", n[i]);
    printf("\n");

    return 0;
}


void qsort(int v[], int left, int right)
/* 快速排序（高阶冒泡排序）*/
{
    int i, last;

    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);  // 将基准值放到最左边，方便进行比较
    last = left;
    for (i = left + 1; i <= right; i++)
        if (v[i] < v[left])
            swap(v, ++last, i);
    swap(v, left, last);  // 将基准值与最右边小于它的值调换位置
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}


void swap(int v[], int i, int j)
/* 交换数组元素 */
{
    int temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
