###Lập trình hợp ngữ (Assembly) 

> Tài liệu tham khảo : [assembly](http://bit.ly/2iZ45FN)

>Thực hiện: Phạm Phú Quí

> Cập nhật lần cuối: 15/01/2017

> ---------

###mục lục:

[1. Tổng quan](#muc1)

[2. Các lệnh logic](#muc2)

 -[ 2.1 các lệnh AND, OR, XOR](#muc2.1)

 - [2.2 các lệnh NOT](#muc2.2)

 - [2.3 lệnh TEST](#muc2.3)

[3. các lệnh dich](#muc3)

 - [3.1 các lệnh dịch trái](#muc3.1)

 - [3.2 các lệnh dịch phải](#muc3.2)

[4. các lệnh quay](#muc4)

> ----------------------

<a name="muc1"></a>

###1. Tổng quan 

 - Trong chương này chúng ta sẽ nghiên cứ về các chỉ thị dùng để thay đổi đến từng bit trong byte word. khả năng thao tác với các bit thường không có ở các ngôn ngữ bậc cao (trừ ngôn ngữ C), đó cũng là một lý do quan trọng để lập trình bằng hợp ngữ.
 - Chúng ta sẽ được tìm hiểu về các lệnh logic AND, OR, XOR và NOT. các lệnh này có thể sử dụng để xóa, thiết lập và kiếm tra từng bit trong các thanh ghi hay các biến. chúng ta sẽ sử dụng các lệnh này để thực hiện một số công việc quen thuộc như đổi chữ thường thành chữ hoa hay còn mới như xác định xem một thanh ghi chứ số chẵn hay lẽ.
 - Tiếp theo là các lệnh dịch, các bit có thể được dịch phải hoặc dịch trái trong thanh ghi hay trong một ô nhớ. khi một bit bị dochj ra khỏi thanh ghi nó sẽ được chứa trong cờ CF. vì dịch trái cũng có nghĩa là nhân đôi số và dịch phải cũng có nghĩa là chia đôi nó, lệnh này cho phép chúng ta thực hiện phép nhân và chia cho một lũy thừa của 2
 - Trong phần 3 chúng ta sẽ tìm hiều về lệnh quay. các lệnh này làm việc giống như các lệnh dịch ngoại trừ một điều là khi một bit bị ra khỏi một phía của toán hạng nó sẽ được trở về phái kia của toán hoạng đó. các lệnh này có thể sử dụng trong các trường hợp chúng ta muốn kiểm tra hoặc thay đổi các bit hay nhóm các bit.
 - Trong phần 4 chúng ta sẽ sử dụng ác lệnh logic, dịch và lệnh quay để thực hiện các thao tác vào ra với số nhị phân và số hex, khả năng đọc và viết các số cho phép chúng ta giải quyết niều vấn đề khác nhau.


<a name="muc2"></a>

###2. Các lệnh logic

 - Như đã nói ở trên khả năng thao tác với từng bit riêng biệt là một ưu điểm của hợp ngữ. chúng ta có thể thay đổi từng bit trong máy tính bằng lệnh logic. các giá trị nhị phân 0 và 1 được xem như là các giá trị logic TRUE hoặc FALSE một cánh tương ứng. bảng 1 là bảng sự thật của các toán tử AND, OR, XOR (hoặc phủ đinhh) và NOT.
 - Khi lệnh logic được áp dụng với các toán hạng 8 và 16 bit kết quả nhận được bằng cách áp dụng chúng với từng bit một.

**Ví dụ 1:** thực hiện các thao tác logic sau đây:
 - 1.  10101010 AND 11110000
 - 2.  10101010 OR 11110000
 - 3.  10101010 XOR 11110000
 - 4.  NOT 10101010
**Trả lời:**

1.

```
       10101010
 AND   11110000 
 ______________
 = 	   10100000
```

2.

```
 	10101010
 OR	11110000
 ___________
 = 	11111010
```

3. 

```
 	10101010
XOR	11110000
_____________
  =	01011010
```
4. 

```
	10101010
	_________
NOT	01010101
```

**BẢNG 1** Bảng sự thật của các lệnh logic AND, OR, XOR và NOT

| a | b | a AND b | a OR b | a XOR b |
|---|---|---------|--------|---------|
| 0 | 0 | 0 | 0 | 0 |
| 0 | 1 | 0 | 1 | 1 |
| 1 | 0 | 0 | 1 | 1 |
| 1 | 1 | 1 | 1 | 0 |

| a | NOT a |
|---|-------|
|0|1|
|1|0|

####2.1 Các lệnh AND, OR, XOR <a name="2.1"></a>

- Các lệnh AND, OR và XOR thực hiện các thao tác logic như tên gọi của chúng. cú pháp như sau:

```
 AND 	đích, nguồn
 OR		đích, nguồn
 XOR	đích, nguồn
```
- Kết quả của thao tác được chứa trong toán hạng đích, nó phải là một thnah ghi hay một ô nhớ, toán hạng nguồn có thể là hằng số, thanh ghi hay ô nhớ tuy nhiên thao tác giữa hai ô nhớ là không hợp lệ.

**Ảnh hưởng tới cờ:**
 
  - SF, ZF, PR, phản ánh kết quả của lệnh.
  - AF không xác định
  - CF, OF = 0
  - Khi sử dụng các lệnh AND, OR, XOR chúng ta có thể thay đổi một các có chọn lọc các bit của toán hạng đích. để làm điều đó chúng ta tạo lên một mẫu bit mặt nạ (gọi là MASK). các bit của mặt nạ được chọn để sao cho các bit tương ứng của toán hạng đích được thay đổi đúng như chúng ta mong muốn khi ệnh logic được thực hiên.
  - Để chọn các bit mặt nạ chúng ta sử dụng các tính chất sao đây của các lệnh AND, OR và XOR .
 
`b AND 1 = b, b OR 0 = b, b XOR 0 = b`
`b AND 1 = b, b OR 1 = 1, b XOR 1 = -b (bù của b)`

- Từ đó chúng ta rút ra kết luận sau:

  - 1. Lệnh AND có thể sử dụng để xóa các bit nhất định của toán hạng đích trong khi giữ nguyên những bit còn lại. bit 0 của mặt nạ xóa bit tương ứng, còn bit 1 của mặt nạ giữ nguyên bit tương ứng của toán hạng đích.

  - 2. Lệnh OR có thể dùng để thiết lập các bit xác định của toán hạng đích trong khi vẫn giữ nguyên những bit còn lại. bit 1 của mặt nạ sẽ thiết lập bit tương ứng trong khi bit 0 của nó sẽ giữ nguyên bit tương ứng của toán hạng đích.

  - 3. Lệnh XOR có thể dùng để đảo các bit xác định của toán hạng đích trong khi vẫn giữ nguyên những bit còn lại. bit 1 của mặt nạ làm đảo bit tương ứng còn bit 0 vẫn giữ nguyên bit tương ứng của toán hạng đích.

**Ví dụ 2:** xóa bit dấu của AL trong khi giữ nguyên các bit còn lại.
**Trả lời:**

 - Sử dụng lệnh AND với 0111111b = 7Fh làm mặt nạ : AND AL, 7Fh.

**Ví dụ 3:** thiết lập các bit trọng lượng cao nhất cà thấp nhất của AL trong khi giữ nguyên các bit còn lại.
**Trả lời :**

 - Sử dụng câu lệnh OR với 10000001b =81h làm mặt nạ : OR AL,81h

**Ví dụ 4:** thay đổi bit dấu của DX 
**Trả lời:**
 
 - Sử dụng mặt nạ 8000h với lênh XOR chúng ta có XOR DX,8000h

**Chú ý:** để tránh nhầm lẫn khi viết, tốt nhất các bạn nên biểu diễn mặt nạ dưới dạng số hex thay vì dưới dạng số nhị phân đặc biệt là khi sử dụng mặt nạ 16 bit

 - Các lệnh logic đặc biệt có ích khi thực hiện các công việc dưới đây:

**Đổi bảng mã ASCII của một số thành số tương ứng.**
 - Chúng ta đã thấy rằng khi một chương trình đọc một ký tự từ bàn phím .AL sẽ chứa mã ASCII của ký tự đó. điều đó cũng đúng với các ký tự biễu diễn số. chẳng hạn khi phím "5" được ấn , AL sẽ chứa 35h thay vì 5. để nhận được 5 trong thành ghi AL có thể làm như sau:
 
 `SUB	AL,30h`

 - Một phương pháp khác là sử dụng lệnh AND để xóa nửa byte cao của AL:

 `AND		AL,0Fh`

 - Vì mã ASCII của các chữ số từ "0" đến "9" là từ 30h đến 39h. phương pháp này có thể dùng để đổi mã ASCII của bất kỳ chữ số nào thành giá trị thập phân tương ứng.
 - Bằng cách sử dụng lệnh AND thay cho lệnh SUB chúng ta nhấn mạnh rằng chúng đang thay đổi những mẫu bit của AL, nhờ đó chương trình trở nên dễ đọc hơn.

**Đổi chữ thường thành chữ hoa**

 - Mã ASCII của các chữ thường từ "a" đến "z" nằm từ 61h đến 7Ah . mã ASCII của các chữ hoa từ "A" đến "Z" nằm từ 41h đến 5Ah. bởi vậy chẳng hạn nếu DL chứa mã ASCII cả một chữ thường chúng ta có thể đổi ra chữ hoa bằng cách thực hiện lệnh:
 `	SUB		DL,20h `
 - Phương pháp này được sử dụng trong chương 4, tuy nhiên nếu chúng ta so sánh mã ASCII dạng nhị phân của các chữ thường và chữ hoa tương ứng sẽ thấy rằng:

| Ký tự | Mã ASCII | Ký tự | Mã ASCII|
|-------|----------|-------|---------|
| a | 0110001 | A | 01000001 |
| b | 0110010 | B | 01000010 | 
|...|.........|...|..........|
| z | 01111010 | Z | 01011010 |
 
 - Rõ ràng là để đổi chữ thường thành chữ hoa chúng ta chỉ cần xóa bit 5. điều này có thể thực hiện bằng cách dùng lệnh AND với mặt nạ 11011111b hay 0DFh. do đó nếu một chữ thường chứa trong DL thì ta có thể đổi nó thành chữ in như sau:
 ` AND		DL,0DFh`

 **Xóa một thanh ghi**
 - Chúng ta đã biết 2 cách để xóa một thanh ghi chẳng hạn để xóa thanh ghi AX ta làm như sau:
  
`MOV	AX,0 `
  
  hay
  
  `SUB	AX,AX `
 - Bằng cách sử dụng một tính chất là 1 XOR 1 =0 và 0 XOR 0 = 0 chúng ta có một phương pháp thứ 3 như sau:
 
`XOR 	AX,AX `

 - Mã máy cho lệnh đầu tiên là 3 byte so với 2 bute của mỗi lệnh sau như vậy các lệnh sau hiệu quả hơn. tuy nhiên các thao tác giữa ô nhớ là không hợp lệ nên khi cần xóa một ô nhớ thì chúng ra bắt buộc phải sử dụng lệnh thứ nhất.

**Kiểm tra xem một thanh ghi có bằng 0 hay không **
 
 - Vì 0 OR 1 = 1 và 0 OR 0 = 0 có vẽ như chúng ta sẽ phí thời gian nếu thự hiện lệnh sau:
  
  `OR 	CX,CX `

 - Bởi vì chúng không làm thay đổi nội dung của CX tuy nhiên chúng lại tác động đến cờ CF và SF do đó trong trường hợp đặc biệt khi CX chứa 0 thì ZF = 1 và vì vậy nó có thể được dùng thay thế cho lệnh :
 
`CMP	CX,0`

 - Để kiểm tra xem nội dung của một thanh ghi có bằng 0 hay không hoặc để kiểm tra dấu của số chứa trong thanh ghi.
####2.2 lệnh NOT <a name="2.2"></a>

 - Lệnh NOT dùng để lấy bù 1 của một toán hạng đích, cú pháp như sau:

`NOT	toán hạng đích`

 - Lệnh này không làm ảnh hưởng tới các cờ.
**Ví dụ 5:**
**Trả lời :**
 - Dùng lệnh NOT :

`NOT 	AX`

####2.3 Lệnh TEST <a name="2.3"></a>

- Lệnh TEST thự hiện các thao tác và logic giữa toán hạng đích với toán hạng nguồn nhưng không làm thay đổi toán hạng đích. mục tiêu cuâe lệnh TEST là thiết lập cờ . Cú pháp :

`TEST 	toán hạng đích,toán hạng nguồn`

- Các cờ bị tác động:
  
 <ul>
 <li> SF,ZF,PF phản ánh kết quả </li>
 <li> AF không xác định</li>
 <li> CF,OF = 0</li>
 </ul>

**Kiểm tra các bit**

- Lệnh TEST có thể sử dụng để kiểm tra các bit ruêng biệt trong một toán hạng. mặt nạ có giá trị 1 ở các bit tương ứng với các bit cần kiểm tra trong toán hạng đích và giá trị 0 ở các bit khác. vì 1 AND b =b và 0 AND b =0 kết quả của lệnh :

`TEST		toán hạng đích,mặt nạ`

 - Sẽ có giá trị 1 ở các bit đã chọn khi và chỉ khi toán hạng đích cũng có giá trị 1 ở các vị trí đó, còn lại các bit khác có giá trị 0. nếu toán hạng đích có giá trị 0 ở tất cả các bit được kiểm tra thì kết quả sẽ bằng 0 và cờ ZF được thiết lập 1.

**Ví dụ 6:** viết đoạn lệnh thực hiện lệnh nhảy đến nhãn BELOW nếu AL chứa số chẵn.
**Trả lời :**
 - Vì các số chẵ có bit 0 bằng 0 nên mặt nạ là 00000001b =1. chúng ta có: 
 
```
 TEST 	AL,1	;AL chứ số chẵn?
 JZ 	BELOW	; đúng! nhảy đến BELOW
```

###3. Các lệnh dịch 
 
 - Các lệnh dịch và quay dịch các bit trong toán hạng đích sang trái hoặc phải một hoặc một số vị trí. đối với lệnh dịch các bit bị dịch ra khỏi toán hạng sẽ bị mất, còn đối với lệnh quay các bit dịch ra khỏi một phía của toán hạng đích sẽ được đưa trở lại phía kia. các lệnh này có 2 dạng sau:

- Khi muốn dịch hoặc quay 1 vị trí chúng ta có:
 
 ` Mã lệnh		toán tử đích,1`

 - Khi muốn dịch hoặc quay N vị trí chúng ta có:

 `mã lệnh 	toán hạng đích, CL`
 
 - Trong đó CL chứa N. trong cả 2 trường hợp toán hạng đích là một thanh ghi 8 hay 16 bit hay là một ô nhớ. chú ý rằng trong các bộ vi xử lý tiên tiến của INTEL, các lệnh quay hoặc dịch cho phép sử dụng các hằng số 8 bit. như chúng ta sẽ thấ ngay sau đâu các lệnh này có thể dùng để nhân hoặc chia cho lũy thừa của 2, và chúng ta sẽ sử dụng chúng trong các chương trình vào ra với số nhị phân và số hex.

####3.1 các lệnh dịch trái <a name="3.1"></a>

**Lệnh SHL**
 
 - Lệnh SHL (shift left) dịch các bit của toán hạng đích sang bên trái, cú pháp cho lệnh dịch một vị trí như sau:
`SHL		toán hạng đích,1 `
 - Một giá trị 0 sẽ được đưa vào vị trí bên phải nhất của toán hạng đích , còn bít msb của nó sẽ được đưa vào cờ CF 
 - Nếu số đếm vị trí dịch N khác 1 thì lện có dạng như sau:

`SHL		toán hạng đích,CL`

  - Trong đó CL chứ N. trong trường hợp này N phép dịch trái đơn được thực hiện. giá trị CL vẫn giữ nguyên không thay đổi khi lệnh thực hiện xong.
   - Các cờ bị tác động:
   	- SF,PF,ZF phản ánh kết quả
   	- AF không xác định
   	- CF chứ bit cuối cùng được dịch ra khỏi toán hạng
   	- OF bằng 1 nếu kết quả bị thay đổi dấu trọng phép dịch cuối cùng.
   
   ![SHL](http://i.imgur.com/qLYJqku.png)

** Ví dụ 7:** giả sử DH chứ *Ah và CL chứ 3, cho biết giá trị của Dh và CF u khi lệnh: `SHL		DH,CL ` được thực hiện

**Trả lời:**

 - Giá trị nhị phân trong DH là 10001010. sau 3 lần dịch CF sẽ chứa giá trị 0 còn nội dung của DH có thể nhận được bằng cách xóa đi 3 bit bên trái nhất của DH và thêm 3 bit 0 vào bên phải của nó. bởi vậy chúng ta nhận được kết quả :01010000b = 50h.

**Thực hiện phép nhân bằng cách dịch trái**
 
 - Giả sử có số thập phân 235, nếu mỗi chữ số của nó được dịch sang bên trái một vị trí và thêm vào bên phải chữ số 0 thì ta nhận được 2350 có nghĩa là bằng 235 nhân 10.
 - Tương tự như vậy việc dịch trái một số nhị phân cũng nhân nó với 2. ví dụ AL chứ 5 =00000101b. sau khi dịch trái một bit chúng ta có 00001010b = 10d ngĩa là bằng 2 nhân 5 . tiếp tục dịch trái chúng ta nhận được 00010100b = 20d nghĩa là lại nhân đôi nó 1 lần nữa.

**Lệnh SAL**
 
 - Như vậy lệnh SHL có thể dùng để nhân một toán hạng với lũy thừa của 2 tuy nhiên để làm nỗi bật bản chất số học của thao tác, lệnh SAL (shift arithmetic left) thường được sử dụng để thay cho việc nhân các số. cả 2 lệnh đề tạo ra cùng một mã máy.

 - Các số âm củng có thể được nhân 2 bằng cách dịch trái. ví dụ nếu Ã chứa FFFh(-1) chúng ta dịch trái nó 3 bit thì sẽ nhận được AX = FFF8h (-8).

**Sự tràn **
 
 - Khi chúng ta sử dụng lệnh dịch trái để làm phép nhân hiện tượng tràn có thể xảy ra. với lệnh dịch trái một bit CF và OF tương ứng chỉ ra một cách chính sác sự tràn không dấu và có dấu. tuy nhiên cờ tràn không còn đáng tin cậy trong lệnh dịch trái nhiều bit. sỡ dĩ như vậy vì lệnh dịch nhiều bit thực ra là nhiều lệnh dịch 1 bit, và cờ CF, OF chỉ phản ánh kết quả của sự dịch cuối cùng . Ví dụ khi BL chứ 80h,CL chứ 2 và chúng ta thực hiện ` SHL 	BL,CL ` thì CF = OF = 0 mặc dù cả 2 hiện tượng tràn có dấu và không dấu đều xảy ra

**Ví dụ 8:** viết một đoạn lệnh thực hiện phép nhân AX với 8, giả sử hiện tượng tràn không xảy ra.
**Trả lời :**
 
 - Để thực hiện phép nhân 8 chúng ta cần thực hiện 3 lần dịch trái:

```
MOV 	CL,3 	;số lần dịch
SHL		AX,CL	; nhân AX với 8
```

####3.2 Các lệnh dịch phải <a name="3.2"></a>

**Lệnh SHR**
 
 - Lệnh SHR (shift right) dịch các bit của toán hạng đích sang bên phải cú pháp cho câu lệnh ịch một vị trí như sau:

```
SHR		toán hạng đích,1
```

 - Một giá trị 0 sẽ được đưa vào bit MSB của toán hạng đích , còn bên phải nhất của nó (lsb) sẽ được đưa vào cờ CF.
 - Nếu số đếm vị trí dịch N khác 1 thì lệnh có dạng sau:

```
SHR 	toán hạng đích,CL
```
 
 - Trong đó CL chứ N . trong trường hợp này N phép dịch phải đơn được thực hiện. giá trị của CL vẫn giữ nguyên không đổi khi lệnh thực hiện xong . 
 - Các cờ bị tác động cũng giống như trong trường hợp dịch trái.

![SHR](http://i.imgur.com/4YVtEmI.png)

**Ví dụ 9:** giả sử DH chứa 8Ah và CL chứa 2 , cho biết giá trị của DH và CF sau lệnh SHL 	DH,CL được thực hiện
**Trả lời:**
 
 - Giá trị nhị phân trong DH là 10001010. sau 2 lần dịch CF sẽ chứa giá trị 1 còn nội dung của DH có thể nhận được bằng cách xóa đi 2 bit bên trái nhất của DH và thêm 2 bit 0 vào bên phải nó. bởi cậy chúng ta nhận được kết quả 00100010b = 22h

** Lệnh SAR**
 
 - Lệnh SAR (shift arimethic right) làm việc gần giống lệnh SHR với một điểm khác biệt là bit msb của toán hạng đích giữ nghuyên giá trị ban đầu của nó. cú pháp như sau:

 ```
 SAR 	toán hạng đích,1
 và
 SAR	toán hạng đích,CL
 ```

  - Các cờ bị tác động giống như lệnh SHR

**Thực hiện phép chia bằng phép dịch phải**

 - Vì việc dịch trái nhân đôi giá trị của toán hạng đích cho nên cũng có lý do khi đoán rằng dịch phải sẽ chia đôi nó. điều đó đúng cho các số chẵn, đối với số lẽ , dịch phải sẽ chia đôi nó và làm tròn xuống số nguyên gần nhất. ví dụ nếu BL chứa 00000101b =5 thì sau khi dịch phải BL sẽ chứa 00000010 = 2.
**Phép chia không dấu và có dấu**
 - Trong phép chia bằng cách dịch phải chúng ta phải phân biệt 2 trường hợp đối với các số không dấu và có dấu. nếu đang làm việc với các số không dấu chúng ta phải sử dụng lệnh SAR vì lệnh này giữ nguyên dấu.

![SAR](http://i.imgur.com/4YVtEmI.png)

**Ví dụ 10:** sử dụng các phép dịch phải để thực hiện phép chia số không dấu 65143 cho 4, thương số chứa trong AX,
**Trả lời :** 
 - Để chia cho 4 chúng ta cần dịch phải 2 lần, do số bị chia là số không dấu chúng ta sử dụng lệnh SHR. đoạn lệnh như sau:

```
 MOV	AX,65143	;AX chứa số bị chia
 MOV	CL,2		;CX chứa số lần dịch phải 
 SHR 	AX,CL		;chia cho 4
```

**Ví dụ 11:** giả sử AL chứa -15, hãy cho biết giá trị thập phân của Al sau khi thực hiện lệnh SAR 	AL,1.
**Trả lời :**
 - Lệnh SAR chia số cho 2 và làm tròn xuống. chia -15 cho 2 chúng ta nhận được -7,2 sau khi làm tròn chúng ta nhận được -8. dưới dạng số nhị phân chúng ta có -15 = 11110001b. sau khi dịch phải chúng ta có 11111000b =-8.

**Các phép nhân và chia tổng quát hơn**
 - Chúng ta đã thấy rằng việc nhân và chia cho lũy thừa của 2 có thể thực hiện bằng các lệnh dịch trái và phải. để nhân với một số bất kỳ như 10d chúng ta có thể kết hợp các lệnh dịch và cộng.

###4. Các lệnh quay <a name="4"></a>

**Lệnh quay trái**
 - Lệnh ROL (rotate left) dịch các bit sang bên trái. bit msb được dịch vào bit bên phải nhất đồng thời được đưa vào cờ CF. các bạn có thể tưởng tượng các bit của toán hạng đích tạo thành một vòng trong với bit lsb . Cú pháp:

```
ROL		toán hạng đích,1
và 
ROL		toán hạng đích, CL
```

**Lệnh quay phải**
 - Lệnh ROR( rotate right) làm việc giống như lệnh ROL trừ một điểm khác biệt là các bit được dịch sang phải, bit bên phải nhất được dịch vào bit msb đồng thời cũng được đưa vào cờ CF. cú pháp của lệnh:

```
ROR		toán hạng đích,1
và 
ROR		tón hạng đích, CL
```

- Lệnh quay trái:
![ROL](http://i.imgur.com/p8UDRb6.png)

- Lệnh quay phải:
![ROR](http://i.imgur.com/VJ24p8J.png)

- Trong các lệnh ROL, ROR cờ CF chứa bit bị dịch ra khỏi toán hạng. ví dụ sau sẽ trình bày một phương pháp để xác định các bit trong môt byte hay word mà không làm thay đổi nội dung của nó.

**Ví dụ 12** sử dụng lệnh ROL để đếm số bit 1 trong thanh BX mà không làm thay đổi nội dung của nó, kết quả trong AX.

**Lời giải:**

```
	XOR		AX,AX		;AX đếm số bit
	MOV		CX,16		;biến đếm vòng lặp
TOP:
	ROL		BX,1		;CF chứa bit bị đưa ra
	JNC		NEXT		;bit 0?
	INC		AX			;không phải !, tăng số bit lên 1
NEXT:	
	LOOP	TOP:		;nhay trở lại top cho đến khi xong
```
 
 - Trong ví dụ trên đây, chúng ta đã sử dụng lệnh JNC(jump if no carry), lệnh này thực hện nhảy nếu CF = 0. trong phần 7.4 chúng ta sẽ sử dụng để đưa ra nội dung của một thanh ghi dưới dạng nhị phân.

**Lệnh quay trái qua cờ nhớ**

 - Lệnh RCL (rotate carry left) dịch các bit của toán hạng đích sang trái. bit msb được đặt vào cờ CF, giá trị cũ của CF được đưa vào bit phải nhất của toán hạng đích. Nói cách khác RCL làm việc giống như ROl ngoại trừ một điều là cờ CF cũng là một phần của vòng tròn tạo lên bởi các bit đang được quay . Cú pháp:

```
	RCL		toán hạng đích, 1 
hay
	RCL 	toán hạng đích,,CL
```

**Lệnh quay phải qua cờ nhớ**

 - Lệnh RCR (rotate carry right) hoạt động giống như lệnh RCL nhưng các bit được quay sang hải, cú pháp của lệnh như sau:

```
	RCR		toán hạng đích,1
hay
	RCR		toán hạng đích,CL
```

- Hình ảnh minh họa cho lệnh RCR:

![RCR](http://i.imgur.com/W5oNQWP.png)

- Hình ảnh minh họa cho lệnh RCL

![RCL](http://i.imgur.com/ctFogus.png)

**Ví dụ 13:** Giả sử DH chứa 8Ah, CF =1 , và CL bằng 3. cho biết nội dung của DH và CF khi thực hiện lệnh `RCR	DH,CL`?

**Trả lời :**

|  | CF | DH |
|--|----|----|
| các giá trị đầu | 1 | 10001010|
|sau 1 lần dịch | 0 | 11000101 |
|sau 2 lần dich | 1 | 01100010 |
|sau 3 lần dịch | 0 | 10110001 |

 - Như vậy sau khi thực hiện lệnh DH chứ 10110001b = B1h 
 - Tác động của các lệnh quay đến cờ
  
  <ul>
  <li>SF, PF, ZF phán ánh kết quả </li>
  <li>AF không xác định </li>
  <li>CF = bit cuối cùng bị dịch ra khỏi toán hạng </li>
  <li>OF = 1 nếu kết quả đổi dấu trong lần quay cuối</li>
  </ul>

**Một số ứng dụng: đảo các mẫu bit**

 - Chúng ta hãy xem xét vẫn đề đảo các mẫu bit trong một byte hoặc một word để làm một ví dụ về ứng dụng của các lệnh quay và dịch. chẳng hạn AL chứ 11011100 chúng ta muốn đổi thành 00111011. một phương pháp đơn giản là sử dụng lệnh SHL để dịch các bit ra khỏi đầu bên trái của AL rồi dùng lệnh RCR để đưa nó vào đầu bên trái của một thanh ghi khác như BL chẳng hạn sau khi lặp lại công việc đó 8 lần BL sẽ chứa các mẫu bit đã đảo ngược của AL và có thể chép lại nộ dung của nó vào AL đoạn lệnh như sau:

```
MOV		CX,8		;lấy số lần thực hiện
REVERSE:		
SHL		AL,1		;lấy bit vào CF
RCR		BL,1		;quay để đưa nó vào BL
LOOP 	REVERSE 	;lặp cho đến khi DO xong
MOV		AL,BL 		;AL chứa mẫu bit đảo ngược
```
