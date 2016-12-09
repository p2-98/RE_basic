#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
const int maxN = 1000;
int a[maxN], f[maxN], b[maxN][maxN];
int n;

void Enter()
{
	FILE *fi = NULL;
	fi = fopen("NKJUMP.inp","r");
	fscanf(fi, "%d", &n);
	for (int i = 1; i <= n; i++)
		fscanf(fi,"%d", &a[i]);
	fclose(fi);
}
void Swap(int &a, int &b)
{
	int t = a;
	a = b;
	b = t;
}
int QSort(int L, int R)
{
	int i = L, j = R;
	int k = a[(L + R)/2];
	do
	{
		while (a[i] < k) i++;
		while (a[j] > k) j--;
		if (i <= j)
			{
				Swap(a[i], a[j]);
				i++;
				j--;
			};
	} while (i <= j);
	if (L < j) QSort(L, j);
	if (i < R) QSort(i, R);
}
void Init()
{
	memset(b, 0, sizeof(b));
	int t, k;
	for (int i = 1; i <= n - 2; i++)
		{
			t = i + 2;
			for (int j = i + 1; j <= n - 1; j++)
			{
				for (k = t; k <= n; k++)
				if (a[i] + a[j] == a[k])
					{
						b[i][k] = 1;
						b[j][k] = 1;
					}
				else
					if (a[i] + a[j] < a[k])
						break;
				t = k;
			}
		}
}
int Optimize()
{
	int maxJ = 0;
	for (int i = 1; i <= n; i++)
	{
		f[i] = 1;
		for (int j = i - 1; j >= 1; j--)
			if ((b[j][i]) && (f[j] + 1 > f[i]))
				f[i] = f[j] + 1;
		if (maxJ < f[i])
			maxJ = f[i];
	}
	return maxJ;
}
void PrintRes()
{
	FILE *fo = NULL;
	fo = fopen("NKJUMP.out","w");
	fprintf(fo,"%d", Optimize());
	fclose(fo);
}
int main()
{
	Enter();
	QSort(1, n);
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	Init();
	PrintRes();
}

/*NKJUMP - VOI08 Lò cò
Nhảy lò cò là trò chơi dân gian của Việt Nam. Người trên hành tinh X cũng rất thích trò chơi này và họ đã cải biên trò chơi này như sau: Trên mặt phẳng vẽ n vòng tròn được đánh số từ 1 đến n. Tại vòng tròn i người ta điền số nguyên dương ai. Hai số trên hai vòng tròn tùy ý không nhất thiết phải khác nhau. Tiếp đến người ta vẽ các mũi tên, mỗi mũi tên hướng từ một vòng tròn đến một vòng tròn khác. Quy tắc vẽ mũi tên là: Nếu có ba số ai, aj, ak thỏa mãn ak = ai + aj thì vẽ mũi tên hướng từ vòng tròn i đến vòng tròn k và mũi tên hướng từ vòng tròn j đến vòng tròn k. Người chơi chỉ được di chuyển từ một vòng tròn đến một vòng tròn khác nếu có mũi tên xuất phát từ một trong số các vòng tròn, di chyển theo cách mũi tên đã vẽ để đi đến các vòng tròn khác. Người thắng cuộc sẽ là người tìm được cách di chuyển qua nhiều vòng tròn nhất.

Ví dụ: Với 5 vòng tròn và các số trong vòng tròn là 1, 2, 8, 3, 5, trò chơi được trình bày trong hình dưới đây:

Khi đó có thể di chuyển được nhiều nhất qua 4 vòng tròn (tương ứng với đường di chuyển được tô đậm trên hình vẽ).

Yêu cầu
Hãy xác định xem trong trò chơi mô tả ở trên, nhiều nhất có thể di chuyển được qua bao nhiêu vòng tròn.

Dữ liệu
Dòng đầu chứa số nguyên n (3 ≤ n ≤ 1000);
Dòng thứ hai chứa dãy số nguyên dương a1, a2, ..., an (ai ≤ 109, i=1, 2,..., n).
Hai số liên tiếp trên một dòng được ghi cách nhau bởi dấu cách.

Kết quả
Ghi ra số lượng vòng tròn trên đường di chuyển tìm được.

Ràng buộc
60% số tests ứng với 60% số điểm của bài có 3 ≤ n ≤ 100.
Ví dụ
Dữ liệu:
5
1 2 8 3 5

Kết qủa
4
Link: http://vn.spoj.com/problems/NKJUMP/ */
