### Tìm hiểu về con trỏ trong C

> Tài liệu tham khảo: [Con Trỏ](http://www.nguyenvanquan7826.com/2014/12/17/lap-trinh-c-bai-9-con-tro-trong-c/)
>
> Thực hiện bởi : Phạm Phú Quí
> 
> Cập nhật lần cuối : 29.10.2016

----

###Mục Lục

- [1. Biến con trỏ](#biencontro)

	- [1.1 Khai báo biến con trỏ](#khaibao)
	- [1.2 Quy định về vùng trỏ tới của con trỏ](#quydinh)
	- [1.3 Các truy xuất](#truyxuat)
	- [1.4 Một số phép toán trên biến con trỏ](#pheptoan)

- [2. Cấp phát và thu hồi vùng nhớ](#capphatvathuhoi)

	- [2.1 Cấp phát](#capphat)
	- [2.2 Thu hồi vùng nhớ](#thuhoi)

- [3. Hàm có đối là con trỏ](#ham)
- [4. Cách sử dụng con trỏ trong một function](#trofunction)
- [5. Con trỏ kiểu void](#void)
- [6. Con trỏ và mảng và con trỏ xâu](#array&string)
- [7. Mảng các con trỏ](#controarry)
- [8. Con trỏ tới con trỏ](#controtoicontro)

----

<a name="biencontro"> </a>

###1. Biến con trỏ:

- Các biến chúng ta đã biết và sửdụng trước đây đều là biến có kích thước và kiểu dữ liệu xác định. Người ta gọi các biến kiểu này là biến tĩnh. Khi khai báo biến tĩnh, một lượng ô nhớ cho các biến này sẽ được cấp phát mà không cần biết trong quá trình thực thi chương trình có sử dụng hết lượng ô nhớ này hay không. Mặt khác, các biến tĩnh dạng này sẽ tồn tại trong suốt thời gian thực thi chương trình dù có những biến mà chương trình chỉ sử dụng 1 lần rồi bỏ.
- Một số hạn chế có thể gặp phải khi sử dụng các biến tĩnh:
	
	- Cấp phát ô nhớ dư, gây ra lãng phí ô nhớ.
	- Cấp phát ô nhớ thiếu, chương trình thực thi bị lỗi.

- Để tránh những hạn chế trên, ngôn ngữ C cung cấp cho ta một loại biến đặc biệt gọi là biến động với các đặc điểm sau:

	- Chỉ phát sinh trong quá trình thực hiện chương trình chứ không phát sinh lúc bắt đầu chương trình.
	- Khi chạy chương trình, kích thước của biến, vùng nhớ và địa chỉ vùng nhớ được cấp phát cho biến có thể thay đổi.
	- Sau khi sử dụng xong có thể giải phóng để tiết kiệm chỗ trong bộ nhớ. Tuy nhiên các biến động không có địa chỉ nhất định nên ta không thể truy cập đến chúng được. Vì thế, ngôn ngữ C lại cung cấp cho ta một loại biến đặc biệt nữa để khắc phục tình trạng này, đó là biến con trỏ (pointer) với các đặc điểm:
	- Biến con trỏ không chứa dữ liệu mà chỉ chứa địa chỉ của dữ liệu hay chứa địa chỉ của ô nhớ chứa dữ liệu.
	- Kích thước của biến con trỏ không phụ thuộc vào kiểu dữ liệu, luôn có kích thước cố định là 2 byte.

- Mỗi biến khi được khai báo đều được cấp phát cho 1 vùng nhớ nhất định ở những nơi (địa chỉ) khác nhau.
- Biến con trỏ là biến dùng để lưu trữ địa chỉ của các biến đó.

**VD mở đầu**

```C
#include <stdio.h>
 
int main() {
    /* khai bao bien x va bien con tro px */
    int x, *px; 
    px = &x;
    /* &x : tra ve dia chi cua bien x
     * px = &x : gan dia chi cua bien x cho px hay px tro den x
     */
     
    x = 42;
     
    printf("Vi tri cua bien x la %p \n", &x);
    printf("Noi dung cua bien x la %d \n", x);
    printf("Vi tri cua bien x la %p \n", px);
    printf("Noi dung cua bien x la %d \n", *px);
     
    *px = 7826;
    printf("\n -------- \n\n");
     
    printf("Noi dung cua bien x la %d \n", x);
    printf("Noi dung cua bien x la %d \n", *px);
     
    return 0;
}
```

- Kết quả:

Vi tri cua bien x la 0xbff327e4
Noi dung cua bien x la 42
Vi tri cua bien x la 0xbff327e4
Noi dung cua bien x la 42

——–

Noi dung cua bien x la 7826
Noi dung cua bien x la 7826
Qua ví dụ mở đầu này ta có thể rút ra một số điểm sau:

<a name="khaibao"> </a>

####a. Khai báo biến con trỏ

- Với mỗi kiểu dữ liệu ta có tương ứng một biến con trỏ có kiểu đó.

`Kiểu * Tên biến con trỏ;`

- Trong VD trên ta khai báo 1 biến con trỏ px thuộc kiểu int.

<a name="quydinh"> </a>

####b. Quy định vùng trỏ tới của con trỏ

Ta dùng toán tử & để lấy địa chỉ của 1 biến và sau đó gán địa chỉ đó cho biến con trỏ.

`Tên con trỏ = &biến;`

<a name="truyxuat"> </a>

####c. Cách truy xuất

Với con trỏ px bên trên ta có 2 phép tuy xuất là:

px : Lấy địa chỉ mà nó lưu giữ (trỏ tới)
*px : Lấy giá trị trong vùng nhớ mà nó trỏ tới.
Trong VD trên ta có thể thấy sau phép gán px = &x ; thì việc ta viết:

px sẽ tương đương với &x
*px sẽ tương đương với x. và ta có thể sử dụng *px trong các phép toán, biểu thức.

<a name="pheptoan"> </a>

####d. Một số phép toán trên biến con trỏ

```C
#include <stdio.h>
 
int main() {
    /* khai bao bien x va 2 bien con tro px, qx */
    int x, *px, *qx; 
    px = &x;
     
    printf("Nhap gia tri cho vung nho px tro toi: ");
    scanf("%d", px); 
    /* px la con tro nen khong viet scanf("%d", &px);  */
     
    qx = px; /* gan gia tri cua px cho qx, qx cun tro toi x*/
     
    printf("Vi tri cua bien x la %p \n", &x);
    printf("Vi tri cua bien x la %p \n", px);
    printf("Vi tri cua bien x la %p \n", qx);
    printf("Noi dung cua bien x la %d \n", x);
    printf("Noi dung cua bien x la %d \n", *px);
    printf("Noi dung cua bien x la %d \n", *qx);
     
    // tang gia tri cua o nho len, <=> x = x + 7826
    *px += 7826; 
    printf("Noi dung cua bien x la %d \n", x);
     
    px++; 
    /* cong them mot don vi cho px
     *  => px tro toi vung nho tiep theo
     */
     
    printf("Vi tri px tro toi la %p \n", px);
     
    return 0;
}
```

Kết quả:

Nhap gia tri cho vung nho px tro toi: 42
Vi tri cua bien x la 0xbfba58a0
Vi tri cua bien x la 0xbfba58a0
Vi tri cua bien x la 0xbfba58a0
Noi dung cua bien x la 42
Noi dung cua bien x la 42
Noi dung cua bien x la 42
Noi dung cua bien x la 7868
Vi tri px tro toi la 0xbfba58a4

- Trong vd trên ta thấy có một số phép toán trên con trỏ hay gặp sau: (ngoài ra còn nhiều phép toán khác).

- 2 biến con trỏ cùng kiểu có thể được gán cho nhau hoặc thực hiện các phép toán cộng cho một số nguyên, trừ 2 con trỏ cho nhau. Ở VD trên ta thực hiện các phép toán:
- Gán: qx = px; Khi này qx nhận giá trị của px hiện có là địa chỉ của biến x, tức là qx và px cùng trỏ đến x. ngoài ra ta có thể gán như sau: qx = px + 2; với qx, px là các biến con trỏ cùng kiểu. Phép trừ 2 con trỏ cùng kiểu sẽ trả về 1 giá trị nguyên (int). Đây chính là khoảng cách (số phần tử) giữa 2 con trỏ đó
- Tăng: Các phép tăng giảm, cộng trừ được thực hiện trên biến con trỏ tương tự như với các biến số học. Điểm khác biệt duy nhất là nó tăng giảm, cộng trừ theo đơn byte mà kiểu của nó có.

- VD. Trong VD trên ta có phép tăng: px++; Khi này giả sử px đang trỏ đến địa chỉ: 0xbfba58a0 thì sau phép tăng nó có giá trị là (trỏ đến vị trí) 0xbfba58a4 (tăng lên 4) vì px là con trỏ kiểu int mà mỗi biến kiểu int chiếm 4 byte trong bộ nhớ.
Ngoài ra chúng ta để ý còn phép thay đổi giá trị của biến x bằng phép toán *px += 3; Ở phép toán này thực chất là ta đã thay đổi giá trị ở ô nhớ (địa chỉ) mà px trỏ tới, từ đó dẫn đến giá trị của biến x cũng thay đổi theo.

**Các bạn chú ý:**

- Tùy theo trình dịch mà dung lượng của các kiểu là khác nhau. (trong trình dịch này thì kiểu int chiếm 4 byte nhưng trong trình dịch khác thì nó lại chiếm 2 byte). Để biết dung lượng từng kiểu bạn dùng toán tử sizeof() mà trong bài 2 đã đề cập.
Mỗi biến con trỏ, dù là con trỏ thuộc kiểu nào (int, float, double,…) cũng chỉ chiếm 2 byte bộ nhớ để lưu trữ đĩa chỉ của các biến.

<a name="capphatvathuhoi"> </a>

2. Cấp phát và thu hồi vùng nhớ

<a name="capphat"> </a>

####a. Cấp phát:

Trước khi vào phần này ta làm ví dụ nho nhỏ.

```C
#include <stdio.h>
 
int main() {
    int *px;
    *px = 42;
    printf("Vi tri con tro px la %p \n", px);
    printf("Gia tri con tro px tro toi la %d \n", *px);
    return 0;
}
```

- Khi biên dịch thì sẽ không co lỗi (có cảnh báo), khi chạy sẽ không thể chạy được mà chương trình sẽ thoát ra luôn.
- Nguyên nhân là khi khai báo biến con trỏ px thì máy mới chỉ cung cấp 2 byte để lưu địa chỉ của biến con trỏ mà chưa cấp phát vùng nhớ để con trỏ px lưu trữ dữ liệu. (tương tự như hợp tác xã cung cấp 2 Kg thóc cho bạn để làm giống nhưng lại không cung cấp cho bạn ruộng đất để bạn reo mạ vậy ).

- **Lưu ý:** Có một số trình dịch sẽ không báo lỗi mà vẫn chạy bình thường nhưng tốt nhất là ta nên cấp phát trước khi sử dụng. Lỗi này sẽ xuất hiện rõ nhất khi bạn sử dụng con trỏ với mảng mà lát nữa ta sẽ đề cập.

- Để cấp phát vùng nhớ cho con trỏ ta dùng các hàm sau trong thư viện stdlib.h.

**malloc : tên con trỏ = (kiểu con trỏ *) malloc (sizeof(kiểu con trỏ));**

- Cái không hay của malloc là các phần tử mới được tạo ra không được khởi gán, *mang giá trị bất định!*

**calloc : tên con trỏ = (kiểu con trỏ *) malloc (n, sizeof(kiểu con trỏ));**

- Cái hay của calloc còn là ở chỗ các phần tử mới tạo ra sẽ được *set to zeros*.

- Trong đó sizeof(kiểu con trỏ) là kích thước của kiểu; n là số lần của sizeof(kiểu con trỏ) được cấp.

```C
#include <stdio.h>
#include <stdlib.h>
 
int main() {
    int *px, *qx;
    px = (int *) malloc(sizeof(int));
    qx = (int *) calloc(1, sizeof(int));
     
    printf("Vi tri con tro px la %p \n", px);
    printf("Gia tri con tro px tro toi la %d \n", *px);
     
    printf("Vi tri con tro qx la %p \n", qx);
    printf("Gia tri con tro qx tro toi la %d \n", *qx);
    return 0;
}
```

- Ở đây các bạn chú ý: sự khác nhau duy nhất giữa malloc và calloc mà các bạn hiểu đơn giản là với malloc thì khi cấp phát máy sẽ cấp phát cho px 1 ô bất kỳ mà không cần biết ô đó có dữ liệu là gì hay không có dữ liệu (do đó *px có giá trị như trên) còn calloc cũng vậy nhưng khác 1 điểm là sau khi cấp phát thì máy sẽ tự động gán luôn giá trị 0 cho ô nhớ mà biến qx trỏ tới, tức qx có giá trị mặc định là 0.
- Khi cấp phát cho biến con trỏ 1 số lượng ô nhớ nào đó mà trong quá trình làm việc ta thiếu và cần cấp phát thêm thì ta sử dụng lệnh realloc:

`tên con trỏ = (kiểu con trỏ *) realloc (tên con trỏ, số lượng cần cấp phát * sizeof(kiểu con trỏ));`

- Trong đó: số lượng cần cấp phát = cũ + mới.

VD: Ban đầu ta cấp phát cho con trỏ px là 10 ô nhớ. Sau đó muốn cấp phát thêm cho nó 5 ô nhớ nữa thì số lượng cấp phát = 15.

<a name="thuhoi"> </a>

####b. Thu hồi và kiểm tra vùng nhớ còn lại

Để thu hổi bộ nhớ đã cấp phát ta dùng hàm free(tên con trỏ);

<a name="ham"> </a>

###3. Hàm có đối là con trỏ

- Như trong bài Hàm chúng ta đã biết cách truyền các tham số a,b trong hàm HoanVi là cách truyền bằng tham trị chứ không phải truyền bằng địa chỉ (hay tham biến) nên mặc dù trong hàm thì giá trị các biến đã được thay đổi nhưng sau khi hàm thực hiện xong thì các giá trị vẫn chưa thể thay đổi được. Và ta sẽ phải sửa lại bằng cách truyền tham số hình thức là con trỏ a và con trỏ b để khi thực hiện hoán đổi có thể hoán đổi tại địa chỉ của các ô nhớ đó. Khi đó ta mới có được kết quả mong muốn.

```C
#include <stdio.h>
 
void hoanVi(int *a, int *b) {
     int temp = *a;
     *a = *b;
     *b = temp;
}
 
int main() {
    int a = 42, b = 7826;
    printf("Truoc khi goi ham hoan vi: a = %d, b = %d \n", a, b);
     
    hoanVi(&a, &b);
     
    printf("Sau khi goi ham hoan vi: a = %d, b = %d \n", a, b);
     
    return 0;
}
```

<a name="trofunction"> </a>

###4. Cách sử dụng con trỏ trong một function

- Điều khá thú vị ở con trỏ là chúng ta có thể sử dụng chúng trong các function để có thể thay đổi trực tiếp giá trị của biến số trong bộ nhớ chứ không phải một bản sao.

- Vậy nó hoạt động như thế nào? Có rất nhiều cách thức để sử dụng. Đây là ví dụ đầu tiên:
```C
void triplePointer(int *pointerSoHang);
int main (int argc, char *argv[ ])
{
int soHang = 5;
triplePointer(&soHang); // Ta gui dia chi cua soHang vao function
printf ("%d", soHang); /* Ta hien thi bien so soHang. Va function da truc tiep thay doi gia tri
cua bien so vi no biet dia chi cua bien so nay */
return 0;
}
void triplePointer(int *pointerSoHang)
{
*pointerSoHang *= 3; // Ta x3 gia tri cua so hang duoc dua vao
}
```

Console
15

- Function triplePointer nhận vào parameter giá trị type int * (đó là một con trỏ chỉ vào một biến số type int).

- Và đây là những gì diễn ra theo thứ tự, bắt đầu bởi function main:

- 1. Một biến số soHang được tạo ra trong main. Khởi tạo với giá trị 5.
- 2. Ta gọi function triplePointer. Ta gửi vào parameter địa chỉ của biến số.
- 3. Function triplePointer nhận địa chỉ là giá trị của pointerSoHang. Và trong funtion triplePointer, ta có một con trỏ pointerSoHang chứa địa chỉ của biến số soHang
- 4. lúc này, ta có một con trỏ chỉ lên biến số soHang, ta đã có thể thay đổi trực tiếp giá trị của biến số soHang trong bộ nhớ! Chỉ cần dùng *pointerSoHang để điều chỉnh giá trị của biến số soHang! Ở ví dụ trên, người ta chỉ đơn giản thực hiện: nhân 3 lần giá trị của biến số soHang.
- 5. kết thúc bằng return trong function main, lúc này soHang đã có giá trị 15 vì function triplePointer đã trực tiếp thay đổi giá trị của nó.

- Tất nhiên, tôi có thể thực hiện return để trả về giá trị như cách chúng ta đã học trong bài học về function. Nhưng điều thú vị ở đây là, bằng cách sử dụng con trỏ, chúng ta có thể thay đổi giá trị của nhiều biến số trong bộ nhớ (có nghĩa là "chúng ta có thể trả về nhiều giá trị"). Không còn giới hạn một giá trị duy nhất được trả về nữa !

*Vậy return còn giá trị sử dụng gì khi người ta đã có thể dùng con trỏ để thay đổi giá trị ?*

- Điều này phụ thuộc vào bạn và chương trình bạn viết. Chúng ta cần hiểu là cách dùng return để trả về giá trị là một cách viết khá đẹp và được sử dụng thường xuyên trong C.
- Và thường xuyên nhất, người ta dùng return để thông báo lỗi của chương trình: ví dụ, function trả về 1 (true) nếu tất cả diễn ra bình thường, và 0 (false) nếu có lỗi trong chương trình.
- Một cách khác để sử dụng con trỏ trong function
- Trong những code source mà chúng ta vừa thấy, không có con trỏ trong function main. Duy nhất chỉ biến số soHang.
- Con trỏ duy nhất được sử dụng nằm trong function triplePointer (có type int *)
- Bạn cần biết rằng có cách viết khác cho đoạn code vừa rồi bằng cách thêm vào con trỏ trong function main:

```C
void triplePointer(int *pointerSoHang);
int main (int argc, char *argv[ ])
{
int soHang = 5;
int *pointer = &soHang; // con tro nhan dia chi cua bien so soHang
triplePointer (pointer); // Ta dua con tro (dia chi cua soHang) vao function
printf ("%d", *pointer); // Ta hien thi gia tri cua soHang voi *pointer
return 0;
}
void triplePointer(int *pointerSoHang)
{
*pointerSoHang *= 3; // Ta x3 gia tri cua soHang
}
```

- Hãy so sánh đoạn code source này với đoạn code source trước đó. Có một số thay đổi nhưng chúng sẽ cho ta cùng một kết quả:

> Console
>
> 15

- Điều cần xét đến là cách đưa địa chỉ của biến số soHang vào function, cách sử dụng địa chỉ của biến số soHang. Điều khác biệt xảy ra ở đây là cách tạo con trỏ trong function main.
- VD trong printf, tôi muốn hiển thị giá trị của biến số soHang bằng cách viết *pointer. Bạn cần biết rằng tôi vẫn thể viết soHang: kết quả sẽ giống nhau vì*pointer và soHang đều có chung một giá trị trong bộ nhớ
- Trong chương trình "Lớn hơn hay nhỏ hơn", chúng ta đã sử dụng con trỏ bất chấp việc biết nó là gì, trong việc sử dụng function scanf.
- Thật ra, function này có tác dụng đọc những thông tin mà người dùng nhập vào bàn phím và gửi lại kết quả.
- Để scanf có thể thay đổi trực tiếp giá trị của một biến số bằng cách nhập từ bàn phím, ta cần địa chỉ của biến số đó:

```C
int soHang = 0;
scanf ("%d", &soHang);
```

- function làm việc với con trỏ của biến số soHang và có thể thay đổi trực tiếp giá trị của soHang.
- Và như chúng ta biết, chúng ta có thể làm như sau:

```C
int soHang = 0;
int *pointer = &soHang;
scanf ("%d", pointer);
```

- Chú ý là ta không đặt kí tự & trước pointer trong function scanf Tại đây, pointer bản thân nó đã là địa chỉ của biến số soHang, không cần thiết phải thêm & vào nữa !
- Nếu bạn làm điều đó, bạn sẽ đưa cho scanf địa chỉ của pointer: nhưng thứ chúng ta cần là địa chỉ của soHang.

<a name="void"> </a>

###5. Con trỏ kiểu Void:

- Là con trỏ không định kiểu (void *).Nó có thể trỏ tới bất kì một loại biến nào.
• Thực chất một con trỏ void chỉ chứa một địa chỉ bộ nhớ mà không biết rằng tại địa chỉ đó có đối tượng kiểu dữ liệu gì. => không thể truy cập nội dung của một đối tượng thông qua con trỏ void.
• Để truy cập được đối tượng thì trước hết phải ép kiểu biến trỏ void thành biến trỏ có định kiểu của kiểu đối tượng

```C
float x; int y;
void *p; // khai báo con trỏ void
p = &x; // p chứa địa chỉ số thực x
*p = 2.5; // báo lỗi vì p là con trỏ void
/* cần phải ép kiểu con trỏ void trước khi truy cập đối tượng qua con trỏ */
*((float*)p) = 2.5; // x = 2.5
p = &y; // p chứa địa chỉ số nguyên y
*((int*)p) = 2; // y = 2
(float) *p=2.5;
*p= (float *) 2.5;
*(float)p =2.5;
(float *) p =2.5;
(float *) *p=2.5;
*((float *) p )=2.5;
```

<a name="array&string"> </a>

###6. Con trỏ và mảng và con trỏ xâu:

**Con trỏ và mảng**

- Giả sử ta có : int a[30]; thì & a[0] là địa chỉ phần tử đầu tiên của mảng đó, đồng thời là địa chỉ của mảng.

• Trong C, tên của mảng chính là 1 hằng địa chỉ = địa chỉ của phần tử đầu tiên của mảng

– a = &a[0];

– a+i = &a[i];

• Tuy vậy cần chú ý rằng a là 1 hằng => không thể dùng nó trong câu lệnh gán hay toán tử tăng, giảm như a++;

• Xét con trỏ: int *pa;
pa = & a[0];
=> pa trỏ vào phần tử thứ nhất của mảng và :

• pa +1 sẽ trỏ vào phần tử thứ 2 của mảng

• *(pa+i) sẽ là nội dung của a[i]

**Con trỏ xâu:**

• Ta có : char tinhthanh[30] =“Da Lat”;

• Tương đương :

```C
char *tinhthanh;
tinhthanh=“Da lat”;
```

• Hoặc : char *tinhthanh =“Da lat”;
• Ngoài ra các thao tác trên xâu cũng tương tự như trên mảng
*(tinhthanh+3) = “l”
• Chú ý : với xâu thường thì không thể gán trực như dòng thứ 3.


<a name="controarry"></a>

###7. Mảng các con trỏ 

**Chú ý:** cần phân biệt mảng con trỏ và mảng nhiều chiều. Mảng nhiều chiều là mảng thực sự được khai báo và có đủ vùng nhớ dành sẵn cho các phần tử. Mảng con trỏ chỉ dành không gian nhớ cho các biến trỏ (chứa địa chỉ). Khi khởi tạo hay gán giá trị: cần thêm bộ nhớ cho các phần tử sử dụng => tốn nhiều hơn

• Một ưu điểm khác của mảng trỏ là ta có thể hoán chuyển các đối tượng (mảng con, cấu trúc..) được trỏ bởi con trỏ này bằng cách hoán chuyển các con trỏ
• Ưu điểm tiếp theo là việc truyền tham số trong hàm
• Ví dụ: Vào danh sách lớp theo họ và tên, sau đó sắp xếp để in ra theo thứ tự ABC.

```C
#include <stdio.h>
#include <string.h>
#define MAXHS 50
#define MAXLEN 30
int main () {
int i, j, count = 0; char ds[MAXHS][MAXLEN];
char *ptr[MAXHS], *tmp;
while ( count < MAXHS) {
printf(“ Vao hoc sinh thu : %d “,count+1);
gets(ds[count]);
if (strlen(ds[count] == 0) break;
ptr[count] = ds +count;
++count;
}
for ( i=0;i<count-1;i++)
for ( j =i+1;j < count; j++)
if (strcmp(ptr[i],ptr[j])>0) {
tmp=ptr[i]; ptr[i] = ptr[j]; ptr[j] = tmp;
}
for (i=0;i<count; i++)
printf(“\n %d : %s”, i+1,ptr[i]);
}
```

<a name="controtoicontro"> </a>

###8. Con trỏ tới con trỏ:

- Bản thân con trỏ cũng là 1 biến, vì vậy nó cũng có địa chỉ và có thể dùng 1 con trỏ khác để trỏ tới địa chỉ đó.

`<Kiểu DL> **<Tên biến trỏ>;`

• Ví dụ : 

```C
int x = 12;
int *p1 = &x;
int **p2 = &p1;
```

• Có thể mô tả 1 mảng 2 chiều qua con trỏ của con trỏ theo công thức :

`M[i][k] = *(*(M+i)+k)`

• Với
– M+i là địa chỉ của phần tử thứ i của mảng
– *(M+i) cho nội dung phần tử trên
– *(M+i)+k là địa chỉ phần tử [i][k]

• Ví dụ : in ra 1 ma trận vuông và công mỗi phần tử của ma trận với 10

```C
#include <stdio.h>
#define hang 3
#define cot 3
int main() {
int mt[hang][cot] = {{7,8,9},{10,13,15},{2,7,8}};
int i,j;
for (i=o;i<hang;i++) {
for (j=0;j<cot;j++) printf(“ %d ”,mt[i][j]);
printf(“\n”);
}
for (i=0; i<hang;i++) {
for (j=0;j<cot;j++) {
*(*(mt+i)+j)=*(*(mt+i)+j) +10;
printf(“ %d “, *(*(mt+i)+j); }
printf(“\n”); }
}
```
