###Lập trình hợp ngữ (Assembly)

> Tài liệu tham khảo: Giáo trình Assembly
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối: 12 - 1 - 2016

----

###Mục lục:

- [1. Lệnh nhảy](#muc1)

- [2. Các lệnh so sánh](#muc2)

- [3. Cấu trúc rẽ nhánh](#muc3)

- [4. Vòng lặp For, While](#muc4)

----

###Tổng quan:

- Để đảm bảo thực hiện được các công việc có ích, các chương trình bằng Hợp ngữ phải có các phương pháp chọn lựa và lặp lại các đoạn mã lệnh. Trong phần này, sẽ chỉ ra các phương pháp đó được thực hiện như thế nào nhờ các lệnh nhảy và lặp.
- Các lệnh nhảy và lập chuyển điều khiển cho các phần khác trong chương trình. Sự chuyển giao này có thể khong có điều kiện, có thể phục thuộc vào các tổ hợp riêng rã các cờ trạng thái.
- Sau khi làm quen với các cấu trúc nhảy, chúng ta sẽ sử dụng chúng để thực hiện các cấu trúc chọn lựa và lặp của ngôn ngữ bậc cao. Các ứng dụng này sẽ làm cho việc đổi một thuật toán với các lệnh giải sang các lệnh **hợp ngữ** dễ dàng hơn.

<a name="muc1"> </a>

###1. Lệnh nhảy:

<a name="muc1.1"> </a>

####1.1 Một ví dụ về lệnh nhảy:

- Để bạn có khái niệm về cách thức làm việc của cấu trúc nhảy, ta sẽ viết một chương trình hiển thị toàn bộ tập ý tự của IBM

- Chương trình:

```
title PGM6_1 ;hien thi cac ky tu IBM
.MODEL SMALL
.STACK 100h
.CODE
MAIN PROC
    MOV Ah,2    ;hien thi ky tu
    MOV CX,256  ;so ky tu duoc hien thi
    MOV DL,0    ;DL chua ma ASCII ky tu NULL
   print_loop:
    int 21h
    inc dl      ;tang ma ascii
    dec cx      ;giam bo dem
    jnz print_loop      ;lap lai neu cx khac 0
   ;dos
    mov ah,4ch
    int 21h
   main endp
end main
```

- **Kết quả:**

<img src="http://i.imgur.com/hfN31cM.png">

-Tập hợp ký tự IBM bao gồm 256 ký tự. Các ký tự có mã từ 32 đến 127 là các ký tự ASCII chuẩn in được đã giới thiệu trong phần trước. IBM cũng cung cấp một hệ thống các ký tự đồ hoạ có mã từ 0 đến 32 và từ 128 đến 255.
- Để hiện thị các ký tự chúng ta dùng một vòng lặp (từ dòng 9 đến dòng 13). Trước khi vào vòng lặp AH được khởi tạo giá trị 2 (hàm hiển thị một ký tự) và DL được đặt bằng 0 là mã ASCII ký tự đầu tiên. CX là bộ đếm vòng lặp, nó được đặt bằng 256 trước khi vào vòng lặp và giảm 1 sau khi mỗi ký tự được hiển thị.
- Lệnh JNZ (**Jump of NOT ZERO**) điều khiển vòng lặp. Nếu kết quả của lệnh kế trước (Dec cx) khác 0, lệnh JNZ sẽ chuyển điều khiển đến lệnh có nhã PRINT_LOOP. Cuối cùng khi DX bằng 0 chương trình tiếp tục thực hiện các lệnh trở về DOS. Tất nhiên với các mã ASCII của các ký tự điều khiển như lùi một ký tự, về đầu dòng v.v.. các chức năng điều khiển sẽ được thực hiện thay vì hiển thị chúng.
- Lưu ý: `Print_loop` là nhãn dòng lệnh lần đầu tiên chúng ta sử dụng trong một chương trình. Các nhãn cần thiết khi một lệnh trỏ đến các lệnh khác giống như trong trường hợp trên. Nhã kết thúc bằng dấu hai chấm và để dễ nhận ra, chúng được đặt riêng một dòng. Các nhã tham trỏ tới lệnh ngay sau chúng.

<a name="muc1.2"> </a>

####1.2 Các lệnh nhảy có điều kiện:

- JNZ là một ví dụ của lệnh **nhảy có điều kiện**. Cú pháp:

- `JNZ nhãn_đích`

- Nếu như điều kiện của lệnh nhảy được thoả mãn, lệnh có `nhãn_đích` sẽ được thi hành. Lệnh này cso thể ở trước hoặc sau lệnh nhảy. Nếu điều kiện không thoả mãn, lệnh ngay sau lệnh nhảy được thi hành. Với lệnh JNZ điều kiện này là kết quả của lệnh trước nó khác 0.

- **Phạm vi của lệnh nhảy có điều kiện**

- Cấu trúc mã máy của lệnh nhảy có điều kiện đòi hỏi `nhãn_đích` phải đứng trước lệnh nhảy không quá 126 byte haowjc đúng sau không quá 127 byte.

- **CPU thực hiện một lệnh nhảy như thế nào?**

- Để thực hiện một lệnh nhảy, CPU nhìn vào thanh ghi cờ. Ta đã biết rằng thanh ghi phản ánh kết quả công việc gần nhất mà bộ vi xử lý thực hiện. Nếu điều kiện của lệnh nhảy (được phát biểu như một tổ hợp các sự lập cờ trạng thái) thoả mãn. CPU điều chỉnh IP trỏ đến nhãn đích và như thế lệnh ở sau nhãn này được thi hành tiếp theo. Nếu điều kiện nhảy không thoả mãn, IP không bị sửa đổi. Điều này có nghĩa là lệnh trên dòng tiếp theo sẽ được thi hành.

- Trong chương trình trên. CPU thi hành lệnh JNZ PRINT_LOOP phụ thuộc vào ZF. Nếu ZF = 0 điều khiển sẽ được chuyển tới nhãn PRINT_LOOP, nếu ZF = 1 chương trình tiếp tục thực hiện lệnh MOV AH,4CH

- **Lưu ý:** Các lệnh nhảy tự nó không ảnh hưởng tới các cờ.

- Cột đầu tiên là mã lệnh nhảy. Rất nhiều lệnh nhảy có hai mã lệnh. Cả hai mã lệnh này có cùng một mã máy. Khi thực hiện chúng cho kết quả hoàn toàn giống nhau.

- **Các lệnh nhảy:**

<img src="http://i.imgur.com/L9Om5k8.png">

- **Lệnh Jmp**

- Lệnh `jmp` (jump) dẫn đến việc chuyển điều khiển không điều kiện (nhảy không điều kiện). Cú pháp:

- `JMP đích`

- Ở đây đích phải là một nhã trong cùng một đoạn với JMP

- JMP có thể được dùng để khắc phục khoảng giới hạn của lệnh nhảy có điều kiện. Ví dụ: Giả sử chúng ta muốn tực hiện vòng lặp:

```
TOP:
;thân vòng lặp
	dec cx 		; giảm bộ đếm
	jnz top 	; lặp nếu cx > 0
	mov ax, bx 	
```

- Nhưng thân vòng lặp lại chứa quá nhiều lệnh đến mức nhãn Top nằm ngoai khoảng giới hạn của lệnh JNZ (nhiều hơn 126 byte trước jnz top). Chúng ta có thể sửa lại:

```
top:
; thân vòng lặo
	dec cx 	;giảm bộ đếm
	jnz bottom	; lặp nếu cx > 0
	jmp exit
bottom: jmp top
exit: 
```

<a name="muc2"> </a>

###2. Câu lệnh so sánh:

- **Lệnh CMP**

- Các điều kiện nhảy thường được cung cấp bởi lệnh CMP (compare). Nó có dạng sau:

- `cmp đích, nguồn`

- Lệnh này so sánh toán tử đích với toán tử nguồn bằng cách lấy toán tử đích trừ đi toán tử nguồn. Kết quả được lưu lại nhưng các cờ bị ảnh hưởng. Các toán hạng của lệnh CMP không thể cùng là các ô nhớ. Toán hạng đích không phép là hằng số. **Chú ý:** CMP giống hệt như SUB ngoại từ việc toán hạng đích không thay đổi.

- **Ví dụ:** Giả thiết chưogn trình chứa hai dòng lệnh sau đây:

```
CMP AX,BX
JG BELOW
```

- Ở đây AX=7FFFh, BX=0001. Kết quả so sánh AX và BX là 7FFFh - 0001h = 7FFEh.
- Bảng các lệnh nhảy chỉ ra rằng điều kiện nhảy cho lệnh JG đã được thoả mãn bởi vì ZF = SF = OF = 0, và do đó điều khiển được chuyển đến nhãn BELOW

- **Dịch các lệnh có điều kiện**

- Trong ví dụ vừa nêu, khi xem xét các cờ sau lệnh `cmp` ta thấy rằng điều khiển sẽ được chuyển đến nhãn BELOW. Đó cũng là cách CPU thực hiện một lệnh nhảy có điều kiện. Người lập trình không cần thiết là phải suy nghĩa nhiều về các cờ, bạn có thể chỉ dùng tên của lệnh nhảy để quyết định việ chuyển điều khiển đến nhãn đích. Các lệnh sau đây:

```
cmp ax,bx
jg below`
```

- Nếu như AX lớn hơn BX (coi là số có dấu) thì JG (jump if greater than) sẽ chuyển đến Below
- Đặc biệt cả khi nghĩ rằng lệnh `cmp` được thiết kế chỉ dùng cho các lệnh nhảy có điều kiện, chúng vẫn có thể đi kèm với các lệnh khác như trong chương trình PGM6_1. Một ví dụ khác:

```
DEC AX
JL THERE
```

- Trường hợp này nếu nội dung của AX (coi là số có dấu) nhỏ hơn 0, điều khiển sẽ được chuyển đến There.

- **So sánh các lệnh nhảy có dấu và không dấu**

- Mỗi lệnh nhảy có dấu đều tương ứng với một lệnh nhảy không dấu. Ví dụ lệnh nhảy có dấu JG và lệnh nhảy khong dấu JA. Dùng lệnh nhảy có dấu hay không dấu tuỳ thuộc vào kiểu số được đưa ra. Trên thực tế, như bảng các lệnh nhảy chỉ ra, các lệnh này thao tác với các cờ khác nhau: Các lệnh nhảy có dấu sử dụng các cờ ZF, SF và OF trong khi các lệnh nhảy không dấu lại dùng các cờ ZF và CF. Sử dụng không đúng loại có thể đưa đến kết quả sai.

- Ví dụ: Giả thiết rằng chúng ta làm việc với các số không dấu. Nếu như AX = 7FFFh và BX = 8000h, khi ta thực hiện:

```
cmp AX,BX
JA BELLOW
```

- Thậm chí 7FFFh > 8000h trong dạng có dấu, chương trình vẫn không nhảy đến nhãn BELOW. Nguyên nhân ở đây là 7FFFh < 8000h ở dạng không dấu và ở đây chúng ta lịa dùng lệnh nhảy không dấu JA

- **Làm việc với các ký tự**

- Khi làm việc với tập hợp ký tự ASCII chuẩn cả các lệnh nhảy có điều kiện và không điều kiện đều có thể sử dụng bởi lẽ bỉt dấu của byte chứa mã ký tự luôn là 0. Dù sao thì các lệnh nhảy không dấu phải được sử dụng khi so sánh các ký tự ASCII mở rộng (mã từ 80h đến FFh).

- **Ví dụ 6.1:**

	- Giả sử AX và BX chứa các số có dấu. Hãy viết các lệnh để đưa số lớn nhất vào CX

- **Trả lời**

```
mov cx,ax 	;đưa ax vào cx
cmp bx, cx 	; bx lớn hơn
jle next	;không, tiếp tục
mov cx, bx 	; đúng, đưa bx vào cx
next:
```

**Các cấu trúc ngôn ngữ bậc cao.**

- Chúng tôi đã có lần nói rằng cấu trúc nhảy có thể được dùng để thực hiện các công việc rẽ nhánh và lặp. Tuy nhiên do các lệnh nhảy quá sơ khai nên rất khó mã hoá một thuật toán (có haowjc không có các dòng hướng dẫn) nhất là đối với những người mới lập trình.

- Bởi vì đa số các bạn đã có chút ít kinh nghiệm về các cấu trúc của ngôn ngữ bậc cao như cấu trúc chọn lựa IF _ Then _ Else hay các vòng lặp While. Chúng tôi sẽ nêu ra cách giải lặp các cấu trúc này trong ngôn ngữ hợp ngữ. Trong trường hợp đầu tiên chúng tôi sẽ đưa ra cấu trúc các toán tử giả của ngôn ngữ bậc cao.

<a name="muc3"> </a>

###3. Các cấu trúc rẽ nhánh:

- Trong các ngôn ngữ bậc cao, các cấu trúc rẽ nhánh của một chương trình để chọn các đường dẫn khác nhau và phụ tuộc vào các điều kiệ. Phần này ta sẽ xem xét 3 cấu trúc:

```
If điều_kiện
	then
		nhánh_đúng
End_if
```

<img src="">

- Điều_kiện là một biểu thức có thể đúng hoặc sai. Nếu nó đúng, nhánh_đúng sẽ được thực hiện. Ngược lại, cấu trúc không thực hiện lệnh nào, chương trình tiếp tục thực hiện với các lệnh sau.

- **Ví dụ 6.2:** Thay số trong AX bằng giá trị tuyệt đối của nó
- **Trả lời:** Một thuật toán với mã lệnh giải:

```
IF AX > 0
then
	thay ax bằng -ax
end_if
```

<img src="">

- Nó có thể được mã hoá như sau:

```
; if ax < 0
	cmp ax,0		;ax < 0
	jnl End_if 		; không, thoát ra
; then
	NEG ax 			; đúng, đổi dấu
END IF:
```

- Điều kiện AX < 0 được kiểm tra bởi lệnh `CMP AX,0`. Nếu AX không nhỏ hơn 0, ta không phai làm gì cả, JNL được dùng để nhảy qua lệnh NEG AX, nếu điều kiện AX < 0 thoả mãn, chương trình tiếp tục thực hiện lệnh NEG AX.

```
IF_THEN_ELSE.

IF điều_kiện
then
	nhánh_đúng
else
	nhánh_sai
End_if
```

<img src="">

- Trong cấu trúc này nếu điều_kiện là đúng nhóm lệnh nhánh_đúng sẽ được thi hành. Còn nếu điều_kiện sai, nhóm lệnh nhánh)sai sẽ được thi hành.

- **Ví dụ 6.3:** Giả sử AL và BL chứa các ký tự ASCII mở rộng. Hãy hiện thị ký tự đứng trước trong bảng mã.

- **Trả lời:**

```
if AL <= BL
	then
		hiển thị ký tự trong AL
else
		hiển thị ký tự trong BL
End_if
```

Ta có thể mã hoá nó như sau:

```
	MOV AH,2	;chuẩn bị hiển thị
;if AL <= BL
	CMP AL,BL 	; al <= bl
	jnbe else_	;không, hiển thị ký tự trong bl
;then
	mov dl,al 	; chuyển ký tụ vào dl để hiển thị
	jmp display	;tới display
else_:
	mov dl,bl 	;chuyển ký tự vào dl để hiển thị
display:
	int 21h		;hiển thị nó.
;End_if
```

- *Chú ý:* Ta dùng nhãn `Else_` vì Else là từ dành riêng.

- Điều kiện AL <= BL được kiểm tra bởi lệnh CMP AL,BL. Nếu nó sai, chương trinhg sẽ nhảy qua `nhánh_đúng` tới ELSE. Chúng ta sử dụng lệnh nhảy không dấu JNBE bởi lẽ chúng ta đang so sánh các kí tự mở rộng.
- Nếu AL <= BL thoả mãn, `nhánh_đúng` được thực hiện. Lưu ý rằng chỉ thị JMP DISPLAY là cần thiết để nhảy qua `nhánh_sai`. Điều này khác trong với ngôn ngữ bậc cao: nhánh_sai được tự động nhảy qua nếu nhánh đúng được thực hiện.

- **CASE**

- CASE là một cấu trúc đa nhánh, nó kiểm tra các thanh ghi, các biến hay các biểu thức với các giá trị riêng rx trong miền giá trị. Dạng tổng quát của nó là:

```
	CASE phát_biểu
		giá_trị_1: Dòng_lệnh_1
		giá_trị_2: dòng_lệnh_2
		.
		.
		giá_trị_n: dòng_lệnh_n
	end_case
```

<img src="">

- Trong cấu trúc này phát_biểu được kiểm tra, nếu giá trị của nó bằng với giá_trị_i thì dòng_lệnh_i sẽ được thi hành. Ta giả thiết tập hợp giá_trị_1... giá_trị_n tách biệt nhau

- **Ví dụ 6.4** Nếu Ax chứa một số âm, hãy nhập -1 vào BX, nếu AX chứa 0, cho BX bằng 0, nếu AX dương đổi BX thành 1.

- **Lời giải**

```
CASE AX

	<0: gán BX bằng -1
	=0: gán BX bằng 0
	>0: gán BX bằng 1
End_case
```

- Ta có thể mã hoá như sau:

```
;case ax
	cmp ax,0	;kiểm tra ax
	jl nagative	;ax<0
	je zero 	;ax=0
	jg positive	;ax>0
negative:
	mov bx,-1	;nhập -1 vào bx
	jmp end_case ;rồi thoát
zero:
	mov bx,0	;nhập 0 vào bx
	jmp End_case ;rồi thoát
positive:
	mov bx,1	;nhập 1 vào bx
end_case:
```

- **Các nhánh với điều kiện kép:**

- Đôi khi điều kiện nhánh của IF hay CASE có dạng:
- `điều_kiện_1 AND điều_kiện_2`
- hay
- `điều_kiện_1 OR điều_kiện_2`
- Ở đây điều_kiện_1 và điều_kiện_2 có thể đúng hoặc sai. Đầu tiên chúng ta hãy xem xét điều kiện AND (AND condition), sau đso đến điều kiện OR(Or condition).

- **Các điều kiện AND**

- Điều kiện AND chỉ đúng khi cả hai điều kiện: `điều_kiện_1` và `điều_kiện_2` cũng đúng. Ngược lại nếu một trong chúng sai, điều kiện AND cũng sẽ sai.
- **Ví dụ 6.6:** Đọc một ký tự. Nếu là chữ hoa thì hiển thị nó.

- **Lời giải:**

```
Đọc 1 ký tự (vào DL)
IF ('A' <= ký_tự) và (ký_tự <= 'Z')
Then
	hiển thị ký tự
End_if
```

- Để mã hoá, đầu tiên chúng ta kiểm tra xem ký tự trong AL có đứng sau 'A' trong bảng mã hay không, nếu sai ta có kết thúc. Nếu đúng, trước khi hiểu thị ký tự ta vẫn còn phải kiểm tra ký tự có đứng trước 'Z' hay không. Sau đây là mã lệnh:

```
;đọc một ký tự
	mov ah,1	;chuẩn bị đọc
	int 21h 	;ký tự vào al
;if ('A' <= ký_tự) và (ký_tự <= 'Z')
	cmp al,'A'	;ký_tự >='A'>
	jnge end_if ;không thoát ra
;then hiển thị ký tự
	mov dl,AL 	;lấy ký tự
	mov ah,2	;chuẩn bị hiển thị
	int 21h		;hiển thị ký tự
end_if:
```

- **Các điều kiện OR**

- Điều_kiện_1 OR Điều_kiện_2 là đúng khi điều_kiện_1 hoặc điều_kiện_2 đúng. Nó chỉ sai khi cả hai điều kiện thành phần cùng sai.

- Ví dụ 6.7: Đọc một ký tự. Nếu 'y' hay 'Y' thì hiển thị nó. Nếu ngược lại, kết thức chương trình.

- **Lời giải:**

```
Đọc một ký tự (vào AL).
IF (ký_tự - 'Y') hoặc (ký_tự = 'Y')
THEN
	hiển thị ký tự
Else
	kết thúc chương trình.
End_if
```

- Để mã hoá, đầu tiên chúng ta sẽ kiểm tra ký_tự ='y'?. Nếu thoả mãn, điều kiện OR đúng và chúng ta có thể thực hiện dòng lệnh THEN. Ngược lại vẫn cơ hội để điều kiện OR đúng, đó là khi ký_tự bằng 'Y', và dòng lệnh Then vẫn được thi hành. Nếu điều này vẫn sai, điều kiện OR là sai và chúng ta sẽ thực hiện dòng lệnh ELSE. Sau đây là mã lệnh

```
;đọc một ký tự
	mov ah,1	;chuẩn bị đọc
	int 21h 	;ký tự trong AL
;if (ký_tự='y') hoặc (ký_tự = 'Y')
	cmp al,'y'	;ký_tự ='y'?
	je Then 	;đúng, chueyẻn đến hiển thị ký tự
	cmp al,'Y' 	;ký_tự = 'Y'
	je then 	;đúng, chuyển đến hiển thị ký tự
	je then 	;đúng, chuyển đến hiển thị ký tự
	jmp else_ 	;sai, kết thúc
then:
	mov ah,2 	;chuẩn bị hiển thị
	mov dl, al 	;lấy ký tự
	int 21h 	;hiển thị nó
	jmp end_if 	;và thoát ra
else_:
	mov ah,4ch 	;
	Int 21h 	;trở về dos
end_if
```

<a name="muc4"> </a>

###4. Cấu trúc lặp:

- Một vòng lặp là một chuỗi các lệnh được lặp lại. Số lần lặp có thể đã xác định trước hoặc phụ thuộc vào các điều kiện

- **Vòng lặp for**

- Đây là một cấu trúc lặp mà số lần lặp lại các dòng lệnh đã biết trước (vòng lặp điều khiển bằng biến đếm). Dạng mã lệnh giả:

```
FOR số_lần_lặp do
	các dòng lệnh
End_for
```

<img src="">

- Ta có thể sử dụng lệnh LOOP để thực hiện vòng lặp FOR. Lệnh này có dạng:

- `LOOP nhãn_đích`

- Bộ đếm vòng lặp là thanh ghi CX được khởi tạo bằng số_lần_lặp. Mỗi lần thực hiện lệnh LOOP, thanh gh CX tự động giảm đi 1 và nếu CX khác 0 thì điều khiển được chuyển tới nhãn đích. Nếu CX = 0, lệnh tiếp sau lệnh LOOP sẽ được thi hành. Nhãn đích phải ở trước lệnh lặp khôg quá 126 byte
- Vòng lặp FOR có thể được thực hiện nhờ lệnh LOO{ như sau:

```
;khởi tạo CX bằng số_lần_lặp
TOP:
	;thân vòng lặp
	LOOP Top
```

- **Ví dụ 6.8:** Viết một vòng lặp điều khiển bằng biến đếm hiển thị một dòng 80 dấu *

- **Lời giải:**

```
For 80 times DO
	hiển thị '*'
End_for
```

- Mã lệnh là:

```
	MOV CX,80 	;số các dấu sao được hiển thị
	MOV AH,2 	;hàm hiển thị ký tự
	MOV DL,'*' 	;ký tự hiển thị
TOP:
	INT 21h 	;hiển thị một dấu sao
	LOOP TOP 	;lặp lại 80 lần
```

- Bạn hãy lưu ý rằng vòng lặp FOR thực hiện bởi lệnh LOOP sẽ được thự hiện ít nhất một lần. Thực ra nếu CX bằng 0 khi vào vòng lặp, lệnh LOOP giảim CX thành 0FFFFh và lệnh LOOP sẽ được thực hiện 0FFFFh = 65535 lần nữa. Để khắc phục điều này, lệnh JCXZ (jump if CX is zero) được đặt trước vòng lặp. Cú pháp của nó là:

- `JCXZ nhãn_đích`

- Nếu CX bằng 0, điều khiển sẽ được chuyển đến nhãn đích. Như vậy vòng lặp sẽ bị bỏ qua nếu CX bằng 0:

```
	JCXZ SKIP
TOP:
	;thân vòn lặp
	LOOP TOP
SKIP:
```

- **Vòng lặp WHILE**

- Đây là vòng lặp phụ thuộc vào một điều kiện. Dạng mã lệnh giả:

```
WHILE điều_kiện DO
	Các dòng lệnh
END_WHILE
```

<img src="">

- Điều_kiện được kiểm tra ở đầu vòng lặp. Nếu nó đúng thì các dòng lệnh sẽ được thi hành. Ngược lại nếu điều_kiện sai, chương trình sẽ tiếp tục thực hiện lệnh ở sau vòng lặp. Rất có thể ngay sau khi khửoi đầu `điều_kiện` đã không thả mãn. Trong trường hợp này thân vòng lặp sẽ không được thực hiện lần nào. Vòng lặp tiếp tục được thực hiện khi điều kiện còn đúng.

- **Ví dụ 6.9:** Viết các lệnh để đếm số ký tự trong một dòng
- **Lời giải:**

```
khởi tạo bộ đếm băng 0, đọc 1 ký tự
WHILE ký tự <> ký tự về đầu dòng DO
	đếm = đếm + 1
	đọc một ký tự
END_WHILE
```

- Các lệnh là:

```
	MOV DX,0 	;dx đếm số ký tự
	mov ah, 1 	;chuẩn bị đọc
	int 21h 	;ký tự trong AL
WHILE_:
	CMP AL,0dh 	 	;CR?
	JE END_WHILE 	;đúng, thoát ra
	inc dx 			;không phải cr, tăng bộ đếm
	int 21h 		;đọc một lý tự
	jmp WHILE_ 	 	;lặp lại
end_while:
```

- Lưu ý là do vòng lặp `WHILE` kiểm tra điều kiện kết thúc ở đầu vòng lặp nên bạn cần chắc chắn rằng bất cứ biến nào liên quan đến điều kiện vòng lặp đều phải đực khởi tạo trước khi vào vòng lặp.Vì vậy bạn phải đọc một ký tự trước khi vào vòng lặp rồi lại phải đọc ký tự khác ở cuối nó. Ta dùng nhãn WHILE_ vì WHILE là từ dành riêng.

- **Vòng lặp REPEAT**

- Có một vòng lặp có điều kiện khác đó là vòng lặp `REPEAT`. Dạng mã lệnh giải của nó là:

```
REPEAT
	các dòng lệnh
UNTIL điều_kiện
```

<img src="">

- Trong một vòng lặp REPEAT...UNTIL, các dòng lệnh được thi hành sau đó mới kiểm tra điều kiện. Nếu điều_kiện đúng, vòng lặp kết thúc, nếu nó sai điều khiển rẽ nhánh đến đầu vòng lặp.

- **Ví dụ:** Viết các lệnh đọc vào các ký tự, kết thúc khi gặp một ký tự trắng:

- **Lời giải**

```
REPEAT
	đọc một ký tự
Until ký_tự_trắng
```

- Các lệnh là:

```
	MOV AH,1 		;chuẩn bị đọc
REPEAT:
	INT 21h 		;ký tự trắng trong AL
;until
	cmp al,' ' 		; ký tự trắng ?
	JNE REPEAT 		;không, đọc tiếp
```

- **So sánh while và repeat**

- Trong nhiều trường hợp khi cần một vòng lặp có điều kiện, sử dụng vòng lặp WHILE và REPEAT là tuỳ ý thích mỗi người. Ưu điểm của vòng lặp WHILE là vòng lặp có thể được bỏ qua khi điều kiện kết thúc khởi tạo với giá trị logic sai, trong khi đó các lệnh trong vòng lặp REPEAT luôn được tực hiện ít nhất một lần. Tuy nhiên các lệnh cho một vòng lặp REPEAT có vẻ ngắn hơn đôi chút bởi lẽ nó chỉ có một lệnh nhảy có điều kiện ở cuối trong khi vòn lặp WHILE có những hai: một lệnh nhảy có điều kiện ở đầu và lệnh JMP ở cuối.

###Mở rộng:

####Lập trình với các cấu trúc bậc cao:

- Để chỉ ra một chương trình có thể được phát triển từ các toán tử giả bậc cao thành các lệnh Hợp ngữ (Assembly) như thế nào, chúng ta hãy giỉa quyết vấn đề sau đây:

- **Yêu cầu:**

- Thông báo cho người sử dụng nhấp vào một dòng văn bản. Hiển thị trên dòng tiếp theo chữ hoa đầu tiên và sau cùng tính theo thứ tự mã ASCII của chuỗi vừa nhập. Nếu không có chữ hoa nào được nhập vào thì heiẻn thị thông báo 'Không có chữ hoa'. Một ví dụ khi thực hiện chương trình:

```
Bạn hãy vào một dòng văn bản:
DONG CHAY THU CHUONG TRINH
Chữ hoa đàu tiên = A. Chữ hoa sau cùng = U
```

- Để giải quyết vấn đề này chúng ta sẽ sử dụg phương pháp thiết kế chưogn trình top_down (từ trên xuống) mà bạn đã có thể gặp trong lập trình ngôn ngữ bậc cao. Trong phương pháp này, vấn đề nguyên thuỷ được chia thành một chuỗi các vấn đề con mà thực hiện mỗi trong chúng đơn giản hơn nheièu sao với vấn đề ban đầu. Mỗi vấn đề con lại có thể được nhỏ hơn nữa... Cứ tiếp tục như thế cho đến khi mỗi vấn đề con có thể được mã hoá trực tiếp. Việc sử dụng các chương trình con có thể phát triển phương pháp này
- Sự phân chia đầu tiên:

	- Hiển thị thông báo ban đầu
	- Đọc và xử lý dòng văn bản
	- Hiển thị kết quả

- **Bước 1: Hiển thị thông báo ban đầu**

	- Bước này có thể mã hoá ngay tức khắc

```
	MOV AH, 9  		;chức năng hiển thị chuỗi
	LEA DX, PROMPT 	;lấy thông báo ban đầu
	INT 21h 		;hiển thị nó
```

- Thông báo có thể chứa trong đoạn dữ liệu như sau :

- `PROMPT DB 'Bạn hãy vào một dòng văn bản',0DH,0AH,'$'`

- Ta đưa vào cả ký tự xuống dòng và về đầu dòng để chuyển con trỏ xuống đầu dòng tiếp theo và như vậy người sử dụng có thể đánh vào toàn bộ một dòng văn bản.

- **Bước 2: Đọc và xử lý dòng văn bản**

	- Bước này thực hiện hầu hết các công việc của chương trình. Nó thực hiện nhập từ bàn phím, trả về các chữ cái thoả mãn (nó cũng đưa ra thông báo nếu không có chữu hoa nào được đọc vào). Sau đây là các bước thực hiện:

```
Đọc một ký tự
WHILE không phải ký tự xuống dòng DO
	IF ký tự là chữ hoa (*)
	THEN
		IF đứng trước chữ hoa đầu
		THEN
			Chữ hoa đầu = ký tự
		End_if
			if đứng sau chữ hoa cuối.
		Then
			chữ hoa cuối = ký tự
		end_if
	end_if
	đọc 1 ký tự
End_while
```

- Dòng (*) thực chất là một điều kiện AND:

```
If ('A' <= ký tự) AND (ký tự <= 'Z')
```

- Bước 2 có thể mã hoá như sau:

```
	MOV AH,1 		;hàm đọc 1 ký tự
	int 21h 		;ký tự trong AL
WHILE_:
;while không phải ký tự xuống dòng do
	cmp al, 0dh 	;cr?
	je end_while 	;đúng thoát ra
;if ký tự là chữ hoa
	cmp al,'A' 		;ký tự >='A' ?
 	JNGE END_IF 	;không phải chữ hoa
	cmp al,'Z' 		;ký tự <= Z ?
	jnle end_if 	;không phải chữ hoa
;then
;if ký tự đứng trước chữ hoa đầu
	cmp al,first 	;ký tự < first?
	jnl check_last 	;không, kiểm tra tiếp
;then chữ hoa đầu = ký tự
	mov first,al 	;first = ký tự
;end_if
CHECK_LAST:
;if ký tự đứng sau chữ hoa cuối
	cmp al,last 	;ký tự > last?
	jng end_if 		;không, cho qua
;then chữ hoa cuối = ký tự
	mov last, al 	;last = ký tự
;end_if
;đọc một ký tự
	int 21h 		;ký tự trong al
	jmp WHILE_ 		;lặp lại
end_while:
```

- Các biến FIRST và LAST phải được khởi tạo trước khi vào vòng lặp WHILE. Chúng có thể được định nghĩa trong đoạn dữ liệu như sau:

```
	FIRST DB '['
	LAST DB '@'
```

- Các giá trị khởi tạo '[' và '@' được chọn bởi vì '[' đúng sau 'Z' và '@' đúng trước 'A'. Theo cách này, chữ hoa đầu tiên được đưa vào sẽ làm thanh đổi giá trị của hai biến.
- Với bước 2 đã được mã hoá. Chúng ta có thể tiếp tục đến bước cuối cùng.

- **Bước 3: Hiển thị kết quả**

```
if không có chữ hoa
then
	hiển thị 'không có chữ hoa ! '
else
	hiển thị chữ hoa đầu và cuối
End_if
```

- Bước này có thể hiển thị một trong hai thông báo NOCAP_MSG nếu không có chữ hoa nào được đánh vào hay CAP_MSG nếu ngược lại. Chúng ta có thể khai báo chúng trong đoạn dữ liệu như sau:

```
NOCAP_MSG	DB 	 	'không có chữ hoa ! $'
CAP_MSG 	DB 		'chữ hoa đầu tiên = '
FIRST 		DB 		'['
			DB 		'chữ hoa sau cùng = '
LAST 		Db 		'@ $'
```

- Khi CAP_MSG được hiển thị, nó sẽ đưa ra thông báo 'Chữ hoa đầu tiên = ', sau đó là giá trị của FIRST rồi đến 'Chữ hoá cuối cùng =' và giá trị của LAST. Chúng ta đã sủ dụng kỹ thuật này trong chương trình ở phần truóc
- Chương trình của chúng ta sẽ kiểm tra biến FIRST biết có chữ hoa nào được đọc voà hay không. Nếu FIRST chưa '[' là giá trị khởi đầu của nó thì có nghĩa là không được vào chữ hoa nào cả.

- Bước ba có thể được mã hoá như sau:

```
	MOV ah,9			;hàm hiẻn thị chuỗi
;if không có chữ hoa
	cmp first,'['		;first ='['?
	jne caps 			;không, hiển thị kết quả
;then
	lea dx,nocap_msg
	jmp display
caps:
	lea dx,cap_msg
display
	int 21h 			;hiển thị thông báo
;end_if
```

- Sau đây la chương trình đầy đủ

```
;chu hoa dau cuoi
.model small
.stack 100h
.data
    prompt      db 'Ban hay vao mot dong van ban',0dh,0ah,'$'
    nocap_msg   db 0dh,0ah,'Khong co chua hoa ! $ '
    cap_msg     db 'Chu hoa dau tien = '
    first       db '['
                db ' Chu hoa sau cung = '
    last        db '@ $ '
.code
main proc
    ;khoi tao ds
        mov ax,@data
        mov ds,ax
     ;hien thi thong bao ban dau
        mov ah,9        ;chuc nang hien thi chuoi
        lea dx,prompt   ;lay thong bao ban dau
        int 21h         ;hien thi no
     ;doc va xu ly mot dong van ban
        mov ah,1        ;ham doc ky tu
        int 21h         ;ky tu trong al
     while_:
     ;while khong phai ky tu xuong dong do
        cmp al,0dh      ;cr?
        je end_while    ;dung, thoat ra
     ;if ky tu la chua hoa
        cmp al,'A'      ;ky tu >= 'A'
        jnge end_if     ;khong phai chu hoa
        cmp al,'Z'      ;ky tu <= 'Z'
        jnle end_if     ;khong phai chu hoa
     ;then
     ;if ky tu dung truoc chu hoa dau
        cmp al,first    ;ky tu < first
        jnl check_last  ;khong, kiem tra tiep
     ;then chu hoa dau = ky tu
        mov first, al   ;first = ky tu
     ;end_if
     Check_last:
     ;if ky tu dung sau chua hoa cuoi
        cmp al,last     ;ky tu > last?
        jng end_if      ;khong, cho qua
     ;then chu hoa cuoi ky tu
        mov last,al     ;last = ky tu
     ;end_if
     End_if:
     ;doc mot ky tu
        int 21h         ;ky tu trong al
        jmp while_      ;lap lai
     end_while:
     ;hien thi ket qua
        mov ah,9        ;ham hien thi chuoi
     ;if khong co chu hoa
        cmp first,'['   ;first = '['?
        jne caps        ;khong, hien thi ket qua
     ;then
        lea dx,nocap_msg
        jmp display
     caps:
        lea dx,cap_msg
     display:
        int 21h         ;hien thi thong bao
     ;end_if
     ;tro ve dos
        mov ah,4ch
        int 21h
main endp
end main
```
