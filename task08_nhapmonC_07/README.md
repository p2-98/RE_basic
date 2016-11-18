###Tìm hiểu về thuật toán

> Tài liệu tham khảo: DSAP - Lê Minh Hoàng
>
> Thực hiện bởi: Phạm Phú Quí
>
> Cập nhật lần cuối : 18.10.2016

-----

###Mục lục:

- [1. Quy Hoạch Động](#qhd)

-----

<a name ="qhd"> </a>

###1. Quy hoạch động:

- Trong ngành khoa học máy tính, quy hoạch động là một phương pháp giảm thời gian chạy của các thuật toán thể hiện các tính chất của các bài toán con gối nhau (overlapping subproblem) và cấu trúc con tối ưu (optimal substructure).

- Nhà toán học Richard Bellman đã phát minh phương pháp quy hoạch động vào năm 1953. Ngành này đã được thành lập như là một chủ đề về kỹ nghệ và phân tích hệ thống đã được tổ chức IEEE thừa nhận.

- Cấu trúc con tối ưu có nghĩa là các lời giải tối ưu cho các bài toán con có thể được sử dụng để tìm các lời giải tối ưu cho bài toán toàn cục. Ví dụ, đường đi ngắn nhất tới một đỉnh trong một đồ thị có thể được tìm thấy bằng cách: trước hết tính đường đi ngắn nhất tới đích từ tất cả các đỉnh kề nó, rồi dùng kết quả này để chọn đường đi toàn cục tốt nhất, như trong hình 1. Nói chung, ta có thể giải một bài toán với cấu trúc con tối ưu bằng một quy trình ba bước:

	- Chia bài toán thành các bài toán con nhỏ hơn.
	- Giải các bài toán này một cách tối ưu bằng cách sử dụng đệ quy quy trình ba bước này.
	- Sử dụng các kết quả tối ưu đó để xây dựng một lời giải tối ưu cho bài toán ban đầu.

- Các bài toán con được giải bằng cách chia chúng thành các bài toán nhỏ hơn, và cứ tiếp tục như thế, cho đến khi ta đến được trường hợp đơn giản dễ tìm lời giải.
- Nói rằng một bài toán có các bài toán con trùng nhau có nghĩa là mỗi bài toán con đó được sử dụng để giải nhiều bài toán lớn hơn khác nhau. Ví dụ, trong dãy Fibonacci, F3 = F1 + F2 và F4 = F2 + F3 — khi tính mỗi số đều phải tính F2. Vì tính F5 cần đến cả F3 và F4, một cách tính F5 một cách ngây thơ có thể sẽ phải tính F2 hai lần hoặc nhiều hơn. Điều này áp dụng mỗi khi có mặt các bài toán con gối nhau: một cách tiếp cận ngây thơ có thể tốn thời gian tính toán lại lời giải tối ưu cho các bài toán con mà nó đã giải.
- Để tránh việc đó, ta lưu trữ lời giải của các bài toán con đã giải. Do vậy, nếu sau này ta cần giải lại chính bài toán đó, ta có thể lấy và sử dụng kết quả đã được tính toán. Hướng tiếp cận này được gọi là lưu trữ (trong tiếng Anh được gọi là memoization, không phải memorization, dù từ này cũng hợp nghĩa). Nếu ta chắc chắn rằng một lời giải nào đó không còn cần thiết nữa, ta có thể xóa nó đi để tiết kiệm không gian bộ nhớ. Trong một số trường hợp, ta còn có thể tính lời giải cho các bài toán con mà ta biết trước rằng sẽ cần đến.
- Tóm lại, quy hoạch động sử dụng:

	- Các bài toán con gối nhau
	- Cấu trúc con tối ưu
	- Memoization

- Quy hoạch động thường dùng một trong hai cách tiếp cận:

	- top-down (Từ trên xuống): Bài toán được chia thành các bài toán con, các bài toán con này được giải và lời giải được ghi nhớ để phòng trường hợp cần dùng lại chúng. Đây là đệ quy và lưu trữ được kết hợp với nhau.
	- bottom-up (Từ dưới lên): Tất cả các bài toán con có thể cần đến đều được giải trước, sau đó được dùng để xây dựng lời giải cho các bài toán lớn hơn. Cách tiếp cận này hơi tốt hơn về không gian bộ nhớ dùng cho ngăn xếp và số lời gọi hàm. Tuy nhiên, đôi khi việc xác định tất cả các bài toán con cần thiết cho việc giải quyết bài toán cho trước không được trực giác lắm.

- Một số ngôn ngữ lập trình hàm, nổi tiếng nhất là Haskell, có thể tự động lưu trữ kết quả của một lời gọi hàm với một tập đối số (argument) cụ thể, để tăng tốc cách đánh giá call-by-name (cơ chế này được gọi là call-by-need). Việc này chỉ có thể đối với các hàm không có hiệu ứng phụ, tính chất này luôn luôn đúng trong ngôn ngữ Haskell nhưng ít khi đúng trong các ngôn ngữ lập trình mệnh lệnh, chẳng hạn Pascal, C, C++, Java...

- Ví dụ
- Dãy Fibonacci
- Một cài đặt đơn giản của một hàm tính phần tử thứ n của dãy Fibonacci, trực tiếp dựa theo định nghĩa toán học. Cài đặt này thực hiện rất nhiều tính toán thừa.:

```C
function fib(n)
    if n = 0 or n = 1
	    return n
    else
        return fib(n − 1) + fib(n − 2)
```

- Lưu ý rằng nếu ta gọi, chẳng hạn, fib(5), ta sẽ tạo ra một cây các lời gọi hàm, trong đó các hàm của cùng một giá trị được gọi nhiều lần:

	- fib(5)
	- fib(4) + fib(3)
	- (fib(3) + fib(2)) + (fib(2) + fib(1))
	- ((fib(2) + fib(1)) + (fib(1) + fib(0))) + ((fib(1) + fib(0)) + fib(1))
	- (((fib(1) + fib(0)) + fib(1)) + (fib(1) + fib(0))) + ((fib(1) + fib(0)) + fib(1))

- Cụ thể, fib(2) được tính hai lần. Trong các ví dụ lớn hơn, sẽ có nhiều giá trị của fib, hay các bài toán con được tính lại, dẫn đến một thuật toán có thời gian lũy thừa.

- Bây giờ, giả sử ta có một đối tượng ánh xạ đơn giản, nó ánh xạ mỗi giá trị của fib đã được tính tới kết quả của giá trị đó. Ta sửa đổi hàm trên như sau để sử dụng và cập nhật ánh xạ trên. Hàm thu được chỉ đòi hỏi thời gian chạy O(n) thay vì thời gian chạy lũy thừa:

```C
var m:= map(0 → 1, 1 → 1)
function fib(n)
    if n not in keys(m)
        m[n]:= fib(n − 1) + fib(n − 2)
    return m[n]
```

- Đây là cách tiếp cận từ trên xuống, do trước hết ta chia bài toán thành các bài toán nhỏ hơn, rồi giải chúng và lưu trữ các kết quả. Trong trường hợp này, ta cũng có thể giảm từ chỗ hàm sử dụng không gian tuyến tính (O(n)) xuống chỉ còn sử dụng không gian hằng bằng cách sử dụng cách tiếp cận từ dưới lên. Cách này tính các giá trị nhỏ hơn của fib trước, rồi từ đó xây dựng các giá trị lớn hơn:

```C
function fib(n)
    var previousFib:= 1, currentFib:= 1
    repeat n − 1 times
        var newFib:= previousFib + currentFib
        previousFib:= currentFib
        currentFib:= newFib
    return currentFib
```

