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
	- [2.3 Truy nhập đến các thành phần của cấu trúc](#truycap)
	- [2.4 Thành phần kiểu FIELD (Nhóm BIT)](#field)
	- [2.5 Mảng cấu trúc](#mangcautruc)
	- [2.6 Khởi đầu cho một cấu trúc](#initstruct)
	- [2.7 Phép gán cấu trúc](#phepgancautruc)
	- [2.8 Con trỏ cấu trúc và địa chỉ cấu trúc](#controcautruc)
	- [2.9 Hàm trên các cấu trúc](#hamtrencautruc)

- [3. Cấp phát bộ nhớ động](#capphatbonho)
- [4. Cấu trúc tự trỏ và danh sách liên kết](#dslk)

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
3
- Biến kiểu enum: Biến kiểu enum thực chất là biến nguyên, nó được cấp phát 2 byte bộ nhớ và nó có thể nhận một giá trị nguyên bất kỳ. Mục đích chính của enum là tạo ra các macro, các kiểu và biến gợi nhớ. Ví dụ để làm việc với các ngày trong tuần ta có thể dùng kiểu week_day và biến day như sau:

	- `enum week_day {SUNDAY, MONDAY, TUESDAY, WEDSDAY, THURSDAY, FRIDAY, SATURDAY} day;

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

	- `struct nhan_cong, nguoi_a, nguoi_b;

- Sẽ cho ta hai cáu trúc với tên là nguoi_a và nguoi_b. Cả hai đều được xây dựng theo kieu nhan_cong

- Một cách tổng quát, việc khai báo cấu trúc được thực hiện theo mẫu:

- `struct tên_kiểu_cấu_trúc danh_sách_tên_cấu_trúc;
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
```

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

<a name ="truycap"> </a>

###2.3 Truy nhập đến các thành phần của cấu trúc

- Chúng ta đã khá quen biết việc sử dụng các biến, các phần sử tử mảng và tên mảng trong các câu lênh. Ta cũng đã biết các phần cơ của một cấu trúc là biến và mảng, nên một lẽ tự nhiên và cũng là một quy tắc cần ghi nhớ là việc xử lý một cấu trúc bao giờ cũng phải được thực hiện thông qua các thành phần cơ bản của nó. Để truy nhập tới một thành phần cơ bản (biến hoặc mảng) của một cấu trúc ta sử dụng một trong cách viết sau:

- **Mẫu 3.1**

	- `tên_cấu_trúc.tên_thành_phần`
	- `tên_cấu_trúc.tên_cấu_trúc.tên_thành_phần`
	- `tên_cấu_trúc.tên cấu trúc.tên_cấu_trúc.tên_thành_phần`
	- ...

- Các viết thứ nhất của mẫu 3.1 được sử dụng khi biến haowjc mảng là thnahf phần trực tiếp của một cấu trúc. Ví dụ biến ngay_thu, bién nam và mảng ten_thang là các thành phần trực tiếp của cấu trúc ngay_di (xem ví dụ 2.3). Mảng ten, mảng di_chi và biến bac_luong là các thành phần trực tiếp của cấu trúc  nguoi_b (xem ví dụ 2.4). Các cách viết còn lại của mẫu 3.1 được sử dụng khi biến hoặc mảng là thành phần trực tiếp của một cauá tryúc mà bản thân cấu trúc này lại là thành phần của một cấu trúc lớn hơn.

- *Ví dụ 3.1* Ta xét vài phép toán trên các thành phần của cấu trúc nguoi_a và nguoi_b (xem ví dụ 2.4).
- **Câu lệnh**

	-`printf("%s",nguoi_a.ten);`

- sẽ đưa tên của nguoi_a lên màn hình.
- Khi thực hiện câu lệnh:

	- s = nguoi_a.bac_luong + nguoi_b.bac_luong;

- Thì biến s sẽ nhận được tổng bậc lương của nguoi_a và nguoi_b;
- Câu lệnh

	-`printf("%d",nguoi_a.ngay_sinh.nam);`

- sẽ cho lên màn hình năm sinh của nguoi_a.
- Câu lệnh:

	-`printf("%d",nguoi_b.ngay_vao_co_quan.nam);`

- sẽ cho lên màn hình năm vào cơ qua của nguoi_b.
- **Chú ý 3.1** Có thể sử dụng phép toán lấy địa chỉ đối với thành phần cấu trúc để nhập số liệu trực tiếp vào thành phần cấu trúc. Ví dụ có thể viết:

	-`scanf("%d",&nguoi_b.ngay_vao_co_quan.nam);`

- Nhưng đối với các thnahf phần không nguyê, việc làm trên có thể dẫn đến treo máy. Ví vậy trước tiên nên nhập số liệu vào một biến trung gian, sau đó mới gán cho thành phần cấu trúc. Cách làm như sau:

```C
int x;
scanf("%d",&x);
nguoi_b.ngay_vao_co_quan.nam = x;
```
- **Chú ý 3.2** Để tránh dài dòng khi làm việc với các thành phần cấu trúc ta có thẻ dùng lệnh `#define`. Ví dụ câu lệnh scanf trong chú ý trên có thể viết theo cách sau:

```C
#define p nguoi_b.ngay_vao_co_quan
...
scanf("%d", &p.nam);
```

<a name="field"> </a>

###2.4 Thành phần kiểu FIELD (Nhóm BIT)

- Các thành phần nguyên (unsigned hoặc signed) với miền giá trị nhỏ (như tuổi biến thiên từ 1 đến 100) có thể khai báo kiểu nhóm bit theo mẫu sau:

```C
struct date
{
	int a:8;
	int b:6;
	int c:8;
	int d:2;
} x;
```

- Khi đó sizeof(struct date) = 3 (3 byte). Khi dùng kiểu field cần lưu ý các điểm sau:

- 1. Kiểu của field phải là int (unsigned haowjc signed).
- 2. Dộ dài của mỗi field không quá 16 bit.
- 3. Khi muốn bỏ qua một số bit thì ta bỏ trống tên trường.
- **Ví dụ** Khi viết

```C
int:8;
int:x;
```

- Tức là bỏ qua 8 bit thấp, x chiếm 8 bit cao của một word.
- 4. Không cho phép lấy địa chỉ thành phần kiểu field.
- 5. Không thể xây dựng các mảng kiểu field.
- 6. Không thể trả về từ hàm bằng một thành phần kiểu field.

- Chẳng hạn không cho phép viết:
	
	- `return x.d`;

- mà phải dùng thủ thật sau:

	- `int t = x.d;`
	- `return t;`

- Ứng dụng của nhóm bit: Nhóm bit thường được ứng dụng để:

	- Tiết kiệm bộ nhớ.
	- Dùng trong union để lấy ra các bit của một từ.

- Ví dụ:

```C
union{
	struct{
		unsigned a1;
		unsigned a2;
	} s;
	struct{
		unsigned n1:1;
		unsigned:15;
		unsigned n2:1;
		unsigned:7;
		unsigned n3:8;
	} f;
} u;
```
- Khi đó:

	- u.f.n1 là bit 0 ủa u.s.a1;
	- u.f.n2 là bit 0 của u.s.a2;
	- u.f.n3 là byte cao của u.s.a2;

<a name="mangcautruc"> </a>

###2.5 Mảng cấu trúc:

- Khi sử dụng một kiểu giá trị (kiểu int chẳng hạn) ta có thể khai báo các biến và các mảng kiểu int. Ví dụ khai báo:
- `int a,b,c[10];` cho ta hai biến nguyên a, b và mảng nguyên c.
- Hoàn toàn tương tự như vậy: Có thể sử dụng một kiểu cấu trúc đã mô tả để khai báo các cấu trúc và các mảng cấu trúc.

- **Ví dụ 5.1** : Giả sử kiểu cấu trúc nhan_cong đã định nghĩa trong 2.2, khi đó khai báo
- `struct nha_cong nguoi_a, nguoi_b, to_1[10], to_2[20];
- Sẽ cho:

	- Hai biến mảng cấu trúc nguoi_a và nguoi_b;
	- Hai mảng cấu trúc to_1 và to_2;

- Mảng to_1 có 10 phần tử và mảng to_2 có 20 phần tử. Mỗi phần tử của chúng là một cấu trúc kiểu nhan_cong.
- **Ví dụ 5.2** : Đoạn chương trình sau sẽ tính tổng lương của 10 nguoi ở to_1.

```C
double s=0;
for (i=0; i<10;++i)
	s+= to_1[i].bac_luong;
```

- **Ghi chú** : Không cho phép sử dụng phép toán lấy địa chỉ đối với các thành phần của mảng cấu trúc. Chảng hạn không cho phép viết:
- `&to_1[i].bac_luong` (nếu kiểu của bac_luong là nguyen thì được);

<a name="initstruct"> </a>

###2.6 Khởi đầu cho một cấu trúc

-  Có thể khởi đầu cho cấu trúc ngoài, cấu trúc tĩnh, mảng cấu trúc ngoài và mảng cấu trúc tĩnh bằng cách viết vào sau khai báo của chúng một danh sách các giá trị cho các thành phần.

- **Ví dụ 6.1** Đoạn chương trình

```C
struct date{
	int day; int month;
	int year;
	int yearday;
	char *month_name;
};

struct date dd = {4,7,1990,120,"December"};
```

- Xác định một cấu trúc (theo kiểu date) có tên là dd và khởi đầu cho các thành phần cảu nó. Như vậy: Nội dụng của dd.day là 4, của dd.month là 7, của dd.year là 1990, của dd.yearday là 120 và của dd.month_name là "December"
- Chú ý nếu month_name được khai báo kiểu ký tự như:
- `char moth_name[20];` thì các khởi đầu trên vẫn đúng.
- **Ví dụ 6.2** Đoạn chương trình

```C
struct month
{
	int number;
	char* name;
} year[12] = {
		{1,"january"},
		{2,"february"},
		...
		{12,"december"}
};
```

- Xác định và khởi đầu một mảng cấu trúc có tên là year bao gồm 12 phần tử. Vì mỗi phần tử của mảng lại là một cấu trúc (kiểu month) nên để khởi đầu cho mảng year, một cách hợp lý hơn cả là sử dụng 12 bộ khởi đầu cho 12 cấu trúc tương ứng.
- Chẳng hạn: `{1,"january"}` là bộ khởi đầu cho phần tử thứ nhất của mảng year.
- Cũng như đối với các mảng khác, khi khởi đầu một mảng cấu trúc ngoài (hoặc tĩnh) ta không cần chỉ ra kích cỡ của nó. Lúc đó kích cỡ của các mảng được khởi đầu sẽ được xác định một cách chính xác (khi dịch chương trình) thông qua số các bộ khởi đầu. Như vậy, đoạn chương trình trong ví dụ 6.2 có thể viết một cách khác như sau:

```C
struct month
{
	int number;
	char* name;
} year[] = {
		{1,"january"},
		{2,"febuary"},
		...
		{12,"december"}
	};
```

- Để xác định số phần tử của year ta có thể dùng toán tử sizeof theo cách sau:
- `int n = sizeof(year)/sizeof(struct month);`
- Nhận xét cuối cùng ở mục này là: Những gì đã nói về việc khởi đầu một mảng thông thường vẫn còn đúng đối với mảng cấu trúc, đó là:

	- Chỉ cho phép khởi đầu các cấu trúc và mảng cấu trúc ngoài (tĩnh). Chúng sẽ nhận giá trị 0 nếu không được khởi đầu.
	- Nếu kích thước của mảng cấu trúc cần khởi đầu đã được khai báo là n thì số bộ khởi đầu (m) cần không vượt quá n. Mỗi bộ khởi đầu cho giá trị của một phần tử mảng cấu trúc. Khi m < n thì chỉ có m phần tử đầu của mảng được khởi đầu, (n - m) phần tử còn lại nhận giá trị 0.
	- Việc khửoi đầu được thực hiện một lần khi dịch chương trình:

- Ví dụ khi dịch đoạn chương trình

```C
struct
	{
		float a;
		int b;
		char* c;
	}
d[10] = {
			{7.1,5,"alpha"},
			{-10.6,8,"beta"}	
		};
```

- Chỉ hai phần tử đầu mảng cấu trúc d được khởi đầu. Trong ví dụ này n = 10 và m = 2;

<a name="phepgancautruc"> </a>

###2.7 Phép gán cấu trúc:

- Có thể thục hiện phép gán trên ác biến và phần tử mảng cấu trúc cùng kiểu như sau:

	- 1. Gán hai biết (cấu trúc) cho nhau.
	- 2. Gán biến cho phần tử mảng (cấu trúc).
	- 3. Gán phần tử mảng cho biến.
	- 4. Gán hai phần tử mảng cho nhau.

- Mỗi phép gán nói trên tương đương với một dãy phép gán các thành phần tương ứng.
- Đoạn chương trình sau minh hoạ cách dùng phép gán cấu trúc để sắp xếp n thí sinh theo thứ tự giảm của tổng diểm.

```C
struct thi_sinh
{
	char ht[25]; /*họ tên*/
	float td; /*tổng điểm*/
} tg, ts[1000];
int i, j, n;
for (i = 1; i <= n - 1; ++i)
for (j = i + 1; j <= n; ++j)
	if (ts[i].td < ts[j].td)
	{
		tg = ts[i];
		ts[i] = ts[j];
		ts[j] = tg;
	}
```

<a name="controcautruc"> </a>

###2.8 Con trỏ cấu trúc và địa chỉ cấu trúc

####2.8.1 Con trỏ và địa chỉ:

- Xét các kiểu cấu trúc ngay va nhan_cong;

```C
struct ngay
{
	int ngay_thu;
	char ten_thang[10];
	int nam;
};
struct nhan_cong
{
	char ten[15];
	char dia_chi[20];
	double bac_luong;
	struct ngay ngay_sinh;
	struct ngay ngay_vao_co_quan;
};
```

- Khi đó con trỏ cấu trúc kiểu nhan_cong có tể được khai báo cùng với biến và mảng (cấu trúc) như sau:
- `struct nhan_cong *p, *p1, *p2, nc2, ds[100];`
- Trong khai trên thì:

	- p, p1 và p2 là con trỏ cấu trúc.
	- nc1 và nc 2 là biến cấu trúc.
	- ds là mảng cấu trúc.

- Con trỏ cấu trúc dùng để lưu trữ địa chỉ của biến cấu trúc và mảng cấu trúc, vì vậy các phép gán sau đây là hợp lệ:

	- p1 = &nc1; /*Gửi địa chỉ nc1 và p1 */
	- p2 = &ds[2]; /*Gửi địa chỉ ds[2] vào p2 */
	- p = ds; /*Gửi địa chỉ ds[0] vào p */

####2.8.2 Truy nhập thông qua con trỏ: Có thể truy nhập đến các phàn thông qua con trỏ theo một trong hai cách sau:

- *Cách 1:*
	
	-`tên_con_trỏ -> tên_thành_phần`;

- *Cách 2:*

	-`(tên_con_trỏ).tên_thành_phần`;

- Chẳng hạn, sau khi thự hiện các phép gán địa chỉ trong 8.1 thì các cách viết sau là tương đương:

	- nc1.ngay_sinh.nam và p1->ngay_sinh.nam
	- ds[2].ngay_sinh.ten_thang và (p2*).ngay_sinh.ten_thang;

- Chẳng hạn, sau khi thực hiẹn các phép gán địa chỉ trong 8.1 thì các cách viết sau là tương đương:

	- nc1.ngay_sinh.nam và p1-> ngay_sinh.nam
	- ds[2].ngay_sinh.ten_thang và (p2*).ngay_sinh.ten_thang;

####2.8.3 Dùng phép gán thông qua con trỏ.

- Giả thiết đã có các lệnh:

```C
p1=&nc1; /*Gửi địa chỉ nc1 vào p1 */
p2 = &ds[2]; /*Gửi địa chỉ ds[2] vào p2 */
```

- Khi đó trong các phép gán cấu trúc:

	- Có thể dùng *p1 thay cho nc1;
	- Có thể dùng *p2 thay cho ds[2];

- Như vậy cách viết: `ds[4] = nc1; ds[2] = nc2;`
- Tương đương với: `ds[4] = *p1; *p2 = nc2;

####2.8.4 Phép cộng địa chỉ:

- Sau phép gán:

```C
p = ds;
p2 = &ds[2];
```
- Thì p trỏ tới ds[0] và p2 trỏ tới ds[2]. Ta có thể dùng các phép cộng, trừ địa chỉ để làm cho p và p2 trỏ tới thành phần bất kỳ nào khác. Ví dụ sau các câu lệnh:

- `p = p + 10; p2 = p2 - 2;` thì p trỏ tới ds[10] còn p2 trỏ tới ds[0].

<a name="hamtrencautruc"> </a>

###2.9 Hàm trên các cấu trúc:

- Đối của hàm có thể là:

	- Biến cấu trúc: Khi đó tham số thực tương ứng là một giá trị cấu trúc.
	- Con trỏ cấu trúc: Khi đó tham số thực tương ứng là địa chỉ của biến cấu trúc.
	- Mảng cấu trúc hình thức hoặc con trỏ cấu trúc: Khi đó tham số thực tương ứng là tên mảng cấu trúc.

- Hàm có thể trả về giá trị:

	- Giá trị cấu trúc.
	- COn trỏ cấu trúc.

- Vd:

	- VD 9.1 : Xét kiểu cấu trúc person gồm 3 thành phần

		+ ht(họ tên) kiểu mảng char
		+ ns (năm sinh) kiểu struct date
		+ bl (bậc lương) kiểu float

- Ta dựa vào 6 hàm thao trên kiểu person.
- Hàm: `person *ptim(char *ht, person h[], int n);`
- => Có tác dụng tìm trong danh sách n nhân viên lưu trong mảng h, người có tên cho trong ht. Hàm trả về con trỏ tới người tìm được haowjc trả về NULL nếu không tìm thấy
- Hàm : `person tim(char *ht, person h[], int n);` => Cũng có tác dụng tìm kiếm như hàm trên, nhưng nó trả về một cấu trúc chứa thông tin người tìm được. Các thông tin này sẽ bằng không nếu không tìm thấy.
- Hàm: `void hv(person *p1, person *p2);` => dùng để hoán vị hai cấu trúc.
- Hàm: `void sapxep(person *p, int n);` => Có tác dụng sắp xếp n phần tử cấu trúc chứ trong p theo thứ tự tăng của năm sinh. Trong hàm sapxep có dùng tới hv.
- Hàm: `void vao(person *p);` => Dùng để nhập dữ liệu cho một đối tượng kiểu person. Một chú ý quan trọng là: Nếu trong hàm vao ta dùng câu lệnh `scanf("%f%*c",&h.bl);` để nhập trực tiếp vào thành phần h.bl thì bị treo máy.
- Hàm: `void in(person p);` => dùng để in một cấu trúc.
- Cách thức làm việc chương trình như sau: Đầu tiên là phần nhập số liệu, rồi đến sắp xếp, sau đó sẽ in danh sách nhân viên đã sắp xếp. Cuối cùng đến các mục tìm kiếm theo hàm ptim hàm tim.

<a name="capphatbonho"> </a>

###3. Cấp phát bộ nhớ động:

- Giả sử ta cần quản lý các viện. Mỗi viện có nhiều phòng và mỗi phòng có nhiều nhân viên. Khi thiết kế chương trình chúng ta chưa biết có bao nhiêu viện, chưa biết mỗi viện có bao nhiêu phòng và cũng chưa biết mỗi phòng có bao nhiêu nhân viên. Nếu sử dụng mảng (cấp phát bộ nhớ tĩnh), thì ta phải sử dụng số viện tối đa. Mỗi viện phải xem như có cùng một số phòng và mỗi phòng phải xem như có số nhân viên bằng nhau. Như vậy sẽ có rất nhiều vùng nhớ được cấp phát mà không bao giờ dùng đến. Chương trình dưới đây minh hoạ phương pháp cấp phát bộ nhớ động. Số viện sẽ đúng bằng số viện cần quản lý. Mỗi viện sẽ được cấp phát mọt vùng nhớ vừa đủ để chứa số phòng thực sự của nó và mỗi phòng cũng có một vùng nhớ ứng với số nhân viên hiện có của nó.
- Nhân viên được mô tả bằng cấu trúc person có 2 thành phần là ht(họ tên), và ns (năm sinh). Phòng được mô tả bởi cấu trúc ppp có 3 thành phần là tenphong (tên phòng), sonhanvien(số nhân viên trong phòng) và nhanvien (con trỏ kiểu person trỏ tới vùng nhớ chứa thông tin các nhân viên trong phòng). Viện được mô tả bằng cấu trúc vvv gồm 3 thành phần là tenvien (tên viện), sophong (số phòng của viện) và phong(con trỏ kiểu ppp trỏ tới vùng nhớ chứa thông tin của các phòng trong viện)

- Chương trình gồm hai phần:

	- Phần đầu gồm các thao tác nhập iệu và cấp phát bộ nhớ đặt xen kẽ nhau. Nhập kiệu để biến cần cấp phát bao nhiêu. Cấp phát để có vùng nhớ chứa thông tin nhập vào sau đó.
	- Phần tiếp theo đơn giản chỉ là in ra màn hinh các thông tin vừa nhập vào.

- Dưới đây là chương trình:

```C
#include "stdio.h"
#include "conio.h"
#include "alloc.h"
typedef struct
	{
		char ht[25]; /*ho ten*/
		int ns; /*nam sinh*/
	} person;
typedef struct
	{
		char tenphong[30];
		int sonhanvien;
		person *nhanvien;
	} ppp;
typedef struct
	{
		char tenvien[30];
		int sophong
		ppp *phong;
	} vvv;
vvv *vien;
int sovien;
main()
	{
		int i, j, k, ngay, thang, nam, sophong, sonhanvien, ns;
		/*Vao so lieu va cap phat bo nho, so vien*/
		clrscr();
		printf("\nSo vien: ");
		scanf("%d%*c",&sovien);
		vien = (vvv*) malloc ((sovien + 1) * sizeof(vvv));
		/* Vao so lieu tung vien */
		for (i = 1; i <= sovien; ++i)
		{
			printf("\nTen vien thu %d: ",i);
			gets(vien[i].tenvien);
			printf("\nSo phong cua vien %s: ", vien[i].tenvien);
			scanf("%d%*c",&sophong);
			vien[i].sophong = sophong;
			vien[i].phong = (ppp*) malloc ((sophong + 1) * sizeof(ppp))
			for (j = 1; j <= sophong; ++j)
				{
					printf("\n Ten phong %d cua vien %s: ", j, vien[i].tenvien);
					gets(vien[i].phong[j].tenphong);
					printf("\n So nhan vien cua phong %s vien %s: ", vien[i].phong[j].tenphong, vien[i].tenvien);
					scanf("%d%*c",&sonhanvien);
					vien[i].phong[j].sonhanvien = sonhanvien;
					printf("\n Vien %s Phong %s", vien[i].tenvien, vien[i].phong[j].tenphong);
					for (k = 1; k <= sonhanvien; ++k)
						{
							printf("\n Ho ten nhan vien %d: ", k);
							gets(vien[i].phong[j].nhanvien[k].ht);
							printf("\nNam sinh nhan vien %d: ", k);
							scanf("%d%*c",&ns); vien[i].phong[j].nhanvien[k].ns = ns;
						}
				}
		}
/*Dua ra man hinh */
clrscr();
for (i = 1; i <= sovien; ++i)
{
	printf("\n Vien %s co %d phong: ",vien[i].tenvien, vien[i].sophong);
	for (j = 1; j <= vien[i].sophong; ++j)
		{
			printf("\nPhong %s vien %s co %d nhan vien: ", vien[i].phong[j].tenphong, vien[i].tenvien, vien[i].phong[j].sonhanvien);
			for (k = 1; k <= vien[i].phong[j].sonhanvien; ++k)
				{
					printf("\nHo ten %s sinh nam %d", vien[i].phong[j].nhanvien[k].ht, vien[i].phong[j].nhanvien[k].ns);
				}
		}
}
getch();
}
```
<a name ="dslk"> </a>

###4. Cấu trúc tự trỏ và danh sách liên kết

- Cấu trúc có ít nhất một thành viên là con trỏ kiểu cấu trúc đang định nghĩa gọi là cấu trúc tự trỏ. Dưới đây trình bầy 3 cách định nghĩa cấu trúc tự trỏ person
- *Cách 1:*

```C
typedef struct pp
{
	char ht[25]; /*ho ten*/
	char qq[20]; /*que quan*/
	int tuoi;
	struct pp *tiep;
} person;
```

- *Cách 2:*

```C
typedef struct pp person;
struct pp
{
	char ht[25];
	char qq[20];
	int tuoi;
	person *tiep;
};
```

- *Cách 3:*

```C
struct pp
{
	char ht[25];
	char qq[20];
	int tuoi;
	struct pp *tiep;
};
typedef pp person;
```

- Cách trúc tự trỏ được dùng để xây dựng danh sach liên kết (móc nối), đó là một nhóm các cấu trúc có tính chất sau:

	- Biết địa chỉ cấu trúc đầu đang được lưu trữ trong một con trỏ nào đó (giả sử pdau).
	- Trong mỗi cấu trúc (trừ cấu trúc cuối) chứa đại chỉ của cấu trúc tiếp theo của danh sách.
	- Cấu trúc cuối chứa hằng NULL.

- Danh sách có 3 tính chất trên gọi là danh sách móc nối theo chiều thuận. Với danh sách này, ta có thể lần lượt truy nhập từ cấu trúc đầu tới cấu trúc cuối theo chiều từ trên xuống dưới.
- Tương tự, danh sách liên kết theo chiều ngược cũng có 3 tính chất trên nhưng theo chiều ngược lại:

	- Biết địa chỉ cấu trúc cuối.
	- Trong mỗi cấu trúc (trừ cấu trúc đầu) chứa địa chỉ của cấu trúc trước.
	-  Cấu trúc đầu chứa hằng Null

- Với danh sách này, ta có thể lần lượt truy nhập từ cấu trúc cuối tới cấu trúc đầu theo chiều từ dưới lên trên.
- Ngoài ra có thể xây dựng các danh sách mà mỗi phần tử chứa hai địa chỉ: Địa chỉ cấu trúc trước và địa chỉ cấu trúc sau. Với loại danh sách này, ta có thể truy nhập từ trên xuống dưới theo chiều thuận haowjc từ dưới lên trên theo chiều ngược.
- Dưới đây là 2 chương trình minh hoạ cách dùng danh sách móc nói.
- Chương trình 1 gồm các phần:
	
	- Nhập một số người và chứa vào bộ nhớ dưới dạng danh sách móc nối thuận (lập danh sách mới).
	- In danh sách móc nói ra màn hình
	- Tìm kiếm trên danh sách móc nối
	- Xoá một người khỏi danh sách
	- Bổ sung vào cuối danh sách
	- Chèn một người vào giữa danh sách

- Trước khi xem chương trình, hãy tìm hiểu các thủ thuật làm việc trên danh sách mốc nối

	- Để tạo danh sách mới cần thực hiện các khâu sau:

		- Cấp phát bộ nhớ cho một cấu trúc.
		- Nhập một người vào vùng nhớ vừa cấp
		- Gán địa chỉ người sau cho thành phần con trỏ của người trước.

	- Để duyệt qua tất cả các phần tử của một danh sách ta thường dùng con trỏ p chứa địa chỉ cấu trúc đang xét.

		- Đầu tiên cho p = dau
		- Để chuyển đến người tiếp theo ta dùng phép gán: `p = p -> tiep;`
		- Dấu hiệu để biết đang xét người cuối là: `p -> tiep == Null``

	- Để loại một người khỏi danh sách cần:

		- Lưu trữ địa chỉ người cần loại vào một con trỏ (dùng để giải phóng bộ nhớ của người cần loại)
		- Sửa đề người trước đó có địa chỉ của người đứng sau mà ta định loại
		- Giải phóng bộ nhớ của người cần loại

	- Để bổ sung (hoặc chèn) cần

		- Cấp phát bộ nhớ và nhập bổ sung
		- Sửa thành phần con trỏ trong các cấu trúc có iên quan để đảm bảo mỗi người chứa địa chỉ người tiếp theo.

- Chương trình dưới đây sẽ minh hoạ các kỹ thuật nói trên. Ngoài ra chúng ta còn thấy phương pháp cấp phát bộ nhớ và các cách truy nhập tới thành phần cấu trúc thông qua con trỏ.

```C
#include <stdio.h>
#include <alloc.h>
#include <conio.h>
#include <string.h>
typedef struct pp
	{
		char ht[25] /*ho ten*/
		char qq[20] /*que quan*/
		int tuoi;
		struct pp *tiep;
	} person;
int main()
{
	int t;
	char ht[25].qq[20];
	person *pdau, *p, *pl;
	clrscr();
	/*
	Vao mot so nguoi va luu tru trong bo nho duoi dang mot danh sach lien ket */
	pdau = NULL;
	while (1)
		{
			printf("\nHo ten (bam enter ket thuoc vao so lieu): ");
			gets(ht);
			if (ht[0] == 0)
				break;
			if (pdau == NULL)
				{
					pdau = (person*) malloc(sizeof(person));
					p = pdau;
				}
			else
				{
					p -> tiep = (person*)malloc(sizeof(person));
					p = p -> tiep;
				}
			strcpy(p -> ht, ht);
			printf("\nQue quan: ");
			gets(p -> qq);
			printf("\nTuoi: ");
			scanf("%d%*c", &t);
			p -> tuoi = t;
			p -> tiep = NULL;
		}
	/*Dua danh sach lien ket ra man hinh biet con tro pdau tro toi dau danh sach*/
	p = pdau;
	while (p  != NULL)
		{
			printf("\nHo ten %-25s Que %-30s Tuoi %d, (*p).ht, (*p).qq, (*p).tuoi");
			p = p -> tiep;
		}
	/*Tim kiem theo que quan*/
	while (1)
		{
			printf("\nQue (bam enter ket thuc tim kiem): ");
			gets(qq);
			if (qq[0] == 0) break;
			/*duyet tu dau danh sach va in ra man hinh nhung nguoi tim duoc */
			p = pdau;
			while (p != NULL)
				{
					if (strcmp(p -> qq, qq) == 0)
						printf("\nHo ten %-25s Que %-30s Tuoi %d",(*p).ht, (*p).qq, (*p).tuoi);
					p = p -> tiep;
				}
		}
	printf("\nLoai phan tu dau danh sach");
	if (pdau != NuLL)
		{
			p = pdau;
			pdau = p -> tiep; /*pdau tro toi nguoi thu hai */
			free(p); /*giai phong vung nho cua nguoi dau */
		}
	printf("\nBo sung mot nguoi vao cuoi danh sach ");
	if (pdau == NULL) /*Danh sach rong*/
		{
			pdau = (person*)malloc(sizeof(person));
			p = pdau;
		}
	else
		{
			/*tim dai chi cuoi va dat vao p */
			p = pdau;
			while (p -> tiep != NULL)
				p = p -> tiep;
				/* cap phat vung nho va nhap bo sung */
			p -> tiep = (person*)malloc(sizeof(person));
			p = p -> tiep;
		}
	/*Nhap bo sung*/
	printf("\nHo ten: "); gets(p -> ht);
	printf("\nQue quan: "); gets(p -> qq);
	printff("\nTuoi: ");
	scanf("%d%*c", &t);
	p -> tuoi = t;
	p -> tiep = NULL;
	printf("\nChen them vao truoc nguoi thu hai")
	/*Chen them mot nguoi vao truoc nguoi thu hai gia thiet co it nhat hai nguoi, truoc tien cap phat vung nho cho p de chua nguoi bo sung */
	p = (person*)malloc(sizeof(person));
	printf("\nHo ten: "); gets(p -> ht);
	printf("\nQue quan: "); gets(p -> qq);
	printf("\nTuoi: "); scanf("%d%*c", &t); p -> tuoi = t;
	/* ket noi */
	p1 = pdau -> tiep; /*p1 chua dia chi nguoi thu 2 */
	pdau -> tiep = p; /*sua de nguoi dau chua dia chi nguoi moi bo sung */
	p -> tiep  = p1; /*nguoi moi bo sung chua dia chi nguoi thu 2 trong danh sach cu*/
	/*Dua danh sach moi ra man hinh biet con tro pdau tro toi dau danh sach */
	p = pdau;
	while (p != NULL)
		{
			if (strcmp(p -> qq, qq) == 0)
				printf("\nHo ten %-25s Que %-30s Tuoi %d",(*p).ht, (*p).qq, (*p).tuoi);
			p = p -> tiep;
		}
}
```

- Chương trình 2 cũng nhập một số người và tạo thành một danh sách liên kết, nhưng phức tạp hơn chương trình 1 ở chỗ: Người vừa nhập được chèn vào vị trí thích hợp để danh sách được sắp theo chiều tăng của tuổi. Như vậy ta có quy trình để vừa nhập liệu vừa sắp xếp một cách đồng thời. Chương trình dùng hai hàm. Hàm `void vao_sl(char *ht, person **p);` dùng đẻ gán ht (họ tên) và p -> ht, gán NuLL cho p -> tiep và nhập quê quán gán cho p -> qq, nhập tuổi gán cho p -> tuoi. Hàm: `void bo_sung(person *pdau, person ng, person **pchen, int *vt);` dùng để xác định xem cấu trúc người cần chèn vào đâu. Nếu vt = 0 thì ng cần chèn vào đầu danh sách. Còn nếu vt = 1 thì ng cần chèn vào ngay sau phần tử được pchen trỏ tới.
- Chương trình 2 chẳng những minh hạo các thủ thuật làm việc trên danh sách móc nói mà còn cho nhữung ví dụ hay về việc dùng hàm có đuối con trỏ

```C
#include <stdio.h>
#include <alloc.h>
#include <conio.h>
#include <string.h>
typedef struct
	{
		char ht[25];
		char qq[20];
		int tuoi;
		struct pp *tiep;
	} person;
void bo_sung(person *pdau, person ng.person **pchen, int *vt);
/* y nghia ham bo_sung:
biet:
+pdau tro toi dau danh sach (gia thiet pdau != NULL);
+ ng la cau truc chua nguoi va nhap
Ham cho biet:
+ Neu vt = 0 chen vao dau danh sach
+ Neu vt = 1 chen vao sau cau truc do pchen tro toi */
void vao_sl(char *ht, person **p);
/* Ham vao_sl dung de:
+ Cap phat vung nho cho p
+ Gan ht vao p -> ht;
+ Vao cac so lieu khac nhu que quan va tuoi */
void bo_sung(person *pdau, person ng.person **pchen, int *vt);
{
	person *p = pdau, *p1;
	if(nguoi.tuoi < p -> tuoi)
		{
			*vt = 0;
			return;
		}
	else
		{
			while (1)
				{
					p1 = p -> tiep;
					if ((p1 = NULL) || (p1 != NULL && ng.tuoi < p1 -> tuoi))
					{
						*pchen = p;
						*vt = 1;
						return;
					}
				p = p1;
				}
		}
}
void vao_sl(char *ht, person **p)
{
	int t;
	person **p;
	pp = (person*)malloc(sizeof(person));
	strcpy(pp -> ht, ht);
	printf("\n Que quan: "); gets(pp -> qq);
	printf("\n Tuoi: "); scanf("%d%*c",&t);
	pp -> tuoi = t;
	p -> tiep = NuLL;
	*p = pp;
}
int main()
{
	int vt;
	char ht[25];
	person *pdau, *p, *ptg, *pchen;
	clrscr();
		/*Vao mot so nguoi va luu tru trong bo nho duoi dang mot danh sach lien ket */
	pdau = NuLL;
	while (1)
		{
			printf("\nHo ten (bam enter ket thuc vao so lieu): ");
			gets(ht);
			if (ht[0] == 0) break;
			if (pdau == NuLL) vao_sl(ht, &pdau);
			else
				{
					vao_sl(ht, &ptg);
					bo_sung(pdau, *ptg, &pchen, &vt);
					if (vt == 0) /*chen vao dau danh sach*/
						{
							ptg -> tiep = pdau; pdau = ptg;
						}
					else
						{
							/*chen vao sau pchen*/
							ptg -> tiep = pchen -> tiep;
							pchen -> tiep = ptg;
						}
				}
		}
	/*Dua danh sach lien ket ra man hinh biet con tro pdau tro toi dau danh sach */
	p = pdau;
	while (p != NuLL)
		{
			if (strcmp(p -> qq, qq) == 0)
				printf("\nHo ten %-25s Que %-30s Tuoi %d",(*p).ht, (*p).qq, (*p).tuoi);
			p = p -> tiep;
		}
	getch();
}
```
