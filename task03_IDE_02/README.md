###Tìm hiểu các IDE C/C++ (Tiếp theo)

> Tài liệu tham khảo: [Tìm hiểu IDE C/C++](http://hocccoban.blogspot.com/2014/02/cc-tong-hop-cac-ide-cho-lap-trinh-c.html)
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 13.10.2016
>

----

[1. Visual Studio C++](#VSC)

- [1.1 Cách cài đặt](#setupVSC)
- [1.2 Tạo New Project trong Studio](#newprojectVSC)

[2. Code::Block](#codeblock)

- [2.1 Cách cài đặt](#setupCB)
- [2.2 Tạo New Project trong Code:Block](#newprojectCB)

----

<a name ="VSC"> </a>

###1. Visual Studio C++

<a name ="setupVSC"> </a>

####1.1 Cách cài đặt:

Chuẩn bị:
- Bộ cài đặt Visual Studio. Có thể tải tại trang chủ của [Microsoft](https://www.visualstudio.com/).
- Một máy tính để cài đặt có kết nối mạng
> Lưu ý Với bộ cài đặt Visual Studio 2015. Trước khi cài đặt các bạn nên update Microsoft .NET Framework lần lượt tới bản mới nhất để việc cài đặt không gặp lỗi.
>
> Bản [Microsoft .NET Framework 4.6.1](https://www.microsoft.com/en-us/download/details.aspx?id=49981)

*Tiến hành download bộ cài đặt VS*
>
>Bộ cài đặt mình dùng trong bài viết là bộ Visual Studio Community 2015. 
>Hệ điều hành sử dụng Windows 10.
>
- Truy cập trang chính thức của [Microsoft](https://www.visualstudio.com/)

<img src ="http://i.imgur.com/DxyhhEu.png">

- Tại giao diện của trang chủ VS, click vào Downloads, chọn mục Top Downloads

<img src="http://i.imgur.com/TJdSXsp.png">

- Tại đây, các bạn có thể click và phần Visual Studio Community để tiến hành tải bản cài đặt.

> Hoặc xem thêm thông tin chi tiết bằng cách click vào phần All downloads

<img src="http://i.imgur.com/lb1qJzi.png">

- Sau khi các bạn đã chọn tải bản cài đặt. Một trang mới sẽ được load

<img src="http://i.imgur.com/1rYZt6z.png">

> Tại đây nếu trình duyệt của bạn vẫn chưa thực hiện tải bản cài đặt thì bạn có thể click vào phần click here to retry để trình duyệt load lại việc tải xuống.

- Khi file cài đặt đã sẵn sàng tải xuống. Các bạn chọn vị trí lưu file cài đặt và nhấn Save

<img src="http://i.imgur.com/91cqsgl.png">

- Việc tải xuống rất nhanh, mất khoảng tầm 2-3s.

<img src="http://i.imgur.com/FObSaka.png">

- Nhấp vào file cài đặt vs_community_ENU.exe

- Sẽ hiện một phần thông báo download các items. Nhưng quá trình load cũng diễn ra rất nhanh

<img src="http://i.imgur.com/T3CoDMt.png">

- Các phần sẽ hiện sau khi load xong file cài đặt

<img src="http://i.imgur.com/BXMUfrz.png">

- Sau đó

<img src="http://i.imgur.com/me2zrpD.png">

- Tiếp theo

<img src="http://i.imgur.com/sLs305b.png">

- Tại đây tùy chỉnh vị trí vị trí cài đặt Visual Studio.
- Tùy chọn *kiểu cài đặt**
> Lưu ý : Nên Chọn kiểu Custom
- Nhấp Install để cài đặt

<img src="http://i.imgur.com/5ZJRnJ6.png">

- Tích các ô tùy chọn muốn cài đặt.
> Lưu ý : Nếu chọn càng nhiều thời gian cài đặt càng lâu.
> Chỉ chọn các cài đặt cần thiết
- Sau đó nhấp Next để quá trình cài đặt bắt đầu.

<img src="http://i.imgur.com/A61BRU6.png">

- Quá trình cài đặt tiếp theo hoàn toàn tự động
> Lưu ý : Vì quá trình cài đặt có thể diễn ra trong thời gian dài. nên bạn có thể rời khỏi khỏi máy tính và làm những công việc khác. 
> Duy trì ổn định nguồn điện của máy và kết nối mạng trong quá trình cài đặt. Để tránh phát sinh lỗi.

<img src="http://i.imgur.com/mx9N5Q2.png">

- Thông báo như vậy là quá trình cài đặt đã thành công
- Nhấn LAUNCH để khởi chạy Visual Studio Community 2015.

** Các lỗi có thể phát sinh trong quá trình cài đặt:

- Trong quá trình cài đặt có thể xảy ra các lỗi không mong muốn. Các bạn có thể tham khảo tại [trang support lỗi trong quá trình cài VS 2015 của Microsoft](https://blog.daynhauhoc.com/cai-dat-visual-studio-2015-de-lap-trinh-c-tren-windows/).

<a name ="newprojectVSC"> </a>

####1.2 Tạo New Project trong Studio:

- Trong giao diện của VS chọn File -> New -> Project (Phím tắt Ctrl + Shift + N)

<img src="http://i.imgur.com/nfycmW3.png">

- Sẽ có một cửa sổ New Project xuất hiện

<img src="http://i.imgur.com/CUTcbag.png">

- Tìm tới phần Visual C++ -> Chọn General -> Empty Project.

	*Tại đây, mình làm project cho C++. Nhưng với các ngôn ngữ khác cũng tạo tương tự như vậy.*

- Bên dưới là phần đặt tên của project và nơi lưu project.

- Name thì các bạn có thể đặt có dấu.

- Location thì mình khuyên là nên tạo riêng từng mục một và đặt ở phần ổ cứng khác với ổ C (với các bạn sử dụng Windows) để tránh việc mất các project quan trọng đã làm.

- Solution name Không nên đặt tên có dấu hoặc kí tự như dấu cách Khi file được chuyển sang các máy khác có thể không hoạt động.

**Sau khi bạn đã tạo một project mới**

<img src="http://i.imgur.com/fPbEiSg.png">

**Có 2 phần các bạn cần để ý là phần :**

- Solution Explorer Tại đây có chứa các mục quan trọng các bạn cần để ý Header File / Source File
- Nếu sau khi tạo xong project mà phần Solution Explorer chưa xuất hiện các bạn có thể click vào View -> Solution Explorer (Ctr+Alt+L)
- Error List: Tại đây có chứa các lỗi gặp phải khi chạy chương trình.
- Cách hiện thanh Error List : Click View -> Error List.

**Tạo file .CPP để thực hiện chương trình**

- Click chuột phải vào Source File -> Add -> New Item (Ctr+Shift+A)

<img src="http://i.imgur.com/nKZjav1.png">

- Một cửa sổ mới sẽ được tạo

<img src="http://i.imgur.com/mBOlnpp.png">

- Chọn C++ File(.cpp) Chưa cần để ý tới phần Header File(.h) vội nha ! Đặt tên cho File mới (.cpp)

- Nháy Add và code thôi

<a name="codeblock"> </a>

###2. Code::Block

<a name="setupCB"> </a>

####2.1 Cách cài đặt

- Link tải về : [Download](http://sourceforge.net/projects/codeblocks/files/Binaries/10.05/Windows/codeblocks-10.05mingw-setup.exe/download)
- Hướng dẫn cài đặt:
	- Chúng ta chỉ cần chọn “Next” và chờ đợi cho tới khi nó chạy xong thì thôi. Các hình ảnh dưới đây minh họa các bước cài đặt CB.
	
<img src ="http://i.imgur.com/iZEbSdW.png">
	
<img src ="http://i.imgur.com/WTlUsAS.png">
	
<img src ="http://i.imgur.com/PCi5AyD.png">
	
<img src ="http://i.imgur.com/wy0Cmv9.png">

<a name ="newprojectCB"> </a>

####2.2 Tạo New Project trong Code:Block

**Tạo một project**

- Để bắt đầu một chương trình, bước đầu tiên là yêu cầu IDE tạo một project. Việc này gần giống như việc bạn yêu cầu Word tạo một văn bản mới.
- Để làm được điều này, bạn hãy chọn File>New>Prọect.

<img src="http://laptrinhtanbinh.com/public/user/1/test1.png">

- Chọn Console application.

<img src="http://laptrinhtanbinh.com/public/user/1/cb-new-project.png">

- Ấn vào Go để tạo một project. Một cửa sổ sẽ mở ra.
- Bạn có thể bỏ qua trang đầu tiên. Hãy ấn Next.
- Bạn được yêu cầu chọn giữa C và C++. Hãy chọn C++

<img src="http://laptrinhtanbinh.com/public/user/1/cb-conf-project.png">

- Bạn được yêu cầu nhập tên của project và thư mục mà bạn muốn lưu các tệp nguồn

<img src="http://laptrinhtanbinh.com/public/user/1/cb-conf-project-1.png">

- Cuối cùng, trang cuối cho phép bạn chọn cách mà chương trình sẽ được biên dịch. Bạn có thể để các option mặc định, điều này sẽ không gây trở ngại gì cho chúng ta vào lúc này. (lưu ý là ít nhất hai option debug và release được tích).

<img src="http://laptrinhtanbinh.com/public/user/1/cb-conf-project-2.png">

- Bạn hãy ấn Finish để hoàn tất ! Code ::Blocks tạo cho bạn một Project đã chứa một chút mã nguồn.

- Trong bản bên trái có tên Projects, bạn có thể xem các tiểu mục bằng cách kích vào dấu  + để hiện danh sách các tệp của project. Bạn sẽ có ít nhất một tệp main.cpp mà bạn có thể mở bằng cách kích đúp vào tệp đó.

<img src="http://laptrinhtanbinh.com/public/user/1/test2.png">

**Chạy một chương trình**

- Hiện tại, tôi muốn bạn làm một việc đơn giản: thử biên dịch và chạy chương trình này. Có một nút “Build and run”. Nút này nằm trên thanh công cụ

<img src="http://laptrinhtanbinh.com/public/user/1/code-block-button.png">

- Việc biên dịch bắt đầu. Bạn sẽ thấy vài thông báo được hiển thị ở phần bên dưới của IDE (trong phần Build log).
- Nếu việc biên dịch không diễn ra và bạn gặp phải lỗi “My-program-Release uses an invalid compiler. Skipping… Nothing to be done.”, điều này nghĩa là bạn đã tải phiên bản Code::Blocks không có mingw (trình biên dịch). Hãy quay lại trang web của Code::Block để tải phiên bản có mingw.
- Nếu không có vấn đề gì, một console sẽ xuất hiện với chương trình của chúng ta.

<img src="http://laptrinhtanbinh.com/public/user/1/test3.png">

###Hết
