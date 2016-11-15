#include <stdio.h>;
#include <stdlib.h>;
typedef struct
	{
		int x, y;
	} index;
int n, t, b;
index a[300000];
int Qsort(int L, int H)
{
	index tmp;
	long i, j, x;
	i = L;
	j = H;
	x = a[(L + H) / 2].x;
	do
		{
			while (a[i].x < x) i++;
			while (a[j].x > x) j--;
			if (i <= j)
				{
					tmp = a[i];
					a[i] = a[j];
					a[j] = tmp;
					i++;
					j--;
				};
		}
	while (i <= j);
	if (L < j) Qsort(L, j);
	if (i < H) Qsort(i, H);
}
void Enter()
{
	FILE *fi = NULL;
	fi = fopen("MINROAD.inp","r");
	fscanf(fi,"%ld %ld %ld", &n, &t, &b);
	for (int i = 1; i <= n; i++)
		{
			fscanf(fi,"%ld %ld", &a[i].x, &a[i].y);
		}
	fclose(fi);
	Qsort(1, n);
}
long Solve()
{
	long j = 1, d1 = 0, d2 = 0, best = 99999;
	for (int i = 1; i <= n; i++)
		{
			if (a[i].y == 1)
				d1++;
			else
				d2++;
			while ((d1 >= t) && (d2 >= b))
				{
					if((a[i].x - a[j].x) < best)
						best = a[i].x - a[j].x;
					if (a[j].y == 1)
						d1--;
					else
						d2--;
					j++;
				}
		}
	if (best == 99999)
		return -1;
	else
		return best;
}
void Output()
{
	FILE *fo = NULL;
	fo = fopen("MINROAD.out","w");
	long res = Solve();
	fprintf(fo,"%d", res);
	fclose(fo);
}
int main()
{
	Enter();
	Output();
}
/*MINROAD - VOI 2014 - Con duong Tung Truc
Địa điểm du lịch Dailai nổi tiếng với con đường Tùng-Trúc. Đó là một con đường dài và thẳng, dọc bên đường người ta trồng rất nhiều cây tùng và cây trúc. Với mục đích tạo điểm nhấn cho con đường, Ban quản lý khu du lịch muốn chọn một đoạn đường mà dọc theo nó có ít nhất a cây tùng và có ít nhất b cây trúc để trang trí. Sau khi khảo sát, Ban quản lý ghi nhận được vị trí của từng cây tùng và cây trúc. Trên con đường có tất cả n cây, không có hai cây nào ở cùng một vị trí. Cây thứ i ở ị trí có khoảng cách đến vị trí bắt đầu của con đường là d_i (i = 1, 2, ..., n). Với kinh phí có hạn, Ban quản lý muốn chọn một đoạn đường thỏa mãn điều kiện đã nêu với độ dài là ngắn nhất.

Yêu cầu
Cho a, b và vị trí của n cây. Hãy tìm đoạn đường có độ dài ngắn nhất mà dọc theo đoạn đường đó có ít nhất a cây tùng và b cây trúc.

Input
Dòng đầu chứa 3 số nguyên dương n, a, b (a + b <= n)
Dòng thứ i trong n dòng tiếp theo mỗi dòng chứa hai số nguyên dương d_i (d_i <= 10^9) trong đó d_i là khoảng cách của cây tính từ vị trí bắt đầu của con đường, k_i = 1 nếu cây thứ i là cây tùng, k_i = 2 nếu là cây trúc.
Các số trên cùng một dòng được ghi cách nhau ít nhất một dấu cách.
Output
Ghi ra một số nguyên là độ dài đoạn đường ngắn nhất tìm được, quy ước ghi số -1 nếu không tồn tại đoạn đường nào thỏa mãn điều kiện đặt ra.

Giới hạn
d_i <= 10^9.
30% số test có n <= 300.
30% số test khác có n <= 3000.
40 % số test còn lại có n <= 300000.
Example
Input:
7 2 2
20 2
30 1
25 1
35 1
60 2
65 2
10 1

Output:
35 */
