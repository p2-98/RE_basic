#include <stdio.h>;

int main()
{
    int a[100][100];
    int n, max = 0;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            scanf("%d",&a[i][j]);
            if (a[i][j] > max)
                max = a[i][j];
        }
    printf("%d", max);
    return 0;
}
/*Tìm giá trị lớn nhất trong mảng 2 chiều n*n
input
5
1 2 3 4 5
5 6 7 8 9
5 6 9 7 2
10 18 12 14 1
1 2 3 6 7
output
18*/
