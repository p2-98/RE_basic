###Lập trình hợp ngữ (Assembly)

> Tài liệu tham khảo: Giáo trình lập trình hợp ngữ
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 11/1/2017

----

###Mục lục

-[1. Thanh ghi cờ](#muc1)
-[2. Hiện tượng tràn](#muc2)
-[3. Sự liên quan giữa tràn và thanh ghi cờ](#muc3)

----

###Tổng quan:

- Một điểm khác biệt quan trọng giữa máy tính và các loại máy khác đó là máy tính có khả năng quyết định. Các mạnh trong máy tính có khả năng thực hiện những quyết định đơn giản dựa trên trạng thái hiện tại của bộ xử lý. Đối với bộ xử lý 8086, trạng thái của bộ vi xử lý được thể hiện trong 9 bit riêng biệt gọi là các cờ. Mọi quyết định của bộ vi xử lý đều dựa trên gái trị của các cờ này.
- Các cờ được đặt trong thanh ghi cờ và chúng được phân thành 2 loại cờ trjang thái và cờ điều khiển. Cờ trạng thái phản ánh kết quả của các phép tính.

<a name="muc1"> </a>

###1. Thanh ghi cờ:

<img src="http://i.imgur.com/zmgPx8T.png">

- Hình trên cho thấy cấu trúc của thanh ghi cờ. Các cờ trạng thái nằn ở các bit 0, 2, 4, 6, 7, 11 còn các cờ điều khiển nằm ở các bit 8, 9 và 10. Các bit khác không có ý nghĩa. Chú ý rằng không cần nhớ cờ nào nằm ở bit nào. Trong hình trên trình bày bày tên các cờ và ký hiệu của chúng. Trong phần này chúng ta sẽ tập trung vào các cờ trạng thái.
-**Các cờ trạng thái**

	- Như đã nói trên, bộ xử lý sử dụng cờ trạng thái để phản ánh kết quả của một phép tính, chẳng hạn khi lệnh SUB AX, AX được thực hiện cờ ZF sẽ được thiết lập 1 nhờ vậy nó chỉ ra rằng kết quả băng 0 đã được tạo ra. Bây giờ chng ta hãy xem các cờ trạng thái.

-**Cờ nhớ: (Carry Flag - CF)**

	- Cờ CF được thiết lập 1 khi có nhớ từ bit msb trong phép cộng hay có vay vào bit msb trong phép trừ. Ngược lại nó bằng 0. Cờ CF cũng bị ảnh hưởng bởi các lệnh quay và dịch.

-**Cờ chẵn lẻ: (Parity Flag - PF)**

	- Cờ PF được thiết lập 1 nếu byte thấp của kết quả có sổ chẳng các bit 1 (parity chẵn). Nó bằng 0 nếu byte thấp có số lẻ bit 1 (parity lẻ). Ví dụ kết quả của một phép cộng các word là FFFEh, như vậy byte thấp có 7 bit 1 do đó PF = 0.

-**Cờ nhớ phụ (Auxiliary Flag - AF)**

	- Cờ AF được thiết lập 1 nếu có nhơ từ bit 3 trong phép cộng hoặc có vay vào bit 3 trong phép trừ. Cờ AF được sử dụng trong các thao tác với số thập phân mã hoá nhị phân (số BCD).

-**Cờ Zero: (Zero Flag - ZF)**

	- Cờ ZF được thiết lập 1 khi kết quả bằng 0 và ngược lại

-**Cờ dấu: (Sign Flag - SF)**

	- Cờ SF được thiết lập 1 khi bit msb của kết quả bằng 1 nó có nghĩa là kết quả là âm nếu bạn làm việc với số có dấu. Ngược lại SF = 0 nếu bit msb của kết quả bằng 0.

-**Cờ tràn: (Overflow Flag - OF)**

	- Cờ OF được thiết lập 1 khi xảy ra tràn ngược lại nó bằng 0, khái niệm tràn sẽ được giải thích sau đây

- Tên và ký hiệu các cờ:

<img src="http://i.imgur.com/eKvvHcw.png">

<a name="muc2"> </a>

###2. Hiện tượng tràn:

- Hiện tượng tràn gắn liền với một sự thật là phạm vi của các số biểu diễn trong máy tính có giới hạn.
- Đối với các số không dấu thì phạm vi là từ 0 đến 65535 cho một word và từ 0 đến 255 cho một byte. Nếu kết quả của một phép tính nằm ngoài phạm vi này thì hiện tượng tràn sẽ xảy ra và kết quả nhận được bị cắt bớt sẽ không phải là kết quả đúng

-**Các ví dụ về hiện tượng tràn:**

	- Sự tràn có dấu và không có dấu là các hiện tượgn độc lập nhau. Khi chúng ta thực hiện một thao tác số học như cộng hay trừ, có 4 khả năng xảy ra là:

		- Không tràn
		- Chỉ tràn có dấu
		- Chỉ tràn không dấu
		- Tràn có dấu và không dấu đồng thời

	- Đây là một ví dụ về hiện tượng tràn không dấu nhưng không tràn có dấu:
	- Giả sử AX chứ FFFFh, BX chứa 0001h và lệnh ADD AX,BX được thực hiện. Kết quả dạng nhị phân như sau:

<img src="">

	- Nếu chúng ta làm việc với các số không dấu, kết quả đúng phải là 100000h = 65536, nhưng kết quả này nằm ngoài vi biểu diễn của một word nên kết quả còn lại trong thanh ghi AX là 0h, đây là một kết quả sai, như vậy hiện tượng tràn khong dấu đã xảy ra. Nhưng kết quả nhận được lại đúng các số có dấu, FFFFh = -1 khi hiểu là số có dấu, trong khi đó 0001h = 1 vậy tổng của chúng bằng 0, rõ ràng hiện tượng tràn có dấu đã không xảy ra.
	- Bây giờ chúng ta hãy xem một ví dụ về hiện tượng tràn có dấu nhưng lại không tràn không dấu. Giải sử AX và BX cùng chứa 7FFFh, hãy thực hiện phép cộng ADD AX.BX
	- Kết quả dạng nhị phân như sau:

<img src="">

	- Trong cả 2 dạng có dấu và không dấu 7FFFh đều bằng 32767, bởi vậy trong cả 2 phép cộng không dấu và có dấu đều cho kết quả là 32767 + 32767 = 65534. Giá trị này nằm ngoài phạm vi của số có dấu, kết quả nhận được dạng có dấu là FFFEh = -2, như vậy xảy ra hiện tượng tràn có dấu. Tuy nhiên FFFEh lại bằng 65534 ở dạng không dấu do vậy không có hiện tượng tràn không dấu.
	- Có 2 vấn đề được đặt ra đó là làm sao CPU chỉ ra có hiện tượng tràn và làm sao nó biết được có hiện tượng tràn xảy ra?

-**CPU đã chỉ ra hiện tượng tràn như thế nào**

	- Bộ xử lý tập cờ OF = 1 để báo có hiện tượng tràn có dấu và CF = 1 để báo hiện tượng tràn không dấu. Thông báo này dùng cho chương trình để tiến hành những hành động thích hợp, nếu như không có hành động nào được thực hiện ngay lập tức thì kết quả của lệnh sau có thể xoá cờ báo tràn.
	- Khi xác định có hiện tượng tràn bộ xử lý không coi kết quả như là số không dấu cũng như số có dấu, thay vào đó nó sử dụng cả 2 cách hiểu có dấu và không có dấu cho mỗi thao tác đồng thời thiết lập các cờ CF hay OF báo tràn có dấu hay không dấu một cách tương ứng.
	- Trách nhiệm thuộc về người lập trình, người có quy ước về kết quả. Nếu anh ta đang làm việc với số có dấu thì chỉ có cờ OF đáng quan tâm trong khi cờ CF có thể bỏ qua, ngược lại khi làm việc với số không dấu thì cờ quan trọng là CF chứ không phải là OF.

-**Làm các nào CPU biết được có hiện tượng tràn xảy ra ?**

	- Có rất nhiều lệnh có thể gây ra hiện tượng tràn, nhưng để đơn giản ở đây chúng ta chỉ nói về phép cộng và phép trừ.

- **Hiện tượng tràn không dấu**

	- Trong phép cộng các số cùng dấu, hiện tượng tràn có dấu xảy ra khi tổng nhận được có dấu khác với dấu của 2 số hạng. Điều này đã xảy ra trong ví dụ trên khi chúng ta cộng 2 số dương 7FFFh nhưng lại nhận được kết quả là một số âm FFFEh
	- Phép trừ các số khác dấu cũng giống như phép cộng các số cùng dấu, ví dụ A - (-B) = A + B và -A - (+B) = - A + - B. Hiện tượng tràn xảy khi kết quả có dấu khác với dấu chúng ta chờ đợi
	- Trong phép cộng 2 số khác dấu hiện tượng tràn là không thể xảy ra vì A + (-B) chính bằng A - B và bởi vì A và B là 2 số đủ nhỏ để chứa trong toán hạng đích thì hiệu của chúng tất nhiên không thể vượt ra ngoài phạm vi của nó được. Cũng vì lý do như vậy mà phép trừ 2 số cùng dấu cũng không thể gây ra hiện tượng tràn.
	- Thực ra bộ xử lý sử dụng phương pháp sau để thiết lập cờ OF
	- Nếu việc nhứo vào bit msb và việc nhứo ra từ nó không đồng thời, có nghĩa là có nhớ vào msb nhưng không có nhớ ra từ nó, hay có nhớ ra từ nó mà không có nhớ vào thì hiện tượng tràn có dấu xuất hiện và OF được lập 1

<a name="muc3"> </a>

###3. Sự ảnh hưởng của các lệnh đến các cờ:

- Nhìn chung mỗi khi bộ xử lý thực hiện một lệnh, các cờ được thay đổi để phản ánh kết quả. Tuy nhiên có một số lệnh không ảnh hưởng tới cờ, chỉ ảnh hưởng tới một số trong chúng hay có thể làm cho chúng không xác định. Vì lệnh nhảy sẽ nghiên cứu trong phần sau phụ thuộc vào việc lập cờ, chúng ta cần biết mỗi lệnh ảnh hưởng tới cờ như thế nào. Chúng ta hãy trở lại với 7 lệnh cơ bản đã học trong phần trước, chúng ảnh hưởng tới cờ như sau:

| Chỉ thị | Các cờ bị ảnh hưởng |
|---------|---------------- -----|
| MOV / XCHG | Không cờ nào |
| ADD / SUB | Tất cả các cờ |
| INC / DEC | Tất cả các cờ trừ cờ CF |
| NEG | Tất cả các cờ (CF = 1 trừ khi két quả là 0,0F = 1 nếu toán hạng word là 8000h hay toán hạng byte là 80h) |

- Để các bạn làm quen với việc các lệnh có ảnh hưởng như thế nào đến các cờ, ta sẽ nêu ra ở đây một vài ví dụ. Trong mỗi ví dụ chúng tôi sẽ trình bày một lệnh, nội dung của các toán hạng và dự đoán kết quả cũng như việc thiết lập các cờ CF, PF, ZF và OF (chúng ta bỏ qua AF vì nó chỉ được sử dụng cho các phép tính số học với số BCD).
- Ví dụ 5.1: Thực hiện phép tính cộgn AX, BX trong đó AX và BX đều chứu FFFFh
-**Trả lời**

<img src="">

- Kết quả thu được chứa trong AX là FFFEh = 1111 1111 1111 1110.

	- SF = 1 vì msb = 1
	- PF = 0 vì có 7 bit 1 (lẻ các bit 1) trong byte thấp của kết quả
	- ZF = 0 vì kết quả thu được khác 0
	- CF = 1 vì có nhứo từ bit msb trong phép cộng
	- OF = 0 vì dấu của tổng nhận được giống như dấu của các số hạng tham gia phép cộng (còn khi thực hiện phép cộng dưới dạng nhị phân bạn sẽ thấy có nhớ vào vit msb đồng thời cũng có nhứo từ msb).

- Ví dụ 5.2 : Thực hiện phép cộgn AL, BL trong đó Al và BL cùng chứa 80h
- **Trả lời:**

<img src="">

- Kết quả nhận được trong AL bằng 0

	- SF = 0 vì msb = 0
	- PF = 1 vì tất cả các bit của tổng bằng 0
	- ZF = 1 vì kết quả thu được bằng 0
	- CF = 1 vì có nhớ từ bit msb trong phép cộng
	- OF = 1 vì các số hạng tham gia phép cộng đều là các số âm nhưng kết quả nhận được là một số dương (còn khi thực hiện phép cộng dứoi dạng nhị phân bạn sẽ thấy không có nhứo vào bit msb nhưng lại có nhớ từ bit msb).

- Ví dụ 5.3: Thực hiện phép trừ AX, BX trong đó AX chứa 8000h còn BX chứa 0001h
-**Trả lời:**

<img src="">

- Kết quả nhận được trong AX là 7FFFh = 0111 1111 1111 1111

	- SF = 0 vì msb = 0
	- PF = 1 vì có 8 bit 1 (chẵn các bit 1) trong byte thấp của kết quả.
	- ZF = 0 vì kết quả thu được khác 0
	- CF = 0 vì số không dấu nhỏ hơn bị trừ từ số lớn hơn

- Còn về cờ OF, xét về phương diện các số có dấu, chúng ta đã trừ một số dương từ một số âm cũng giống như cộng 2 số âm. Tuy nhiên kết quả nhận được lại là số dương (sai dấu) do đó OF = 1.

- Ví dụ 5.4: Tăng AL lên 1 khi AL chứa FFh
- **Trả lời:**

<img src="">

- Kết quả nhập được trong AL là 00h, SF = 0, PF = 1, ZF = 1. Mặc dù có nhứo CF không bị ảnh hưởng bởi lệnh INC. Có nghĩa là nếu trước đó CF = 0 thì cuối cùng CF vẫn bằng 0.
- OF = 0 vì 2 số hạng có dấu khác nhau (có nhớ vào msb đồng thời cũng có nhớ từ msb)

- Ví dụ 5.5: Chuyển -5 vào AX
- **Trả lời:**

<img src="">

- Kết quả nhận được trong AX là 1000 0000 0000 0000 = 8000h

	- SF = 1, PF = 1, ZF = 0
	- CF = 1 vì trong lệnh NEG, CF luôn bằng 1 trừ khi kết quả bằng 0
	- OF = 1 vì kết quả là 8000h, khi lấy nghịch đảo của một số kết quả nhận được phải có dấu ngược lại nhưng ở đây số bù 2 của 8000h lại chính thức bằng nó tức là dấu không thay đổi.