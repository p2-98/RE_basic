###Mô phỏng ATM

> Tài liệu tham khảo: Giáo trình lập trình C - PVA
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 27 - 12 - 2016

----

###Mục lục

- [1. Giới thiệu chương trình](#intro)
- [2. Giới thiệu các module](#introModuel)
- [3. Chi tiết các module](#mainModuel)
	
	- [3.1 Đăng nhập - Đăng ký](#sign)
	- [3.2 Màn hình chính](#scrmain)

		- [3.2.1 Rút tiền](#rt)
		- [3.2.2 Thông tin tài khoản](#tttk)
		- [3.2.3 Chuyển khoản](#ck)
		- [3.2.4 Đổi mật khẩu](#dmk)
		- [3.2.5 Tra cứu dịch vụ](#tcdv)

----

<a name="intro"> </a>

###1. Giới thiệu chương trình:

- Chương trình mô phỏng ATM được viết ra nhằm nâng cao kỹ năng viết code cũng như cũng cố lại phần kiến thức đã học và phát triển thêm nhiều kiến thức mới

- Ưu điểm:

	- Xây dựng giao diện dễ nhìn
	- Xử lý thông tin nhanh chóng
	
- Nhược điểm:

	- Chưa thể cập nhật tức thời phần sao kê tài khoản (còn nhiều lỗ hỏng)
	- Giao diện không bắt mắt
	- Độ bảo mật không được đánh giá cao

<a name="introModuel"> </a>

###2. Giới thiệu các Moduel:

- Chương trình mô phỏng máy ATM gồm có các moduel như sau

	- Màn hình đăng nhập - đăng ký:

<img src="http://i.imgur.com/gjvkjl1.png">
	
	- Khi nhấn vào đăng nhập bạn sẽ thấy xuất hiện 1 khung đăng nhập như sau:

<img src="http://i.imgur.com/EuDB60X.png">

	- Sau khi đăng nhập bạn sẽ thấy được màn hình chính bao các thành phần như sau:

<img src="http://i.imgur.com/1ImYJlp.png">

<a name="mainModuel"> </a>

###3. Chi tiết các Moduel:

- Sau đây, mình sẽ giới thiệu chi tiết các về các Moduel:

<a name="sign"> </a>

####3.1 Đăng nhập - Đăng ký:

- Khi bạn khởi động chương trình mô phỏng ATM, ban đầu bạn sẽ thấy được màn hình gồm 2 thành phần đăng nhập và đăng ký như sau:

<img src="http://i.imgur.com/gjvkjl1.png">

- **ĐĂNG NHẬP**

- Khi bạn ấn nút b, cũng có nghĩa là chọn phần Sign in (Đăng nhập), lúc này màn hình sẽ xuất hiện 1 giao diện bao gồm nhập ID CODE

<img src="http://i.imgur.com/EuDB60X.png">

- Lúc này bạn nhập vào ID CODE mà chương trình của mình đã cung cấp lúc bạn đăng ký, mình sẽ demo thử khi bạn nhập đúng và sai ID CODE thì sẽ như thế nào:

	- Demo: ID CODE: 1234 ; Pass: 123456

	- Sai ID CODE: Chương trình sẽ tự động yêu cầu bạn nhập lại

<img src="http://i.imgur.com/e5W0seH.png">

	- Đúng ID CODE: Chương trình sẽ xuất hiện phần PASS (Mật khẩu) để bạn đăng nhập vào màn hình chính

<img src="http://i.imgur.com/bGpOXvx.png">

	- Tiếp đó sẽ là trường hợp sai PASS, bạn sẽ phải nhập lại từ phần ID CODE

<img src="http://i.imgur.com/Ufo9hPp.png">

	- Khi đúng chương trình sẽ tự động chuyển sang màn hình chính trong vòng 2s

- **ĐĂNG KÝ**

- Đầu tiên sẽ là ID và Pass của chính Admin:

<img src="http://i.imgur.com/YXuFbqL.png">

- Tiếp đó là xây dựng các thông tin khách hàng thông qua bàn phím:

<img src="http://i.imgur.com/LdO9GPH.png">

<img src="http://i.imgur.com/pdajeaB.png">

- Id Code sẽ được sinh ra một cách ngẫu nhiên và thông qua sự kiểm tra xem nó có tồn tại hay chưa:

<img src="http://i.imgur.com/7kozPhA.png">

<img src="http://i.imgur.com/a2J7Hbu.png">

<img src="http://i.imgur.com/wDdrR1a.png">

<img src="http://i.imgur.com/VRDFuLV.png">

<a name="scrmain"></a>

####3.2 Màn hình chính:

- Khi bạn đăng nhập thành công, đồng nghĩa với quá trình bắt đầu tiến hành giao dịch trong màn hình chính, lúc này bạn sẽ thấy được màn hình chính bao gồm các chức năng tương tự một máy ATM thực sự:

<img src="http://i.imgur.com/1ImYJlp.png">

- Và chúng ta sẽ bắt đầu làm việc với từng chức năng một:

<a name="rt"> </a>

#####3.2.1 Rút tiền:

- Khi bạn nhấn vào chữ "a", tức là sẽ tiến hành quá trình rút tiền từ tài khoản với các mệnh giá quy định sẵn hoặc số tiền tuỳ ý (lớn hơn 50.000)

<img src="http://i.imgur.com/NYZB9Lw.png">

- Ví dụ bạn muốn rút 500.000, khi đó bạn sẽ nhấn vào chữ 'a' và màn hình sẽ xuất hiện 1 dòng thông báo đang xử lý, tiếp đến là thông báo tiếp tục giao dịch hoặc hoàn tất quá trình giao dịch

<img src="http://i.imgur.com/xBxUYc9.png">

<img src="http://i.imgur.com/Os5QkLL.png">

- Khi bạn ấn vào nút Có (chữ b), chương trình sẽ đưa bạn về màn hình chính, ngược lại chữ e tức Không, chương trình sẽ tự động đăng xuất và đưa về màn hình đăng nhập

<a name="tttk"> </a>

#####3.2.2 Thông tin tài khoản:

- Khi vào bạn mục này, bạn sẽ xem được số tiền còn trong tài khoản của mình và xem sao kê 5 lần giao dịch gần đây nhất, lưu ý: Khi giao dịch lớn hơn 5 lần thì chức năng lần giao dịch gần nhất mới hoạt động (đây cũng là 1 điểm yếu của mô phỏng, sẽ khắc phục sau):

<img src="http://i.imgur.com/i2rQSLv.png">

<img src="http://i.imgur.com/UztChQL.png">

<a name="ck"> </a>

#####3.2.3 Chuyển khoản:

- Phần chuyển khoản được thiết kế chỉ dùng để chuyển khoản trong nội bộ (nhằm kiểm tra toàn diện hơn về chương trình), khi vào phần chuyển khoản bạn sẽ thấy được những giao diện sau:

<img src="http://i.imgur.com/oE9fWeI.png">

<img src="http://i.imgur.com/S7X2fe6.png">

<img src="http://i.imgur.com/X1guHdh.png">

<img src="http://i.imgur.com/EBVSXHn.png">

<a name="dmk"> </a>
#####3.2.4 Đổi mật khẩu:

- Khi vào đổi mật khẩu, bạn sẽ phải thực hiện việc nhập mật khẩu cũ, mật khẩu mới, nhập lại mật khẩu mới (lưu ý: Mật khẩu mới và nhập lại mật khẩu mới phải hoàn toàn trùng khớp nhau, nếu không bạn sẽ phải thực hiện lại từ đầu rất tốn thời gian của bạn)

<img src="http://i.imgur.com/i7bOgCX.png">

<img src="http://i.imgur.com/65VmoM2.png">

<img src="http://i.imgur.com/f6PgXy0.png">

<img src="http://i.imgur.com/d7jFBhO.png">

<img src="http://i.imgur.com/6Lh9yB2.png">

<a name="tcdv"> </a>

#####3.2.5 Tra cứu dịch vụ:

- Đây là phần hiện thông tin cá nhân của người viết mô phỏng

<img src="http://i.imgur.com/sBq2LoG.png">.
