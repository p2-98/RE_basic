#include<stdio.h>
#include<math.h>
long a[7]={0,15,19,5,3,1,10},b[7]={0,2,3,2,1,1,1},a1[1000005];
long l[8][1000005];
long min(long a, long b)
{
	if(a<b) return a;
	else return b;
}
void tim(long n)
{
	long t=1;
	for(long i=1;i<=6;i++)
	for(long j=1;j<=n;j++)
	{
		
		if(l[i][j-a[i]]==0)
		{
			if(a[i]==j) 
			{
				l[i][j]=b[i];
				if(l[i-1][j]!=0) l[i][j]=min(b[i],l[i-1][j]);
			}
			
			else l[i][j]=l[i-1][j];
		}
		
		
		else
		{
			if(l[i-1][j]!=0)
			l[i][j]=min(l[i-1][j],l[i][j-a[i]]+b[i]);
			else l[i][j]=l[i][j-a[i]]+b[i];
			
		}
	
	}
	
}
int main()
{
	
	long t,n;
	scanf("%ld",&t);
	for(long i=1;i<=t;i++)
	{
		
		scanf("%ld",&a1[i]);
		
	}
	long max=a1[1];
	for(long i=1;i<=t;i++)
	if(a1[i]>max) max=a1[i];
	tim(max);
	for(long i=1;i<=t;i++)
		printf("%ld\n",l[6][a1[i]]);
}
/*
Hùng đang chơi một trò chơi võ thuật đối kháng, trong trò chơi này, bạn sẽ phải đánh bại các đối thủ bằng các kỹ năng của mình, ở mỗi vòng bạn sẽ thi đấu với một đối thủ, mỗi lần thi triển kỹ năng, bạn nhận được một số điểm kỹ năng nhất định. Đặc biệt, trong trò chơi này, nếu bạn đã đánh bại đối thủ thì bạn chưa chắc đã chiến thắng, bạn còn phải đạt được chính xác số điểm kỹ năng mà đối thủ quy định sao cho số lần thi triển kỹ năng là ít nhất. Sau đây là các kỹ năng bạn có thể sử dụng và số điểm kỹ năng giành được khi thi triển:
++ Đấm: sau khi đấm bạn sẽ có thêm 5 điểm
++ Nhảy: sau khi nhảy bạn sẽ có thêm 4 điểm
++ Đẩy: sau khi đẩy bạn sẽ có thêm 4 điểm
++ Kéo: sau khi kéo bạn sẽ có thêm 3 điểm
++ Đá trên không: sau khi đá trên không bạn sẽ có thêm 1 điểm
++ Đá: sau khi đá bạn sẽ có thêm 10 điểm
Tuy nhiên, các kỹ năng này không thể sử dụng một cách tùy ý mà nó còn có những quy tắc nhất định:
++ Sau khi đấm, bạn bắt buộc phải đá.
++ Sau khi nhảy, bạn bắt buộc phải đấm.
++ Sau khi đẩy, bạn bắt buộc phải đá trên không.
Vì mải chơi nên không thể tính toán được, bạn hãy giúp Hùng tính cách chơi tối ưu nhất nhé.
Input
Dòng thứ nhất là số nguyên T - số vòng của trò chơi (1 <= T <= 105)
T dòng tiếp theo, mỗi dòng là số nguyên N là số điểm kỹ năng bạn phải đạt được trong vòng chơi tương ứng (1 <= N <= 106)
Output
Gồm T dòng, mỗi dòng là số lần thi triển kỹ năng ít nhất để đạt được chính xác số điểm kỹ năng mà vòng chơi đó yêu cầu
Ví dụ
input
4
1
2
3
4
output
1
2
1
2 */
