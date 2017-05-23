### BreakPoint trong OllyDBG
> Tài liệu tham khảo: [Tut 10 + 11 +12](https://kienmanowar.wordpress.com/)
> 
> Người thực hiện: Phạm Phú Quí
> 
> Cập nhật lần cuối: 22/05/2017
> 
> -------------------------------------
> 
> ### Mục lục
- [1. Breakpoint trong lập trình và dịch ngược là gì](#1)
- [2. Các loại Breakpoint](#2)
    - [2.1 Comon Breakpoint](#2.1)
    - [2.2 Breakpoint on Memory](#2.2)
    - [2.3 Hardware Breakpoint](#2.3)
    - [2.4 Conditional Breakpoint](#2.4)
    - [2.5 Conditional Log Breakpoint](#2.5)
    - [2.6 Message Breakpoint](#2.6)

-----------------------------------------------------------------------------------

<a name="1"></a>
### 1. Breakpoint trong lập trình và dịch ngược:

- Trong việc phát triển phần mềm, Breakpoint (BP) là ép buộc chương trình ngừng hoạt động hoặc tạm ngưng tại một vị trí nào đó trong chương tình, đặt BP cho mục đích debug chưong trình. Và nó thường được sử dụng để tạm ngưng chưong trình.
- Thường thì BP có nghĩa là sẽ lấy mọi thông tin của chương trình trong suốt quá trình thực thi chương trình. Trong quá trình gián đoạn, function sẽ không được gọi đến. Trong quá trình thực thi chương tình, một BP có thể chứa một hoặc nhiều điều kiện làm gián đoạn chương trình.
- [Nguồn Wikipedia về BP](https://en.wikipedia.org/wiki/Breakpoint)

<a name="2"></a>
### 2. Một số loại breakpoint trong OllyDBG:

<a name="2.1"></a>
#### 2.1 Common Breakpoint:

- Đây là một phưong pháp đặt BP phổ biến nhất mà ta thưòng hay sử dụng nhất. Thông thường, đối với một câu lệnh nào đó mà chúng ta muốn đặt BPX lên nó thì đơn giản là chọn dòng lệnh mà ta muốn và nhấn F2 ( Nhấn F2 một lần nữa để Remove BPX ) hoặc thông qua Command Bar: BP hoặc BPX tên hàm cần đặt BP
- Ví dụ mình họa: Load CrackMe vào OllyDBG
- Trích dẫn [Tut 10 - ollydbg](https://kienmanowar.wordpress.com/)

<img src="http://i.imgur.com/sUis6PZ.png">

- Các bạn có thể thấy trên hình minh họa, tại địa chỉ 00401018 khi tôi bấm F2 thì ngay lập tức địa chỉ này được tô sáng lên bằng màu vàng (của các bạn có thể là màu đỏ hay bất kì màu nào do bạn cấu hình Olly), điều này có nghĩa là tôi đã đặt BP tại 00401018 |. 0BC0   or  eax,  eax .
Ngay lúc này, bạn chuyển qua cửa sổ quản lý các Breakpoints bằng cách nhấn chữ B (hoặc vào Menu: Windows -> BreakPoints) :

<img src="http://i.imgur.com/9mtBmbK.png">

- Các bạn sẽ thấy BP mà chúng ta vừa đặt đã được liệt kê tại cửa sổ này, ta tìm hiểu qua về cửa sổ quản lý BreakPoints này một chút :

<img src="http://i.imgur.com/H55S7dH.png"> 

- Chúng ta quan sát thấy tại cột Active thì trạng thái của BP ta đặt luôn là Always điều này có nghĩa là BP này sẽ luôn được thực thi hay nói cách khác là nó sẽ được kích hoạt khi ta thực thi chương trình. Khi ta chọn và nhấn chuột phải lên dòng lệnh ta sẽ nhận được một menu  ngữ cảnh như sau :

<img src="http://i.imgur.com/z1wTj0H.png">

- **Remove**: loại bỏ breakpoint ra khỏi danh sách các điểm đặt BP mà cửa sổ này quản lý.
- **Disable :** tạm thời disable bp của chúng ta mà không loại nó khỏi danh sách, khi cần ta lại active nó lên.
- **Edit Condition :** khi chọn chức năng này là ta đang muốn ch*uyển đổi bp của chúng ta sang một dạng khác là conditional bp, kiểu đặt bp này sẽ được bàn tới ở dưới.
- **Follow in Disassembler :** Với một danh sách dài các bp thì chúng ta khó có thể nhớ được nó liên quan tới đoạn code nào, tính năng này cho phép chúng ta tìm tới điểm mà chúng ta đặt bp tại cửa sổ code.
- **Disable all :** tương tự như tính năng Disable tuy nhiên có khác là nó sẽ disable hết toàn bộ các bp có trong cửa sổ Breakpoints.
Copy to clipboard : sao chép thông tin về bp vào clipboard. Khi chọn tính năng này sẽ xuất hiện thêm một số chức năng con đi kèm.

<img src="http://i.imgur.com/gZ9cX6D.png">

- Ta thử chọn chức năng Copy to Clipboard -> Whole line, tính năng này sẽ copy nguyên dòng mà chúng ta chỉ định. Còn Whole table sẽ copy toàn bộ tất cả những danh sách bp hiện có trong cửa sổ Breakpoints. Đây là kết quả khi ta chọn Whole line :

```C
Br3akp0ints, item 0 
Address=00401018 
Module=CRACKME 
Active=Always
Disassembly=or  eax,  eax
```
- OK, như trên chúng ta đã đặt một bp tại 0x00401018, bây giờ chúng ta cần kiểm tra xem bp mà chúng ta đặt có hoạt động đúng như chúng ta mong muốn hay không? Nhấn F9 để thực thi chương trình, ngay lập tức các bạn sẽ thấy ta đã dừng lại tại nơi mà ta đặt bp :

<img src="http://i.imgur.com/VPQk4Dt.png">

- Dòm qua thanh status ta thấy như sau :

<img src="http://i.imgur.com/0ZzcEAP.png">

- Bây giờ chúng ta sẽ tìm hiểu xem điều gì đã thực sự xảy ra? Có sự thay đổi nào không khi ta thiết lập BP tại lệnh mà chúng ta muốn.Ok, chuột phải tại 0x00401018 và chọn :

<img src="http://i.imgur.com/TEaShIK.png">

- Quan sát nội dung tại cửa sổ Dump ta có như sau :

<img src="http://i.imgur.com/2kXfKPV.png">

- So sánh thông tin ở cửa sổ Dump với thông tin ở cửa sổ CPU ta thấy không có gì thay đổi cả, ở  cửa sổ Dump các bạn thấy các bytes 0B  C0  tương đương với câu lệnh or  eax,  eax tại cửa sổ   CPU. Điều này khiến chúng ta không khỏi thắc mắc, nếu như không có sự thay đổi gì thì tại sao  khi tôi run chương trình thì nó lại dừng lại tại điểm mà tôi đặt BP? Để kiểm chứng xem có sự thay đổi hay không, các bạn hãy restart lại Olly (Ctrl+F2) và chắc chắn rằng chúng ta vẫn đang đặt BP tại địa chỉ 0x00401018 . Sau khi Restart lại Olly, ta sẽ dừng lại tại EP của chương trình, tiến hành edit một đoạn code như sau tại EP :

<img src="http://i.imgur.com/DAtiVUc.png">

- Mục đích của đoạn code này chỉ đơn giản là đọc ra nội dung tại địa chỉ 0x401018 và lưu vào thanh ghi eax. Để dễ hiểu hơn bạn nhìn vào cửa sổ Tip :

<img src="http://i.imgur.com/PNcF1P0.png">

- Nhìn vào cửa sổ Dump ta sẽ biết được đây là những bytes gốc ban đầu, chưa bị thay đổi gì.Nhưng tôi lấy làm ngờ vực, tôi thử nhấn F7 để trace và kết quả là thanh ghi EAX đã có sự thay đổi rất thú vị :

<img src="http://i.imgur.com/6MTVqho.png">

- Để ý cửa sổ Dump bạn thấy các bytes vẫn được giữ nguyên như ban đầu, nhưng ở thanh ghi EAX thì ta lại thấy giá trị đã khác là : 0x0174C0CC. Điều này được giải thích sơ bộ như sau: khi tôi đặt một BP tại địa chỉ 0x401018 thì Olly sẽ tiến hành thay thế byte đầu tiên mà ở đây là giá trị 0B bằng một giá trị khác là 0xCC. Nếu như bạn quy đổi byte CC này sang lệnh asm thì nó là int3, đây là một câu lệnh đặc biệt (nó còn được gọi là Trap to Debugger) nó sẽ gây ra một exception khi chúng ta cố gắng thực thi chương trình. Các bạn đọc thêm thông tin sau :

```C
“So generally it is complex to set a breakpoint in an arbitrary place of the program. 
The debugger should save the current value of the memory location at the specified address, then write the code 0xCC there. 
Before exiting the debug interrupt, the debugger should return everything to its  former place, and should modify IP saved in the stack so that it points to the beginning of the restored instruction. (Otherwise, it points to its middle.)”
```

Hơi lằng nhắng một chút nhưng hi vọng các bạn cũng thấm vào đầu được ít nhiều , ngoài việc đặt BP thông qua việc chọn câu lệnh và nhấn F2 thì ta còn một cách đặt BP khác nữa như sau, tìm địa chỉ cần đặt BP và gõ lệnh tại Command Bar plugin :

<img src="http://i.imgur.com/bTEQuwT.png">

Giờ ta tìm hiểu một chút về cách đặt BP cho hàm API. Như ở trên tôi đã nói lệnh BPX thường được sử dụng cho việc đặt BP tại các hàm API của chương trình, thêm nữa nó lại phụ thuộc vào phiên bản Windows mà bạn đang sử dụng. Đối với những ai sử dụng Windows NT/2000/XP/2003 thì việc đặt BP tại một API function cụ thể rất đơn giản, chỉ việc gõ BP [tên của hàm] trong Command Bar như sau :

<img src="http://i.imgur.com/ACAxABV.png">

Bạn nhớ gõ đúng chữ hoa chữ thường trong tên hàm nhé!! Trên Windows 98 thì ngược lại, việc  đặt BP tại 1 hàm API cụ thể không được hỗ trợ mà thay vào đó là việc đặt BP tới những nơi có lời gọi tới hàm API mà chúng ta cần. Ví dụ :

<img src="http://i.imgur.com/AftbE6H.png">

Kết quả ta có được như sau :

<img src="http://i.imgur.com/Jb4Tcg2.png">

Vậy là ta đã thấy được sự khác biệt giữa BPX và BP, BPX không thiết lập một breakpoint tại một địa chỉ cụ thể đã được chỉ định như BP đã làm mà nó chỉ đặt BP tại những câu lệnh tham chiếu tới địa chỉ đó mà thôi. Lý thuyết phải đi kèm thực tế, các bạn đặt liền một lúc cả BP và BPX tại API MessageBoxA và quan sát cửa sổ Breakpoints :

<img src="http://i.imgur.com/5bmBWs5.png">

Ngoài việc hỗ trợ đặt BP thông qua phím F2 và thông qua command line, Olly còn hỗ trợ cho chúng ta việc đặt bp thông qua việc nhấn đúp chuột. Để thực hiện việc đặt bp tại một địa chỉ, bạn chỉ việc chọn cột Hex Dump tại cửa sổ CPU và nhấp đúp chuột lên đó.Nếu nhấp đúp chuột một lần nữa thì sẽ loại bỏ BP :

<img src="http://i.imgur.com/5bmBWs5.png">

- **Tóm tắt**: Common Breakpoint: Set BP: F2 (Command Bar). Thường được đặt tại các API của chương trình

<a name="2.2"></a>
#### 2.2 Breakpoint on Memory:

- Đặc điểm:  Chỉ có một Memory Breakpoint trong chương trình
- Có hai loại BP Memory:
    + Breakpoint Memory on access: Đặt Bp này lên một vùng nhớ sẽ cho phép dừng thực thi chương trình khi có bất kỳ một sự thực thi chương trình khi có bất kỳ một sự thực thi, đọc hay ghi lên vùng nhớ mà ta đặt Bp.
    + Breakpoint Memory on write: Dừng thực thi chương trình khi có bất kỳ dữ liệu nào đưọc ghi lên vùng nhớ mà ta đặt Bp.
=> Khắc phục cơ chế anti-bp tại các hàm APIs

- Ví dụ từng loại Breakpoint Memory: [Tut 10](https://kienmanowar.wordpress.com/)

- Chúng ta đã load crackme vào Olly và đang dừng lại tại EP của crackme.

<img src="http://i.imgur.com/2T0zqjv.png">

- Chuyển xuống cửa sổ Dump và nhấn chuột phải chọn Goto > Expression hay nhấn phím tắt là
Ctrl+G và gõ vào địa chỉ như sau :

<img src="http://i.imgur.com/7KcGrQV.png">

- Olly sẽ đưa ta tới đây :

<img src="http://i.imgur.com/ebvLyji.png">

- Ok chúng ta đã tới vùng nhớ để thực hành đặt bp, tôi sẽ tiến hành đặt một bp là Memory on access lên 4 bytes tại 4020CA, sau đó tiến hành thực thi chương trình và hi vọng rằng chương trình sẽ   dừng quá trình thực thi lại nếu như có một đoạn code nào đó đọc 4 bytes tại 4020CA, hoặc ghi vào   4 bytes tại 4020CA hay thực thi lệnh tại 4020CA. Để đặt bp tại 4 bytes tôi làm như sau, dùng chuột  bôi đen 4 bytes :

<img src="http://i.imgur.com/kEQ0ZCY.png">

- Tiếp theo nhấn chuột phải và chọn như hình :

<img src="http://i.imgur.com/MiIQpGn.png">

- Một điểm đáng lưu ý là không giống như việc đặt với lệnh BP hay BPX , việc đặt bp tại memory  sẽ không được lưu giữ thông tin tại cửa sổ Breakpoint vì vậy ta phải tự ghi nhớ xem mình đã đặt ở đâu, nếu chúng ta muốn remove breakpoint đã đặt thì nhấn chuột phải và chọn :

<img src="http://i.imgur.com/7QXMmAZ.png">

- Như đã nói ở trên, Olly chỉ cho phép tại một thời điểm có một memory bp duy nhất, nếu bạn đặt một bp khác thì bp đã đặt trước đó sẽ tự động bị loại bỏ. Ok, sau khi đã đặt bp theo hướng dẫn như trên, các bạn cho thực thi chương trình bằng cách nhấn F9,chương trình ngay sau đó sẽ dừng lại tại đoạn code bên dưới EP chút xíu :

<img src="http://i.imgur.com/1qTkLTH.png">

<img src="http://i.imgur.com/huvJgj5.png">

- Thông tin ở Status Bar đã cho chúng ta biết được tại sao Olly lại break, đó là bởi vì câu lệnh tại địa chỉ 0x00401007 chuẩn bị ghi giá trị của thanh ghi eax vào nội dung của địa chỉ 4020CA, việc này sẽ gây ra một exceptions khiến cho dừng sự thực thi của chương trình.Giờ ta nhìn qua cửa sổ Register để xem giá trị của eax là gì :

<img src="http://i.imgur.com/Adk8uPs.png">

- Ta nhấn F7 để trace qua đoạn code mov   dword   ptr   [4020CA],   eax   và quan sát giá trị tại của sổ dump :

<img src="http://i.imgur.com/orhN2MD.png">

- Như vậy là giá trị 0x00400000 được lưu giữ tại [4020CA], tiếp tục một lần nữa ta nhấn F9 để thực thi chương trình để xem chuyện gì sẽ xảy ra :

<img src="http://i.imgur.com/vlj72xB.png">

<img src="http://i.imgur.com/vlj72xB.png">

- Chà, một lần nữa Olly lại break và lần này là tại 0x401045, nhìn xuống thanh Status Bar ta thấy được lý do tại sao lại dừng sự thực thi của chương trình. Đó chính là do đoạn code tại 0x401045 đang cố gắng đọc nội dung tại 4020CA và lưu vào thanh ghi eax. Nội dung tại 4020CA là gì thì ta đã biết ở trên, giờ ta nhấn F7 để trace và quan sát thanh ghi eax :

<img src="http://i.imgur.com/V7ItadY.png">

<img src="http://i.imgur.com/2mQ8KZT.png">

- Giá trị 0x400000 lại được đưa trả về cho thanh ghi eax. Lại tiếp tục nhấn F9 thêm lần nữa :

<img src="http://i.imgur.com/R41g4Rv.png">

<img src="http://i.imgur.com/6MMsHVV.png">

- Như vậy là các bạn đã hiểu về Memory on Access và cách thức để có thể đặt một bp Memory on access rồi nhé. Việc đặt bp Memory on Write cũng tương tự như những gì tôi đã làm ở trên, các bạn tự thực hành để rút ra kết luận nhé.
- Ngoài việc đặt bp như trên, Olly còn cho phép chúng ta đặt Memory bp lên các section của file. Để thực hiện được điều này các bạn mở cửa sổ Window -> Memory map hoặc nhấn phím tắt là Alt + M :

<img src="http://i.imgur.com/90p4ioC.png">

<img src="http://i.imgur.com/c4e4nQC.png">

- Ta chọn đại lấy một section để làm ví dụ, ở đây để đơn giản tôi chọn section CODE và đặt một Memory bp lên nó. Chỉ việc chọn section, nhấn chuột phải và chọn như hình dưới đây để thiết lập một bp :

<img src="http://i.imgur.com/c4e4nQC.png">

- Sau khi đặt xong bp, nhấn F9 để thực thi chương trình :

<img src="http://i.imgur.com/Yk9jUlD.png">

<img src="http://i.imgur.com/uziZYwR.png">

- Việc quá trình thực thi bị dừng lại là hoàn toàn chính xác, đó là vì ta đang thực thi lệnh tại [401002]. Giờ ta thử đặt BP lên section của một module khác mà không phải là section của file exe mà ta đang làm việc, ở đây tôi chọn là kernel32 :

<img src="http://i.imgur.com/uziZYwR.png">

<img src="http://i.imgur.com/hSSbIli.png">

- Nhấn F9 để thực thi chương trình, ta không cần remove memory bp đã đặt ở trước đơn giản là vì khi ta đặt một memory bp khác thì bp trước sẽ bị remove luôn :

<img src="http://i.imgur.com/6FFGB3H.png">

<img src="http://i.imgur.com/0AullXE.png">

- Nhìn sang cửa sổ Stack ta sẽ biết là ta đang dừng tại hàm API nào :

<img src="http://i.imgur.com/s2icTCb.png">

- Như vậy là chương trình đã dừng lại khi thực thi lệnh của kernel32.dll, nhìn ở cửa sổ Stack ở hình trên và kết hợp với lý thuyết về Stack mà tôi đã giới thiệu qua ở phần trước thì có thể nhận thấy rằng địa chỉ 0x401007 là địa chỉ trở về của lệnh bên dưới lời gọi hàm Call GetModuleHandleA tại địa chỉ 0x401002. Thử nhấn chuột phải và chọn Follow in Disassembler để kiểm chứng lại :

<img src="http://i.imgur.com/wdn2YGp.png">

<img src="http://i.imgur.com/f2caZgQ.png">

- Đây là cách nhanh nhất để quay về địa chỉ của lệnh bên dưới, còn một cách khác cũng hay được áp dụng nữa là khi ta đang dừng tại hàm API như hình mình họa ở trên, ta nhấn chọn Menu Debug  > Execute till User code hoặc nhấn phím tắt là Alt+F9. Olly sẽ đưa chúng ta về đúng nơi  như những gì ta vừa mới thực hiện ở trên (tuy nhiên chú ý là phải bỏ Bp trên memory trước rồi mới thực hiện nhấn Alt+F9) :

<img src="http://i.imgur.com/WbUpZ9e.png">

<img src="http://i.imgur.com/rRApZuo.png">

- Mở rộng vấn để ra một chút, ở phần trước tôi đã thực hiện việc phân tích sơ bộ chương trình và  các bạn cũng đã biết rằng khi chúng ta nhập sai thông tin về UserName và Serial thì ta sẽ nhận được một thông báo lỗi. Bây giờ tôi muốn đặt BP tại hàm MessageBoxA (vd: Bp MessageBoxA), nhưng vì một lý do nào đó chương trình sử dụng cơ chế anti-bp và phát hiện ra rằng có CC (tức int3) được sử dụng ngay lập tức nó sẽ terminate Olly của ta. Vậy không lẽ ta phải chịu vậy sao và không thể đặt bp tại API MessageBoxA. Xin thưa với các bạn, đến lúc này việc đặt Memory Bp mới có tác dụng và hiệu quả. Để tìm địa chỉ của hàm MessageBoxA tôi làm như sau trong Olly :

<img src="http://i.imgur.com/VJ4Ycux.png">

- Vậy là địa chỉ hàm MessageBoxA của tôi là ở 0x7E45058A (trên máy các bạn có thể khác), lúc này tôi chỉ việc qua cửa sổ CPU và nhấn Ctrl+G, gõ địa chỉ này vào hoặc thay vào đó tôi gõ trực tiếp tên hàm vào và nhấn Ok, Olly sẽ đưa tôi đến đúng nơi cần tìm :

<img src="http://i.imgur.com/9JUkcby.png">

<img src="http://i.imgur.com/VQcaolj.png">

- Bây giờ việc đặt bp hết sức đơn giản, thực hiện như hình minh họa dưới đây :

<img src="http://i.imgur.com/VQcaolj.png">

- Giờ ta test thử xem việc đặt bp có hoạt động đúng như ta mong đợi không nhé. Nhấn F9 để run chương trình, sau đó nhập fake info gì là tùy bạn :

<img src="http://i.imgur.com/Fzn8y0H.png">

- Nhẹ nhàng bấm OK xem thế nào :

<img src="http://i.imgur.com/QxVX1z1.png">

- Khà khà Olly đã break đúng chỗ rồi, quan sát cửa sổ Stack :

<img src="http://i.imgur.com/QxVX1z1.png">

- Giờ tôi muốn quay trở về code chính của chương trình thì thế nào nhỉ? Quá đơn giản, bạn remove memory bp đi và nhấn Alt+F9, chương trình sẽ thực thi và show nag. Ta nhấn Ok để chấp nhận, sau đó Olly sẽ đưa chúng ta tới đây :

<img src="http://i.imgur.com/QxVX1z1.png">

<a name="2.3"></a>
#### 2.3 Hardware Breakpoint:

- Đặc điểm: Được phép đặt 4 harware bp trong chương trình
- Harware Breakpoint không sử dụng INT3 để dừng thực thi chương trình, nó được hỗ trợ trực tiếp từ CPU, sử dụng một số thanh ghi đặc biệt (debug register) DR0. DR1, DR2, DR37 
- Dừng thực thi chương trình ở DR7 (Sử dụng INT1)
- 4 khả năng dừng thực thi chương trình:
    + Khi 1 câu lệnh được thực thi
    + Khi nội dung của memory có thay đổi
    + Khi 1 vị trí của memory được đọc ra hoặc update
    + Khi 1 vị trí input - output port được tham chiếu tới
- Có 3 kiểu Hardware Breakpoint:
    + HWBP on Excution
    + HWBP on Write
    + HWBP on Access
- **Thực hành lần lưọt với các kiểu Hardware Breakpoint:** (Tut  11)
- Bây giờ là phần thực hành, mở Olly lên và load crackme vào nào :

<img src="http://i.imgur.com/HVm5gvC.png">

- Ta sẽ thực hành lần lượt với các kiểu HWBP là : HardWare Breakpoint on Execution, HWBP on Write và HWBP on Access.

- Việc đặt HWBP on Execution cũng gần tương tự như cách ta đặt BP thông thường tại một câu lệnh, chỉ có một điều hơi khác là HWBP không có thay đổi code do đó khiến cho việc phát hiện HWBP trở nên khó khăn hơn. Mặc dù vậy vẫn có những chương trình có khả năng sử dụng một số tricks để xóa HWBP, những kĩ thuật như vậy và cách thức chống lại nó chúng ta sẽ tìm hiểu trong các phần tiếp theo. Bây giờ quay trở lại vấn đề, ta muốn đặt một HWBP tại địa chỉ 0x00401013 thì làm như thế nào? Câu trả lời cực kì đơn giản, ta chọn địa chỉ đó nhấn chuột phải và chọn như sau :

<img src="http://i.imgur.com/HVm5gvC.png">

- Hoặc một cách khác là thực hiện thông qua command line:

<img src="http://i.imgur.com/fwDF1OB.png">

- Chà ta đặt HWBP rồi mà chẳng thấy có dấu hiệu gì chứng tỏ là ta đã đặt cả. Có cách gì kiểm chứng không nhỉ? Xin thưa là có, Olly hỗ trợ cho chúng ta một cửa sổ đặc biệt dùng để quản lý các HWBP, để mở cửa sổ này bạn làm như sau :

<img src="http://i.imgur.com/e6T5YHt.png">

- Ta sẽ nhận được một cửa sổ như sau :

<img src="http://i.imgur.com/jQkawnw.png">

- Không cần giải thích nhiều chắc các bạn cũng hiểu được ý nghĩa từng thành phần của cửa sổ HWBP. Giờ để tìm tới chỗ ta vừa đặt HWBP ta chỉ việc nhấn vào nút Follow là Olly sẽ di chuyển vệt sáng tới chỗ ta đặt BP. Bây giờ ta nhấn F9 để thực thi chương trình :

<img src="http://i.imgur.com/LJuDTpE.png">

- Bùm…Olly đã stop tại chỗ mà ta đặt BP. Ta thấy nó chẳng khác gì với việc ta đặt BP như ở phần 10, giờ ta kiểm chứng xem nó có thay đổi code gì không nhé. Để kiểm chứng ta làm hệt như những gì tôi đã hướng dẫn các bạn ở phần trước :

<img src="http://i.imgur.com/ckxd8sh.png">

- Chúng ta edit lại đoạn code như trên, dòm xuống cửa sổ Tip và cửa sổ Dump ta có được thông tin như sau :

<img src="http://i.imgur.com/KNVwe78.png">

<img src="http://i.imgur.com/dfuunN9.png">

- Giờ ta nhấn F7 để trace và quan sát thanh ghi EAX :

<img src="http://i.imgur.com/kqgyHKk.png">

- Ta thấy được gì nào, thanh ghi eax vẫn giữ nguyên giá trị được mov vào mà không thấy có thay đổi , vậy chứng tỏ một điều HWBP không có change code. Giờ ta kiểm chứng một điều khác nữa, ở phần trước khi ta restart chương trình thì memory bp cũng theo đó mà mất luôn , vậy HWBP có như thế không? Thử cái biết liền, ta nhấn Ctrl+F2 để restart chương trình sau đó vào cửa sổ HWBP để kiểm tra xem còn lưu lại BP không :

<img src="http://i.imgur.com/vIzX9mG.png">

- Oh vẫn y nguyên nhé!! Giờ ta xóa HWBP này đi, sau đó đặt một HWBP tại MessageBoxA như ta thực hiện bằng lệnh BPX.

<img src="http://i.imgur.com/AkTtwVo.png">

<img src="http://i.imgur.com/AkTtwVo.png">

- Kiểm tra chắc chắn xem bp đã đặt được chưa :

<img src="http://i.imgur.com/04jmF1f.png">

- Chắc các bạn cũng đoán ra được ý đồ vì sao tôi lại đặt HWBP tại MessageBoxA rồi chứ. Đơn giản, tôi muốn các bạn tự kiểm chứng xem khi ta cho thực thi chương trình, sau đó nhập UserName và Serial vào và nhấn OK thì Olly sẽ dừng lại tại MessageBoxA, tương tự như những gì ta đã thực hiện ở các phần trước. Các bạn tự thực hành nhé .

- Tiếp theo ta tìm hiểu tiếp về HWBP on Write và HWBP on Access. Hai kiểu HWBP này cho phép thiết lập với Byte, Word, Dword (tương ứng 1, 2 hoặc 4 bytes). Không khó để thực hiện hai kiểu hwbp này, đơn giản bạn chỉ việc qua cửa sổ Dump, sau đó đánh dấu vùng bytes tương ứng và đặt BP. Ta thực hành luôn nhé, giờ bạn xóa hết các HWBP đã đặt đi, sau đó chúng ta sẽ thử đặt HWBP on Access tại địa chỉ 4020CA tại cửa sổ Dump. Ta chuyển qua cửa sổ Dump, nhấn Ctrl+G và nhập vào :

<img src="http://i.imgur.com/ZAc5PbC.png">

- Ta tới đây :

<img src="http://i.imgur.com/ZAc5PbC.png">

- Giờ ta đánh dấu 4 bytes như hình dưới đây :

<img src="http://i.imgur.com/ogCgg2N.png">

- Nhấn chuột phải và chọn như sau :

<img src="http://i.imgur.com/8Rrb3vx.png">

- Như các bạn nhìn thấy trên hình, vùng mà chúng ta đánh dấu cho phép chúng ta thiết lập HWBP tại 1 byte hoặc 2 bytes (word). Mặc dù chúng ta đánh dấu chọn 4 bytes nhưng ở đây tùy chọn Dword không xuất hiện trong danh sách của HWBP on Access. Thực hiện tương tự với byte tiếp theo và lần này ta chỉ thấy có tùy chọn Byte xuất hiện :

<img src="http://i.imgur.com/TJpVfDR.png">

- Thử tiếp tục với byte kế tiếp, lần này ta thấy tùy chọn Dword đã xuất hiện :

<img src="http://i.imgur.com/wArdNoH.png">

- Quay trở lại vấn đề chính, chúng ta đang muốn giám sát vùng nhớ tại 4020CA khi có bất kì một sự thực thi, đọc hay ghi lên vùng nhớ mà ta đã đặt bp. Để làm điều này ta đặt HWBP như sau :

<img src="http://i.imgur.com/BmUfWMI.png">

- Trong cửa sổ quản lý HWBP ta thấy xuất hiện như sau (size bằng 1 tương ứng với 1 byte) :

<img src="http://i.imgur.com/8CfDqKt.png">

- Ok, đặt xong hwbp rồi giờ ta run thử chương trình xem thế nào :

<img src="http://i.imgur.com/6yk0ehR.png">

- Oh, chúng ta đã dừng lại khi có sự tác động vào vùng nhớ 4020CA. Quan sát Olly các bạn thấy dòng Hardware breakpoint 1 at…, số “1” ở đây tương ứng với số thứ tự của Hwbp được liệt kê trong cửa sổ quản lý Hwbp như các bạn thấy ở hình trên. Ngoài ra các bạn để ý là vệt sáng đang dừng lại tại 0040100C |. 6A 00 push 0 ; /Title = NULL,chứ không dừng lại tại lệnh tác động vào vùng nhớ [4020CA]: 00401007 |.A3 CA204000 mov dword ptr [4020CA], eax.

- Đây là điểm khác biệt giữa Hwbp và Memory Bp, giờ ta quan sát xem nội dung của 4020CA đã thay đổi như thế nào :

<img src="http://i.imgur.com/ubHxuPF.png">

<a name="2.4"></a>
#### 2.4 Conditional Breakpoint

- Conditional Breakpoint như là một breakpoint thông thường dùng INT3 để dừng sự thực thi chương trình
- Conditional Breakpoint được quản lý thông qua cửa sổ Breakpoint (B)
- Điều kiện dừng phải thõa điều kiện mà ta thiết lập từ trước
- Điểm quan trọng: Sử dụng để "tóm" các Window Message (Vd: WM_Close, WM_Paint, v.v...)
- Ví dụ cụ thể về Conditional Breakpoint: (Tut 11)
- Bây giờ chúng ta xem xét một ví dụ nhỏ để dễ hiểu và dễ hình dung hơn, chúng ta đang ở tại Entry point của Crackme :

<img src="http://i.imgur.com/ngKEEXd.png">

- Xóa hết các Hwbp đã đặt trước đó đi. Tiếp theo ta sẽ đặt một Conditional BP tại 0x0040100E, ta làm như sau :

<img src="http://i.imgur.com/qumZdrP.png">

- Hoặc đơn giản hơn ta chọn dòng cần đặt Conditional bp và nhấn phím tắt Shift+F2, một cửa sổ xuất hiện cho phép ta đặt điều kiện :

<img src="http://i.imgur.com/P0Kz3rT.png">

- Gỉa sử, tôi muốn dừng sự thực thi của chương trình khi giá trị của thanh ghi eax=0x400000. Tôi nhập điều kiện như sau :

<img src="http://i.imgur.com/zpDaR1N.png">

- Sau khi nhập điều kiện xong, ngay lập tức ta thấy địa chỉ 0x0040100E được tô sáng thành màu hồng :

<img src="http://i.imgur.com/eNbBx3D.png">

- Sau khi đặt xong bp, nhấn F9 để thực thi chương trình và quan sát :

<img src="http://i.imgur.com/eNbBx3D.png">

- Nhìn sang cửa sổ Registers, ta xem giá trị của EAX lúc này đang là bao nhiêu :

<img src="http://i.imgur.com/r4z5zXI.png">

- Vậy là ta thấy giá trị của EAX đang là 0x400000, giá trị này thỏa với điều kiện mà ta đã thiết lập để đặt BP, do đó chương trình dừng lại và quyền điều khiển được trả về cho trình debug. Ta thử đặt lại Conditional bp nhưng với điều kiện Eax==0x500000 xem thế nào :

<img src="http://i.imgur.com/r1B3KaW.png">

- Nhấn F9 để run chương trình và quan sát, khà khà lần này chẳng thấy nó Olly break gì cả mà lại thấy chương trình chạy vù vù. Điều này chứng tỏ điều kiện ta đặt ra không thỏa

<img src="http://i.imgur.com/Bvey6kV.png">

<a name="2.5"></a>

#### 2.5 Conditional Log Breakpoint

- Tương tự như Conditional Breakpoint tuy nhiên nó có thêm nhiều tùy chọn cho phép ta lưu vết gía trị của biểu thức hoặc các tham số của function mỗi khi xảy ra bp hoặc khi thỏa mãn điều kiện mà ta đặt ra.
- Thông tin sẽ lưu ở của sổ Log
- Thực hiện một ví dụ để minh họa, trước tiên chúng ta restart lại Olly cái đã. Sau đó nhấn Ctrl+G và tìm tới hàm MessageBoxA :

<img src="http://i.imgur.com/hL9Evbu.png">

<img src="http://i.imgur.com/hL9Evbu.png">

- Sau khi tới vị trí tương tự như hình trên, ta tiến hành đặt một Conditional Log BP như sau :

<img src="http://i.imgur.com/M3u0VWA.png">

- Hoặc đơn giản chỉ việc nhấn phím tắt Shift+F4, cửa sổ Conditional Log BP xuất hiện với rất nhiều tùy chọn :

<img src="http://i.imgur.com/wbbu0W4.png">

- Trong trường hợp này của tôi, tôi không muốn dừng sự thực thi tại hàm MessageBoxA mà đơn giản tôi chỉ muốn ghi lại các giá trị mà tôi cần quan tâm, tôi đặt diều kiện như sau :

<img src="http://i.imgur.com/RZBkWuW.png">

- Những gì tôi giải thích trên hình minh họa chắc các bạn cũng hiểu phần nào mục đích của việc đặt BP. Tôi xin nói chi tiết lại như sau, trong phần Expresstion tôi nhập vào là [esp] có nghĩa là tôi muốn đọc ra nội dung của thanh ghi Esp. Phần Pause program tôi chọn là Nerver, có nghĩa là tôi không muốn dừng sự thực thi của chương trình lại. Hai thành phần tiếp theo là Log value of expression và Log function arguments tôi chọn là Always, có nghĩa là tôi muốn ghi lại nội dung của biểu thức mà cụ thể ở đây là giá trị của thanh ghi esp, đồng thời tôi cũng muốn ghi lạ các tham số truyền vào cho function mà cụ thể ở đây là hàm MessageBoxA. Giải thích vậy các bạn đã hiểu chưa. Sau khi thiết lập như trên xong, nhấn Ok ta có được như sau :

<img src="http://i.imgur.com/n6nqIG7.png">

- Tiếp theo ta chuyển qua cửa sổ Log :

<img src="http://i.imgur.com/AvPe0h5.png">

- Tại cửa sổ Log ta clear hết các thông tin đi để tiện theo dõi :

<img src="http://i.imgur.com/oBhquKK.png">

- Clear xong ta nhấn F9 để run chương trình, tiến hành nhập các thông tin mà chương trình yêu cầu :

<img src="http://i.imgur.com/EmNVPQA.png">

- Sau đó nhấn OK, ta sẽ nhận được Nag thông báo. Lúc này để ý cửa sổ Log ta thấy như sau :

<img src="http://i.imgur.com/bA1GyDJ.png">

- Nhìn vào thông tin trên các bạn thấy dòng màu đỏ đầu tiên COND: 0040137D chắc cũng đoán được đây là giá trị của thanh ghi ESP. Còn các dòng tiếp theo chắc tôi không cần giải thích chắc các bạn cũng đoán ra đó chính là các tham số truyền vào cho hàm MessageBoxA. Để kiếm chứng giá trị của thanh ghi ESP bạn có thế nhìn vào cửa sổ Stack :

<img src="http://i.imgur.com/3LRrzKH.png">

- Gía trị 0x0040137D chính là địa chỉ trở về sau khi thực hiện xong hàm MessageBoxA :

<img src="http://i.imgur.com/elSkp7y.png">

- Khà khà mọi thứ đều rõ ràng quá . Tiếp theo chúng ta thử đặt một Conditional Log BP khác xem thế nào, quay trở lại hàm MessageBoxA và nhấn Shift+F4 để sửa lại như sau :

<img src="http://i.imgur.com/kFFMtO0.png">

- Với Conditional Log bp này tôi thêm điều kiện là [esp]==0x40137D và cho dừng sự thực thi của chương trình khi thỏa điều kiện đã đặt ra.Sau khi sửa xong nhấn Ok để chấp nhận những thay đổi.Qua cửa sổ Log và clear hết thông tin cũ. Nhấn F9 để thực thi chương trình và nhập thông tin theo yêu cầu :

<img src="http://i.imgur.com/jjSfpoz.png">

- Sau đó nhấn OK, ngay lập tức Olly sẽ break tại chỗ ta đặt BP. Ta chuyển qua cửa sổ Log để quan sát kết quả thu được :

<img src="http://i.imgur.com/fxBIPpZ.png">

- Để ý kĩ ta thấy có khác với lần đặt BP trước là sự thực thi của chương trình đã dừng lại và có thêm dòng thông báo : Conditional breakpoint at user32.MessageBoxA. Điều đó chứng tỏ là điều kiện đặt bp đã thỏa cho nên chương trình mới dừng lại. Giờ ta kiểm tra cửa sổ Stack xem giá trị của Esp bây giờ có đúng là 0x0040137D hay không

<img src="http://i.imgur.com/jcEX4yB.png">

<a name="2.6"></a>
#### 2.6 Message Breakpoint

- Gần tương tự như Conditional Log Breakpoint nhưng Olly sẽ tự động tạo ra các điều kiện cho phép dừng lại tại các Message (Window Message)
- Một vài thông tin tìm hiểu về Window Message:
    + Mesage là một trong những phương tiện giao tiếp quan trọng nhất trong môi trường Windows.
    + Lập trình trong Windows chủ yếu là đáp ứng lại những sự kiện.
    + Message có thể báo hiệu nhiều sự kiện gây ra bởi người sử dụng, hệ điều hành, hoặc chương trình khác.
    + Có hai lọai message: window message và thread message.
    + **Window Message:**
        * Tất cả các message đều được trữ trong một Message Queue(một nơi trong bộ nhớ). Những message này sau đó sẽ được luân chuyển giữa các ứng dụng.
    + **Message Loop:**
        * Bạn có thể gọi những message bằng cách tạo ra một Message Queue.
        * Message Loop là một vòng lặp kiểm tra những message trong Message Queue.
        * Khi một message được nhận, Message Loop giải quyết nó bằng cách gọi Message Handler (một hàm được thiết kế để giúp Message Loop xử lý message)(hầu hết công việc lập trình của mình sẽ tập trung vào đây)
        * Message Loop sẽ kết thúc khi nhận được message WM_QUIT (lúc người dùng chọn File/Exit || click vào nút Close || bấm Alt+F4)
        * Khi bạn tạo cửa sổ (ứng dụng) Windows sẽ tạo cho bạn một Message Handler mặc định. Bạn sẽ vào đây để sửa chữa giúp ứng dụng phản hồi lại những sự kiện theo ý bạn muốn ->chương trình của bạn.
        * Tất cả những control chuẩn đều như thế. Lấy một button làm ví dụ: khi nó nhận WM_PAINT message nó sẽ vẽ button; khi bạn click chuột trái lên nó sẽ nhận WM_LBUTTONDOWN message và nó sẽ vẽ hình button bị nhấn xuống; khi buông chuột ra nó nhận WM_LBUTTONUP message và sẽ vẽ lại button bình thường.
        * Tên của window message thường có dạng WM_ và hàm để xử lý message đó thường có dạng On. Ví dụ hàm xử lý WM_SIZE message là OnSize.
        * Message thường có hai tham số lưu trữ thông tin về sự kiện(32 bit): lParam kiểu LONG và wParam kiểu WORD. Ví dụ: WM_MOUSEMOVE sẽ trữ tọa độ chuột trong một tham số còn  tham số kia sẽ có cờ hiệu để ghi nhận trạng thái của phím ATL, Shift, CTRL và những nút trên  con chuột.
        * Message có thể trả về một giá trị giúp bạn gửi dữ liệu ngược trở về chương trình gửi nó. Ví dụ: WM_CTLCOLOR message chờ bạn trả về một HBRUSH (khi dùng AppWizard để tạo nhanh ứng dụng bạn chú ý những hàm có dạng On... và nhận xét những kiểu trả về của nó, bạn sẽ hiểu hơn về cơ chế liên kết giữa các thành phần ứng dụng với nhau)
- Ví dụ minh họa về Window Message: (Tut 12)
- Load crackme vào OllyDbg cái đã:

<img src="http://i.imgur.com/IGy81Yo.png">

- Nhưng trước khi thực hiện phương pháp Message BP ta ôn lại phương pháp đặt BP tại APIs cái đã. Lần này tôi không dùng hàm MessageBoxA nữa mà sẽ dùng hàm GetDlgItemTextA, hàm này có nhiệm vụ như sau :

```C
The GetDlgItemText function retrieves the title or text associated with a control in a dialog box.

UINT GetDlgItemText (
HWND hDlg,  // handle of dialog box int nIDDlgItem, // identifier of control
LPTSTR lpString,    // address of buffer for text int nMaxCount // maximum size of string
);
```

- Mục đích của tôi là, thông qua hàm này tôi tìm ra nơi lưu thông tin mà tôi nhập vào để dùng cho các quá trình xử lý tiếp theo trong chương trình. Vậy để đặt BP tại hàm GetDlgItemTextA tôi làm như sau, trước tiên tôi tìm nó cái đã :

<img src="http://i.imgur.com/KMefcCC.png">

- Các bạn còn nhớ cách tìm hàm API trong cửa sổ Names mà tôi đã hướng dẫn ở các phần trước  chứ, nếu không nhớ thì các bạn chỉ việc : tại cửa sổ Names gõ đúng tên hàm API cần tìm là Olly sẽ đưa chúng ta đến đúng hàm ta cần. Tôi có được như sau :

<img src="http://i.imgur.com/Usn6lo8.png">

- Thực hiện đặt BP tại hàm này như sau :

<img src="http://i.imgur.com/MfpWbHF.png">

- Hoặc đơn giản hơn, tại cửa sổ Command Bar Plug-in ta gõ :

<img src="http://i.imgur.com/945RwzD.png">

- Đặt BP xong, cho thực thi chương trình bằng cách nhấn F9. Sau đó điền thông tin về UserName và Serial vào :

<img src="http://i.imgur.com/SviK6Gn.png">

- Nhập xong ta nhấn OK, ngay lập tức Olly sẽ break tại API GetDlgItemTextA mà chúng ta đã đặt BP ở trên.

<img src="http://i.imgur.com/cljbGd0.png">

- Đảo mắt qua cửa sổ Stack để xem ta thu được những thông tin gì:

<img src="http://i.imgur.com/vzovyLv.png">

- Wow, như các bạn thấy thông tin các tham số truyền vào cho hàm GetDlgItemTextA là hết sức rõ ràng, kết hợp với mô tả về hàm này ở trên các bạn sẽ thấy rằng tham số Buffer sẽ là nơi lưu đoạn text mà chúng ta nhập vào, nhưng lúc này chúng ta chưa biết là vùng Buffer này sẽ lưu Name hay Serial. Ta phỏng đoán theo thứ tự lần lượt từ trên xuống thì nó sẽ lấy UserName trước. Để xác định chính xác ta làm như sau, chuột phải tại chỗ Buffer và chọn Follow in Dump hoặc chuyển qua cửa sổ Dump, nhấn Ctrl + G và nhập vào địa chỉ của vùng Buffer là 0x0040218E :

<img src="http://i.imgur.com/g8uiLL3.png">

- Lúc này tại cửa sổ Dump các bạn nhận được kết quả là toàn byte 0x00. Đơn giản là vì ta đã thực  thi hàm đâu mà lấy được đoạn text nhập vào

<img src="http://i.imgur.com/KC39kUB.png">

- Bây giờ ta cho thực thi hàm GetDlgItemTextA và quan sát kết quả thu được tại cửa sổ Dump :

<img src="http://i.imgur.com/P6eRpKB.png">

<img src="http://i.imgur.com/jcQaseh.png">

- Ok đúng như ta phỏng đoán, chương trình sẽ lấy UserName nhập vào trước và lưu nó vào vùng Buffer có địa chỉ là 0x0040218E. Tiếp theo ta lại cho thực thi chương trình bằng cách nhấn F9 :

<img src="http://i.imgur.com/DhDTNRO.png">

<img src="http://i.imgur.com/WbapQXx.png">

- Bùm, Olly một lần nữa lại Break tại hàm GetDlgItemTextA. Không cần nói chắc các bạn cũng có thể đoán ra ngay được là nó sẽ lấy Serial mà ta nhập vào.Nhưng lúc này Serial sẽ được lưu vào  một vùng Buffer khác mà các bạn thấy ở trên, đó là 0x0040217E. Ta follow theo vùng Buffer này :

<img src="http://i.imgur.com/vFHfQDC.png">

- Cho thực thi hàm và kiểm tra kết quả có được tại vùng Buffer :

<img src="http://i.imgur.com/H1xa01A.png">

- Hehe Serial mà chúng ta nhập vào kìa!! Như vậy là với việc đặt BP tại hàm GetDlgItemTextA tôi đã dừng lại tại nơi lấy những thông tin mà tôi nhập vào, bao gồm UserName và Serial, bước tiếp theo tôi sẽ trace dần dần từng đoạn code cho tới khi nào tôi có thể tìm ra một Serial hợp lệ. Nhưng có lẽ tạm thời ta nên dừng lại tại đây để chuyển sang phần thực hành với Message BP, xem có thể thu được những thông tin tương tự như những gì ta vừa mới làm với việc đặt BP tại hàm APIs hay không? Trước khi thực hành ta xóa hết các BP đã đặt, vào cửa sổ BreakPoint và xóa hết :

<img src="http://i.imgur.com/FaI167M.png">

- Sau khi xóa xong, ta restart lại Olly và cho thực thi chương trình , tiến hành nhập thông tin mà chương trình yêu cầu :

<img src="http://i.imgur.com/tlOhzXJ.png">

- Không giống như đặt BP tại các hàm API là ta có thể đặt BP tại đầu hàm thì để đặt Message BP chúng ta phải làm việc với cửa sổ Windows. Hiện tại chương trình của chúng ta đang thực thi, chúng ta chuyển qua cửa sổ Window bằng cách nhấn vào nút W :

<img src="http://i.imgur.com/G2uzdVe.png">

- Sau khi bạn nhấn vào nút W thì cửa sổ Windows sẽ hiện ra. Nếu như bạn thấy nó trống trơn không có gì cả thì nhấn chuột phải và chọn Actualize :

<img src="http://i.imgur.com/WiC56UP.png">

- Kết quả ta có được như sau :

<img src="http://i.imgur.com/C2ypaQV.png">

- Như đã nói ở trên, mục đích của chúng ta là sau khi bấm Button Ok thì chương trình sẽ dừng lại. Vậy quan sát trong cửa sổ Windows, ở phần Class ta thấy có dòng Button, sau đó nhìn qua phần Title ta thấy được tên của Button là OK. Vậy đây chính là mục tiêu của chúng ta. Để đặt Message BP ta làm như sau, chuột phải tại nơi của Button OK và chọn Message Breakpoint on ClassProc:

<img src="http://i.imgur.com/1fmWZ91.png">

- Cửa sổ cho phép ta thiết lập BP hiện ra :

<img src="http://i.imgur.com/ljSBtmg.png">

- Ở phần Messages là một danh sách liệt kê những dạng Messages mà chúng ta có thể thiết lập BP :

<img src="http://i.imgur.com/IC8F5Hk.png">

- Như các bạn thấy, Olly hỗ trợ đủ loại Messages từ Text,Mouse, Keyboard v…v.. Song bên cạnh  đó nó còn hỗ trợ cho ta một loạt danh sách các Messages thông dụng nhất. Quay trở lại ví dụ của chúng ta: ta mong muốn khi ta nhấn chuột vào nút OK thì chương trình sẽ dừng sự thực thi. Vậy ta phân tích một chút, lúc ta bấm chuột mà cụ thể ở đây là chuột trái lên nút OK thì chương trình sẽ gửi một thông điệp là WM_LBUTTONDOWN (L ở đây có nghĩa là Left, BUTTONDOWN có nghĩa là ta bấm chuột xuống). Lúc ta nhả chuột thì chương trình cũng sẽ gửi một thông điệp là WM_LBUTTONUP. Do vậy trong trường hợp cụ thể của ta, ta sẽ nhờ Olly bắt thông điệp WM_LBUTTONUP khi ta nhả chuột khỏi nút OK. Trong phần Messages ta cuộn chuột xuống và tìm thấy :

<img src="http://i.imgur.com/N3UPrn0.png">

- Ta chọn nó và cấu hình lại như sau :

<img src="http://i.imgur.com/OJpl6TV.png">

- Sau khi cấu hình như trên ta nhấn OK :

<img src="http://i.imgur.com/CDQOWFy.png">

- Ta sẽ thấy chỗ ClsProc của hai Button Cancel và OK được hightlight. Bạn sẽ đặt câu hỏi là tại sao tôi đặt cho nút OK mà lại dính cả vào nút Cancel, đó là vì trong phần cấu hình BP ở trên bạn chọn là Break on any window, nếu bạn chọn là Break on all windows with same title thì sẽ có kết  quả tương tự nhưng lúc đó điều kiện đặt BP sẽ khác, các bạn hãy tự mình khám phá thêm. Bây giờ sau khi đặt BP như trên, ta nhấn nút OK để kiểm tra việc đặt BP :

<img src="http://i.imgur.com/GTSNXLA.png">

<img src="http://i.imgur.com/lmPagNc.png">

- Olly đã break ngay lập tức sau khi ta nhả nút OK, quan sát cửa sổ Stack bạn có được thông tin như trên. Tại cửa sổ Log Window lúc này ta cũng có được các tham số truyền vào :

<img src="http://i.imgur.com/RYllDj3.png">

- Ok vậy là quá trình thực thi của chương trình đã bị dừng lại và quyền điều khiển lúc này là của Olly. Tuy nhiên,như các bạn thấy thông thường khi dừng lại tại các hàm API ta luôn muốn tìm cách trở về đoạn code chính của chương trình, để rồi từ đó lần ra các manh mối tiếp theo. Vậy trong trường hợp này ta làm cách nào để quay về? Rất đơn giản các bạn nhấn Alt + M để mở cửa sổ Memory :

<img src="http://i.imgur.com/EFIe6vb.png">

- Các bạn biết rằng chương trình của chúng ta sẽ thực thi code tại section bắt đầu từ 0x00401000, do đó để quay về làm việc với code của chương trình ta đặt một BP tương tự như sau :

<img src="http://i.imgur.com/EXUcfV8.png">

- Sau đó nhần F9 để thực thi chương trình và chúng ta sẽ dừng lại tại đây :

<img src="http://i.imgur.com/3QKquyA.png">

- Đừng vội xóa bỏ Memory BP, ta tiếp tục nhấn F9 để thực thi chương trình. Bạn sẽ thấy lúc này chương trình sẽ lần lượt thực thi từng lệnh một, sau khi thực thi xong lệnh retn 10 bạn sẽ tới đây:

<img src="http://i.imgur.com/DRihXMJ.png">

- Để ý bạn sẽ thấy rằng chúng ta đang ở tại chỗ sắp sửa thực thi hàm API GetDlgItemTextA, mà hàm này sẽ lấy thông tin về UserName và Serial ta nhập vào để lưu vào vùng Buffer. Qua đây ta thấy rằng không cần sử dụng đến phương pháp đặt bp tại hàm API ta cũng có thể thông qua Messages BP để lần tới những điểm quan trọng.
- Tuy nhiên, giả sử trong một trường hợp nào đó mà chương trình không sử dụng hàm API để lấy text do ta nhập vào thì ta làm thế nào, lúc đó ta cần sử dụng đến Messages BP để tiếp cận mục tiêu. Ta sẽ thực hiện một demo nhỏ, trước tiên xóa Memory BP và Message BP đã đặt trước đó đi :

<img src="http://i.imgur.com/9CjR24Q.png">
<img src="http://i.imgur.com/wN3I1zu.png">

- Restart lại Olly và cho thực thi chương trình :

<img src="http://i.imgur.com/wN3I1zu.png">

- Ở đây tôi chưa nhập thông tin gì vội, chuyển qua cửa số Windows và chọn Actualize :

<img src="http://i.imgur.com/wN3I1zu.png">

- Tại lần minh họa này tôi thực hiện đặt một Message BP như sau :

<img src="http://i.imgur.com/jc5WErj.png">

- Các bạn sẽ hỏi tại sao tôi chọn WM_KEYUP, đơn giản là vì khi tôi gõ một kí tự bất kì và nhả phím thì sẽ có một thông điệp WM_KEYUP sinh ra. Tôi muốn Olly bắt lấy thông điệp này và dừng sự thực thi của chương trình lại. Thông tin thêm về WM_KEYUP :

```C
The WM_KEYUP message is posted to the window with the keyboard focus when a nonsystem key is released. A nonsystem key is a key that is pressed when the  ALT key is not pressed, or a keyboard key that is pressed when a window has the keyboard focus.

WM_KEYUP
nVirtKey = (int) wParam;    // virtual-key code lKeyData = lParam;  // key data
```

<img src="http://i.imgur.com/cCRAviE.png">

<img src="http://i.imgur.com/f3bKwj5.png">

- Sau khi đặt BP như trên, tôi tiến hành gõ thử một kí tự vào Textbox Name tuy nhiên khi tôi nhả phím thì chẳng thấy chương trình dừng lại gì cả. Đó là bởi vì chương trình mà chúng ta làm việc không xử lý các Messages liên quan tới WM_KEYUP, nhưng qua đây ta cũng biết được một hướng khác để tiếp cận mục tiêu.
- Quay trở lại vấn đề chính, tôi muốn tìm hiểu xem thực sự Message BP là gì và hoạt động của nó. Tôi tiến hành đặt lại BP tại Message 202 WM_LBUTTONUP :

<img src="http://i.imgur.com/2L2cIgW.png">

- Sau đó nhấn OK ta sẽ break :

<img src="http://i.imgur.com/aQy21wJ.png">

- Chuyển qua cửa sổ Breakpoint ta thấy như sau :

<img src="http://i.imgur.com/kpoPaBs.png">

- Chúng ta thấy rằng Message BP cũng được quản lý bởi cửa sổ BP, nhấn chuột phải vào BP này và chọn :

<img src="http://i.imgur.com/s3uRKa9.png">

<img src="http://i.imgur.com/iyAG3iK.png">

- Ồ.. vậy bản chất của Message BP thực ra là một Conditional Log BP, trong đó điều kiện để dừng sự thực thì của chương trình là [ESP+8]==WM_LBUTTONUP (tức là [ESP+8]==202). Lúc này ta để ý cửa sổ Stack :

<img src="http://i.imgur.com/BA1SNzk.png">

- Giá trị tại [esp + 8] đúng là 202, để cho rõ ràng hơn bạn nhấp đúp chuột tại cột chứa giá trị của ESP sẽ có được như sau :

<img src="http://i.imgur.com/b9cPGUL.png">

- “$+8” ở đây chính là “ESP + 8”. Hehe qua đó tôi biết chắc một điều rằng, giá trị [esp + 8] sẽ  chứa giá trị của các Messages. Vậy đề dò các giá trị tôi sửa lại BP như sau :

<img src="http://i.imgur.com/BeGQyt4.png">

- Ý nghĩa của những thiết lập trong hình trên tôi không cần phải giải thích lại nữa. Sửa lại BP xong tôi cho thực thi chương trình và nhập thông tin vào. Tiếp theo bấm OK và chuyển qua cửa sổ Log để quan sát các giá trị mà tôi thu được :

<img src="http://i.imgur.com/RxTf99W.png">

- Khà khà nhiều quá trời, để ý các bạn thấy là chương trình này xử lý hai Message là WM_LBUTTONDOWN(201) và WM_LBUTTONUP(202), đồng thời ta cũng thấy là nó không hề xử lý các Messages như WM_KEYUP hay WM_KEYDOWN.
- Ngoài ra để kiểm soát toàn bộ các Message cho tất cả các chương trình chúng ta có thể đặt một BP conditional log tại các hàm APIs chuyên kiểm soát các Messages. Hai hàm API đó là TranslateMessage và DefWindowProcA. Ta thực hiện như sau, tại command bar gõ hai lệnh :

<img src="http://i.imgur.com/9kMt9dk.png">

<img src="http://i.imgur.com/K7MqFS5.png">


- Mở cửa sổ quản lý BP, chọn BP đầu tiên, chuột phải và chọn FOLLOW IN DISSASSEMBLER :

<img src="http://i.imgur.com/Pdxju4r.png">

- Sau đó lại chuột phải tiếp và chọn :

<img src="http://i.imgur.com/OSldhDo.png">

- Đặt một Conditional Log BP như sau :

<img src="http://i.imgur.com/AZNH8Ei.png">

- Thực hiện tương tự với BP thứ hai :

<img src="http://i.imgur.com/vHJiMV8.png">

- Ok như vậy là ta đã chuyển hết hai BP sang dạng Conditional Log BP rồi :

<img src="http://i.imgur.com/YUub1Hr.png">

- Tiếp theo ta sẽ cấu hình cửa sổ Log để lưu toàn bộ thông tin vào một text file để tiện theo dõi. Chuyển qua cửa sổ Log, clear hết Log cũ đi sau đó chuột phải và chọn :

<img src="http://i.imgur.com/GFhin0F.png">

- Lưu với tên file bất kỳ mà bạn muốn, cuồi cùng ta cho thực thi chương trình :

<img src="http://i.imgur.com/MRda01D.png">

- Sau đó quan sát cửa sổ Log bạn sẽ thấy có rất nhiều Windows Message được xử lý. Đóng chương trình lại và kiểm tra log file của chúng ta xem ta thu được gì nào :

<img src="http://i.imgur.com/twSRsa0.png">

- Rất đầy đủ và chi tiết.

