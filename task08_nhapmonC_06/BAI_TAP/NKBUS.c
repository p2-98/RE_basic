#include <stdio.h>
#include <stdlib.h>

int sumT, a[200000], n, m;
void Enter()
{
	FILE* fi = NULL;
	fi = fopen("NKBUS.INP","r");
	fscanf(fi,"%d %d", &n, &m);
	sumT = 0;
	int t = 0, k;
	a[0] = 0;
	for (int i = 1; i <= n; i++)
		{
			sumT = sumT + t; 
			fscanf(fi,"%d %d", &t, &k);
			for (int j = 1; j <= k; j++)
				{
					a[0]++;
					fscanf(fi,"%d", &a[a[0]]);
					if (a[a[0]] - sumT > 0)
						{
							a[a[0]] -= sumT;
						}
					else
						{
							a[a[0]] = 0;
						}
				}
		}
	fclose(fi);
	sumT += t;
}
void Swap(int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}
int QSort(int L, int H)
{
	int i = L;
	int j = H;
	int x = a[(L + H) / 2];
	do
		{	
			while (a[i] < x) i++;
			while (a[j] > x) j--;
			if (i <= j)
				{
					Swap(i, j);
					i++;
					j--;
				}
		}
	while (i <= j);
	if (L < j) QSort(L, j);
	if (i < H) QSort(i, H);
}
void Output()
{
	FILE* fo = NULL;
	fo = fopen("NKBUS.out","w");
	if (m > a[0])
		{
			fprintf(fo,"%d", sumT + a[a[0]]);
		}
	else
		fprintf(fo,"%d",sumT + a[m]);
	fclose(fo);
}
int main()
{
	Enter();
	QSort(1, a[0]);
	Output();
}
/*NKBUS - Bus
Một xe buýt của công ty có nhiệm vụ đón nhân viên đến trụ sở làm việc. Trên hành trình, xe buýt sẽ tiếp nhận nhân viên đứng chờ ở các điểm hẹn nếu như xe còn chỗ trống. Xe buýt có thể đỗ lại để chờ những công nhân chưa kịp đến điểm hẹn.

Cho biết thời điểm mà mỗi nhân viên đến điểm hẹn của mình và thời điểm qua mỗi điểm hẹn của xe buýt. Giả thiết rằng xe buýt đến điểm hẹn đầu tiên tại thời điểm 0 và thời gian xếp khách lên xe được bằng 0.

Xe buýt cần phải chở một số lượng nhiều nhất các nhân viên có thể được đến trụ sở. Hãy xác định khoảng thời gian ngắn nhất để xe buýt thực hiện công việc.

Dữ liệu vào
Dòng đầu tiên chứa 2 số nguyên dương n, m theo thứ tự là số điểm hẹn và số chỗ ngồi của xe buýt

Dòng thứ i trong số n dòng tiếp theo chứa số nguyên ti là thời gian cần thiết để xe buýt di chuyển từ điểm hẹn thứ i đến điểm hẹn thứ i+1 (điểm hẹn thứ n+1 sẽ là trụ sở làm việc của công ty) và số nguyên k là số lượng nhân viên đến điểm hẹn i, tiếp theo k số nguyên là các thời điểm đến điểm hẹn của k nhân viên.

Kết qủa
Gồm một dòng duy nhất, là thời gian ngắn nhất tìm được.

Giới hạn
1 ≤ n ≤ 200000, 1 ≤ m ≤ 20000

Tổng số nhân viên không vượt quá 200000.

Kết quả không vượt quá 231-1.

Ví dụ
Dữ liệu mẫu
3 2
3 2 4 3
1 3 6 3 7
5 1 5

Kết qủa
10
Giải thích: Trên đường đến công ty có 3 trạm xe buýt. Từ trạm 1 đến trạm 2, trạm 2 đến trạm 3, và từ trạm 3 đến công ty lần lượt mất 3, 1 và 5 đơn vị thời gian. Xe buýt có thể đi như sau: đến thẳng trạm 2, đón người thứ 2, đến trạm 3, chờ 1 đơn vị thời gian để đón người duy nhất ở trạm này, và cuối cùng đến công ty. Tổng cộng xe buýt đi mất 3 + 1 + 1 + 5 = 10 đơn vị thời gian.*/
