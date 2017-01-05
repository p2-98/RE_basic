#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

extern char sUser[255], fPass[255];
char fMoneyOfUser[255],
	 fSaveUser[255],
	 arrT[10][255],
	 arrM[10][255],
	 sNewPass[255];
long long nMoney, MN;
int atmTools1();
int Gsign();
int Compare(char *x, char *y);
void GraphicButtonB();
void MoneyOfUser()
{
	//file Save
	char sSave[] = " Save.txt";
	strcpy(fSaveUser,sUser);
	strcat(fSaveUser,sSave);
	//file Tien
	char sfInform[] =".txt";
	strcpy(fMoneyOfUser, sUser);
	strcat(fMoneyOfUser,sfInform);
	//printf("%s",sTmpUser);
	FILE *fi = NULL;
	fi = fopen(fMoneyOfUser,"r");
	fscanf(fi,"%lld", &nMoney);
	fclose(fi);
}
void GraphicTool()
{
	clearviewport();
	settextstyle(6,HORIZ_DIR,1);
	//Init Button Left
	rectangle(20,40,200,100);
	rectangle(20,140,200,200);
	rectangle(20,240,200,300);
	//Init Button Right
	rectangle(350,40,530,100);
	rectangle(350,140,530,200);
	rectangle(350,240,530,300);
	//Init Label For Button Left
	char lButtonA[] = "Rut tien", lButtonB[] = "Thong tin TK" ,lButtonC[] = "Doi mat khau";
	outtextxy(70,60,lButtonA);
	outtextxy(25,160,lButtonB);
	outtextxy(30,260,lButtonC);
	//Init Label For Button Right
	char rButtonD[] = "Chuyen tien", rButtonE[] = "Tra Cuu DV", rButtonF[] = "Thoat";
	outtextxy(370,60,rButtonD);
	outtextxy(370,160,rButtonE);
	outtextxy(410,260,rButtonF);
}
void GraphicButtonA()
{
	clearviewport();
	//Init Button Left
	rectangle(20,40,200,100);
	rectangle(20,140,200,200);
	rectangle(20,240,200,300);
	//Init Button Right
	rectangle(350,40,530,100);
	rectangle(350,140,530,200);
	rectangle(350,240,530,300);
	//Init Label For Button Left
	char lButtonA[] = "500.000", lButtonB[] = "1.000.000" ,lButtonC[] = "1.500.000";
	outtextxy(70,60,lButtonA);
	outtextxy(60,160,lButtonB);
	outtextxy(60,260,lButtonC);
	//Init Label For Button Right
	char rButtonD[] = "2.000.000", rButtonE[] = "So Tien Khac", rButtonF[] = "Thoat";
	outtextxy(385,60,rButtonD);
	outtextxy(365,160,rButtonE);
	outtextxy(400,260,rButtonF);
}
int gButtonRT()
{
	/* Graphic */
	char sMessRT[] = "Quy khach vui long doi trong giay lat...";
	clearviewport();
	outtextxy(50,150,sMessRT);
	delay(1200);
}
int MessCont()
{
	char sMessTTGD[] = "Ban co muon thuc hien giao dich khac?",
		 sMessY[] = "Co", sMessN[] = "Khong",
		 sMessThanks[] = "Cam on quy khach da su dung dich vu";
	clearviewport();
	outtextxy(50,90,sMessTTGD);
	rectangle(20,140,200,200);
	rectangle(350,140,530,200);
	outtextxy(90,160,sMessY);
	outtextxy(400,160,sMessN);
	char sEnterButton[2];
	sEnterButton[0] = getch();
	sEnterButton[1] = NULL;
	if (sEnterButton[0] == 'b')
		atmTools1();
	if (sEnterButton[0] == 'e')
		{
			clearviewport();
			//settextstyle(6,HORIZ_DIR,4);
			outtextxy(60,150,sMessThanks);
			delay(1500);
			//update sau
			Gsign();
		}
}
int checkMoneyInAccount(long long x, long long y)
{
	if (x > y)
		{
			char sMessFail[] = "So tien rut vuot qua so du kha dung";
			clearviewport();
			outtextxy(60,150,sMessFail);
			delay(1500);
			return 1;
		}
	return 0;
}
int EnterMoney()
{
	clear: clearviewport();
	char sMessEnterMoney[] = "So Tien Ban Can Rut: ",
		 sMessLimit[] = "So tien ban rut vuot qua gioi han cho phep",
		 sMessOk[] = "OK";
	outtextxy(60,100,sMessEnterMoney);
	rectangle(60,150,400,200);
	rectangle(425,150,475,200);
	outtextxy(430,165,sMessOk);
	long long MoneyTmp = 0;
	int tmp = 0, tmpR = 0;
	char sMoney[2], sMoneyTmp[255], sTmp[2];
	sTmp[0] = getch();
	sTmp[1] = NULL;
	while (sTmp[0] != 'e')
		{
			sMoney[0] = sTmp[0];
			sMoney[1] = NULL;
			sMoneyTmp[tmp] = sMoney[0];
			outtextxy(65 + tmpR,160,sMoney);
			tmpR+=15;
			tmp++;
			sTmp[0]= getch();
		}
	sMoneyTmp[tmp] = NULL;
	MoneyTmp = atoi(sMoneyTmp);
	if ((MoneyTmp > 50000000) || (MoneyTmp < 100000))
		{
			outtextxy(60,225,sMessLimit);
			while (!kbhit()) delay(1);
			goto clear;
		}
	return MoneyTmp;
}
void Repair(long long x, long long y)
{
	long long tmp = y - x;
	//Tru Tien Tai Khoan
	FILE *fo = NULL;
	fo = fopen(fMoneyOfUser,"w");
	fprintf(fo,"%lld",tmp);
	fclose(fo);
}
void Save(long long x)
{
	//printf("%s",fSaveUser);
	//Sao Ke Tai Khoan
	FILE *fi = NULL;
	fi = fopen(fSaveUser,"a+");
	time_t rawtime;
 	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	fprintf(fi,"%sR %lld\n",asctime(timeinfo), x);
	fclose(fi);
}
int ButtonA()
{
	char sEnterButton[2];
	sEnterButton[0] = getch();
	sEnterButton[1] = NULL;
	if (sEnterButton[0] == 'a')
		{
			int nMoneyTmp = 500000;
			if (checkMoneyInAccount(nMoneyTmp, nMoney) == 0)
				{
					gButtonRT();
					MessCont();
					//Repair(nMoneyTmp, *nMoney);
					Save(nMoneyTmp);
					nMoney -= nMoneyTmp;
				}
			else
				MessCont();
		};
	if (sEnterButton[0] == 'b')
		{
			int nMoneyTmp = 1000000;
			if (checkMoneyInAccount(nMoneyTmp, nMoney) == 0)
				{
					gButtonRT();
					MessCont();
					//Repair(nMoneyTmp, nMoney);
					Save(nMoneyTmp);
					nMoney -= nMoneyTmp;				
				}
			else
				MessCont();
		};
	if (sEnterButton[0] == 'c')
		{
			int nMoneyTmp = 1500000;
			if (checkMoneyInAccount(nMoneyTmp, nMoney) == 0)
				{
					gButtonRT();
					MessCont();
					//Repair(nMoneyTmp, nMoney);
					Save(nMoneyTmp);
					nMoney -= nMoneyTmp;
				}
			else
				MessCont();
		};
	if (sEnterButton[0] == 'd')
		{
			int nMoneyTmp = 2000000;
			if (checkMoneyInAccount(nMoneyTmp, nMoney) == 0)
				{
					gButtonRT();
					MessCont();
					//Repair(nMoneyTmp, nMoney);
					Save(nMoneyTmp);
					nMoney -= nMoneyTmp;
				}
			else
				MessCont();
		};
	if (sEnterButton[0] == 'e')
		{
			long long nMoneyTmp = EnterMoney();
			if (checkMoneyInAccount(nMoneyTmp, nMoney) == 0)
				{
					gButtonRT();
					MessCont();
					//Repair(nMoneyTmp, nMoney);
					Save(nMoneyTmp);
					nMoney -= nMoneyTmp;
				}
			else
				MessCont();
		}
	if (sEnterButton[0] == 'f')
		atmTools1();
}
void OpenFS()
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
/*
void OpenFM()
{
	FILE *fi = NULL;
	fi = fopen(fMoneyOfUser,"r");
	fscanf(fi,"%lld",&M);
	fclose(fi);
}
*/
void ButtonB()
{
	clearviewport();
	int tmp = 0;
	char sTmpT[255], sTmpM[255], sMessE[] = "Thoat", sEnterKey[2];
	for (int i = 1; i < 6; i++)
	{
		strcpy(sTmpT,arrT[i]);
		strcpy(sTmpM,arrM[i]);
		outtextxy(20,50 + tmp, sTmpT);
		outtextxy(350,50 + tmp, sTmpM);
		tmp +=40;
	}
	rectangle(350,240,530,300);
	outtextxy(410,260, sMessE);
	sEnterKey[0] = getch();
	sEnterKey[1] = NULL;
	if (sEnterKey[0] = 'f')
		atmTools1();
}
void GraphicButtonB()
{
	clearviewport();
	OpenFS();
	//OpenFM();
	char sBMessU[] = "Xin Chao: ",
		 sBMessTK[] = "So Tien Trong Tai Khoan Cua Quy Khach La: ",
		 sMessInfA[] = "Lan cap nhat tai khoan gan day nhat: ",
		 sButtonL[] = "Sao Ke TK",
		 sButtonR[] = "Thoat",
		 sEnterKey[2], sMoney[255],
		 sUpdateInfT[255], sUpdateInfM[255];
	strcat(sBMessU, sUser);
	outtextxy(140,30, sBMessU);
	outtextxy(20,70,sBMessTK);
	rectangle(20,100,530,130);
	strcpy(sMoney,"");
	sprintf(sMoney,"%lld",nMoney);
	outtextxy(220,105,sMoney);
	outtextxy(20,140,sMessInfA);
	strcpy(sUpdateInfT,arrT[5]);
	strcpy(sUpdateInfM,arrM[5]);
	outtextxy(20,190,sUpdateInfT);
	outtextxy(350,190,sUpdateInfM);
	//Button
	rectangle(20,240,200,300);
	rectangle(350,240,530,300);
	outtextxy(50,260,sButtonL);
	outtextxy(410,260,sButtonR);
	sEnterKey[0] = getch();
	sEnterKey[1] = NULL;
	if (sEnterKey[0] == 'c')
		ButtonB();
	else
		if (sEnterKey[0] = 'f')
			atmTools1();
	getch();
}
int checkOldPass(int x, int y)
{
	char sPass[2], sCheckPass[255],
		 sPrintPass[] = "*", Pass[255];
	int tmp = 0, tmpR = 0;
	printPass: sPass[0] = getch();
	sPass[1] = NULL;
	sCheckPass[tmp] = sPass[0];
	outtextxy(x + tmpR,y,sPrintPass);
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
int initNewPass()
{
	char sPass[2], sNewPass1[255], sNewPass2[255],
		 sPrintPass[] = "*", sMessNP[] = "Mat khau moi: ",
		 sMessReNP[] = "Nhap lai MK: ";
	//NewPass
	int tmp = 0, tmpR = 0;
	rectangle(220,100,450,130);
	outtextxy(40,105,sMessNP);
	printPass1: sPass[0] = getch();
	sPass[1] = NULL;
	sNewPass1[tmp] = sPass[0];
	outtextxy(255 + tmpR,105,sPrintPass);
	tmpR+=15;
	tmp++;
	if (tmp < 6) goto printPass1;
	sNewPass1[tmp] = NULL;
	//Re-En NewPass
	rectangle(220,160,450,190);
	outtextxy(40,165,sMessReNP);
	tmp = 0, tmpR = 0;
	printPass2: sPass[0] = getch();
	sPass[1] = NULL;
	sNewPass2[tmp] = sPass[0];
	outtextxy(255 + tmpR,165,sPrintPass);
	tmpR+=15;
	tmp++;
	if (tmp < 6) goto printPass2;
	sNewPass2[tmp] = NULL;
	/*printf("%s\n",sNewPass1);
	printf("%s\n",sNewPass2);*/
	if (Compare(sNewPass1, sNewPass2) == 0)
		{
			strcpy(sNewPass,sNewPass1);
			return 0;
		}
	return 1;
}
void UpdateFPass()
{
	FILE *fi = NULL;
	fi = fopen(fPass,"w");
	fprintf(fi,"%s",sNewPass);
	fclose(fi);
	clearviewport();
	char sSuccess[] = "Doi mat khau thanh cong";
	outtextxy(150,120,sSuccess);
	delay(1200);
	MessCont();
}
void GraphicButtonC()
{
	clear: clearviewport();
	char sMessOldPass[] = "Mat khau cu: ",
		 sMessOk[] = "Doi mat khau",
		 sMessE[] = "Thoat",
		 sMessFCmp[] = "Mat khau khong khop",
		 sMessRe[] = "Quy khach vui long nhap lai",
		 sMessFi[] = "OK";
	rectangle(220,35,450,65);
		outtextxy(40,40,sMessOldPass);	
	rectangle(350,240,530,300);
		outtextxy(370,260,sMessOk);
	if (checkOldPass(255,40) == 0)
		{
			int tmpNP = initNewPass();
			if (tmpNP == 1)
				{
					clearviewport();
					outtextxy(150,120,sMessFCmp);
					outtextxy(125,150,sMessRe);
					delay(1500);
					goto clear;
				}
			else
				{
					outtextxy(460,165,sMessFi);
				};
		}
	else
		{
			char sMessFail[] = "Sai mat khau";
			outtextxy(220,66,sMessFail);
			while (!kbhit()) delay(1);
			goto clear;
		};
	char sEnterButton[2];
	sEnterButton[0] = getch();
	sEnterButton[1] = NULL;
	if (sEnterButton[0] == 'f')
		UpdateFPass();
}
void ProcessD(char *TM, char *sU)
{
	char sSave[] = " Save.txt",
		 sTmpU[255];
	strcpy(sTmpU, sU);
	strcat(sU,sSave);
	FILE *fi = NULL;
	fi = fopen(sU,"a+");
	time_t rawtime;
 	struct tm * timeinfo;
	time ( &rawtime );
	timeinfo = localtime ( &rawtime );
	fprintf(fi,"%sN %lld\n",asctime(timeinfo), MN);
	fclose(fi);
	//Repairr File User
	long long m;
	char sSaveM[] = ".txt";
	strcat(sTmpU,sSaveM);
	FILE *fii = NULL;
	fii = fopen(sTmpU,"r");
	fscanf(fii,"%lld", &m);
	fclose(fii);
	FILE *fo = NULL;
	long long sum = m + MN;
	fo = fopen(sTmpU,"w");
	fprintf(fo,"%lld", sum);
	fclose(fo);
}
void ButtonD()
{
	char sMessIDN[] = "ID Nguoi Nhan: ",
		 sMessM[] = "So Tien Can Chuyen: ",
		 sButtonR[] = "Chuyen Khoan",
		 sUserTmp[255],
		 sMessFailId[] = "ID ban nhap khong ton tai";
	clear: clearviewport();
	rectangle(300,50,550,80);
		outtextxy(70,55,sMessIDN);
	rectangle(300,170,550,200);
		outtextxy(40,170,sMessM);
	rectangle(350,240,530,300);
		outtextxy(355,260,sButtonR);
	//EnterID
	int tmp = 0, tmpW = 0, count = 0;
	char sEn[2], sEID[255], sEM[255], sIdTmp[255], sMessFailID[] = "ID ban nhap khong ton tai";
	EnterID: sEn[0] = getch();
	sEn[1] = NULL;
	sEID[tmp] = sEn[0];
	tmp++;
	outtextxy(310 + tmpW,55,sEn);
	tmpW += 15;
	if (tmp < 4) goto EnterID;
	sEID[tmp] = NULL;
	//Print ID Nguoi Nhan
	//printf("%s\n",sEID);
	FILE *fi = NULL;
	int countID = 0;
	fi = fopen("DataID.txt","r");
	while (!feof(fi))
		{
			fscanf(fi," %[^\n]", sIdTmp);
			count++;
			if (Compare(sIdTmp, sEID) == 0)
				{
					countID = 1;
					break;
				}
		}
	//printf("%s\n",sIdTmp);
	if (countID == 0)
		{
			clearviewport();
			outtextxy(150,85,sMessFailID);
			delay(1200);
			goto clear;
		}
	else
		{
			char sMessIDN[] = "Ten Cua Nguoi Nhan: ",
				 sMess[] = "So tien hien co trong tai khoan cua ban: ",
				 sMessMoA[255];
			FILE *fi = NULL;
			fi = fopen("Username.txt","r");
			for (int i = 1; i < count + 1; i++)
				{
					fscanf(fi," %[^\n]", sUserTmp);
				}
			//printf("%s\n",sUserTmp);
			outtextxy(40,95,sMessIDN);
			outtextxy(300,95,sUserTmp);
			sprintf(sMessMoA,"%lld",nMoney);
			outtextxy(40,115,sMess);
			outtextxy(40,135,sMessMoA);
		}
	//EnterM
	tmp = 0;
	EnterM: sEn[0] = getch();
	sEn[1] = NULL;
	if (sEn[0] == 'f')
		{
			char sMessSucc[] = "Giao dich thanh cong";
			sEM[tmp] = NULL;
			MN = atoi(sEM);
			nMoney -=MN;
			Save(MN);
			ProcessD(sEM, sUserTmp);
			clearviewport();
			outtextxy(160,160,sMessSucc);
			delay(1200);
			MessCont();
		}
	else
		{
			sEM[tmp] = sEn[0];
			tmp++;
			outtextxy(310 + tmpW,175,sEn);
			tmpW += 15;
			goto EnterM;
		}
}
void GraphicButtonD()
{
	clear: clearviewport();
	char sMessEnPass[] = "Moi ban nhap mat khau: ",
		 sMessEnF[] = "Sai mat khau, moi ban nhap lai ";
	rectangle(150,150,440,180);
		outtextxy(160,120,sMessEnPass);
	if (checkOldPass(230,155) == 0)
		{
			delay(1200);
			ButtonD();
		}
	else
		{
			outtextxy(140,185,sMessEnF);
			delay(1200);
			goto clear;
		}
	getch();
}
void Tool()
{
	char sEnterButton[2];
	sEnterButton[0] = getch();
	sEnterButton[1] = NULL;
	if (sEnterButton[0] == 'a')
		{
			GraphicButtonA();
			ButtonA();
		}
	if (sEnterButton[0] == 'b')
		{
			GraphicButtonB();
		}
	if (sEnterButton[0] == 'c')
		{
			GraphicButtonC();
		}
	if (sEnterButton[0] == 'd')
		{
			GraphicButtonD();
		}
	if (sEnterButton[0] == 'e')
		{
			clearviewport();
			char sMessDev[] = "Mo phong duoc viet boi: Pham Phu Qui - AT13M",
				 sMessEmail[] = "Email: phamphuqui1998@gmail.com",
				 sMessPhone[] = "Phone: 01665020373";
			outtextxy(0,100,sMessDev);
			outtextxy(60,140,sMessEmail);
			outtextxy(155,180,sMessPhone);
			getch();
			MessCont();
		}
	if (sEnterButton[0] == 'f')
		Gsign();
}
int atmTools1()
{	
	//Repair(0,nMoney);
	GraphicTool();
	Tool();
}
int atmTool()
{
	MoneyOfUser();
	//M = nMoney;
	atmTools1();
	Repair(0,nMoney);
}
