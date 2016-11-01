### Tìm hiểu về con trỏ trong C

> Tài liệu tham khảo: [Con Trỏ](http://diendan.congdongcviet.com/threads/t42977::tim-hieu-ban-chat-cua-con-tro-tu-co-ban-den-nang-cao.cpp)
>
> Thực hiện bởi : Phạm Phú Quí
> 
> Cập nhật lần cuối : 29.10.2016

----

###Mục Lục

- [1. Cấp phát bộ nhớ](#capphatbonho)

----


<a name "capphatbonho"> </a>

###1. Vấn đề cấp phát bộ nhớ

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

**>>>>> khi ta xin cấp phát xong thì vùng nhớ đó hoàn toàn có giá trị ngẫu nhiên**


+ Nếu như khi anh ta xin cấp phát mà có đút lót để ra thêm điều kiện hoặc trước đó anh ta có thuê thêm 1 người quét dọn xây sửa thì anh sẽ có được 1 mảnh đất có sẵn cái anh ta muốn

**>>>> khi ta cấp phát đi cùng với ép buộc sẽ được vùng nhớ có giá trị như ta mong muốn**

ví dụ 

```C
int *a=new int(4);
int *b=(int*)malloc(1000);
memset(b.....);
static int x[1000];
static int y[10]={1,2,3,4,5,6};
```

**<<<<<<<< toàn bộ điều này là đáp án tại sao khi cấp phát bộ nhớ lại có giá trị ngẫu nhiên**

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

*<<< điều này giải thích cho cách hiểu sai lầm của 1 số bạn mới học đối với việc cấp phát và giải phóng*

**4. Memory leak**

- Câu hỏi mở rộng :

- Như thế này có phải là giải phóng ko

```C
 int*x=new int[20];
 x=NULL;  <<<<< như thế này có phải là giải phóng ko 
```

Ở trong C (not java, java khác) thì :
- Câu trả lời là không , bạn đã hiểu sai lầm hoàn toàn về việc giải phóng rồi, bạn nên đọc kĩ lại phần giải phóng để hiểu tại sao. 
như thế này chính là :
	- Anh ta đánh mất cái quyền sử dụng đất của mình, kết quả là vùng đất đó ko được sở lấy về, sau nhiều lần như thế thì tài nguyên đất của sở càng ngày càng ít đi, hiện tượng này gọi mà memory leak


- Sau khi chương trình kết thúc , việc bộ nhớ xin cấp phát có được tự giải phóng hay ko thì tùy thuộc vào cài đặt của trình biên dịch và hệ điều hành. Chúng ta có 2 khả năng · Khả năng 1 : trong phần khởi động (trước khi vào function main() ), program xin một khối memory cuả system gọi là XXXX và mỗi lần malloc được gọi thì cấp pháp một phần memory cuả XXXX cho malloc. Do đó, khi program exit thì trả XXXX về cho system là xong. Trong trường hợp này không bị mất memory
Khả năng 2 : mỗi lần malloc được gọi thì xin memory từ system . Trường hợp này có thể memory không trả về cho system. Lúc này chương trình sẽ bị gọi là có memory leak.Như vậy sau vài lần chạy sẽ ko còn memory để cấp phát nữa

- Đó là giải thích tại sao có nhiều chương trình chạy xong, thoát ra rồi, f5 mấy lần rồi mà máy vẫn cứ ì ì ì ra..........

