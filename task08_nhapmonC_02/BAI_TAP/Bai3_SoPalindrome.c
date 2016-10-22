#include <stdio.h>;
#include <math.h>;
int convert(int &num)
{
	int tmp = num, tmp1 = 0;
	while (tmp)
	{
		tmp1 = tmp1 * 10 + tmp%10;
		tmp /= 10;
	}
  return (tmp1 == num);
}
int main()
{
	int num, n;
	scanf("%d",&n);
	for (int i = 0; i < n ; i++)
		{
			scanf("%d",&num);
			if (convert(num) != 0)
				printf("%d ",num);
		}
}
/*
Một số nguyên dạng Palindrome là số mà đọc từ trái qua phải hay từ phải qua trái đều giống nhau, ví dụ các số Palindrome: 101, 22, 123321.
Nhập vào một mảng n số nguyên a1, a2, ... an. Hãy in ra các số Palindrome theo đúng thứ tự nhập.
Dữ liệu nhập:
- Dòng thứ nhất là chiều dài n của mảng (1<= n <= 1000)
- Dòng thứ hai gồm n số nguyên a1, a2, a3, ... an (0<= ai <= 109), mỗi số cách nhau một khoảng trắng.
Dữ liệu xuất:
- Là một dòng duy nhất chứa các số nguyên Palindrome theo đúng thứ tự nhập, mỗi số cách nhau một khoảng trắng.
Yêu cầu: không dùng các thao tác chuỗi để xử lý.
Ví dụ
input
6
1 13 27 22 1221 556
output
1 22 1221
*/
