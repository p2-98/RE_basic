#include <stdio.h>
#include <math.h>
int n,a[107];
void init()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
}
void solve()
{
    int f[107];
    init();
    sort(a+1,a+n+1);
    f[1] = a[1];
    f[2] = a[2];
    for(int i=3;i<=n;i++)
        f[i] = min(f[i-1]+f[1],f[i-2]+2*f[2]+f[1])+a[i];
    printf("%d",f[n]);
}
int main()
{
    solve();
    return 0;
}
/*Có n người cần qua bên kia cầu trong đêm. Vì cầu yếu nên chỉ đi một lúc tối đa được hai người. Trong đêm tối họ phải dùng đèn nhưng cả nhóm chỉ có 1 cái đèn. Vì vậy mỗi lần hai người cầm đèn qua sông thì phải có một người cầm đèn quay trở lại. Mỗi người qua cầu với các tốc độ lần lượt là: a1, a2, a3,..., an giây. Hai người đi cùng nhau thì sẽ đi theo vận tốc của người đi chậm hơn. Hỏi để tất cả n người đều qua sông được thì phải tốn ít nhất là bao nhiêu giây?
Dữ liệu nhập:
- Dòng đầu tiên là số nguyên n (1 ≤ n ≤ 100)
- Dòng thứ 2 gồm n số nguyên a1, a2, a3,..., an (1 ≤ ai ≤ 100), mỗi số cách nhau một khoảng trắng.
Dữ liệu xuất:
- Là thời gian ít nhất để n người đi qua cầu.
Ví dụ
input
4
1 3 8 12
output
22
input
5
1 3 6 8 12
output
29
input
1
4
output
4
Trong test 1 đi theo cách như sau:
1) Người 1 và 2 qua cầu: mất 3 giây.
2) Người 1 cầm đèn quay trở lại: mất 1 giây.
3) Người 3 và 4 qua cầu: mất 12 giây.
4) Người 2 cầm đèn quay trở lại:  mất 3 giây.
5) Người 1 và 2 qua cầu: mất 3 giây.
Tổng cộng mất 22 giây. */
