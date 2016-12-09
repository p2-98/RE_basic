###Tìm hiểu về thuật toán

> Tài liệu tham khảo: DSAP - Lê Minh Hoàng
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối : 09.12.2016

-----

###Mục lục:

- [1. Thuật toán quay lui](#quaylui)

	- [1.1 Liệt kê các dãy nhị phân có độ dài n](#nhiphan);
	- [1.2 Liệt kê các tập con K phần tử](#tapconKphantu);
	- [1.3 Liệt kê các chỉnh hợp không lặp chập k](#chinhhopkhonglap)
	- [1.4 Bài toán phân tích số](#phantichso)
	- [1.5 Bài toán quân hậu](#queen)

- [2. Thuật toán tham lam](#greedy)

	- [2.1 Bài toán máy rút tiền tự động ATM](#money)

- [3. Quy hoạch động](#qhd)

	- [3.1 Công thức truy hồi](#trace)

		- [3.1.1 Cải tiến thứ nhất](#thunhat)
		- [3.1.2 Cải tiến thứ hai](#thuhai)
		- [3.1.3 Cải tiến đệ quy](#dequy)

	- [3.2 Phương pháp quy hoạch động](#quyhoach)

		- [3.2.1 Bài toán quy hoạch](#baitoan)
		- [3.2.2 Phương pháp quy hoạch](#phuongphap)

	- [3.3 Một số bài toán quy hoạch động](#baitoan)

		- [3.3.1 Dãy con đơn điệu tăng dài nhất](#daycon)
		- [3.3.2 Bài toán cái túi](#caitui)

- [4. Tư duy và rèn luyện code của Xcross87](#xcross87)

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

```C
#include <stdio.h>;
#include <stdlib.h>;
int n, x[100], t[100];
FILE *fo = NULL;
void Enter()
{
	FILE *fi = NULL;
	fi = fopen("ANALYSE.inp","r");
	fscanf(fi,"%d", &n);
	fclose(fi);
	x[0] = 1;
	t[0] = 0;
}
void PrintRes(int k)
{
	fprintf(fo,"%d = ", n);
	for (int i = 1; i < k; i++)
		fprintf(fo,"%d + ",x[i]);
	fprintf(fo,"%d", x[k]);
	fprintf(fo,"\n");
}
void Backtrack(int i)
{
	for (int j = x[i - 1]; j <= ((n - t[i - 1])/2); j++)
	{
		x[i] = j;
		t[i] = t[i - 1] + j;
		Backtrack(i + 1);	
	}
	x[i] = n - t[i - 1];
	PrintRes(i);
}
int main()
{
	Enter();
	fo = fopen("ANALYSE.out","w");
	Backtrack(1);
	fclose(fo);
}
```

- **Bây giờ ta xét tiếp một ví dụ kinh điển của thuật toán quay lui:**

<a name="queen"> </a>

####1.5 Bài toán xếp hậu:

- **1.5.1 Bài toán**
- Xét bàn cờ tổng quát kích thước nxn. Một quân hậu trên bàn cờ có thể ăn được các quân khác nằm tại các ô cùng hàng, cùng cột hoặc cùng đường chèo. Hãy tìm các xếp n quân hậu trên bàn cờ sao chpo không quân nào ăn được quân nào.
- Ví dụ một cách xếp với n = 8;

<img src="http://i.imgur.com/V02njLl.png">

- **1.5.2 Phân tích**
- Rõ ràng n quân hậu sẽ được đặt mỗi con một hàng vì hậu ăn được hàng ngang, ta gọi quân hậu sẽ đặt đặt ở hàng 1 là quân hâyụ 1, quân hậu ở hàng 2 là quân hậu 2... quân hậu ở hàng n là quân hậu n. Vậy một nghiệm của bài toán sẽ được biết khi ta tìm ra được vị trí cột của những quân hậu
- Nếu ta định hướng Đông (Phải), Tây (Trái), Nam (Dưới), Bắc (Trên) thì ta nhận thấy rằng:

	- Một đường chéo theo hướng Đông Bắc - Tây Nam (ĐB - TN) bất kỳ sẽ đi qua một số ô, các ô đó có tính chất: Hàng + Cột = C (const). Với mỗi đường chéo ĐB - TN ta có 1 hằng số C và với một hàng số C: 2 <= C <= 2n xác định duy nhất 1 đường chéo ĐB - TN vì vậy ta có thể đánh chỉ số cho các đường chéo ĐB - TN từ 2 đến 2n
	- Một đường chéo theo hướng Đông Nam - Tây Bắc (ĐN - TB) bất kỳ sẽ đi qua một số ô, các ô đó có tính chất Hàng - Cột = C (const). Với mỗi đường chéo ĐN - TB ta có 1 hằng số C và với một ahừng số C: 1 - n <= C <= n - 1 xác định duy nhất 1 đường chéo ĐN - TB vì vậy ta có thể đánh chỉ số cho các đường chéo ĐN - TB từ 1 - n đến n - 1

- **Cài đặt**

	- Ta có 3 mảng logic để đánh dấu:
	- Mảng a[1..n]. a[i] = TRUE nếu như cột i còn tự do, a[i] = FALSE nếu như cột i đã bị một quân hậu khống chế
	- Mảng b[2..2n]. b[i] = TRUE nếu như đường chéo ĐB - TN thứ i còn tự do, b[i] = FALSE nếu như đường chéo đó đã bị một quân hậu khống chế
	- Mảng c[1 - n..n - 1].c[i] = TRUE nếu như đường chéo ĐN - TB thứ i còn tự do, c[i] = FALSE nêu như đường chéo đó đã bị một quân hậu khống chết.
	- Ban đầu cả 3 mảng đánh dấu đều mang giá trị TRUE. (Các cột và đường chéo đều tự do)

- **Thuật toán quay lui**

	- Xét tất cả các cột, thử đặt quân hậu 1 vào một cột, với mỗi các đặt như vậy, xét tất cả các cách đặt quân hậu 2 không bị quân hậu 1 ăn, lại thử 1 cách đặt và xét tiếp các cách đặt quân hậu 3... Mỗi cách đặt được đến quân hậu n cho ta 1 nghiệm
	- Khi chọn vị trí cột j cho quân hậu thứ i, thì ta phải chọn ô(i, j) không bị các quân hậu đặt trước đó ăn, tức là phải chọn cột j còn tự do, đường chéo ĐB - TN (i + j) còn tự do, đường chéo ĐN - TB (i - j) còn tự do. Điều này có thể kiểm tra (a[j] = b[i + j] = c[i - j] = TRUE)
	- Khi thử đặt được quân hậu thứ i vào cột j, nếu đó là quân hậu cuối cùng (i = n) thì ta có một nghiệm. Nếu không:

- **Trước khi gọi** đệ quy tìm các đặt quân hậu thứ i + 1, ta đánh dấu cột và 2 đường chéo bị quân hậy vừa đặt khống chế (a[j] = b[i + j] = c[i - j] = FALSE) để các lần gọi đệ quy tiếp sau chọn cách đặt các quân hậu kết tiếp sẽ không chọn vào những ô nằm trên cột j và những đường chéo này nữa.
-**Sau khi gọi** đệ quy tìm cách đặt quân hậu thứ i + 1, có nghĩa là sắp tới ta lại thử một cách đặt khác cho quân hậu thứ i, ta bỏ đánh dấu cột và 2 đường chéo bị quân hayụa vưa thử đặt khống chét (a[j] = b[i + j] = c[i - j] = TRUE) tức là cột và 2 đường chéo đó là thành tự do, bởi khi đã đặt quân hậu i sang vị trí khác rồi thì cột và 2 đường chéo đó hoàn toàn có thể gán cho một quân hậu khác
- Hãy xem lại trong các chương trình liệt kê chỉnh hợp không lặp và hoán vị về kỹ thuật đánh dấu. Ở đây chỉ khác với liệt kê hoán vị là: liệt kê hoán vị chỉ cần một mảng đánh dấu xem giá trị có tự do không, còn bài toán xếp hậu thì cần phải đánh dấu cả 3 thành phần: Cột, đường chéo ĐB - TN, đường chéo ĐN - TB. Trường hợp đơn giản hơn: Yêu cầu liệt kê các cách đặt n quân xe lên bàn cờ n*n sao cho không quân nào ăn quân nào chính là bài toán liệt kê hoán vị.

	- Input: file văn Queens.inp chứa số nguyên dương n <= 100
	- Output: file văn bản Queens.out, mỗi dòng ghi một cách đặt n quân hậu

| QUEENS.inp | QUEENS.out |
|------------|------------|
| 5 | (1, 1); (2, 3); (3, 5); (4, 5); (5, 4); |
| | (1, 1); (2, 4); (3, 2); (4, 5); (5, 3); |
| | (1, 2); (2, 4); (3, 1); (4, 3); (5, 5); |
| | (1, 2); (2, 5); (3, 3); (4, 1); (5, 4); |
| | (1, 3); (2, 1); (3, 4); (4, 2); (5, 5); |
| | (1, 4); (2, 1); (3, 3); (4, 5); (5, 2); |
| | (1, 4); (2, 2); (3, 5); (4, 3); (5, 1); |
| | (1, 5); (2, 2); (3, 4); (4, 1); (5, 3); |
| | (1, 5); (2, 3); (3, 1); (4, 4); (5, 2); |

```C
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define c(i) c[i + 100]
#define TRUE 1
#define FALSE 0
#define Bool int

Bool c[200], a[100], b[200];
int x[100], n;
FILE *fo = NULL;
void Enter()
{
	FILE *fi = NULL;
	fi = fopen("QUEENS.inp","r");
	fscanf(fi,"%d", &n);
	fclose(fi);
	for (int i = -n; i <= n ; i++)
		{
			c(i) = TRUE;
		}
	for (int i = 0; i <= n; i++)
		a[i] = TRUE;
	for (int i = 0; i <= n*2; i++)
		b[i] = TRUE;
}
void PrintRes()
{
	for (int i = 1 ; i <= n; i++)
		fprintf(fo,"(%d, %d); ",i, x[i]);
	fprintf(fo,"\n");
}
void Backtrack(int i)
{
	for (int j = 1; j <= n; j++)
	{
			if ((a[j] == TRUE) && (b[i + j] == TRUE) && (c(i - j) == TRUE))
				{
					x[i] = j;
					if (i == n) PrintRes();
				else
					{
						a[j] = FALSE;
						b[i + j] = FALSE;
						c(i - j) = FALSE;
						Backtrack(i + 1);
						a[j] = TRUE;
						b[i + j] = TRUE;
						c(i - j) = TRUE;
					}
				}
	}
}
int main()
{
	fo = fopen("QUEENS.out","w");
	Enter();
	Backtrack(1);
	fclose(fo);
}
```

- Tên gọi thuật toán quay lui, đứng trên phương diện cài đặt có thể nen gọi là kỹ thuật vét cạn bằng quay lui thì chính xác hơn, tuy nhiên đứng trên phương diện bài toán, nếu như ta coi công việc giải bài toán bằng cách xét tất cả các khả năng cũng là 1 cách giải thì tên gọi thuật toán quay lui cũng không có gì trái logic. Xét hoạt động của chương trình tên cây tìm kiếm quay lui ta thấy tại bước thử chọn x[i] nó sẽ gọi đệ quy đẻ tìm tiếp x[i + 1] có nghĩa là quá trình sẽ duyệt tiến sâu xuống phía dưới đến tận nút lá, sau khi đã duyệt hết các nhánh, tiến trình lùi lại thử áp đặt một giá trị khác x[i], đó chính là nguồn gốc của tên gọi "thuật toán quay lui."

<a name="greedy"> </a>

###2. Thuật toán tham lam:

- Giải thuật tham lam là gì ?

	- Tham lam (hay tham ăn) là một trong những phương pháp phổ biến nhất để thiết kế giải thuật. Nếu bạn đã đọc truyện dân gian thì sẽ có câu chuyện như thế này: trên một mâm cỗ có nhiều món ăn, món nào ngon nhất ta sẽ ăn trước, ăn hết món đó ta sẽ chuyển sang món ngon thứ hai, và chuyển tiếp sang món thứ ba, …
	- Rất nhiều giải thuật nổi tiếng được thiết kế dựa trên ý tưởng tham lam, ví dụ như giải thuật cây khung nhỏ nhất của Dijkstra, giải thuật cây khung nhỏ nhất của Kruskal, …
	- Giải thuật tham lam (Greedy Algorithm) là giải thuật tối ưu hóa tổ hợp. Giải thuật tìm kiếm, lựa chọn giải pháp tối ưu địa phương ở mỗi bước với hi vọng tìm được giải pháp tối ưu toàn cục.
	- Giải thuật tham lam lựa chọn giải pháp nào được cho là tốt nhất ở thời điểm hiện tại và sau đó giải bài toán con nảy sinh từ việc thực hiện lựa chọn đó. Lựa chọn của giải thuật tham lam có thể phụ thuộc vào lựa chọn trước đó. Việc quyết định sớm và thay đổi hướng đi của giải thuật cùng với việc không bao giờ xét lại các quyết định cũ sẽ dẫn đến kết quả là giải thuật này không tối ưu để tìm giải pháp toàn cục.

- Bạn theo dõi một bài toán đơn giản dưới đây để thấy cách thực hiện giải thuật tham lam và vì sao lại có thể nói rằng giải thuật này là không tối ưu.

- Bài toán đếm số đồng tiền
	
	- Yêu cầu là hãy lựa chọn số lượng đồng tiền nhỏ nhất có thể sao cho tổng mệnh giá của các đồng tiền này bằng với một lượng tiền cho trước.
	- Nếu tiền đồng có các mệnh giá lần lượt là 1, 2, 5, và 10 xu và lượng tiền cho trước là 18 xu thì giải thuật tham lam thực hiện như sau:

		- Bước 1: Chọn đồng 10 xu, do đó sẽ còn 18 – 10 = 8 xu.
		- Bước 2: Chọn đồng 5 xu, do đó sẽ còn là 3 xu.
		- Bước 3: Chọn đồng 2 xu, còn lại là 1 xu.
		- Bước 4: Cuối cùng chọn đồng 1 xu và giải xong bài toán.

- Bạn thấy rằng cách làm trên là khá ổn, và số lượng đồng tiền cần phải lựa chọn là 4 đồng tiền. Nhưng nếu chúng ta thay đổi bài toán trên một chút thì cũng hướng tiếp cận như trên có thể sẽ không đem lại cùng kết quả tối ưu.
- Chẳng hạn, một hệ thống tiền tệ khác có các đồng tiền có mệnh giá lần lượt là 1, 7 và 10 xu và lượng tiền cho trước ở đây thay đổi thành 15 xu thì theo giải thuật tham lam thì số đồng tiền cần chọn sẽ nhiều hơn 4. Với giải thuật tham lam thì: 10 + 1 + 1 +1 + 1 + 1, vậy tổng cộng là 6 đồng tiền. Trong khi cùng bài toán như trên có thể được xử lý bằng việc chỉ chọn 3 đồng tiền (7 + 7 +1).
Do đó chúng ta có thể kết luận rằng, giải thuật tham lam tìm kiếm giải pháp tôi ưu ở mỗi bước nhưng lại có thể thất bại trong việc tìm ra giải pháp tối ưu toàn cục.

<a name="money"> </a>

####2.1 Bài toán máy rút tiền tự động ATM:

- Thuật toán với ý tưởng tham lam đơn giản, hàm chọn như sau: Tại mỗi bước ta sẽ chọn tờ tiền lớn nhất còn lại không vượt quá lượng tiền còn phải trả, cụ thể:

	- Sắp xếp các tờ tiền giảm gần theo giá trị.
	- Lần lượt xét các tờ tiền từ giá trị lớn đến giá trị nhỏ, nếu vẫn còn chưa lấy đủ S và tờ tiền đang xét có giá trị nhỏ hơn hoặc bằng S thì lấy luôn tờ tiền đó.

| ATM.inp | ATM.out |
|---------|---------|
| 10 390 | 5 |
| 200 10 20 20 50 50 50 50 100 100 | 200 100 50 20 20 |

```C
#include <stdio.h>
#include <stdlib.h>

int n, s, a[100], x[100], c = 0;

void Enter()
{
	FILE *fi = NULL;
	fi = fopen("ATM.inp","r");
	fscanf(fi,"%d %d",&n, &s);
	for (int i = 1; i <= n; i++)
		fscanf(fi,"%d", &a[i]);
	fclose(fi);
}
void QSort(int L, int H)
{
	int i = L;
	int j = H;
	int x = a[(L + H) / 2];
	do
	{
		while (a[i] > x) i++;
		while (a[j] < x) j--;
		if (i <= j)
			{
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
				i++;
				j--;
			}
	} while (i <= j);
	if (L < j) QSort(L, j);
	if (i < H) QSort(i, H);
}
void solve()
{
	for (int i = 1; i <= n; i++)
		if (s >= a[i])
		{
			c++;
			x[i] = 1;
			s -= a[i];
		}
}
void Output()
{
	FILE *fo = NULL;
	fo = fopen("ATM.out","w");
	if (s == 0)
	{
		fprintf(fo,"%d \n", c);
		for (int i = 1; i <= n; i++)
		{
			if (x[i] == 1)
				fprintf(fo,"%d ",a[i]);
		}
	}
	else
		fprintf(fo,"-1");
	fclose(fo);
}
int main()
{
	Enter();
	QSort(1, n);
	solve();
	Output();
}
```

<a name="qhd"> </a>

###3. Quy hoạch động

-Các thuật toán đệ quy có ưu điểm dễ vài đặt, tuy nhiên do bản chất của quá trình đệ quy, các chương trình này thường kéo theo những đòi hỏi lớn về không gian bộ nhớ và một lượng tính toán khổng lồ.
- Quy hoạch động (Dynamic programming) là một kỹ thuật nhằm đơn giản hoá việc tính toán các công thức truy hồi bằng cách lưu trữ toàn bộ hay một phần kết quả tính toán tại mỗi bước với mục đích sử dụng lại. Bản chất của quy hoạch động là thay thế mô hình tính toán "từ trên xuống" (Top - down) bằng mô hình tính toán (Bottom - up)
- Từ "programming" ở đây không liên quan gì tới việc lập trình cho máy tính, đó là một thuật ngữ mà các nhà toán học hay dùng để chỉ ra các bước khung trong việc giải quyết một dạng bài toán hay một lớp các vấn đề. Không có một thuật toán tổng quát để giải tất cả các bài toán quy hoạch động.

<a name="trace"> </a>

####3.1 Công thức truy hồi:

- **Ví dụ:** Cho số tự nhiên n <= 100. Hãy cho biết có bao nhiêu cách phân tích số n thành tổng của dãy các số nguyên dương, các cách phân tích là hoán vị của nhau chỉ tính là một cách.

	- *Ví dụ:* n = 5 có 7 cách phân tích:
	- 1. 5 = 1 + 1 + 1 + 1 + 1
	- 2. 5 = 1 + 1 + 1 + 2
	- 3. 5 = 1 + 1 + 3
	- 4. 5 = 1 + 2 + 2
	- 5. 5 = 1 + 4
	- 6. 5 = 2 + 3
	- 7. 5 = 5

- **(Lưu ý: n = 0 vẫn coi là có 1 cách phân thành tổng các số nguyên dương (0 là tổng của dãy rỗng))**
- Để giải bài toán này, trong chuyên mục trước ta đã dùng phương pháp liệt kê tất cả các cách phân tích và đếm số cấu hình. Bây giờ ta thử nghĩ xem, *có cách nào tính ngay ra số lượng các cách phân tích mà không càn phải liệt kê hay không?*. Bởi vì khi số cách phân tích tương đối lớn, phương pháp liệt kê tỏ ra khá chậm (n = 100 có 190569292 cách phân tích).
- **Nhận xét:**
- Nếu gọi **F[m, v] là số cách phân tích số v thành tổng các số nguyên dương <= m**. Khi đó:
- Các cách phân tích số v thành tổng các số nguyên dương <= m có thể chưa làm 2 loại:

	- Loại 1: Không chứa số m trong phép phân tích, khi đó số cách phân tích loại này chính là số cách phân số v thành tổng các số nguyên dương < m, tức là số cách phân tích số v thành tổng các số nguyên <= m - 1 và bằng F[m - 1, v].
	- Loại 2: Có chứa ít nhất một số m trong phép phân tích. Khi đó nếu trong các cách phân tích loại này ta bỏ đi số m đó thì ta sẽ được các cách phân tích số v - m thành tổng các số nguyên < m (Lưu ý: điều này chri đúng khi không tính lặp lại các hoán vị của một cách). Có nghĩa là về mặt số lượng, số các cách phân tích loại này bằng F[m, v - m]

- Trong trường hợp m > v thì rõ ràng chỉ có các cách phân tích loại 1, còn trong trường hợp m <= v thì ta sẽ có cả các cách phân tích loại 1 và loại 2. Vì thế:

	- F[m, v] = F[m - 1, v]; if m > v
	- F[m - 1, v] + F[m, v - m]; if m <= v

- Ta có công thức xây dựng F[m, v từ F[m - 1, v] và F[m, v - m]. Công thức này có tên gọi là công thức truy hồi đưa việc tính F[m, v] về việc tính các F[m', v'] với dữ liệu hơn. Tất nhiên cuối cùng ta sẽ quan tâm đến F[n, n]; Số các cách phân tích n thành tổng các số nguyên dương <= n.
- Ví dụ với n = 5, bảng F sẽ là

| F | 0 1 2 3 4 5 |
|---|-------------|
| 0 | 1 0 0 0 0 0 |
| 1 | 1 1 1 1 1 1 |
| 2 | 1 1 2 2 3 3 |
| 3 | 1 1 2 3 4 5 |
| 4 | 1 1 2 3 5 6 |
| 5 | 1 1 2 3 5 7 |

- Nhìn vào bảng F, ta thấy rằng F[m, v] được tính bằng tổng của:
- Một phần tử ở hàng trên: F[m = 1, v] và một phần tử ở cùng hàng, bên trái: F[m, v - m].
- Ví dụ F[5, 5] sẽ đyợc tính bằng F[4, 5] + F[5, 0], hay F[3, 5] sẽ được tính bằng F[2, 2] + F[3, 2]. Chính vì vậy để tính F[m, v] thì F[m - 1, v] và F[m, v - m] phải được tính trước. Suy ra thứ tự hợp lý để tính các phần tử trong bảng F sẽ phải là theo thứ tụ từ trên xuống và trên mỗi hàng thì tính theo thứ tự từ trên xuống và trên mỗi hàng thì tính theo thứ tự từ trái qua phải.
- Điều đó có nghĩa là ban đầu ta phải tính hàng 0 của bảng: F[0, v] = số dãy có các phần tử <= 0 mà tổng bằng v, theo quy ước ở để bài thì F[0, 0] = 1 còn F[0, v] với mọi v > 0 đều là 0. Vậy giải thuật dựng rất đơn giản: Khởi tạo dòng 0 của bảng F: F[0, 0] = 1 còn F[0, v] với mọi v > 0 đều bằng 0, sau đó dùng công thức hồi tính ra tất cả các phần tử của bảng F. Cuối cùng F[n, n] là số cách phân tích cần tìm.

```C
#include <stdio.h>
#include <memory.h>

int main()
{
	int a[100][100], n;
	scanf("%d", &n);
	memset(a, 0, sizeof(a));
	a[0][0]6 = 1;
	for (int m = 1; m <= n; m++)
		for (int v = 0; v <= n; v++)
		{
			if (v < m)
				a[m][v] = a[m - 1][v];
			else
				a[m][v] = a[m - 1][v] + a[m][v - m];	
		}
	printf("%d Analyses", a[n][n]);
}
```
<a name="thunhat"> </a>

####3.1.1 Cải tiến thứ nhất:
- Cách làm trên có thể tóm tắt lại như sau: Khởi tạo dòng 0 của bảng, sau đó dùng dòng 0 tính dòng 1, dùng dòng 1 tính dòng 2 v.v... tới khi tính được hết dòng n. Có thể nhận thấy rằng khi đã tính xong dòng thứ k thì việc lưu trữ các dòng từ dòng 0 tới dòng k - 1 là không caàn thiết bởi vì việc tính dòng k + 1 chỉ phụ thuộc các giá trị lưu trữ trên dòng k. Vậy ta có thể dùng hai mảng một chiều: Mảng Current lưu dòng hiện thời đang xét của hàng và mảng Next lưu dòng kết tiếp, đầu tiên mảng Current được gán các giá trị tương ứng trên dòng 0. Sau đó dùng mảng Current tính mảng Next, mảng Next sau khi tính sẽ mang các giá trị tương ứng trên dòng 1. Rồi lại gán mảng Current = Next và tiếp tục dùng mảng Current tính mảng Next, mảng Next sẽ gồm các giá trị tương ứng trên 2 v.v... Vậy ta có cài đặt cải tiến sau:

```C
#include <stdio.h>
#include <memory.h>

int main()
{
	int current[100], next[100], n;
	scanf("%d", &n);
	memset(current, 0, sizeof(current));
	current[0] = 1;
	for (int m = 1 ; m <= n; m++)
	{
		for (int v = 0; v <= n; v++)
			if (v < m) 
				next[v] = current[v];
			else
				next[v] = next[v - m] + current[v];
		memcpy(current, next, sizeof(next)); 
	}
	printf("%d Analyses", current[n]);
}
```

- Cách làm trên đã tiết kiệm được khá nhiều không gian lưu trữ, nhưng nó hơi chậm hơn phương pháp đầu tiên vì phép gán mảng (current = next). Có thể cảu tiến thêm cách làm này như sau:

```C
#include <stdio.h>
#include <memory.h>

int main()
{
	int n, b[100][100]; 
	scanf("%d", &n);
	memset(b[1], 0, sizeof(b[1]));
	b[1][0] = 1;
	int x = 1;
	int y = 2;
	for (int m = 1; m <= n; m++)
	{
		for (int v = 0; v <= n; v++)
		if ( v < m) 
			b[y][v] = b[x][v];
		else
			b[y][v] = b[x][v] + b[y][v - m];
		x = 3 - x; y = 3 - y;
	}
	printf("%d Analyses", b[x][n]);
}
```

<a name="thuhai"> </a>

####3.1.2 Cải tiến thứ hai:

- Ta vẫn còn cách tốt hơn nữa, tại mỗi bước, ta chỉ cần lưu lại một dòng của bảng 1 chiều, sau đó dùng mảng đó tính lại chính nó để sau khi tính, mảng một các giá trị của bảng F trên dòng kế tiếp.

```C
#include <stdio.h>
#include <memory.h>

int main()
{
	int l[100], n;
	scanf("%d", &n);
	memset(l, 0, sizeof(l));
	l[0] = 1;
	for (int m = 1; m <= n; m++)
		for (int v = m; v <= n; v++)
			l[v] = l[v] + l[v - m];
	printf("%d Analyses", l[n]);
}
```

<a name="dequy"> </a>

####3.1.3 Cài đặt đệ quy:

- Xem lại công thức truy hồi tính F[m, v] = F[m - 1, v] + F[m, v - m], ta nhận thấy rằng để tính F[m, v] ta phải biết được chính xác F[m - 1, v] và F[m, v - m]. Như vậy việc xác định thứ tự tính các phần tử trong bảng F (phần tử nào tính trước, phần tử tính sau) là quan trọng. Tuy nhiên ta có thể tính dựa trên một hàm đệ quy mà không cần phải quan tâm tới thứ tự tính toán. Việc viết một hàm đệ quy mà không cần phải quan tâm tới thứ tự tính toán. Việc viết một hàm đệ quy tính công thức truy hồi khá đơn giản, như ví dụ này ta có thể viết:

```C
#include <stdio.h>

int GetF(int m, int v)
{
	if (m == 0)
		if (v == 0) 
			return 1;
		else
			return 0;
	else
		if (m > v)
			return GetF(m - 1, v);
		else
			return GetF(m - 1, v) + GetF(m, v - m);
}
int main()
{
	int n;
	scanf("%d", &n);
	printf("%d Analyses", GetF(n, n));
}
```

- Phương pháp cài đặt này tỏ ra khá chậm vì phải gọi nhiều lần mỗi hàm GetF(m, v) (bài sau giải thích rõ hơn điều này). Ta có thể cải tiến bằng cách kết hợp với một mảng hai chiều F. Ban đầu các phần tử của F được coi là "chưa biết" (bằng cách gán một giá trị đặt biệt). Hàm GetF(m, v) khi được gọi trước hết sẽ tra cứu tới F[m, v], nếu F[m, v] chưa biết thì hàm GetF(m, v) khi được gọi trước hết sẽ tra cứu tới F[m, v], nếu F[m, v] chưa biết thì hàm GetF(m, v) sẽ gọi đệ quy để tính gái trị của F[m, v] rồi dùng giá trị này gán cho kết quả hàm, còn nếu F[m, v] đã biết thì hàm này chỉ việc gán kết quả hàm là F[m, v] mà không cần gọi đệ quy để tính toán nữa.

```C
#include <stdio.h>
#include <memory.h>

int GetF(int F[100][100], int m, int v)
{
	if (F[m][v] = -1)
	{
		if (m == 0)
			if (v == 0)
				F[m][v] = 1;
			else
				F[m][v] = 0;
		else
			if (m > v)
				F[m][v] = GetF(F, m - 1, v);
			else
				F[m][v] = GetF(F, m - 1, v) + GetF(F, m, v - m);
	}
	return F[m][v];
}
int main()
{
	int F[100][100], n;
	scanf("%d", &n);
	memset(F, -1, sizeof(F));
	printf("%d Analyses", GetF(F, n, n));
}
```

- Việc sử dụng phương pháp đệ quy để giải công thức truy hồi là một kỹ thuật đáng lưu ý, vì khi gặp một công thức truy hồi phức tạp, khó xác định thứ tự tính toán thì phương pháp này tỏ ra rất hiệu quả, hơn thế nữa nó làm rõ hơn bản chất đệ quy của công thức truy hồi.

<a name="quyhoach"> </a>

###3.2 Phương pháp quy hoạch động

<a name="baitoan"> </a>

####3.2.1 Bài toán quy hoạch:

- Bài toán quy hoạch là bài toán tối ưu: gồm có một hàm f gọi là hàm mục tiêu hay hàm đánh giá, các hàm g1, g2,... gn cho giá trị logic gọi là hàm ràng buộc. Yêu cầu của bài toán là tìm một cấu hình x thoả mãn tất cả các ràng buộc g1, g2, ..., gn. gi(x) = TRUE (với mọi 1 <= i <= n) và x là tốt nhất, theo nghĩa không tồn tại một cấu hình y nào khác thoả mãn các hàm ràng buộc mà f(y) tốt hơn f(x).

- **Ví dụ:**

	- Tìm (x, y) để
	- Hàm mục tiêu: x + y -> max
	- Hàm ràng buộc: x^2 + y^2 <= 1
	- Xét trong mặt phẳng toạ độ, những cặp (x, y) thoả mãn x^2 + y^2 <= 1 là toạ độ của những điểm nằm trong hình tròn có tâm 0 là gốc toạ độ, bán kính 1. Vậy nghiệm của bài toán bắt buộc nằm trong hình tròn đó.
	- Những đường thẳng có phương trình: x + y = C (C là một hằng số) là đường thẳng vuông góc với đường phân giác góc phần thư thứ nhất. Ta phải tìm số C lớn nhất mà đường thẳng x+ y = C vẫn có điểm chung với đường trong (O, 1). Đường thẳng đó là một tiếp tuyến của đường tròn: x + y = sqrt(2). Tìm (1/sqrt(2), 1/sqrt(2)) tương ứng với nghiệm tối ưu của bài đã cho.

<img src="http://i.imgur.com/4t3uVKk.jpg">

- Các dạng bài toán quy hoạch rất phong phú và đa dạng, ứng dụng nhiều trong thực tế, nhưng cũng cần biết rằng, đa số các bài toán quy hoạch là không giải được, hoặc chưa giải được. Cho đến nay, người ta mới chỉ có thuật toán đơn hình giải bài toán quy hoạch tuyến tính lồi, và một vài thuật toán khác áp dụng cho các lớp bài toán cụ thể.

<a name="phuongphap"> </a>

####3.2.2 Phương pháp quy hoạch động:

- Phương pháp quy hoạch động dùng để giải bài toán tối ưu có bản chất đệ quy, tức là viẹc tìm phương án tối ưu cho bài toán đó có thể đưa về tìm phương án tối ưu của một số hữu hạn các bài toán con. Đối với nhiều thuật toán đệ quy chúng ta đã tìm hiểu, nguyên lý chia để trị (divide and conquer) thường đóng vai tròn chủ đạo trong việc thiết kế thuật toán. Để giải quyết một bài toán ớn, ta chia nó làm nhiều bài toán con cùng dạng với nó để có thể giải quết độc lâp. Trong phương pháp quy hoạch động, nguyên lý này càng được thể hiện rõ: Khi không biết cần phải giải quyết những bài toán con nào, ta sẽ đi giải quyết tất cả các bài toán con và lưu trữ những lời giải hay đáp số của chúng với mục đích sử dụng lại theo một sự phối hợp nào đó để giải quyết những bài toán tổng quát hơn. Đó chính là điểm khác nhau giữa Quy hoạch động và phép phân giải đệ quy và cũng là nội dung phương pháp quy hoạch động:

	- Phép phân giải đệ quy bắt đầu từ bài toán lớn phân rã thành nhiều bài toán con và đi giải từng bài toán con đó. Việc giải từng bài toán con lại đưa về phép phân rã tiếp thành nhiều bài toán nhỏ hơn và lại đi giải tiếp bài toán nhỏ hơn đó bất kể nó đã được giải hay chưa.
	- Quy hoạch động bắt đầu từ việc giải tất cả các bài toán nhỏ nhất (bài toán cơ sở) để từ đso từng bước giải quyết những bài toán lớn hơn, cho tới khi giải được bài toán lớn  nhất (bài toán ban đầu).

- Ta xét một ví dụ đơn giản:

	- Dãy Fibonacci là dãy vô hạn các số nguyên dương F[1], F[2],... được định nghĩa như sau:

	- F[i] = i, if i <= 2;
	- F[i] = F[i - 1] + F[i - 2], if i >= 3;

- Hãy tính F[6]
- Xét hai cách cài đặt chương trình:
- Cách 1:

```C
int F(int i)
{
	if (i < 3)
		return 1;
	else
		return F(i - 1) + F(i - 2);
}
int main()
{
	printf("%d", F[6]);
}
```

- Cách 2:

```C
int main()
{
	int F[6];
	F[1] = 1;
	F[2] = 1;
	for (int i = 3; i < 7; i++)
		F[i] = F[i - 1] + F[i - 2];
	printf("%d", F[6]);
}
```

- Các 1 có hàm đệ quy F(i) để tính số Fibonacci thứ i. Chương trình chính gọi F(6), nó sẽ gọi tiếp F(5) và F(4) để tính ... Quá trình tính toán có thể vẽ như cây dứoi đây. Ta nhận thấy để tính F(6) nó phải tính 1 lần F(5), hai lần F(4), ba lần F(3), năm lần F(2), ba lần F(1).

<img src="http://i.imgur.com/AfpvLig.png">

- Cách 2 thì không như vậy. Trước hết nó tính sẵn F[1] và F[2], từ đó tính tiếp F[3], lại tihs tiếp được F[4], F[5], F[6]. Đảm bảo rằng mỗi giá trị Fibonacci chỉ phải tính 1 lần.
- (Cách 2 còn có thể cải tiến thêm nữa, chỉ cần dừng 3 giá trị tính lại lẫn nhau).
- Trước khi áp dụng phương pháp quy hoạch động ta phải xét xem phương pháp đó có thể thoả mãn những yêu cầu dưới đây hay không:

	- Bài toán lớn phải phân rã được thành nhiều bài toán con, mà sự phối hợp lời giải các bài toán con đó cho ta lời giải của bài toán lớn.
	- Vì quy hoạch động là đi giải tất cả các bài toán con, nên nếu không đủ không gian vật lý lưu trữ lời giải (bộ nhớ, đĩa,...) để phối hợp chúng thì phương pháp quy hoặch động cũng không thể thực hiện được.
	- Quá trình từ bài toán cơ sở tìm ra lời giải bài toán ban đầu phải qua hữu hạn bước.

- **Các khái niệm:**

	- Bài toán giải theo phương pháp quy hoạch động gọi là **bài toán quy hoạch động**
	- Công thức phối hợp nghiệm của các bài toán con để có nghiệm của bài toán lớn gọi là **công thức truy hồi (hay phương trình truy toán) của quy hoạch động.
	- Tập các bài toán nhỏ nhất có ngay lời giải để từ đó giải quyết các bài toán lớn hơn gọi là *cơ sở quy hoạch động**
	- Không gian lưu trữ lời giải các bài toán con để tìm các phối hợp chúng gọi là *bảng phương án quy hoạch động**.

- **Các bước cài đặt một chương trình sử dụng quy hoạch động:**

	- Giải tất cả các bài toán cơ sở (thông thường rất dễ), lưu các lời giải vào bảng phương án.
	- Dùng công thức truy hồi phối hợp những lời giải của những bài toán nhỏ đã lưu trong brng phương án để tìm lời giải của những bài toán lớn hơn và lưu chúng vào bảng phương án. Cho tới khi bài toán ban đầu tìm được lời giải.
	- Dựa vào bảng phương án, truy vết tìm ra nghiệm tối ưu.

- Cho đến nay, vẫn chưa có một định lý nào cho biết một cách chính xác những bài toán có thể giải quyết hiệu quả bằng quy hoạch động. Tuy nhiên để biết được bài toán có thể giải được bằng quy hay không, ta có thể tự đặt câu hỏi: **"Một nghiệm tối ưu của bài toán lớn có phải là sự phối hợp các nghiệm tối ưu của các bài toán con hay không?"** và **"Liệu có thể nào lưu trữ được nghiệm các bài toán con dưới một hình thức nào đó để phối hợp tìm được nghiệm bài toán lớn".**

<a name="baitoanqhd"> </a>

###3.3 Một số bài toán quy hoạch động:

<a name="daycon"> </a>

####3.3.1 Dãy con đơn điệu tăng dài nhất:

- Cho dãy số nguyên A = a[1..n]. (n <= 10^6, -10^6 <= a[i] <= 10^6). Một dãy con của A là một cách chọn ra trong A một số phần tử giữ nghuyên thứ tự. Như vậy A có 2^n dãy con.
- Yêu cầu: Tìm dãy con đơn điệu tăng của A có độ dài lớn nhất,
- Ví dụ: A = (1, 2, 3, 4, 9, 10, 5, 6, 7). Dãy con đơn điệu tăng dài nhất là (1, 2, 3, 4, 5, 6, 7).
- **Input:** file văn bản INCSEQ.inp

	- Dòng 1: Chứa số n
	- Dòng 2: Chứ n số a[1], a[2],..., a[n] cách nhau ít nhất một dấu cách

- **Output:** file văn bản INCSEQ.out

	- Dòng 1: Ghi dộ dài dãy con tìm được
	- Các dòng tiếp: Ghi dãy con tìm được và chỉ số những phần tử được chọn vào dãy con đó.

| INCSEQ.inp | INCSEQ.out |
|------------|------------|
| 11 | 8 |
| 1 2 3 8 9 4 5 6 20 9 10 | a[1] = 1 |
| | a[2] = 2 |
| | a[3] = 3 |
| | a[6] = 4 |
| | a[7] = 5 |
| | a[8] = 6 |
| | a[10] = 9 |
| | a[11] = 10 |

- **Cách giải**
- Bổ sung vào A hai phần tử: a[0] = âm vô cực và a[n + 1] = dương vô cực. *Khi đó dãy con đơn điệu tăng dài nhất chắc chắn sẽ bắt đầu từ a[0] và kết thúc ở a[n + 1].*
- Với mọi i: 0 <= i <= n + 1. Ta sẽ tính L[i] = độ dài dãy con đơn điệu tăng dài nhất bắt đầu từ a[i].

- **Cơ sở quy hoạch động (bài toán nhỏ nhất):**
- L[n + 1] = Độ dài dãy con đơn điệu tăng dài nhất bắt đầu tại a[n + 1] = dương vô cực. Dãy con này chỉ gồm một phần tử (dương vô cực) nên L[n + 1] = 1.
- **Công thức truy hồi:**
- Giả sử với i chạy từ n về 0, ta cần tính L[i]: độ dài dãy con tăng dài nhất bằng đầu tại a[i].L[i] được tính trong điều kiện L[i + 1 .. n + 1] đã biết:
- Dãy con đơn điệu tăng dài nhất bắt đầu từ a[i] sẽ được thành lập bằng cách lấy a[i] ghép vào đầu một trong số nhữung dãy con đơn điệu tăng dài nhất bằng đầu tại vị trí a[j] đứng sau a[i]. Ta sẽ chọn dãy nào để ghép a[i] vào đầu? Tất nhiên là chỉ dược ghép a[i] vào đầu những dãy con bắt đầu tại a[j] nào đó lớn hơn a[i] (để đảm bảo tính tăng) và dĩ nhiên ta sẽ chọn dãy dai nhất để ghép a[i] vào đầu (để đảm bảo tính dài nhất). Vậy L[i] được tính như sau: **Xét tất cả các chỉ số j trong khỏng từ i + 1 đến n + 1 mà a[j] > a[i], chọn ra chỉ số jmax có L[jmax] lớn nhất. Đặt L[i] = L[jmax] + 1:**
- L[i] = max(L[j] + 1) với (i < j <= a - 1 và a[i] < a[j])
- **Truy vết:**
- Tại bước xây dựng dãy L, mỗi khi gán L[i] = L[jmax] + 1, ta đặt T[i] = jmax. Để lưu lại rằng: Dãy con dài nhất bắt đầu tại a[i] sẽ có phần tử thứ hai kế tiếp là a[jmax].
- Sau khi tính xong hai dãy L và T, ta bắt đầu từ T[0].

	- T[0] chính là phần tử đầu tiên được chọn,
	- T[T[0]] là phần tử thứ hai được chọn,
	- T[T[T[0]]] là phần thử thứ ba được chọn,...

- Quá trình truy viết có thể diễn tả như sau:

```C
int i = T[0];
while (i != n + 1)
{
	<Thông báo chọn a[i]>
	i = T[i];
}
```

- Ví dụ: Với A = (5, 2, 3, 4, 9, 10, 5, 6, 7, 8). Hai dãy L và T say khi tính sẽ là:

<img src="http://i.imgur.com/A4gz2hD.jpg">

```C
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int max = 1000000;
int n, *a = new int [max], *L = new int [max], *T = new int [max];
void Enter()
{
	FILE *fi = NULL;
	fi = fopen("INCSEQ.inp","r");
	fscanf(fi,"%d", &n);
	for (int i = 1; i <= n; i++)
		fscanf(fi,"%d", &a[i]);
	fclose(fi);
}
void Optimize()
{
	a[0] = INT_MIN;
	a[n + 1] = INT_MAX;
	L[n + 1] = 1;
	for (int i = n; i > -1; i--)
	{
		int jmax = n + 1;
		for (int j = i + 1; j < n + 2; j++)
			if ((a[j] > a[i]) && (L[j] > L[jmax]))
				jmax = j;
		L[i] = L[jmax] + 1;
		T[i] = jmax;
	}
}
void PrintRes()
{
	FILE *fo = NULL;
	fo = fopen("INCSEQ.out","w");
	fprintf(fo, "%d\n",L[0] - 2);
	int i = T[0];
	while (i != n + 1)
	{
		fprintf(fo,"a[%d] = %d\n",i, a[i]);
		i = T[i];
	}
	fclose(fo);
}
int main()
{
	Enter();
	Optimize();
	PrintRes();
	delete[] a;
	delete[] T;
	delete[] L;
}
```

- **Cải tiến:**
- Khi bắt đầu vào một lần lặp với một giá trị i, ta đã biết được:

	- m: Độ dài dãy con đơn điệu tăng dài nhất cảu dãy a[i + 1 .. n + 1]
	- StartOf[k] (1 <= k <= m): Phần tử a[StartOf[k]] là phần tử lớn nhất trong số các phần tử trong đoạn a[i + 1 .. n + 1] thoả mãn: Dãy con đơn điệu tăng dài nhất bắt đầu từ a[StartOf[k]] có dài k. Do thứ tự tính toán được áp đặt như trong sơ đồ trên, ta dễ dàng nhận thất rằng:

		- a[StartOf[k]] < a[StartOf[k - 1]] < ... < a[StartOf[1]].

- Điều kiện để có dãy con đơn điệu tăng độ dài p + 1 bắt đầu tại a[i] chính là a[StartOf[p]] > a[i] (vì theo thứ tự tính toán thì khi bắt đầu một lần lặp với giá trị i, a[StartOf[p]] luôn đứng sau a[i]). Mặt khác nếu đem a[i] ghép vào đầu dãy con đơn điệu tăng dài nhất bắt đầu tại a[StartOf[p]] mà thu được dãy tăng thì đem a[i] ghép vào đầu dãy con đơn điệu tăng dài nhất bắt đầu tại a[StartOf[p - 1]] ta cũng thu được dãy tăng. Vạy để tính L[i], ta có thể tìm số p lớn nhất thoả mãn a[StartOf[p]] > a[i] bằng **thuật toán tìm kiếm nhị phân** rồi đặt L[i] = p + 1 (và sau đó T[i] = StartOf[p], tất nhiên)

```C
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#define max 1000000
int n, m;
int *a = new int [max], *L = new int [max], *StartOf = new int [max], *T = new int [max];
void Enter()
{
	FILE *fi = NULL;
	fi = fopen("INCSEQ.inp","r");
	fscanf(fi,"%d", &n);
	for (int i = 1; i <= n; i++)
		fscanf(fi, "%d", &a[i]);
	fclose(fi);
}
void init()
{
	a[0] = INT_MIN;
	a[n + 1] = INT_MAX;
	m = 1;
	L[n + 1] = 1;
	StartOf[1] = n + 1;
}
int find(int i)
{
	int inf = 1, sup = m + 1;
	do
	{
		int median = (inf + sup) / 2;
		int j = StartOf[median];
		if (a[j] > a[i])
			inf = median;
		else
			sup = median;
	} while (inf + 1 != sup);
	return StartOf[inf];
}
void Optimize()
{
	for (int i = n; i > -1; i--)
	{
		int j = find(i);
		int k = L[j] + 1;
		if (k > m)
			{
				m = k;
				StartOf[k] = i;
			}
		else
			{
				if (a[StartOf[k]] < a[i])
					StartOf[k] = i;
			};
		L[i] = k;
		T[i] = j;
	}
}
void PrintRes()
{
	FILE *fo = NULL;
	fo = fopen("INCSEQ.out","w");
	fprintf(fo,"%d\n", m - 2);
	int i = T[0];
	while (i != n + 1)
		{
			fprintf(fo,"a[%d] = %d\n",i, a[i]);
			i = T[i];
		}
	fclose(fo);
}
int main()
{
	Enter();
	init();
	Optimize();
	PrintRes();
	delete[] a;
	delete[] L;
	delete[] T;
	delete[] StartOf;
}
```

- Dễ thấy chi phí thời gian thực hiện thuật giải nay cấp O(nlogn), đây là một ví dụ điển hình cho thấy rằng một cong thức truy hồi có thể có nhiều phương pháp tính.

<a name="caitui"> </a>

###3.3.2 Bài toán cái túi:

- Trong siêu thị có n gói hàng (n <= 100), gói hàng thứ i có trọng lượng là W[i] <= 100 và giá trị V[i] <= 100. Một tên trọm đột nhập và siêu thị, tên trộm mang theo một cái túi có thể mang được tối đa trọng lượng M (M <= 100). Hỏi tên trọm sẽ lấy đi những gói hàng nào để được tổng giá trị lớn nhất
- **Input** file văn bảng BAG.inp

	- Dòng 1: Chứa hai số n, M cách nhau ít nhất một dấu cách
	- n dòng tiếp theo, dòng thứ i chứa hai số nguyên dương W[i], V[i] cách nhau ít nhất một dấu cách.

- **Output** file văn bản BAG.out

	- Dòng 1: Ghi giá trị lớn nhất tên trọm có thể lấy
	- Dòng 2: Ghi chỉ số những gói bị lấy

| BAG.inp | BAG.out |
|---------|---------|
|5 11 | 11 |
| 3 3 | 5 2 1 |
| 4 4 | |
| 9 10 | |
| 4 4 | |

- **Cách giải**

	- Nếu gọi F[i, j] là giá trị lớn nhất có thể có bằng cách chọn trong các gói {1, 2, ..., i} với giới hạn trọng lượng j. Thì giá trị lớn nhất khi được chọn trong số n gói với giới hạn trọng lượng M chính là F[n, M].

- **Công thức truy hồi tính F[i, j]: **

	- Với giới hạn trọng lượng j, việc chọn tối ưu trong số các gói {1, 2, ..., i - 1, i} để có giá trị lớn nhất sẽ có hai khả năng:

		- Nếu không chọn gói thứ i thì F[i, j] là giá trị lớn nhất có thể bằng cách chọn trong các số gói {1, 2, ..., i - 1} với giới hạn trọng lượng là j. Tức là: F[i, j] = F[i - 1, j]
		- Nếu có chọn gói thứ i (tất nhiên chỉ xét tới trường hợp này khi mà W[i] <= j) thì F[i, j] bằng giá trị gói thứ i là V[i] cộng với giá trị lớn nhất có thể có được bằng cách chọn trong số các gói {1, 2, ..., i - 1} với giới hạn trọng lượng j - W[i]. Tức là về mặt giá trị thu được: F[i, j] = V[i] + F[i - 1, j - W[i]]

	- Vì theo cách xây dựng F[i, j] là giá trị lớn nhất có thể, nên F[i, j] sẽ là max trong 2 giá trị thu được ở trên.

- **Cơ sở quy hoạch động:**

	- Dễ thấy F[0, j] = giá trị lớn nhất có thể bằng cách chọn trong số 0 gói = 0.

- **Tính bảng phương án:**

	- Bảng phương án F gồm n + 1 dòng. M + 1 cột, trước tiên được điền cơ sở quy hoạch động. Dòng 0 gồm toán số 0 sử dụng công thức truy hồi, dùng dòng 0 tính dòng 1, dùng dòng 1 tính dòng 2, v.v... đến khi tính hết dòng n.

<img src="http://i.imgur.com/h2XdAmc.jpg">

- **Truy vết**

	- Tính xong bảng phương án thì ta quan tâm đến F[n, M] đó chính là giá trị lớn nhất thu được khi chọn trong cả n gói với giới hạn trọng lượng M. Nếu F[n, M] = F[n - 1, M] thì tức là không chọn gói thứ n, nên ta truy tiếp F[n - 1, M]. Còn nếu F[n, M] != F[n - 1, M] thì ta thông báo rằng phép chọn tối ưu có chọn gói thứ n và truy tiếp F[n - 1, M - W[n]]. Cứ tiếp tục cho tới khi truy lên tới hàng 0 của bảng phương án.

```C
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <iostream>

using namespace std;

int n, M, W[100], V[100], F[100][100];

void Enter()
{
	FILE *fi = NULL;
	fi = fopen("BAG.inp","r");
	fscanf(fi,"%d %d", &n, &M);
	for (int i = 1; i <= n; i++)
		fscanf(fi,"%d %d", &W[i], &V[i]);
	fclose(fi);
}
void Optimize()
{
	memset(F[0], 0, sizeof(F[0]));
	for (int i = 1; i <= n; i++)
		for (int j = 0; j <= M; j++)
			{
				F[i][j] = F[i - 1][j];
				if ((j >= W[i]) && (F[i][j] < F[i - 1][j - W[i]] + V[i]))
					F[i][j] = F[i - 1][j - W[i]] + V[i];
			}
}
void Trace()
{
	FILE *fo = NULL;
	fo = fopen("BAG.out","w");
	fprintf(fo,"%d \n", F[n][M]);
	while (n != 0)
		{
			if (F[n][M] != F[n - 1][M])
				{
					fprintf(fo,"%d ", n);
					M = M - W[n];
				};
			n--;
		}
	fclose(fo);
}
int main()
{
	Enter();
	Optimize();
	Trace();
}
```

<a name="xcross87"> </a>

###4. Tư duy và rèn luyện code của Xcross87:

- Cũng như tất cả các thứ khác, coding cũng là một quá trình làm việc có trình tự kiểu như một bài văn, cần có dàn bài xây dựng ý, tạo khung, và viết thử lấp đầy ý cho văn vẻ; cuối cũng chắp ghép lại cho hợp ý mình.
- Ở bài này mình hướng dẫn các bạn cách tư duy và rèn luyện khi coding.
- Đề bài mẫu : Tính tổng 2 số nguyên và in ra màn hình kết quả
- **1. Tạo khung sườn ban đầu chương trình:**
- Đơn giản như bao bài tập , như hồi đầu mới yêu C 

```C
/* 1. Cần có thư viện chuẩn */
#include <stdio.h>

/* 2. Entry Point - Điểm bắt đầu chương trình */
int main(void)
{
      /* 3. Thân chương trình */
      return 0;
}
```

- Vậy là được cái sườn hơi chua 

- **2. Xác định yếu tố cần thiết**

- Cái này trong thân chương trình.
- Tính tổng : cần có 3 số và một toán tử '+'
- Cần ít nhất khai báo 2 biến, giả sử là a và b
- In ra màn hình : xài printf();
- Áp dụng

```C
#include <stdio.h>

int main(void)
{
         int a,b;
          
         a = 1;
         b = 2;
         printf(" Ket qua: %d + %d = %d ", a, b, a+b);
         return 0;
}
```

- **3. Mở rộng ra với yêu cầu người dùng nhập vào 2 số từ bàn phím:**
- Để lấy input sử dụng hàm scanf() 

```C
#include <stdio.h>

int main(void)
{
         int a,b;
          
         printf("Nhap a = ");scanf("%d",&a);
         printf("Nhap b = ");scanf("%d",&b);
         printf(" Ket qua: %d + %d = %d ", a, b, a+b);
         return 0;
}
```

- **4. Thêm một biến lưu trữ tổng đi:**

- Giả sử biến lưu tổng là s

```C
#include <stdio.h>

int main(void)
{
         int a,b;
         int s; 
         printf("Nhap a = ");scanf("%d",&a);
         printf("Nhap b = ");scanf("%d",&b);
         s = a + b;
         printf(" Ket qua: %d + %d = %d ", a, b, s);
         return 0;
}
```

- **5. Giờ cho nguyên cái đoạn xử lý vào một hàm:**

- Giả sử gọi hàm là: Sum()

```C
#include <stdio.h>

void Sum()
{
         int a,b;
         int s; 
         printf("Nhap a = ");scanf("%d",&a);
         printf("Nhap b = ");scanf("%d",&b);
         s = a + b;
         printf(" Ket qua: %d + %d = %d ", a, b, s);
}

int main(void)
{
         Sum(); 
         return 0;
}
```

- **6. Tạo hàm xử lý input cho đỡ đơn điệu:**

- Hàm Sum() nhận 2 tham số;

```C
#include <stdio.h>

void Sum(int x, int y)
{
        int s;
        s = x + y;
        printf("Ket qua: %d + %d = %d", x, y, s);
}
int main(void)
{
       int a,b;
       printf("Nhap a = ");scanf("%d",&a);
       printf("Nhap b = ");scanf("%d",&b);
       Sum();
       return 0;
}
```

- **7. Chia nhỏ cái nhập số:**

```C
#include <stdio.h>

int Input()
{
      int num;
      printf(" Nhap so : ");scanf("%d",&num);
      return num;
}

void Sum(int x, int y)
{
      int s = x + y;
      printf("Ket qua: %d + %d = %d ", x, y, s);
}

int main(void)
{
      int a,b;
      a = Input();
      b = Input();
      Sum();
      return 0;
}
```

- **8. Để hàm main chỉ có gọi sub-function thôi vậy:**

```C
#include <stdio.h>

int Input()
{
      int num;
      printf(" Nhap so : ");scanf("%d",&num);
      return num;
}

void Sum()
{
      int x, y, s;
      x = Input();
      y = Input();
      s = x + y;
      printf("Ket qua: %d + %d = %d ", x, y, s);
}

int main(void)
{      
      Sum();
      return 0;
}
```

- Nghe chừng gọn quá 

- **9. Giờ lấy input thông qua arg xem thế nào:**

```C
#include <stdio.h>

void Sum(int x, int y)
{
       int s = x + y;
       printf("Ket qua: %d + %d = %d ",x , y, s);
}

int main(int argc, char *argv[])
{
       if ( argc != 2 ) {
               printf(" Usage: sum.exe num1 num2 \n");
               printf(" Example: sum 3 4 \n");
               printf(" Result: Ket qua: 3 + 4 = 7");
               return -1;
       }
       
       Sum(argv[0],argv[1]);
       return 0;
}
```

- Vậy là có được một loạt sản phẩm rồi đó, chỉ cần chọn một cái ưng ý thôi.

- Tham khảo: [Hỏi đáp về C](http://diendan.congdongcviet.com/threads/t4169::danh-sach-cau-hoi-lap-trinh-c-hoi-tra-loi.cpp);
