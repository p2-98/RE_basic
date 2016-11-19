###Tìm hiểu về thuật toán

> Tài liệu tham khảo: DSAP - Lê Minh Hoàng
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối : 18.10.2016

----

###Mục lục:

- [1. Thuật toán quay lui](#quaylui)

	- [1.1 Liệt kê các dãy nhị phân có độ dài n](#nhiphan)

---

<a name="quaylui"> </a>

###1. Thuật toán quay lui:

- Thuật toán quay lui dùng để giải bài toán liệt kê các cấu hình. Mỗi cấu hình được xây dựng bằng cách xây dựng từng phần tử, mỗi phần tử được chọn bằng cách thử tất cả các khả năng. Giả sử cấu hình cần liệt kê có dạng x[1..n], khi đó thuật toán quay lui được thực hiện qua các bước:

	- 1) Xét tất cả các giá trị x[1] có thể nhận, thử cho x[1] nhận lần lượt các giá trị đó. Với mỗi giá trị thử gán cho x[1] ta sẽ:
	- 2) Xét tất cả các giá trị x[2] có thể nhận, lại thử cho x[2] nhận lần lượt các giá trị đó. Với mỗi giá trị thử gán cho x[2] lại xét tiếp các khả năng chọn x[3]... cứ tiếp tục như vậy đến bước:
	...
	- n) Xét tất cả các giá trị x[n] có thể nhận, thử cho x[n] nhận lần lượt các giá trị đó, thông báo cấu hình tìm được (x[1], x[2],..., x[n]).

- Trên phương diện quy nập, có thể nói rằng thuật toán quay lui liệt kê các cấu hình n phần tử dạng x[1..n] bằng cách thử cho x[1] nhận lần lượt các giá trị có thể. Với mỗi giá trị thử gán cho x[1] bài toàn trở thành liệt kê cấu hình n - 1 phần thử x[2..n].

- **Mô hình của thuật toán quay lui có thể mô tả như sau:**
- {Thủ tục này thử cho x[i] nhận lần lượt các giá trị mà nó có thể chấp nhận}
```C
int Attempt (i)
{
	for {mọi giá trị V có thể gán cho x[i]}
	{
		{thử cho x[i] = V};
		if {x[i] là phần thử cuối cùng trong cấu hình}
			{Thông báo cấu hình tìm được}
		else
			{
				{Ghi nhận việc cho x[1] nhận giá trị V (nếu cầu)};
				Attemp(i + 1); {Gọi đệ quy đề chọn tiếp x[i + 1]}
				{Nếu cần, bỏ ghi nhận việc thử x[i] := V để thử giá trị khác};
			};
	}
}
```

- Thuật toán quay lui sẽ bắt đầu bằng lời gọi Attempt (1)

<a name="nhiphan"> </a>

###1.1 Liệt kê các dãy nhị phân độ dài N

- Biểu diễn dãy nhị phân độ dài N dưới dạng x[1..n]. Ta sẽ liệt kê các dãy này bằng cách thử dùng gái trị {0, 1} gán cho x[i]. Với mỗi giá trị thử gán cho x[i] lại thử các giá trị có thể gán cho x[i + 1]. Chương trình liệt kê bằng thuật toán quay lui có thể viết:

```C
#include <stdio.h>
#include <stdlib.h>

int x[50] = {0}, n;
FILE *fo = NULL;
void PrintRes()
{
	for (int i = 1; i <= n; i++)
		fprintf(fo,"%d", x[i]);
	fprintf(fo,"\n");
}
void Backtrack(int i)
{
	for (int j = 0; j <= 1; j++)
		{
			x[i] = j;
			if (i == n)
				PrintRes();
			else
				Backtrack(i + 1);
		}
}
void Enter()
{
	FILE *fi = NULL;
	fi = fopen("BSTR.inp","r");
	fo = fopen("BSTR.out","w");
	fscanf(fi,"%d", &n);
	Backtrack(1);
	fclose(fi);
	fclose(fo);
}
int main()
{
	Enter();
}
```
