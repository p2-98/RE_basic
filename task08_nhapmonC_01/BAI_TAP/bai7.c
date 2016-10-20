#include <stdio.h>;

int main()
{
    int a[100][100];
    int n, min = 9999;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
            if (a[i][j] < min)
                min = a[i][j];
        }
    printf("%d", min);
    return 0;
}
/*Tìm giá trị nhỏ nhất trong mảng 2 chiều n*n
input
3
1 2 3
4 5 6
7 8 9
output
1*/
