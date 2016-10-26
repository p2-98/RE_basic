#include <stdio.h>
#include <stdlib.h>
const int MAX=1000;
int n,m,w[MAX],v[MAX],f[MAX][MAX];

void vet(int i,int j){
    if (f[i][j]!=0)
        if (f[i][j]==f[i-1][j-w[i]]+v[i]){
            vet(i-1,j-w[i]);
            printf("%d ",i);
        }
        else
            vet(i-1,j);
}

int max(int a,int b){
    return a>b?a:b;
}

int main(){
    scanf("%d %d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%d %d",&w[i],&v[i]);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            if (j>=w[i])
                f[i][j]=max(f[i-1][j-w[i]]+v[i],f[i-1][j]);
            else
                f[i][j]=f[i-1][j];

    printf("%d\n",f[n][m]);
    vet(n,m);
}
/*rong siêu thị có N gói hàng, gói hàng thứ i có trọng lượng là Wi và giá trị là Vi. Một tên trộm đột nhập vào siêu thị, tên trộm mang theo một cái túi có thể mang được tối đa trọng lượng là M. Hỏi tên trộm sẽ lấy đi những gói hàng nào để được tổng giá trị là lớn nhất.
Dữ liệu nhập:
- Dòng thứ nhất là hai số N, M cách nhau một khoảng trắng (1 ≤ N ≤ 100, 1 ≤ M ≤ 100)
- Trong N dòng tiếp theo, dòng thứ i là hai số nguyên Wi và Vi cách nhau một khoảng trắng (1 ≤ Wi , Vi ≤ 100)
Dữ liệu xuất:
- Nếu tên trộm không thể lấy được món đồ nào, in ra 0.
- Nếu tên trộm có thể lấy được ít nhất một món đồ, dòng thứ nhất in ra giá trị lớn nhất tên trộm có thể lấy. Dòng thứ hai là chỉ số những gói bị lấy. Nếu có nhiều cách lấy đồ có cùng giá trị lớn nhất, chỉ cần in ra một cách bất kỳ.
Ví dụ
input
5 11
3 3
4 4
5 4
9 10
4 5
output
12
5 2 1
Lấy 3 đồ vật 1, 2, 5 có tổng trọng là: 3+4+4 = 11 và tổng giá trị là: 3+4+5 = 12
*/
