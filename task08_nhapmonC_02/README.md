### Tìm hiểu về các câu lệnh lặp

> Tài liệu: Tìm hiểu về các câu lệnh lặp
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 21.10.2016

----

###Mục lục:

- [1. Cấu trúc rẻ nhánh không điều kiện](#kdk)
	
	- [1.1 Lệnh break](#break)
	- [1.2 Lệnh goto](#goto)
	- [1.3 Lệnh continue](#continue)

- [2. Vòng lặp For](#for)
- [3. Vòng lặp While](#whiledo)
- [4. Vòng lặp Do - while](#dowhile)
- [* Mở rộng](#morong)
- [5. Tiền xử lý #define](#define)

----

<a name="kdk"> </a>

###12 Cấu trúc rẻ nhánh không điều kiện:

<a name="break"> </a>

####1.1 Lệnh BREAK:

- Thông thường lệnh break dùng để thoát khỏi vòng lặp không xác định điều kiện dừng hoặc bạn muốn dừng vòng lặp theo điều kiện do bạn chỉ định Việc dùng lệnh break để thoát khỏi vòng lặp thường sử dụng phối hợp với lệnh if. Lệnh break dùng trong for, while, do…while, switch. Lệnh break thoát khỏi vòng lặp chứa nó.
- Trong bài trước chúng ta đã sử dụng lệnh break trong switch để nhảy bỏ các câu lệnh kế tiếp còn lại.

<a name="goto"> </a>

###1.2 Lệnh Goto:

- Một lệnh goto trong Ngôn ngữ chương trình C cung cấp một bước nhảy không điều kiện từ lệnh goto tới lệnh được gán nhãn trong cùng một hàm.

- Ghi chú: Sử dụng lệnh goto gây khó khăn cho bất kỳ ngôn ngữ chương trình nào bởi vì nó gây khó khăn cho việc theo dấu dòng điều khiển của một chương trình, làm cho chương trình khó để hiểu và khó để chỉnh sửa. Bất kỳ chương trình nào sử dụng một lệnh goto có thể được viết lại để có thể không cần lệnh goto này.

**Cú pháp:**

- Cú pháp cho một lệnh goto trong Ngôn ngữ C như sau:

```C
goto ten_nhan;
..
.
ten_nhan: lenh;
```
- Ở đây, **ten_nhan** (là tên nhãn) có thể là bất kỳ phần thuần văn bản nào ngoại trừ các từ khóa trong C, và nó có thể được thiết lập bất cứ đâu trong chương trình C, bên trên hoặc dưới lệnh goto này.

**Sơ đồ:**

<img src="http://i.imgur.com/Ol0lHNg.jpg">;

Ví dụ:

```C
#include <stdio.h>
 
int main ()
{
   /* phan dinh nghia bien cuc bo  */
   int a = 5;

   /* vong lap do...while */
   VIETJACK:do
   {
      if( a == 10)
      {
         /* nhay qua buoc lap nay */
         printf("Nhay qua buoc lap nay!\n");
         a = a + 1;
         goto VIETJACK;
      }
      printf("Gia tri cua a la: %d\n", a);
      a++;
     
   }while( a < 15 );
   printf("\n===========================\n");
   printf("VietJack chuc cac ban hoc tot! \n");
 
   return 0;
}
```

Biên dịch và thực thi chương trình C trên sẽ cho kết quả sau:

<img src="http://i.imgur.com/PnP3zuI.png">

- Lệnh goto kết hợp với lệnh if cũng có thể tạo ra một vòng lặp

```C
#include <stdio.h>
 
int main(){
    int a, kt;
    tieptuc : printf("Nhap a = ");
    scanf("%d", &a);
     
    switch(a) {
        case 1: printf("Mot"); break;
        case 2: printf("Hai"); break;
        case 3: printf("Ba"); break;
        case 4: printf("Bon"); break;
        case 5: printf("Nam"); break;
        default: printf("Khong phai so tu 1 den 5");
    }
     
    printf("\nBan muon tiep tuc? 1 de tiep tuc, 0 de dung: ");
    scanf("%d", &kt);
     
    if(kt) goto tieptuc;
     
    return 0;
}
```

**Tuy nhiên khi sử dụng lệnh goto bạn cần chú ý các điểm sau:**

-Nếu lệnh goto và nhãn nằm trong 1 hàm thì lệnh goto chỉ được phép nhảy trong hàm đó và không được phép nhảy sang hàm khác.
-Không được dùng lệnh goto nhảy từ ngoài vào trong một khối nhưng được phép nhảy từ trong khối ra ngoài.

<a name="continue"> </a>

###3.Lệnh continue

- Được dùng trong vòng lặp for, while, do…while. Khi lệnh continue thi hành quyền điều khiển sẽ trao qua cho biểu thức điều kiện của vòng lặp gần nhất. Nghĩa là lộn ngược lên đầu vòng lặp, tất cả những lệnh đi sau trong vòng lặp chứa continue sẽ bị bỏ qua không thi hành.

<a name="for"> </a>

###2. Vòng lặp for:

Vòng lặp xác định thực hiện lặp lại một số lần xác định của một (hoặc một chuỗi) hành động.

<img src="http://i.imgur.com/hVy7Nte.png">

- **Các biểu thức :**

	- Biểu thức 1: khởi tạo giá trị ban đầu cho biến điều khiển.
	- Biểu thức 2: là quan hệ logic thể hiện điều kiện tiếp tục vòng lặp.
	- Biểu thức 3: phép gán dùng thay đổi giá trịbiến điều khiển.

- **Cách hoạt động:**

	- Bước 1: Xác định giá trị của biểu thức 1
	- Bước 2: Xác định giá trị của biểu thức 2 (kiểm tra điều kiện đúng hay sai tức 1 hoặc 0). Tùy vào giá trị của biểu thức 2 mà thực hiện theo 2 hướng:
		+ Nếu sai (0) sẽ thoát khỏi vòng lặp
		+ Nếu đung (1) sẽ thực hiện khối lệnh trong vòng for đến khi gặp dấu } ở cuối vòng for hoặc lệnh continue thì sẽ tưới bước 3.
	- Bước 3: Tính giá trị biểu thức 3, sau đó quay lại bước 2.

*Lưu ý:*

- Biểu thức 1 bao giờ cũng chỉ được tính toán một lần khi gọi thực hiện for.
- Biểu thức 2, 3 và thân for có thể thực hiện lặp lại nhiều lần.
- Biểu thức 1, 2, 3 phải phân cách bằng dấu chấm phẩy ( ; ), các biểu thức có thể vắng mặt 1,2 hoặc cả 3 nhưng vẫn phải có dấy chấm phẩy này.
- Nếu biểu thức 2 không có, vòng for được xem là luôn luôn đúng. Muốn thoát khỏi vòng lặp for phải dùng một trong lệnh break, goto hoặc return.
- Với mỗi biểu thức có thể viết thành một dãy biểu thức con phân cách nhau bởi dấu phẩy. Khi đó các biểu thức con được xác định từ trái sang phải. Tính đúng sai của dãy biểu thức con trong biểu thức thứ 2 được xác định bởi biểu thức con cuối cùng.
- Trong thân for (khối lệnh) có thể chứa một hoặc nhiều cấu trúc điều khiển khác, vòng lặp khác.
- Khi gặp lệnh break, cấu trúc lặp sâu nhất sẽ thoát ra.
- Trong thân for có thể dùng lệnh goto để thoát khỏi vòng lặp đến vị trí mong muốn.
- Trong thân for có thể sử dụng return để trở về một hàm nào đó.
- Trong thân for có thể sử dụng lệnh continue để chuyển đến đầu vòng lặp (bỏ qua các câu lệnh còn lại trong thân).

**VD:**

VD1: Sử dụng vòng for in các số nguyên từ 1 đến 10

```C
#include <stdio.h>
 
int main(){
    int i;
    for (i = 1; i <= 10; i++) {
        printf("%-5d", i);
    }
     
    return 0;
}
```

VD2: Sử dụng vòng for in để đảo ngược mảng trong đó các biểu thức của vòng for là một dãy biểu thức con phân cách nhau bởi dấu phẩy.

```C
#include <stdio.h>
 
int main(){
    int i, j, n = 4, a[] = {1, 3, 7, 2}; // mang a gom 4 phan tu
     
    /* Xuat mang ban dau*/
     
    printf("Mang ban dau: ");
    for (i = 0; i < n; i++) {
        printf("%-5d",a[i]);
    }
    printf("\n");
     
    /* Dao nguoc mang*/
     
    for (i = 0, j = n - 1; i <= j; i++, j--) {
        // doi cho 2 phan tu a[i] va a[j]
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
    } 
     
    /* Xuat mang sau khi dao nguoc*/
     
    printf("Mang dao nguoc: ");
    for (i = 0; i < n; i++) {
        printf("%-5d",a[i]);
    }
    printf("\n");
     
    return 0;
}
```

VD3: Sử dụng vòng for in để đảo ngược mảng trong đó vắng mặt biểu thức 2, ta sử dụng lệnh break để thoát khỏi vòng lặp

```C
#include <stdio.h>
 
int main(){
    int i, j, n = 4, a[] = {1, 3, 7, 2}; // mang a gom 4 phan tu
     
    /* Xuat mang ban dau*/
     
    printf("Mang ban dau: ");
    for (i = 0; i < n; i++) {
        printf("%-5d",a[i]);
    }
    printf("\n");
     
    /* Dao nguoc mang*/
     
    for (i = 0, j = n - 1; ; i++, j--) {
        if (i >= j) break;
        // doi cho 2 phan tu a[i] va a[j]
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;    
    } 
     
    /* Xuat mang sau khi dao nguoc*/
     
    printf("Mang dao nguoc: ");
    for (i = 0; i < n; i++) {
        printf("%-5d",a[i]);
    }
    printf("\n");
     
    return 0;
}
```

VD4: Minh họa lệnh continue trong vòng for.

```C
#include <stdio.h>
 
int main(){
    int i, n = 4, a[] = {1, -3, -7, 2}; // mang a gom 4 phan tu
     
    printf("Cac so duong trong mang: ");
    for (i = 0; i < n; i++) {
        if (a[i] <= 0) continue;
        printf("%-5d",a[i]);
    }
     
    return 0;
}
```

<a name="whiledo"> </a>

###3. Vòng lặp While:

<img src="http://i.imgur.com/vpl4eHt.png">

- Ta có thể hiểu đơn giản: Trong khi biểu thức còn đúng thì làm lệnh, khi sai thì thoát

	- Biểu thức: có thể là một biểu thức hoặc nhiều biểu thức con. Nếu là nhiều biểu thức con thì cách nhau bởi dấu phẩy (,) và tính đúng sai của biểu thức được quyết định bởi biểu thức con cuối cùng.
	- Trong thân while (khối lệnh) có thể chứa một hoặc nhiều cấu trúc điều khiển khác.
	- Trong thân while có thể sử dụng lệnh continue đểchuyển đến đầu vòng lặp (bỏqua các câu lệnh còn lại trong thân).
	- Nếu biểu thức là một hằng khác không thì nó luôn đúng và vòng lặp diễn ra vô hạn. Muốn thoát khỏi vòng lặp while tùy ý có thể dùng các lệnh break, goto, return như với lệnh for.

- VD: Nhập mật khẩu:

```C
#include <stdio.h>
#define PASS "nguyenvanquan7826" // dat pass
 
int main(){
    char pass[100];
     
    /* Ham strcmp  tra ve ket qua la 0 khi 2 chuoi bang nhau  */
     
    while(strcmp(pass, PASS) != 0) { 
        printf("Nhap pass: ");
        gets(pass);
    }
     
    printf("Mat khau dung roi!");
     
    return 0;
}
```

<a name="dowhile"> </a>

###4. Vòng lặp do - while:

<img src="http://i.imgur.com/M1f76Ty.png">

```C
#include <stdio.h>
 
int main(){
    do {
        printf("khoi lenh duoc thuc hien\n");
    } while(5 > 8);
     
    return 0;
}
```
<a name="morong"> </a>

###Sự khác nhau cơ bản của For - While - Do While:

**For và While**

- For: Áp dụng cho vòng lặp với số lần thực hiện là nhất định (đã định sẫn)

- Vd: Nhập mảng số nguyên có 10 phần tử

```C
for (int i = 0; i < 10; i++)
	{
	scanf("%d", &a[i]);
	}
```

- While: Lặp với số lần không xác định

- Vd: In số đảo ngược của 1 số tự nhiên bất kỳ
 
```C
while (n)
	{
	tmp = n % 10;
	printf("%d", tmp);
	n /= 10
	}
```

=> Ta không thể dùng for cho vd số 2 được vì dữ liệu là 1 số nguyên bất kỳ, không biết nó có bao nhiêu chữ số

**Sự khác nhau giữa While và Do - while:**

- while : kiểm tra dk lặp trước khi làm
- do while: làm sau đó mới kiểm tra điều kiện lặp
=> vòng lặp do while luôn luôn được thực hiện ít nhất 1 lần, dù cho không thỏa mãn dk lặp

**VD thực tế**

- 1. xin trước cho phép rồi kiss(while)// cơ hội 50/50
- 2. kiss sau đó mới xin phép (do while)//hoàn thành được ước nguyện, nhưng hoàn toàn có thể để lại "di chứng"

###Sử dụng nhiều vòng lặp chồng lên nhau:

- Vấn đề đặt ra ở đây là khi nào thì ta nên sử dụng chồng các vòng lặp nhau? Ta xét 1 ví dụ đơn giản như sau:
	
- Nhập vào một ma trận vuông cấp 2

Ta sẽ có được 2 cách làm như sau: 
- Cách 1: Tiếp cận một cách thô sơ nhất như sau

```C
j = 0;
for (int i = 0; i < 2, i++)
	scanf("%d", &a[j][i]);
j = 1;
for (int i = 0; i < 2, i++)
	scanf("%d", &a[j][i]);
```

- Vậy với n = 6, 7 hoặc 8, v.v thì bạn phải dùng vô số vòng lặp for, chương trình vừa dài vừa khó đọc và nhận xét lỗi, bây giờ chúng ta sẽ tiếp cận với cách làm thứ 2:

```C
for (int i = 0; i < n, i++)
	for (int j = 0; j < n, j++)
		{
			scanf("%d", &a[i][j]);
		}
```
	
Phân tích:
	
- Ban đầu i = 0, j sẽ bắt đầu chạy từ 0 tới < n vậy là ta đã nhập được hàng thứ 1 trong ma trận tương ướng với a[0][0]; a[0][1];
- Tiếp đến i = 1, sẽ sẽ bắt đầu chạy từ 0 tới < n vậy là ta đã nhập được hàng thứ 2 trong ma trận a[1][0], a[1][1];

=> Từ đó ta thấy được cách 2 sẽ ngắn gọn hơn rất nhiều và dễ để chúng ta xem xét được chương trình

- Ta sẽ xét thêm 1 ví nữa về sự chồng vòng lặp vào nhau:

- Viết số đảo ngược của tất cả các chữ số trong mảng gồm 3 phần tử

Ta cũng sẽ có được 2 cách làm như sau:

- Cách 1: Tiếp cận thô sơ:

```C
while (a[0])
	{
		tmp = a[0] % 10;
		b[0] = b[0] * 10 + tmp;
		a[0] /= 10;
	}
while (a[1])
	{
		tmp = a[1] % 10;
		b[1] = b[1] * 10 + tmp;
		a[1] /= 10;
	}
while (a[2])
	{
		tmp = a[2] % 10;
		b[2] = b[2] * 10 + tmp;
		a[2] /= 10;
	}
```

- Cách 2 : Vậy nếu không phải là 3 mà là n nào đó ta sẽ làm thế nào ? Vì vậy ta sẽ có cách tiếp cận thứ 2 như sau:

```C
for (int i = 0, i < n, i++)
	{
		while (a[i])
			{
				tmp = a[i] % 10;
				b[i] = b[i] * 10 + tmp;
				a[i] = a[i] / 10
			}
	}
```

- Như vậy, ta đã có được 1 chương trình tổng quát hơn có thể chạy tới n số mà không phải code 1 cách dài dòng, sự chồng vòng lặp lên nhau sẽ hỗ trợ cho ta rất nhiều trong mảng xử lý hàng loạt công việc xảy ra 1 cách lần lượt, trong lúc làm việc này, thực hiện song song 1 việc kia.

<a name="define"> </a>

###5.Bộ tiền xử lý # define trong C++

**Dùng #define để định nghĩa hằng và kiểu**

- Một cách tổng quát thì từ khóa tiền xử lý `#define` đùng để định nghĩa tên của một kiểu (đối tượng) nào đó. Thực ra, câu lệnh #define chỉ là một loại câu lệnh macro. Có hai ứng dụng chính như sau:

*Định nghĩa tên hằng*

- Có thể dùng câu lệnh tiền xử lý #define để định nghĩa một hằng:

 `#define PI 3.14159           //định nghĩa tên một hằng số PI`
 `#define STANDARD "ANSI C"    //định nghĩa tên một hằng dãy kí tự `
 `#define ESC '\033'           //định nghĩa tên một hằng kí tự mã ASCII của phím Esc.`

- Lưu ý: so với cách định nghĩa dùng từ khóa const thì cách dùng này không được uyển chuyển bằng nhưng nó thường cho hiệu quả thực thi nhanh hơn vì đây chỉ là các macro.

*Định nghĩa tên của kiểu dữ liệu*

- Có thể dùng #define để định nghĩa tên của một kiểu dữ liệu:

 `#define real float  //định nghĩa tên kiẻu real cho dữ liệu có kiểu float`

- Việc khai báo các biến không có gì khác lạ ngoại trừ tên mới được dùng:

 `real x, y[3], *z;`

- Lưu ý: Việc sử dụng #define có thể có các hiệu ứng phụ không ngờ nếu dùng nó kết hợp với nhiều định tính và có thể dẫn đến những lỗi khó tìm khi viết mã:

 `#define STRING char *`

- Trong lúc định nghĩa biến người lập có thể muốn định nghĩa hai con trỏ char như sau:

 `STRING name, job;`

- Tuy nhiên, điều ước muốn sẽ không xảy ra vì #define là macro nên trình dịch sẽ diễn giải thành (nó chỉ thay thế tên STRING bằng char *):

 `char * name, job;`

- Và như vậy, người lập trình sẽ không nhận được hai biến con trỏ như dự tính mà chỉ có một biến name là con trỏ mà thôi.
