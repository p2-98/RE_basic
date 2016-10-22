#include <stdio.h>;
#include <math.h>;
int solve(long long num)
{
	long long tmp;
	if (num < 2) return 0;
	if (num == 2) return 1;
	tmp = (int)sqrt(num);
	for (int i = 2; i <= tmp; i++)
	{
		if (num % i == 0)
			return 0;
	}
	return 1;
}
int main()
{
	long long num;
	scanf("%lld",&num);
	if (solve(num))
		printf("YES");
	else
		printf("NO");
	return 0;
}
/*Số nguyên tố là số chia hết cho 1 và chính nó. Một số số nguyên tố đầu tiên là: 2, 3, 5, 7, 11, 13, 17 .... (số 1 không được xem là số nguyên tố).
Cho một số nguyên dương n, xác định xem n có phải là số nguyên tố hay không?
Dữ liệu vào:
- Là một số nguyên dương n (1<= n <= 1012). Chú ý dùng kiểu long long.
Dữ liệu xuất:
- Nếu n là số nguyên tố in ra "YES" (không in dấu nháy).
- Nếu n không phải là số nguyên tố in ra "NO" (không in dấu nháy).
 
Ví dụ
input
5
output
YES
input
9
output
NO*/
