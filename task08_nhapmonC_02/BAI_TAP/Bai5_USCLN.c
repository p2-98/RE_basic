#include <stdio.h>;
#include <math.h>;
int solve(int m, int n)
{
	if (m % n == 0) return n;
	if (n % m == 0) return m;
	if (m > n)
		return solve(m % n, n);
	else
	if (m < n)
		return solve(m, n % m);

}
int main()
{
	int m, n;
	scanf("%d %d",&m, &n);
	printf("%d",solve(m, n));
	return 0;
}
/*Cho hai số nguyên dương a và b, hãy tìm ước số chung lớn nhất của a và b.
Dữ liệu nhập:
- Gồm 2 số a và b cách nhau một khoảng trắng (1 ≤ a, b ≤ 5.000.000)
Dữ liệu xuất:
- Là ước số chung lớn nhất của a và b.
Ví dụ
input
6 9
output
3
input
1 10
output
1
*/
