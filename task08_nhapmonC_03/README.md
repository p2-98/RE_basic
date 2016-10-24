###Tìm hiểu về hàm và biến trong C

> Tài liệu tham khảo: [Hàm và biến](https://easylearnc.wordpress.com/2015/04/18/ham-bien-toan-cucbien-cuc-bo-trong-c/)
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 22.10.2016

----

###Mục lục

- [1. Hàm trong C](#ham)
	
	- [1.1 Khai báo và định nghĩa hàm](#khaibao)
	- [1.2 Lời gọi hàm](#goiham)

- [2. Biến trong C](#bien)
- [3. Cách hoạt động của hàm](#hoatdong)

----

<a name="ham"> </a>

###1. Hàm trong C:

<a name="khaibao"> </a>

####1.1 Khai báo và định nghĩa hàm

- Xây dựng một hàm bao gồm: khai báo kiểu hàm, đặt tên hàm, khai báo các đối và đưa ra câu lệnh cần thiết để thực hiện yêu cầu đề ra cho hàm. Một hàm được viết theo mẫu sau:

```C
<Kiểu_trả_về>  <tên_hàm> ( [khai báo các tham số hình thức])
{
//Khai báo các biến cục bộ
//Các câu lệnh
return  [biểu thức];
}
```

Giải thích:

–     `<Kiểu_trả_về>:` giá trị kiểu dữ liệu của dữ liệu sẽ trả về cho hàm

–      `<tên_hàm>:` tên của hàm mà bạn muốn định nghĩa, được đặt theo qui tắc đặt tên của C

–      `[khai báo các tham số hình thức]:` các tham số hình thức và kiểu của chúng

–      `[Khai báo các biến cục bộ]:` khai báo các biến cục bộ, các biến này chỉ có tác dụng trong nội bộ hàm

–      `[return]:` là lệnh thực hiện gán giá trị trả về cho hàm

–      `[biểu thức]:` là giá trị trả về cho hàm, có thể là biến, hằng, biểu thức nhưng phải có giá trị xác định và có kiểu dữ liệu là kiểu đã khai báo cho hàm.

 

Ví dụ 1: Hàm tìm giá trị lớn nhất giữa hai giá trị

```C
#include <stdio.h>
int tim_max(int a, int b)
{
            if(a>=b)
                        return a;
            else
                        return b;
}int main(){
int Max = tim_max (5,8);
printf ("Max = %d",Max);
return 0;
}
```

kết quả :Max = 8

**Lưu ý:**

– Hàm có thể có giá trị trả về hoặc không, giá trị trả về phải cùng kiểu với kiểu trả về đã khai báo hàm. Nếu hàm không có giá trị trả về thì đặt từ khóa void trước tên hàm để báo hiệu là hàm không cần giá trị trả về cho hàm.

– Khi hàm khai báo không có kiểu ở trước nó thì nó được mặc định là kiểu int.

– Không nhất thiết phải khai báo nguyên mẫu hàm. Nhưng nói chung nên có vì nó cho phép chương trình biên dịch phát hiện lỗi khi gọi.

– Nguyên mẫu của hàm thực chất là dòng đầu tiên của hàm thêm vào dấu;. Tuy nhiên, trong nguyên mẫu có thể bỏ tên các tham số hình thức.

ví dụ :

```C
#include <stdio.h>
#include <conio.h>
void A (){
printf ("Toi la A");
}
void B (){
printf ("nToi la B");
}
int main (){
//Goi ham A
A();
//Goi ham B
B();
getch ();
return 0;
}
```

kết quả :

Toi la A

Toi la B

<a name="goiham"> </a>

###1.2. Lời gọi hàm

Cú pháp:

	`tên hàm ([Danh sách các tham số thực])`

 
- Danh sách các tham số thực phải bằng số tham số hình thức và lần lượt chúng có kiểu tương ứng với nhau.

Ví dụ 

```C
#include <stdio.h>
#include <conio.h>
// khai bao prototype
// ham so sanh a và b
int tim_max(int a, int b)
 {
if(a>=b)
return a;
else
return b; }
int main()
{
int a=5, b=7;
printf(“Max là %d ”,tim_max(a,b));
getch();
}
```
<a name="bien"> </a>

###2. Biến trong C:

- Các tham số dùng khi khai báo hàm được gọi là tham số hình thức. Các tham số được cung cấp cho hàm khi gọi hàm là tham số thực. Tham số thực có thể là một biểu thức, trong khi tham số hình thức thì không thể là 1 biểu thức. Dãy các tham số thực phải tương ứng về kiểu với tham số hình thức.

- Có những hàm không cần có tham số. Vì vậy, khi khai báo ta có thể dùng từ khóa void để báo rằng hàm không cần tham số.

ví dụ : hàm tra bảng cửu chương 2

```C
void in_cuuchuong2(void)

{
    for(int i=1;i<=10;i++)
        printf(“2 x %d = %dn”, i, i*2);
}
```
 
- **Biến toàn cục** là biến được khai báo ngoài tất cả các hàm, kể cả hàm main. biến toàn cục có thể được sử dụng trong cả chương trình

- **Biến cục bộ** là biến chỉ có phạm vi hoạt động trọng nội bộ hàm, được khia báo bên trong hàm. Do tham số thực và biến cục bộ đều có phạm vi hoạt động trong cùng một hàm nên tham số thực và biến cục bộ cần có tên khác nhau.

- **Tham số hình thức** và **biến cục bộ** có thể trùng tên với các đại lượng ngoài hàm mà không gây ra nhầm lẫn nào.

- Khi một hàm được gọi tới, việc đầu tiên là giá trị của các tham số thực được gán cho các tham số hình thức. Như vậy các tham số hình thức chính là các bản sao của các tham số thực.  Hàm chỉ làm việc trên các tham số hình thức.

- Các tham số hình thức có thể bị biến đổi trong thân hàm, còn các tham số thực thì không bị thay đổi.

ví dụ :

```C
#include <stdio.h>
#include <conio.h>
// khai bao prototype
int power(int, int);
void main(void)
{
printf("2 mu 2 = %d.n", power(2, 2));
printf("2 mu 3 = %d.n", power(2, 3));
getch();
}
// ham tinh so mu
int power(int ix, int in)
{
int i, ip = 1;
for(i = 1; i <= in; i++)
ip *= ix; //tương đương với ip=ip*ix
return ip; //giá trị trả về cho hàm
}
```

*kết quả :*

2 mu 2 = 4.

2 mu 3 = 8.

**Giải thích chương trình:**

Hàm power có hai tham số truyền vào là ix, in có kiểu int và kiểu trả về cũng có kiểu int.

Dòng lệnh: return ip, trả về giá trị sau khi tính toán

Hai tham số ix, in của hàm power là dạng truyền tham trị.

<a name="hoatdong"> </a>

###3. Cách hoạt động của hàm:

Khi gặp một lời gọi hàm thì nó sẽ bắt đầu được thực hiện. Nói cách khác, khi máy gặp lời gọi hàm ở một vị trí nào đó trong chương trình, máy sẽ tạm dời chỗ đó và chuyển đến hàm tương ứng. Quá trình đó diễn ra theo trình tự sau:

–   Cấp phát bộ nhớ cho các biến cục bộ.

–   Gán giá trị của các tham số thực cho các tham số hình thức tương ứng.

–   Thực hiện các câu lệnh trong thân hàm.

–   Khi gặp câu lệnh return hoặc dấu } cuối cùng của thân hàm thì máy sẽ xoá các tham số hình thức, biến cục bộ và ra khỏi hàm.

Nếu trở về từ một câu lệnh return có chứa biểu thức thì giá trị của biểu thức được gán cho hàm. Giá trị của hàm sẽ được sử dụng trong các biểu thức chứa nó.
