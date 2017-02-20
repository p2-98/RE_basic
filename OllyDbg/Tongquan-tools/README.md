###Tìm hiểu tổng quan về hợp ngữ và công cụ Olly DBG

> Tài liệu tham khảo: [Reverse](http://ctf.ist-vnisa.org.vn/category/reverse); [OllyDBG](https://kienmanowar.wordpress.com/2008/09/03/ollydbg_tut1/)
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 19/02/2016

----

###Mục lục

- [1. Reverse Engineering](#1)

	- [1.1 Thế nào là dịch ngược?](#1.1)
	- [1.2 Dịch ngược nhầm mục đích gì?](#1.2)
	- [1.3 Các kiến thức cần thiết?](#1.3)
	- [1.4 Những loại công cụ được sử dụng](#1.4)

- [2. Khái quát sơ lược và thực hành đơn giản về công cụ OllyDBG](#2)
- [3. Bài viết và các tutorial tham khảo](#3)

----

<a name="1"> </a>

###1. Reverse Engineering:

<a name="1.1"> </a>

####1.1 Thế nào là dịch ngược?

- Dịch ngược là quá trình cố gắng tìm hiểu cách thức chương trình làm việc dựa vào file đã biên dịch. Ban đầu lập trình viên viết code bằng ngôn ngữ lập trình bậc cao như  C, C++, Visual Basic … Sau đó chúng được dịch ra mã máy để giúp máy tính có thể hiểu được. Nhưng đối với con người thì mã máy thật sự khó hiểu, vì thế dịch ngược giúp ta hiểu được chương trình cần làm gì mà không có file code ban đầu.

####1.2 Dịch ngược nhầm mục đích gì?

- Dịch ngược được sử dụng ở rất nhiều mảng trong khoa học máy tính nhưng sau đây là những mảng chính:

	- Có được trong tay ý tưởng code của tác giả
	- Phá vỡ cơ chế bảo vệ phần mềm
	- Học tập nghiên cứu virus hay mã độc
	- Kiểm tra chất lượng phần mềm
	- Bổ sung thêm tính năng vào chương trình

- Ở mảng đầu tiên, công việc là tái tạo lại file code ban đầu dựa vào file nhị phân. Công việc hơi buồn chán nên tôi không sẽ không nói tiếp.

- Ở mảng thứ hai, chúng ta phá vỡ cơ chế bảo vệ của chương trình. Điều đó có nghĩa là chúng ta gỡ bỏ tính năng thời gian dùng thử, đăng kí sử dụng hay tất cả những thứ mà những chương trình thương mại làm để bắt người dùng phải trả tiền. Đây sẽ là phần dài nhất.

- Ở mảng thứ ba, là nghiên cứu virus và mã độc. Việc dịch ngược là cần thiết vì bên ngoài có rất nhiều người viết virus và họ sẽ chẳng bao giờ để lộ cách họ viết ra virus, mục tiêu của virus hay cách mà virus đạt được mục tiêu của mình (trừ khi họ bị ngu). Đây thực sự là mảng thú vị, nhưng nó lại yêu cầu lượng kiến thức lớn. Chúng ta sẽ không bàn quá nhiều về mảng này.

- Mảng thứ tư là kiểm tra thẩm định tính an toàn cũng như lỗ hổng của phần mềm. Khi mà phải làm việc với một chương trình lớn (ví dụ như hệ điều hành Windows) thì việc dich ngược giúp đảm bảo không có những lỗ hổng nghiêm trọng hay làm khó các cracker cố gắng crack phần mềm.

- Mảng cuối cùng là thêm những tính năng mới vào phần mềm. Theo ý kiến riêng, tôi nghĩ đây là một mảng khá là vui. Kiểu như bạn không thích bức ảnh trong phần mềm, hãy thay đổi nó. Hay như thêm tính năng mã hóa nội dung văn bản vào chương trình soạn thảo. Thậm chí là trêu tức nhân viên bằng các hộp thoại khi họ đang làm việc với chương trình Windows calculator. Chúng ta sẽ bắt đầu một loạt bài sau.

<a name="1.3"> </a>

####1.3 Các kiến thức cần thiết:

- Chắc là bạn cũng đoán ra việc có lượng kiến thức lớn là việc cần thiết đối với một người dịch ngược viên. Thật may mắn, những kiến thức quá cao siêu hiện tại chưa cần thiết cho người mới bắt đầu, đó chỉ là những gì tôi mong muốn. Như đã nói, không chỉ có khoảng thời gian vui vẻ reversing and chắc chắn sau khi bạn hoàn thành xong những bài hướng dẫn này bạn sẽ hiểu được cách thức mà chương trình chạy (ví dụ: bạn sẽ thấy rõ như thế nào là mảng, cấu trúc điều khiển if..else..). Làm quen với ngôn ngữ Assembly là điều rất khuyến khích. Có thể bạn không cần kiến thức về ASM khi học những bài hướng dẫn này, nhưng rõ ràng bạn sẽ muốn trở thành một guru về ASM để có thể biết mình đang làm gì. Thêm vào đó, bạn dành thời gian chủ yếu để học cách sử dụng các tool. Những tool này là vô giá đối với những người dịch ngược, đòi hỏi cần phải học cách sử dụng chúng. Cuối cùng, việc dịch ngược đòi hỏi lượng kinh nghiệm rất cụ thể. Hãy chơi với các `packer/protectors/encryption` khác nhau, học các viết 1 chương trình với nhiều ngôn ngữ khác nhau, những `trick` trong khi reverse… Ở cuối bài hướng dẫn này, tôi sẽ viết thêm 1 phần giới thiệu về các nguồn tham khảo. Nếu bạn muốn giỏi hơn trong reverse, thì tôi khuyên nên xem chúng.

<a name="1.4"> </a>

####1.4 Những loại công cụ được sử dụng:

- Có rất nhiều loại tool trong dịch ngược. Một số loại dùng trong những trường hợp cụ thể. Một số loại giúp việc dịch ngược trở nên dễ dàng hơn. Một số loại bạn sẽ dùng thường xuyên. Chúng có thể chia thành các loại sau:

- `1. Disassemblers`

- Disassemblers sẽ cố hiển thị ngôn ngữ máy trong các file binary một cách dễ hiểu. Chúng cũng tìm ra và hiển thị những hàm, tham số truyền vào, string… Tất cả những điều đó khiến việc đọc mã trở nên dễ dàng với con người hơn. Có rất nhiều disassemble, một số loại dành cho những thứ riêng biệt (ví dụ: Binary được viết bởi Delphi). Rồi bạn sẽ thoải mái làm việc với chúng. Bản thân tôi thấy làm việc với IDA ( bản miễn phí ở đấy  http://www.hex-rays.com )

- `2. Debuggers`

- Trình gỡ rối  (debugger) là thứ tối quan trọng với người dịch ngược. Đầu tiên chúng phân tích binary giống như Disassembler. Trình gỡ rối cho phép chương trình chạy từng dòng code, chạy từng dòn một và hiển thị kết quả. Đây là chìa khóa để khám phá ra chương trình hoạt động như thế nào. Cuối cùng, một số trình gỡ rối cho phép chỉnh sửa mã trực tiếp. Ví dụ như Windbg và Ollydbg. Tôi chủ yếu dùng Ollydbg (http://www.ollydbg.de/), ngoại trừ khi cần debug binary chạy trên kernel, chúng ta sẽ bàn tới sau.

- `3. Hex editors`

- Trình soạn thảo Hex cho phép bạn nhìn thấy từng byte trong binary và thay đổi chúng. Chúng cũng cung cấp việc tìm kiếm cho những kiểu cụ thể, lưu file binary và nhiều thứ khác nữa. Có rất nhiều trình soạn thảo Hex miễn phí rất ổn. Chúng ta không sử dụng quá nhiều ở trong bài hưỡng dẫn này. Tuy nhiên chúng sẽ rất có ích trong một số trường hợp.

- `4. PE and resource viewers/editors`

- Tất cả những binary được thiết kế để chạy trên máy tính Windows ( hay cả Linux ) đều có những phần dữ liệu cụ thể ở đầu mỗi file. Chúng giúp cho hệ thống khở tạo chạy chương trình. Chúng cho OS biết dung lượng bộ nhớ mà chúng cần, những DLL mà chương trình cần. Chúng được gọi là Portable Executable, tất cả chương trình chạy trên Windows đều phải dùng loại này.

- Trong môi trường dịch ngược, cấu trúc sắp xếp các bytes là điều rất quan trọng, nó giúp người dịch ngược có thêm thông tin cần thiết. Thậm chí nhiều khi bạn muốn thay đổi những thông tin này để làm cho chương trình chạy khác so với ban đầu hoặc thay đổi nó như chương trình ban đầu. Hiện nay có rất nhiều phần mềm xem và chỉnh sửa PE. Tôi sử dụng CFF Explorer (http://www.ntcore.com/exsuite.php) and LordPE (http://www.woodmann.com/collaborative/tools/index.php/LordPE), bạn có thể tùy chọn công cụ mà bạn thích.

- Hầu hết các file đều có phần “resource”, nơi chứa hình ảnh, item trong dialog, icon, text… Thỉnh thoảng bạn có thể chỉnh sửa những thứ này. Tôi sẽ làm ví dụ trong bài hướng dẫn.

- `5. System Monitoring tools`

- Khi bạn dịch ngược thỉnh thoảng những công cụ này sẽ phát huy tác dụng (rõ ràng nhất là khi nghiên cứu virus và malware), chúng hiển thị sự thay đổi mà chương trình gây ra đối với hệ thống, có thẻ là key trong registry được tạo ra hay được truy xuất, hay file .ini được tạo, hay những tiến trình ẩn được khởi tạo. Một số công cụ được biết đến như là procmon, regshot, and process hacker. Chúng ta sẽ bàn luận sau.

- `6. Miscellaneous tools and information`

- Đây là những công cụ được sưu tầm trong quá trình làm việc như  scripts, unpackers, packer identifiers … Windows API cũng là một phần thông tin quan trọng. Nó cực kì hữu ích, cho chép chúng ta biết hàm API đó có tác dụng gì.

<a name="2"> </a>

###2. Khái quát sơ lược về công cụ OllyDBG:

- OllyDBG hay còn gọi tắt là Olly là công cụ debug rất phổ biến. Nhờ giao diện trực quan và dễ sử dụng nên Olly phù hợp với người dùng ở mọi trình độ khác nhau.

 
- Mọi người có thể download lại địa chỉ: [OllyDBG](http://www.ollydbg.de/)

- Việc sử dụng OllyDBG cũng không có gì phức tạp, sau khi hoàn thành việc download, giải nén và chạy chương trình OLLYDBG.EXE mà không cần phải cài đặt.

- Trong lần chạy đầu tiên, có thể đường dẫn đến thư mục UDD và Plugins bị lỗi :

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=960&stc=1">

- Để sửa lỗi này bạn vào : Options => Appearance => Directories để sửa lại đường dẫn đến thư mục UDD và Plugins.

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=963&stc=1">

- Restart lại OllyDBG để những thay đổi của mình có tác dụng.

- Thử mở 1 file .exe với OllyDBG. Ở đây tôi dùng 1 crackme trên trang [CrackMe](http://reversing.kr/challenge.php) – Easy Crack để minh họa cho những hướng dẫn của mình về OllyDBG.

- Để mở 1 file .exe ta vào File -> Open hoặc ấn phím F3. Sau đó chọn đúng file .exe cần dùng.

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=964&stc=1">

- Ta có các thông tin OllyDBG hiển thị ra như sau:

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=965&stc=1">

- Cửa sổ OllyDBG được chia ra làm 5 cửa sổ con :

	- **1: Disassembler window:** Các đoạn mã của chương trình dưới dạng code assembly và các comment tại các dòng code đó.
	- **2: Register window:** Các thanh ghi và giá trị của chúng.
	- **3: Tip window:** Các thông tin bổ sung cho 1 dòng code. Các thông tin này khá hữu ích trong quá trình debug.
	- **4: Dump window:** Cho phép người sử dụng xem và chỉnh sửa các giá trị trong bộ nhớ của chương trình đang được debug.
	- **5: Stack window:** Thông tin về stack của chương trình.

- Ngoài 5 cửa sổ trên thì Olly còn có một số cửa sổ khác. Để ý trên thanh menu có các chức năng:

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=966&stc=1">

– Click vào nút L ta thấy cửa số Log data của Olly. Chứa các thông tin về các module, các import library và các plugins được load cùng chương trình tại thời điểm chương trình được load vào Olly.
– Click vào nút E ta thấy cửa sổ Executable modules, danh sách các file thực thi được chương trình sử dụng.
– Click vào nút M ta thấy cửa sổ Memory Map, chứa thông tin về bộ nhớ được chương trình của ta sử dụng.
– Click vào nút T là cửa sổ Threads, liệt kê các thread của chương trình.
– Click vào nút W là Windows
– Nút H là cửa sổ Handles.
– Nút / là Patches, cửa sổ chứa các thông tin về những câu lệnh ta đã sửa ở trong chương trình.
– Nút K là cửa sổ Call Stack.
– Nút B là cửa sổ Breakpoints, hiển thị các breakpoint ta đặt trong chương trình.
– Nút R – References chứa thông tin về kết quả cho chức năng tìm kiếm trong Olly.

- *Những chức năng không thể thiếu đó là các chức năng phục vụ cho công việc debug:*

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=967&stc=1">

– Đặt Breakpoint: `F2`
– Run: `F9`
– Step into: `F7`
– Step over: `F8`
– Restart: `Ctrl + F2`

- **Thực hành**

- Bên trên là những thông tin cơ bản về các chức năng của Olly. Bắt tay vào sử dụng ngay thôi nào.

- Quay trở lại với crackme ta đề cập đến ở đầu bài giới thiệu: `Easy_CrackMe.exe` 
- Load lại file Easy_CrackMe.exe vào OllyDBG
- `F9` để chạy chương trình.

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=968&stc=1">

- Làm gì tiếp theo đây??
- Điền bừa cái gì đó rồi bấm nút xem sao

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=969&stc=1">

- Sai rồi, chả có lý do gì để lần thử đầu tiên là đúng cả. 
Nhưng vẫn thu được 1 lượng thông tin kha khá. Đó là string thông báo của chương trình là : ”Incorrect Password” và thông báo được đưa ra bởi 1 message box.

- Sử dụng chức năng tìm kiếm của OllyDBG để tìm kiếm tất cả các chuỗi trong chương trình.

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=970&stc=1">

- Kết quả thu được:

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=971&stc=1">

- Click double vào chuỗi “Incorrect Password” ta sẽ đến được đoạn code sử dụng chuỗi này.

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=972&stc=1">

- Ta thấy sẽ có thể có 2 trường hợp xảy ra : 1 trường hợp là thông báo Incorrect Password ta vừa gặp, trường hợp còn lại là “Congratulation !!” – chắc là thông báo password đúng.)
- Câu lệnh đầu tiên của đoạn code in ra thông báo “Incorrect Password” tại địa chỉ `0x0040113c`.

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=973&stc=1">

- Để ý mũi tên mau đỏ trỏ đến câu lệnh tại địa chỉ 0x0040113c. Ta thấy có 4 lệnh JNZ đến địa chỉ 0x0040113c.
Goto đến lệnh JNZ đầu tiên.

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=974&stc=1">

- Để ý đến câu lệnh tại địa chỉ `0x004010AA` có comment : `GetDlgItemTextA` – lấy 1 đoạn dữ liệu từ 1 dialog box. => có thể đây chính là câu lệnh thực hiện nhiệm vụ đọc password ta nhập vào.

- Ấn F2 để đặt 1 breakpoint tại địa chỉ `0x004010AA` và chạy lại chương trình. Nhập password rồi ấn nút “??”. Chương trình dùng tại breakpoint `0x004010AA`.

- F8 để chạy qua hàm `GetDlgItemTextA`. Ta có kết quả như sau:

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=975&stc=1">

- Quan sát Stack, password ta nhập vào “123454321” đã được được vào trong stack bắt đầu tại địa chỉ `0x0012FA18.`

- `004010B0 CMP BYTE PTR SS:[ESP+5], 61`

- Thực hiện câu lệnh so sánh giá trị tại địa chỉ `ESP+5` và `0x61`.
Địa chỉ `ESP+5` là ký tự thứ 2 trong password ta vừa nhập vào.
Câu lệnh tiếp theo:

- `004010B5 JNZ SHORT Easy_Cra.00401135`

- Sau câu lệnh CMP, nếu 2 giá trị được mang ra so sánh mà khác nhau, cờ ZF vẫn mang giá trị 0 và lệnh JNZ được thực hiện, đoạn code thông báo “Incorrect Password” sẽ được thực hiện và bật ra thông báo.
- Như vậy bước kiểm tra đầu tiên để password được chấp nhận thì ký tự thứ 2 cúa password là ký từ có mã ASCII là `0x61` => ký tự “a”.

- Ta có thể sửa password, restart lại chương trình và run lại, nhưng ta có thể sử dụng cách bớt phức tạp hơn là ghi nhớ ký tự thứ 2 của password là “a” rồi sửa cờ ZF để tiếp tục thực hiện chương trình.
Click double vào giá trị 0 ở cờ ZF, giá trị ZF được set lại giá trị =1.

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=976&stc=1">

- Quan sát tip window ở bên dưới Assembler window sẽ thấy thông tin

- `Jump is NOT taken`
- `00401135=Easy_Cra.00401135`

- F7 để tiếp tục thực hiện chương trình, đến câu lệnh :

- `004010C3 CALL Easy_Cra.00401150`

- Thì dừng lại và quan sát stack.

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=977&stc=1">

- 2 chuỗi “3454321”, “5y” và giá trị 0x02 được đẩy vào stack trước khi thực hiện lệnh Call 0x00401150
F7 để thực hiện hàm tại địa chỉ 0x00401150

- Đoạn chương trình thực hiện công việc so sánh 2 ký tự thứ 3 và 4 của password với chuỗi “5y”.
- Như vậy ta đã có 3 ký tự thứ 2,3,4 của password là “a5y”

- Tiếp tục dùng cách sửa cờ ZF để vượt qua câu lệnh

- `004010CD JNZ SHORT Easy_Cra.00401135`

- Tiếp tục so sánh các ký tự từ thứ 5 trở đi đến hết password với chuỗi “R3versing”

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=978&stc=1">

- Như vậy ta có password có dạng “xa5yR3versing” với ký tự đầu tiên là ký tự chưa tìm ra.

- Restart lại chương trình và nhập vào password có dạng như trên.

- Dễ dàng vượt qua các bước kiểm tra trên.

- Dừng lại ở câu lệnh:

`0040110D CMP BYTE PTR SS:[ESP+4], 45`

- So sánh ký tự đầu tiên của password với ký tự “E”

- Như vậy ta tìm ra password chính xác là “Ea5yR3versing”

- Chạy lại chương trình và nhập password vừa tìm được.

- Ta nhận được kết quả như sau:

<img src="https://forum.whitehat.vn/attachment.php?attachmentid=979&stc=1">

<a name="3"> </a>

###3. Bài viết và tutorial tham khảo:

- [OllyDBG](https://kienmanowar.wordpress.com/2008/09/03/ollydbg_tut1/)
