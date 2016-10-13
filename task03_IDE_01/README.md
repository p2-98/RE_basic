###Tìm hiểu về các IDE của C/C++

> Tài liệu tham khảo: [Tìm hiểu IDE C/C++](http://hocccoban.blogspot.com/2014/02/cc-tong-hop-cac-ide-cho-lap-trinh-c.html)
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 13.10.2016
>

----

[1. Khái quái sơ lược về ngôn ngữ lập trình C](#conceptC)

[2. Các IDE hỗ trợ lập trình C/C++](#ideC)

- [2.1 Turbo C/C++](#turbo)
	- [2.1.1 Cách cài đặt](#setupTurbo)
	- [2.1.2 Phân tích ưu, nhược điểm](#analyzeTurbo)
- [2.2 C - Free](#cfree)
	- [2.2.1 Cách cài đặt](#setupCfree)
	- [2.2.2 Phân tích ưu, nhược điểm](#analyzeCfree)
- [2.3 Code::Blocks](#codeblock)
	- [2.3.1 Cách cài đặt](#setupCodeblock)
	- [2.3.2 Phân tích ưu, nhược điểm](#analyzeCodeblock)
- [2.4 Dev C++](#devC)
	- [2.4.1 Cách cài đặt](#setupDevC)
	- [2.4.2 Phân tích ưu, nhược điểm](#analyzeDevC)
- [2.5 Visual Studio C++](#VSC)
	- [2.5.1 Cách cài đặt](#setupVSC)
	- [2.5.2 Phân tích ưu, nhược điểm](#analyzeVSC)

----

<a name = "conceptC"> </a>

###1. Khái quát sơ lược về ngôn ngữ lập trình C

- Ngôn ngữ lập trình C là một ngôn ngữ mệnh lệnh được phát triển từ đầu thập niên 1970 bởi Ken Thompson và Dennis Ritchie để dùng trong hệ điều hành UNIX. Từ dó, ngôn ngữ này đã lan rộng ra nhiều hệ điều hành khác và trở thành một những ngôn ngữ phổ dụng nhất. C là ngôn ngữ rất có hiệu quả và được ưa chuộng nhất để viết các phần mềm hệ thống, mặc dù nó cũng được dùng cho việc viết các ứng dụng. Ngoài ra, C cũng thường được dùng làm phương tiện giảng dạy trong khoa học máy tính mặc dù ngôn ngữ này không dược thiết kế dành cho người nhập môn.

<a name = "ideC"> </a>

###2. Các IDE hỗ trợ lập trình C/C++

- IDE viết tắt của cụm từ Integrated Development Environment là phần mềm cung cấp cho các lập trình viên một môi trường tích hợp bao gồm nhiều công cụ khác nhau như chương trình viết mã lệnh hay code editor, chương trình sửa lỗi hay debugger, chương trình mô phỏng ứng dụng khi chạy thực tế hay simulator.... Nói cách khác thì IDE là một phần mềm bao gồm những gói phần mềm khác giúp phát triển ứng dụng phần mềm.
- Một về IDE phổ biến dùng cho C/C++ là: Dev-C++, Code::Block, Microsoft Visual Studio,...

<a name = "turbo"> </a>

####2.1 Turbo C/C++:

<a name = "setupTurbo"> </a>

#####*2.1.1 Cách cài đặt*

- Link tải về:
	- Turbo C++ 3.1: http://www.mediafire.com/download.php?h1gf52gsjouohip
	- Borland C++: http://www.mediafire.com/download.php?p1f1q3yr6f1w27e
	- Turbo C++ DosBox (để code họa trên Win 7 - thank for kithuatlaptrinh.tk): http://www.mediafire.com/download.php?z31o6que726a2kk
- Hướng dẫn cài đặt: (VD Turbo C++ 3.0)
	
	- Bung nén Turbo C++ 3.0
	
	- *Bước 1:* Bấm về Intall.exe để cài đặt. Nhấn Enter
	
	<img src ="http://i.imgur.com/Wza2U34.png">
	
	- *Bước 2:*  Ghi tên ổ đĩa chứa phần mềm Turbo C++ 3.0 mà bạn vừa bung nén (VD: C, D, E,... bam ky tu tuong ung). Bấm ENTER
	
	<img src ="http://i.imgur.com/sBEqFTy.png">
	
	- *Bước 3:* Nó hiện lên dường dẫn, kệ nó, hãy bỏ qua. Bấm Enter
	
	<img src ="http://i.imgur.com/GnNstAR.png">
	
	- *Bước 4:* Bấm F9 cài đặt nhanh(hoặc bấm nút lên xuống để chọn lựa, chọn Start Intallation là cài đặt). Bấm Enter
	
	<img src ="http://i.imgur.com/YMBThlT.png">
	
- Quá trình cài đặt diễn ra nhanh chóng, bấm nút bất kỳ trên bàn phím để mở Read me, Nếu không đọc thì tắt nó đi bằng cách bấm Esc

- Bây giờ bạn đã có thể bắt đầu lập trình với Turbo C++

> **Lưu ý : Có 1 thư mục "TC" được tạo ngay ổ đĩa chứa phần mềm turbo c++ tốt nhất bạn nên copy vào ổ chứa hệ điều hành để có thể chạy được các thư viện hàm của C++**

<img src="http://i.imgur.com/udt9cgh.png">

<a name ="analyzeTurbo"> </a>

#####*2.1.2 Phân tích ưu, nhược điểm*

- Ưu điểm:

	- Miễn phí (do hãng Borland không còn hỗ trợ và phát triển tiếp), không cần cài đặt, môi trường tích hợp thuận tiện, dung lượng nhỏ (khoảng 4,3 MB), biên dịch và chạy chương trình nhanh, có thể chạy trên mọi thế hệ máy tính có hệ điều hành DOS.
	
- Nhược điểm:

	- Không cập nhật, vì thế chỉ có thể sử dụng cho những người mới học lập trình, viết các chương trình chạy trên DOS hay chương trình chạy trên hệ thống nhúng, mô phỏng một số thuật toán đồ họa trên DOS. Các nhược điểm khác của Turbo C++ 3.0: không hỗ trợ các tính năng mới của C/C++ (như kiểu dữ liệu bool, namespace, thư viện STL, các phương thức chuyển đổi kiểu dữ liệu ...), không thể biên dịch chương trình chạy trên nền Windows, không hỗ trợ các công nghệ mới như Intellisense (nhắc người dùng các từ khóa, hàm và kiểu dữ liệu). Bên cạnh đó, thao tác soạn thảo của Turbo C++ 3.0 cũng không tiện lợi vì đòi hỏi sử dụng các tổ hợp phím khá phức tạp. Vì các lý do trên, theo nhận xét của cá nhân tôi, chúng ta không nên tiếp tục sử dụng phần mềm này trừ khi dành cho các mục đích đặc biệt.

<a name ="cfree"> </a>

####2.2 C - Free

<a name ="setupCfree"> </a>

#####*2.2.1. Cách cài đặt*

- Link tải về:
	- [Bản Free](http://www.ipower.com/scripts/clickthroughtracker.cmp?url=http://www.programarts.com/download/cfree4_0_std_setup.exe&username=ipw.programarts)
	- [Bản Pro](http://www.ipower.com/scripts/clickthroughtracker.cmp?url=http://www.programarts.com/download/cfree5_0_pro_setup.exe&username=ipw.programarts)
- Hướng dẫn cài đặt:
	- *Bước 1:* Ấn đúp chuột vào bản cài đặt. Một cửa sổ nhỏ hiện lên -> Chọn English
	
	<img src ="http://i.imgur.com/dwRppCu.png">
  
	- *Bước 2:* Sau đó chọn Next
  
	<img src ="http://i.imgur.com/kLl3wre.png">
  
	- *Bước 3:* Bạn chọn I accept the agreement -> Next
	
	<img src ="http://i.imgur.com/lPO4qaD.png">
	
	- *Bước 4:* Bạn chọn đường dẫn (Nên để mặc định) -> Next
	
	<img src ="http://i.imgur.com/Sqz8pzM.png">
	
	- *Bước 5:* Tiếp theo bạn tao thư mục: Mặc định là C-Free 5 (Nên để mặc định) -> Next
	
	<img src ="http://i.imgur.com/rW5LbC7.png">
	
	- *Bước 6:* Bạn chọn Create a desktop icon -> Next
	
	<img src ="http://i.imgur.com/kbgN1kH.png">
	
	- *Bước 7:* Tiếp theo bạn chọn next để tiếp tục cài đặt C free 5
	
	<img src ="http://i.imgur.com/WLETeXS.png">
	
	- *Bước 8:* Quá trình cài đặt hoàn tất -> Finish
	
	<img src ="http://i.imgur.com/Dv72BEB.png">
	
- Giao điện C-Free:

	<img src = "http://i.imgur.com/VbMlSPB.png">

<a name = "analyzeCfree"> </a>

#####*2.2.2 Phân tích ưu, nhược điểm*
- Sử dụng trình biên dịch Mingw nhưng C-Free dịch nhanh hơn so với DevCpp, file kết quả .exe cũng nhỏ hơn. C-Free sử dụng kỹ thuật gọi là Intelligence Input (gần giống với công nghệ Intellisense của Microsoft) cho phép lập trình viên nhanh chóng chèn các đoạn mã lệnh theo kiểu nhắc lệnh và các đoạn mã template vào file đang làm việc. So với DevCpp và Pelles C, C-Free tỏ ra vượt trội ở giao diện, khả năng hỗ trợ soạn thảo mã nguồn. Nói chung nếu để làm việc với C/C++ thì C-Free là một lựa chọn tuyệt vời.

<a name = "codeblock"> </a>

####2.3 Code::Block

<a name = "setupCodeblock"> </a>

#####*2.3.1 Cách cài đặt*

- Link tải về : [Download](http://sourceforge.net/projects/codeblocks/files/Binaries/10.05/Windows/codeblocks-10.05mingw-setup.exe/download)
- Hướng dẫn cài đặt:
	- Chúng ta chỉ cần chọn “Next” và chờ đợi cho tới khi nó chạy xong thì thôi. Các hình ảnh dưới đây minh họa các bước cài đặt CB.
	
<img src ="http://i.imgur.com/iZEbSdW.png">
	
<img src ="http://i.imgur.com/WTlUsAS.png">
	
<img src ="http://i.imgur.com/PCi5AyD.png">
	
<img src ="http://i.imgur.com/wy0Cmv9.png">

<a name ="analyzeCodeblock"> </a>

#####*2.3.2 Phân tích ưu, nhược điểm*

- CodeBlock là một IDE được viết bằng C++ sử dụng framework wxWidget.
Điểm nổi bật của CB bao gồm:
1. Cross-platform, nó có thể run trên mọi hệ điều hành, bao gồm : Mac, Linux, Windows, …
2. Rất gọn nhẹ, chỉ có đúng 70mb.
3. Có thể chọn bất cứ compiler để biên dịch source, mặc định là gcc.
4. Hỗ trợ format source code rất tiện lợi cho việc copy code từ các site khác về, và chỉnh sữa lại.
5. Free! Nó cũng giống như VC++, chúng ta không phải trả bất cứ một phí nào để download và sử dụng nó.

<a name="devC"> </a>

####2.4 Dev C++

<a name = "setupDevC"> </a>

#####*2.4.1 Cách cài đặt*

- Link tải về: [Download](http://prdownloads.sourceforge.net/dev-cpp/devcpp-4.9.9.2_setup.exe)
- Hướng dẫn cài đặt:
	- Chúng ta cũng chỉ cần Next thôi:
	
<img src ="http://i.imgur.com/q46XkXw.png">
	
<img src ="http://i.imgur.com/vs64APv.png">
	
<img src ="http://i.imgur.com/KUnE4qZ.png">
	
<img src ="http://i.imgur.com/FQbA1Sl.png">
	
<img src ="http://i.imgur.com/1SKbQuW.png">
	
<img src ="http://i.imgur.com/QwVTkbj.png">
	
<img src ="http://i.imgur.com/kPaHW94.png">
	
<img src ="http://i.imgur.com/T44oMGR.png">
	
<img src ="http://i.imgur.com/FGlCoO7.png">
	
<img src ="http://i.imgur.com/obfEqwr.png">

<a name="analyzeDevC"> </a>

#####*2.4.2 Phân tích ưu nhược điểm*

- Ưu điểm:
	- DevCpp là công cụ IDE sử dụng trình biên dịch Mingw (một trình biên dịch mã nguồn mở phát triển từ trình biên dịch GCC trên môi trường Linux), hoàn toàn chạy trên Windows, hỗ trợ đầy đủ các tính năng mới của ngôn ngữ C/C++, cho phép gỡ lỗi, soạn thảo chương trình, quản lý project, thêm các thư viện hỗ trợ C/C++ khác. DevCpp hiện nay được khá nhiều lập trình viên sử dụng trong việc phát triển phần mềm thương mại, nguồn mở cũng như trong môi trường giáo dục (có khá nhiều website dạy lập trình C/C++ sử dụng DevCpp để làm bài tập lập trình, project môn học ...). Có lẽ mã nguồn mở, miễn phí, chạy trên Windows chính là ưu điểm lớn nhất của DevCpp.
- Nhược điểm:
	- Chương trình chạy chậm (mặc dù theo như tài liệu trợ giúp đi kèm, yêu cầu hệ thống của DevCpp khá thấp: chạy trên các hệ thống Windows với 8 MB Ram, 30 MB ổ cứng, CPU 100 Mhz (cấu hình đề nghị là Windows 2000/XP, 32 MB Ram, 200 MB ổ cứng, CPU 400 Mhz); việc biên dịch chương trình cũng khá chậm, mã chương trình sinh ra lớn (ví dụ một chương trình C++ đơn giản sử dụng thư viện STL sinh ra file .exe có dung lượng tới 470 KB, sau khi nén bằng UPX còn 270 KB), giao diện soạn thảo và cấu hình có đôi chỗ còn rối rắm, không thuận tiện.

<a name ="VSC"> </a>

####2.5 Visual Studio C++

<a name ="setupVSC"> </a>

#####*2.5.1 Cách cài đặt*

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

<img src="https://daynhauhoc.s3-ap-southeast-1.amazonaws.com/optimized/2X/f/ff112093cfd6d866243ab625661e37775fe00aec_1_690x325.png">

> Tại đây nếu trình duyệt của bạn vẫn chưa thực hiện tải bản cài đặt thì bạn có thể click vào phần click here to retry để trình duyệt load lại việc tải xuống.

- Khi file cài đặt đã sẵn sàng tải xuống. Các bạn chọn vị trí lưu file cài đặt và nhấn Save

<img src="https://daynhauhoc.s3-ap-southeast-1.amazonaws.com/original/2X/4/46a36b3529a9d987893afcd3603e2218fcd9fa0d.png">

- Việc tải xuống rất nhanh, mất khoảng tầm 2-3s.

<img src="https://daynhauhoc.s3-ap-southeast-1.amazonaws.com/original/2X/0/037e13dbac38b647d1888f820e7d8d07ee577012.png">

- Nhấp vào file cài đặt vs_community_ENU.exe

- Sẽ hiện một phần thông báo download các items. Nhưng quá trình load cũng diễn ra rất nhanh

<img src="https://daynhauhoc.s3-ap-southeast-1.amazonaws.com/original/2X/f/f53627a575f59c624ea213ed47a2c64670dfb473.png">

- Các phần sẽ hiện sau khi load xong file cài đặt

<img src="https://daynhauhoc.s3-ap-southeast-1.amazonaws.com/original/2X/5/582c99958cdd0d7a16ef7bc98e455ec9c0f5e5f1.png">

- Sau đó

<img src="https://daynhauhoc.s3-ap-southeast-1.amazonaws.com/optimized/2X/1/1835ca159a269abd0d9db420c3c5aa9c058cc1eb_1_357x500.png">

- Tiếp theo

<img src="https://daynhauhoc.s3-ap-southeast-1.amazonaws.com/optimized/2X/8/8be70508cfc3a9f3170209595532d7121699ee15_1_454x500.png">

- Tại đây tùy chỉnh vị trí vị trí cài đặt Visual Studio.
- Tùy chọn *kiểu cài đặt**
> Lưu ý : Nên Chọn kiểu Custom
- Nhấp Install để cài đặt

<img src="https://daynhauhoc.s3-ap-southeast-1.amazonaws.com/optimized/2X/d/d856d6a2c9ae930a74e45fb0d5f753ddc221e9c5_1_434x500.png">

- Tích các ô tùy chọn muốn cài đặt.
> Lưu ý : Nếu chọn càng nhiều thời gian cài đặt càng lâu.
> Chỉ chọn các cài đặt cần thiết
- Sau đó nhấp Next để quá trình cài đặt bắt đầu.

<img src="https://daynhauhoc.s3-ap-southeast-1.amazonaws.com/optimized/2X/3/36519553da4b9c24b2de998cbe4c23dc5e71aad5_1_436x500.png">

- Quá trình cài đặt tiếp theo hoàn toàn tự động
> Lưu ý : Vì quá trình cài đặt có thể diễn ra trong thời gian dài. nên bạn có thể rời khỏi khỏi máy tính và làm những công việc khác. 
> Duy trì ổn định nguồn điện của máy và kết nối mạng trong quá trình cài đặt. Để tránh phát sinh lỗi.

<img src="https://daynhauhoc.s3-ap-southeast-1.amazonaws.com/original/2X/2/21da51dddf747ff3d9c48177a92cee73140472cb.png">

- Thông báo như vậy là quá trình cài đặt đã thành công
- Nhấn LAUNCH để khởi chạy Visual Studio Community 2015.

<a name="analyzeVSC"> </a>

#####*2.5.2 Phân tích ưu, nhược điểm*

- Ưu điểm
	- Ưu điểm lớn nhất của nó là tốc độ phát triển rất nhanh, với cùng một project nếu bạn phát triển bằng Java sẽ tiêu tốn thời gian gấp rưỡi đến gấp đôi so với bạn phát triển nó trên Visual Studio.
	- Ưu điểm thứ hai đáng kể đến chính là sự linh hoạt và thư viện hàm, và đối tượng khổng lồ của nó. Với những lập trình viên đã thân quen với ngôn ngữ C có thể dễ dàng tiếp cận với nó thông qua visual C++, với những ai đang là tín đồ của Java cũng có thể đến với nó và visual C#. Và những anh em đi trên nghiệp Visual basic thì vẫn có thể đi tiếp con đường mình đang đi nhưng với tầm với ngày càng rộng lớn.
	- Ưu điểm kế tiếp của nó chính là công cụ lập trình thân thiện dễ sử dụng cùng với hệ thống thư viện online MSDN có thể đáp ứng tối đa nhu cầu học hỏi của lập trình viên. Khi bạn gần như bế tắc, hãy nhấn F1, chắc chắn bạn sẽ tìm thấy điều mình muốn.
- Nhược điểm
	- Khuyết điểm lớn nhất của các sản phẩm làm ra từ Visual Studio là phải phụ thuộc vào thư viện nền Framework. Và gần như chỉ có thể chạy trên hệ điều hành windows.
	- Khuyết điểm thứ hai: Visual Studio không phải là Open source, do đó rất khó tìm thấy một bộ mã nguồn hoàn chỉnh đâu đó trên mạng.

##Và một vài IDE khác như: Notepad++, Sublime Text,  eclipse, NetBean,...

###Hết
