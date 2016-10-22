#include <stdio.h>;
#include <string.h>;
int main ()
{
	char s[10000];
	int k;
	scanf("%s %d",&s, &k);
	for (int i = k - 1; i >= 0; i--)
		printf("%c",s[i]);
	for (int i = strlen(s) - 1; i >= k; i--)
		printf("%c",s[i]);
}

/*
Vị Giám đốc công ty XYZ cần gửi một văn bản quan trọng tới một đối tác của mình. Để bảo mật văn bản, ông quyết định mã hóa văn bản trước khi gửi. Văn bản là một xâu S các chữ cái la tinh in thường. Ông ta chia văn bản thành hai đoạn liên tiếp Sb và Se. Lần lượt viết hai xâu Sb và Se nhưng đều theo thứ tự ngược lại ông ta nhận được xâu mã hóa Q. Bức thư thứ nhất gửi cho đối tác có nội dung là Q. Để đối tác đọc được văn bản, ông ta gửi thêm một bức thư thứ hai trong đó chứa khóa để giải mã: độ dài k của xâu Sb.
       Ví dụ nội dung bức thư S = ’programming’ với với khóa k= 7 sẽ được chia  thành 2 đoạn: Sb = ’program’, Se = ’ming’, nhận được xâu mã hóa Q = ’margorpgnim’.
Yêu cầu: Cho xâu mã hóa Q và khóa k, hãy xác định xâu S (k≥ 0 và không vượt quá độ dài xâu S).
Dữ liệu nhập:
- Dòng thứ nhất chứa xâu mã hóa Q có độ dài từ 1 đến 250.
- Dòng thứ hai chứa khóa k.
Dữ liệu xuất:
- Là xâu S tìm được.
Ví dụ
input
margorpgnim
7
output
programming
*/
