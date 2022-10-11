#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <mmsystem.h>

#pragma comment(lib, "winmm.lib")

#define SOUND_FILE_NAME "iq.wav"

#define SOUND_FILE_NAM "bmusic.wav"

int score;

int timeout = 1;

int random;

int randomtime;

int randomstop;

int menu;

int N = 1;

int q, w, e, r; // 입력 값

int Q, W, E, R; // 맞추는 값

int a, s, d, f; // 메뉴 설명창

void load(const char* text) // 그림 불러오기
{
	FILE* file = fopen(text, "r");

	char buffer[10000] = { 0, };

	fread(buffer, 1, 10000, file);

	printf("%s", buffer);

	fclose(file);

} 

void CursorView()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1; //커서 굵기 (1 ~ 100)
	cursorInfo.bVisible = FALSE; //커서 Visible TRUE(보임) FALSE(숨김)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void start() // 시작
{
	printf("\n");
	load("start.txt");
	printf("\n시작하기(1)\n설명 보기(2)\n");
	
	again:

	scanf_s("%d", &menu);

	if (menu == 1)
	{
		system("cls");
		printf("LOADING....");
		Sleep(1000);
		system("cls");
	}
	else if (menu == 2)
	{
		z:
		system("cls");
		printf("이 게임은 리그오브레전드를 플레이 하기 전 \n손을 풀기 위한 목적으로 만들었습니다!\n");
		printf("화면에 보이는 이즈리얼의 Q,W,E,R을 보고 누르시면 됩니다!\n");
		printf("꾹 누르면 추가 점수가 있습니다!\n");
		printf("게임은 약 80초간 진행됩니다!\n");
		printf("\n");
		load("q.txt");
		printf("\n이즈리얼의 Q입니다");
		printf("\n넘기기(1)");
		a:
		scanf_s("%d", &a);
		if (a == 1)
		{
			d:
			system("cls");
			load("w.txt");
			printf("\n이즈리얼의 W입니다");
			printf("\n넘기기(1)\n뒤로가기(2)");
			b:
			scanf_s("%d", &s);
			if (s == 1)
			{
				n:
				system("cls");
				load("e.txt");
				printf("\n이즈리얼의 E입니다");
				printf("\n넘기기(1)\n뒤로가기(2)");
				s:
				scanf_s("%d", &d);

				if (d == 1)
				{
					
					system("cls");
					load("r.txt");
					printf("\n이즈리얼의 R입니다");
					printf("\n시작하기(1)\n뒤로가기(2)");
					m:
					scanf_s("%d", &f);
					if (f == 1)
					{
						

					}
					else if (f == 2)
					{

						goto n;
					}
					else
					{
						printf("ERROR...\n다시 입력해주십시오");
						goto m;
					}
				}
				else if (d == 2)
				{
					
					goto d;
				}
				else
				{
					printf("ERROR...\n다시 입력해주십시오");
					goto s;
				}
			}
			else if (s == 2)
			{
				goto z;
			}
			else
			{
				printf("ERROR...\n다시 입력해주십시오");
				goto b;
			}
			
		}
		else
		{
			printf("ERROR...\n다시 입력해주십시오");
			goto a;
		}
		system("cls");
	}
	else
	{
		printf("ERROR...\n다시 입력해주십시오");
		goto again;
	}

	printf("5초후 시작...");
	Sleep(1000);
	system("cls");
	printf("4초후 시작...");
	Sleep(1000);
	system("cls");
	printf("3초후 시작...");
	Sleep(1000);
	system("cls");
	printf("2초후 시작...");
	Sleep(1000);
	system("cls");
	printf("1초후 시작...");
	Sleep(1000);
	system("cls");
} 

unsigned _stdcall KEY(void* arg)
{
	while (timeout)
	{

		if (GetAsyncKeyState(0x51))
		{
			q++;
			Sleep(100);
			q--;
		}
		else if (GetAsyncKeyState(0x57))
		{
			w++;
			Sleep(100);
			w--;
		}
		else if (GetAsyncKeyState(0x45))
		{
			e++;
			Sleep(100);
			e--;
		}
		else if (GetAsyncKeyState(0x52))
		{
			r++;
			Sleep(100);
			r--;
		}
	}
}

unsigned _stdcall print_random(void* arg)
{
	srand(time(NULL));

	while (timeout)
	{
		random = rand() % 4;

		randomstop = rand() % (1000 + 1 - 500) + 500;

		randomtime = rand() % 2000;

		if (random == 0)
		{
			N--;
			Q++;
			load("q.txt");
			Sleep(randomstop);
			Q--;
			system("cls");
			N++;
			Sleep(randomtime);
		}
		else if (random == 1)
		{
			N--;
			W++;
			load("w.txt");
			Sleep(randomstop);
			W--;
			system("cls");
			N++;
			Sleep(randomtime);
		}
		else if (random == 2)
		{
			N--;
			E++;
			load("e.txt");
			Sleep(randomstop);
			E--;
			system("cls");
			N++;
			Sleep(randomtime);
		}
		else if (random == 3)
		{
			N--;
			R++;
			load("r.txt");
			Sleep(randomstop);
			R--;
			system("cls");
			N++;
			Sleep(randomtime);

		}
	}
}

unsigned _stdcall gametime(void* arg)
{
	for (int i = 0; i < 79; i++)
	{
		Sleep(1000);
	}
	timeout--;
	PlaySound(NULL, 0, 0);
	system("cls");
}


void main()
{
	CursorView();

	PlaySound(TEXT(SOUND_FILE_NAM), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);

	system("mode con cols=160 lines=40");

	start();
	PlaySound(TEXT(SOUND_FILE_NAME), NULL, SND_FILENAME | SND_ASYNC | SND_LOOP);
	_beginthreadex(NULL, 0, KEY, 0, 0, NULL);
	_beginthreadex(NULL, 0, print_random, 0, 0, NULL);
	_beginthreadex(NULL, 0, gametime, 0, 0, NULL);

	while (timeout)
	{
		if (q == 1)
		{
			if (Q == 1)
			{
				score++;
				Sleep(200);
			}
			else if (W == 1)
			{
				score--;
				Sleep(200);
			}
			else if (E == 1)
			{
				score--;
				Sleep(200);
			}
			else if (R == 1)
			{
				score--;
				Sleep(200);
			}
			else if (N == 1)
			{
				score--;
				Sleep(200);
			}
		}
		if (w == 1)
		{
			if (Q == 1)
			{
				score--;
				Sleep(200);
			}
			else if (W == 1)
			{
				score++;
				Sleep(200);
			}
			else if (E == 1)
			{
				score--;
				Sleep(200);
			}
			else if (R == 1)
			{
				score--;
				Sleep(200);
			}
			else if (N == 1)
			{
				score--;
				Sleep(200);
			}
		}
		if (e == 1)
		{
			if (Q == 1)
			{
				score--;
				Sleep(200);
			}
			else if (W == 1)
			{
				score--;
				Sleep(200);
			}
			else if (E == 1)
			{
				score++;
				Sleep(200);
			}
			else if (R == 1)
			{
				score--;
				Sleep(200);
			}
			else if (N == 1)
			{
				score--;
				Sleep(200);
			}
		}
		if (r == 1)
		{
			if (Q == 1)
			{
				score--;
				Sleep(200);
			}
			else if (W == 1)
			{
				score--;
				Sleep(200);
			}
			else if (E == 1)
			{
				score--;
				Sleep(200);
			}
			else if (R == 1)
			{
				score++;
				Sleep(200);
			}
			else if (N == 1)
			{
				score--;
				Sleep(200);
			}
		}
	}
	system("cls");
	
	printf("당신의 점수는 %d점 입니다!", score);
}