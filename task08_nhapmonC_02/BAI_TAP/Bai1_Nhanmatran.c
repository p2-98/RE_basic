#include <stdio.h>

int main()
{
    int n, a[100][100], b[100][100];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    for (int i = 0; i < n; i++)
        for (int j =0; j < n; j++)
            for (int k = 0; k < n; k++)
            {
                b[i][j] = a[i][k] * a[k][j];
            };
    for (int i = 0; i < n; i++)
        {
		for (int j = 0; j < n; j++)
			printf("%d ", b[i][j]);
		printf("\n");
		};
}
/* Nhân 2 ma trận vuông A cấp n
Input
0 1
1 1
Output
1 1
1 1 */
