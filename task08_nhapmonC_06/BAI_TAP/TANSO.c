#include <stdio.h>
#include <stdlib.h>

void Enter(int &save, int &max)
{
	int n, a[1000], b[10000];
	FILE* fi = NULL;
	fi = fopen("TANSO.inp","r");
	fscanf(fi,"%d", &n);
	for (int i = 1; i < n + 1; i++)
		{
			fscanf(fi,"%d", &a[i]);
			b[a[i]]++;
			if (b[a[i]] > max)
				{
					save = a[i];
					max = b[a[i]];
				}
		}
	fclose(fi);
}
void Output(int save, int max)
{
	FILE *fo = NULL;
	fo = fopen("TANSO.out","w");
	fprintf(fo,"%d %d",save, max);
	fclose(fo);
}
int main()
{
	int max = 0, save;
	Enter(save, max);
	Output(save, max);
	return 0;
}
/* TÌm số có tần số xuất hiện nhiều nhất trong mảng
Dữ liệu vào :
- Dòng chữ nhất : N là số phần tử trong mảng
- Dòng thứ hai : Giá trị mảng
Dữ liệu ra:
- Gồm 2 số : Số thứ nhất là số có tần số xuất hiện nhiều nhất, số thứ 2 là tần số xuất hiện của nó
Input
5
1 1 2 4 1
Output
1 3 */
