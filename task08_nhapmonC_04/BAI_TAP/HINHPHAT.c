#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    int *pn, *px, *py;
    int x, y, n;
    x = y = 1;
    scanf("%d", &n);
    px = &x;
    py = &y;
    pn = &n;
    int s[n];
    for(int i = 0; i < *pn; i++)
    {
        scanf("%d", &s[i]);
        if(s[i] == 1)
            *px= *px+1;
        else
            *py= *py+1;
    }
	int	res =(*px - *py);
	printf("%d", abs(res));
}
/*Bạn Nam mất trật tự trong giờ học thể dục nên bị thầy giáo phạt. Hình phạt của thầy như sau: bạn Nam đứng nghiêm, khi thầy hô "trái" thì Nam bước sang trái một mét, thầy hô "phải" thì Nam bước sang phải một mét. Hỏi sau n lần thầy hô như vậy thì bạn Nam cách xa vị trí ban đầu bao nhiêu mét?
Dữ liệu nhập:
- Dòng thứ nhất là số n (1 ≤ n ≤ 100).
- Dòng tiếp theo gồm n số 1 hoặc 2, mỗi số cách nhau một khoảng trắng. Nếu là số 1 thì thầy giáo hô "trái", nếu là số 2 thì thầy giáo hô "phải".
Dữ liệu xuất:
- Là khoảng cách của Nam sau n lần hô so với vị trí ban đầu.
 
Ví dụ
input
3
1 1 1
output
3
input
4
1 1 2 1
output
2
input
5
2 2 1 1 1
output
1
*/
