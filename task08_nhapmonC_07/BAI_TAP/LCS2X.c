#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#define max(a, b) ((a)>(b)?(a):(b))
int a[1500], b[1500], t, n, m;
int Optimize()
{
	int F[1500];
	memset(F, 0, sizeof(F));
	int res = 0;
	for (int i = 1; i <= n; i++)
		{
			int ma = 0;
			for (int j = 1 ; j <= m; j++)
				{
					int matruocj = ma;
					if (a[i] >= b[j] * 2)
						ma = max(ma, F[j]);
					if (a[i] == b[j])
						F[j] = max(F[j], matruocj + 1);
					if (F[j] > res)
						res = F[j];
				}
		}
		return res;
}
void Enter()
{
	FILE *fi = NULL;
	FILE *fo = NULL;
	fo = fopen("LCS2X.out","w");
	fi = fopen("LCS2X.inp","r");
	fscanf(fi,"%d", &t);
	for (int k = 1; k <= t; k++)
		{
			fscanf(fi,"%d %d", &n, &m);
			for (int i = 1; i <= n; i++)
				fscanf(fi,"%d", &a[i]);
			for (int j = 1; j <= m; j++)
				fscanf(fi,"%d", &b[j]);
			fprintf(fo,"%d", Optimize());
		}
	fclose(fi);
	fclose(fo);
}
int main()
{
	Enter();
}
/*LCS2X - VOI 2014 - Dãy con chung bội hai dài nhất
Dãy C = c1, c2, .. ck được gọi là dãy con của dãy A = a1, a2, .., an nếu C có thể nhận được bằng cách xóa bớt một số phần tử của dãy A và giữ nguyên thứ tự của các phần tử còn lại, nghĩa là tìm được dãy các chỉ số 1 ≤ l1 < l2 < … < lk ≤ n sao cho c1 = a_l1, c2 = a_l2, …, ck = a_lk. Ta gọi độ dài của dãy là số phần tử của dãy.

Cho hai dãy A = a1, a2, …, am và B = b1, b2, …, bn Dãy C = c1, c2, …, ck được gọi là dãy con chung bội hai của dãy A và B nếu C vừa là dãy con của dãy A, vừa là dãy con của dãy B và thỏa mãn điều kiện 2 × ci ≤ c(i+1) (i = 1, 2, …, k – 1).

Yêu cầu
Cho hai dãy A và B. Hãy tìm độ dài dãy con chung bội hai có độ dài lớn nhất của hai dãy A và B.

Input
Dòng đầu tiên chứa T là số lượng bộ dữ liệu. Tiếp đến là T nhóm dòng, mỗi nhóm cho thông tin về một bộ dữ liệu theo khuôn dạng sau:

Dòng đầu chứa 2 số nguyên dương m và n.
Dòng thứ hai chứa m số nguyên không âm a1, a2, ..., am mỗi số không vượt quá 10^9.
Dòng thứ ba chứa n số nguyên không âm b1, b2, ..., bn mỗi số không vượt quá 10^9.
Các số trên cùng một dòng được ghi cách nhau ít nhất một dấu cách.
Giới hạn
30% số test có m, n <= 15.
30% số test khác có m, n <= 150.
có 40% số test còn lại có m, n <= 1500.
Output
Ghi ra T dòng, mỗi dòng ghi một số nguyên là độ dài dãy con chung bội hai dài nhất của dãy A và B tương ứng với bộ dữ liệu vào.

Example
Input:
1
5 5
5 1 6 10 20
1 8 6 10 20

Output:
3*/
