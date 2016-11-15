#include <stdio.h>
#include <stdlib.h>
typedef struct
	{
		int d, c;
	} index;
int main()
{
	FILE *fi = NULL;
	FILE *fo = NULL;
	fi = fopen("BONES.inp","r");
	fo = fopen("BONES.out","w");
	long s1, s2, s3;
	fscanf(fi,"%ld %ld %ld", &s1, &s2, &s3);
	index a[20*30*40];
	long max = -99999, count = 0, b[100];
	for (int i = 1; i <= s1; i++)
	for (int j = 1; j <= s2; j++)
	for (int k = 1; k <= s3; k++)
		{
			b[i + j + k]++;
			if (b[i + j + k] > max)
				{
					max = b[i + j + k];
					count++;
					a[count].d = i + j + k;
					a[count].c = b[i + j + k];
				};
		};
	for (int i = count; i >= 2; i--)
	if (a[i].c != a[i - 1].c)
		{
			fprintf(fo,"%ld",a[i].d);
			return 0;
		};
	fclose(fi);
	fclose(fo);
}
/*BONES - Xúc xắc bò
Bessie rất yêu thích chơi những trò chơi đổ xúc xắc và cô bò này đã nài được bác nông dân John chở tới cửa hàng đồ chơi và cô bò đã mua 3 cái xúc xắc về để lăn.

Những viên xúc xắc này tương ứng có S1, S2 và S3 mặt đều nhau, các mặt được đánh số từ 1->S1, 1->S2 và 1->S3 (2 <= S1 <= 20; 2 <= S2 <= 20; 2 <= S3 <= 40).

Bessie cứ thả xúc xắc liên tục và mỗi lần lại ghi nhận lại 1 số nguyên là tổng giá trị của 3 mặt xúc xắc thả được. Mục đích của cô bò là để tìm ra xem tổng giá trị nào xuất hiện nhiều nhất.

Cho số mặt của 3 xúc xắc, hãy xác định xem tổng giá trị nào xuất hiện nhiều nhất. Nếu có nhiều hơn 1 giá trị xuất hiện nhiều nhất thì ghi ra giá trị nhỏ nhất.

DỮ LIỆU
Dòng 1: 3 số nguyên cách nhau bởi dấu cách: S1, S2 và S3
KẾT QUẢ
Dòng 1: Số nguyên nhỏ nhất là tổng giá trị xuất hiện nhiều lần nhất, giả sử rằng xác suất các mặt xúc xắc xuất hiện là như nhau.
VÍ DỤ
Dữ liệu
3 2 3

Kết quả
5
GIẢI THÍCH
Đây là tất cả các trường hợp có thể xảy ra. 1 1 1 -> 3 1 2 1 -> 4 2 1 1 -> 4 2 2 1 -> 5 3 1 1 -> 5 3 2 1 -> 6 1 1 2 -> 4 1 2 2 -> 5 2 1 2 -> 5 2 2 2 -> 6 3 1 2 -> 6 3 2 2 -> 7 1 1 3 -> 5 1 2 3 -> 6 2 1 3 -> 6 2 2 3 -> 7 3 1 3 -> 7 3 2 3 -> 8 Trong đó 5 và 6 xuất hiện nhiều nhất (mỗi số 5 lần), vậy 5 là kết quả.*/
