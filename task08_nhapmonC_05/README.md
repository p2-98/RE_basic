###Tìm hiểu về các thành phần cấu trúc trong C

> Tài liệu tham khảo: GTC PVA.
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 10.10.2016.

----

###Mục Lục

- [1. Kiểu enum](#enum)
- [2. Kiểu cấu trúc - Struct](#struct)

	- [2.1 Kiểu cấu trúc](#kieucautruc)
	- [2.2 Khai báo theo một kiểu cấu trúc đã định nghĩa](#khaibaovadinhnghia)

----

<a name="enum"> </a>

###1. Kiểu Enum:

- Câu lệnh `enum` có thể viết theo 4 dạng sau:

	- enum tk {pt1, pt2,...} tb1, tb2,...;
	- enum tk {pt1, pt2,...} ;
	- enum 	  {pt1, pt2,...} tb1, tb2,...;
	- enum 	  {pt1, pt2,...};

- Trong đó:
	
	- tk là tên kiểu enum (một kiểu dữ liệu mới)
	- pt1, pt2, ... là tên các phần tử,
	- tb1, tb2, ... là tên biến kiểu enum.

- **Tác dụng**:

- Câu lệnh thứ nhất có các chứng năng sau:

	- Định nghĩa các macro (như kiểu `#define`) pt1, pt2,... với các giá trị nguyên liên tiếp tính từ 0. Nói cục thể hơn: pt1 = 0, pt2 = 1,... chức năng này tương đương các câu lệnh `#define` sau:

		- #define pt1 0;
		- #define pt2 1;
		- ...
	
	- Định nghĩa kiểu enum có tên là tk, Sau này có thể dùng cụm ừ enum tk để khai báo các biến enum theo mẫu:

		- enum tk, x, y, z;
	
	- Khai báo các biến kiểu enum có tên là tb1, tb2,...

		- Câu lệnh thứ hai có các chức a và b.
		- Câu lệnh thứ ba các các chức a và c.
		- Câu lệnh thứ tư chỉ có chức a.

- Biến kiểu enum: Biến kiểu enum thực chất là biến nguyên, nó được cấp phát 2 byte bộ nhớ và nó có thể nhận một giá trị nguyên bất kỳ. Mục đích chính của enum là tạo ra các macro, các kiểu và biến gợi nhớ. Ví dụ để làm việc với các ngày trong tuần ta có thể dùng kiểu week_day và biến day như sau:

	- `enum week_day {SUNDAY, MONDAY, TUESDAY, WEDSDAY, THURSDAY, FRIDAY, SATURDAY} day;`

- Ví dụ: Chương trình sau minh hoạc các lệnh có thể dùng với các kiểu, các macro và các biến tạo bởi enum.
	
```C
#include <stdio.h>
int main()
{
	enum {T0, T1, T2};
	enum day {cn, t2, t3, t4, t5, t6, t7} n1;
	enum day n2;
	int i, j = 2000, K = T2;
	i = T7;
	n1 = -1000;
	n2 = j;
	printf("\n n1 = %d n2 = %d i = %d", n1, n2, i);
	printf("\nk = %d T1 = %d", k, T1);
}
```
<a name ="struct"> </a>

###2. Kiểu cấu trúc - Struct

- Để lưu trữ và xử lý thông tin trong máy tính ta có các biến và các mảng. Mỗi biến chứa một giá trị. Mảng có thẻ xem là tập hợp nhiều biến có cùng một kiểu giá trị và được biểu thị bằng một cái tên. Cấu trúc có thể xem như một sự mở rộng của các khái niệm biến và mảng, nó cho phép lưu trữ và xử lý các dạng thông tin phức tập hơn, Cấu trúc là một tập hợp các biến, các mảng và được biểu thị bởi một tên duy nhất. Khái niệm cấu trúc trong C có những nét tương tự như khái niệm bản ghi (record) trong Pascal hay Foxpro. Một ví dụ truyền thống về cấu trúc là phiếu ghi lương: Mỗi công nhân được miêu tả bởi một tập hợp các thuộc tính như tên, địa chỉ, ngày sinh, bật lương, ... Một vài trong thuộc này lại có thẻ là cấu trúc: Tên có thể có nhiều thành phần, địa chỉ và thậm chí ngày sinh cũng vậy.

<a name = "kieucautruc"> </a>

####2.1 Kiểu cấu trúc:

- Trước khi ây dựng một hoặc một số cấu trúc có cùng một kiểu ta cần phải mô tả kiểu của nó. Điuề này cũng tương tự như việc phải thiết kế một kiẻu nhà trước khi xây dựng những căn nhà thực sự ở các địa điểm khác nhau. Khi định nghĩa một cấu trúc cần chỉ ra : Tên của kiểu cấu trúc và các thành phàn của nó. Việc này được thực hiện theo mẫu sau:

- Mẫu 1:

```C
struct tên_kiểu_cấu_trúc
	{
		Khai báo các thàh phần của nó
	};
```

- Trong đó: struct là từ khoá, tên_kiểu_cấu_trúc là một tên bất kỳ do người lập trình tự đặt theo các tắc.
- Thnhà phần của cấu trúc có thể là: Biến, mảng, nhóm bit, hợp hoặc một cấu trúc khác mà kiểu của nó đã định nghĩa từ trước

- Ví dụ 1.1: Đoạn chương trình

```C
struct ngay
	{
		int ngay_thu;
		char ten_thang[10];
		int nam;
	}
```

- Mô tả một kiểu cấu trúc có tên là ngay gồ ba thành phần: biến nguyên ngay_thu, mang ten_thang và biến nam.

- Ví dụ 1.2 : Đoạn chương trình

```C
	strut nhan_cong
	{
		char ten[15];
		char dia_chi[20];
		double bac_luong;
		struct ngay ngay_sinh;
		struct ngay ngay_vao_co quan;
	};
  ```

- Thiết kết một kiểu cấu trúc có tên là nhan_cong gồm năm thành phần. Hai thành phần đầu là các mảng ten và dia_chi (kiểu char). Thành phần thứ ba là mọt biến kiểu double (biến bac_luong). Hai thành phần còn lại là các cấu trúc ngay_sinh à ngay_vao_co_quan, cả hai cấu trúc xây dựng theo kiểu cấu trúc ngay định nghĩa trong ví dụ 1.1
- **Chú ý 1.1:** Có thể dùng toán tử typedef để định nghĩa các kiểu cấu trúc ngay và nhan_cong ở trên như sau:

```C
typedef struct
	{
		int ngay_thu;
		char ten_thang[10];
		int nam;
	} ngay;
typedef struct
	{
		char ten[15]; char dia_chi[20];
		double bac_luong;
		ngay ngay_sinh;
		ngay ngay_vao_co_quan;
	} nhan_cong;
```

<a name ="khaibaovadinhnghia"> </a>

####2.2 Khai báo theo một kiểu cấu trúc đã định nghĩa:

- Việc làm này nhằm xây dựng những cấu trúc thự sự theo các kiểu đã thiết kế ở các phần trên. Về mặt ngữ pháp điều này hoàn toàn giống như việc khai báo các biến và các mảng. Khi kgai báo một biến cần chỉ ra kiểu và tên của nó.
- Ví dụ khai báo:
	
	- `float x, y`;

- Cho ta hai biến kiểu float với các tên là x và y. Ta cũng sẽ làm y hệt như vậy khi khai báo biến cấu trúc. Giả sử ta đã có ác kiểu cấu trúc ngay va nhan_cong như trong các ví dụ 1.1 và 1.2 khi đó ta có thể xét các ví dụ sau:

- *Ví dụ 2.1* : Khai báo
	
	- `struct ngay ngay_di, ngay_den;`

- Sẽ cho ta hai biến cấu trúc với tên là ngay_di và ngay_den. Cả hai đều được xây dựng theo kiểu ngay.

- *Ví dụ 2.2* : Khai báo

	- `struct nhan_cong, nguoi_a, nguoi_b;`

- Sẽ cho ta hai cáu trúc với tên là nguoi_a và nguoi_b. Cả hai đều được xây dựng theo kieu nhan_cong

- Một cách tổng quát, việc khai báo cấu trúc được thực hiện theo mẫu:

- `struct tên_kiểu_cấu_trúc danh_sách_tên_cấu_trúc;`
- Sau đây là một vài điều cần lưu ý:

	- *Nhận xét 2.1:* Các biến cấu trúc được khai báo theo mẫu trên sẽ được cấp phát bộ nhớ một cách đầy đủ cho tất cả các thành phàn của nó.
	- *Nhận xét 2.2:* Việc khai báo có thể thực hiện đồng thời với việc dịnh nghĩa kiểu cấu trúc. Muốn vậy chỉ cần đặt danh sách tên biến cấu trúc cần khai báo vào sau } cuối cùng trong mẫu 1.1

- Nói cách khác: Đề vừa thiết kế kiểu vừa khai báo các biến cấu trúc ta sử dụng mẫu sau:

- **Mẫu 2.2**
	
```C
struct ten_kiểu_cấu_trúc
{
	các thành phần cảu cấu trúc
} danh sách tên biến cấu trúc
```

- Ví dụ 2.3: Các cấu trúc ngay_di và ngay_den trong ví dụ 2.1 có thể được xây dựng theo cách:

```C
struct ngay
{
	int ngay_thu;
	char ten_thang[10];
	int nam;
} ngay_di, ngay_den;
```

- Ví dụ 2.4: Các cấu trúc nguoi_a, nguoi_b trong ví dụ 2.2 có thể xây dựng theo mẫu sau (giải sử kiểu ngay đẫ được mô tả như ở ví dụ 1.1)

```C
struct nhan_cong
{
	char ten[15];
	char dia_chi[20];
	double bac_luong;
	struct ngay ngay_sinhl
	struct ngay ngay_vao_co_quan;
} nguoi_a, nguoi_b;

- Nhận xét 2.3 : Khi vừa định nghĩa kiểu (cấu trúc) vừa khai báo cấu trúc như trong ví dụ 2.3 và 2.4 ta có thể không cần đến tên kiểu cấu trúc. Nói cách khác các cấu trúc có thể được khai báo theo mẫu sau.

- Mẫu 2.3 :

```C
struct
{
	các thành phần cảu cấu trúc
} danh sách tên cấu trúc;
```

- Ví dụ 2.5: Các cấu trúc ngay_di và ngay_den trong ví dụ 2.3 được khai báo theo cách:

```C
struct
{
	int ngay_thu;
	char ten_thang[10];
	int nam;
} ngay_di, ngay_den;
```

- Cũng cần nói thêm sự khác nhau giữa mẫu 2.2 và mẫu 2.3. Điều ngày sẽ trở nên hoàn toàn rõ ràng khi so sánh ví dụ 2.3 và ví dụ 2.5 ở ví dụ 2.3 ngoài việc xây dựng được cấcc cấu trúc ngay_di, ngay_den ta còn cho ra đời được kiểu cấu trúc ngay. Kieẻu ngay có thể sử dụng để khai báo ở các cấu trúc khác. Ỏ ví dụ 2.4 ta chỉ đặt được mục đích đầu của ví dụ 2.3.

- **Chú ý**: Nếu dùng typedef để định nghĩa kiểu cấu trúc, thì khi khai báo ta chỉ cần dùng tên kiểu (bỏ từ khoá struct). Ví dụ như kiểu cấu trúc ngay dược định như trong chú ý 1.1 của 2.1 thì các cấu trúc ngay_di và ngay_den trong ví dụ 2.1 có thể khai báo như sau:

- `ngay ngay_di, ngay_den;`

