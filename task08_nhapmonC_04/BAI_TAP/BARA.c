#include <stdio.h>

int solve(int n, int k, int *res)
{
	if(k >= n)
		{
			*res = 10;
			return 0;
		}
	*res = ((n * 2 - 1) / k + 1) * 5;
}
int main()
{
	int n, k, res = 0;
	scanf("%d %d", &n, &k);
	solve(n, k, &res);
	printf("%d", res);
}
/*Chú mèo máy Đorêmon có n cái bánh cần rán, mỗi bánh có hai mặt, mỗi lần rán một mặt. Đorêmon có một cái chảo có thể rán được k cái bánh cùng lúc. Mỗi lần rán một mặt bánh tốn 5 phút. Hỏi Đorêmon cần ít nhất bao nhiêu phút để rán hết n cái bánh?
Dữ liệu nhập:
- Là hai số nguyên n, k cách nhau một khoảng trắng (1 ≤ n, k ≤ 1000)
Dữ liệu xuất:
- Là số phút ít nhất để rán hết n cái bánh.
Ví dụ
input
8 4
output
20
input
6 4
output
15
Test 1: Rán 4 bánh đầu hết 10 phút, rán 4 bánh sau hết 10 phút, tổng cộng 20 phút
*/
