#include <stdio.h>

int main()
{
    int a[100];
    int n, x, check = 0;
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++)
        {
            scanf("%d", &a[i]);
            if (a[i] == x)
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
5 6
1 2 6 8 1
output
yes
input
3 2
9 6 8
output
no*/
