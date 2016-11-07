#include <stdlib.h>
#include <stdio.h>
#define max(a,b)(a)>(b)?(a):(b)
#define min(a,b)(a)<(b)?(a):(b)
#define vc 100000;
int n, L[200][200], a[200][200];
void Enter()
{
	FILE* fi = NULL;
	fi = fopen("DISNEY.INP","r");
	fscanf(fi,"%d", &n);
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		fscanf(fi,"%d", &a[i][j]);
	fclose(fi);
}
void init()
{
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		L[i][j] = vc;
	L[1][1] = 0;
}
int solve()
{
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		{
			int t = max(i, j) + 1;
			L[i][t] = min(L[i][t], L[i][j] + a[j][t]);
			L[t][j] = min(L[t][j], L[i][j] + a[i][t]);
			L[t][t] = min(L[t][t], L[i][j] + a[j][t] + a[i][t]);
		}
	int res = vc;
	for (int i = 1; i <= n; i++)
		{
			res = min(res, L[i][n] + a[1][i] + a[1][n]);
			res = min(res, L[n][i] + a[1][n] + a[1][i]);
		}
	return res;
}
void Output()
{
	FILE* fo = NULL;
	fo = fopen("DISNEY.OUT","w");
	int res = solve();
	fprintf(fo,"%d", res);
	fclose(fo);
}
int main()
{
	Enter();
	init();
	Output();
	return 0;
}

/*Công viên Disneyland khai trương N điểm vui chơi mới. Một hôm Bờm và Cuội đến chơi Công viên. Qua việc hỏi thăm người hướng dẫn Bờm và Cuội đã biết thời gian cụ thể để đi từ điểm vui chơi i đến địa điểm vui chơi j. Bờm và Cuội muốn đi thăm hết tất cả các địa điểm theo nguyên tắc sau:
-Mỗi người đi từ điểm số 1, qua 1 số điểm và quay trở về điểm số 1.
-Các điểm đến trên đường đi của Bờm và Cuội là 1 dãy số tăng dần( trừ điểm số 1 khi quay về).
-Mỗi điểm vui chơi phải thuộc ít nhất 1 trong 2 đường đi của Bờm và Cuội.
-Thời gian đi là nhỏ nhất (tính cả thời gian quay về 1).

Input
-Dòng đầu là số N (N<201)
-Tiếp theo là ma trận N dòng N cột: 1 số nguyên không âm(<1001) trên hàng i cột j cho ta biết thời gian đi từ địa điểm i đến địa điểm j.
(A[i][j] = A[j][i] , A[i][i] = 0 với mọi i, j).

Output
Gồm 1 số duy nhất là thời gian nhỏ nhất để Bờm và Cuội thăm quan Công Viên theo nguyên tắc trên.

Example
Input:
4
0 1 4 3
1 0 2 4
4 2 0 4
3 4 4 0


Output:
10

(Giải thích : cách đi tốt nhất là Bờm đi 1->2->3->4->1 và Cuội đứng yên)*/
