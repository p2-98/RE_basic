#include <stdio.h>;
#include <math.h>;
int solve(long n)
{
    long sum = 0;
    while (n)
        {
            sum += n % 10;
            n /= 10;
        };
    return (sum % 10 == 9);
}
int main()
{
    long n;
    scanf("%ld",&n);
    if (solve(n) == 1)
        printf("YES");
    else
        printf("NO");
    return 0;
}
/*Số tự nhiên N được gọi là số đẹp nếu cộng các chữ số của N lại ta có một số mà kết thúc bằng 9. Ví dụ một số số đẹp là 18 (1+8=9), 234 (2+3+4=9), 658 (6+5+8=19). Cho một số N, hãy kiểm tra xem N có phải là số đẹp hay không.
Dữ liệu nhập:
- Là số nguyên N (0 ≤ n ≤ 109)
Dữ liệu xuất:
- Nếu N là số đẹp, in ra "YES", nếu không in ra "NO"
Ví dụ
input
27
output
YES
input
658
output
YES
input
111
output
NO*/
