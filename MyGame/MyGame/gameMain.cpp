#include <stdlib.h>
#include "glut.h"
#include <afxwin.h>
#include<time.h>
#include <math.h>
#include <stdio.h>
#include <conio.h>


void delay(int d)
{
	int end = clock() + d; // clock meanz current time : d meanz hourz, current time + duration
	while( clock() < end)// while current time is less than ending time do nothing
		;
}

void gameOver();
void myGame();
void idf();
void kdf(unsigned char,int,int);
void spdf(int,int,int);
	int x=800;
	int x1=500;
	int x2=980;
	int x3=350;
	int xb=940;
	int xt=0;		//tank
	int xc=30;
	int yc=475;
	int xt1=970;		//target
	int yt1=485;		//target
	int xt2=1370;		//target
	int yt2=485;		//target
	int bx,by;			//bulit
	int treex=940;
	int bbx,bby;			//bulit
	int firing=0;
	int toop=0;
	int c0x=200, c1x=500, c2x=900;
	int num=1;
	int ssflag=0;
	int hhx=1100,hhy=170,hhxlive=1;
	int hf1x=0,hf1y=0;
	int hf2x=0,hf2y=0;
	int hf3x=0,hf3y=0;
	int hf4x=0,hf4y=0;
	int score=0;
	int hitTime=-600;
	int mylife=100;

	int aaax1=1100,aaax1flag=0,aaax1bx1=0,aaax1bx2=0,aaax1bx3=0,aaax1live=1;
	int aaax2=699,aaax2flag=0,aaax2bx1=0,aaax2bx2=0,aaax2bx3=0,aaax2live=1;
	bool stop=false;
	bool resume=true;
	float ptime=clock();


	int *cloud2 =new int [20000];
	int *fire =new int [10000];
	int *tree =new int [10000];
	
	int *ss1 =new int [10000000];
	int *ss2 =new int [10000000];
	int *ss3 =new int [10000000];
	int *hh =new int [19236];
	int *aaa1 =new int [18400];
	int *aaa2 =new int [10000000];


void loadpic(int *bits, CString str)
{
	int *temp = new int[10000000];
	CBitmap bmp;
	HBITMAP hBitmap;
	BITMAP bm;

	hBitmap=(HBITMAP) LoadImage(NULL, str, IMAGE_BITMAP, 0,0, LR_LOADFROMFILE);
	bmp.Attach(hBitmap);
	bmp.GetBitmap(&bm);
	int h = bm.bmHeight, w = bm.bmWidth;
	int size = w * h * 4;
	int x = bmp.GetBitmapBits(size, temp);


	for(int i = 0; i < w*h; i+= w)
		for(int j = 0; j < w; j++)
			bits[i + j] = temp[h*w-w-i+j];

	bmp.Detach();
	delete temp;
}
//mfc 


void main(int argc,char **argv)
{
	glutInit(&argc, argv);
	glutInitWindowPosition(0, 0);
	
	glutInitDisplayMode(GLUT_DOUBLE);   //We do not use flush we use glutSwapBuffer();
	glutInitWindowSize(940, 680);
	int id=glutCreateWindow("My Game");
	glutDisplayFunc(myGame);
	gluOrtho2D(0, 939, 679, 0);
	glutIdleFunc(idf);
	glutKeyboardFunc(kdf);
	glutSpecialFunc(spdf);

	loadpic(cloud2,"cloud2.bmp");
	loadpic(ss1,"ss1.bmp");
	loadpic(ss2,"ss2.bmp");
	loadpic(ss3,"ss3.bmp");
	loadpic(hh,"hh.bmp");
	loadpic(aaa1,"aaa1.bmp");
	loadpic(aaa2,"aaa2.bmp");
	loadpic(fire,"fire.bmp");
	loadpic(tree,"tree.bmp");

	glutMainLoop();
}
void myGame()

{    
	
	glClearColor(0,0.63529,0.9098,0);
	glClear(GL_COLOR_BUFFER_BIT);
	
	

	glRasterPos2i(hhx ,hhy);
	glDrawPixels(229,84,GL_BGRA_EXT,GL_UNSIGNED_BYTE,hh);
	
	glRasterPos2i(treex ,530);
	glDrawPixels(100,100,GL_BGRA_EXT,GL_UNSIGNED_BYTE,tree);

	
	glRasterPos2i(c0x ,110);
	glDrawPixels(200,100,GL_BGRA_EXT,GL_UNSIGNED_BYTE,cloud2);
	glRasterPos2i(c1x ,100);
	glDrawPixels(200,100,GL_BGRA_EXT,GL_UNSIGNED_BYTE,cloud2);
	glRasterPos2i(c2x ,120);
	glDrawPixels(200,100,GL_BGRA_EXT,GL_UNSIGNED_BYTE,cloud2);
	
	if(aaax1live==1){
	glRasterPos2i(aaax1,500);
	glDrawPixels(99,160,GL_BGRA_EXT,GL_UNSIGNED_BYTE,aaa1);
	}
	if(aaax2live==1){
	glRasterPos2i(aaax2,530);
	glDrawPixels(136,115,GL_BGRA_EXT,GL_UNSIGNED_BYTE,aaa2);
	}
		
	



	
	glColor3f(1,1,1);
	
	
	if(ssflag==0){
	glRasterPos2i(xc ,yc);
	glDrawPixels(100,100,GL_BGRA_EXT,GL_UNSIGNED_BYTE,ss2);
	
	
	}
	if(ssflag==1){
	glRasterPos2i(xc,yc);
	glDrawPixels(100,100,GL_BGRA_EXT,GL_UNSIGNED_BYTE,ss1);

	}

	if(ssflag==2){
	glRasterPos2i(xc,yc);
	glDrawPixels(100,100,GL_BGRA_EXT,GL_UNSIGNED_BYTE,ss3);

	}

	glEnable(GL_LINE_STIPPLE);
	glLineStipple(8,0x0F0F);
	
	if(aaax1flag==1 && aaax1live==1){
		glColor3f(1,1,1);
		glLineWidth(10);
		glBegin(GL_LINES);
		glVertex2f(aaax1bx1,420);
		glVertex2f(aaax1bx1-200,420);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(aaax1bx2,420);
		glVertex2f(aaax1bx2-200,420);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(aaax1bx3,420);
		glVertex2f(aaax1bx3-200,420);
		glEnd();
	}
if(aaax2flag==1 && aaax2live==1){
		glColor3f(1,1,1);
		glLineWidth(10);
		glBegin(GL_LINES);
		glVertex2f(aaax2bx1,460);
		glVertex2f(aaax2bx1-200,460);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(aaax2bx2,460);
		glVertex2f(aaax2bx2-200,460);
		glEnd();
		glBegin(GL_LINES);
		glVertex2f(aaax2bx3,460);
		glVertex2f(aaax2bx3-200,460);
		glEnd();
	}

	if(firing==1 && ssflag!=2)
	{
		glColor3f(1,1,1);
		glLineWidth(10);
		glBegin(GL_LINES);
		glVertex2f(bx,by);
		glVertex2f(bx+200,by);
		glEnd();
	}

	if(firing==1 && ssflag==2)
	{
		glColor3f(1,1,1);
		glLineWidth(10);
		glBegin(GL_LINES);
		glVertex2f(bbx,bby);
		glVertex2f(bbx,bby-200);
		glEnd();
	}


	if(hhx<=750){
	glPointSize(9);
	glBegin(GL_POINTS);
	glVertex2f(hf1x,hf1y);
	
	glEnd();
	}

	if(hhx<=500){
	glPointSize(9);
	glBegin(GL_POINTS);
	glVertex2f(hf2x,hf2y);
	
	glEnd();
	}

	if(hhx<=250){
	glPointSize(9);
	glBegin(GL_POINTS);
	glVertex2f(hf3x,hf3y);
	
	glEnd();
	}

	if(hhx<=100){
	glPointSize(9);
	glBegin(GL_POINTS);
	glVertex2f(hf4x,hf4y);
	
	glEnd();
	}

	if(hf4y>500&&hf4y<520){
		glRasterPos2i(hf4x,500);
	glDrawPixels(100,100,GL_BGRA_EXT,GL_UNSIGNED_BYTE,fire);
	if(hf4x>=xc-10 &&  hf4x <= xc+80){
		mylife--;
		if(mylife<=0)
	gameOver();
	}
	
	}

	if(hf3y>500&&hf3y<520){
		glRasterPos2i(hf3x,500);
	glDrawPixels(100,100,GL_BGRA_EXT,GL_UNSIGNED_BYTE,fire);
	if(hf3x>=xc-10 &&  hf3x <= xc+80){
		mylife--;
		if(mylife<=0)
	gameOver();
	}
	
	}
	if(hf2y>500&&hf2y<520){
		glRasterPos2i(hf2x,500);
	glDrawPixels(100,100,GL_BGRA_EXT,GL_UNSIGNED_BYTE,fire);
	if(hf2x>=xc-10 &&  hf2x <= xc+80){
		mylife--;
		if(mylife<=0)
	gameOver();
	}
	}
	if(hf1y>500&&hf1y<520){
		glRasterPos2i(hf1x,500);
	glDrawPixels(100,100,GL_BGRA_EXT,GL_UNSIGNED_BYTE,fire);
	if(hf1x>=xc-10 &&  hf1x <= xc+80){
		mylife--;
		if(mylife<=0)
	gameOver();
	}
	}
	
	glColor3f(0,0,0);
	
	glBegin(GL_POLYGON);
	glVertex2f(xt1,yt1);
	glVertex2f(xt1+70,yt1);
	glVertex2f(xt1+70,yt1+10);
	glVertex2f(xt1+60,yt1+15);
	glVertex2f(xt1+10,yt1+15);
	glVertex2f(xt1,yt1+10);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex2f(xt2,yt2);
	glVertex2f(xt2+70,yt2);
	glVertex2f(xt2+70,yt2+10);
	glVertex2f(xt2+60,yt2+16);
	glVertex2f(xt2+10,yt2+16);
	glVertex2f(xt2,yt2+10);
	glEnd();
	
		glColor3f(1,0,0);
	glBegin(GL_POLYGON);
	glVertex2f(xt1+10,yt1);
	glVertex2f(xt1+10,yt1-50);
	glVertex2f(xt1+15,yt1-45);
	glVertex2f(xt1+30,yt1-75);
	glVertex2f(xt1+30,yt1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(xt2+10,yt2);
	glVertex2f(xt2+10,yt2-30);
	glVertex2f(xt2+15,yt2-25);
	glVertex2f(xt2+40,yt2-45);
	glVertex2f(xt2+40,yt2);
	glEnd();
	
	
	glBegin(GL_POLYGON);
	glVertex2f(xt1+30,yt1);
	glVertex2f(xt1+30,yt1-30);
	glVertex2f(xt1+45,yt1-25);
	glVertex2f(xt1+60,yt1-45);
	glVertex2f(xt1+60,yt1);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(xt2+40,yt2);
	glVertex2f(xt2+40,yt2-75);
	glVertex2f(xt2+55,yt2-45);
	glVertex2f(xt2+65,yt2-50);
	glVertex2f(xt2+65,yt2);
	glEnd();
	
	if(clock()<5000){
	char str2[50]="Game is Start Good Luck! Use A S Z X for playing";
	glColor3f(1,1,1);
	glRasterPos2i(330,200);
	for(int i=0;i<strlen(str2);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str2[i]);
	stop=false;
	}
	
	if(xc+60>=xt1+20&&xc+60<=xt1+70&&yc>460||xc+60>=xt2+20&&xc+60<=xt2+70&&yc>460){
		mylife--;
		if(mylife<=0)
	gameOver();
	}
	
	if((aaax1bx1>=xc+30&&aaax1bx1<=xc+80&&yc>470)||(aaax1bx2>=xc+30&&aaax1bx2<=xc+80&&yc>470)||(aaax1bx3>=xc+30&&aaax1bx3<=xc+80&&yc>470)){
	mylife--;
		if(mylife<=0)
	gameOver();
	}
	if((aaax2bx1>=xc+30&&aaax2bx1<=xc+80&&yc>480)||(aaax2bx2>=xc+30&&aaax2bx2<=xc+80&&yc>480)||(aaax2bx3>=xc+30&&aaax2bx3<=xc+80&&yc>480)){
	mylife--;
		if(mylife<=0)
	gameOver();
	}
	if(bby>=hhy&&bby<=hhy+70&&bbx>=hhx+20&&bbx<=hhx+180){
	hhxlive=0;
	hhx=-1;
	hf1x=0,hf1y=0;
	hf2x=0,hf2y=0;
	hf3x=0,hf3y=0;
	hf4x=0,hf4y=0;
	hitTime=clock();
	score+=1000;
	}

	if(clock()<hitTime+1000){
	char str2[50]="You Got 1000 Points Hiting H!";
	glColor3f(1,1,1);
	glRasterPos2i(330,200);
	for(int i=0;i<strlen(str2);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str2[i]);
	
	}
	if(bx+10>=aaax1+10 && bx+10<=aaax1+90 && by >= 380 && by <= 460){
	aaax1live=0;
	aaax1bx1=0;
		aaax1bx2=0;
		aaax1bx3=0;
		score++;
	}

	if(bx+10>=aaax2+10 && bx+10<=aaax2+90 && by >= 440 && by <= 470){
	aaax2live=0;
	aaax2bx1=0;
		aaax2bx2=0;
		aaax2bx3=0;
		score++;
	}
	glColor3f(0.47843,0.30196,0.20392);
	char str[50]="Your Score Is = ";
	char val[10]="";
	sprintf(val,"%d",score);
	strcat(str,val);
	glRasterPos2i(30,40);
	for(int i=0;i<strlen(str);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str[i]);
	glColor3f(1,0,0);
	char str1[50]="Your Life Is = ";
	char val1[10]="";
	sprintf(val1,"%d",mylife);
	strcat(str1,val1);
	strcat(str1," % Remaning");
	glRasterPos2i(330,40);
	for(int i=0;i<strlen(str1);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str1[i]);
	
	if(resume==false)
	{
	char str5[50]="Press X to Resume!"; 
	glColor3f(1,1,1);
	glRasterPos2i(330,300);
	for(int i=0;i<strlen(str5);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str5[i]);
	}
	glColor3f(0.47843,0.30196,0.20392);
	
	glBegin(GL_QUADS);
	glVertex2f(0,500);
	glVertex2f(940,500);
	glVertex2f(940,680);
	glVertex2f(0,680);
	glEnd();
	
	glutSwapBuffers();
	
	
	
	
}
void idf(){

	if(stop==false)
	{
		if(clock()-ptime>=1)
	{
		treex--;
		if(treex==0)
			treex=940;
/*	x--;
	if(x==-80)
		x=940;
	x1--;
	if(x1==-180)
		x1=900;
	x2--;
	if(x2==-280)
		x2=980;
	x3--;
	if(x3==-80)
		x3=980;
		*/
	xb--;
	if(xb==0)
		xb=1000;
		

	xt1--;
	if(xt1==-280)
		xt1=980;
	xt2--;
	if(xt2==-280)
		xt2=980;
	if(firing==1 && ssflag!=2)
	{
		bx+=8;
		
	}
	if(firing==1 && ssflag==2)
	{
		bby-=8;
		
	}
	if(yc<499)
		yc++;
	
	

	c0x--;
	if(c0x==-180)
		c0x=980;
	c1x--;
	if(c1x==-180)
		c1x=980;
	c2x--;
	if(c2x==-180)
		c2x=980;

	hhx--;
	if(hhx==-280){
		hhx=940;
		hhxlive=1;
	}
	if(hhxlive!=0){
	if(hhx==750){
		hf1x=hhx+50;
		hf1y=150;
	}
	if(hhx<750)
		hf1y++;
	if(hhx==500){
		hf2x=hhx+50;
		hf2y=150;
	}
	if(hhx<500)
		hf2y++;

	if(hhx==250){
		hf3x=hhx+50;
		hf3y=150;
	}
	if(hhx<250)
		hf3y++;

	if(hhx==100){
		hf4x=hhx+50;
		hf4y=150;
	}
	if(hhx<100)
		hf4y++;
	}

	aaax1--;
	if(aaax1==-80){
	aaax1=1100;
	aaax1flag=0;
	aaax1live=1;
	}
	if(aaax1live!=0){
	if(aaax1==935){
		aaax1flag=1;
		aaax1bx1=aaax1;

	}
	
		aaax1bx1-=6;
	if(aaax1==700){
		aaax1flag=1;
		aaax1bx1=aaax1;

	}
	aaax1bx2-=6;
	if(aaax1==500){
		aaax1flag=1;
		aaax1bx1=aaax1;

	}
	
		
	aaax1bx3-=6;
	}

	aaax2--;
	if(aaax2==0){
	aaax2=940;
	aaax2flag=0;
	aaax2live=1;
	}
	if(aaax2live!=0){
	if(aaax2==800){
		aaax2flag=1;
		aaax2bx1=aaax2;

	}
	
		aaax2bx1-=6;
	if(aaax2==600){
		aaax2flag=1;
		aaax2bx1=aaax2;

	}
	aaax2bx2-=6;
	if(aaax2==500){
		aaax2flag=1;
		aaax2bx1=aaax2;


	}
	
		
	aaax2bx3-=6;
	}
	
	
	myGame();
		ptime = clock();
	}
	}
}
void spdf(int key,int x,int y)
{
	
	
	if(key==GLUT_KEY_RIGHT&&stop!=true){
		if(xc<900)
		xc+=25;
		else
			xc=900;
		if(num%2==0)
		ssflag=0;
		if(num%2==1)
		ssflag=1;
		num++;
		myGame();
	}
	if(key==GLUT_KEY_LEFT&&stop!=true){
		if(xc>=25){
		xc-=25;	 
		if(num%2==0)
		ssflag=0;
	if(num%2==1)
		ssflag=1;
	num++;
		myGame();
		}
		else
			xc=0;
	
	}
	if(key==GLUT_KEY_UP&&stop!=true){
	
		if(yc>470)
		yc-=150;
	
	}
	
	myGame();
}

void kdf(unsigned char key,int x,int y)
{
	if(key == 's' || key == 'S')
	{
	
		firing=1;
		bx=xc+100;
		by=yc-46;
		ssflag=1;

	}
	if(key == 'a' || key == 'A' )
	{
		ssflag=2;
		firing=1;
		bbx=xc+50;
		bby=yc-95;
		myGame();
	}
	if(key=='z'|| key=='Z')
	{
	stop=true;
	resume=false;
	myGame();
	}
	if(key=='x'|| key=='X')
	{
	stop=false;
	resume=true;
	myGame();
	}
	
		
}

void gameOver(){
char str2[50]="Game over!"; 
	glColor3f(1,1,1);
	glRasterPos2i(330,300);
	for(int i=0;i<strlen(str2);i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,str2[i]);
	stop=true;}