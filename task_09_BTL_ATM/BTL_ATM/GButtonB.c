#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern char fSaveUser[255],
			fMoneyOfUser[255],
			sUser[255];
/*void OpenFS()
{
	int tmp = 1;
	char sTimeTmp[255], sMoneyTmp[255];
	FILE *fi = NULL;
	fi = fopen(fSaveUser,"r");
	while (!feof(fi))
		{
			fscanf(fi," %[^\n]", &arrT[tmp]);
			fscanf(fi," %[^\n]", &arrM[tmp]);
			tmp++;
			if (tmp == 6)
				tmp = 1;
		}
}
*/
long long OpenFM()
{
	
}
void ButtonB()
{
}
void GraphicButtonB()
{
	/*printf("%s\n",fSaveUser);
	printf("%s\n",fMoneyOfUser);*/
	clearviewport();
	//OpenFS();
	//OpenFM();
	char sBMessU[] = "Xin Chao: ",
		 sBMessTK[] = "So Tien Trong Tai Khoan Cua Quy Khach La: ",
		 sMessInfA[] = "Lan cap nhat tai khoan gan day nhat: ",
		 sButtonL[] = "Sao Ke TK",
		 sButtonR[] = "Thoat",
		 sEnterKey[2], sMoney[255];
	strcat(sBMessU, sUser);
	outtextxy(140,30, sBMessU);
	outtextxy(20,70,sBMessTK);
	rectangle(20,100,530,130);
	sprintf(sMoney,"%lld",OpenFM());
	outtextxy(220,105,sMoney);
	outtextxy(20,140,sMessInfA);
	//Button
	rectangle(20,240,200,300);
	rectangle(350,240,530,300);
	outtextxy(50,260,sButtonL);
	outtextxy(410,260,sButtonR);
	/*sEnterKey[0] = getch();
	sEnterKey[1] = NULL;
	if (sEnterKey[0] == 'c')
		ButtonB();
	else
		if (sEnterKey[0] = 'f')
			atmTools1();
	getch();*/
	getch();
}
