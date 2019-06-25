
#include <afxwin.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "glut.h"
#include <time.h>
#include <math.h>

void delay(int d)
{
	int end = clock() + d;
	while (clock() < end);
}

void myGame();
void idf();
void spdf(int, int, int);
int start = 1;
int deel = 1;
int cx = 0;
int cy = 0;
int cx1 = 400;
int cy1 = 0;
int tgx1 = 170;
int tgx2 = 290;
int tgy1 = 0;
int tgy2 = -400;
int tgy3 = -800;
int tgy4 = -200;
int tgy5 = -600;
int tgy6 = -1000;
int tgy7 = -1400;
int tgy8 = -1200;
int tgy9 = -1800;
int tgy10 = 200;
int tgy11 = 600;
int carx = 170;
int cary = 380;
int score = 0;
//////////////// arrays for image//////////////////

int *b1 = new int[10000000];
int *b2 = new int[10000000];
int *b3 = new int[10000000];
int *b4 = new int[10000000];
int *b5 = new int[10000000];
int *b6 = new int[10000000];
int *b7 = new int[10000000];
int *b8 = new int[10000000];
int *b9 = new int[10000000];




int ptime = clock();

void loadpic(int *bits, CString str)
{
	int *temp = new int[10000000];
	CBitmap bmp;
	HBITMAP hBitmap;
	BITMAP bm;

	hBitmap = (HBITMAP)LoadImage(NULL, str, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	bmp.Attach(hBitmap);
	bmp.GetBitmap(&bm);
	int h = bm.bmHeight, w = bm.bmWidth;
	int size = w * h * 4;
	int x = bmp.GetBitmapBits(size, temp);


	for (int i = 0; i < w*h; i += w)
	for (int j = 0; j < w; j++)
		bits[i + j] = temp[h*w - w - i + j];

	bmp.Detach();
	delete temp;
}


void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowPosition(100, 50);
	glutInitWindowSize(640, 680);
	int id = glutCreateWindow("My Game");
	glutDisplayFunc(myGame);
	gluOrtho2D(0, 499, 399, 0);

	glutSpecialFunc(spdf);
	glutIdleFunc(idf);
	loadpic(b1, "w11.bmp");
	loadpic(b2, "w12.bmp");
	loadpic(b3, "w13.bmp");
	loadpic(b4, "w14.bmp");
	loadpic(b5, "w15.bmp");
	loadpic(b6, "w16.bmp");
	loadpic(b7, "w17.bmp");
	loadpic(b8, "w18.bmp");
	loadpic(b9, "w19.bmp");


	glutMainLoop();

}
void spdf(int key, int x, int y)
{
	if (start == 1)
	{

		if (key == GLUT_KEY_RIGHT)
			carx = 290;
		if (key == GLUT_KEY_LEFT)
			carx = 170;
	}
	myGame();
}

void idf()
{

	if (carx == tgx1 && tgy1 <= cary - 20 && tgy1 >= cary - 70 || carx == tgx1 && tgy2 <= cary - 20 && tgy2 >= cary - 70 || carx == tgx1 && tgy3 <= cary - 20 && tgy3 >= cary - 70 || carx == tgx1 && tgy11 <= cary - 20 && tgy11 >= cary - 70)
	{
		start = 0;
		myGame();
	}
	else
	if (carx == tgx2 && tgy4 <= cary - 20 && tgy4 >= cary - 70 || carx == tgx2 && tgy7 <= cary - 20 && tgy7 >= cary - 70 || carx == tgx2 && tgy8 <= cary - 20 && tgy8 >= cary - 70 || carx == tgx2 && tgy9 <= cary - 20 && tgy9 >= cary - 70 || carx == tgx2 && tgy10 <= cary - 20 && tgy10 >= cary - 70 || carx == tgx2 && tgy8 <= cary - 20 && tgy8 >= cary - 70)
	{
		start = 0;
		myGame();
	}
	if (clock() % 10000 == 0)
		deel--;

	if (start == 1)
	{

		tgy1++;
		if (tgy1 == 800)
		{
			tgy1 = -800;
		}

		tgy2++;
		if (tgy2 == 800)
		{
			tgy2 = -800;
		}

		tgy3++;
		if (tgy3 == 800)
		{
			tgy3 = -800;
		}

		tgy4++;
		if (tgy4 == 800)
		{
			tgy4 = -800;
		}
		tgy6++;
		if (tgy6 == 800)
		{
			tgy6 = -800;
		}
		tgy7++;
		if (tgy7 == 800)
		{
			tgy7 = -800;
		}
		tgy8++;
		if (tgy8 == 800)
		{
			tgy8 = -800;
		}
		tgy9++;
		if (tgy9 == 800)
		{
			tgy9 = -800;
		}
		tgy10++;
		if (tgy10 == 800)
		{
			tgy10 = -800;
		}
		tgy11++;
		if (tgy11 == 800)
		{
			tgy11 = -800;
		}

		
		tgy5++;
		if(tgy5==800)
		{
		tgy5=-800;
		}
		
		if (tgy1 == 480 || tgy2 == 480 || tgy3 == 480 || tgy4 == 480 || tgy6 == 480 || tgy7 == 480 || tgy8 == 480 || tgy9 == 480 || tgy10 == 480 || tgy11 == 480)
		{
			score+=10;
			
		}
		myGame();

	}


	delay(deel);
}
void myGame()

{

	glClearColor(0.5, 0.5, 0.5, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	if (clock()<5000){
		char str2[50] = "Game is Start Good Luck!";
		glColor3f(1, 1, 1);
		glRasterPos2i(180, 200);
		for (int i = 0; i<strlen(str2); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str2[i]);

	}


	glRasterPos2i(tgx1, tgy1);
	glDrawPixels(100, 150, GL_BGRA_EXT, GL_UNSIGNED_BYTE, b2);

	glRasterPos2i(tgx1, tgy2);
	glDrawPixels(100, 150, GL_BGRA_EXT, GL_UNSIGNED_BYTE, b3);

	glRasterPos2i(tgx1, tgy11);
	glDrawPixels(100, 150, GL_BGRA_EXT, GL_UNSIGNED_BYTE, b8);

	glRasterPos2i(tgx1, tgy3);
	glDrawPixels(100, 150, GL_BGRA_EXT, GL_UNSIGNED_BYTE, b5);

	glRasterPos2i(tgx2, tgy5);
	glDrawPixels(100, 150, GL_BGRA_EXT, GL_UNSIGNED_BYTE, b3);

	glRasterPos2i(tgx2, tgy7);
	glDrawPixels(100, 150, GL_BGRA_EXT, GL_UNSIGNED_BYTE, b6);

	glRasterPos2i(tgx2, tgy4);
	glDrawPixels(100, 150, GL_BGRA_EXT, GL_UNSIGNED_BYTE, b7);

	glRasterPos2i(tgx2, tgy8);
	glDrawPixels(100, 150, GL_BGRA_EXT, GL_UNSIGNED_BYTE, b8);

	glRasterPos2i(tgx2, tgy9);
	glDrawPixels(100, 150, GL_BGRA_EXT, GL_UNSIGNED_BYTE, b9);

	glRasterPos2i(tgx2, tgy10);
	glDrawPixels(100, 150, GL_BGRA_EXT, GL_UNSIGNED_BYTE, b9);







	glRasterPos2i(carx, cary);
	glDrawPixels(100, 150, GL_BGRA_EXT, GL_UNSIGNED_BYTE, b1);


	glColor3f(0, 0, 1);

	glBegin(GL_QUADS);
	glVertex2i(cx, cy);
	glVertex2i(cx + 150, cy);
	glVertex2i(cx + 150, cy + 475);
	glVertex2i(cx, cy + 475);
	glEnd();

	glColor3f(0, 0, 1);
	glBegin(GL_QUADS);
	glVertex2i(cx1, cy1);
	glVertex2i(cx1 + 400, cy1);
	glVertex2i(cx1 + 400, cy1 + 475);
	glVertex2i(cx1, cy1 + 475);
	glEnd();



	glColor3f(1, 1, 1);
	glEnable(GL_LINE_STIPPLE);
	glLineStipple(8, 0x00ff);
	glLineWidth(10);

	glBegin(GL_LINES);
	glVertex2i(280, 20);
	glVertex2i(280, 480);
	glEnd();

	if (start == 0){
		char str2[50] = "Game Over!";
		glColor3f(1, 1, 1);
		glRasterPos2i(180, 200);
		for (int i = 0; i<strlen(str2); i++)
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str2[i]);

	}
	glColor3f(0.47843, 0.30196, 0.20392);
	char str[50] = "Your Score Is = ";
	char val[10] = "";
	sprintf_s(val, "%d", score);
	strcat_s(str, val);
	glRasterPos2i(30, 40);
	for (int i = 0; i<strlen(str); i++)
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, str[i]);

	glutSwapBuffers();
}
