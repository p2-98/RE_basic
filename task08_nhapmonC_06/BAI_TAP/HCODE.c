#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n;
char s[500][256];
void Enter()
{
	FILE* fi = NULL;
	fi = fopen("HCODE.inp","r");
	fscanf(fi,"%d", &n);
	fscanf(fi,"\n");
	for (int i = 1; i <= n; i++)
		{
			fgets(s[i],256, fi);
		}
	fclose(fi);
		
}
int Solve(char s1[255], char s2[255])
{
	int jTmp = 1;
	int count = 0;
	for (int i = 0; i < strlen(s2); i++)
		{
			if (s2[i] == s1[jTmp])
				{
					if (jTmp < strlen(s1)) jTmp++;
					if (jTmp == strlen(s1))
						break;
					else
						count ++;
				}
		}
	if (count == strlen(s1) - 1)
		return 0;
	else
		return 1;
}
int Process(int &save)
{
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		{
			if ((i != j) && (strlen(s[i]) < strlen(s[j])))
			if (Solve(s[i], s[j]) == 0)
				{
					save = i;
					return 0;
				}
		}
}
void Output(int &save)
{
	FILE* fo= NULL;
	fo = fopen("HCODE.out","w");
	if (save == 0)
		{
			fprintf(fo,"1");
		}
	else
		{
			fprintf(fo,"0 \n");
			fprintf(fo,"%d", save);
		}
	fclose(fo);
}
int main()
{
	int save = 0;
	Enter();
	Process(save);
	Output(save);
}
/*Siêu mã là một loại mã có nhiều ứng dụng quan trọng trong lĩnh vực mã hóa và truyền tin. Trong bài này, ta xét bài toán đơn giản sau đây về siêu mã. Cho u và v là hai xâu kí tự khác rỗng có độ dài hữu hạn. Xâu u được gọi là xâu con của xâu v nếu u có thể nhận được từ v bằng cách xóa bớt ít nhất một kí tự trong v. Một tập X các xâu khác rỗng có độ dài hữu hạn được gọi là siêu mã nếu mọi cặp u, v bất kỳ thuộc X, u không là xâu con của v và v không là xâu con của u.
Cho trước một tập X = {x1, x2, ..., xN} gồm N xâu khác rỗng, mỗi kí tự trong xâu là 0 hoặc 1. Hãy kiểm tra xem X có là một siêu mã hay không?
Dữ liệu: vào từ file văn bản HCODE.INP có định dạng như sau:
•	Dòng đầu tiên chứa  số nguyên dương N (N ≤ 500);
•	Dòng thứ i trong N dòng tiếp theo ghi xâu xi của tập X, độ dài của xâu xi không quá 15, với i = 1, 2, ..., N.
Kết quả: ghi ra file văn bản HCODE.OUT có định dạng như sau:
•	Nếu X là siêu mã thì ghi số 1;
•	Nếu X không là siêu mã thì dòng đầu tiên ghi số 0, dòng thứ hai ghi chỉ số i nhỏ nhất mà hoặc xi là xâu con của xj hoặc xj là xâu con của xi, với xi, xj thuộc X, 1 ≤ i < j ≤ N.
Input:
3
010
1000
11
Output:
1 */
