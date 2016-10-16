###Tìm hiểu các thành phần cơ bản trong C

> Tài liệu tham khảo: [Wikiversity](https://beta.wikiversity.org/wiki/C%C3%A1c_th%C3%A0nh_ph%E1%BA%A7n_c%C6%A1_b%E1%BA%A3n_c%E1%BB%A7a_ng%C3%B4n_ng%E1%BB%AF_C#B.E1.BB.99_ch.E1.BB.AF_vi.E1.BA.BFt_trong_C)
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 15.10.2016

----

##Nội dung:

[1. Bộ chữ viết trong C](#textinC)
[2. Các từ khoá trong C](#keyinC)
[3. Cặp dấu ghi chú thích](#noteinC)
[4. Các kiểu dữ liệu chuẩn trong C](#datainC)

- [4.1 Kiểu số nguyên](#dataInt)
- [4.2 Kiểu số thực](#datafloat)

[5. Tên và hằng trong C](#name&const)

- [5.1 Tên](#name)
- [5.2 Hằng](#const)

	- [5.2.1 Hằng số thực](#constfloat)
	- [5.2.2 Hằng số nguyên](#constint)
	- [5.2.3 Hằng ký tự](#constchar)
	- [5.2.4 Hằng chuỗi ký tự](#conststring)

[6. Biến và biểu thức](#var&express)

- [6.1 Biến](#var)

	- [6.1.1 Cú pháp khai báo biến](#cuphap)
	- [6.1.2 Vị trí khai báo biến](#vitri)

- [6.2 Biểu thức](#express)

	- [6.2.1 Các toán tử số học](#toantu)
	- [6.2.2 Các toán tử quan hệ và toán tử Logic](#logic)
	- [6.2.3 Các toán tử Bitwise](#bitwise)
	- [6.2.4 Toán tử ? cùng với :](#haicham)
	- [6.2.5 Toán tử con trỏ & và *](#contro)
	- [6.2.6 Toán tử dấu phẩy](#phay)
	- [6.2.7 Cách viết tắt trong C](#viettat)

[7. Cấu trúc 1 chương trình C](#contrucstion)

- [7.1 Tiền xử lý và biên dịch](#debug)
- [7.2 Cấu trúc 1 chương trình C](#contruc)
- [7.3 Các tập tin thư viện thông dụng](#libary)
- [7.4 Cú pháp khai báo các phần bên trong 1 chương trình C](#cuphapC)

	- [7.4.1 Chỉ thị #include dùng để sử dụng tập tin thư viện](#include)
	- [7.4.2 Chỉ thị #define để định nghĩa hằng số](#define)
	- [7.4.3 Khai báo các prototype của hàm](#prototype)
	- [7.4.4 Cấu trúc hàm "Bình thường"](#normal)
	- [7.4.5 Cấu trúc hàm main](#main)

----

<a name ="textinC"> </a>

###1. Bộ chữ viết trong C:

- Bộ chữ viết trong ngôn ngữ C bao gồm những ký tự, ký hiệu sau: (phân biệt chữ in hoa và in thường):

	- 26 chữ cái latinh hoa A,B,C...Z
	- 26 chữ cái latinh thường a,b,c ...z.
	- 10 chữ số thập phân 0,1,2...9.
	- Các ký hiệu toán học: +, -, *, /, =, <, >, (, )
	- Các ký hiệu đặc biệt: :. , ; " ' _ @ # $ ! ^ [ ] { } ...
	- Dấu cách hay khoảng trống, xuống hàng (\n) và tab (\t)

<a name ="keyinC"> </a>

###2. Các từ khoá trong C:

- Từ khóa là các từ dành riêng (reserved words) của C mà người lập trình có thể sử dụng nó trong chương trình tùy theo ý nghĩa của từng từ. Ta không được dùng từ khóa để đặt cho các tên của riêng mình. Các từ khóa của Turbo C 3.0 bao gồm:

	- asm  • auto  • break  • case  • cdecl  • char  • class  • const  • continue  • _cs  • default  • delete  • do double  • _ds  • else  • enum  • _es  • extern  • _export  • far  • _fastcall  • float  • for  • friend  • goto  • huge  • if  • inline  • int  • interrupt  • _loadds  • long  • near  • new  • operator  • pascal  • private  • protected  • public  • register  • return  • _saveregs  • _seg  • short  • signed  • sizeof  • _ss  • static  • struct  • switch  • template  • this  • typedef  • union  • unsigned  • virtual  • void  • volatile  • while

<a name ="noteinC"> </a>

###3. Cặp dấu chú thích:

- Khi viết chương trình đôi lúc ta cần phải có vài lời ghi chú về 1 đoạn chương trình nào đó để dễ nhớ và dễ điều chỉnh sau này; nhất là phần nội dung ghi chú phải không thuộc về chương trình (khi biên dịch phần này bị bỏ qua). Trong ngôn ngữ lập trình C, nội dung chú thích phải được viết trong cặp dấu /* và */.

Ví dụ :


> 1 #include <stdio.h>
>
> 2 #include<conio.h>
>
> 3 int main ()
>
> 4 {
>
> 5     char ten[50]; /* khai bao bien ten kieu char 50 ky tu */
>
> 6     /*Xuat chuoi ra man hinh*/
>
> 7     printf("Xin cho biet ten cua ban !");
>
> 8     scanf("%s",ten); /*Doc vao 1 chuoi la ten cua ban*/
>
> 9     printf("Xin chao ban %s\n ",ten); 
>
> 10     printf("Chao mung ban den voi Ngon ngu lap trinh C");
>
> 11     /*Dung chuong trinh, cho go phim*/
>
> 12     getch(); 
>
> 13     return 0;
>
> 14 }

<a name="datainC"> </a>

###.4 Các kiểu dữ liệu chuẩn trong C:

- Các kiểu dữ liệu sơ cấp chuẩn trong C có thể được chia làm 2 dạng : kiểu số nguyên, kiểu số thực.

<a name ="dataInt"> </a>

**4.1 Kiểu số nguyên**

Kiểu số nguyên là kiểu dữ liệu dùng để lưu các giá trị nguyên hay còn gọi là kiểu đếm được. Kiểu số nguyên trong C được chia thành các kiểu dữ liệu con, mỗi kiểu có một miền giá trị khác nhau

**Kiểu số nguyên 1 byte (8 bits)**
Kiểu số nguyên một byte gồm có 2 kiểu sau:

| STT | Kiểu dữ liệu | Miền giá trị (Domain) |
|-----|--------------|-----------------------|
| 1 | unsigned char | Từ 0 đến 255 (tương đương 256 ký tự trong bảng mã ASCII) |
| 2 | char | Từ -128 đến 127 |

Kiểu unsigned char: lưu các số nguyên dương từ 0 đến 255. => Để khai báo một biến là kiểu ký tự thì ta khai báo biến kiểu unsigned char. Mỗi số trong miền giá trị của kiểu unsigned char tương ứng với một ký tự trong bảng mã ASCII .

Kiểu char: lưu các số nguyên từ -128 đến 127. Kiểu char sử dụng bit trái nhất để làm bit dấu. => Nếu gán giá trị > 127 cho biến kiểu char thì giá trị của biến này có thể là số âm (?).

**Kiểu số nguyên 2 bytes (16 bits)**

Kiểu số nguyên 2 bytes gồm có 4 kiểu sau:

| STT | Kiểu dữ liệu | Miền giá trị (Domain) |
|-----|--------------|-----------------------|
| 1 | enum | Từ -32,768 đến 32,767 |
| 2 | unsigned int | Từ 0 đến 65,535 |
| 3 | short int | Từ -32,768 đến 32,767 |
| 4 | int | Từ -32,768 đến 32,767 |

Kiểu enum, short int, int: Lưu các số nguyên từ -32768 đến 32767. Sử dụng bit bên trái nhất để làm bit dấu. => Nếu gán giá trị >32767 cho biến có 1 trong 3 kiểu trên thì giá trị của biến này có thể là số âm.

Kiểu unsigned int: Kiểu unsigned int lưu các số nguyên dương từ 0 đến 65535.

**Kiểu số nguyên 4 byte (32 bits)**

Kiểu số nguyên 4 bytes hay còn gọi là số nguyên dài (long) gồm có 2 kiểu sau:

| STT | Kiểu dữ liệu | Miền giá trị (Domain) |
|-----|--------------|-----------------------|
| 1 | unsigned long | Từ 0 đến 4,294,967,295 |
| 2 | long | Từ -2,147,483,648 đến 2,147,483,647 |

<a name = "datafloat"> </a>

**4.2 Kiểu số thực**

Kiểu số thực dùng để lưu các số thực hay các số có dấu chấm thập phân gồm có 3 kiểu sau:

| STT |Kiểu dữ liệu	| Kích thước (Size) | Miền giá trị (Domain) |
|-----|-------------|-------------------|-----------------------|
| 1 | float | 4 bytes | Từ 3.4 * 10-38 đến 3.4 * 1038 |
| 2	| double | 8 bytes | Từ 1.7 * 10-308 đến 1.7 * 10308 |
| 3	| long double | 10 bytes | Từ 3.4 *10-4932 đến 1.1 *104932 |

Mỗi kiểu số thực ở trên đều có miền giá trị và độ chính xác (số số lẻ) khác nhau. Tùy vào nhu cầu sử dụng mà ta có thể khai báo biến thuộc 1 trong 3 kiểu trên.

Ngoài ra ta còn có kiểu dữ liệu void, kiểu này mang ý nghĩa là kiểu rỗng không chứa giá trị gì cả.

<a name ="name&const"> </a>

###5. Tên và hằng trong C

<a name ="name"> </a>

####5.1 Tên:

- Tên hay còn gọi là danh biểu (identifier) được dùng để đặt cho chương trình, hằng, kiểu, biến, chương trình con... Tên có hai loại là tên chuẩn và tên do người lập trình đặt.
- Tên chuẩn là tên do C đặt sẵn như tên kiểu: int, char, float,...; tên hàm: sin, cos...
- Tên do người lập trình tự đặt để dùng trong chương trình của mình. Sử dụng bộ chữ cái, chữ số và dấu gạch dưới (_) để đặt tên, nhưng phải tuân thủ quy tắc:
	- Bắt đầu bằng một chữ cái hoặc dấu gạch dưới.
	- Không có khoảng trống ở giữa tên.
	- Không được trùng với từ khóa.
	- Độ dài tối đa của tên là không giới hạn, tuy nhiên chỉ có 31 ký tự đầu tiên là có ý nghĩa.
	- Không cấm việc đặt tên trùng với tên chuẩn nhưng khi đó ý nghĩa của tên chuẩn không còn giá trị nữa.
Ví dụ: tên do người lập trình đặt: Chieu_dai, Chieu_Rong, Chu_Vi, Dien_Tich
Tên không hợp lệ: Do Dai, 12A2,...

<a name="const"> </a>

####5.2 Hằng

- Là đại lượng không đổi trong suốt quá trình thực thi của chương trình.
- Hằng có thể là một chuỗi ký tự, một ký tự, một con số xác định. Chúng có thể được biểu diễn hay định dạng (Format) với nhiều dạng thức khác nhau.

<a name ="constfloat"> </a>
####5.2.1 Hằng số thực

- Số thực bao gồm các giá trị kiểu float, double, long double được thể hiện theo 2 cách sau:

	- **Cách 1:** Sử dụng cách viết thông thường mà chúng ta đã sử dụng trong các môn Toán, Lý, …Điều cần lưu ý là sử dụng dấu thập phân là dấu chấm (.);
	Ví dụ: 123.34-223.3333.00-56.0
	- **Cách 2:** Sử dụng cách viết theo số mũ hay số khoa học. Một số thực được tách làm 2 phần, cách nhau bằng ký tự e hay E
	Phần giá trị: là một số nguyên hay số thực được viết theo cách 1.
	Phần mũ: là một số nguyên
	Giá trị của số thực là: Phần giá trị nhân với 10 mũ phần mũ.
	Ví dụ: 1234.56e-3= 1.23456 (là số 1234.56 * 10-3)
	-123.45E4 = -1234500 ( là -123.45 *104)

<a name="constint"> </a>

####5.2.2 Hằng số nguyên

- Số nguyên gồm các kiểu int (2 bytes) , long (4 bytes) được thể hiện theo những cách sau.
	- Hằng số nguyên 2 bytes (int) hệ thập phân: Là kiểu số mà chúng ta sử dụng thông thường, hệ thập phân sử dụng các ký số từ 0 đến 9 để biểu diễn một giá trị nguyên.
	Ví dụ: 123 ( một trăm hai mươi ba), -242 ( trừ hai trăm bốn mươi hai).
	- Hằng số nguyên 2 byte (int) hệ bát phân: Là kiểu số nguyên sử dụng 8 ký số từ 0 đến 7 để biểu diễn một số nguyên.
	Cách biểu diễn: 0 <các ký số từ 0 đến 7>
	Ví dụ : 0345 (số 345 trong hệ bát phân)
	-020 (số -20 trong hệ bát phân)

<a name ="constchar"> </a>

####5.2.3 Hằng ký tự

- Hằng ký tự là một ký tự riêng biệt được viết trong cặp dấu nháy đơn ('). Mỗi một ký tự tương ứng với một giá trị trong bảng mã ASCII. Hằng ký tự cũng được xem như trị số nguyên.

Ví dụ: 'a', 'A', '0', '9'
Chúng ta có thể thực hiện các phép toán số học trên 2 ký tự (thực chất là thực hiện phép toán trên giá trị ASCII của chúng)

<a name="conststring"> </a>

####5.2.4 Hằng chuỗi ký tự

- Hằng chuỗi ký tự là một chuỗi hay một xâu ký tự được đặt trong cặp dấu nháy kép (").

Ví dụ: "Ngon ngu lap trinh C", "Khoa AT13M", "PPQui"

**Chú ý:**

	- 1. Một chuỗi không có nội dung "" được gọi là chuỗi rỗng.
	- 2. Khi lưu trữ trong bộ nhớ, một chuỗi được kết thúc bằng ký tự NULL ('\0': mã Ascii là 0).
	- 3. Để biểu diễn ký tự đặc biệt bên trong chuỗi ta phải thêm dấu \ phía trước.
	Ví dụ: "I'm a student" phải viết "I\'m a student"
	"Day la ky tu "dac biet"" phải viết "Day la ky tu \"dac biet\""

<a name ="var&express"> </a>

###6. Biến và biểu thức

<a name ="var"> </a>

####6.1 Biến

- Biến là một đại lượng được người lập trình định nghĩa và được đặt tên thông qua việc khai báo biến. Biến dùng để chứa dữ liệu trong quá trình thực hiện chương trình và giá trị của biến có thể bị thay đổi trong quá trình này. Cách đặt tên biến giống như cách đặt tên đã nói trong phần trên.

- Mỗi biến thuộc về một kiểu dữ liệu xác định và có giá trị thuộc kiểu đó.

<a name ="cuphap"> </a>

**Cú pháp khai báo biến**

<Kiểu dữ liệu> Danh sách các tên biến cách nhau bởi dấu phẩy;

Ví dụ:

> 1 int a, b, c; /*Ba biến a, b,c có kiểu int*/
>
> 2 long int chu_vi; /*Biến chu_vi có kiểu long*/
>
> 3 float nua_chu_vi; /*Biến nua_chu_vi có kiểu float*/
>
> 4 double dien_tich; /*Biến dien_tich có kiểu double*/

*Lưu ý:* Để kết thúc 1 lệnh phải có dấu chấm phẩy (;) ở cuối lệnh.

<a name ="vitri"> </a>

**Vị trí khai báo biến trong C**

- Trong ngôn ngữ lập trình C, ta phải khai báo biến đúng vị trí. Nếu khai báo (đặt các biến) không đúng vị trí sẽ dẫn đến những sai sót ngoài ý muốn mà người lập trình không lường trước (hiệu ứng lề). Chúng ta có 2 cách đặt vị trí của biến như sau:

*a) Khai báo biến ngoài:* Các biến này được đặt bên ngoài tất cả các hàm và nó có tác dụng hay ảnh hưởng đến toàn bộ chương trình (còn gọi là biến toàn cục).

Ví dụ:
> 1 int i; /*Bien ben ngoai */
>
> 2 float pi; /*Bien ben ngoai*/
>
> 3 int main()
>
> 4 { ... }

*b) Khai báo biến trong:* Các biến được đặt ở bên trong hàm, chương trình chính hay một khối lệnh. Các biến này chỉ có tác dụng hay ảnh hưởng đến hàm, chương trình hay khối lệnh chứa nó. Khi khai báo biến, phải đặt các biến này ở đầu của khối lệnh, trước các lệnh gán, ...

Ví dụ 1:

> 1 #include <stdio.h>
>
> 2 #include<conio.h>
>
> 3 int bienngoai;/*khai bao bien ngoai*/
>
> 4 int main ()
>
> 5 {
>
> 6     int j,i;/*khai bao bien ben trong chuong trinh chinh*/
>
> 7     clrscr();
>
> 8     i=1; j=2;
>
> 9     bienngoai=3;
>
> 10     printf("\n Gia7 tri cua i la %d",i); 4
>
> 11     /*%d là số nguyên, sẽ biết sau */
>
> 12     printf("\n Gia tri cua j la %d",j);
>
> 13     printf("\n Gia tri cua bienngoai la %d",bienngoai);
>
> 14     getch();
>
> 15     return 0;
>
> 16 }

Ví dụ 2:

> 1 #include <stdio.h>
>
> 2 #include<conio.h>
>
> 3 int main ()
>
> 4 {
>
> 5     int i, j;/*Bien ben trong*/
>
> 6     clrscr();
>
> 7     i=4; j=5;
>
> 8     printf("\n Gia tri cua i la %d",i);
>
> 9     printf("\n Gia tri cua j la %d",j);
>
> 10     if(j>i)
>
> 11     {
>
> 12         int hieu=j-i; /*Bien ben trong */
>
> 13         printf("\n Hieu so cua j tru i la %d",hieu);
>
> 14     }
>
> 15     else
>
> 16     {
>
> 17         int hieu=i-j; /*Bien ben trong*/
>
> 18         printf("\n Gia tri cua i tru j la %d",hieu);
>
> 19     }
>
> 20     getch();
>
> 21     return 0;
>
> 22 }

<a name="express"> </a>

####6.2 Biểu thức

- Biểu thức là một sự kết hợp giữa các toán tử (operator) và các toán hạng (operand) theo đúng một trật tự nhất định.

- Mỗi toán hạng có thể là một hằng, một biến hoặc một biểu thức khác.

- Trong trường hợp, biểu thức có nhiều toán tử, ta dùng cặp dấu ngoặc đơn () để chỉ định toán tử nào được thực hiện trước.

	- Ví dụ: Biểu thức nghiệm của phương trình bậc hai:
		(-b + sqrt(Δ))/(2*a)
	Trong đó 2 là hằng; a, b, Δ là biến.

<a name ="toantu"> </a>
	
**Các toán tử số học**
Trong ngôn ngữ C, các toán tử +, -, *, / làm việc tương tự như khi chúng làm việc trong các ngôn ngữ khác. Ta có thể áp dụng chúng cho đa số kiểu dữ liệu có sẵn được cho phép bởi C. Khi ta áp dụng phép / cho một số nguyên hay một ký tự, bất kỳ phần dư nào cũng bị cắt bỏ. Chẳng hạn, 5/2 bằng 2 trong phép chia nguyên.

| Toán tử | Ý nghĩa |
|---------|---------|
| + | Cộng |
| -	| Trừ |
| * | Nhân |
| / | Chia |
| % | Chia lấy phần dư |
| -- | Giảm 1 đơn vị |
| ++ | Tăng 1 đơn vị |

Cả 2 toán tử tăng và giảm đều có thể tiền tố (đặt trước) hay hậu tố (đặt sau) toán hạng. Ví dụ: x = x + 1 có thể viết x++ (hay ++x)

Tuy nhiên giữa tiền tố và hậu tố có sự khác biệt khi sử dụng trong 1 biểu thức. Khi 1 toán tử tăng hay giảm đứng trước toán hạng của nó, C thực hiện việc tăng hay giảm trước khi lấy giá trị dùng trong biểu thức. Nếu toán tử đi sau toán hạng, C lấy giá trị toán hạng trước khi tăng hay giảm nó. Tóm lại:

> x = 10
> y = ++x //y = 11

Tuy nhiên:

> x = 10
> y = x++ //y = 10

*Thứ tự ưu tiên của các toán tử số học:*

++ -- sau đó là * / % rồi mới đến + -

<a name ="logic"> </a>

**Các toán tử quan hệ và các toán tử Logic**

Ý tưởng chính của toán tử quan hệ và toán tử Logic là đúng hoặc sai. Trong C mọi giá trị khác 0 được gọi là đúng, còn sai là 0. Các biểu thức sử dụng các toán tử quan hệ và Logic trả về 0 nếu sai và trả về 1 nếu đúng.

|Toán tử | Ý nghĩa |
|--------|---------|
| Các toán tử quan hệ |
| > | Lớn hơn |
| >= | Lớn hơn hoặc bằng |
| < | Nhỏ hơn |
| <= | Nhỏ hơn hoặc bằng |
|== | Bằng |
|!= | Khác |
| Các toán tử Logic |
| && | AND |
| `|` | OR |
| ! | NOT |

Bảng chân trị cho các toán tử Logic.

| p | q | p`&&`q | p`||`q | !p |
|---|---|--------|--------|----|
| 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 |

Các toán tử quan hệ và Logic đều có độ ưu tiên thấp hơn các toán tử số học. Do đó một biểu thức như: 10 > 1+ 12 sẽ được xem là 10 > (1 + 12) và kết quả là sai (0).

Ta có thể kết hợp vài toán tử lại với nhau thành biểu thức như sau:

	- 10>5&&!(10<9)||3<=4 Kết quả là đúng

Thứ tự ưu tiên của các toán tử quan hệ là Logic Cao nhất: **! → >>=<<= → ==!= → && → Thấp nhất: ||**

<a name ="bitwise"> </a>

**Các toán tử Bitwise**

Các toán tử Bitwise ý nói đến kiểm tra, gán hay sự thay đổi các Bit thật sự trong 1 Byte của Word, mà trong C chuẩn là các kiểu dữ liệu và biến char, int. Ta không thể sử dụng các toán tử Bitwise với dữ liệu thuộc các kiểu float, double, long double, void hay các kiểu phức tạp khác.

| Toán tử | Ý nghĩa |
|---------|---------|
| & | AND |
| `|` |	OR |
| ^ | XOR |
| ~ | NOT |
| >> | Dịch phải |
| << | Dịch trái |

Bảng chân trị của toán tử ^ (XOR)

| p | q | p^q |
|---|---|-----|
| 0 | 0 | 0 |
| 0 | 1 | 1 |
| 1 | 0 | 1 |
| 1 | 1 | 0 |

<a name ="haicham"> </a>

**Toán tử ? cùng với :**

- C có một toán tử rất mạnh và thích hợp để thay thế cho các câu lệnh của If-Then-Else. Cú pháp của việc sử dụng toán tử ? là:
- E1?E2:E3
Trong đó E1, E2, E3 là các biểu thức.

Ý nghĩa: Trước tiên E1 được ước lượng, nếu đúng E2 được ước lượng và nó trở thành giá trị của biểu thức; nếu E1 sai, E3 được ước lượng và trở thành giá trị của biểu thức.

*Ví dụ:*

> X = 10
> Y = X > 9 ? 100 : 200

Thì Y được gán giá trị 100, nếu X nhỏ hơn 9 thì Y sẽ nhận giá trị là 200. Đoạn mã này tương đương cấu trúc if như sau:

> X = 10
> if (X < 9) Y = 100
> else Y = 200

<a name="contro"> </a>

**Toán tử con trỏ & và * **

- Một con trỏ là địa chỉ trong bộ nhớ của một biến. Một biến con trỏ là một biến được khai báo riêng để chứa một con trỏ đến một đối tượng của kiểu đã chỉ ra nó. Ta sẽ tìm hiểu kỹ hơn về con trỏ trong chương về con trỏ. Ở đây, chúng ta sẽ đề cập ngắn gọn đến hai toán tử được sử dụng để thao tác với các con trỏ.

- Toán tử thứ nhất là &, là một toán tử quy ước trả về địa chỉ bộ nhớ của hệ số của nó.

Ví dụ:

> m = &count

Đặt vào biến m địa chỉ bộ nhớ của biến count.

Chẳng hạn, biến count ở vị trí bộ nhớ 2000, giả sử count có giá trị là 100. Sau câu lệnh trên m ở vị trí bộ nhớ 2000.

Toán tử thứ hai là *, là một bổ sung cho &; đây là một toán tử quy ước trả về giá trị của biến được cấp phát tại địa chỉ theo sau đó.

Ví dụ:

> q = *m

Sẽ đặt giá trị của count vào q. Bây giờ q sẽ có giá trị là 100 vì 100 được lưu trữ tại địa chỉ 2000.

<a name="phay"> </a>

**Toán tử dấu phẩy ,**

- Toán tử dấu , được sử dụng để kết hợp các biểu thức lại với nhau. Bên trái của toán tử dấu , luôn được xem là kiểu void. Điều đó có nghĩa là biểu thức bên phải trở thành giá trị của tổng các biểu thức được phân cách bởi dấu phẩy.

Ví dụ:
> x = (y=3,y+1);

Trước hết gán 3 cho y rồi gán 4 cho x. Cặp dấu ngoặc đơn là cần thiết vì toán tử dấu , có độ ưu tiên thấp hơn toán tử gán.

- Xem các dấu ngoặc đơn và cặp dấu ngoặc vuông là toán tử

- Trong C, cặp dấu ngoặc đơn là toán tử để tăng độ ưu tiên của các biểu thức bên trong nó.

- Các cặp dấu ngoặc vuông thực hiện thao tác truy xuất phần tử trong mảng.

Tổng kết về độ ưu tiên

| Cao nhất | () [] |
|----------|-------|
| | ! ~ ++ -- (Kiểu) * & |
| | * / % |
| | + - |
| | << >> |
| | < <= > >= |
| | & |
| | ^ |
| | `|` |
| | && |
| | `||` |
| | ?: |
| | = += -= *= /= |
| Thấp nhất | , |

<a name ="viettat"> </a>

**Cách viết tắt trong C**

- Có nhiều phép gán khác nhau, đôi khi ta có thể sử dụng viết tắt trong C nữa. Chẳng hạn:

> x = x + 10 được viết thành x +=10

- Toán tử += báo cho chương trình dịch biết để tăng giá trị của x lên 10.
- Cách viết này làm việc trên tất cả các toán tử nhị phân (phép toán hai ngôi) của C. Tổng quát:

> (Biến) = (Biến)(Toán tử)(Biểu thức)

có thể được viết:

> (Biến)(Toán tử)=(Biểu thức)

<a name="contrucstion"> </a>

###7. Cấu trúc 1 chương trình C:

<a name="debug"> </a>

**Tiền xử lý và biên dịch**

- Trong C, việc dịch (translation) một tập tin nguồn được tiến hành trên hai bước hoàn toàn độc lập với nhau:

	- Tiền xử lý.
	- Biên dịch.

- Hai bước này trong phần lớn thời gian được nối tiếp với nhau một cách tự động theo cách thức mà ta có ấn tượng rằng nó đã được thực hiện như là một xử lý duy nhất. Nói chung, ta thường nói đến việc tồn tại của một bộ tiền xử lý (preprocessor?) nhằm chỉ rõ chương trình thực hiện việc xử lý trước. Ngược lại, các thuật ngữ trình biên dịch hay sự biên dịch vẫn còn nhập nhằng bởi vì nó chỉ ra khi thì toàn bộ hai giai đoạn, khi thì lại là giai đoạn thứ hai.

- Bước tiền xử lý tương ứng với việc cập nhật trong văn bản của chương trình nguồn, chủ yếu dựa trên việc diễn giải các mã lệnh rất đặc biệt gọi là các chỉ thị dẫn hướng của bộ tiền xử lý (destination directive of preprocessor); các chỉ thị này được nhận biết bởi chúng bắt đầu bằng ký hiệu (symbol) #.

- Hai chỉ thị quan trọng nhất là:

	- Chỉ thị sự gộp vào của các tập tin nguồn khác: #include
	- Chỉ thị việc định nghĩa các macros hoặc ký hiệu: #define

- Chỉ thị đầu tiên được sử dụng trước hết là nhằm gộp vào nội dung của các tập tin cần có (header file), không thể thiếu trong việc sử dụng một cách tốt nhất các hàm của thư viện chuẩn, phổ biến nhất là:

> `#include <stdio.h>`

- Chỉ thị thứ hai rất hay được sử dụng trong các tập tin thư viện (header file) đã được định nghĩa trước đó và thường được khai thác bởi các lập trình viên trong việc định nghĩa các ký hiệu như là:

> `#define NB_COUPS_MAX 100`
> `#define SIZE 25`

<a name="contruc"> </a>

**Cấu trúc một chương trình C**

- Một chương trình C bao gồm các phần như: Các chỉ thị tiền xử lý, khai báo biến ngoài, các hàm tự tạo, chương trình chính (hàm main).

- Cấu trúc có thể như sau:

	- Các chỉ thị tiền xử lý (Preprocessor directives)#include <Tên tập tin thư viện>#define ...
	- Định nghĩa kiểu dữ liệu (phần này không bắt buộc): dùng để đặt tên lại cho một kiểu dữ liệu nào đó để gợi nhớ hay đặt 1 kiểu dữ liệu cho riêng mình dựa trên các kiểu dữ liệu đã có.Cú pháp: typedef <Tên kiểu cũ> <Tên kiểu mới>Ví dụ: typedef int SoNguyen; // Kiểu SoNguyen là kiểu int
	- Khai báo các prototype (tên hàm, các tham số, kiểu kết quả trả về,… của các hàm sẽ cài đặt trong phần sau, phần này không bắt buộc): phần này chỉ là các khai báo đầu hàm, không phải là phần định nghĩa hàm.
	- Khai báo các biến ngoài (các biến toàn cục) phần này không bắt buộc: phần này khai báo các biến toàn cục được sử dụng trong cả chương trình.
	- Chương trình chính phần này bắt buộc phải có<Kiểu dữ liệu trả về> main(){Các khai báo cục bộ trong hàm main: Các khai báo này chỉ tồn tại trong hàm mà thôi, có thể là khai báo biến hay khai báo kiểu.Các câu lệnh dùng để định nghĩa hàm mainreturn <kết quả trả về>; // Hàm phải trả về kết quả}

- Cài đặt các hàm<Kiểu dữ liệu trả về> function1( các tham số){Các khai báo cục bộ trong hàm.Các câu lệnh dùng để định nghĩa hàmreturn <kết quả trả về>;}...

*Lưu ý:* Một số tập tin header thường dùng:

Một chương trình C bắt đầu thực thi từ hàm main (thông thường là từ câu lệnh đầu tiên đến câu lệnh cuối cùng).

<a name="libary"> </a>

**Các tập tin thư viện thông dụng**

- Đây là các tập tin chứa các hàm thông dụng khi lập trinh C, muốn sử dụng các hàm trong các tập tin header này thì phải khai báo #include <Tên tập tin> ở phần đầu của chương trình

1) **stdio.h:** Tập tin định nghĩa các hàm vào/ra chuẩn (standard input/output). Gồm các hàm in dữ liệu (printf()), nhập giá trị cho biến (scanf()), nhận ký tự từ bàn phím (getc()), in ký tự ra màn hình (putc()), nhận một dãy ký tự từ bàm phím (gets()), in chuỗi ký tự ra màn hình (puts()), xóa vùng đệm bàn phím (fflush()), fopen(), fclose(), fread(), fwrite(), getchar(), putchar(), getw(), putw()...

2) **conio.h:** Tập tin định nghĩa các hàm vào ra trong chế độ DOS (DOS console). Gồm các hàm clrscr(), getch(), getche(), getpass(), cgets(), cputs(), putch(), clreol(),...

3) **math.h:** Tập tin định nghĩa các hàm tính toán gồm các hàm abs(), sqrt(), log(). log10(), sin(), cos(), tan(), acos(), asin(), atan(), pow(), exp(),...

4) **alloc.h:** Tập tin định nghĩa các hàm liên quan đến việc quản lý bộ nhớ. Gồm các hàm calloc(), realloc(), malloc(), free(), farmalloc(), farcalloc(), farfree(), ...

5) **io.h:** Tập tin định nghĩa các hàm vào ra cấp thấp. Gồm các hàm open(), _open(), read(), _read(), close(), _close(), creat(), _creat(), creatnew(), eof(), filelength(), lock(),...

6) **graphics.h:** Tập tin định nghĩacác hàm liên quan đến đồ họa. Gồm initgraph(), line(), circle(), putpixel(), getpixel(), setcolor(),...

- Còn nhiều tập tin khác nữa.

<a name ="cuphapC"> </a>

**Cú pháp khai báo các phần bên trong môt chương trình C**

<a name="include"> </a>

**Chỉ thị #include để sử dụng tập tin thư viện**

- Cú pháp:

> `#include <Tên tập tin> // Tên tập tin được đạt trong dấu <>`
> `hay #include "Tên đường dẫn"`

- Menu Option của Turbo C có mục INCLUDE DIRECTORIES, mục này dùng để chỉ định các tập tin thư viện được lưu trữ trong thư mục nào.

- Nếu ta dùng #include<Tên tập tin> thì Turbo C sẽ tìm tập tin thư viện trong thư mục đã được xác định trong INCLUDE DIRECTORIES.

Ví dụ:

> `#include <stdio.h>`

- Nếu ta dùng #include "Tên đường dẫn" thì ta phải chỉ rõ tên ở đâu, tên thư mục và tập tin thư viện.

Ví dụ: 

> `#include "C:\\TC\\math.h"`

- Trong trường hợp tập tin thư viện nằm trong thư mục hiện hành thì ta chỉ cần đưa tên tập tin thư viện. Ví dụ: #include "math.h".

Ví dụ:

> `#include <stdio.h>`
> `#include <conio.h>`
> `#include "math.h"`

<a name="define"> </a>

**Chỉ thị #define để định nghĩa hằng số**

- Cú pháp:

> `#define <Tên hằng> <Giá trị>`

Ví dụ:

> `#define MAXINT 32767`

<a name ="prototype"> </a>

**Khai báo các prototype của hàm**

Cú pháp:

> <Kiểu kết quả trả về> Tên hàm (danh sách đối số)

Ví dụ:

> long giaithua( int n); //Hàm tính giai thừa của số nguyên n
> double x_mu_y(float x, float y);/*Hàm tính x mũ y*/

<a name ="normal"> </a>

**Cấu trúc của hàm "bình thường"

- Cú pháp:

> <Kiểu kết quả trả về> Tên hàm (các đối số)
> {
> Các khai báo và các câu lệnh định nghĩa hàm
> return kết quả;
> }

Ví dụ:

> int tong(int x, int y) /*Hàm tính tổng 2 số nguyên*/
> {
>    return (x+y);
> }
> float tong(float x, float y) /*Hàm tính tổng 2 số thực*/
> {
>    return (x+y);
> }

<a name ="main"> </a>

**Cấu trúc của hàm main**

- Hàm main chính là chương trình chính, gồm các lệnh xử lý, các lời gọi các hàm khác.

- Cú pháp:

> <Kết quả trả về> main( đối số)
> {

- Các khai báo và các câu lệnh định nghĩa hàm

> return <kết quả>;
> }

Ví dụ 1:

> int main()
> {
>    printf("Day la chuong trinh chinh");
>    getch();
>    return 0;
> }

Ví dụ 2:

> int main()
> {
>    int a=5, b=6,c;
>    float x=3.5, y=4.5,z;
>    printf("Day la chuong trinh chinh");
>    c=tong(a,b);
>    printf("\n Tong cua %d va %d la %d",a,b,c);
>    z=tong(x,y);
>    printf("\n Tong cua %f và %f là %f", x,y,z);
>    getch();
>    return 0;
> }
