#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>

void GetUserName();
char sCheckId[10], sCheckPass[10], sUser[255],  fPass[255];
int countForPass;
int Compare(char *x, char *y)
{
	for (int i = 0; i < strlen(x); i++)
	{
		if (x[i] != y[i])
			return 1;
	}
	return 0;
}
int checkId()
{
	char sID[2];
	countForPass = 0;
	int tmp = 0, tmpR = 0;
	int tmpC = 1;
	printID: sID[0] = getch();
	sID[1] = NULL;
	sCheckId[tmp] = sID[0];
	outtextxy(175 + tmpR,98,sID);
	tmpR+=15;
	tmp++;
	if (tmp < 4) goto printID;
	sCheckId[tmp]=NULL;
	FILE *fi = NULL;
	char sTmp[4];
	fi = fopen("DataID.txt","r");
	while (!feof(fi))
		{
			countForPass++;
			fscanf(fi," %[^\n]", &sTmp);
			if (Compare(sTmp, sCheckId) == 0)
				{
					fclose(fi);
					return 0;
				}
		}
	fclose(fi);
	return 1;
}
int checkPass()
{
	char sPass[2], sPrintPass[] = "*", Pass[10], sFilePass[] = " Pass.txt";
	GetUserName();
	strcpy(fPass,sUser);
	//printf("%s\n",fPass);
	strcat(fPass,sFilePass);
	//printf("%s\n",fPass);
	int tmp = 0, tmpR = 0;
	printPass: sPass[0] = getch();
	sPass[1] = NULL;
	//strcat(sUser,sFilePass);
	sCheckPass[tmp] = sPass[0];
	outtextxy(175 + tmpR,148,sPrintPass);
	tmpR+=15;
	tmp++;
	if (tmp < 6) goto printPass;
	sCheckPass[tmp] = NULL;
	tmp = 0;
	FILE *fi = NULL;
	fi = fopen(fPass,"r");
	fscanf(fi," %[^\n]",&Pass);
	fclose(fi);
	if (Compare(Pass,sCheckPass) == 0)
		return 0;
	return 1;
}
void GetUserName()
{
	int tmp = 0;
	FILE *fi = NULL;
	fi = fopen("Username.txt","r");
	while (tmp < countForPass)
		{
			fscanf(fi," %[^\n]",sUser);
			tmp++;
		};
	fclose(fi);
}
int GraphicSign()
{
	clear: clearviewport();
	setcolor(9);
	char sCode[] = "ID CODE: ";
	settextstyle(6,HORIZ_DIR,2);
	outtextxy(20,100, sCode);
	rectangle(170,95,500,130);
	if (checkId() == 0)
		{
			char sPass[] = "Password: ";
			outtextxy(20,150, sPass);
			rectangle(170,145,500,180);
			if (checkPass() == 0)
				{
					char sMessSigninComplete[] = "Xin chao: ", sMessStart[] = "Tien hanh qua trinh giao dich...";
					strcat(sMessSigninComplete,sUser);	
					settextstyle(6,HORIZ_DIR,1);
					outtextxy(100,200,sMessSigninComplete);
					outtextxy(100,250,sMessStart);
					delay(1500);
					return 0;
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
