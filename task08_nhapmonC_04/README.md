### Tìm hiểu về con trỏ trong C

> Tài liệu tham khảo: [Con Trỏ](http://diendan.congdongcviet.com/threads/t42977::tim-hieu-ban-chat-cua-con-tro-tu-co-ban-den-nang-cao.cpp)
>
> Thực hiện bởi : Phạm Phú Quí
> 
> Cập nhật lần cuối : 3.11.2016

----

###Mục Lục

- [1. Khái quát về bộ nhớ](#khaiquatbonho)
- [2. Cấp phát bộ nhớ](#capphatbonho)
- [3. Tổng quan về con trỏ](#tongquanvecontro)
- [4. Khai báo con tro](#khaibaocontro)
- [5. Khởi tạo con trỏ](#khoitaocontro)
- [6. Kiểu dữ liệu và phép toán](#dulieuvapheptoan)
- [7. Con trỏ mảng, xâu, cấp phát bộ nhớ động](#arraystring)
	
	- [7.1 Hằng con trỏ](#hangcontro)
	- [7.2 Mảng](#array)
	- [7.3 Con trỏ hằng](#pointconst)
	- [7.4 Xâu ký tự](#xaukytu)
	- [7.5 Cấp phát động](#capphatdong)
	- [7.6 Mảng 2 chiều](#mang2chieu)

- [8. Com trỏ với hàm, con trỏ hàm](#hamcontro)
----

<a name ="khaiquatbonho"> </a>

###1. Khái quát về bộ nhớ 

- Bộ nhớ vật lý:

<img src="http://i.imgur.com/6yzHtKn.jpg">

- Bộ nhớ ảo:

<img src="http://i.imgur.com/jywbXxG.jpg">

####a. Bộ nhớ ảo là gì?

Quản lý bộ nhớ vật lý (cấp phát, thu hồi) là 1 vấn đề cực kì phức tạp trong hệ thống máy tính , để bảo đảm sự hiệu quả, đúng đắn, an toàn cho việc quản lý đó, hệ điều hành xây dựng lên các vùng nhớ ảo

Trong hệ thống máy tính, bộ nhớ ảo (tiếng Anh: virtual memory) là một kĩ thuật cho phép một chương trình ứng dụng tưởng rằng mình đang có một dải bộ nhớ liên tục (một không gian địa chỉ), trong khi thực ra phần bộ nhớ này có thể bị phân mảnh trong bộ nhớ vật lý và thậm chí có thể được lưu trữ cả trong đĩa cứng. So với các hệ thống không dùng kĩ thuật bộ nhớ ảo, các hệ thống dùng kĩ thuật này cho phép việc lập trình các ứng dụng lớn được dễ dàng hơn và sử dụng bộ nhớ vật lý thực (ví dụ RAM) hiệu quả hơn. 

Lưu ý rằng khái niệm "bộ nhớ ảo" không chỉ có nghĩa "sử dụng không gian đĩa để mở rộng kích thước bộ nhớ vật lý" - nghĩa là chỉ mở rộng hệ thống bộ nhớ để bao gồm cả đĩa cứng. Việc mở rộng bộ nhớ tới các ổ đĩa chỉ là một hệ quả thông thường của việc sử dụng các kĩ thuật bộ nhớ ảo. Trong khi đó, việc mở rộng này có thể được thực hiện bằng các phương pháp khác như các kĩ thuật overlay hoặc chuyển toàn bộ các chương trình cùng dữ liệu của chúng ra khỏi bộ nhớ khi các chương trình này không ở trạng thái hoạt động. Định nghĩa của "bộ nhớ ảo" có nền tảng là việc định nghĩa lại không gian địa chỉ bằng một dải liên tục các địa chỉ bộ nhớ ảo để "đánh lừa" các chương trình rằng chúng đang dùng các khối lớn các địa chỉ liên tục.

<img src="http://i.imgur.com/uwOzXaq.jpg">

####b. Địa chỉ ảo là gì?

- Trong cái vùng bộ nhớ ảo kia, để cho tiến trình dễ sử dụng, hệ điều hành dễ hiểu, 2 thằng này cùng nhau quy định rằng, chi nhỏ ra theo từng byte, và đánh số từ 1 đến hết
- Cái ô nhớ nào đó, đã được đánh số là i thì ta nói địa chỉ của cái ô nhớ đó là i
- Giả sử tôi có biến a khai báo như sau:

`int a;`

- Và a nằm trong cái ô thứ 452321 tại cái vùng nhớ trên, vậy a có địa chỉ là 452321 tiến trình hiểu là thế, còn hệ điều hành thì hiểu hơn 1 tí : "à, cái địa chỉ này tương ứng với cái ô nhớ nào trong thanh ram mà ta đang quản lý"
- Thêm 1 tí nữa là : người ta ko dùng hệ thập phân (decimal, hệ đếm cơ số 10) để viết địa chỉ đâu, nên thui, chuyển qua hệ thập lục phân (hexadecimal , hệ đếm cơ số 16 nha ), 452321 hệ cơ số 10, chuyển lại thành 6E6E1 ở hệ cơ số 16, ở trong C tôi viết là 0x6E6E1
- Ổ ngôn ngữ ASM tôi viết là 6E6E1h << thêm chữ h vài cuối để hiểu hệ cơ số ấy mà, thôi viết là 0006E6E1h đi
- **Tại sao vậy ? tại vì như này nè**
- Trong windows 32bit (xp, vista, 7) thì địa chỉ ảo có độ dài là 32 bit, tương ứng với số hexa có 8 chữ số, thế à, nên tôi viết thêm 0 vào cho dễ hiểu ấy mà
- Các điều cần nhớ sau đây :

	- Mỗi tiến trình có 1 vùng nhớ ảo riêng
	- Vùng nhớ ảo là 1 ko gian địa chỉ ảo trải dài từ thấp đến cao ( từ 0x0000 -> cao hơn)
	- Ở trong windows 32bit thì ko gian địa chỉ ảo có địa chỉ từ 00000000h trải dài đến 7fffffffh
	- Bạn cần hiểu nó chỉ là ảo, ko phải vùng nào cũng có bộ nhớ vật lý thật đâu nhá,
	- Khái niệm về bộ nhớ phân đoạn : segment offset bạn hãy bỏ qua đi, vì nó quá cũ rồi

<a name= "capphatbonho"> </a>

###2. Vấn đề cấp phát bộ nhớ:

**1. Dẫn nhập**

- Bộ nhớ là 1 tài nguyên quan trọng trong hệ thống , được phân phối điều phối phức tạp.

- Ở đây, chúng ta sẽ xét tương quan như sau cho dễ hiểu : đất là 1 tài nguyên quý giá trong thành phố và được điều phối bởi sở tài nguyên môi trường (coi như thế, giờ hình như nó thuộc sở nhà đất thì phải,nói tóm lại là sở quản lí)


**2. Cấp phát bộ nhớ :**

- Bộ nhớ quan trọng như thế ko thể tùy tiện sử dụng , vì trong máy có nhiều tiếng trình cần bộ nhớ, tùy tiện sử dụng thì lấy đâu ra mà dùng ????

- Ai cũng cần có đất, cứ tùy tiện lấy gì cần gì sở quản lý, như thế sẽ có người không có đất mà dùng ???


- *Cấp phát bộ nhớ hoạt động như thế nào* : bản chất là trao quyền sử dụng.

Hôm nay 1 người (1 con trỏ) xin cấp phát (malloc, new) 1 vùng đất, anh ta được trao quyền sử dụng 1 vùng đất đó. 

- Khi này :
	
	- Có thể trên mảnh đất này đang trống rỗng (toàn null) nhưng cũng có thể trên đó đầy cỏ rác,hoa màu hoặc nhà cửa do người trước đó sử dụng vẫn còn . (điều này đối với anh ta mà nói nó hoàn toàn là ngẫu nhiên, ko ai có thể khẳng định được cả)

**=> khi ta xin cấp phát xong thì vùng nhớ đó hoàn toàn có giá trị ngẫu nhiên**


+ Nếu như khi anh ta xin cấp phát mà có đút lót để ra thêm điều kiện hoặc trước đó anh ta có thuê thêm 1 người quét dọn xây sửa thì anh sẽ có được 1 mảnh đất có sẵn cái anh ta muốn

**=> khi ta cấp phát đi cùng với ép buộc sẽ được vùng nhớ có giá trị như ta mong muốn**

ví dụ 

```C
int *a=new int(4);
int *b=(int*)malloc(1000);
memset(b.....);
static int x[1000];
static int y[10]={1,2,3,4,5,6};
```

**=> toàn bộ điều này là đáp án tại sao khi cấp phát bộ nhớ lại có giá trị ngẫu nhiên**

**3. Giải phóng bộ nhớ như thế nào**

- Anh ta dùng xong đất rồi, ko cần nữa, đem trả quyền sử dụng mảnh đất lại cho khổ chủ.
- Giải bộ nhớ hoạt động như thế nào : bản chất là trả lại quyền sử dụng

- *Khi này :*

	- Sở sẽ thu lại quyền sử dụng đất của anh, thế là đủ rồi, sở ko cần phải động chạm sửa chữa lại gì vùng đất đó. Nên khi đó dù vùng đất đó đã được giải phóng nhưng mà hoa màu của a ta trên đó thì vẫn còn, ko có biến mất được

- Điều này giải thích tại sao khi mà trong 1 số hệ điều hành đời cổ, nhiều bạn thử giải phóng bộ nhớ rồi, delete rồi, free rồi mà khi in thử ra vẫn thấy kết quả như thế .
- Đơn giản thôi, anh ta trả lại mảnh đất đó, nhưng chưa có ai thuê nó cả, chưa có ai sử dụng nên hôm sau ra xem thử thì nó vẫn như hôm trước khi a ta trả lại 

- Các bạn đọc rõ chú ý ở dưới rồi hẵng hỏi thêm về câu này nhé.

- Và các bạn phải chú ý là quyền sử dụng đất mới là cái được quan tâm duy nhất của vấn đề này

```C
int *a=new int[10];
int *b=(int*)malloc(1000);
```

- Thì giá trị trong a và b là địa chỉ của vùng nhớ được cấp phát. địa chỉ này sẽ được lưu lại trong sở, sở sẽ dùng cái số địa chỉ này để hiểu là quyền sử dụng đất khi giải phóng

- Tiếp theo

```C
free(b);
delete []a;
```

- 2 câu lệnh này ko có làm thay đổi giá trị của a và ba và b vẫn trỏ vào mảnh đất đấy. ok ? Và càng ko can thiệp vào vùng nhớ mà a ,b trỏ đến, cái duy nhất mà nó làm là xác nhận vùng nhớ đó đã được trả lại, đang rảnh rỗi, có thể cho thuê tiếp.

*=> điều này giải thích cho cách hiểu sai lầm của 1 số bạn mới học đối với việc cấp phát và giải phóng*

**4. Memory leak**

- Câu hỏi mở rộng :

- Như thế này có phải là giải phóng ko

```C
 int*x=new int[20];
 x=NULL;  < như thế này có phải là giải phóng ko 
```

Ở trong C (not java, java khác) thì :
- Câu trả lời là không , bạn đã hiểu sai lầm hoàn toàn về việc giải phóng rồi, bạn nên đọc kĩ lại phần giải phóng để hiểu tại sao. 
như thế này chính là :
	- Anh ta đánh mất cái quyền sử dụng đất của mình, kết quả là vùng đất đó ko được sở lấy về, sau nhiều lần như thế thì tài nguyên đất của sở càng ngày càng ít đi, hiện tượng này gọi mà memory leak


- Sau khi chương trình kết thúc , việc bộ nhớ xin cấp phát có được tự giải phóng hay ko thì tùy thuộc vào cài đặt của trình biên dịch và hệ điều hành. Chúng ta có 2 khả năng · Khả năng 1 : trong phần khởi động (trước khi vào function main() ), program xin một khối memory cuả system gọi là XXXX và mỗi lần malloc được gọi thì cấp pháp một phần memory cuả XXXX cho malloc. Do đó, khi program exit thì trả XXXX về cho system là xong. Trong trường hợp này không bị mất memory
Khả năng 2 : mỗi lần malloc được gọi thì xin memory từ system . Trường hợp này có thể memory không trả về cho system. Lúc này chương trình sẽ bị gọi là có memory leak.Như vậy sau vài lần chạy sẽ ko còn memory để cấp phát nữa

- Đó là giải thích tại sao có nhiều chương trình chạy xong, thoát ra rồi, f5 mấy lần rồi mà máy vẫn cứ ì ì ì ra..........

<a name="tongquanvecontro"> </a>

###3. Tổng quan về con trỏ:

- *con trỏ chỉ là 1 biến nguyên bình thường*
- Con trỏ chỉ là 1 biến nguyên bình thường như cân đường hộp sữa. Nó là 1 biến, biến nguyên giá trị của nó là nguyên, nó chứa cái được gọi là địa chỉ ảo mà ta đã nói ở bên trên.
- Ví dụ như là : 0x6E6E1 hoặc 0x4B6088 hoặc 454321
- Dù bạn khai báo

```C
void *p;
char *p;
hay là 
double *p;
long long *p;
```

=> Thì p vẫn là 1 biến, nó là 1 biến, biến nguyên

- *Trong hệ điều hành 32bit thì nó có độ dài là 32 bit*
- Trong windows 32bit (xp, vista, 7) thì địa chỉ ảo có độ dài là 32 bit, tương ứng với số hexa có 8 chữ số, vì sao lại chỉ có 32bit ? 
- **Vì nó cần 32bit là vừa đủ để chỉ trỏ hết vùng nhớ ảo đó**

- *Lưu ý*

- Con trỏ chỉ là 1 công cụ, là 1 kiểu dữ liệu, để ta cài đặt các giải thuật, chứ ko phải là 1 giải thuật hay thuật toán, nên câu nói như là "dùng con trỏ để giải bài A", "giải bài tập B bằng con trỏ" là hoàn toàn sai. 
Nói đúng phải là "giải bài tập C sử dụng con trỏ"

<a name="khaibaocontro"> </a>

###4. Khai báo con trỏ:

####a. Cấu trúc khai báo

`kieudulieu *tenConTro;`

- Kiểu dữ liệu ở đây có thể là 

	- Kiểu dữ liệu có sẵn (built-in data type ) : int , char , void , double , long , ......
	- Kiểu dữ liệu cấu trúc do người dùng định nghĩa (user-defined data type) : struct , union
	- Kiểu dữ liệu là lớp do người dùng định nghĩa (C++)
	- Kiểu dữ liệu dẫn xuất + kiểu con trỏ hàm (các cháp adv nhé)

- *Nhắc lại lần nữa, kiểu dữ liệu này là kiểu dữ liệu của cái vùng nhớ mà nó trỏ đến nha*

<img src="http://i.imgur.com/EOqF3na.jpg">

- tenConTro : là tên của con trỏ
- Ra khỏi câu khai báo rồi thì tenConTro sẽ là tên của con trỏ,

`int *a;`

-> Ra khỏi câu khai báo này ta sẽ nói : a là con trỏ

####b. Ví dụ

```C
int  *a,*p;  
```

=> Ta sẽ được 2 con trỏ a, và p
- Xin chú ý đế cách tôi viết nhé
	- a, p là con trỏ 
	- *a,*p không phải là con trỏ
	- kí tự * đứng gần a, đừng gần p, tại sao vậy?

####c. Chú ý

- Chú ý 1 :

```C
int  *a,b; // thì a là con trỏ, b là biến nguyên  
```

- Chú ý 2:

```C
int* a,b; //thì a là con trỏ, b là biến nguyên 
//và cách viết như này cực kì đáng ghét vì gây ra toàn hiểu lần đáng ghét  
```

- Chú ý 3:

```C
void *a;//đúng , hoàn toàn có con trỏ void nha 
```

<a name="khoitaocontro"> </a>

###5. Khởi tạo con trỏ:

###a. Khởi tạo là gì

- Có 1 số bạn sẽ lạ lầm vì cái tiêu đề khai báo với khởi tạo nghe có vẻ giống nhau..... Nhưng bạn ơi, khai báo (declared, register) và khởi tạo(initialize) hoàn toàn khác nhau nha

```C
int a; // khai báo biến a 
int b=2; //khai báo biến b và kết hợp với khởi tạo giá trị cho biến b bằng 2
```

- Khi ta khai báo 1 biến thì câu lệnh đầu tiên thiết lập giá trị cho biến đó thì đó là khởi tạo. Trong C03, C++03 trở lên khi ta khai báo 1 biến local, chưa khởi tạo giá trị mà đã đem sử dụng thì sẽ phát sinh lỗi runtime . 
- Ví dụ đoạn code sau vẫn dịch được, vẫn run nhưng khi chạy sẽ tung ra lỗi "Run-Time Check Failure #3 - The variable 'a' is being used without being initialized."

```C
#include <iostream> 
void main() 
{ 
    int a; 
    if (a==2) printf("ok"); // có lỗi run-time sinh ra ở dòng này  
}
```

####b. Khởi tạo giá trị cho biến con trỏ:

- Cấu trúc khởi tạo:

	`TênConTrỏ= ĐịaChỉ;`

- Trong đó tên con trỏ là tên của biến con trỏ
- Địa chỉ là vùng địa chỉ mà ta muốn trỏ đến

- Ví dụ:

<img src="http://i.imgur.com/YVaD0a8.jpg">

- *Chú ý 1*: Bản thân p cũng là 1 biến (nguyên), p cũng nằm trong bộ nhớ, cũng có địa chỉ riêng.

- *Chú ý 2:* Toán tử & ở đây chính xác phải gọi là `unary operator &`, toán tử `& 1 ngôi`, nó hoàn toàn khác với toán tử `& 2 ngôi (bitwise)`. Toán tử & 1 ngôi này dùng để lấy địa chỉ của 1 biến . Trước khi động đến lý thuyết về con trỏ, chúng ta đã từng sử dụng toán tử này rồi đó : `scanf("%d",&a);` .

```C
a=3&2 //toán tử & 2 ngôi, là toán tử dạng bitwise  
p=&a; // toán tử & 1 ngôi, là toán tử lấy địa chỉ của 1 biến 
scanf("%d",&a)// toán tử & 1 ngôi, là toán tử lấy địa chỉ của 1 biến 
```

- *Chú ý 3:* Có thể viết ví dụ trên ngắn gọn lại thành

```C
    int a=1987,p=&a;
```

####c. Có được điều gì sau khi khởi tạo như ví dụ trên:

- Khi giá trị nằm trong p là địa chỉ của a thì ta nói p trỏ vào a
- Lúc này thì *p hoàn toàn tương đương với a , người ta coi *p là bí danh của a , thao tác với *p cũng như thao tác với a, thao tác với a cũng như thao tác với *p

- **ví dụ : **

- a. câu lệnh a=2; hoàn toàn tương đương với câu lệnh *p=2;
- b. câu lệnh a++; hoàn toàn tương đương với (*p)++ 
- *// chú ý khác với *p++ nhé, phải cho *p vào trong đóng mở ngoặc vì toán tử * có độ ưu tiên thấp hơn ++*
- c. câu lệnh b=a+c-9; hoàn toàn tương đương với câu lệnh b=(*p)+c-9;
- d. câu lệnh (*p)=(*p) -1227; hoàn toàn tương đương với a=a-1227;

- Lúc này câu lệnh scanf("%d",&a); ta có thể thay bằng scanf("%d",p);

- *Chú ý :* Toán tử `*`

- Toán tử `*` ở đây là toán tử 1 ngôi , tác dụng là truy xuất đến ô nhớ mà con trỏ đang trỏ đến
- Để tránh những hiểu lầm ko đáng có, khi có sự nhập nhằng mà bạn ko thể đoán được, bản hãy thêm cặp () nha

- `(*p)++`
- `a+(*p)*c` // thêm vào cho nó sáng sủa code ra

####d. Một số trường hợp 

- *1. Hiểu lầm về cách cho p trỏ vào a*

<img src="http://i.imgur.com/InZnny1.jpg">

- *2. Cùng trỏ vào 1 biến*

<img src="http://i.imgur.com/H2hCR05.jpg">

- *3. Con trỏ đa cấp*

<img src="http://i.imgur.com/7AdI301.jpg">

- *4. Con trỏ đến ô nhớ đã biết*

<img src="http://i.imgur.com/D10jRbW.jpg">

- *5. Con trỏ kiểu void*

- Con trỏ void là 1 con trỏ đặc biệt, thích trỏ đi đâu thì trỏ

```C
int ham() 
{ 
    return 1; 
} 

void main() 
{ 
    int a; 
    void *p,*q; 
    p=ham; 
    q=&a; 
}
```

<a name="dulieuvapheptoan"> </a>

###6. Kiểu dữ liệu con trỏ và các phép toán trên con trỏ

####1. Kiểu dữ liệu con trỏ

- Khi ta viết int *p,b; chúng ta luôn viết * gần a, vì sao? vì * này là của p, p là con trỏ, b ko phải con trỏ

=> Kiểu dữ liệu của b là int
=> Kiểu dữ liệu của p là gì ???????????????? (1)

- Bạn xem lại hình ảnh của mục 5. Con trỏ trỏ đến ô nhớ đã biết thấy

- `p=(int *)....;` (2)

=> Từ (1) và (2) chúng ta có thể nhận thấy điều này, kiểu dữ liệu của p là (int *)

- Thật ra chúng ta đã từng gặp kiểu dữ liệu con trỏ dạng này rồi. Ví dụ khi tra MSDN tôi có được cái này :

```C
char* gets(char* str);
```

- Tôi rất tin vào cách viết chuẩn mực của Microsoft, vì thế tôi cũng khuyên các bạn code theo chuẩn mực này :
	
	- Trong câu lệnh khai báo con trỏ tôi viết * gần tên con trỏ
	- Khi viết kiểu dữ liệu tôi viết * đứng gần kiểu dữ liệu cơ bản : cụ thể ở kiểu dữ liệu trả về của hàm, ở tiêu đề và nguyên mẫu hàm
	- Ở câu lệnh ép kiểu thì manual theo bạn muốn, có thể viết cách ra cho thoáng code

- Các bạn có thể xem lại nguyên mẫu hàm gets ở bên trên để hiểu thêm về cách viết code này

####2. Các phép toán trên con trỏ

- *a. Phép gán*

- Phép gán đối với con trỏ thì tham khảo phần khởi tạo nhưng có 1 vài yếu tố xâu đây :
	- Tất cả các loại con trỏ đều có phép gán
	- Phép gán với con trỏ yêu cầu vế trái là 1 con trỏ và vế phải là 1 địa chỉ
	- Phép gán yêu cầu sự tương xứng về kiểu dữ liệu, nếu ko tương xứng chúng ta phải ép kiểu

- ví dụ `p=(int*)8232;`
	
	- p có kiểu dữ liệu là int*
	- còn 8232 là 1 hằng số nguyên, nên phải ép kiểu về int* rồi thực hiện phép gán

- Phép gán với 1 con trỏ kiểu void ko cần thiết phải tương xứng hoản toàn về kiểu dữ liệu, void* có thể tương ứng với tất cả (như ở ví dụ cháp trước), thậm chí là vượt cấp (vượt hẳn 2 cấp) như ví dụ sau

```C
    void *p,**q;
    p=&q;  
```

- *b. Phép so sánh*

- Phép so sánh ngang bằng dùng để kiểm tra 2 con trỏ có trỏ vào cùng 1 vùng nhớ hay không, hoặc kiểm tra 1 con trỏ có phải là đang trỏ vào NULL hay không (trong trường hợp cấp phát động, mở file, mở resource,........)

- Phép so sánh lớn hơn nhỏ hơn : > , < , >= , <= sử dụng để kiểm tra về độ thấp cao giữa 2 địa chỉ . Con trỏ nào nhỏ hơn thì trỏ vào địa chỉ thấp hơn.

- Được quyền so sánh mọi con trỏ với 0, vì 0 chính là NULL

```C
void main()
{
    int a=197,*p=&a;
    double *x;
    p==&a;
    main==0;  // học các cháp sau để hiểu sâu hơn dòng lệnh này, he he he he he 
    p==0;
    x==0;

}
```

- Ngoài ra thì khi so sánh 2 con trỏ hoặc con trỏ với 1 địa chỉ xác định (số nguyên) cần có sự tương xứng về kiểu dữ liệu

```C
int main()
{
    int a=197,*p=&a;
    double b=0,*x=&b;

    // so sánh 2 con trỏ 
    (int)p==(int)x;
    p==(int *)x;
    (double*)p==x;
    (void*)p==(void*)x;
    p==(void*)x;
    (float*)p==(float*)x;

    //so sánh con trỏ với số nguyên
    p==(int*)9999;
    int(p)==9999;

    // phần nâng cao và thâm thúy về con trỏ   
    (int)p==int(main);
    p==(int*)main;
    (int(*)())p==main;
    p==(void*)main;
    // bình tĩnh tự tin theo hết bài viết này bạn sẽ hiểu được cái gì đang xảy ra ở 4 dòng code này

}  
```

- Con trỏ void có thể đem ra so sánh với tất cả các con trỏ khác

```C
void main()
{
    int a=197,*p=&a;
    (int(*)())p==main;
}  
```

- *c. Phép cộng trừ và phép tăng giảm : + += - -= ++ --*

- Bản chất của việc tăng/ giảm con trỏ p đi 1 đơn vị là cho p trỏ đến ô nhớ bên cạnh phía dưới/trên.
- *Chú ý:*
	
	- Khi tăng giảm con trỏ p đo 1 đơn vị không có nghĩa là trỏ sang byte bên cạnh
	- Việc tăng giảm con trỏ đi 1 đơn vị phụ thuộc vào kiểu dữ liệu và nó trỏ đến, quy tắc là  
	- *p+1 >>> giá trị chứa trong p + sizeof(kiểu dữ liệu của biến mà p trỏ đến)*
	- Không có phép tăng giảm trên con trỏ void
	- Không có phép tăng giảm trên con trỏ hàm
	- Không có phép cộng 2 con trỏ với nhau
	- Phép trừ 2 con trỏ trả về độ lệch pha giữa 2 con trỏ

- Vậy ta có kết luận như sau : kiểu dữ liệu trỏ đến có tác dụng xác thực sự rõ ràng tất cả các phép toán trên con trỏ (bao gồm cả phép = * &)  

<img src="http://i.imgur.com/IWWux6g.jpg">

####3. Ứng dụng

- Mình demo trước một ứng dụng của việc thao tác các phép toán trên con trỏ

- Ứng dụng duyệt xâu

```C
#include <stdio.h>
#include <conio.h>

void main()
{
    char xau[200];

    printf("Nhap xau : "); 
    scanf("%[a-zA-Z ]",xau); //nếu bạn chưa hiểu dòng lệnh này hãy xem bài viết này để hiểu sâu thêm về scanf 
    //http://forums.congdongcviet.com/showthread.php?t=34612

    //Viết hoa xâu  (duyệt xuôi)
    printf("Viet hoa  : ");
    for (char *p=xau;*p;p++) //p trỏ đến xâu; kí tự trỏ đến khác NULL;p=p+1
        printf("%c",toupper(*p));

    //viết đầy đủ sẽ là (char *p=xau;*p!=NULL;p++)
    //viết ngắn gọn lại cho độc đáo


    //Viết đảo ngược xâu  (duyệt ngược)
    printf("\nDao nguoc xau : ");
    for(char *p=xau+strlen(xau)-1;p>=xau;p--)  // cho p trỏ vào từ cuối cùng; p còn lớn hơn xau;p=p-1
        printf("%c",*p);



    getch();
}
```

- Ứng dụng đổi số thực thành số nhị phân

```C
#include <stdio.h>
#include <conio.h>

void nhiphan(float n)
{
    for(int i=0,*temp=(int *)(void*)&n;i<sizeof(n)*8;i++,(*temp)<<=1)
        printf("%d",*temp>=0);
}

void main()
{
    nhiphan(3.9f);
    getch();
}
```   
- Ứng dụng tìm (số float lớn hơn ko) nhỏ nhất đấy chính là số 00000000 00000000 00000000 00000001

```C
#include <stdio.h>

int main()
{
    float x = 0;
    char *p = (char*)&x;
    (*p) |= 1;
    printf("%c",x);
    return 0;
}
``` 
<a name="arraystring"> </a>

###7: Con trỏ với mảng, xâu, cấp phát bộ nhớ động

<a name="hangcontro"> </a>

####I. Hằng con trỏ - const pointer ???? Con trỏ hằng , pointer to const???

- *a. Hằng là gì?*

- Ta đã biét hằng số (toán học) là những đại lương có giá trị không đổi, trong lập trình là những đại lương có giá trị không đổi trong suốt trương trình.
- Hằng trong C/C++/C++0x có định kiểu rõ ràng
- Hằng trong C/C++/C++0x được định nghĩa bằng từ khóa const

- *Chú ý :* Có 1 số người hiểu lầm rằng dùng từ khóa define định nghĩa hằng số, đây thật sự là 1 cái hiểu sai lầm hoàn toàn. Define định nghĩa nên macro và có rất nhiều sự khác nhau khi ta dùng define và const

- *b. Hằng con trỏ ?*

- Mình đã tìm hiểu về kiểu dữ liệu con trở ở : 
	- Nó lưu trữ cái gì, miền giá trị của nó 
	- Các phép toán trên con trỏ

- Bây giờ mình sẽ tìm hiểu thêm về kiểu dữ liệu con trở ở : hằng con trỏ . Vậy hằng con trỏ là gì ? Đối với hằng và con trỏ có 2 loại như sau
	
	- Những con trỏ mà chỉ trỏ cố định vào 1 vùng nhớ , những con trỏ này ko có khả năng trỏ vào vùng nhớ khác, ko thay đổi được (1)
	- Những con trỏ mà trỏ vào 1 vùng nhớ cố định, con trỏ này chỉ có tác dụng trỏ đến, chứ không có khả năng thay đổi giá trị của vùng nhớ này, con trỏ này được ứng dụng gần như là tác dụng của phương thức hằng trong OOP (2)

- Để tiên phân biệt, mình gọi (1) là hằng con trỏ và (2) là con trỏ hằng, và chúng ta có thể gộp cả 2 kiểu này để thành 1 kiểu mới

- Ví dụ về loại (1)

```C
void main()
{
char buf[] = "bonjour";
char * const p = buf;
 
p++;   <<<<<<<<<<<<<<<<<<<<<<< báo lỗi tại đây
p[4]++; <<<<<<<<<<<<<<<<<<<<<<<<< ko vấn đề, hoàn toàn có thể thay đổi giá trị vùng nhớ mà p trỏ đến
}
```

ví dụ về loại (2), tham khảo về những sai lầm thường gặp

```C
void main()
{
    char *p="Bui Tan Quang";
   
    p++;
 
 
    (*p)++; <<<<<<<<<<<<<<<<<<<<<<< báo lỗi tại đây (không báo lỗi khi biên dịch nhưng có lỗi trong run-time)
    p[2]='b';<<<<<<<<<<<<<<<<<<<<<<< báo lỗi tại đây (không báo lỗi khi biên dịch nhưng có lỗi trong run-time)
 
}
```

```C
char buf[] = "bonjour";
char const * p = buf; /* hay const char * p = buf; */
 
p++;    /* được */
p[4]++; /* ko được, sai */
```

ví dụ về kết hợp

```C
char buf[] = "bonjour";
char const * const p = buf;
 
p++;    /* Sai */
p[4]++; /* Sai */
```

- Ví dụ tiếp với hàm

```C
void ConvertUnicodeTextToSomeThing(const unsigned short int *wstr)
{
    unsigned short int const * p=wstr; //okies
 
    unsigned short int * q=wstr; //báo lỗi
 
}
```

- Ứng dụng lớn nhất của char const * đó là chú ý khi khai báo và sử dụng các hàm trả về const, nếu ko biết điều này có thể bạn sẽ ko bít cách xài code của người khác khi đang ở trong 1 project lớn và mọi người dùng các hàm của nhau. Chú ý nhé, mấy newbie hay gặp vấn đề với cái này lắm nhé

```C
const char * HamGiDoCuaNguoiKhacViet(void)
{
    return "abc";
}
 
void HamCuaToi(void)
{
    //gọi và sử dụng đến kết quả hàm bên trên thế nào?
 
    char const * pstr=HamGiDoCuaNguoiKhacViet(); // thế này nè
}
```
<a name="array"> </a>

####II. Mảng liên quan gì đến con trỏ và cho vào bài viết này chi ?

- Khi ta khai báo mảng thì tương đương với : xin cấp phát 1 vùng nhớ có kich thước như bạn khai báo và khai báo ra 1 hằng con trỏ trỏ vào đầu vùng nhớ đó

- `int a[100];`

- Có thể coi a là 1 hằng con trỏ trỏ vào phần tử thứ 0 của mảng nhé, a mang đầy đủ tính chất của 1 hằng con trỏ nhưng có thêm 1 số khác biệt nhỏ (ví dụ khi dùng size of)
- Các phép toán nhằm làm a trỏ tới vùng khác (thay đổi giá trị của a) là ko thể (++ -- = )
- a tương đương với &a[0]
- a+i tương đương với &a[i]
- *a tương đương với a[0]
- *(a+i) tương đương với a[i]
- *Chú ý :* trình biên dịch luôn hiểu a[i] là *(a+i)

<img src="http://i.imgur.com/yiawxLS.jpg">

**Biết điều này để làm gì ?**

- 1. Nhập mảng

```C
#include <stdio.h>
#include <conio.h>

void main()
{
    float a[100];
    int n;
    //nhập n
    printf("Nhap n :");
    scanf("%d",&n);
    // nhập mảng
    for(int i=0;i<n;i++)
    {
        printf("Nhap vao phan tu thu %d",i+1);
        scanf("%f",a+i);
    }

    // xuất mảng
    printf("mang vua nhap : \n");
    for(int i=0;i<n;i++)
        printf("%f  ",*(a+i));

    getch();
}
```

2. Bài toán vui

```C
#include <stdio.h>
#include <conio.h>

void main()
{
    int a[100]={0,1,2,3,4,5,6};
    printf("%d",2[a]); //in ra 2, tại sao vậy ?

    getch();
}
```

- Chắc chắn lúc nhìn thấy 2[a] ko ít người sẽ thấy là lạ, nghĩ nó là lỗi,...... có người thì nghĩ là nó in ra 2, nhưng tại sao vậy ?
- Thật ra : 2[a] trình biên dịch sẽ hiểu là *(2+a)
- *(2+a) hoàn toàn tương đương với *(a+2)
- Mà *(a+2) chính là a[2]
- Vậy 2[a] cũng đơn giản là a[2]

<a name="pointconst"> </a>

####III. À, thế còn con trỏ hằng là cái gì thế ?

- Con trỏ hằng là 1 optional ability trong lập trình, tác dụng của nó tựa như là (gần như thôi, ko thể bằng được) phương thức hằng trong C++;
- Ý nghĩa là 1 con trỏ, trỏ đến 1 ô nhớ, nhưng ko được quyền thay đổi giá trị của ô nhớ đó!!!!!!!!

```C
    int a=3;
    const int *p;
    p=&a;  <<<<<<<<<<<<< bản thân p thì có thể thay đổi, cho p gán vào chỗ khác được nhưng

    (*p)++; <<<<<<<<<<< báo lỗi tại đây!
```

Ví dụ điển hình nhất ở đây là hàm strlen của chúng ta

```C
int strlen(const char *Str)
```

- Khi bạn code trong 1 project C lớn 1 tí hoặc lớn nhiều tí, hơ hơ, giả sử bạn có 1 hàm, thao tác với 1 mảng , hàm này chỉ đọc mảng thôi, không làm thay đổi các giá trị trong mảng . Và quan trọng là, khi share code cho các bạn khác trong cùng project, làm sao để họ biết điều này ?
- Vậy ta sẽ cài đặt hàm của mình như sau

- Demo ví dụ mẫu

```C
// đối với trường hợp hằng con trỏ là tham số hình thức thì
// void ham(const int *) và void ham(int const *) 
// là như nhau, từ const khi đóng góp vào trong tham số hình thức là như nhau
void ham(const int *a,int n)  
{
    //xử lý gì đó
}
void main()
{
    int a[100]={1,2},n=2;

    ham(a,n); // khi sử dụng hàm này tôi hiểu là, à, nó ko thay đổi mảng a của tôi đâu
    //yên tâm xài, nếu có lỗi gì đó thì ko phải sinh ra từ đây
}
```

<a name="xaukytu"> </a>

####IV. Thế còn xâu kí tự thì sao ?

- Xâu kí tự là trường hợp đặc biệt của mảng 1 chiều khi mà cách thành phần của mảng là 1byte
- Xâu kí tự kết thúc bằng NULL. NULL là 1 kí tự đặc biệt có mã là 0, 
- Có 3 cách viết NULL trong C như sau : NULL , '\0' , 0

*A. Sai lầm thường gặp khi làm việc với xâu kí tự*

- Đối với xâu kí tự thì các bạn phải nhớ được những trường hợp sau 

- 1. Chưa có bộ nhớ đã sử dụng như đúng rồi => Sai

```C
    char *xau;
    gets(xau); // vẫn biên dịch được
    //nhưng khi chạy sẽ sinh ra lỗi run-time
    // ở 1 số trình biên dịch cùi bắp ngày xưa thì có thể ko bị lỗi đâu
    //  nhưng sai thì vẫn là sai, code này sai thuộc loại chưa cấp phát
```

- 2. Thay đổi giá trị của một hằng => Sai

```C
    char *xau="langman-congdongcviet";
    xau[6]='A';// vẫn biên dịch được
    //nhưng khi chạy sẽ sinh ra lỗi run-time
    // lỗi này là lỗi cố tình thay đổi giá trị của 1 hằng
```

- Nguyên nhân sâu xa của vấn đề như sau : 
- Khi khai báo char *xau="langman-congdongcviet"; thì bản chất là 
	
	- Trong vùng nhớ data của chương trình sẽ có 1 hằng chuỗi "langman-congdongcviet" . <<<< là hằng chuỗi, đã là hằng thì ko thể bị thay đổi
	- Cho con trỏ xau trỏ đến đầu của vùng nhớ đó. 
	- Câu lệnh tiếp theo xau[6]='A'; cố tình thay đổi giá trị của hằng , rõ ràng là sinh ra lỗi rồi

- 3. Cố tình thay đổi giá trị của hằng con trỏ => sai 

```C
    char xau[100];
    xau="bùi tấn quang"; // không biên dịch được
    // vì phép toán trên có nghĩa là khai báo 1 chuỗi "bùi tấn quang" trong vùng nhớ code
    //   rồi sau đó cho hằng con trỏ xâu trỏ vào đó
    //  rất tiếc xau là hằng con trỏ nên ko thể trỏ đi đâu khác được 
   // ngoài vị trí đã được khởi tạo trong câu lệnh khai báo
```

- Chú ý char xau[100]="bùi tấn quang"; hoặc char xau[100]={0}; thì hoàn toàn hợp lệ

4. Dùng phép toán so sánh để so sánh nội dung 2 xâu => Sai 

```C
void main()
{
    char xau[100]="quangxeng";
    if (xau=="quangxeng") ... // code này ko sai về ngữ pháp, ko sinh ra lỗi runtime
    //nhưng mang lại kết quả ko như người dùng mong muốn
       // vì theo mục b. ở trên ta có
    //Phép so sánh ngang bằng dùng để kiểm tra 2 con trỏ có trỏ vào cùng 1 vùng nhớ hay không,
//hoặc kiểm tra 1 con trỏ có phải là đang trỏ vào NULL hay không
//(trong trường hợp cấp phát động, mở file, mở resource,........)
      // chứ ko phải là phép so sánh nội dung của xâu
//để so sáng nội dung của xâu ta phải dùng những hàm strcmp (string compare) hoặc stricmp
// hoặc những hàm bạn tự định nghĩa
}
```
- *Phụ lục*

<img src="http://i.imgur.com/6zleq3f.jpg">

- 1 Style duyệt xâu mới:

- Nhập vào dạng "họ đệm tên", viết ra màn hình "Tên Đệm Họ":

```C
#include <stdio.h>
#include <conio.h>

void main()
{
    char xau[100],*p=xau,*q,*i;
    printf("Nhap : "),scanf("%[a-z ]",xau); // nhap vao "ho dem ten"
    
    while(*p!=' ') p++;
    q=xau+strlen(xau)-1;
    while(*q!=' ') q--;
    
    //viet hoa
    *xau=toupper(*xau);
    p[1]=toupper(1[p]);
    q[1]=toupper(1[q]);

    //viet
    printf("Xuat :%s",q); //ten
    for(i=p;i<=q;i++) printf("%c",*i); // dem
    for(i=xau;i<p;i++) printf("%c",*i); // ho
    
    getch();
}
```

<a name="capphatdong"> </a>

####V. Thế còn cái từ cấp phát động thì sao?

- *1. cấp phát động như thế nào*
- **a. C**

- `contro = (ép kiểu) malloc(...)`

- Trong C chúng ta cấp phát động chủ yếu sử dụng các hàm trong alloc.h
- các bạn có thể tham khảo các hàm [ở đây](http://forums.congdongcviet.com/showpost.php?p=30657)

- Chú ý là : 

	- malloc trả về 1 địa chỉ đến 1 vùng nhớ và coi vùng nhớ này là void *, nên trong câu lệnh malloc luôn đi kèm với việc ép kiểu
	- Cấp phát là luôn phải đi kèm với giải phóng, ở đâu cũng thế, malloc là phải free, ok ? Code mà để thoát chương trình rồi chưa giải phóng cho dù là có hệ thống có tự giải phóng đi nữa vẫn bị coi là bad!!!!
	- Trong java chỉ cần cho reference = null là nó giải phóng nhưng trong C thì bắt buộc phải có thao tác giải phóng free()

- **b. C++**

- Trong C++ chúng ta dùng new và delete để cấp phát động 
- `new` và `delete` về cú pháp tham khảo trong sách

*Sự khác nhau giữa malloc và new?*

- new và malloc khác nhau cực cực kì nhiều đó các pạn à
- Sơ bộ như sau, chưa phân tích kĩ
	
	- malloc là hàm, cấp phát trả về kiểu void *, malloc thì ko gọi hàm tạo
	- free ko gọi hàm hủy
	- malloc trả về NULL nếu thất bại

- new là toán tử, new gọi hàm tạo, new có thể được đa năng hóa (nạp chồng), new ném ra exception nếu thất bại. Toán tử new và toán tử new[] ko có khả năng realloc

<a name="mang2chieu"> </a>

####VI. Mảng 2 chiều, bản chất như thế nào, khác gì mảng một chiều ? 

<img src="http://i.imgur.com/ysBCUXm.jpg">

<img src="http://i.imgur.com/hNdLbaj.jpg">

<img src="http://i.imgur.com/4O3KDA6.jpg">

<a name="hamcontro">

###8.Con trỏ với hàm, con trỏ hàm

*I. Hàm cũng có địa chỉ:*

- Khi 1 chương trình(1 pe file) chạy (tiến trình) thì các hàm nằm bên chương trình đó được được load lên không gian nhớ ảo, VA space, chúng nằm trong vùng nhớ code.
- Các bạn có thể tham khảo hình dưới đây , hình ảnh khi debug 1 ứng dụng với ollydbg và debug 1 ứng dụng bằng IDE VS2010 :

<img src="http://i.imgur.com/oKD7N2c.jpg">

<img src="http://i.imgur.com/24LrlIf.jpg">

*II. Con trỏ hàm*

- Con trỏ hàm là 1 điều thú vị trong C/C++. bản chất của con trỏ hàm cũng là 1 con trỏ có định kiểu.
- ta có thể sử dụng con trỏ hàm để gọi hàm (invoke ) khi đã biết địa chỉ của hàm

**a. gọi nội ứng dụng**

- demo 1 ví dụ

```C
#include <stdio.h>
#include <conio.h>
int min(int a,int b)
{
    if (a>b) return a;
    return b;
}
void main()
{
    int (*p)(int,int);
    p=min;
    printf("min cua 4 va 5 la %d",p(4,5));
    getch();
}
```

- Chú ý : khi khai báo ta phải dùng toán tử () với ý nghĩa là * này thuộc về p, là 1 con trỏ hàm. int (*p)(int,int);

**b. gọi từ ứng dụng khác (bản chất thì vẫn là nội nhưng ở 1 hình thái khác, remote + nội)**

- Bạn có thể ý thấy auto game võ lâm ko ? Làm sao khi ta ấn Ctrl+Z nó sẽ mở hòm đồ ra ?
- Nguyên tắc của nó như sau : nó sử dụng kĩ thuật cài hook để cài 1 thread vào trong game võ lâm.
- Thread này khi người dùng ấn nút Ctrl+Z nó sẽ gọi hàm mở hòm đồ có sẵn trong game võ lâm.

- Giả sử a có hàm dạng void hamMoHomDo(int a); tại địa chỉ 0x873AB chẳng hạn thì a sẽ làm thế này

```C
void (*p)(int);
p=(void (*)(int)) 0x873AB;
p(3); //gọi hàm với tham số là 3
```

*III. Hằng con trỏ hàm*

- Khái niệm hằng con trỏ hàm cũng gần gần giống như khái niệm hằng con trỏ với mảng 1 chiều, khi bạn khai báo 1 hàm, thì tên của hàm chính là 1 hằng con trỏ hàm, con trỏ này trỏ cố đình vào vùng nhớ của hàm. Vâng, đó là lý do vì sao ở code bên trên, tôi có thể có những dòng lệnh này

```C
    (int)p==int(main);
    p==(int*)main;
    (int(*)())p==main;
    p==(void*)main;
```  

- Chúng ta thấy đó, chúng ta khai báo ra 1 hàm main. vậy rõ ràng ta có 1 hằng con trỏ main, là 1 hằng thì ta hoàn toàn có thể sử dụng để so sánh rồi

*IV. Ứng dụng của con trỏ hàm*

- Con trỏ hàm được ứng dụng trong nhiều trường hợp khác nhau khá rộng rãi. Sau đây mình xin tiến cử vài ví dụ điển hình
	
	- Trường hợp đơn giản tất cả chúng ta đều sử dụng ko ít lần rồi, nhưng vẫn ko hiểu ko biết là mình dùng, đó là cout<<endl;

- *endl, hex, oct được định nghĩa như nào ?*
- endl nó được định nghĩa như này ?

```C
ostream& endl ( ostream& os )
{
       os.push('\n');
       return os;
}
```

- Vậy thì câu lệnh cout<<endl;
- Không hiểu thằng endl được truyền tham số vào như nào?
- Câu hỏi khá hay và khá ảo, bạn ơi vấn đề là thằng toán tử << có 1 hàm overload như này
- Tôi demo lại cho dễ hiểu nha

```C
friend ostream& operator<<(ostream &os, ostream& (*p)(ostream&) )
{
       return p(os);
}
```

- Sử dụng trong các hàm mẫu, lớp mẫu , có tính tùy chọn cao

- Bạn đã bao giờ nghe nói về hàm qsort trong namespace std chưa, tại sao khi sử dụng nó ta lại phải truyền vào 1 tên hàm , hay nói chính xác là 1 hằng con trỏ hàm?
- Mình xin demo 1 cái đơn giản

```C
#include <iostream>
using namespace std;
 
#include <stdio.h>
#include <conio.h>
void xapxep(void *a,int sizeOfElement,int n,int (*hamsosanh)(void*,void*))
{
    int i,j;
    void *temp=new char[sizeOfElement];
    for(i=0;i<n-1;i++)
        for(j=i+1;j<n;j++)
            if (hamsosanh((char*)a+i*sizeOfElement,(char*)a+j*sizeOfElement)>0)
            {
                memcpy(temp,(char*)a+i*sizeOfElement,sizeOfElement);
                memcpy((char*)a+i*sizeOfElement,(char*)a+j*sizeOfElement,sizeOfElement);
                memcpy((char*)a+j*sizeOfElement,temp,sizeOfElement);
            }
    delete[] temp;
}
 
 
 
int hamsosanhungdung1(void *a,void *b)
{
    return (*(double*)a)>(*(double*)b);
}
 
int hamsosanhungdung2(int *a,int *b)
{
    return (*a)>(*b);
}
void main()
{
    double a[100]={1.,2.,3.,4.,6.,5.};
    int n=6;
   
    xapxep(a,sizeof(double),n,hamsosanhungdung1);
 
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
 
    cout<<endl;
    int b[100]={1,2,6,3,5,4};
    int m=6;
    xapxep(b,sizeof(int),m,(int(*)(void*,void*))hamsosanhungdung2);
 
        for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
 
    getch();
}
```

*V. Con trỏ với hàm (quan trọng)*

**1. Overview lại về hàm trong C**

<img src="http://i.imgur.com/OGO7Rsr.jpg">

**2. Sai lầm trong suy nghĩ**

- Có nhiều thật nhiều người nói rằng trong C, ta có thể sử dụng con trỏ trong tham số của hàm như là 1 tham biến, qua hàm ta có thể thay đổi được giá trị của tham số.
- Tôi xin khẳng định lại, điều này thật là 1 hiểu lầm, sai lầm trong suy nghĩ, 1 sự hiểu biết nông cạn, 1 câu phát biểu kiểu ù ù cạc cạc!!!

- Nguyên nhân
	
	- Hàm trong C ko hề có tham biến, hàm trong C đều hoạt động theo nguyên tắc sau :

- Khi gọi hàm, 1 bản sao của tham số được tạo ra (cấp phát vùng nhớ mới, copy giá trị sang. quá trình này theo giáo trình của đại học FPT gọi là shadow copy, là 1 yếu tố cần quan tầm, 1 C/C++ Developer đừng bao giờ quên điều này), và hàm sẽ làm việc với bản sao này (trong C++ nó sẽ dùng hàm tạo sao chép để tiến hành quá trình shadow copy này).

- Vậy khi làm việc với con trỏ thì hàm làm thế nào?

	- Vâng, hàm vẫn cứ làm theo nguyên tắc 1 và 1 bản sao của con trỏ được tạo ra, và hàm làm việc với bản sao hàm, và trước khi gọi hàm con trỏ trỏ vào đâu thì nó vẫn được trỏ vào đấy chứng minh :

```C
#include <stdio.h>
#include <conio.h>
 
int ham(int *a)
{
    *a=2;
    a++;
}
void main()
{
    int *a;
    printf("Truoc : %x",a); //trước và sau khi gọi hàm
    ham(a);                    //con trỏ a trỏ vào đâu
    printf("Sau %x",a);     // thì nó vẫn trỏ vào đó
    getch();
}
```

- Vậy tại sao lại có sự thay đổi và tại sao lại sử dụng con trỏ trong hàm? Con trỏ ko thay đổi thì cái gì thay đổi được ?
	
	- Vâng, các bạn chú ý nhé, giá trị nằm trong vùng nhớ trỏ đến thay đổi. Vâng đúng thế đấy bạn à, do biến của ta nằm trong vùng nhớ được trỏ đến nên nó được thay đổi

```C
#include <stdio.h>
#include <conio.h>
 
int ham(int *a)
{
    *a=2; // làm việc với địa chỉ nhận được
}
void main()
{
    int n;
    ham(&n);// truyền địa chỉ của n vào đây
    // do đó sau hàm này n =2
    getch();
}
```

**3. Sai lầm trong hành động**

- Một trong những sai lầm cơ bản nhưng lại hay gặp đó là ví dụ sau. 
- Sai lầm vì trong hàm chúng ta cấp phát bộ nhớ rồi cho bản sao đang làm việc trỏ đến. ra khỏi hàm rồi thì x của ta vẫn chưa có trỏ vào bộ nhớ nào cả

```C
#include <stdio.h>
#include <conio.h>
 
void nhap(int *a,int n)
{
    //a=new int[n]; //sai lầm
    a=(int*)malloc(n * sizeof(int)); //sai lầm
    for(int i=0;i<n;i++)
        cin>>a[i];
}
void main()
{
    int *x;
    int n=6;
    nhap(x,n);
    //xuat
    delete[] x; // sản sinh ra lỗi run-time , tung là 1 exception, do x chưa trỏ vào đâu mà đòi giải phóng
}
```

*VI. Vậy tôi phải làm thế nào để mà thay đổi giá trị của 1 con trỏ qua 1 hàm*

- Vâng, hôm nay có người bạn hỏi mình như vậy, hì hì, lại nhớ ra bài này mình chưa trả lời, vậy nên tôi đề xuất ra đây 2 cách để có thể thay đổi giá trị của 1 con trỏ qua 1 hàm 
- Cách 1 : dùng tham chiếu trong C++

```C
void ham(int *&a)
{
    a=new int[100];
}
void ham(int **&a)
{
    a=new int*[100];
}
```

- Xin chú ý là * đứng trước &

- Cách 2: up level của * dùng con trỏ cấp cao hơn con trỏ hiện tại
- Cách 2 này mình chỉ demo thôi, bạn cần phải đọc chi tiếp ở chap con trỏ đa cấp

```C
#include <stdio.h>
#include <conio.h>
 
void ham(int **a)
{
    *a=(int*)malloc(100*sizeof(int));
    //a[0]=(int*)malloc(100*sizeof(int));
    // 2 cach nay nhu nay
}
 
void main()
{
    int *a;
    ham(&a);
 
    free(a);
}
```

*VII. Nâng cao về con trỏ hàm,mảng con trỏ hàm và kĩ năng phân tích vấn đề*
- Mời các bạn đọc 3 bài viết sau
- Giải thích ý nghĩa của dòng lệnh khai báo int(*) : http://forums.congdongcviet.com/showthread.php?t=49779
- Kĩ năng phân tích vấn đề : http://forums.congdongcviet.com/showthread.php?p=117404
- So sánh (*ptr)[10] và *ptr[10] trong C! : http://forums.congdongcviet.com/showthread.php?t=34085

####9. Con trỏ đa cấp

*I. Con trỏ đa cấp là gì ?*

- Mình cũng ko rõ định nghĩa của nó , nhưng ta có thể tạm hiểu đó là những con trỏ có dạng 2 hoặc nhiều `*`

ví dụ:

```C
int **a; // cấp 2
char ***b; //cấp 3
int *******************a; //cấp ??
```

- Phép toán trên con trỏ cấp n (n>1 và con trỏ cấp 2 thuần túy như trong ví dụ vừa khai báo trên) tương tự như với con trỏ cấp 1 tương ứng

```C
#include <stdio.h>
#include <conio.h>
 
 
void main()
{
    int **a=NULL;
    printf("%x\n",a); //0x0
    a++;
    printf("%x",a);//0x4
    getch();
}
```

*II. Con trỏ đa cấp dùng để làm gì ?*

- Con trỏ đa cấp dùng để làm gì và tại sao tôi lại phải quan tâm?
	
	- Con trỏ đa cấp thường được dùng trong trường hợp cần thay đổi giá trị của 1 con trỏ cấp thấp hơn khi ra khỏi hàm.
	- Tthật ra thường thì rất ít khi mình và bạn cần đá xoáy vào vấn về này. Tại vì theo như các framework, và như 1 OS core linux mình đã từng làm việc, người ta thường hay dùng con trỏ void với sự linh hoạt rất cao
	- Con trỏ cấp 2 còn được dùng như là "con trỏ" trỏ tới một "con trỏ", có thể dùng để xử lý 1 matrix 2 chiều 
	- Con trỏ cấp 3 còn được dùng như là con trỏ trỏ tới một "con trỏ", mà con trỏ này đang trỏ tiếp tới 1 con trỏ khác có thể dùng như matrix 3 chiều
	- ...v.v

*III. Vài ví dụ hay gặp*

- Trường hợp 1 hay gặp : Xử lý con trỏ mảng các chuỗi:

```C
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
void main(void)
{
    char**  lines;
    int     numberline=10;
    int     linelen=200;
   
    //cấp phát
    //malloc **
    lines=(char**)calloc(1,sizeof(char*)*numberline);
 
    for (int i=0;i<numberline;i++)
    {
        //malloc *
        lines[i]=(char*)calloc(1,linelen);
 
 
        //gán giá trị để demo thôi
        lines[i][0]='A'+i;
    }
 
    //xem giá trị gán mẫu
    for (int i=0;i<numberline;i++)
    {
        printf("%s\n",lines[i]);
    }
 
    //giải phóng
    //free *
    for (int i=0;i<numberline;i++) free(lines[i]);
    //free **
    free(lines);
 
    getch();
}
```

- Trường hợp 2 hay gặp : Xử lý con trỏ mảng các chuỗi cấp phát bằng hàm

```C
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
void HamCapPhat(char*** lines,int numberline,int linesize)
{
    //malloc **
    (*lines)=(char**)calloc(1,sizeof(char*)*numberline);
   
    for (int i=0;i<numberline;i++)
    {
        //malloc *
        (*lines)[i]=(char*)calloc(1,linesize);
 
 
        //gán giá trị để demo thôi
        (*lines)[i][0]='A'+i;
    }
}
void HamGiaiPhong(char** lines,int numberline)
{
    //free *
    for (int i=0;i<numberline;i++) free(lines[i]);
    //free **
    free(lines);
}
void main(void)
{
    char**  lines;
    int     numberline=10;
    int     linelen=200;
    //cấp phát bằng hàm
    HamCapPhat(&lines,numberline,linelen);
 
    //xem giá trị gán bằng hàm
    for (int i=0;i<numberline;i++)
    {
        printf("%s\n",lines[i]);
    }
 
    //giải phóng bằng hàm
    HamGiaiPhong(lines,numberline);
 
    getch();
}
```

- Trường hợp 3 hay gặp : Xử lý con trỏ int ** (float **, double **, ????? ** tương tự nhé)

```C
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
void main(void)
{
    int**   array;
    int     sodong=10;
    int     socot=200;
   
    //cấp phát bằng hàm
    //malloc **
    array=(int**)calloc(1,sizeof(int*)*sodong);
 
    for (int i=0;i<sodong;i++)
    {
        //malloc *
        array[i]=(int*)calloc(1,socot);
    }
 
    //giải phóng
    //free *
    for (int i=0;i<sodong;i++) free(array[i]);
    //free **
    free(array);
 
    getch();
}
```
