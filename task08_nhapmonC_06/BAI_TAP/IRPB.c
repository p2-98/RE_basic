#include <stdlib.h>
#include <stdio.h>

int main()
{
    long k, m, n;
    FILE* taptin = NULL;
    taptin = fopen("rosalind_iprb.txt", "r");
    fscanf(taptin, "%ld %ld %ld", &k, &m, &n);
    fclose(taptin);
    long a, b, c, s;
    a = 4 * k * (k - 1);
    b = 3 * m * (m - 1);
    c = 4 * (2 * k * m + 2 * k * n + m * n);
    s = k + m + n;
    float res =  (a + b + c)*1.0 / (4 * s * (s - 1));
    FILE* taptin1 = NULL;
    taptin1 = fopen("rosalind_iprb_result.txt", "w");
    fprintf(taptin1,"%f", res);
    fclose(taptin1);
return 0;
}
/*CHO: Ba số nguyên dương k, m, n tượng trưng cho kích thước quần thể có k + m + n (cá thể) với k là số lượng các thể mang thể đồng hợp trội, m là số lượng cá thể mang thể dị hợp và n  là số lượng cá thể mang thể đồng hợp lặn.
KẾT QUẢ: Giả định rằng hai cá thể có khả năng giao phối. Cho biết xác suất mà hai cá thể lựa chọn ngẫu nhiên được giao phối sẽ tạo ra một cá thể đời sau sở hữu một alen trội (và do đó hiển thị qua kiểu hình trội). 
Hãy viết chương trình cho phép đọc tập tin văn bản có tên rosalind_iprb.txt chứa các số k, m, n. 
Yêu cầu: xác suất mà hai cá thể giao phối lựa chọn ngẫu nhiên sẽ tạo ra một cá thể đời sau sở hữu một alen trội. Sau đó ghi kết quả ra file có tên rosalind_iprb_result.txt 
DỮ LIỆU MẪU 
2 2 2
KẾT QUẢ MẪU 
0.78333
*/
