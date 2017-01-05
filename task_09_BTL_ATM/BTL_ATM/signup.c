#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

void ToolSignUp();
int Compare1(char *x, char *y)
{
	for (int i = 0; i < strlen(x); i++)
	{
		if (x[i] != y[i])
			return 1;
	}
	return 0;
}
int checkId1()
{
	char sID[2], sTmp[] = "*", sCheckId[255];
	int tmp = 0, tmpR = 0;
	int tmpC = 1;
	printID: sID[0] = getch();
	sID[1] = NULL;
	sCheckId[tmp] = sID[0];
	outtextxy(175 + tmpR,98,sTmp);
	tmpR+=15;
	tmp++;
	if (tmp < 9) goto printID;
	sCheckId[tmp]=NULL;
	if(Compare1("147258369", sCheckId) == 0)
				{
					return 0;
				}
	return 1;
}
int checkPass1()
{
	char sPass[2], sPrintPass[] = "*", sCheckPass[255];
	//printf("%s\n",fPass);
	//printf("%s\n",fPass);
	int tmp = 0, tmpR = 0;
	printPass: sPass[0] = getch();
	sPass[1] = NULL;
	//strcat(sUser,sFilePass);
	sCheckPass[tmp] = sPass[0];
	outtextxy(175 + tmpR,148,sPrintPass);
	tmpR+=15;
	tmp++;
	if (tmp < 12) goto printPass;
	sCheckPass[tmp] = NULL;
	tmp = 0;
	if (Compare1("123456789101",sCheckPass) == 0)
		return 0;
	return 1;
}
int GSignUp()
{
	clear: clearviewport();
	setcolor(9);
	char sCode[] = "ID CODE: ";
	settextstyle(6,HORIZ_DIR,2);
	outtextxy(20,100, sCode);
	rectangle(170,95,500,130);
	if (checkId1() == 0)
		{
			char sPass[] = "Password: ";
			outtextxy(20,150, sPass);
			rectangle(170,145,500,180);
			if (checkPass1() == 0)
				{
					ToolSignUp();
					getch();
				}
			else
				{
					char sMessIdFail[] = "Ban nhap sai mat khau";
					settextstyle(6,HORIZ_DIR,1);
					outtextxy(180,70, sMessIdFail);
					while (!kbhit()) delay(1);
					goto clear;
				};
		}
	else
		{
			char sMessIdFail[] = "ID ban nhap khong ton tai";
			settextstyle(6,HORIZ_DIR,1);
			outtextxy(180,70, sMessIdFail);
			while (!kbhit()) delay(1);
			goto clear;
		}

}
