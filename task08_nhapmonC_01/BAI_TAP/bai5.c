#include <stdio.h>

int a[100];
int main()
{
    int n, min = 999;
    scanf("%d", &n);
    printf("%d",n);
    for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] < min)
                min = a[i];
        }
    printf("%d", min);
    return 0;
}

Tìm giá trị nhỏ nhất trong mảng:
input
3
3 6 1
output
1
