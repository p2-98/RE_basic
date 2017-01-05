#include <graphics.h>
#include <string.h>
#include <conio.h>
#include <stdio.h>
int Gsign();
int GSignUp();
int GraphicSign();
int atmTool();
int Monitor()
{
	initwindow(1300, 725);			
	setbkcolor(0);	
	cleardevice();
	setcolor(14);
	//Init Title
	char s[] = "Simulation ATM";
	settextstyle(6,HORIZ_DIR,5);			
	outtextxy(430,20,s);
	//Init Line Of Text
	setlinestyle(2,5,1);
	line(400, 20, 875, 20);
	line(400, 68, 875, 68);
	// Init Numpad
	setlinestyle(1,5,2);
	settextstyle(6,HORIZ_DIR,4);
	//Init Numpad 1
	char sTmp1[] = "1", sTmp2[] = "2", sTmp3[] = "3", sTmp4[] = "4", sTmp5[] = "5", sTmp6[] = "6", sTmp7[] = "7", sTmp8[] = "8", sTmp9[] = "9", sTmp0[] = "0";
	char sTmpA[] = "A", sTmpB[] = "B", sTmpC[] = "C", sTmpD[] = "D", sTmpE[] = "E", sTmpF[] = "F";
	rectangle(400 + 125,450+50, 450 + 125,500+50);
		outtextxy(513 + 25,455+50, sTmp1);
	rectangle(475 + 125, 450+50, 525 + 125, 500+50);
		outtextxy(588 + 25,455+50, sTmp2);
	rectangle(550 + 125,450+50,600 + 125 ,500+50);
		outtextxy(663 + 25,455+50, sTmp3);
	//Init Numpad 2
	rectangle(400 + 125, 525+25, 450 + 125, 575+25);
		outtextxy(513 + 25, 530+25, sTmp4);
	rectangle(475 + 125, 525+25, 525 + 125, 575+25);
		outtextxy(588 + 25, 530+25, sTmp5);
	rectangle(550 + 125,525+25, 600 + 125 ,575+25);
		outtextxy(663 + 25, 530+25, sTmp6);
	//Init Numpad 3
	rectangle(400 + 125,600, 450 + 125,650);
		outtextxy(513 + 25, 605, sTmp7);
	rectangle(475 + 125, 600, 525 + 125, 650);
		outtextxy(588 + 25, 605, sTmp8);
	rectangle(550 + 125,600,600 + 125 ,650);
		outtextxy(663 + 25, 605, sTmp9);
	//Init Numpad 4
	char sTmp[] = " ";
	rectangle(525, 650, 575, 700);
		outtextxy(513 + 25, 655, sTmp);
	rectangle(575 + 25, 650, 625 + 25, 700);
		outtextxy(588 + 25, 655, sTmp0);
	rectangle(650 + 25, 650, 700 + 25, 700);
		outtextxy(663 + 25, 655, sTmp);
	//Init AlphaPad
	setfillstyle(0,14);
	//Init AlphaPad Left
	bar3d(150 + 100,200,200+ 100,250,10,1);
		outtextxy(257,207,sTmpA);
	bar3d(150+ 100,275 + 25 ,200+ 100,325 + 25,10,1);
		outtextxy(259,307,sTmpB);
	bar3d(150+ 100,350 + 50 ,200+ 100,400 + 50,10,1);
		outtextxy(259,407,sTmpC);
	//Init AlphaPad Right
	bar3d(950,200,1000,250,10,1);
		outtextxy(957,207,sTmpD);
	bar3d(950,300,1000,350,10,1);
		outtextxy(957,307,sTmpE);
	bar3d(950,400,1000,450,10,1);
		outtextxy(960,407,sTmpF);
	//Init Monitor
	setcolor(8);
	setlinestyle(3,5,10);
	line(350,100,925,100);
	moveto(925,100);
	linerel(0,370);
	moveto(925,470);
	linerel(-575,0);
	moveto(350,470);
	linerel(0,-370);
	settextstyle(6,HORIZ_DIR,4);
	setcolor(2);
	char sWelcome[] = "Welcome To KMA BANK";
	outtextxy(375,120,sWelcome);
	setviewport(360,150,910,465,0);
	setcolor(9);
	setlinestyle(0,9,1);
	Gsign();
}
int Gsign()
{
	clearviewport();
	settextstyle(6,HORIZ_DIR,4);		
	rectangle(20,140,210,200);
	rectangle(340,140,530,200);
	//rectangle(380,300,580,350);
	//rectangle(700,300,900,350);
	setcolor(9);
	char sSignin[] = "SIGN IN", sSignup[] = "SIGN UP", sAdmin[] = "(For Admin)";
	/*outtextxy(395,305,sSignin);
	outtextxy(710,305,sSignup);*/
	outtextxy(28,160,sSignin);
	outtextxy(345,160,sSignup);
	settextstyle(6,HORIZ_DIR,2);
	outtextxy(360,210,sAdmin);
	settextstyle(6,HORIZ_DIR,4);
	char EnterButton[2];
	EnterButton[0] = getch();
	EnterButton[1] = NULL;
	if (EnterButton[0] == 'b')
		//Graphic
		{
			//setviewport(360,150,910,465,0);
			if (GraphicSign() == 0)
				atmTool();
		}
	else
	if (EnterButton[0] == 'e')
		{
			GSignUp();
		}
}
