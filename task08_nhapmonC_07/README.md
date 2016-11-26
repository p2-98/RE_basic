###Tìm hiểu về thuật toán

> Tài liệu tham khảo: DSAP - Lê Minh Hoàng
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối : 26.11.2016

-----

###Mục lục:

- [1. Thuật toán quay lui](#quaylui)

	- [1.1 Liệt kê các dãy nhị phân có độ dài n](#nhiphan);
	- [1.2 Liệt kê các tập con K phần tử](#tapconKphantu);
	- [1.3 Liệt kê các chỉnh hợp không lặp chập k](#chinhhopkhonglap)
	- [1.4 Bài toán phân tích số](#phantichso)

----

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
int Backtrack (i)
{
	for {mọi giá trị V có thể gán cho x[i]}
	{
		{thử cho x[i] = V};
		if {x[i] là phần thử cuối cùng trong cấu hình}
			{Thông báo cấu hình tìm được}
		else
			{
				{Ghi nhận việc cho x[1] nhận giá trị V (nếu cầu)};
				Backtrack(i + 1); {Gọi đệ quy đề chọn tiếp x[i + 1]}
				{Nếu cần, bỏ ghi nhận việc thử x[i] := V để thử giá trị khác};
			};
	}
}
```

- Thuật toán quay lui sẽ bắt đầu bằng lời gọi Backtrack (1)

<a name="nhinphan"> </a>

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

- Ví dụ: Khi n = 3, cây tìm kiếm quay lui như sau:

<img src="http://i.imgur.com/cxWERZX.jpg">

<a name="tapconKphantu"> </a>

###1.2 Liệt kê các tập con K phần tử:

- Để lệt kê các tập con k phần tử của tập S = {1, 2, 3, ..., n} ta có thể đưa về liệt kê các cấu hình x[1..n], ở đay x[i] thuộc S và x[1] < x[2] < ... < x[k]. Ta có nhận xét:
- x[k] <= n;
- x[k - 1] <= x[k] - 1 <= n - 1
- ...
- x[i] <= n - k + i
- ....
- x[1] <= n - k + 1.
- Từ đó suy ra x[i - 1] + 1 <= n - k + i (1 <= i <= k) ở đây ta có giả thiết có thêm một số x[0] = 0 khi xét i = 1.
- Như vậy ta sẽ xét dấu tất cả các cách chọn x[1] từ 1 (= x[0] + 1) đến n - k + 1, với mỗi giá trị đó, xét tiếp tất cả các cách chọn x[2] từ x[1] + 1 đến n - k + 2, ... cứ như vậy khi chọn được đến x[k] thì ta có một cấu hình cần liệt kê. Chương trình liệt kê bằng thuật toán quay lui như sau:

```C
#include <stdio.h>
#include <stdlib.h>

int x[50] = {0}, n, k;
FILE *fo = NULL;
void PrintRes()
{
	for (int i = 1; i <= k; i++)
		fprintf(fo,"%d ", x[i]);
	fprintf(fo,"\n");
}
void Backtrack(int i)
{
	for (int j = x[i - 1] + 1; j <= n - k + i; j++)
		{
			x[i] = j;
			if (i == k)
				PrintRes();
			else
				Backtrack(i + 1);
		}
}
void Enter()
{
	FILE *fi = NULL;
	fi = fopen("SUBSET.inp","r");
	fo = fopen("SUBSET.out","w");
	fscanf(fi,"%d %d", &n, &k);
	x[0] = 0;
	Backtrack(1);
	fclose(fi);
	fclose(fo);
}
int main()
{
	Enter();
}
```

- Nếu để ý chương trình trên và chương trình liệt kê dãy nhị phân độ dài n, ta thấy về cơ bản chung chỉ khác nhau ở thủ tục Backtrack(i) - chọn thử các giá trị cho x[i], ở chương trình liệt kê dãy nhị phân ta thử chọn các giá trị 0 hoặc 1 còn ở chương trình liệt kê các tập con k phần tử ta thử chọn x[i] là một trong các giá trị nguyên từ x[i - 1] + 1 đến n - k + i. Qua đó ta có thể thấy tính phổ dụng của thuật toán quay lui: Mô hình cài đặt có thể thích hợp cho nhiều bài toán, khác với phương pháp sinh tuần tự, với mỗi bài toán lại phải có một thuật toán sinh kế tiếp riêng làm cho việc cài đặt mỗi bài mỗi khác, bên cạnh đó, không phải thuật toán sinh kế tiếp nào cũng dễ cài đặt.

<a name="chinhhopkhonglap"> </a>

###1.3 Liệt kê các chỉnh hợp không lặp chập k:

- Để liệt kê các chỉnh hợp không lặp chập k của tập S = {1, 2, ..., n} ta có thể đưa về liệt kê các cấu hình x[1..k] ở đây các x[i] thộc S và khác nhau đôi một.
- Như vậy thủ tục Backtrack(i) - xét tất các khả năng chọn x[i] - sẽ thử hết các giá trị từ 1 đến n, mà các giá trị này chưa bị các phần tử đứng trước chọn. Muốn xem các giá trị nào chưa được chọn ta sử dụng kỹ thuật dùng mảng đánh dấu:

	- Khởi tại một mảng c[1..n] mang kiểu logic boolean. Ở đây c[i] cho biết giá trị i có con tự do hay đã bị chọn rồi.  Ban đầu khởi tạo tất cả các phần tử mảng c là true có nghĩa là các phần tử từ 1 đến n đều tự do.
	- Tại bước chọn các giá trị có thể của x[i] ta chỉ xét những giá trị j có c[j] = TRUE có nghĩa là chỉ chọn những giá trị tự do.
	- Trước khi gọi đệ quy tìm x[i + 1]: Ta đặt giá trị j vừa gán cho x[i] đã bị chọn có nghĩa là đặt c[j] = FALSE để các thủ tục Backtrack(i + 1), Backtrack(i + 2)... gọi sau này không chọn phải gái trị j đó nữa
	- Sau khi gọi đệ quy tìm x[i + 1]: Có nghĩa là sắp tới ta sẽ thử gán một giá trị khác cho x[i] thì ta sẽ đặt giá trị j vừa thử đó thành tự do (c[j] = TRUE), bởi vì khi x[i] đã nhận một giá trị khác rồi thì các phần tử dứng sau: x[i + 1], x[i + 2]... hoàn toàn có thể nhận lại giá trị j nào đó. Điều này hoàn toàn hợp lý trong phép xây dựng chỉnh hợp không lặp: x[1] có n cách chọn, x[2] có n - 1 cách chọn, ... Lưu ý rằng khi thử tục Attempt(i) có i = k thì ta không cần phải đánh dấu gì cả vì tiếp theo chỉ có in kết quá chứ không cần phải chọn thêm phần tử nào nữa

- Input: File văn bản ARRANGE.INP chứa hai số nguyên n, k (1 <= k <= n <= 100) cách nhau ít nhất một dấu cách
- Output: File văn bản ARRANGE.OUT ghi cách chỉnh hợp không lặp chập k của tập {1,.., n}

|ARRANGE.INP|ARRANGE.OUT|
|-----------|-----------|
| 3 2 | 1 2 |
|| 1 3 |
|| 2 1 |
|| 2 3 |
|| 3 1 |
|| 3 2 |

```C
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int x[100], n, k, c[100];
FILE *fo = NULL;

void PrintRes()
{
	for (int i = 1; i <= k; i++)
		fprintf(fo,"%d ", x[i]);
	fprintf(fo,"\n");
}
void Backtrack(int i)
{
	for (int j = 1; j <= n; j++)
		{
			if (c[j] == 0)
			{
				x[i] = j;
				if (i == k)
					PrintRes();
				else
				{	
					c[j] = 1;
					Backtrack(i + 1);
					c[j] = 0;
				}
			}
		}
}
void Enter()
{
	FILE *fi = NULL;
	fi = fopen("ARRANGE.inp","r");
	fo = fopen("ARRANGE.out","w");
	fscanf(fi,"%d %d", &n, &k);
	Backtrack(1);
	fclose(fi);
	fclose(fo);
}
int main()
{
	memset(c, 0, sizeof(c));
	Enter();
 }
```

 - **Nhận xét** : Khi k = n thì đây là chương trình liệt kê hoán vị.

<a name="phantichso"> </a>

###1.4 Bài toán phân tích số:

- **Bài toán**:

- Cho một số nguyên dương n <= 30, hãy tìm tất cả các cách phân tích số n thành tổng của các số nguyên dương, các cách phân tích là hoán vị của nhau chỉ tính là 1 cách.

- **Cách làm**:

- Ta sẽ lưu nghiệm trong mảng x, ngoài ra có một mảng t. Mảng t xây dựng nhu sau: t[i] sẽ là tổng các phần tử trong mảng x từ x[1] đến x[i]: t[i] = x[1] + x[2] + ... + x[i].
- Khi liệt kê các dãy x có tổng các phần tử đúng bằng n, để tránh sự trùng lặp ta sẽ đưa thêm ràng buộc x[i - 1] <= x[i]
- Vì số phần tử thực sự của mảng x là không cố định nên thủ tục PrintResult dùng để in ra 1 cách phân tích phải cso thêm tham số cho biết sẽ in ra bao nhiêu phần tử.
- Thủ tục đệ quy Backtrack(i) sẽ thử các giá trị có thể nhận của x[i] (x[i] >= x[i - 1])
- Khi nào thì in kết quả và khi nào thì gọi đệ quy tìm tiếp?
- Lưu ý rằng t[i - 1] là tổng của tất cả các phần tử từ x[1] đến x[i - 1] do đó

	- Khi t[i] = n tức là (x[i] = n - t[i - 1]) thì in kết quả
	- Khi tìm tiếp, x[i + 1] sẽ phải lớn hơn hoặc bằng x[i]. Mặt khác t[i + 1] là tổng của các số từ x[1] tới x[i + 1] không được vượt quá n. Vậy ta có t[i + 1] <= n <=> t[i - 1] + x[i] + x[i + 1] <= n <=> x[i] + x[i + 1] <= n - t[i - 1] tức là x[i] <= (n - t[i - 1])/2: Ví dụ đơn giản khi n = 10 thì ta chọn x[1] = 6, 7, 8, 9 là việc làm vô nghĩa vì như vậy cũng khi ra nghiệm mà cũng không chọn tiếp x[2] được nữa.

- *Một cách dễ hiểu: Ta gọi đẻ quy tìm tiếp khi gái trị x[i] được chọn còn cho phép chọn thêm một phần tử khác lớn hơn hoặc bằng nó mà không làm tổng vượt quá n. Còn ta in kết quả chỉ khi x[i] mang giá trị đúng bằng số thiếu hụt của tổng i - 1 ohần tử đầu so với n.*
- Vậy thủ tục Backtrack(i) thử các giá trị cho x[i] có thể viết như sau: (để tổng quá cho i = 1, ta đặt x[0] = 1 và t[0] = 0).

	- Xét các giá trị của x[i] từ x[i - 1] đến (n - t[i - 1]) / 2, cập nhật t[i] = t[i - 1] + x[i] và gọi đệ quy tiếp
	- Cuối cùng xét giá trị x[i] = n - t[i - 1] và in kết quả từ x[1] đến x[i].

- **Input :** File văn bản ANALYSE.inp chứa số nguyên dương n <= 100
- **Output :** File văn bản ANALYSE.out ghu các cách phân tích số n.

|ANALYSE.inp|ANALYSE.out|
|-----------|-----------|
| 6 | 6 = 1 + 1 + 1 + 1 + 1 + 1 |
|  | 6 = 1 + 1 + 1 + 1 + 2 |
|  | 6 = 1 + 1 + 1 +3 |
|  | 6 = 1 + 1 + 2 + 2 |
|  | 6 = 1 + 1 + 4 |
|  | 6 = 1 + 2 + 3 |
|  | 6 = 1 + 5 |
|  | 6 = 2 + 2 + 2 |
|  | 6 = 2 + 4 |
|  | 6 = 3 + 3 |
|  | 6 = 6 |

