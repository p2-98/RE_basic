###Nhập môn C

> Tài liệu tham khảo: [Tài liệu nhập môn](http://www.nguyenvanquan7826.com/2014/12/10/lap-trinh-c-bai-3-phep-toan-toan-tu-trong-c/#Co_lien_quan)
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 18.10.2016
>

----

###Mục lục:

- [1. Các toán tử trong C](#toantu)
	
	- [1.1 Toán tử toán học](#math)
	- [1.2 Toán tử quan hệ](#quanhe)
	- [1.3 Toán tử luận lý](#luanly)
	- [1.4 Toán tử tăng/ giảm](#tanggiam)
	- [1.5 Toán tử khởi tạo](#init)
	- [1.6 Toán tử điều kiện](#dieukien)
	- [1.7 Toán tử dấu phẩy](#phay)
	- [1.8 Toán tử lấy kích thước](#size)
	- [1.9 Độ ưu tiên của các toán tử](#douutien)

- [2. Mảng trong C](#array)
	
	- [2.1 Ví dụ mở đầu](#exstar)
	- [2.2 Mảng 1 chiều](#array1)
	- [2.3 Mảng 2 chiều](#array2)

- [3. Các hàm ra, vào dữ liệu](#inoutdata)
- [4. Cấu trúc rẻ nhánh](#renhanh)

	- [4.1 If - Else](#ifelse)
	- [4.2 Switch](#switch)

----

<a name="toantu"> </a>

###1. Các toán tử trong C:

<a name = "math"> </a>

####1.1 Toán tử toán học:

- C cung cấp 5 toán tử toán học cơ bản

#####Các toán tử toán học trong C

|STT | Toán tử | Tên | Ví dụ | Kết quả |
|----|---------|-----|-------|---------|
| 1 | + | Cộng | 4+12.6 | 16.6 |
| 2 | - | Trừ | 4-2.5 | 1.5 |
| 3 | * | Nhân | 4*2 | 8 |
| 4 | / | Chia | 6/3 | 2 |
| 5 | % | Lấy dư | 6%4 | 2 |

```C
#include <stdio.h>
 
int main(){
    int a = 5, b = 7;
    double c = 4.5, d = 6;
 
    printf("%d + %f = %f \n", a, c, a + c);
    printf("%d - %d = %d \n", a, b, a - b);
    printf("%d * %f = %f \n", b, d, b * d);
 
    /* Luu y phep chia nhe*/
 
    printf("%d / %d = %d \n", b, a, b / a);
    printf("%f / %d = %f \n", c, a, c / a);
    printf("%f / %f = %f \n", c, d, c / d);
 
    printf("%d %% %d = %d \n", b, a, b % a);
 
    return 0;
}
```

**Kết quả**

> 5 + 4.500000 = 9.500000
>
> 5 – 7 = -2
>
> 7 * 6.000000 = 42.000000
>
> 7 / 5 = 1
>
> 4.500000 / 5 = 0.900000
>
> 4.500000 / 6.000000 = 0.750000
>
> 7 % 5 = 2

- Toán tử lấy phần dư (%) yêu cầu cả hai toán hạng là số nguyên. Nó trả về phần dư còn lại của phép chia. Ví dụ 7 % 5 được tính toán bằng cách chia số nguyên 7 cho 5 để được 1 và phần dư là 2; vì thế kết quả là 2.
- Thông thường, nếu cả hai toán hạng là số nguyên sau đó kết quả sẽ là một số nguyên. Tuy nhiên, một hoặc cả hai toán hạng là số thực thì sau đó kết quả sẽ là một số thực.
- Khi cả hai toán hạng của toán tử chia là số nguyên thì sau đó phép chia được thực hiện như là một phép chia số nguyên và không phải là phép chia thông thường mà chúng ta sử dụng. Phép chia số nguyên luôn cho kết quả là phần nguyên của thương. Ví dụ: 7 / 5 =1 chứ không phải 7 / 5 = 1.4. Để khắc phục lỗi này thì ta có thể chuyển một số hoặc cả 2 số sang kiểu thực rồi thực hiện phép chia. Cách chuyển kiểu (hay ép kiểu) ta như sau:
(kiểu cần chuyển) (biến).
- **Lưu ý** khi ép kiểu thế này thì kiểu của các biến ban đầu không thay đổi mà chỉ là giá trị tức thời (tại thời điểm đó thay đổi sang kiểu mới). Để lưu lại giá trị tức thời này bạn cần khai báo thêm một biến mới có kiểu cần chuyển và gán giá trị đó lại. Ví dụ cho dễ.

```C
#include <stdio.h>
 
int main(){
    int a = 5, b = 7;
    double c;
 
    printf("%d / %d = %d \n", b, a, b / a);
 
    /* Chuyen gia tri tuc thoi cua b sang kieu so thuc*/
    printf("%d / %d = %f \n", b, a, (double)b / a);
 
    /* Chuyen gia tri tuc thoi cua a sang kieu so thuc*/
    printf("%d / %d = %f \n", b, a, b / (double)a);
 
    /* Neu lam the nay thi van khong dung, vi b/a duoc so nguyen
     * sau do chung ta moi ep kieu so nguyen do sang so thuc
     */
    printf("%d / %d = %f \n", b, a, (double)(b / a));
 
    return 0;
}
```
**Kết quả**

> 7 / 5 = 1
>
> 7 / 5 = 1.400000
>
> 7 / 5 = 1.400000
>
> 7 / 5 = 1.000000

<a name="quanhe"> </a>

####1.2 Toán tử quan hệ:

- C cung cấp 6 toán tử quan hệ để so sánh các số. Các toán tử quan hệ trả về1 (thay cho kết quả đúng) hoặc 0 (thay cho kết quả sai).

#####Các toán tử quan hệ trong C

| STT | Toán tử | Tên | Ví dụ | Kết quả |
|-----|---------|-----|-------|---------|
| 1 | == | So sánh bằng | 5 == 5 | 1 |
| 2 | != | So sánh khác | 5 != 5 | 0 |
| 3 | > | So sánh lớn hơn |	5 > 4 | 1 |
| 4 | < | So sánh nhỏ hơn |	5 < 4 |	0 |
| 5 | >= | So sánh lớn hơn hoặc bằng | 5 >= 4 | 1 |
| 6 | <= | So sánh nhỏ hơn hoặc bằng | 5 <= 5 |	1 |

- Chúng ta sử dụng các toán tử này để so sánh các giá trị, các ký tự,… tuy nhiên không so sánh các xâu với nhau vì điều này sẽ dẫn đến các địa chỉ của chuỗi được so sánh chứ không phải là nội dung chuỗi. Chúng ta có các hàm so sánh xâu ở thư viện string và sẽ tìm hiểu sau. Khi so sánh các ký tự với nhau thì bản chất ta có thể hiểu là máy so sánh các mã ASCII của các ký tự với nhau. VD. ‘A’ >’B’ sẽ trả về giá trị 0 vì ‘A’ có mã ASCII là 65 còn ‘B’ là 66.

<a name="luanly"> </a>

####1.3 Toán tử luận lý:

- C cung cấp ba toán tử luận lý cho việc kết nối các biểu thức luận lý. Giống như các toán tử quan hệ, các toán tử luận lý ước lượng tới 0 hoặc 1.

#####Các toán tử luận lý trong C:

| STT | Toán tử | Tên | Ví dụ | Kết quả |
|-----|---------|-----|-------|---------|
| 1 | ! | Phủ định | !5 | 0 |
| 2 | && | Phép và | 5 > 4 && 5 > 6 | 0 |
| 3 | `||` | Phép hoặc | 5 > 4 `||` 5 > 6 | 1 | 

<a name="tanggiam"> </a>

####1.4 Toán tử tăng, giảm:

- Các toán tử tăng một (++) và giảm một (- -) cung cấp các tiện lợi tương ứng cho việc cộng thêm 1 vào một biến số hay trừ đi 1 từ một biến số. Ví dụ với khai báo int i = 5, k;

#####Các toán tử luận lý trong C

| Toán tử | Tên | Ví dụ | Kết quả k | Kết quả i |
|---------|-----|-------|-----------|-----------|
| ++ | Tăng 1 (tiền tố) | k = ++i | 6 | 6 |
| ++ | Tăng 1 (hậu tố) | k = i++ | 5 | 6 |
| - - | Giảm 1 (tiền tố) | k = – -i | 4 | 4 |
| - - |	GIảm 1 (hậu tố) | k = i- - | 5 | 4 |

- Tức là ta có:
++i thì i được tăng trước sau đó sẽ lấy kết quả để thực hiện biểu thức
i++ thì i được đưa vào thực hiện biểu thức trước sau đó mới tăng i lên 1

<a name ="init"> </a>

####1.5 Toán tử khởi tạo:

- Toán tử khởi tạo được sử dụng để lưu trữ một biến. Toán hạng trái nên là một giá trị trái và toán hạng phải có thể là một biểu thức bất kỳ. Biểu thức được tính và kết quả được lưu trữ trong vị trí được chỉ định bởi giá trị trái.

#####Các toán tử khởi tạo trong C

| Toán tử | Ví dụ | Tương đương với |
|---------|-------|-----------------|
| = | x = 5 | Gán 5 cho x |
| += | x += 5 | x = x + 5 |
| -= | x -= 5 | x = x – 5 |
| *= | x *= 5 | x = x * 5 |
| /= | x /= 5 |	x = x / 5 |
| %= | x %= 5 | x = x % 5 |

- Phép toán khởi tạo chính nó là một biểu thức mà giá trị của nó là giá trị được lưu trong toán hạng trái của nó. Vì thế một phép toán khởi tạo có thể được sử dụng như là toán hạng phải của một phép toán khởi tạo khác. Bất kỳ số lượng khởi tạo nào có thể được kết nối theo cách này để hình thành một biểu thức. 

<a name ="dieukien"> </a>

####1.6 Toán tử điều kiện :

- Toán tử điều kiện yêu cầu 3 toán hạng. Hình thức chung của nó là:

> toán hạng 1? toán hạng 2: toán hạng 3

Toán hạng đầu tiên được ước lượng và được xem như là một điều kiện. Nếu kết quả không là 0 thì toán hạng 2 được ước lượng và giá trịcủa nó là kết quả sau cùng. Ngược lại, toánhạng 3 được ước lượng và giá trị của nó là kết quả sau cùng. Ví dụ:

```C
int m = 1, n = 2;
int min = (m < n? m :n); // min nhận giá trị 1
```

**Chú ý** rằng trong các toán hạng thứ 2 và toán hạng thứ 3 của toán tử điều kiện thì chỉcó một toán hạng được thực hiện. Điều này là quan trọng khi một hoặc cả hai chứa hiệu ứng phụ (nghĩa là, việc ước lượng của chúng làm chuyển đổi giá trịcủa biến). Ví dụ, với m = 1 và n = 2 thì trong:

```C
int min = (m < n ? m++ : n++);
```

- m được tăng lên bởi vì m++ được ước lượng nhưng n không tăng vì n++ không được ước lượng. Bởi vì chính phép toán điều kiện cũng là một biểu thức nên nó có thể được sử dụng như một toán hạng của phép toán điều kiện khác, có nghĩa là các biểu thức điều kiện có thể được lồng nhau.

Ví dụ:

```C
int m = 1, n = 2, p =3;
int min = (m < n ? (m < p ? m: p) : (n < p ? n: p));
```

<a name="phay"> </a>

####1.7 Toán tử dấu phẩy:

- Nhiều biểu thức có thể được kết nối vào cùng một biểu thức sử dụng toán tử phẩy. Toán tử phẩy yêu cầu 2 toán hạng. Đầu tiên nó ước lượng toán hạng trái sau đó là toán hạng phải, và trả về giá trị của toán hạng phải như là kết quả sau cùng.
Ví dụ: 
```C
int m, t;
m = (t =2, t*5 + 10)
```

- Khi đó t =2 và m = 2*5+10 = 20.

- Ví dụ nữa để các bạn chạy và xem kêt quả.

```C
#include <stdio.h>
 
int main(){
    int a = 5, b = 7, c = 8, d = 11, min;
    min = (a < b ? (c++, a) : (d--, b));
     
    printf("min = %d\nc = %d\nd = %d\n", min, c, d);
     
    return 0;
}
```

Kết quả:

> min = 5
>
> c = 9
>
> d = 11

<a name="size"> </a>

####1.8 Toán tử lấy kích thước:

- C cung cấp toán tử hữu dụng, sizeof, để tính toán kích thước của bất kỳ hạng mục dữ liệu hay kiểu dữ liệu nào. Nó yêu cầu một toán hạng duy nhất có thể là tên kiểu (ví dụ, int) hay một biểu thức (ví dụ, 100) và trả về kích thước của những thực thể đã chỉ định theo byte. Chạy thử ví dụ nhá.

```C
#include <stdio.h>
 
int main(){
     
    printf("char size = %d byte\n", sizeof(char));
    printf("short size = %d byte\n", sizeof(short));
    printf("int size = %d byte\n", sizeof(int));
    printf("long size = %d byte\n", sizeof(long));
    printf("float size = %d byte\n", sizeof(float));
    printf("double size = %d byte\n", sizeof(double));
    printf("1.55 size = %d byte\n", sizeof(1.55));
    printf("\"Hello\" size = %d byte\n", sizeof("Hello"));
    return 0;
}
```

Kết quả:

>char size = 1 byte
>
>short size = 2 byte
>
> int size = 4 byte
>
> long size = 4 byte
>
> float size = 4 byte
>
> double size = 8 byte
>
> 1.55 size = 8 byte
>
> “Hello” size = 6 byte

<a name="douutien"> </a>

####1.9 Độ ưu tiên các toán tử:

- Thứ tự mà các toán tử được ước lượng trong một biểu thức là rất quan trọng và được xác định theo các luật ưu tiên. Các luật này chia các toán tử C ra thành một số mức độ ưu tiên. Các toán tử ởmức cao hơn sẽ có độ ưu tiên cao hơn các toán tử có độ ưu tiên thấp hơn.

<img src="http://i.imgur.com/eBX4ZzN.png">

<a name ="array"> </a>

###2. Mảng trong C:

<a name ="exstar"> </a>

####2.1 Ví dụ mở đầu:

- Xét ví dụ nhập 5 số nguyên, xuất ra màn hình 5 số và tính tổng 5 số đó.

```C
#include <stdio.h>
 
int main() {
    int a, b, c, d, e; // 5 bien
     
    printf("Nhap a = ");
    scanf("%d", &a);
     
    printf("Nhap b = ");
    scanf("%d", &b);
     
    printf("Nhap c = ");
    scanf("%d", &c);
     
    printf("Nhap d = ");
    scanf("%d", &d);
     
    printf("Nhap e = ");
    scanf("%d", &e);
 
    int tong  = a + b + c + d + e;
    printf("Tong cua %d + %d + %d + %d + %d = %d", a, b, c, d, e, tong);
     
    return 0;
}
```

- Như ví dụ ta thấy nhập hết 5 số và xuất chúng ta màn hình có vẻ rất vất vả và ta đã phải sử dụng quá nhiều biến, nếu số biến của chúng ta không phải là 5 mà là 50, 500,… thì việc này quả là rất khó khăn. Để khắc phục điều này chúng ta hãy sử dụng kiểu mảng.
- Mảng Là tập hợp các phần tử có cùng kiểu dữ liệu. Mảng có mảng 1 chiều, 2 chiều,… và mỗi kiểu dữ liệu thì có 1 kiểu mảng tương ứng (mảng nguyên, mảng thực, mảng ký tự (chuỗi)),… Ta chủ yếu xét về mảng 1 chiều và mảng 2 chiều.
- Bây giờ chúng ta sẽ giải quyết lại ví dụ trên bằng cách sử dụng mảng 1 chiều.

<a name="array1"> </a>

####2.2 Mảng 1 chiều:

**a. Cách khai báo mảng 1 chiều**

- `<kiểu dữ liệu> <tên mảng> <[số phần tử tối đa trong mảng]>;`

VD: int a[10]; mảng 1 chiều a gồm 10 phần tử thuộc kiểu nguyên. Sau khi khai báo ta có 1 mảng có dạng như sau:

<img src="http://i.imgur.com/tBpKAM1.png">;

**b. Cách truy xuất đến các phần tử trong mảng.**

- Sau khi mảng được khai báo, mỗi phần tử trong mảng đều có chỉ số để tham chiếu. Chỉ số bắt đầu từ 0 đến n-1 (với n là kích thước mảng). Trong ví dụ trên, ta khai báo mảng 10 phần tử thì chỉ số bắt đầu từ 0 đến 9.

- Và ta truy xuất qua cú pháp: <tên mảng><[chỉ số]>

<img src="http://i.imgur.com/U7p48AN.png">;

**c. Cách nhập và xuất các phần tử của mảng**

- Để nhập dữ liệu cho các phần tử trong mảng ta cần duyệt tới từng phần tử trong mảng và tiến hành nhập bằng một vòng for

```C
for (i = 0; i < n; i++) {
    printf("Nhap a[%d] = ", i);
    scanf("%d", &a[i]);
}
```

- Việc xuất các phần tử trong mảng cũng được tiến hành tương tự:

```C
for (i = 0; i < n; i++) {
    printf ("%d \t", a[i]);
}
```

- Ngoài ra chúng ta cũng có thể sử dụng các vòng lặp khác nhứ while, do while,…

**d. Nhập xuất mảng sử dụng hàm**

- Trong nhiều bài toán, chúng ta phải nhập nhiều mảng, và xuất nhiều lần, khi đó hãy đưa nhập xuất vào hàm cho dễ dùng.

```C
#include <stdio.h>
 
void nhapMang(int a[], int n) {
    int i;
    // thuc hien nhap tung phan tu mang
    for (i = 0; i < n; i++) {
        printf("Nhap a[%d] = ", i);
        scanf("%d", &a[i]);
    }
}
 
void xuatMang(int a[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf ("%d \t", a[i]);
    }
}
 
int main() {
    // khai bao mang a co n phan tu
    int n = 5;
    int a[n];
    nhapMang(a, n);
    xuatMang(a, n);
     
    return 0;
}
```

- Lưu ý: Một mảng có mối quan hệ với 1 con trỏ, mảng có thế coi như 1 con trỏ nên khi truyền mảng vào hàm thì các phần tử của mảng sẽ bị ảnh hưởng nếu có sự thay đổi nào trong mảng.

**e. Một vài lưu ý khác**

- Khởi tạo mảng: Chúng ta có thể khởi tạo mảng trong quá trình khai báo ngay. VD: float a [5] = {3.4, 5, 6, 7, 4,2}
- Với cách khởi tạo này nếu ta khởi tạo vượt quá 5 phần tử máy sẽ báo lỗi, nếu thiếu phần tử nào thì phần tử đó nhận giá trị là 0.

VD: float a [5] = {3.4, 5, 7} => a[4] = a[5] = 0.
VD: float a [5] = {3.4, 5, 7, 1, 2, 3} => máy báo lỗi.

- Ngoài ra chúng ta có cách khai báo và khởi tạo mảng chưa biết trước số lượng.

VD: int a[] = {3,6,2,5} => Mảng có 4 phần tử nhận giá trị tương ứng.
Hoặc: int a[]; => Thường sử dụng khi dùng mảng làm tham số hình thức trong hàm.

<a name="array2"> </a>

#####2.3 Mảng 2 chiều:

- Chúng ta có thể coi nó như một ma trận. Các tính chất, cách khai báo, nhập xuất,… cũng tương tự như mảng 1 chiều.
- Khai báo: <kiểu dữ liệu> <tên mảng> <[số hàng][số cột]>;

VD khai báo: int a[5][10]; //Mảng a gồm 5 hàng và 10 cột (mỗi hàng có 10 phần tử).

<img src="http://i.imgur.com/RsUEcnl.png">

```C
#include <stdio.h>
#define MAX 10
 
// nhap mang n hang, m cot
void nhapMang(int a[MAX][MAX], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("Nhap a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}
 
// xuat mang n hang, m cot
void xuatMang(int a[MAX][MAX], int n, int m) {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf ("%-3d", a[i][j]);
        }
        printf("\n"); // xuong dong khi het 1 dong
    }
}
 
int main() {
    // khai bao mang a co n phan tu
    int n = 2, m = 3;
    int a[MAX][MAX];
    nhapMang(a, n, m);
    xuatMang(a, n, m);
     
    return 0;
}
```

*Chú ý:* Thực chất trong bộ nhớ, các phần tử của mảng 2 chiều (và mảng nhiều chiều) được tổ chức như là nhiều mảng 1 chiều liên tiếp nhau, vì vậy ta có thể quy mảng 2 chiều thành mảng 1 chiều.

<img src="http://i.imgur.com/6DmEcjP.png">

<a name="inoutdata"> </a>

###3. Các hàm ra, vào dữ liệu:

- Trong phần này ta sẽ nói về chức năng nhập và xuất cơ bản. Nhập và xuất (I/O) luôn là các thành phần quan trọng của bất kỳ chương trình nào. Để tạo tính hữu ích, chương trình của bạn cần có khả năng nhập dữ liệu vào và hiển thị lại những kết quả của nó.
– Trong C, thư viện chuẩn cung cấp những thủ tục cho viêc nhập xuất. Thư viện chuẩn có những hàm quản lý các thao tác nhập/ xuất cũng như các thao tác trên ký tự và chuỗi. Trong bài học này, tất cả những hàm dùng để đọc dữ liệu vào từ thiết bị nhập chuẩn và tất cả những hàm xuất dùng để viết kết quả ra thiết bị xuất chuẩn. Thiết bị nhập chuẩn thông thường là bàn phím. Thiết bị xuất chuẩn thông thường là màn hình (console). Nhập và xuất ra có thể được định hướng đến tập tin hay từ tập tin thay vì thiết bị chuẩn. Những tập tin có thể được lưu trên đĩa hay trên bất cứ thiết bị lưu trữ nào khác. Dữ liệu đầu ra cũng có thể được gửi đến máy in.

*1.Tập tin tiêu đề `<stdio.h>`*

Code:

	```C
	#include <stdio.h>
	```

– Đây là lệnh tiền xử lý (**preprocessor command***). Trong C chuẩn, ký hiệu # nên đặt tại cột đầu tiên. stdio.h là một tập tin và được gọi là tập tin tiêu đề (header). Nó chứa các macro cho nhiều hàm nhập và xuất được dùng trong C. Hàm **printf()**, **scanf()**, **putchar()** và **getchar()** được thiết kế theo cách gọi các macro trong tập tin **stdio.h** để thực thi các công việc tương ứng.

*2.Nhập xuất trong C (input anh output)*

– Thư viện chuẩn trong C cung cấp hai hàm để thực hiện các yêu cầu nhập và xuất có đinh dạng. Chúng là:

Code:
	
	```C
	printf() - Hàm xuất có định dạng.
	scanf() – Hàm nhập có định dạng.
	```

– Những hàm này gọi là những hàm được định dạng vì chúng có thể đọc và in dữ liệu ra theo các định dạng khác nhau được điều khiển bởi người dùng. Bộ định dạng qui định dạng thức mà theo đó giá trị của biến sẽ được nhập vào và in ra.

*3.printf()*

– Cấu trúc câu lệnh:

Code:
	
	`printf(“control string”, argument list);`

– Trong đó control string bao gồm những ký tự văn bản và các lệnh định dạng. Các ký tự dấu trắng, phím tab và dấu xuống dòng không in được. Dưới đây bảng mã định dạng của printf(), quy ước in và các ký tự đặc biệt trong chuỗi điều khiển.

d,i :	Số nguyên có dấu
u :	Số nguyên không dấu
f :	Số thực
c :	Ký tự
s :	Chuỗi ký tự

– Bổ từ (modifier) cho các lệnh định dạng trong printf()
+ Bổ từ “–” : dữ liệu sẽ được canh trái bên trong không gian dành cho nó, chúng sẽ được in bắt đầu từ vị trí ngoài cùng bên trái.
+ Bổ từ xác định độ rộng : chúng có thể được dùng với kiểu: float, double hay char array (chuỗi-string). Bổ từ xác định độ rộng là một số nguyên xác định độ rộng nhỏ nhất của trường dữ liệu. Các trường dữ liệu có độ rộng nhỏ hơn sẽ cho canh phải trong kết quả của trường dữ liệu. Các dữ liệu có kích thước lớn hơn sẽ được in bằng cách thêm những vị trí cho đủ yêu cầu.
+ Bổ từ xác định độ chính xác : chúng có thể được dùng với kiểu float, double hay char array, string. Bổ từ xác định độ rộng chính xác được viết dưới dạng .m với m là một số nguyên. Nếu xử dụng với kiểu float và double, chuỗi số chỉ ra số con số tối đa có thể được in ra phía bên phải dấu chấm thập phân. Nếu phần phân số của các mục dữ liệu kiểu float hay double vượt quá độ rộng con số chỉ trong bổ từ, thì số đó sẽ được làm tròn. Nếu chiều dài chuỗi vượt quá chiều dài chỉ định thì chuỗi sẽ được cắt bỏ phần dư ra ở phía dưới. Một vài số “0” sẽ được thêm vào nếu số con số thực sự trong một mục dữ liệu ít hơn được chỉ định trong bổ từ. Tương tự, các khoảng trắng sẽ được thêm vào cho chuỗi ký tự.
-> Bổ từ “0” : Theo mặc định, việc thêm vào một trường được thực hiện với các khoảng trắng. Nếu người dùng muốn thêm vào trường với số không “0“, bổ từ này phải được dùng.
-> Bổ từ “1” : Bổ từ này có thể được dùng để hiển thị số nguyên như: long int hay một tham số kiểu double. Mã định dạng tương ứng cho nó là %ld
-> Bổ từ “h” : Bổ từ này được dùng để hiển thị kiểu short integer. Mã định dạng tương ứng cho nó là %hd.
-> Bổ từ “*” : Bổ từ này được dùng khi người dùng không muốn chỉ trước độ rộng của trường mà muốn chường trình xác định nó. Nhưng khi đi với bổ từ này, một tham số đựoc yêu cầu phải chỉ ra rộng trường cụ thể. Dưới đây là một vài ví dụ về bổ từ…

```C
/*Chuong trinh nay trinh bay cach dung bo tu trong printf()*/
#include <stdio.h>
void main()
{
printf(“The number 555 is various forms: \n”);
printf(“Without any modifier: \n”);
printf(“[%d] \n”, 555);
printf(“With – modifier: \n”);
printf(“[%-d] \n”, 555);
printf(“With digit string 10 as modifier: \n”);
printf(“[%10d] \n”, 555);
printf(“With 0 as modifier: \n”);
printf(“[%0d] \n”, 555);
printf(“With 0 and digit string 10 as modifiers: \n”);
printf(“[%010d] \n”, 555);
printf(“With -, 0 and digit string 10 as modifiers: \n”);
printf(“[%-010d] \n”, 555);
}
```
*VD2*

```C
/*Chuong trinh nay trinh bay cach dung bo tu trong printf()*/
#include <stdio.h>
void main()
{
printf(“The number 555.55 in various forms: \n”);
printf(“In float form without modifiers: \n”);
printf(“[%f] \n”, 555.55);
printf(“In exponential form without any modifier: \n”);
printf(“[%e] \n”, 555.55);
printf(“In float form with – modifier: \n”);
printf(“[%-f] \n”, 555.55);
printf(“In float form with digit string 10.3 as modifier \n”);
printf(“[%10.3f] \n”, 555.55);
printf(“In float form with 0 as modifier: \n”);
printf(“[%0f] \n”, 555.55);
printf(“In float form with 0 and digit string 10.3”);
printf(“as modifier: \n”);
printf(“[%010.3f] \n”, 555.55);
printf(“In float form with -, 0”);
printf(“and digit string 10.3 as modifiers: \n”);
printf(“[%-010.3f] \n”, 555.55);
printf(“In exponential form with 0”);
printf(“and digit string 10.3 as modifier: \n”);
printf(“[%010.3e] \n”, 555.55);
printf(“In exponential form with -, 0″);
printf(” and digit string 10.3 as modifiers: \n”);
printf(“[%-010.3e]  \n\n”, 555.55);
}
```

**4. scanf()**

– Hàm scanf() được sử dụng để nhập dữ liệu. Khuôn dạng chung của hàm scanf() như sau:

C Code:
	
	`scanf(“Chuỗi các định dạng”,”Danh sách các tham số”);`

– Định dạng được sử dụng bên trong câu lệnh printf() cũng được sử dụng cùng cú pháp trong các câu lệnh scanf(). Những lệnh định dạng, bao gồm bổ từ và danh sách tham số được bàn luận cho printf() thì cũng hợp lệ cho scanf(), chúng tuân theo một số đặc điểm sau:
+ Sự khác nhau trong danh sách tham số giữa printf() và scanf(): Hàm printf() dùng các tên biến, hằng số, hằng chuỗi và các biểu thức, nhưng scanf() sử dụng những con trỏ tới các biến. Một con trỏ tới một biến là một mục dữ liệu chức đựng địa chỉ của nơi mà biến được cất giữ trong bộ nhớ. Những con trỏ sẽ được bàn luận chi tiết ở chương sau. Khi sử dụng scanf() cần tuân theo những quy tắc cho danh sách tham số:
-> Nếu ta muốn nhập giá trị cho một biến có kiểu dữ liệu cơ bản, gõ và tên biến cùng với ký hiệu & trước nó.
-> Khi nhập giá trị cho một biến thuộc kiểu dữ liệu dẫn xuất (không phải thuộc bốn kiểu dữ liệu cơ bản char, int, float, double), không sử dụng & trước tên biến.
+ Sự khác nhau trong lệnh định dạng giữa printf() và scanf(): Không có tùy chọn %g. Mã định dạng %f và %e có cũng hiệu quả tác động. Cả hai nhận một ký hiệu tùy chọn, một chuỗi các con số có hay không có dấu chấm thập phân và một trường số mũ tùy chọn.
– Cách thức hoạt động của scanf(): nó sử dụng những ký tự không được in như ký tự khoảng trắng, ký tự phân cách (tab), ký tự xuống dòng để quyết định khi nào một trường nhập kết thúc và bắt đầu. Có sự tương ứng giữa lệnh định dạng với những trường trong danh sách tham số theo một thứ tự xác định, bỏ qua những ký tự khoảng trắng bên trong. Do đó, đầu vào có thể được trải ra hơn một dòng, miễn là chúng ta có it nhất một ký tự phân cách, khoảng trắng hay hàng mới giữa các trường nhập vào. Nó bỏ qua những khoảng trắng và ranh giới hàng để thu được dữ liệu.

Ví dụ 1:

```C
/*Chuong trinh mo ta viec dung ham scanf()*/
#include <stdio.h>
void main()
{
int a;
float d;
char ch, name[40];
printf(“Please enter the date \n”);
scanf(“%d %f %c %s”, &a, &d, &ch, name);
printf(“\nThe values accepted are: %d, %f, %c, %s”, a, d, ch, name);
}
```

Ví dụ 2:

```C
/*Chuong trinh mo ta viec dung ham scanf()*/
#include <stdio.h>

void main()
{
char line[80]; /*line[80] la mot mang luu 80 ky tu, mang chung ta se noi toi sau*/
scanf(“% [ABCDEFGHIJMNOPQRSTUVWXYZ]”, line);
}
```

**5. Bộ nhớ đệm nhập và xuất (Buffered I/O)**

– Ngôn ngữ C bản thân nó không định nghĩa các thao tác nhập và xuất. Tất cả thao tác nhập và xuất được thực hiện bởi các hàm có sẵn trong thư viện hàm của C. Thư viện hàm C chứa một hệ thống hàm riếng mà nó điều khiển các thao tác này. Đó là:
+ Bộ nhớ đệm Nhập và Xuất – được dùng để đọc và viết các ký tự ASCII
– Một vùng đệm là nơi lưu trữ tạm thời, nằm trên bộ nhớ máy tính hoặc trên thẻ nhớ của bộ điều khiển thiết bị (controller card). Các ký tự nhập vào từ bàn phím được đưa vào bộ nhớ và đợi đến khi người dùng nhấn phím return hay enter thì chúng sẽ được thu nhận như một khối và cung cấp cho chương trình. Bộ nhớ đệm nhập và xuất có thể được phân thành:
+ Thiết bị nhập/ xuất chuẩn (Console I/O
+ Tập tin đệm nhập/ xuất (Buffered File I/O)
– Các hàm đơn giản nhất của Thiết bị nhập/ xuất chuẩn là:

Code:

	`getchar() - Đọc một và chỉ một ký tự từ bàn phím.`
	`putchar() - Xuất một ký từ đơn ra màn hình.`

**6. getchar()**

– Hàm này được dùng để đọc dữ liệu nhập vào, chỉ một ký tự tại một thời điểm từ bàn phím. Trong hầu hết việc thực thi C, khi dùng getchar(), các ký tự nằm trong vùng đệm cho đến khi người dùng nhấn phím xuống dòng. Vì vậy nó sẽ đợi cho đến khi phím Enter được gõ. Hàm getchar() không có tham số, nhưng vấn phải có cặp dấu ngoặc đơn. Nó đơn giản lấy về ký tự tiếp theo và sẵn sàng đưa ra cho chương trình. Chúng ta nói rằng hàm này trả về một giá trị có kiểu ký tự.

Ví dụ

```C
/*Chuong trinh trinh bay cach dùng getchar()*/
#include <stdio.h>
void main()
{
char letter;
printf(“\nPlease enter my character: “);
letter = getchar();
printf(“\nThe character entered by you is %c. “, letter);
}
```

***7. putchar()***

– putchar() là hàm xuất ký tự trong C, nó sẽ xuất một ký tự lên màn hình tại vị trí con trỏ màn hình. Hàm này yêu cầu một tham số. 

Ví dụ

```C
/* Chuong trinh nay trinh bay viec su dung hang và dinh dang trong ham putchar() */
#include <stdio.h>
void main()
{
putchar(“H”); putchar(“\n”);
putchar(“\t”);
putchar(“E”); putchar(“\n”);
putchar(“\t”); putchar(“\t”);
putchar(“L”); putchar(“\n”);
putchar(“\t”); putchar(“\t”); putchar(“\t”);
putchar(“L”); putchar(“\n”);
putchar(“\t”); putchar(“\t”); putchar(“\t”);
putchar(“\t”);
putchar(“O”);
}
```

<a name ="renhanh"> </a>

###4. Cấu trúc rẻ nhánh trong C:

<a name="ifelse"> </a>

####4.1 If / Else :

- Cấu trúc rẽ nhánh là một cấu trúc được dùng rất phổ biến trong các ngôn ngữ lập trình nói chung. Trong C, có hai dạng: dạng không đầy đủ và dạng đầy đủ.

**Dạng không đầy đủ**

Cú pháp:

if (< Biểu thức điều kiện >)

<Công việc>

Lưu đồ cú pháp:

<img src="http://i.imgur.com/nkcL9vr.png">

*Giải thích:*

- <Công việc> được thể hiện bằng 1 câu lệnh hay 1 khối lệnh.
- Kiểm tra Biểu thức điều kiện trước.
- Nếu điều kiện đúng (!= 0) thì thực hiện câu lệnh hoặc khối lệnh liền sau điều kiện.
- Nếu điều kiện sai thì bỏ qua lệnh hoặc khối lệnh liền sau điều kiện (những lệnh và khối lệnh sau đó vẫn được thực hiện bình thường vì nó không phụ thuộc vào điều kiện sau if).

Ví dụ 1:

Yêu cầu người thực hiện chương trình nhập vào một số thực a. In ra màn hình kết quả nghịch đảo của a khi a 0.

```C
#include <stdio.h>

#include <conio.h>

int main ()

{

float a;

printf("Nhap a = "); scanf("%f",&a);

if (a !=0 )

printf("Nghich dao cua %f la %f",a,1/a);

getch();

return 0;

}
```

Giải thích:

- Nếu chúng ta nhập vào a <> 0 thì câu lệnh printf("Nghich dao cua %f la %f",a,1/a)được thực hiện, ngược lại câu lệnh này không được thực hiện.

- Lệnh getch() luôn luôn được thực hiện vì nó không phải là “lệnh liền sau” điều kiện if.

Ví dụ 2: Yêu cầu người chạy chương trình nhập vào giá trị của 2 số a và b, nếu a lớn hơn b thì in ra thông báo “Gia trị của a lớn hơn giá trị của b”, sau đó hiển thị giá trị cụ thể của 2 số lên màn hình.

```C
#include <stdio.h>

#include<conio.h>

int main ()

{

int a,b;

printf("Nhap vao gia tri cua 2 so a, b!");

scanf("%d%d",&a,&b);

if (a>b)

{

printf("\n Gia tri cua a lon hon gia tri cua b");

printf("\n a=%d, b=%d",a,b);

}

getch();

return 0;

}
```

Giải thích:

Nếu chúng ta nhập vào giá trị của a lớn hơn giá trị của b thì khối lệnh:

```C
{

printf("\n Gia tri cua a lon hon gia tri cua b");

printf("\n a=%d, b=%d",a,b);

}
```

sẽ được thực hiện, ngược lại khối lệnh này không được thực hiện.

**Dạng đầy đủ**

Cú pháp:

if (< Biểu thức điều kiện >)

<Công việc 1>

else

<Công việc 2>

Lưu đồ cú pháp:

<img src="http://i.imgur.com/nr3sf9S.png">

*Giải thích:*

- Công việc 1, công việc 2 được thể hiện là 1 câu lệnh hay 1 khối lệnh.
- Đầu tiên Biểu thức điều kiện được kiểm tra trước.
- Nếu điều kiện đúng thì thực hiện công việc 1.
- Nếu điều kiện sai thì thực hiện công việc 2.
- Các lệnh phía sau công việc 2 không phụ thuộc vào điều kiện.

Ví dụ 1: Yêu cầu người thực hiện chương trình nhập vào một số thực a. In ra màn hình kết quả nghịch đảo của a khi a 0, khi a =0 in ra thông báo “Khong the tim duoc nghich dao cua a”

```C
#include <stdio.h>

#include <conio.h>

int main ()

{

float a;

printf("Nhap a = "); scanf("%f",&a);

if (a !=0 )

printf("Nghich dao cua %f la %f",a,1/a);

else

printf(“Khong the tim duoc nghich dao cua a”);

getch();

return 0;

}
```

Giải thích:

- Nếu chúng ta nhập vào a 0 thì câu lệnh printf("Nghich dao cua %f la %f",a,1/a)được thực hiện, ngược lại câu lệnh printf(“Khong the tim duoc nghich dao cua a”) được thực hiện.

- Lệnh getch() luôn luôn được thực hiện.

Ví dụ 2: Yêu cầu người chạy chương trình nhập vào giá trị của 2 số a và b, nếu a lớn hơn b thì in ra thông báo “Gia trị của a lớn hơn giá trị của b, giá trị của 2 số”, ngược lại thì in ra màn hình câu thông báo “Giá trị của a nhỏ hơn hoặc bằng giá trị của b, giá trị của 2 số”.

```C
#include <stdio.h>

#include<conio.h>

int main ()

{

int a, b;

printf("Nhap vao gia tri cua 2 so a va b !");

scanf("%d%d",&a,&b);

if (a>b)

{

printf("\n a lon hon b”);

printf("\n a=%d b=%d ",a,b);

}

else

{

printf("\n a nho hon hoac bang b");

printf("\n a=%d b=%d",a,b);

}

printf("\n Thuc hien xong lenh if");

getch();

return 0;

}
```

Giải thích:

- Nếu chúng ta nhập vào 40 30  thì kết quả hiển ra trên màn hình là

> a lon hon b
>
> a=40 b=30
>

- Thuc hien xong lenh if

- Còn nếu chúng ta nhập 40 50 thì kết quả hiển ra trên màn hình là

> a nho hon hoac bang b
>
> a=40 b=50
>

- Thuc hien xong lenh if

Ví dụ 3: Yêu cầu người thực hiện chương trình nhập vào một số nguyên dương là tháng trong năm và in ra số ngày của tháng đó.

- Tháng có 31 ngày: 1, 3, 5, 7, 8, 10, 12

- Tháng có 30 ngày: 4, 6, 9, 10

- Tháng có 28 hoặc 29 ngày : 2

```C
#include <stdio.h>

#include<conio.h>

int main ()

{

int thg;

printf("Nhap vao thang trong nam !");

scanf("%d",&thg);

if (thg==1||thg==3||thg==5||thg==7||thg==8||thg==10||thg==12)

printf("\n Thang %d co 31 ngay ",thg);

else if (thg==4||thg==6||thg==9||thg==11)

printf("\n Thang %d co 30 ngay",thg);

else if (thg==2)

printf("\n Thang %d co 28 hoac 29 ngay",thg);

else printf("Khong co thang %d",thg);

printf("\n Thuc hien xong lenh if");

getch();

return 0;

}
```

Giải thích:

- Nếu chúng ta nhập vào một trong các số 1, 3, 5, 7, 8, 10, 12 thì kết quả xuất hiện trên màn hình sẽ là

> Thang "số"" co 31 ngay
>
> Thuc hien xong lenh if

- Nếu chúng ta nhập vào một trong các số 4, 6, 9, 11 thì kết quả xuất hiện trên màn hình sẽ là

> Thang "số" co 30 ngay
>
> Thuc hien xong lenh if

- Nếu chúng ta nhập vào số 2 thì kết quả xuất hiện trên màn hình sẽ là

> Thang 2 co 28 hoac 29 ngay
>
> Thuc hien xong lenh if

- Nếu chúng ta nhập vào số nhỏ hơn 0 hoặc lớn hơn 12 thì kết quả xuất hiện trên màn hình sẽ là

> Khong co thang <số>
> 
> Thuc hien xong lenh if

- Trong đó <số> là con số mà chúng ta đã nhập vào.

Lưu ý:

- Ta có thể sử dụng các câu lệnh if…else lồng nhau. Trong trường hợp if…else lồng nhau thì else sẽ kết hợp với if gần nhất chưa có else.

- Trong trường hợp câu lệnh if “bên trong” không có else thì phải viết nó trong cặp dấu {} (coi như là khối lệnh) để tránh sự kết hợp else if sai.

Ví dụ 1:

```C
if ( so1>0)

if (so2 > so3)

a=so2;

else /*else của if (so2>so3) */

a=so3;

Ví dụ 2:

if (so1>0)

{

if (so2>so3) /*lệnh if này không có else*/

a=so2;

}

else /*else của if (so1>0)*/

a=so3;
```
<a name="switch"> </a>

####4.2 Switch

- Switch so sánh một biểu thức nguyên với một danh sách giá trị các số nguyên, các hằng kí tự hoặc biểu thức hằng. Mỗi giá trị trong danh sách chính là một case label (nhãn trường hợp) trong khối codes của switch. Ngoài ra, trong khối codes switch còn có thể có một default label (nhãn mặc định) có thể có hoặc không. Mặt khác, trong mỗi label còn chứa các khối codes chờ được thực thi.

**Cú pháp của cấu trúc switch…case**

Muốn sử dụng cấu trúc switch…case, bạn dùng cú pháp như sau:

```C
switch (expression)
{
    case constant_1:
    {
        Statements;
        break;
    }
    case constant_2:
    {
        Statements;
        break;
    }
    .
    .
    .
    case constant_n:
    {
        Statements;
        break;
    }
    default:
    {
        Statements;
    }
}
```

Ví dụ:

```C
#include <iostream.h>
using namespace std;
 
int main()
{
    int month;
    cout << "Month: " << endl;
    cin >> month;
 
    switch (month)
    {
        case 1:
        {
            cout << "January" << endl;
            break;
        }
        case 2:
        {
            cout << "February" << endl;
            break;
        }
        case 3:
        {
            cout << "March" << endl;
            break;
        }
        case 4:
        {
            cout << "April" << endl;
            break;
        }
        case 5:
        {
            cout << "May" << endl;
            break;
        }
        case 6:
        {
            cout << "June" << endl;
            break;
        }
        case 7:
        {
            cout << "July" <<endl;
            break;
        }
        case 8:
        {
            cout << "August" << endl;
            break;
        }
        case 9:
        {
            cout << "September" << endl;
            break;
        }
        case 10:
        {
            cout << "October" << endl;
            break;
        }
        case 11:
        {
            cout << "November" << endl;
            break;
        }
        case 12:
        {
            cout << "December" << endl;
            break;
        }
        default:
        {
            cout << "Input is false" << endl;
        }
    }
 
    return 0;
}
```

**Nguyên tắc hoạt động cấu trúc switch…case**

- Biểu thức nguyên trong switch được tính toán và kiểm tra lần lượt với giá trị của từng case label. Đầu tiên, nó sẽ được so sánh với giá trị của case label đầu tiên. Nếu bằng nhau thì sẽ thực hiện các statement trong case label này cho đến khi nó gặp được từ khoá break. Khi đó, cấu trúc switch…case kết thúc. Chương trình sẽ thực hiện tiếp những dòng code sau cấu trúc switch…case. Ngược lại, nếu như giá trị biểu thức nguyên không bằng giá trị case label đầu tiên thì nó sẽ tiếp tục so sánh đến giá trị của case label thứ hai và tiếp tục thực hiện như những bước trên. Giả sử, đến cuối cùng vẫn không tìm được giá trị bằng nó thì các khối codes trong default label sẽ được thực hiện nếu như có tồn tại default label.

Ta có sơ đồ hoạt động của cấu trúc switch…case như sau:

<img src="http://i.imgur.com/cnOHOg8.png">

Một số lưu ý khi dùng cấu trúc switch…case

- Các giá trị của mỗi case label phải cùng kiểu dữ liệu với giá trị của biểu thức đem đi so sánh.
- Số lượng các case label là không giới hạn nhưng chỉ có thể có duy nhất một default label.
- Giá trị của các case label là một hằng số và các giá trị của các case label phải khác nhau.
- Từ khóa break có thể sử dụng hoặc không. Nếu không được sử dụng thì chương trình sẽ không kết thúc cấu trúc switch…case khi đã thực hiện hết khối codes của case label có giá trị bằng với biểu thức nguyên. Thay vào đó, nó sẽ thực hiện tiếp các khối codes tiếp theo cho đến khi gặp từ khoá break hoặc dấu “ } “ cuối cùng của cấu trúc switch…case. Vì vậy, các bạn có thể sử dụng một khối codes cho nhiều trường hợp khác nhau.

Ví dụ:

```C
#include <iostream.h>
using namespace std;
 
int main()
{
        int month, day;
        cout << "Month: " << endl;
        cin >> month;
 
        switch (month)
        {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
            {
                day = 30;
                break;
            }
            case 4:
            case 6:
            case 9:
            case 11:
            {
                day = 31;
                break;
            }
            default:
            {
                day = 28;
            }
        }
 
        return 0;
}
```
###Hết
