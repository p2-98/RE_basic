#include <stdio.h>;
#include <math.h>;
int main()
{
    long n, res = 1;
    scanf("%ld",&n);
    for (int i = 1; i <= n; i++)
        res = res * i;
    printf("%ld",res);
    return 0;
}
/*
Cho số nguyên n, hãy tính n!
Dữ liệu nhập:
- Là số nguyên n (1 ≤ n ≤ 17)
Dữ liệu xuất:
- Giá trị của n! . Chú ý rằng số này có thể rất lớn nên dùng kiểu long long.
Ví dụ
input
1
output
1
input
2
output
2
input
3
output
6
*/
