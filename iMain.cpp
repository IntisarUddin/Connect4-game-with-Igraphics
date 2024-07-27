#include "iGraphics.h"
#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma comment(lib, "Winmm.lib")
#define screenwidth 1200 // 1200&650//1540&760
#define screenhight 650
#define m_w 1.283
#define m_h 1.169

/*
	function iDraw() is called again and again by the system.

	*/
struct object
{
	int x, y;
	bool e;
	bool yellow, red, white, mark;
};
struct object ball[6][7];

char bt[18][40] = {"button\\0.bmp", "button\\1.bmp", "button\\2_2.bmp", "button\\3.bmp", "button\\4.bmp", "button\\sound_1.bmp", "button\\exit.bmp", "button\\board.bmp", "button\\mute_1.bmp", "button\\back.bmp", "button\\pause.bmp", "button\\pause_op.bmp", "button\\back1.bmp", "button\\back2.bmp", "button\\pl1n.bmp", "button\\pl2n.bmp", "button\\next.bmp", "button\\name_temp.bmp"};
char im[15][40] = {"image\\1.bmp", "image\\2.bmp", "image\\3.bmp", "image\\4.bmp", "image\\p_1_wins.bmp", "image\\r.bmp", "image\\l1.bmp", "image\\h.bmp", "image\\p2_wins.bmp", "image\\bl.bmp", "image\\ins2.bmp", "image\\enter_name.bmp", "image\\view_board.bmp", "image\\score.bmp", "image\\move_left.bmp"};
bool music = true;
bool w = true;
int game_state = 0;
int y = 0;
bool d = false;
int a, b, c;
int z = 0;
bool v = true;
bool e = false;
bool l = false;
bool f = false;
int count = 0;
int count1 = 21;
int count2 = 21;
int mode = 0;
int mode1 = 0;
int mode2 = 0;
int mode3 = 0;
int mode4 = 0;
int len = 0;
int score;
char name[35], name_t[35], name1[35], name2[35];
char name_p[5][35];
char score_p[5][10];
char pos[5][2];
char score_s[8];
char count_s1[4];
char count_s2[4];
bool g = false;
bool h = true;

FILE *leaderboard;
FILE *Scores;
char *player_name = "PLAYER'S NAME";
char *player_score = "SCORE";

// HOF = fopen("HOF.txt", "r");
// Scores = fopen("Scores.txt", "r");

void make_all_neutral()
{
	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			ball[i][j].e = false;
			ball[i][j].yellow = false;
			ball[i][j].red = false;
			ball[i][j].white = false;
			ball[i][j].mark = false;
		}
	}
	v = true;
	z = 0;
	d = false;
	count1 = 21;
	count2 = 21;
	g = false;
	h = true;
	itoa(count1, count_s1, 10);
	itoa(count2, count_s2, 10);
}

int check_win(int a, int b, int c, object ball[6][7]) // a is row, b is coloum. r = 6, c = 7;
{
	int count = 0;
	int i;
	int k, l;
	k = a;
	l = b;
	if (c == 1) // yellow;
	{
		a = k;
		b = l;
		count = 0;
		for (i = 0; (i < 4) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // x axis forward;
		if(a<0 || b<0){break;}
			if (ball[a][b].yellow)
			{
				count++;
			}
			else
			{
				break;
			}
			b++;
		}
		if (count >= 4)
		{
			return 1;
		}
		// count = 0;
		a = k;
		b = l;
		for (i = 0; (i < 3) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // x axis backward;
		
			b--;
			if(a<0 || b<0){break;}
			if (ball[a][b].yellow)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if (count >= 4)
		{
			return 1;
		}
		count = 0;
		a = k;
		b = l;
		for (i = 0; (i < 4) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // y axis upward;
		if(a<0 || b<0){break;}
			if (ball[a][b].yellow)
			{
				count++;
			}
			else
			{
				break;
			}
			a++;
		}
		if (count >= 4)
		{
			return 1;
		}
		// count = 0;
		a = k;
		b = l;
		for (i = 0; (i < 3) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // y axis downward;
		
			a--;
			if(a<0 || b<0){break;}
			if (ball[a][b].yellow)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if (count >= 4)
		{
			return 1;
		}
		count = 0;
		a = k;
		b = l;
		for (i = 0; (i < 4) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // +45 degree;
		if(a<0 || b<0){break;}
			if (ball[a][b].yellow)
			{
				count++;
			}
			else
			{
				break;
			}
			a++;
			b++;
		}
		if (count >= 4)
		{
			return 1;
		}
		// count = 0;
		a = k;
		b = l;
		for (i = 0; (i < 3) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // -135 degree;

			a--;
			b--;
			
			if(a<0 || b<0){break;}
			if (ball[a][b].yellow)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if (count >= 4)
		{
			return 1;
		}
		count = 0;
		a = k;
		b = l;
		for (i = 0; (i < 4) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // +135 degree;
		if(a<0 || b<0){break;}
			if (ball[a][b].yellow)
			{
				count++;
			}
			else
			{
				break;
			}
			b--;
			a++;
		}
		if (count >= 4)
		{
			return 1;
		}
		// count = 0;
		a = k;
		b = l;

		for (i = 0; (i < 3) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // -45 Degree;
			b++;
			a--;
			if(a<0 || b>6){break;}
			if (ball[a][b].yellow)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if (count >= 4)
		{
			return 1;
		}
		count = 0;
		a = k;
		b = l;
	}

	else if (c == 2)
	{ // Red;
		count = 0;
		a = k;
		b = l;
		for (i = 0; (i < 4) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // x axis forward;
		if(a<0 || b<0){break;}
			if (ball[a][b].red)
			{
				count++;
			}
			else
			{
				break;
			}
			b++;
		}
		if (count >= 4)
		{
			return 2;
		}
		// count = 0;
		a = k;
		b = l;
		for (i = 0; (i < 3) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // x axis backward;
			b--;
			if(a<0 || b<0){break;}
			if (ball[a][b].red)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if (count >= 4)
		{
			return 2;
		}
		count = 0;
		a = k;
		b = l;
		for (i = 0; (i < 4) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // y axis upward;
		if(a<0 || b<0){break;}
			if (ball[a][b].red)
			{
				count++;
			}
			else
			{
				break;
			}
			a++;
		}
		if (count >= 4)
		{
			return 2;
		}
		// count = 0;
		a = k;
		b = l;
		for (i = 0; (i < 3) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // y axis downward;
			a--;
			if(a<0 || b<0){break;}
			if (ball[a][b].red)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if (count >= 4)
		{
			return 2;
		}
		count = 0;
		a = k;
		b = l;
		for (i = 0; (i < 4) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // +45 degree;
		if(a<0 || b<0){break;}
			if (ball[a][b].red)
			{
				count++;
			}
			else
			{
				break;
			}
			a++;
			b++;
		}
		if (count >= 4)
		{
			return 2;
		}
		// count = 0;
		a = k;
		b = l;
		for (i = 0; (i < 3) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // -135 degree;
			a--;
			b--;
			if(a<0 || b<0){break;}
			if (ball[a][b].red)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if (count >= 4)
		{
			return 2;
		}
		count = 0;
		a = k;
		b = l;
		for (i = 0; (i < 4) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // +135 degree;
		if(a<0 || b<0){break;}
			if (ball[a][b].red)
			{
				count++;
			}
			else
			{
				break;
			}
			b--;
			a++;
		}

		if (count >= 4)
		{
			return 2;
		}
		// count = 0;
		a = k;
		b = l;
		for (i = 0; (i < 3) && (a >= 0 && a <= 5) && (b >= 0 && b <= 6); i++)
		{ // -45 Degree;
			b++;
			a--;
			if(a<0 || b>6){break;}
			if (ball[a][b].red)
			{
				count++;
			}
			else
			{
				break;
			}
		}
		if (count >= 4)
		{
			return 2;
		}
		count = 0;
		a = k;
		b = l;
	}
	return 0;
}
void leader_board(FILE *leaderboard, FILE *Scores)
{
	leaderboard = fopen("leaderboard.txt", "r");
	Scores = fopen("Scores.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		pos[i][0] = i + '0' + 1;
		pos[i][1] = 0;
	}
	for (int i = 0; i < 5; i++)
	{
		fgets(score_p[i], 10, Scores);
		fgets(name_p[i], 35, leaderboard);
	}
	fclose(leaderboard);
	fclose(Scores);
	return;
}
void leaderboard2(char *name)
{
	FILE *tempname;
	FILE *leaderboard;
	FILE *Scores;
	FILE *tempscore;
	// int score;
	// char name[35];
	// scanf(" %[^\n]", name);
	// scanf("%d", &score);
	char s[8];
	char n[35];

	tempname = fopen("tempname.txt", "a");
	leaderboard = fopen("leaderboard.txt", "r");
	Scores = fopen("Scores.txt", "r");
	tempscore = fopen("tempscore.txt", "a");

	int flag = 0;
	char tempn[35];
	int temps;

	for (int i = 0; i < 5; i++)
	{
		fgets(s, 10, Scores);
		fgets(n, 35, leaderboard);

		int a = atoi(s);
		if (score < a)
		{
			char b[8];
			itoa(a, b, 10);
			fprintf(tempname, n);
			// fprintf(tempname, "\n");
			fprintf(tempscore, b);
			fprintf(tempscore, "\n");
		}
		else if (flag != 1)
		{
			char b[8];
			itoa(score, b, 10);
			fprintf(tempname, name);
			fprintf(tempname, "\n");
			fprintf(tempscore, b);
			fprintf(tempscore, "\n");
			flag = 1;

			strcpy(tempn, n);
			temps = a;
		}
		else if (flag == 1 || flag == 2)
		{
			char b[8];
			itoa(temps, b, 10);
			fprintf(tempname, tempn);
			// fprintf(tempname, "\n");
			fprintf(tempscore, b);
			fprintf(tempscore, "\n");
			strcpy(tempn, n);
			temps = a;
			flag == 2;
		}
	}
	if (flag == 2)
	{
		char b[8];
		itoa(temps, b, 10);
		fprintf(tempname, tempn);
		fprintf(tempname, "\n");
		fprintf(tempscore, b);
		fprintf(tempscore, "\n");
	}

	fclose(leaderboard);
	fclose(Scores);
	fclose(tempname);
	fclose(tempscore);

	remove("leaderboard.txt");
	remove("Scores.txt");
	rename("tempscore.txt", "Scores.txt");
	rename("tempname.txt", "leaderboard.txt");
	return;
}
void make_true(int m, int n, object ball[6][7], int *a, int *b, int *c)
{
	for (int r = m; r < 6; r++)
	{
		if (ball[r][n].e == false)
		{
			ball[r][n].e = true;
			*a = r;
			*b = n;
			if (!d)
			{
				ball[r][n].yellow = true;
				ball[r][n].red = false;
				d = true;
				*c = 1;
				count1--;
				itoa(count1, count_s1, 10);
			}
			else if (d)
			{
				ball[r][n].yellow = false;
				ball[r][n].red = true;
				d = false;
				*c = 2;
				count2--;
				itoa(count2, count_s2, 10);
			}
			return;
		}
	}
}

void iDraw()
{
	// place your drawing codes here

	if (game_state == 0)
	{
		iClear();
		iShowBMP(0, 0, bt[0]); // Backgroud;
		iShowBMP(0, 0, bt[6]);
		iShowBMP(900 * m_w, 0 * m_h, im[0]);  // menu minion;
		iShowBMP(270 * m_w, 80 * m_h, bt[3]); // Leaderboard button;
		iShowBMP(600 * m_w, 40 * m_h, bt[4]); // Instruction button;
		iShowBMP(70 * m_w, 150 * m_h, bt[2]); // Get Started button;
		if (w && music)
		{
			iShowBMP(1080 * m_w, 530 * m_h, bt[5]);
		}
		else
		{
			iShowBMP(1080 * m_w, 530 * m_h, bt[8]);
		}									   // Sound button;
		iShowBMP(120 * m_w, 480 * m_h, bt[1]); // Game logo;*/
	}

	else if (game_state == 1) // Get Started (main game)
	{
		iClear();
		iShowBMP(0 * m_w, 0 * m_h, bt[0]); // Backgroud;
		iShowBMP(1320, 300, bt[10]);	   // pause button;
		iShowBMP(1300, 0, bt[9]);		   // Back button;

		if (w && music)
		{
			iShowBMP(1080 * m_w, 530 * m_h, bt[5]);
		}
		else
		{ // Sound
			iShowBMP(1080 * m_w, 530 * m_h, bt[8]);
		}
		iShowBMP(150, 570, bt[1]); // Game logo;
		iShowBMP(450, 0, bt[7]);   // Board;
		if (!d && v)			   // yellow
		{
			iShowBMP(0, 0, bt[14]);
		}
		else if (d && v) // red
		{
			iShowBMP(0, 0, bt[15]);
		}
		iSetColor(0, 0, 0);
		iShowBMP(20, 200, im[14]);
		iText(75, 230, count_s1, GLUT_BITMAP_TIMES_ROMAN_24); // player 1 move left;
		iText(220, 230, count_s2, GLUT_BITMAP_TIMES_ROMAN_24);

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{

				if (ball[i][j].e)
				{

					if (ball[i][j].yellow)
					{

						iSetColor(235, 228, 27);

						iFilledCircle(ball[i][j].x, ball[i][j].y, 34, 100);

						ball[i][j].mark = true;
						ball[i][j].red = false;
					}
					else if (ball[i][j].red)
					{
						iSetColor(247, 44, 44);

						iFilledCircle(ball[i][j].x, ball[i][j].y, 34, 100);
						ball[i][j].mark = true;
						ball[i][j].yellow = false;
					}
					else if (ball[i][j].white)
					{
						iSetColor(255, 255, 255);

						iFilledCircle(ball[i][j].x, ball[i][j].y, 34, 100);
					}
				}
			}
		}
		if (e && z == 1)
		{
			// Sleep(2000);
			game_state = 5;
			e = false;
			l = true;
			score = 300 + (count1 * 10);
			printf("WINNER!!!\n");
			printf("%s\n", name1);
			printf("%d\n", score);
			leaderboard2(name1);
			itoa(score, score_s, 10);
		}
		else if (f && z == 2)
		{
			// Sleep(2000);
			game_state = 6;
			f = false;
			l = true;
			score = 300 + (count2 * 10);
			printf("WINNER!!!\n");
			printf("%s\n", name2);
			printf("%d\n", score);
			leaderboard2(name2);
			itoa(score, score_s, 10);
		}
		if (count1 == 0 && count2 == 0)
		{
			if (h)
			{
				g = true;
				game_state = 8;
				h = false;
			}
		}
	}

	else if (game_state == 2)
	{ // leader Board;
		iClear();
		iShowBMP(0 * m_w, 0 * m_h, bt[0]);
		iShowBMP(1000, 0, im[1]);

		iSetColor(255, 255, 255);
		iText(170, 680, player_name, GLUT_BITMAP_TIMES_ROMAN_24);
		iText(760, 680, player_score, GLUT_BITMAP_TIMES_ROMAN_24);

		iText(80, 600, pos[0], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 600, name_p[0], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 600, " ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(780, 600, score_p[0], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(800, 600, "\n", GLUT_BITMAP_TIMES_ROMAN_24);

		iText(80, 500, pos[1], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 500, name_p[1], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 500, " ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(780, 500, score_p[1], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(800, 500, "\n", GLUT_BITMAP_TIMES_ROMAN_24);

		iText(80, 400, pos[2], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 400, name_p[2], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 400, " ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(780, 400, score_p[2], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(800, 400, "\n", GLUT_BITMAP_TIMES_ROMAN_24);

		iText(80, 300, pos[3], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 300, name_p[3], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 300, " ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(780, 300, score_p[3], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(800, 300, "\n", GLUT_BITMAP_TIMES_ROMAN_24);

		iText(80, 200, pos[4], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(200, 200, name_p[4], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(700, 200, " ", GLUT_BITMAP_TIMES_ROMAN_24);
		iText(780, 200, score_p[4], GLUT_BITMAP_TIMES_ROMAN_24);
		iText(800, 200, "\n", GLUT_BITMAP_TIMES_ROMAN_24);

		// iShowBMP(1000, 0, im[5]);
		if (w && music)
		{
			iShowBMP(1080 * m_w, 530 * m_h, bt[5]);
		}
		else
		{ // Sound
			iShowBMP(1080 * m_w, 530 * m_h, bt[8]);
		}
		iShowBMP(10, 10, bt[13]); // back button
	}
	else if (game_state == 3)
	{ // Instruction
		iClear();

		iShowBMP(0 * m_w, 0 * m_h, bt[0]);

		iShowBMP(0, 0, im[10]);
		iShowBMP(1400, 30, bt[12]);

		if (w && music)
		{
			iShowBMP(1082 * m_w, 530 * m_h, bt[5]);
		}
		else
		{ // Sound
			iShowBMP(1082 * m_w, 530 * m_h, bt[8]);
		}
	}

	else if (game_state == 4) // paused state;
	{
		iClear();
		iShowBMP(0 * m_w, 0 * m_h, bt[0]); // background;
		if (w && music)
		{
			iShowBMP(1080 * m_w, 530 * m_h, bt[5]);
		}
		else
		{ // Sound
			iShowBMP(1080 * m_w, 530 * m_h, bt[8]);
		}
		iShowBMP(150, 560, bt[1]); // Game logo;
		iShowBMP(400, 40, bt[11]); // pause option button(when pause button is pressed);
	}
	else if (game_state == 5)
	{ // yellow wins.{

		// if(e){

		// Sleep(3000);
		// e = false;
		// }
		if (l)
		{
			Sleep(2000);
			l = false;
			if (music)
			{
				PlaySound("music\\win.wav", NULL, SND_ASYNC);
			}
		}
		iClear();
		iShowBMP(0 * m_w, 0 * m_h, bt[0]); // background;
		iShowBMP(0, 0, im[2]);			   // win minion
		iShowBMP(380, 330, im[4]);		   // player 1 win logo
		iShowBMP(1100, 210, im[5]);		   // replay;
		iShowBMP(1100, 120, im[6]);		   // leaderboard;
		iShowBMP(1100, 30, im[7]);		   // home;
		iShowBMP(1150, 300, im[12]);	   // view board;
		iShowBMP(570, 70, im[13]);		   // score view
		iSetColor(0, 0, 0);
		iText(690, 100, score_s, GLUT_BITMAP_TIMES_ROMAN_24);
		if (w && music)
		{
			iShowBMP(1080 * m_w, 530 * m_h, bt[5]);
		}
		else
		{ // Sound
			iShowBMP(1080 * m_w, 530 * m_h, bt[8]);
		}
	}
	else if (game_state == 6)
	{ // red wins.
		if (l)
		{
			Sleep(2000);
			l = false;
			if (music)
			{
				PlaySound("music\\win.wav", NULL, SND_ASYNC);
			}
		}
		iClear();
		iShowBMP(0 * m_w, 0 * m_h, bt[0]); // background;
		iShowBMP(0, 0, im[2]);
		iShowBMP(380, 330, im[8]);
		iShowBMP(1100, 210, im[5]);
		iShowBMP(1100, 120, im[6]);
		iShowBMP(1100, 30, im[7]);
		iShowBMP(1150, 300, im[12]);
		iShowBMP(570, 70, im[13]); // score view
		iSetColor(0, 0, 0);
		iText(690, 100, score_s, GLUT_BITMAP_TIMES_ROMAN_24);

		if (w && music)
		{
			iShowBMP(1080 * m_w, 530 * m_h, bt[5]);
		}
		else
		{ // Sound
			iShowBMP(1080 * m_w, 530 * m_h, bt[8]);
		}
	}
	else if (game_state == 7) // player name entry.
	{
		iClear();
		iShowBMP(0 * m_w, 0 * m_h, bt[0]);
		iShowBMP(10, 500, bt[14]);	// player 1
		iShowBMP(10, 350, bt[15]);	// player 2
		iShowBMP(400, 500, bt[17]); // name template

		iShowBMP(400, 350, bt[17]);
		iShowBMP(490, 200, im[11]);
		iSetColor(0, 0, 0);
		if (mode && mode3 == 0)
		{
			iText(450, 540, name, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if (mode3 == 1)
		{
			iText(450, 540, name1, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		if (mode && mode4 == 0)
		{
			iText(450, 390, name_t, GLUT_BITMAP_TIMES_ROMAN_24);
		}
		else if (mode4 == 1)
		{
			iText(450, 390, name2, GLUT_BITMAP_TIMES_ROMAN_24);
		}

		iShowBMP(10, 10, bt[13]);	// back button
		iShowBMP(1280, 10, bt[16]); // next button
		if (w && music)
		{
			iShowBMP(1080 * m_w, 530 * m_h, bt[5]);
		}
		else
		{ // Sound
			iShowBMP(1080 * m_w, 530 * m_h, bt[8]);
		}
	}
	else if (game_state == 8)
	{
		if (g)
		{
			Sleep(2000);
			g = false;
			if (music)
			{
				PlaySound("music\\win.wav", NULL, SND_ASYNC);
			}
		}
		iClear();
		iShowBMP(0 * m_w, 0 * m_h, bt[0]); // background;
		if (w && music)
		{
			iShowBMP(1080 * m_w, 530 * m_h, bt[5]);
		}
		else
		{ // Sound
			iShowBMP(1080 * m_w, 530 * m_h, bt[8]);
		}
		iShowBMP(400, 100, im[9]);	 // draw logo
		iShowBMP(0, 0, im[3]);		 // draw minion
		iShowBMP(1100, 210, im[5]);	 // replay;
		iShowBMP(1100, 120, im[6]);	 // leaderboard;
		iShowBMP(1100, 30, im[7]);	 // home;
		iShowBMP(1150, 300, im[12]); // view board;
	}
	/*else if(game_state >= 1){
		iClear();
	iShowBMP(0*m_w,0*m_h,bt[0]);
	}*/

	/*
		function iMouseMove() is called when the user presses and drags the mouse.
		(mx, my) is the position where the mouse pointer is.
		*/
}
void iMouseMove(int mx, int my)
{
	// printf("x = %d, y= %d\n",mx,my);
	// place your codes here*/

	// function iMouse() is called when the user presses/releases the mouse.
	//(mx, my) is the position where the mouse pointer is.
}
void iMouse(int button, int state, int mx, int my)
{
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
		/*//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		x += 10;
		y += 10;*/
		if (game_state == 0)
		{
			if (mx >= 90 * m_w && mx <= 290 * m_w && my >= 200 * m_h && my <= 250 * m_h)
			{
				game_state = 7;
				itoa(count1, count_s1, 10);
				itoa(count2, count_s2, 10);
				// if (music && w)
				// {
				// 	PlaySound("music\\game.wav", NULL, SND_LOOP | SND_ASYNC); // Get stared;
				// }
				// else
				// {
				// 	PlaySound(0, 0, 0);
				// }
			}
			else if (mx >= 350 * m_w && mx <= 610 * m_w && my >= 150 * m_h && my <= 400 * m_h)
			{
				game_state = 2;
				leader_board(leaderboard, Scores);
				if (music && w)
				{
					PlaySound("music\\leaderboard.wav", NULL, SND_LOOP | SND_ASYNC); // Leader board;
				}
				else
				{
					PlaySound(0, 0, 0);
				}
			}
			else if (mx >= 650 * m_w && mx <= 970 * m_w && my >= 180 * m_h && my <= 270 * m_h)
			{
				game_state = 3;
				if (music && w)
				{
					PlaySound("music\\instruction.wav", NULL, SND_LOOP | SND_ASYNC); // Instructions;
				}
				else
				{
					PlaySound(0, 0, 0);
				}
			}
			else if (mx >= 1390 && mx <= 1490 && my >= 620 && my <= 720)
			{
				// Sound;
				if (music)
				{
					music = false;
					PlaySound(0, 0, 0);
					w = false;
				}
				else
				{
					music = true;
					w = true;
					PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
			else if (mx >= 50 && mx <= 300 && my >= 70 && my <= 120)
			{

				exit(0); // Exit Game;
			}
		}
		else if (game_state == 1)
		{ // main game;
			if (mx >= ball[0][0].x - 34 && mx <= ball[0][0].x + 34 && my >= ball[0][0].y - 34 && my <= ball[5][0].y + 34 && v)
			{
				make_true(0, 0, ball, &a, &b, &c);
				z = check_win(a, b, c, ball);
			}
			else if (mx >= ball[0][1].x - 34 && mx <= ball[0][1].x + 34 && my >= ball[0][1].y - 34 && my <= ball[5][1].y + 34 && v)
			{
				make_true(0, 1, ball, &a, &b, &c);
				z = check_win(a, b, c, ball);
			}
			else if (mx >= ball[0][2].x - 34 && mx <= ball[0][2].x + 34 && my >= ball[0][2].y - 34 && my <= ball[5][2].y + 34 && v)
			{
				make_true(0, 2, ball, &a, &b, &c);
				z = check_win(a, b, c, ball);
			}
			else if (mx >= ball[0][3].x - 34 && mx <= ball[0][3].x + 34 && my >= ball[0][3].y - 34 && my <= ball[5][3].y + 34 && v)
			{
				make_true(0, 3, ball, &a, &b, &c);
				z = check_win(a, b, c, ball);
			}
			else if (mx >= ball[0][4].x - 34 && mx <= ball[0][4].x + 34 && my >= ball[0][4].y - 34 && my <= ball[5][4].y + 34 && v)
			{
				make_true(0, 4, ball, &a, &b, &c);
				z = check_win(a, b, c, ball);
			}
			else if (mx >= ball[0][5].x - 34 && mx <= ball[0][5].x + 34 && my >= ball[0][5].y - 34 && my <= ball[5][5].y + 34 && v)
			{
				make_true(0, 5, ball, &a, &b, &c);
				z = check_win(a, b, c, ball);
			}
			else if (mx >= ball[0][6].x - 34 && mx <= ball[0][6].x + 34 && my >= ball[0][6].y - 34 && my <= ball[5][6].y + 34 && v)
			{
				make_true(0, 6, ball, &a, &b, &c);
				z = check_win(a, b, c, ball);
			}
			else if (mx >= 1350 && mx <= 1470 && my >= 100 && my <= 150)
			{ // back Button;
				make_all_neutral();
				game_state = 0;
				if (music && w)
				{
					PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
			}
			else if (mx >= 1400 && mx <= 1470 && my >= 350 && my <= 420)
			{ // pause button;
				game_state = 4;
				if (music && w)
				{
					PlaySound("music\\pause.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
			}
			else if (mx >= 1390 && mx <= 1490 && my >= 620 && my <= 720)
			{
				// Sound;
				if (music)
				{
					music = false;
					PlaySound(0, 0, 0);
					w = false;
				}
				else
				{
					music = true;
					w = true;
					PlaySound("music\\game.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
			if (z == 1)
			{
				v = false;
				for (int i = 0; i < 6; i++)
				{
					for (int j = 0; j < 7; j++)
					{
						if (ball[i][j].red)
						{
							ball[i][j].white = true;
							ball[i][j].red = false;
						}
					}
				}
			}
			else if (z == 2)
			{
				v = false;
				for (int i = 0; i < 6; i++)
				{
					for (int j = 0; j < 7; j++)
					{
						if (ball[i][j].yellow)
						{
							ball[i][j].white = true;
							ball[i][j].yellow = false;
						}
					}
				}
			}
			if (!v && z == 1)
			{

				// game_state = 5;
				e = true;
			}
			else if (!v && z == 2)
			{
				f = true;
			}
		}
		else if (game_state == 2) // Leader Board;
		{
			if (mx >= 1390 && mx <= 1490 && my >= 620 && my <= 720)
			{
				// Sound;
				if (music)
				{
					music = false;
					PlaySound(0, 0, 0);
					w = false;
				}
				else
				{
					music = true;
					w = true;
					PlaySound("music\\leaderboard.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
			else if (mx >= 10 && mx <= 240 && my >= 10 && my <= 97) // back button
			{
				game_state = 0;
				if (music && w)
				{
					PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
			}
		}
		else if (game_state == 3) // Instructions;
		{
			if (mx >= 1390 && mx <= 1490 && my >= 620 && my <= 720)
			{
				// Sound;
				if (music)
				{
					music = false;
					PlaySound(0, 0, 0);
					w = false;
				}
				else
				{
					music = true;
					w = true;
					PlaySound("music\\instruction.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
			else if (mx >= 1400 && mx <= 1491 && my >= 30 && my <= 61)
			{
				game_state = 0;
				if (music && w)
				{
					PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
			}
		}
		else if (game_state == 4) // pause option;
		{
			if (mx >= 1390 && mx <= 1490 && my >= 620 && my <= 720)
			{
				// Sound;
				if (music)
				{
					music = false;
					PlaySound(0, 0, 0);
					w = false;
				}
				else
				{
					music = true;
					w = true;
					PlaySound("music\\pause.wav", NULL, SND_LOOP | SND_ASYNC);
				}
			}
			else if (mx >= 570 && mx <= 920 && my >= 130 && my <= 210) // Resume button;
			{
				game_state = 1;
				if (music && w)
				{
					PlaySound("music\\game.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
			}
			else if (mx >= 560 && mx <= 666 && my >= 240 && my <= 350) // Restart button;
			{
				game_state = 1;
				if (music && w)
				{
					PlaySound("music\\game.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
				make_all_neutral();
			}
			else if (mx >= 690 && mx <= 786 && my >= 240 && my <= 350) // Home button;
			{
				game_state = 0;
				if (music && w)
				{
					PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
				make_all_neutral();
			}
		}
		else if (game_state == 5) // player 1 wins
		{
			if (mx >= 1390 && mx <= 1490 && my >= 620 && my <= 720)
			{
				// Sound;
				if (music)
				{
					music = false;
					PlaySound(0, 0, 0);
					w = false;
				}
				else
				{
					music = true;
					w = true;
					PlaySound("music\\win.wav", NULL, SND_ASYNC);
				}
			}
			else if (mx >= 1100 && mx <= 1470 && my >= 210 && my <= 290) // REPLAY button
			{
				game_state = 1;
				if (music && w)
				{
					PlaySound("music\\game.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
				make_all_neutral();
			}
			else if (mx >= 1100 && mx <= 1470 && my >= 120 && my <= 200) // Leaderboard button
			{
				game_state = 2;
				if (music && w)
				{
					PlaySound("music\\leaderboard.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
				leader_board(leaderboard, Scores);
				make_all_neutral();
			}
			else if (mx >= 1100 && mx <= 1470 && my >= 30 && my <= 110) // Home buutton
			{
				game_state = 0;
				if (music && w)
				{
					PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
				make_all_neutral();
			}
			else if (mx >= 1150 && mx <= 1421 && my >= 300 && my <= 370) // view board;
			{
				game_state = 1;
				if (music && w)
				{
					PlaySound("music\\game.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
			}
		}
		else if (game_state == 6) // player 2 wins.
		{
			if (mx >= 1390 && mx <= 1490 && my >= 620 && my <= 720)
			{
				// Sound;
				if (music)
				{
					music = false;
					PlaySound(0, 0, 0);
					w = false;
				}
				else
				{
					music = true;
					w = true;
					PlaySound("music\\win.wav", NULL, SND_ASYNC);
				}
			}
			else if (mx >= 1150 && mx <= 1421 && my >= 300 && my <= 370) // view board
			{
				game_state = 1;
				if (music && w)
				{
					PlaySound("music\\game.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
			}
			else if (mx >= 1100 && mx <= 1470 && my >= 120 && my <= 200) // Leaderboard button
			{
				game_state = 2;
				if (music && w)
				{
					PlaySound("music\\leaderboard.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
				leader_board(leaderboard, Scores);
				make_all_neutral();
			}
			else if (mx >= 1100 && mx <= 1470 && my >= 30 && my <= 110) // Home buutton
			{
				game_state = 0;
				if (music && w)
				{
					PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
				leader_board(leaderboard, Scores);
				make_all_neutral();
			}
			else if (mx >= 1100 && mx <= 1470 && my >= 210 && my <= 290) // REPLAY button
			{
				game_state = 1;
				if (music && w)
				{
					PlaySound("music\\game.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
				make_all_neutral();
			}
		}
		else if (game_state == 7) // name entry.
		{
			if (mx >= 400 && mx <= 1068 && my >= 500 && my <= 610) // player name 1
			{
				mode = 1;
				mode1 = 1;
				mode3 = 0;
			}
			else if (mx >= 400 && mx <= 1068 && my >= 350 && my <= 460) // player name 2
			{
				mode = 1;
				mode2 = 1;
				mode4 = 0;
			}
			else if (mx >= 10 && mx <= 240 && my >= 10 && my <= 97) // back button
			{
				game_state = 0;
			}
			else if (mx >= 1280 && mx <= 1510 && my >= 10 && my <= 97) // next
			{
				game_state = 1;
				if (music && w)
				{
					PlaySound("music\\game.wav", NULL, SND_LOOP | SND_ASYNC); // Get stared;
				}
				else
				{
					PlaySound(0, 0, 0);
				}
			}
			else if (mx >= 1390 && mx <= 1490 && my >= 620 && my <= 720)
			{
				// Sound;
				if (music)
				{
					music = false;
					PlaySound(0, 0, 0);
					w = false;
				}
				else
				{
					music = true;
					w = true;
					PlaySound("music\\menu.wav", NULL, SND_ASYNC);
				}
			}
		}
		else if (game_state == 8) // game draw
		{
			if (mx >= 1390 && mx <= 1490 && my >= 620 && my <= 720)
			{
				// Sound;
				if (music)
				{
					music = false;
					PlaySound(0, 0, 0);
					w = false;
				}
				else
				{
					music = true;
					w = true;
					PlaySound("music\\win.wav", NULL, SND_ASYNC);
				}
			}
			else if (mx >= 1100 && mx <= 1470 && my >= 210 && my <= 290) // REPLAY button
			{
				game_state = 1;
				if (music && w)
				{
					PlaySound("music\\game.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
				make_all_neutral();
			}
			else if (mx >= 1100 && mx <= 1470 && my >= 120 && my <= 200) // Leaderboard button
			{
				game_state = 2;
				if (music && w)
				{
					PlaySound("music\\leaderboard.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
				leader_board(leaderboard, Scores);
				make_all_neutral();
			}
			else if (mx >= 1100 && mx <= 1470 && my >= 30 && my <= 110) // Home buutton
			{
				game_state = 0;
				if (music && w)
				{
					PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
				make_all_neutral();
			}
			else if (mx >= 1150 && mx <= 1421 && my >= 300 && my <= 370) // view board;
			{
				game_state = 1;
				if (music && w)
				{
					PlaySound("music\\game.wav", NULL, SND_LOOP | SND_ASYNC);
				}
				else
				{
					PlaySound(0, 0, 0);
				}
			}
		}
	}

	if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
	{
		/*//place your codes here
		x -= 10;
		y -= 10;*/
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{
	int z;

	if (mode == 0 && key == 'q')
	{
		game_state--;
		if (game_state == 1)
		{
			game_state--;
		}
		else
		{
			game_state = 0;
		}
		if (game_state == 0)
		{
			if (music && w)
			{
				PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else
			{
				PlaySound(0, 0, 0);
			}
		}
		else if (game_state == 1)
		{
			if (music && w)
			{
				PlaySound("music\\game.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else
			{
				PlaySound(0, 0, 0);
			}
		}
		else if (game_state == 2)
		{
			if (music && w)
			{
				PlaySound("music\\leaderboard.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else
			{
				PlaySound(0, 0, 0);
			}
		}
		else if (game_state == 3)
		{
			if (music && w)
			{
				PlaySound("music\\instruction.wav", NULL, SND_LOOP | SND_ASYNC);
			}
			else
			{
				PlaySound(0, 0, 0);
			}
		}
		// else if (game_state == 3)
		// {
		// 	if (music && w)
		// 	{
		// 		PlaySound("music\\instruction.wav", NULL, SND_LOOP | SND_ASYNC);
		// 	}
		// 	else
		// 	{
		// 		PlaySound(0, 0, 0);
		// 	}
		// }
		// else if (game_state == 3)
		// {
		// 	if (music && w)
		// 	{
		// 		PlaySound("music\\instruction.wav", NULL, SND_LOOP | SND_ASYNC);
		// 	}
		// 	else
		// 	{
		// 		PlaySound(0, 0, 0);
		// 	}
		// }

		make_all_neutral();
	}
	else if (mode)
	{
		if (key == '\r')
		{
			mode = 0;
			if (mode1)
			{
				mode1 = 0;
				mode3 = 1;
				strcpy(name1, name);
				printf("%s\n", name1);
				for (z = 0; z < len; z++)
				{
					name[z] = 0;
				}
				len = 0;
			}
			else if (mode2)
			{
				mode2 = 0;
				mode4 = 1;
				strcpy(name2, name_t);
				printf("%s\n", name2);
				for (z = 0; z < len; z++)
				{
					name[z] = 0;
				}
				len = 0;
			}
		}
		else if (key != '\r')
		{
			if (mode1)
			{
				if (key != '\b')
				{
					name[len] = key;
					len++;
					name[len] = 0;
				}
				else if (key == '\b')
				{
					if (len <= 0)
					{
						len = 0;
					}
					else
					{
						len--;
					}
					name[len] = 0;
				}
			}
			else if (mode2)
			{
				if (key != '\b')
				{
					name_t[len] = key;
					len++;
					name_t[len] = 0;
				}
				else if (key == '\b')
				{
					if (len <= 0)
					{
						len = 0;
					}
					else
					{
						len--;
					}
					name_t[len] = 0;
				}
			}
		}
	}

	// place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		// exit(0);
	}
	// place your codes for other keys here
}

int main()
{
	// place your own initialization codes here.
	if (music)
	{
		PlaySound("music\\menu.wav", NULL, SND_LOOP | SND_ASYNC);
	}

	int u = 499 - 83;
	int v = 50 - 83;
	for (int i = 0; i < 6; i++)
	{

		for (int j = 0; j < 7; j++)
		{
			u += 83;
			ball[i][j].x += u;
			ball[i][j].e = false;
			ball[i][j].yellow = false;
			ball[i][j].red = false;
			ball[i][j].mark = false;
			ball[i][j].white = false;
		}
		u = 499 - 83;
	}
	for (int i = 0; i < 7; i++)
	{

		for (int j = 0; j < 6; j++)
		{
			v += 83;
			ball[j][i].y += v;
		}
		v = 50 - 83;
	}
	iInitialize(screenwidth * m_w, screenhight * m_h, "CONNECT_4");

	return 0;
}
