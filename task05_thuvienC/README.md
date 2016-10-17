###Tìm hiểu các thư viện chuẩn của C

> Tài liệu tham khảo: [Thư viện của C](http://diendan.congdongcviet.com/threads/t5490::thu-vien-c-cac-ham-trong-thu-vien-chuan-kem-vi-du.cpp)
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 17.10.2016

----

###Mục Lục

- [1. Thư viện của C là gì? Thiết kế ra sao?](#concept)
- [2. Chuẩn ANSI](#ANSI)
- [3. Các tập tin tiêu đề của chuẩn ANSI C](#standarANSI)
- [4. Các hàm cơ bản của các thư viện trong C](#libary)
	- [4.1 Stdio](#stdio)
	- [4.2 Math](#math)
	- [4.3 Float](#float)
	- [4.4 String](#string)

----

<a name="concept"> </a>

###1. Thư viện của C là gì? Thiết kế ra sao?

- Khái niệm:

	- Thư viện chuẩn C ngày nay là một tập hợp của các tập tin tiêu đề và thư viện các thủ tục được tiêu chuẩn hóa dùng để thiết lập các pháp toán tổng quát, như là việc xử lí I/O và dãy kí tự trong C. Khác với Pascal hay PL/I, C không bao hàm sẵn các từ khoá để dùng cho tác thao tác, và như vậy, hầu như mọi chương 
	trình C đều phụ thuộc vào thư viện chuẩn để hoạt động.

- Thiết kế: 

	- Tên và đặc tính của mỗi hàm trong C được chứa trong một tập tin gọi là tập tin tiêu dề nhưng sự kiến tạo thực sự của các hàm này được phân chia vào trong các tập tin thư viện. Tên và nội hàm của các tiêu đề đã trở nên thông dụng nhưng tổ chức của các thư viện này vẫn còn phân hoá. Thư viện chuẩn thường được ban hành chung với một trình dịch. Vì các trình dịch C thường hay cung cấp thêm các chức năng không có trong tiêu chuẩn ANSI C, nên một thư viện chuẩn của một trình dịch đặc thù hầu như sẽ không tương thích với các thư viện chuẩn của trình dịch khác.

	- Nhiều phần thư viện chuẩn C cho thấy việc thiết kế chúng rất tốt. Tuy nhiên, một số ít, cho thấy điểm yếu sau khi dược dùng rộng rãi như là hàm đọc từ đầu vào `gets()` (và cũng như hàm `scanf()` đọc dãy kí tự từ đầu vào) là một nguyên nhân của nhiều lỗi tràn bộ nhớ đệm, và hầu hết các sách hướng dẫn đều khuyến cáo tránh dùng chúng. Một khuyết điểm nữa là hàm `strtok()` được thiết kế như là một phân tích từ điển cơ bản nhưng rất khó dùng và dễ bị hỏng.

<a name="ANSI"> </a>

###2. Chuẩn ANSI:

- Thư viện chuẩn ANSI bao gồm 24 tiêu đề C mà có thể được bao gồm trong một đề án của người lập trình với các chỉ thị (dịch). Mỗi tiêu đề chứa một hay nhiều sự khai báo của hàm, sự định nghĩa của kiểu dữ liệu và các macro. Nội dung của các tiêu đề như sau:

	- Thư viện chuẩn thì không được viết hoa. Nó cung cấp tập hợp cơ bản các hàm toán, điều chỉnh dãy kí tự, chuyển đổi kiểu, và các I/O cơ sở. Nó không bao gồm một tập hợp chuẩn các "kiểu thùng chứa" như trong Thư viện chuẩn C++. Nó cũng không bao gồm các bộ công cụ GUI, các công cụ mạng, và những chức năng phong phú khác như Java đã cung cấp. Lợi thế chính của một thư viện chuẩn cỡ nhỏ là nó cung ứng một môi trường làm việc của ANSI C dễ dàng hơn so với các ngôn ngữ khác, và hậu quả là việc xuất chưong trình C sang một nền tảng mới tương đối dễ dàng hơn.
	- Nhiều thư viẹn đã được phát triển để cung cấp chức năng tương đương với những thứ mà ngôn ngữ khác có trong thư viện chuẩn. Thí dụ môi trường của đề án GNOME phát triển bộ công cụ đồ họa GTK và glib, một thư viện của thùng chứa các cấu trúc dữ liệu, và có rất nhiều thí dụ nổi tiếng khác. Nhiều thư viện có ý nghĩa với các bộ công cụ tuyệt vời đã tự chứng tỏ qua lịch sử. Một điểm đáng lưu tâm là các công cụ này thường không tương thích nhau, những người lập trình thường quen với sự khác nhau của các bộ thư viện này, và một bộ công cụ có thể khả dụng trong bất kì nền tảng nào.

<a name="standarANSI"> </a>

###3. Các tập tin tiêu đề của chuẩn ANSI C:

- **`<assert.h>`**: Bao gồm macro assert dùng để hỗ trợ trong việc phát hiện các lỗi lô-gíc và các kiểu lỗi khác trong các phiên bản dùng để tìm lỗi của một chương trình.
- **`<complex.h>`**: Một tập hợp các hàm dùng để điều chỉnh các số phức (mới có trong chuẩn C99).
- **`ctype.h>`**: bao gồm các hàm dùng để phân lớp các kí tự bởi các kiểu hay dùng để chuyển đổi giữa chữ viết hoa và viết thường.
- **`<errno.h>`**: Dùng để thử (hay hiển thị) các lỗi được báo cáo từ các hàm thư viện.
- **`<fenv.h>`**: Dùng để kiểm soát môi trường chấm động (mới có trong C99).
- **`<float.h>`**: Bao gồm định nghĩa các hằng mà nêu ra các đặc tính xây dựng của thư viện chấm động, như là sự khác nhau nhỏ nhất của hai số chấm động (có thể có) qua _EPSILON, số lớn nhất của các chữ số của độ chính xác qua _DIG và khoảng cách của các số mà có thể biểu thị được qua _MIN và _MAX.
- **`<inttypes.h>`**: Dùng cho việc chuyển đổi kiểu chính xác giữa các kiểu nguyên (mới có trong C99).
- **`<iso646.h>`**: Để lập trình trong ISO 646 cho các bộ kí tự khác nhau (mới có trong NA1).
- **`<limits.h>`**: Chứa định nghĩa các hằng có đặc tính đặc biệt của các kiểu nguyên, như là khoảng cách của các số mà có thể biểu thị quan _MIN, _MAX.

Contains defined constants specifying the implementation-specific properties of the integer types, such as the range of numbers which can be represented (_MIN, _MAX).

- **`<locale.h>`**: Dùng cho setlocale() và các hằng có liên quan. Việc này được dùng để lựa chọn địa phương cần thiết.
- **`<math.h>`**: Cho việc tính các hàm số thông dụng.
- **`<setjmp.h>`**: Khai báo setjump/longjump đưuợc dùng trong việc thoát ra của nơi không có tính địa phương.
- **`<signal.h>`**: Để kiểm soát các điều kiện ngoại lệ.
- **`<stdarg.h>`**: Để truy cập số lượng khác nhau của các đối số được chuyển vào hàm.
- **`<stdbool.h>`**: Dùng cho khiểu dữ liệu Bool (mới có trong C99).
- **`<stdint.h>`** : Dùng trong việc định nghĩa các kiểu nguyên khác nhau (mới có trong C99).
- **`<stddef.h>`**: Cung cấp nhiều kiểu và macro hữu dụng.
- **`<stdio.h>`**: Cung cấp cốt lõi của những khả năng nhập trong C. Tập tin này bao gồm họ hàm printf.
- **`<stdlib.h>`**: Dùng để xúc tiến nhiều phép toán, bao gồm sự chuyển đổi, các số giả ngầu nhiên, cấp phát vùng nhớ, kiểm soát quá trình, môi trường, tín hiệu, tìm kiếm, và xếp thứ tự.
- **`<string.h>`**: Để điều chỉnh nhiều loại dãy kí tự.
- **`<tgmath.h>`**: Dùng cho các hàm toán kiểu thông dụng (mới có trong C99).
- **`<time.h>`**: Để chuyển đổi giữa các định dạng khác nhau về thì giờ và ngày tháng.
- **`<wchar.h>`**: Để điều chỉnh độ rộng của các dòng (dữ liệu) và nhiều loại dãy kí tự sử dụng nhiều (loại) kí tự có độ lớn (Unicode chẳng hạn). -- Đây là chìa khóa để hỗ trợ nhiều ngôn ngữ (mới có trong NA1).
- **`<wctype.h>`**: Để phân lớp các kí tự có độ lớn (mới có trong NA1).

<a name ="libary"> </a>

###4. Các hàm cơ bản của các thư viện trong C:

<a name ="stdio"> </a>

####Stdio.h:

- Header file có tên stdio.h trong Thư viện C chuẩn định nghĩa 3 kiểu biến, một số macro và các hàm đa dạng để thực hiện input và output.

*Các biến được định nghĩa trong stdio.h*

- Dưới đây liệt kê một số kiểu biến được định nghĩa trong stdio.h trong Thư viện C:

	- 1. size_t
	- Đây là kiểu nguyên không dấu và là kết quả của từ khóa sizeof

	- 2. FILE
	- Đây là một kiểu đối tượng phù hợp để lưu trữ thông tin cho một File Stream

	- 3. fpos_t
	- Đây là một kiểu đối tượng phù hợp để lưu trữ bất cứ vị trí nào trong một File

######Các macro được định nghĩa trong stdio.h

Dưới liệt kê một số Macro được định nghĩa trong stdio.h trong Thư viện C:

**1	NULL**
Macro này là giá trị của một hằng con trỏ null

**2	_IOFBF, _IOLBF và _IONBF**
Đây là các macro mà phát triển các biểu thức hằng số nguyên với các giá trị riêng biệt và phù hợp để sử dụng như là tham số thứ ba cho hàm setvbuf

**3	BUFSIZ**
Macro này là một số nguyên, mà biểu diễn kích cỡ của Buffer được sử dụng bởi hàm setbuf

**4	EOF**
Macro này là một số nguyên âm, chỉ rằng đã đến End-Of-File

**5	FOPEN_MAX**
Macro này là một số nguyên, biểu diễn số file tối đa mà hệ thống có thể bảo đảm để được mở một cách đồng thời

**6	FILENAME_MAX**
Macro này là một số nguyên, biểu diễn length dài nhất của một mảng ký tự phù hợp để lưu trữ filename dài nhất có thể. Nếu trình triển khai là không giới hạn, thì giá trị này nên là giá trị tối đa được đề nghị

**7	L_tmpnam**
Macro này là một số nguyên, biểu diễn length dài nhất của một mảng ký tự phù hợp để lưu trữ filename tạm thời dài nhất có thể mà được tạo bởi hàm tmpnam

**8	SEEK_CUR, SEEK_END, và SEEK_SET**
Macro này được sử dụng trong hàm fseek để xác định các vị trí khác nhau trong một File

**9	TMP_MAX**
Macro này là số tối đa các filename duy nhất mà hàm tmpnam có thể tạo

**10	stderr, stdin, và stdout**
Các macro này là các con trỏ tới các kiểu FILE tương ứng với Standard Error, Standard Input và Standard Output Stream

######Các hàm được định nghĩa trong stdio.h
Sau đây là một số hàm được định nghĩa trong stdio.h trong Thư viện C:

Khi truy cập link để theo dõi các ví dụ, bạn chú ý rằng file được tạo trong hàm đầu tiên sẽ được sử dụng trong các hàm tiếp theo.

1	
**Hàm int fclose(FILE *stream)**

Đóng Stream. Tất cả Buffer (bộ đệm) bị Flush (xóa sạch hoặc chuyển hết ra ngoại vi)

2	
**Hàm void clearerr(FILE *stream)**

Xóa end-of-file và error indicator cho Stream đã cho

3	
**Hàm int feof(FILE *stream)**

Kiểm tra end-of-file indicator cho Stream đã cho

4	
**Hàm int ferror(FILE *stream)**

Kiểm tra error indicator cho Stream đã cho

5	
**Hàm int fflush(FILE *stream)**

Flush bộ đệm đầu ra của một Stream

6	
**Hàm int fgetpos(FILE *stream, fpos_t *pos)**

Lấy vị trí file hiện tại của Stream và ghi nó tới pos

7	
**Hàm FILE *fopen(const char *filename, const char *mode)**

Mở tên file được trỏ tham số filename bởi sử dụng chế độ mode đã cho

8	
**Hàm size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream)**

Đọc dữ liệu từ Stream đã cho trong mảng được trỏ bởi ptr

9	
**Hàm FILE *freopen(const char *filename, const char *mode, FILE *stream)**

Gắn kết một filename mới với Stream đã cho và cùng lúc đó đóng FILE cũ trong Stream

10	
**Hàm int fseek(FILE *stream, long int offset, int whence)**

Thiết lập vị trí file của Stream tới offset đã cho. Tham số offset xác định số byte để tìm kiếm từ vị trí where đã cho

11	
**Hàm int fsetpos(FILE *stream, const fpos_t *pos)**

Thiết lập vị trí file của stream đã cho tới vị trí đã cho. Tham số pos là một vị trí được cung cấp bởi hàm fgetpos

12	
**Hàm long int ftell(FILE *stream)**

Trả về vị trí file hiện tại của Stream đã cho

13	
**Hàm size_t fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)**

Ghi dữ liệu từ mảng được trỏ bởi ptr tới Stream đã cho

14	
**Hàm int remove(const char *filename)**

Xóa filename đã cho để nó không thể truy cập được nữa

15	
**Hàm int rename(const char *old_filename, const char *new_filename)**

Làm cho filename được tham chiếu tới, được thay đổi từ old_filename thành new_filename

16	
**Hàm void rewind(FILE *stream)**

Thiết lập vị trí file tới phần đầu của file trong Stream đã cho

17	
**Hàm void setbuf(FILE *stream, char *buffer)**

Định nghĩa cách một Stream nên được đệm (buffer)

18	
**Hàm int setvbuf(FILE *stream, char *buffer, int mode, size_t size)**

Một hàm khác để xác định cách một Stream nên được đệm (buffer)

19	
**Hàm FILE *tmpfile(void)**

Tạo file tạm thời trong chế độ wb+

20	
**Hàm char *tmpnam(char *str)**

Tạo và trả về một filename tạm thời hợp lệ (chưa tồn tại trước khi tạo)

21	
**Hàm int fprintf(FILE *stream, const char *format, ...)**

Gửi output đã được định dạng tới một Stream

22	
**Hàm int printf(const char *format, ...)**

Gửi output đã được định dạng tới một stdout

23	
**Hàm int sprintf(char *str, const char *format, ...)**

Gửi output đã được định dạng tới một chuỗi string

24	
**Hàm int vfprintf(FILE *stream, const char *format, va_list arg)**

Gửi output đã được định dạng tới một stream bởi sử dụng một danh sách tham số

25	
**Hàm int vprintf(const char *format, va_list arg)**

Gửi output đã được định dạng tới một stdout bởi sử dụng một danh sách tham số

26	
**Hàm int vsprintf(char *str, const char *format, va_list arg)**

Gửi output đã được định dạng tới một chuỗi string bởi sử dụng một danh sách tham số

27	
**Hàm int fscanf(FILE *stream, const char *format, ...)**

Đọc input đã được định dạng từ một Stream

28	
**Hàm int scanf(const char *format, ...)**

Đọc input đã được định dạng từ stdin

29	
**Hàm int sscanf(const char *str, const char *format, ...)**

Đọc input đã được định dạng từ một chuỗi string

30	
**Hàm int fgetc(FILE *stream)**

Lấy ký tự kế tiếp (một unsigned char) từ Stream đã cho và tăng position indicator cho Stream đó

31	
**Hàm char *fgets(char *str, int n, FILE *stream)**

Đọc một dòng từ Stream đã cho và lưu trữ nó vào trong chuỗi được trỏ bởi str. Nó dừng khi gặp bất cứ điều kiện nào sau: (n-1) ký tự đã được đọc, ký tự newline (dòng mới) được đọc hoặc bắt gặp end-of-file

32	
**Hàm int fputc(int char, FILE *stream)**

Ghi một ký tự (một unsigned char) đã được xác định bởi tham số char tới Stream đã cho và tăng position indicator cho Stream

33	
**Hàm int fputs(const char *str, FILE *stream)**

Ghi một chuỗi tới Stream đã xác định (không ghi ký tự null)

34	
**Hàm int getc(FILE *stream)**

Lấy ký tự kế tiếp (một unsigned char) từ Stream đã cho và tăng position indicator cho Stream đó

35	
**Hàm int getchar(void)**

Lấy một ký tự (một unsigned char) từ stdin

36	
**Hàm char *gets(char *str)**

Đọc một dòng từ stdin và lưu trữ nó bên trong chuỗi được trỏ bởi str. Nó dừng khi bắt gặp end-of-file hoặc ký tự newline (dòng mới) được đọc

37	
**Hàm int putc(int char, FILE *stream)**

Ghi một ký tự (một unsigned char) được xác định bởi tham số char tới Stream đã cho và tăng position indicator cho Stream đó

38	
**Hàm int putchar(int char)**

Ghi một ký tự (một unsigned char) đã được xác định bởi tham số char tới stdout

39	
**Hàm int puts(const char *str)**

Ghi một chuỗi str tới stdout (không ghi ký tự null). Một ký tự newline (dòng mới) được phụ thêm tới output

40	
**Hàm int ungetc(int char, FILE *stream)**

Đẩy ký tự char (là một unsigned char) lên trên Stream đã cho để mà ký tự kế tiếp được đọc

41	
**Hàm void perror(const char *str)**

In một thông điệp mô tả lỗi tới stderr. Đầu tiên thì chuỗi str được in được theo sau bởi một dấu hai chấm và sau đó là một space

<a name="math"> </a>

####Math.h:

- Header file có tên math.h trong Thư viện C định nghĩa các hàm toán học đa dạng và một macro. Tất cả các hàm có sẵn trong thư viện này nhận double như là một tham số và trả về kết quả ở kiểu double.

######Các macro được định nghĩa trong math.h

Chỉ có một Macro được định nghĩa trong thư viện này:

**1	HUGE_VAL**
Macro này được sử dụng khi kết quả của một hàm không thể biểu diễn dưới dạng một số thực dấu chấm động. Nếu độ lớn để biểu diễn chính xác kết quả là quá lớn, thì hàm thiết lập errno thành ERANGE để chỉ một Range Error, và trả về một giá trị đủ lớn, cụ thể được đặt tên bởi HUGE_VAL hoặc đối của nó là – HUGE_VAL.

Nếu độ lớn của kết quả là quá nhỏ, thì một giá trị 0 được trả về. Trong trường hợp này, errno có thể hoặc không thể được thiết lập thành ERANGE.

######Các hàm được định nghĩa trong math.h

Sau đây là một số hàm được định nghĩa trong math.h trong Thư viện C:

1	
**Hàm double acos(double x)**

Trả về arcos của x (giá trị radian)

2	
**Hàm double asin(double x)**

Trả về arcsin của x (giá trị radian)

3	
**Hàm double atan(double x)**

Trả về arctan của x (giá trị radian)

4	
**Hàm double atan2(doubly y, double x)**

Trả về arctan của y/x (giá trị radian)

5	
**Hàm double cos(double x)**

Trả về cos của góc x (giá trị radian)

6	
**Hàm double cosh(double x)**

Trả về cosh (hàm hyperbolic cosin) của x (giá trị radian)

7	
**Hàm double sin(double x)**

Trả về sin của góc x (giá trị radian)

8	
**Hàm double sinh(double x)**

Trả về sinh (hàm hyperbolic sin) của x (giá trị radian)

9	
**Hàm double tanh(double x)**

Trả về tanh (hàm hyperbolic tan) của x (giá trị radian)

10	
**Hàm double exp(double x)**

Trả về ex

11	
**Hàm double frexp(double x, int *exponent)**

Giá trị được trả về là mantissa (phần định trị) và số nguyên được trỏ tới bởi exponent (số mũ). Giá trị kết quả là x = mantissa * 2 ^ exponent

12	
**Hàm double ldexp(double x, int exponent)**

Trả về x*2exponent

13	
**Hàm double log(double x)**

Trả về lnx

14	
**Hàm double log10(double x)**

Trả về log10(x)

15	
**Hàm double modf(double x, double *integer)**

Trả về phần thập phân của x

16	
**Hàm double pow(double x, double y)**

Trả về xy

17	
**Hàm double sqrt(double x)**

Trả về căn bậc hai của x

18	
**Hàm double ceil(double x)**

Trả về giá trị nguyên nhỏ nhất lớn hơn hoặc bằng x

19	
**Hàm double fabs(double x)**

Trả về trị tuyệt đối của x

20	
**Hàm double floor(double x)**

Trả về giá trị nguyên lớn nhất nhỏ hơn hoặc bằng x

21	
**Hàm double fmod(double x, double y)**

Trả về phần dư của phép chia x/y

<a name="float"></a>

#####Float.h

- Header file có tên float.h của Thư viện C chứa một tập hợp các hằng số đa dạng (phụ thuộc vào nền tảng) liên quan tới các giá trị số thực dấu chấm động. Các hằng này được đề xuất bởi ANSI C. Trước khi tìm hiểu các hằng này, bạn cần biết số thực dấu chấm động gồm 4 thành phần:

| Thành phần | Miêu tả |
|------------|---------|
| S | Dấu ( +/- ) |
| b | Biểu diễn cơ số (base): hệ nhị phân là 2, thập phân là 10, thập lục phân là 16, … |
| e | Số mũ (exponent), một số nguyên giữa emin và emax |
| p | Số ký tự thập phân có nghĩa (Precision) |

Dựa vào 4 thành phần trên, một số thực dấu chấm động sẽ có giá trị của nó được biểu diễn như sau:

- số thực dấu chấm động = ( S ) p x be

hoặc

- số thực dấu chấm động = (+/-) precision x baseexponent

######Các macro được định nghĩa trong float.h

Các giá trị sau là trình triển khai riêng và được định nghĩa với chỉ thị #define, nhưng các giá trị này không thể là chữ thường. Ghi chú rằng, tất cả FLT tham chiếu tới kiểu float, DBL tham chiếu tới double và LDBL tham chiếu tới long double.


**FLT_ROUNDS:** Định nghĩa chế độ làm tròn cho phép cộng số thực dấu chấm động và nó có thể có bất kỳ giá trị nào sau đây:
`-1 − Không xác định`

`0 − Làm tròn về 0`

`1 − Làm tròn về giá trị gần nhất`

`2 − Hướng về dương vô cực`

`3 − Hướng về âm vô cực`

**FLT_RADIX 2**	Định nghĩa biểu diễn cơ số của số mũ. Base-2 là hệ nhị phân, base-10 là hệ thập phân, …

**FLT_MANT_DIG**

**DBL_MANT_DIG**

**LDBL_MANT_DIG**

- Các macro này định nghĩa số chữ số để biểu diễn số thực (trong FLT_RADIX base)

**FLT_DIG 6**

**DBL_DIG 10**

**LDBL_DIG 10**

- Các macro này xác định số chữ số thập phân tối đa (base-10) có thể được biểu diễn mà không thay đổi sau khi làm tròn

**FLT_MIN_EXP**

**DBL_MIN_EXP**

**LDBL_MIN_EXP**

- Các macro này xác định giá trị nguyên âm nhỏ nhất cho số mũ (exponent) trong cơ số FLT_RADIX

**FLT_MIN_10_EXP -37**

**DBL_MIN_10_EXP -37**

**LDBL_MIN_10_EXP -37**

- Các macro này xác định giá trị nguyên âm nhỏ nhất cho một số mũ (exponent) trong cơ số 10

**FLT_MAX_EXP**

**DBL_MAX_EXP**

**LDBL_MAX_EXP**

- Các macro này xác định giá trị nguyên lớn nhất cho một số mũ (exponent) trong cơ số FLT_RADIX

**FLT_MAX_10_EXP +37**

**DBL_MAX_10_EXP +37**

**LDBL_MAX_10_EXP +37**

- Các macro này xác định giá trị nguyên lớn nhất cho một số mũ (exponent) trong cơ số 10

**FLT_MAX 1E+37**

**DBL_MAX 1E+37**

**LDBL_MAX 1E+37**

- Các macro này xác định giá trị số thực dấu chấm động lớn nhất

**FLT_EPSILON 1E-5**

**DBL_EPSILON 1E-9**

**LDBL_EPSILON 1E-9**

- Các macro này xác định chữ số có nghĩa tối thiểu mà có thể biểu diễn được

**FLT_MIN 1E-37**

**DBL_MIN 1E-37**

**LDBL_MIN 1E-37**

- Các macro này định nghĩa các giá trị số thực dấu chấm động nhỏ nhất

Ví dụ
Chương trình C sau minh họa cách sử dụng của một số hằng được định nghĩa trong float.h.

`#include <stdio.h>`

`#include <float.h>`

`int main()`

`{`

`  printf("Gia tri max cua mot so thuc = %.10e\n", FLT_MAX);`

`  printf("Gia tri min cua mot so thuc = %.10e\n", FLT_MIN);`

`  printf("So ky so de bieu dien mot so = %.10e\n", FLT_MANT_DIG);`

`}`

- Kết quả:

<img src="http://i.imgur.com/Ql8u5yY.png">

<a name="string"> </a>

#####String

**Hàm và mục đích các hàm**

1	**strcpy(s1, s2);**
Sao chép chuỗi s2 cho chuỗi s1.

2	**strcat(s1, s2);**
Nối chuỗi s2 vào cuối chuỗi s1.

3	**strlen(s1);**
Trả về độ dài của chuỗi s1.

4	**strcmp(s1, s2);**
Trả về 0 nếu s1 và s2 là như nhau; nhỏ hơn 0 nếu s1<s2; lớn hơn 0 nếu s1>s2.

5	**strchr(s1, ch);**
Trả về con trỏ tới vị trí đầu tiên của ch trong s1.

6	**strstr(s1, s2);**
Trả về con trỏ tới vị trí đầu tiên của chuỗi s2 trong chuỗi s1.

###Hết
