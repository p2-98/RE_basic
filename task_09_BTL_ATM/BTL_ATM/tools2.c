#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <conio.h>
#include <time.h>
#include <memory.h>

char sTmpUser[255], sPass[255], sIdC[255], sM[255];
int IdCode, arrTmp[10000];
int Gsign();
void initButtonCF()
{
	char rButtonF[] = "OK",
		 lButtonC[] = "Thoat";
	rectangle(350,240,530,300);
		outtextxy(420,260,rButtonF);
	rectangle(20,240,200,300);
		outtextxy(75,260,lButtonC);
}
void PrintFileUserName()
{
	FILE *fi = NULL;
	fi = fopen("UserName.txt","a");
	fprintf(fi,"%s\n",sTmpUser);
	fclose(fi);
}
void PrintIdCode()
{
	FILE *fi = NULL;
	fi = fopen("DataID.txt","a");
	fprintf(fi,"%d\n",IdCode);
	fclose(fi);
	sprintf(sIdC,"%d",IdCode);
}
void InitIdCode()
{
	long tmp;
	FILE *fi = NULL;
	fi = fopen("DataID.txt","r");
	while (!feof(fi))
	{
		fscanf(fi,"%ld",&tmp);
		arrTmp[tmp] = 1;
	};
	memset(arrTmp, sizeof(arrTmp), 0);
	int tmpIdCode = rand()%(9999-1000+1) + 1000;
	//printf("%d",arrTmp[tmpIdCode]);
	//srand(time(NULL));
	while (arrTmp[tmpIdCode] == 1)
		tmpIdCode = rand()%(9999-1000+1) + 1000;
	IdCode = tmpIdCode;
	fclose(fi);
	PrintIdCode();
}
void CreateFileM()
{
	clearviewport();
	initButtonCF();
	char st[255];
	FILE *fi = NULL;
	strcpy(st,sTmpUser);
	strcat(st,".txt");
	fi = fopen(st,"w");
	fprintf(fi,"%s",sM);
	fclose(fi);
	FILE *fo = NULL;
	strcat(sTmpUser," Save.txt");
	fo = fopen(sTmpUser,"w");
	time_t rawtime;
 	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	fprintf(fo,"%sN %s\n",asctime(timeinfo), sM);
	fclose(fo);
	char sMessKeyBoard[] = "Tao file thong tin ",
		 sMessSucc[] = "Hoan thanh thong tin",
		 sC[]= ".";
	int tmp = 0;
	outtextxy(90,100,sMessKeyBoard);
	for (int i = 0; i < 6; i++)
		{
			outtextxy(300 + tmp,100,sC);
			tmp += 15;
			delay(1000);
		}
	clearviewport();
	outtextxy(100,150,sMessSucc);
	delay(1200);
	Gsign();
}
void CreateFilePass()
{
	clearviewport();
	initButtonCF();
	char sTmpPass[255];
	strcpy(sTmpPass,sTmpUser);
	strcat(sTmpPass," Pass.txt");
	FILE *fi = NULL;
	fi = fopen(sTmpPass,"w");
	fprintf(fi,"%s",sPass);
	fclose(fi);
	char 
		 sMessM[] = "Nhap so tien gui: ",
		 sEn[2];
	outtextxy(50,110,sMessM);
		rectangle(255,110,530,140);
	int tmp = 0, tmpR = 0;
	EnterM: sEn[0] = getch();
	sEn[1] = NULL;
	if (sEn[0] == 'c')
		{
			Gsign();
		}
	else
	if (sEn[0] == 'f')
		{
			sM[tmp] = NULL;
			CreateFileM();
		}
	else
		{
			sM[tmp] = sEn[0];
			tmp++;
			outtextxy(260 + tmpR,115,sEn);
			tmpR += 15;
			goto EnterM;
		}
}
void CreateFileUser()
{
	clearviewport();
	initButtonCF();
	PrintFileUserName();
	InitIdCode();
	char sMessInitId[] = "ID CODE: ",
		 sMessPass[] = "Nhap mat khau: ",
		 sEn[2];
	strcat(sMessInitId,sIdC);
	outtextxy(90,80,sMessInitId);
	outtextxy(50,110,sMessPass);
		rectangle(255,110,530,140);
	int tmp = 0, tmpR = 0;
	EnterPass: sEn[0] = getch();
	sEn[1] = NULL;
	if (sEn[0] == 'c')
		{
			Gsign();
		}
	else
	if (sEn[0] == 'f')
		{
			sPass[tmp] = NULL;
			CreateFilePass();
		}
	else
		{
			sPass[tmp] = sEn[0];
			tmp++;
			outtextxy(260 + tmpR,115,sEn);
			tmpR += 20;
			goto EnterPass;
		}
}
void SignUp()
{
	clearviewport();
	initButtonCF();
	char sMessName[] = "Ten nguoi dung: ",
		 sEn[2];
	outtextxy(50,110,sMessName);
		rectangle(255,110,530,140);
	int tmp = 0, tmpR = 0;
	EnterUserName: sEn[0] = getch();
	sEn[1] = NULL;
	if (sEn[0] == 'c')
		{
			Gsign();
		}
	else
	if (sEn[0] == 'f')
		{
			sTmpUser[tmp] = NULL;
			CreateFileUser();
		}
	else
		{
			sTmpUser[tmp] = sEn[0];
			tmp++;
			outtextxy(260 + tmpR,115,sEn);
			tmpR += 20;
			goto EnterUserName;
		}
}
void ToolSignUp()
{
	clearviewport();
	char sMessKeyBoard[] = "Detect KeyBoard ",
		 sC[]= ".";
	int tmp = 0;
	outtextxy(90,150,sMessKeyBoard);
	for (int i = 0; i < 6; i++)
		{
			outtextxy(300 + tmp,150,sC);
			tmp += 15;
			delay(1000);
		}
	SignUp();
}
