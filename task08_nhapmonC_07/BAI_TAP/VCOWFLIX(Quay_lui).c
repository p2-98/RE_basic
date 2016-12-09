#include <stdio.h>
#include <stdlib.h>
int max = 0, tong = 0, c, n;
int a[20], x[20];
void Enter()
{
	FILE *fi = NULL;
	fi = fopen("VCOWFLIX.inp","r");
	fscanf(fi,"%d %d", &c, &n);
	for (int i = 1; i <= n; i++)
		fscanf(fi,"%d", &a[i]);
	fclose(fi);
}
void Backtrack(int i)
{
	for (int j = 1; j > -1; j--)
		{
			x[i] = j;
			tong += j*a[i];
			if (tong <= c)
				{
					if (i == n)
						{
							if (tong > max)
								max = tong;
						}
					else
						Backtrack(i + 1);
				}
			tong = tong - j*a[i];
		}
}
void PrintRes()
{
	FILE *fo = NULL;
	fo = fopen("VCOWFLIX.out","w");
	fprintf(fo,"%d", max);
	fclose(fo);
}
int main()
{
	Enter();
	Backtrack(1);
	PrintRes();
}
/*VCOWFLIX - Đi xem phim
Nông dân John đang đưa các con bò của anh ta đi xem phim! Xe tải của anh ta thì có sức chứa có hạn thôi, là C (100 <= C <= 5000) kg, anh ta muốn đưa 1 số con bò đi xem phim sao cho tổng khối lượng của đống bò này là lớn nhất, đồng thời xe tải của anh ta vẫn chịu được.

Cho N (1 <= N <= 16) con bò và khối lượng W_i của từng con, hãy cho biết khối lượng bò lớn nhất mà John có thể đưa đi xem phim là bao nhiêu.

Dữ liệu
Dòng 1: 2 số nguyên cách nhau bởi dấu cách: C và N
Dòng 2..N+1: Dòng i+1 chứa 1 số nguyên: W_i
Kết quả
Dòng 1: Một số nguyên là tổng khối lượng bò lớn nhất mà John có thể mang đi xem phim.
Ví dụ
Dữ liệu
259 5
81
58
42
33
61

Kết quả
242 */
