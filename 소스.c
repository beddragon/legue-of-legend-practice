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

int menu;

int q, w, e, r; // �Է� ��

int Q, W, E, R; // ���ߴ� ��

int a, s, d, f; // �޴� ����â

void load(const char* text) // �׸� �ҷ�����
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
	cursorInfo.dwSize = 1; //Ŀ�� ���� (1 ~ 100)
	cursorInfo.bVisible = FALSE; //Ŀ�� Visible TRUE(����) FALSE(����)
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void start() // ����
{
	printf("\n");
	load("start.txt");
	printf("\n�����ϱ�(1)\n���� ����(2)\n");
	
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
		printf("�� ������ ���׿��극���带 �÷��� �ϱ� �� \n���� Ǯ�� ���� �������� ��������ϴ�!\n");
		printf("ȭ�鿡 ���̴� ������� Q,W,E,R�� ���� �����ø� �˴ϴ�!\n");
		printf("������ �� 80�ʰ� ����˴ϴ�!\n");
		printf("\n");
		load("q.txt");
		printf("\n������� Q�Դϴ�");
		printf("\n�ѱ��(1)");
		a:
		scanf_s("%d", &a);
		if (a == 1)
		{
			d:
			system("cls");
			load("w.txt");
			printf("\n������� W�Դϴ�");
			printf("\n�ѱ��(1)\n�ڷΰ���(2)");
			b:
			scanf_s("%d", &s);
			if (s == 1)
			{
				n:
				system("cls");
				load("e.txt");
				printf("\n������� E�Դϴ�");
				printf("\n�ѱ��(1)\n�ڷΰ���(2)");
				s:
				scanf_s("%d", &d);

				if (d == 1)
				{
					
					system("cls");
					load("r.txt");
					printf("\n������� R�Դϴ�");
					printf("\n�����ϱ�(1)\n�ڷΰ���(2)");
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
						printf("ERROR...\n�ٽ� �Է����ֽʽÿ�");
						goto m;
					}
				}
				else if (d == 2)
				{
					
					goto d;
				}
				else
				{
					printf("ERROR...\n�ٽ� �Է����ֽʽÿ�");
					goto s;
				}
			}
			else if (s == 2)
			{
				goto z;
			}
			else
			{
				printf("ERROR...\n�ٽ� �Է����ֽʽÿ�");
				goto b;
			}
			
		}
		else
		{
			printf("ERROR...\n�ٽ� �Է����ֽʽÿ�");
			goto a;
		}
		system("cls");
	}
	else
	{
		printf("ERROR...\n�ٽ� �Է����ֽʽÿ�");
		goto again;
	}

	printf("5���� ����...");
	Sleep(1000);
	system("cls");
	printf("4���� ����...");
	Sleep(1000);
	system("cls");
	printf("3���� ����...");
	Sleep(1000);
	system("cls");
	printf("2���� ����...");
	Sleep(1000);
	system("cls");
	printf("1���� ����...");
	Sleep(1000);
	system("cls");
} 

void gotoxy(int x, int y)

{

	COORD pos = { x,y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

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

		randomtime = rand() % 2000;

		if (random == 0)
		{
			Q++;
			load("q.txt");
			Sleep(1000);
			Q--;
			system("cls");
			Sleep(randomtime);
		}
		else if (random == 1)
		{
			W++;
			load("w.txt");
			Sleep(1000);
			W--;
			system("cls");
			Sleep(randomtime);
		}
		else if (random == 2)
		{
			E++;
			load("e.txt");
			Sleep(1000);
			E--;
			system("cls");
			Sleep(randomtime);
		}
		else if (random == 3)
		{
			R++;
			load("r.txt");
			Sleep(1000);
			R--;
			system("cls");
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
				printf("+1��!");
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
		}
	}
	system("cls");

	if (score < 0)
	{
		printf("%d..? ���̳ʽ�..?");
	}
	else if (score = 0)
	{
		printf("0��? ���� �����ϰ� ������ �Ϸ�����??");
	}
	else if (score < 10)
	{
		printf("�ܿ� %d���̾�? �Ǹ��̴�..", score);
	}
	else if (score < 50)
	{
		printf("�ܿ� %d���̾�? ���� �� �������!", score);
	}
	else if (score < 100)
	{
		printf("%d���̾�! ���� ���ϴµ�?", score);
	}
	else if (score > 100)
	{
		printf("%d��? �̰� �Ǵ±���..", score);
	}
}