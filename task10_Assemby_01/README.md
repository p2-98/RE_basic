###Lập trình hợp ngữ (Assembly)

> Tài liệu tham khảo: [Assembly](http://bit.ly/2iryedL)
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 09 - 01 - 2017

----

###Mục lục:

- [1. Cấu trúc chương trình](#muc1)

	- [1.1 Cú pháp hợp ngữ](#muc1.1)

		- [1.1.1 Các dòng lệnh](#muc1.1.1)
		- [1.1.2 Trường tên](#muc1.1.2)
		- [1.1.3 Trường toán tử](#muc1.1.3)
		- [1.1.4 Trường toán hạng](#muc1.1.4)
		- [1.1.5 Trường lời giải thích](#muc1.1.5)

	- [1.2 Cấu trúc chương trình hợp ngữ dùng cho chương trình thực thi .exe](#muc1.2)
	- [1.3 Cấu trúc chương trình hợp ngữ dành cho tập tin lệnh .com](#muc1.3)
	- [1.4 Biên dịch và liên kết chương trình trong NASM](#muc1.4)
	- [1.5 Chương trình Marco Assembly: (MASM)](#muc1.5)

- [2. Toán tử, biểu thức và các lệnh đơn giản](#muc2)

	- [2.1 Các phép toán](#muc2.1)
	- [2.2 Biểu thức](#muc2.2)
	- [2.3 Câu lệnh gán](#muc2.3)
	- [2.4 Xử lý số liệu đơn giản](#muc2.4)

- [3. Lệnh và ngắt ra vào dòng nhập chuẩn](#muc3)
- [4. Cài đặt Emu8086](#muc4)

----

**Tổng quan về ngôn ngữ**

- Ngôn ngữ assembly (còn gọi là hợp ngữ) là một ngôn ngữ bậc thấp được dùng trong việc viết các chương trình máy tính. Ngôn ngữ assembly sử dụng các từ có tính gợi nhớ, các từ viết tắt để giúp ta dễ ghi nhớ các chỉ thị phức tạp và làm cho việc lập trình bằng assembly dễ dàng hơn. Mục đích của việc dùng các từ gợi nhớ là nhằm thay thế việc lập trình trực tiếp bằng ngôn ngữ máy được sử dụng trong các máy tính đầu tiên thường gặp nhiều lỗi và tốn thời gian. Một chương trình viết bằng ngôn ngữ assembly được dịch thành mã máy bằng một chương trình tiện ích được gọi là assembler (Một chương trình assembler khác với một trình biên dịch ở chỗ nó chuyển đổi mỗi lệnh của chương trình assembly thành một lệnh Các chương trình viết bằng ngôn ngữ assembly liên quan rất chặt chẽ đến kiến trúc của máy tính. Điều này khác với ngôn ngữ lập trình bậc cao, ít phụ thuộc vào phần cứng.

- Trước đây ngôn ngữ assembly được sử dụng khá nhiều nhưng ngày nay phạm vi sử dụng khá hẹp, chủ yếu trong việc thao tác trực tiếp với phần cứng hoặc làm các công việc không thường xuyên. Ngôn ngữ này thường được dùng cho trình điều khiển (tiếng Anh: driver), hệ nhúng bậc thấp (tiếng Anh: low-level embedded systems) và các hệ thời gian thực. Những ứng dụng này có ưu điểm là tốc độ xử lí các lệnh assembly nhanh.

- Ngôn ngữ máy cực kỳ khó hiểu đối với lập trình viên vì thế họ không thể sử dụng trực tiếp ngôn ngữ máy để viết chương trình. Một sự trừu tượng khác là ngôn ngữ assembly. Nó cung cấp những tên dễ nhớ cho các lệnh và một ký hiệu dễ hiểu hơn cho dữ liệu. Bộ dịch được gọi là assembler chuyển ngôn ngữ assembly sang ngôn ngữ máy. Ngay cả những ngôn ngữ assembly cũng khó sử dụng. Những ngôn ngữ cấp cao như C++ cung cấp các ký hiệu thuận tiện hơn nhiều cho việc thi hành các giải thuật. Chúng giúp cho các lập trình viên không phải nghĩ nhiều về các thuật ngữ cấp thấp, và giúp họ chỉ tập trung vào giải thuật. Trình biên dịch (compiler) sẽ đảm nhiệm việc dịch chương trình viết bằng ngôn ngữ cấp cao sang ngôn ngữ assembly. Mã assembly được tạo ra bởi trình biên dịch sau đó sẽ được tập hợp lại để cho ra một chương trình có thể thực thi. Một ngôn ngữ bất kỳ từ ngôn ngữ giao tiếp của con người tới ngôn ngữ máy tính đều xây dựng trên một bộ ký tự. Các ký tự ghép lại thành các từ có nghĩa gọi là từ vựng. Các từ lại được viết thành các câu tuân theo cú pháp và ngữ pháp của ngôn ngữ để diễn tả hành động sự việc cần thực hiện. Bộ ký tự của Assembly gồm có:

- Các chữ cái latin: 26 chữ hoa A-Z, 26 chữ thường a-z. - Các chữ số thập phân: ‘0’ - ‘9’ - Các ký hiệu phép toán, các dấu chấm câu và các ký hiệu đặc biệt: + - * / @ ? $,.: [ ] () < > { } & %! \ # v.v... - Các ký tự ngăn cách: space và tab.

<a name="muc1"> </a>

###1. Cấu trúc chương trình:

<a name="muc1.1"> </a>

####1.1 Cú pháp hợp ngữ:

<a name="muc1.1.1"></a>

#####1.1.1 Các dòng lệnh:

- Các chương trình bao gồm các dòng lệnh, mỗi dòng lệnh trên một dòng. Một dòng lệnh là một lệnh mà trình biên dịch sẽ dịch ra mã máy hay là mọt hướng dẫn biên dịch để chỉ dẫn chi trình biên dịch thực hiện một vài nhiệm vụ đặc biệt nào đó, chẳng hạn dành chỗ cho một biến nhớ hay khai báo một chương trình con. Mỗi lệnh hay hướng dẫn biên dịch thường có 4 trường:

- `Tên	Toán tử	Toán hạng	Lời bình`

- Các trường phải được phân cách nhau bằng ít nhất một ký tự trống hay tab. Cũng không bắt buộc phải sắp xếp các trường theo cột nhưng chúng nhất định phải xuất hiện theo đúng tự nêu trên.

- Ví dụ một lệnh:  `START: MOV CX,5	;khởi tạo bộ đếm.`

- Trong ví dụ này, trườn tên là nhãn START, toán tử là MOV, hạng là CX và 5. lời bình là 'Khởi tạo bộ đếm'.

- Ví dụ về hướng dẫn biên dịch: `MAIN PROC`
- MAIN là tên và toán hạng là PROC. Dẫn hướng biến dịch này khai báo một chương trình con có tên là PROC.

<a name="muc1.1.2"> </a>

#####1.1.2 Trường tên:

- Trường tên được sử dụng làm nhãn lệnh, các tên thr tục và các tên biến.
- Chương trình biên dích ẽ chuyển các tên thành các địa chỉ bộ nhớ.
- Các tên có thể có chiều dài từ 1 đến 31 ký tự, có thể chứa các chữ cái, chữ số và các ký tự đặc biệt (? . @ _ $ %). Không được phép chèn dấu trống vào giữa một tên. Nếu sử dụng dấu chấm (.) thì nó phải đứng đầu tiên. Các tên không được bắt đầu bằng một chữ số. Chương trình biên dịch không phân biệt chữ hoa và chữ thường trong tên.

- Ví dụ các tên hợp lệ:

	- COUNTER1
	- @character
	- SUM_OF_DIGITS
	- $1000
	- DONE?
	- .TEST

- Ví dụ các tên không hợp lệ:

	- TWO WORD 	chứa 1 khoảng trống
	- 2abc bắt 	đầu bằng một chữ số
	- A45.28 	dấu chấm không phải là ký tự đầu tiên
	- YOU&ME 	chứa 1 ký tự không hợp lệ

<a name="muc1.1.3"> </a>

#####1.1.3 Trường toán tử

- Trong một lệnh, trường toán tử chứa mã lệnh dạng tượng trưng. Chương trình biên dịch sẽ chuyển mã lệnh dạng tượng trưng sang mã lệnh của ngôn ngữ máy. Tượng trung của mã lệnh thường biểu thị chức năng của các thao tác. Ví dụ như: MOV, ADD, SUB.
- Trong một hướng dẫn biên dịch, trường toán tử chứa **toán tử giả** (pseudo - op). Các toán tử giải sẽ không được dịch ra mã máy mà đơn giải chúng chỉ báo cho trinh biên dịch làm một việc gì đó. Chẳng hạn toán tử giải PROC được dùng để tạo ra một thủ tục.

<a name="muc1.1.4"> </a>

#####1.1.4 Trường toán hạng:

- Đối với một chỉ thị, trường toán hạng xác định dữ liệu sẽ được các thao tác tác động lên. Một chỉ thị có thể không có, có 1 hoặc có 2 toán hạng. Ví dụ:

	- `NOP`		Không toán hạng, không làm gì cả.
	- `INC AX`	Một toán hạng, cộng 1 vào nội dung AX.
	- `ADD WORD1, 2` hai toán hjng, cộng 2 vào từ nhớ WORD1.

- Trong một chỉ thị hai toán hạng, toán hạng đầu tiên gọi là toán hạng đích. Nó có thể là một thanh ghi haowjc một ô nhớ, là nơi chứa kết quả (lưu ý một số chỉ thị không lưu giữ kết quả). Toán hạng thứ hai là toán hạng nguồn. Các chỉ thị thường không làm thay đổi toán hạng nguồn.
- Đối với một hướng dẫn biên dịch, trường toán hạng thường chứa thên thông tin về việc dẫn hướng.

<a name="muc1.1.5"> </a>

#####1.1.5 Trường lời giải thích:

- Người lập trình thường sử dụng trường lời giải thích của một dòng lệnh để giải thích dòng lệnh đó làm cáic gì. Mở đầu trường này là một dấu chấm phẩy (;) và trình biên dịch bỏ qua một cái được đánh vào sau dấy chấm phẩy này. Lời giải thích có thể tuỳ ý (có hoặc không) nhưng vì Hợp ngữ là ngôn ngữ cho nên ta hầu như không thể hiểu được một chương trình viết bằng Hợp ngữ khi không có lời bình. Trên thực tế điền các lời giải thích vào hầu hết các dòng lệnh là một phương pháp học lập trình tốt. Nghệ thuật chú giải sẽ được phát triển cùng với quá trình thực hành.
- Không nên viết những điều quá rõ ràng như:

	- `MOV	CX,0	;chuyển 0 vào CX`

- Thay vào đó, ta nên sử dụng các lời giải thích để đặt các chỉ thị vào trong ngữ cảnh của chương trình:

	- `MOV CX,0		;CX đếm số vòng lặp, khởi tạo 0`

- Cũng có thể tạo nên cả một dòng ghi chú và dùng chúng để tạo ra các dòng trống như trong chương trình:

```
;
;khởi tạo các thanh ghi
;
MOV		AX,0;
MOV		BX,0;
```

<a name="muc1.2"></a>

####1.2 Cấu trúc chương trình hợp ngữ dùng cho tập tin thực thi .EXE:

- Phần **"Data segment"**: khai báo các hằng số, biến mảng... Các toán thử thường dùng:

	- org -> Xác định vị trí mã lệnh
	- EQU -> gán giá trị cho 1 biến
	- DB -> khai báo biến kích thích 1 byte
	- DD -> Khai báo biến kích thước 4 byte
	- DQ -> Khai báo biến kích thước 8 byte
	- DT -> Khai báo biến kích thước 10 byte
	- dup(?) -> tạo một mảng và gán cùng một giá trị

- Ví dụ:

```
xuongdong  EQU  0Dh    ; xuống dòng
Tmp        DB   ?      ; Tạo một biến tên Tmp
Str        DB   "2"    ; Tạo một mảng chứa chuỗi 
bufferdata DB   100 dup(?) ; Tạo mảng có 100 ô nhớ
```

- Phần **"Stack segment"**: khai báo bộ ngăn xếp. Do x86 sử dụng cá thanh ghi 16bit nen kích thước bộ đệm luôn được gán bằng toán tử DW:

- VD:

```
	Stack segment
        DW  256 dup (?) ; tạo ngăn xếp có 256 ô nhớ.
    Ends
```

- Phần **"Code Segment"**: phần chính của chương trình chứa các lệnh hợp ngữ gồm chương chình chính và chương trình con - Procedure(Nếu có).

- VD:

```
  Code Segment
      ...                     ;các lệnh hợp ngữ
      call chuongtrinhcon     ;gọi chương trình con
      ...                     ;các lệnh hợp ngữ
  Ends
  chuongtrinhcon      Proc
      ...                         ;các lệnh hợp ngữ
      ret                         ;quay về chương trình chính
  chuongtrinhcon      EndP
```

<a name="muc1.3"> </a>

####1.3 Cấu trúc chương trình hợp ngữ dành cho tập tin lệnh .com:

- Tập tin gồm 2 phần (data và code), không có bộ nhớ ngăn xếp. 
- VD:

```
    Code Segment
        org     h   ;địa chỉ đầu của chương trình
    Start:      JMP     CONTINUE    
        ;Các khai báo biến, mảng, hằng... để tại đây
    CONTINUE:
        MAIN    PROC    
    ; Các lệnh của chương trình chính, trở về DOS bằng INT 20h
        MAIN    ENDP
    ;Các chương trình con(nếu có) khai báo ở đây.
    END strart
```

<a name="muc1.4"> </a>

####1.4 Biên dịch và liên kết chương trình trong NASM

- Các Netwide Assembler, NASM, là 80x86 và x86-64 lắp ráp thiết kế cho tính di động và mô đun. Nó hỗ trợ một loạt các định dạng tập tin đối tượng, bao gồm cả Linux và BSD * a.out, ELF, COFF, Mach-O, Microsoft 16-bit OBJ, Win32 và Win64. Nó cũng sẽ ra thuần tập tin nhị phân. Cú pháp của nó được thiết kế để đơn giản và dễ hiểu, tương tự như Intel, nhưng ít phức tạp hơn. Nó hỗ trợ tất cả x86 hiện đang được biết đến mở rộng kiến trúc, và đã hỗ trợ mạnh mẽ cho các macro.

<a name="muc1.5"> </a>

####1.5 Chương trình Marco Assembly: (MASM)

- Chương trình A86 Macro Assembly (tập tin chính là: A86.com) thường được sử dụng để dịch chương trình hợp ngữ sang chương trình thực thi dạng COM.

- Chương trình Macro Assembly (tập tin chính là: MASM.exe) thường được sử dụng để dịch chương trình hợp ngữ sang chương trình thực thi dạng EXE. Tuy nhiên, MASM chỉ có thể dịch tập tin chương trình hợp ngữ sang dạng tập tin đối tượng mã máy dạng Obj. Để chuyển tập tin Obj sang tập tin chương trình thực thi EXE ta phải sử dụng chương trình liên kết của MSDOS, đó là Link.exe. Để chuyển tập tin thực thi dạng EXE sang tập tin thực thi dạng COM ta phải sử dụng thêm một chương trình khác của MS_DOS, đó là EXE2Bin.com.

- Có thể sử dụng các tập tin TASM.Exe và TLINK.Exe để thay thế cho MASM.exe và Link.exe. Các tập tin này, và cả tập tin EXE2Bin.com, có thể tìm thấy trong bộ chương trình Turbo Pascal.

- MASM có thể dịch tập tin chương trình hợp ngữ sang các tập tin: tập tin đối tượng (**.Obj), tập tin liệt kê thông tin (.Lst), tập tin tham khảo chéo (**.Crf**).

	- Tập tin đối tượng (Object File): Chứa bảng dịch mã máy của các lệnh trong chương trình nguồn hợp ngữ, và các thông tin cần thiết để có thể tạo nên một tập tin thực thi. Đây là tập tin chính để tạo nên tập tin thực thi.
	- Tập tin liệt kê thông tin (List File): Là một tập tin văn bản cho biết địa chỉ offset của từng lệnh trong đoạn Code; mã lệnh của các lệnh trong chương trình; danh sách các tên/nhãn dùng trong chương trình; các thông báo lỗi và một số thông tin khác. Đây là tập tin cơ sở hỗ trợ việc gỡ rối chương trình.

		- Tập tin tham khảo chéo (Cross Reference File): Liệt kê các tên sử dụng trong chương trình và dòng mà chúng xuất hiện.

<a name="muc2"> </a>

###2. Các phép toán, biểu thức, câu lệnh gán và các sử lý dữ liệu đơn giản:

<a name="muc2.1"> </a>

####2.1 Các phép toán:

- Bao gồm các chỉ thị ADD, SUB, INC và DEC:

	- Các chỉ thị ADD và SUB được sử dụng để cộng hoặc trừ nội dung của hai thanh ghi, một thanh ghi và một ô nhớ haowjc cộng (trừ) một số vào (từ) một thanh ghi hay một ô nhớ. Cú pháp:

		- `ADD 		đích, nguồn`
		- `SUB 		đích, nguồn`

	- Ví dụ:

		- `ADD 		WORD1, AX`

	- Chỉ thị này "cộng AX vào WORD1", sẽ cộng nội dung của thanh ghi AX với nội dung của ô nhớ WORD1 và chứa tổng trong WORD1. AX không bị thay đổi

		- `SUB 		AX, DX`

	- Trong ví dụ này "trừ DX từ AX", giá trị cảu AX trừ đi giá trị của DX, kết quả được chứa trong AX, thanh ghi DX không bị thay đổi

		- `ADD  	BL, 5`

	- Chỉ thị này cộng số 5 vào nội dung của thanh ghi BL.
	- Cũng giống như trường hợp MOV và XCHG, có một vài hạn chế khi kết hợp các toán hạng của ADD và SUB. Các trường hợp cho phép được tổng kết trong bảng 4.3. Phép cộng hay trừ trực tiếp giữa các ô nhớ là không hợp lệ. Ví dụ:

		- `ADD 		BYTE1, BYTE2	;không hợp lệ`

	- Có một giải pháp là chyển BYTE2 vào một thanh ghi trước khi cộng:

		- `MOV  	AL, BYTE2		;AL lấy giá trị BYTE2
		- `ADD  	BYTE1, AL 		;cộng vào BYTE1

	- INC (INCrement) được dùng để cộng 1 vào nội dung của một thanh ghi hay ô nhớ, DEC (DECrement) trừ 1 từ nội dung của một thanh ghi hay ô nhớ. Cú pháp

		- `INC 		đích`
		- `DEC 		đích`

	- Ví dụ: 

		- `INC 		WORD1`

	- Cộng 1 vào nội dung của WORD1

		- `DEC 		BYTE1`

	- Trừ từ 1 biến BYTE1

- NEG:

	- NEG dùng để phủ định nội dung của toán hạng đích. DEC sẽ thay thế nội dung bởi phần bù 2 của nó. Cú pháp:

		- `NEG 		đích`

	- Toán hạng đích có thể là một thanh ghi hay một ô nhớ. Ví dụ:

		- `NEG 		BX`

	- Sẽ phủ định nội dung của thanh ghi BX.

- Kiểu quy ước của các toán hạng:

	- Các toán hạng của các lệnh hai toán hạng đã nêu phải có cùng kiểu, tức là cùng là byte hoặc word. Vì thế một lệnh như sau:

		- `MOV 		AX, bYTE1 		;không hợp lệ`

	- là không được phép. Tuy nhiên trình biên dịch chấp nhận cả hai lệnh sau đây:

		- `MOV 		AH, 'A'`

	- và

		- `MOV 		AX, 'A'`

	- Trong trường hợp đầu, trình biên dịch xét thấy do toán hạng đích AH là một byte nên toán hạng nguồn cũng phải là một byte và nó chuyển 41h vào AH. Đến trường hợp sau, vì toán hạng nguồn là một từ, nó giải thiết toán hạng đích cũng như vậy và chuyển 0041h vào AX.

<a name="muc2.2"> </a>

####2.2 Biểu thức:

- Biểu thức logic: Bao gồm các phép **NOT - AND - OR - XOR - TEST**

| A | B | A AND B | A OR B | A XOR B | NOT A |
|---|---|---------|--------|---------|-------|
| 0 | 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 1 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 |

- Cú pháp:

	- `NOT` 	đích
	- `AND` 	đích, nguồn
	- `OR` 		đích, nguồn
	- `XOR` 	đích, nguồn
	- `TEST` 	đích, nguồn

- Lệnh Not (Logical Not): Thực hiện việc đảo ngược từng bít trong nội dung của [Toán hạng đích]. Lệnh này không làm ảnh hưởng đến các cờ.

	- Lệnh Not thường được sử dụng để tạo dạng bù 1 của [Toán hạng đích].

- Lệnh And (Logical And): Thực hiện phép tính logic And trên từng cặp bít (tương ứng về vị trí) của [Toán hạng nguồn] với [Toán hạng đích], kết quả lưu vào [Toán hạng đích].

	- Lệnh And thường được sử dụng để xóa (= 0) một hoặc nhiều bít xác định nào đó trong một thanh ghi.

- Lệnh Or(Logical Inclusive Or):Thực hiện phép tính logic Or trên từng cặp bít (tương ứng về vị trí) của [Toán hạng nguồn] với [Toán hạng đích], kết quả lưu vào [Toán hạng đích].

	- Lệnh Or thường dùng để thiết lập (= 1) một hoặc nhiều bít xác định nào đó trong một thanh ghi.

- Lệnh Xor (eXclusive OR):Thực hiện phép tính logic Xor trên từng cặp bít (tương ứng về vị trí) của [Toán hạng nguồn] với [Toán hạng đích], kết quả lưu vào [Toán hạng đích].

	- Lệnh Xor thường dùng để so sánh (bằng nhau hay khác nhau) giá trị của hai toán hạng, nó cũng giúp phát hiện ra các bít khác nhau giữa hai toán hạng này.

- Lệnh Test: Tương tự như lệnh And nhưng không ghi kết quả vào lại [Toán hạng đích], nó chỉ ảnh hưởng đến các cờ CF, OF, ZF,...

<a name="muc2.3"> </a>

####2.3 Câu lệnh gán:

- `MOV đích, nguồn` trong đó:

	- Đích: Có thể là thanh ghi (8bit hay 16bit), ô nhớ (chính xác hơn là địa chỉ của một ô nhớ) hay một biến nào đó. Đích không thể là hằng số.
	- Nguồn: có thể là hằng số, biến, thanh ghi, ô nhớ (chính xác hơn là địa chỉ của một ô nhớ) nào đó.

- *Tác dụng:* lấy nội dung (giá trị) của nguồn vào đích. Nội dung của nguồn không bị thay đổi

<a name="muc2.4"> </a>

####2.4 Xử lý số liệu đơn giản:

- `IN AL, <Địa chỉ cổng>`

- Lệnh In (input): Đọc một lượng dữ liệu 8bit từ cổng được chỉ ra ở <Địa chỉ cổng> đưa vào lưu trữ trong thanh ghi AL.
- Nếu địa chỉ cổng nằm trong giới ạn từ 0 đến FF (hệ thập lục phân) thì có thể viết trực tiếp trong câu lệnh, nếu địa chỉ cổng lớn FF thì ta phải dùng thanh ghi Dx để chỉ định địa chỉ cổng.

- `OUT <Địa chỉ cổng>, AL`

- Lệnh Out (output): Gởi một lượng dữ liệu 8bit từ thanh ghi AL ra cổng được chỉ ra ở <Địa chỉ cổng>. Tương tự lệnh In, địa chỉ cổng có thể được viết trực tiếp trong câu lệnh haowjc thông qua thanh ghi Dx.

<a name="muc3"> </a>

###3. Lệnh và ngắt ra vào dòng nhập chuẩn:

- **Ngắt 21h**

- Ngắt 21h được dùng để gọi rất nhiều hàm của DOS. Mỗi hàm được gọi bằng cách đặt só hàm vào trong thanh ghi AH và gọi INT 21h. Chúng ta hãy xem xét các hàm sau đây:

| Số hiệu hàm | Chương trình |
|-------------|--------------|
| 1 | Vào một phím |
| 2 | Đưa một ký tự ra màn hình |
| 9 | Đưa ra một chuỗi ký tự |

- Các hmà của ngắt 21h nhận dữ liệu trong các thanh ghi nào đó và trả về kết quả trong các thanh ghi khác. Các thanh ghi này sẽ được liệt kê khi mô tả mỗi hàm.
- **Hàm 1**
- **Vào một phím**

```
Vào : AL = 1
Ra : AL  = Mã ASCII nếu một phím ký tự được ấn.
		 = 0 Nếu một phím điều khiển hay chức năng được nhấn
```

- Để gọi phục vụ này, bạn hãy thực hiện các lệnh sau:

	- `MOV 		AH, 1		;hàm vào một phím`
	- `INT 		21h 		;mã ASCII trong AL`

- Bộ vi xử lý sẽ đượi người sử dụng ấn một phím nếu cần thiết. Nếu một phím ký tự được ấn, AL sẽ nhận mã ASCII và ký tự được hiện lên trên mình hình. Nếu một phím khác được ấn, chẳng hạn phím mũi tên, F1 - F10..., thì AL sẽ chứa 0. Trong các lệnh tiếp theo INT 21h có thể kiểm tra AL và thực hiện tác vụ thích hợp.

- Bởi vì hàm 1 của ngắt 21 không đưa ra thông báo để người sử dụng vào một phím nên bạn sẽ không biết được là máy tính đang đợi nhập dữ liệu hay đang làm các công việc khác. Hàm tiếp theo có thể được dùng để đưa ra các thông báo nhập liệu:

- **Hàm 2**:
- **Hiển thị một ký tự hay thi hành một chức năng điều khiển:**

```
Vào: AH = 2
	 DL = mã ASCII của ký tự hiển thị hay ký tự điều khiển.
Ra: AL = mã ASCII của ký tự hiển thị hay ký tự điều khiển.
```

- Để dùng hàm này hiển thị một ký tự, ta đặt mã ASCII của nó trong DL, Ví dụ các lệnh sau đây sẽ làm xuất hiện dấu chấm hỏi trên màn hình:

```
MOV	AH,2
MOV	DL,'?'
INT 21h
```

- Sau khi ký tự được hiển thị, con trỏ màn hình dịch sang vị trí tiếp theo của dòng (nếu ở cuối dùng) con trỏ màn hình sẽ dịch chuyển sang đầu dòng tiếp theo).
- Hàm 2 cũng có thể được dùng để thực hiện một chức năng điều khiển. Nếu như DL chứa mã ASCII của ký tự điều khiển, hàm này sẽ thi hành chức năng điều khiển đó. Các ký tự điều khiển quan trọng được chỉ ra sau đây:

| MÃ ASCII(HEX) | Ký hiệu | Chức năng |
|---------------|---------|-----------|
| 7 | BEL | phát tiếng bíp (beep) |
| 8 | BS | lùi lại 1 vị trí  |
| 9 | HT | tab |
| A | LF | xuống dòng |
| D | CR | xuống dòng và về đầu dòng |

- Khi thực hiện, AL nhận mã ASCII của ký tự điều khiển.

<a name="muc4"> </a>

###4. Cài đặt IDE Emu80866:

- Emu8086 là chương trình mô phỏng bộ VXL 8086/86 rất hay với đầy đủ chức năng của một text editor, assembler, disassembler, và software emulator, bạn có thể theo dõi trạng thái của thanh ghi, cờ và bộ nhớ khi chương trình đang chạy.

- [Vào đây để tải.](http://www.emu8086.com/)

- Sau khi giải nén. Ta bắt đầu cài đặt, lần lượt theo thứ tự sau:

-1

<img src="http://i.imgur.com/iIgd3jE.png">

-2

<img src="http://i.imgur.com/N5KYWXe.png">

-3

<img src="http://i.imgur.com/MP2DV6s.png">

-4

<img src="http://i.imgur.com/B4JkWv1.png">

-5

<img src="http://i.imgur.com/Wz4mFmz.png">

-6

<img src="http://i.imgur.com/CY8LGy1.png">

-7 Màn hình làm việc:

<img src="http://i.imgur.com/vYwY14Z.png">

- Ví dụ 1 đoạn chương trình mẫu: (nguồn TynKen)

<img src="http://i.imgur.com/F7uLnUB.gifv">
