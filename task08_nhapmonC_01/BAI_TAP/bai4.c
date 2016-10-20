#include <stdio.h>

int a[100];
int main()
{
    int n, max = 0;
    scanf("%d", &n);
    printf("%d",n);
    for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] > max)
                max = a[i];
        }
    printf("%d", max);
    return 0;
}
/*Tìm giá trị lớn nhất trong mảng:
Input
3
1 2 3
output
3*/
