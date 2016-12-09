#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
int found, n, s, k, tmp = 0;
int x[20], save[20], a[20][20];
void Enter()
{
	FILE *fi = NULL;
	fi = fopen("V8SCORE.inp","r");
	fscanf(fi,"%d %d %d", &s, &k, &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= k; j++)
			fscanf(fi,"%d", &a[i][j]);
	fclose(fi);
}
int Backtrack(int i)
{
	for (int j = 1; j <= n; j++)
		if (found == 1)
			{
				x[i] = a[j][i];
				tmp += a[j][i];
				if (tmp <= s)
				if (x[i] >= x[i - 1])
					{
						if (i == k)
						if (tmp == s)
							{
								found = 0;
								memcpy(save, x, sizeof(x));
								return 0;
							}
						if (i != k)
							Backtrack(i + 1);
					}
				tmp = tmp - a[j][i];
			}
}
void PrintRes()
{
	FILE *fo = NULL;
	fo = fopen("V8SCORE.out","w");
	if (found == 0)
		{
			fprintf(fo, "YES\n");
			for (int i = 1; i <= k; i++)
				fprintf(fo,"%d ", save[i]);
		}
	else
		fprintf(fo, "NO");
	fclose(fo);
}
int main()
{
	Enter();
	found = 1;
	x[0] = 0;
	Backtrack(1);
	PrintRes();
}

/*V8SCORE - Chấm điểm
Có N vị giám khảo trong kỳ thi chọn đội tuyển tin học. Kỳ thi bao gồm K bài. Vị giám khảo thứ i đề nghị số điểm của bài j là Aij.

Hội đồng giám khảo muốn xác định số điểm cho mỗi bài sao cho:

Tổng số điểm bằng S.
Điểm của mỗi bài không bé hơn điểm của bài trước đó.
Số điểm của mỗi bài bằng điểm đề nghị cho bài này của một vị giám khảo nào đó.
Dữ liệu
Dòng đầu tiên chứa ba số nguyên S (1 ≤ S ≤ 200), (1 ≤ K ≤ 20), (1 ≤ N ≤ 20).
Dòng thứ i trong số N dòng tiếp theo chứa K số nguyên, số thứ j cho biết giá trị Aij là số điểm vị giám khảo thứ i đề nghị cho bài thứ j.
Kết qủa
Nếu tồn tại một cách cho điểm thỏa mãn yêu cầu:
Dòng thứ nhất: in ra 'YES'.
Dòng thứ hai: in ra K số nguyên là điểm của mỗi bài tìm được.
Nếu không tồn tại cách cho điểm, in ra 'NO'.
Ví dụ
Input
100 3 2
30 20 40
50 30 50
Output
YES
30 30 40
Input
100 2 3
1 1
2 2
3 3
Output
NO
