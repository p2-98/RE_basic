#include <stdio.h>

int solve(int *dung, int *nam, int *gia, int n, int m)
{
	for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int k = n - i - j;
				if((k % 3 == 0) && (k != 0) && (5 * i + 3 * j + k / 3 == m))
				{
					*dung = i;
					*nam = j;
					*gia = k;
					return 0;
				}
			}
		}
	return -1;
}
int main()
{
	int dung = 0, nam = 0, gia = 0, n, m;
	scanf("%d %d", &n, &m);
	if (solve(&dung, &nam, &gia, n, m) == 0)
		printf("%d %d %d",dung, nam, gia);
	else
		printf("-1");
	return 0;	
}
/*Dân gian Việt Nam có một câu đố:
    Trăm trâu trăm cỏ
    Trâu đứng ăn năm
    Trâu nằm ăn ba
    Lụm khụm trâu già
    Ba con một bó
Sau khi giải được bài tập trên với 4 trâu đứng, 18 trâu nằm và 78 trâu già, bạn Nam thắc mắc không biết trong trường hợp tổng quát với n con (vừa trâu đứng, trâu nằm, trâu già) và m bó cỏ thì sẽ giải như thế nào. Bạn hãy giúp bạn Nam nhé. Chú ý rằng phải có đủ phải có đầy đủ ba loại trâu và đủ 3 con trâu già mới được ăn 1 bó cỏ.
Dữ liệu nhập:
- Là hai số nguyên n, m cách nhau một khoảng trắng (1 ≤ n, m ≤ 1.000)
Dữ liệu xuất:
- Nếu có đáp án, in ra ba số nguyên a, b và c thể hiện số trâu đứng, trâu nằm và trâu già, mỗi số cách nhau một khoảng trắng. Nếu có nhiều đáp án, chỉ cần in một đáp án bất kỳ.
- Nếu không có đáp án, in ra -1.
Ví dụ
input
100 100
output
4 18 78 */
