#include <stdio.h>

int main()
{
    int a[100][100];
    int n, x, check = 0;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
            if (a[i][j] == x)
                    check = 1;
        }

    if (check == 1)
        printf("Yes");
    else
        printf("No");
    return 0;
}
/*Kiểm tra xem x có thuộc trong mảng A không:
input
3 2
1 2 3
6 8 7
1 5 8
output
yes
input
2 1
2 3
6 9
output
no*/
