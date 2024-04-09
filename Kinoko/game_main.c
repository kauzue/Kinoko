#pragma warning(disable:4996)

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "Init.h"
#include "game.h"
#include "cursor.h"

enum Menu { START, CONTINUE, OPTION, EXIT };
enum Option { OPTION1, OPTION2, OPTION3};

void Continue();
void Option();

void screen()
{
	int key;
	int x, y;

	while (true) {
		key = 0;
		x = 2;
		y = 2;

		system("cls");

		printf("Kinoko - �ͽ��� ���� \n");

		MoveCursor(x - 2, y);
		printf("> ó������");

		MoveCursor(x, y + 2);
		printf("�̾��ϱ�");

		MoveCursor(x, y + 4);
		printf("����");

		MoveCursor(x, y + 6);
		printf("����");

		while (key != 4) {
			key = ControlKey();

			switch (key) {
			case UP: {
				if (y > 2) {
					MoveCursor(x - 2, y);
					printf(" ");
					MoveCursor(x - 2, y -= 2);
					printf(">");
				}
				break;
			}

			case DOWN: {
				if (y < 8) {
					MoveCursor(x - 2, y);
					printf(" ");

					MoveCursor(x - 2, y += 2);
					printf(">");
				}
				break;
			}

			case ENTER: {
				system("cls");

				switch ((y - 2) / 2) {
				case START: {
					InitGame(0);
					break;
				}

				case CONTINUE: {
					Continue();
					break;
				}

				case OPTION: {
					Option();
					break;
				}

				case EXIT: {
					return;
				}
				}
			}
			}
		}
	}
}

void Continue()
{
	char save_filename[16];

	int key;
	int x, y;
	int page = 0;

	while (true) {
		key = 0;
		x = 2;
		y = 2;

		system("cls");

		printf("�̾��ϱ� \n");

		for (int i = 0; i < 5; i++) {
			sprintf(save_filename, "���̺� %02d", (page * 5) + i);

			MoveCursor(x - 2, y + i * 2);
			if (i == 0) {
				MoveCursor(x - 2, y);
				printf("> %s", save_filename);
			}
			else {
				MoveCursor(x, y + i * 2);
				printf("%s", save_filename);
			}
			
			MoveCursor(x, y + 10);
			printf("���� ������");

			MoveCursor(x, y + 12);
			printf("���� ������");

		}

		while (key != 4) {
			key = ControlKey();

			switch (key) {
			case UP: {
				if (y > 2) {
					MoveCursor(x - 2, y);
					printf(" ");
					MoveCursor(x - 2, y -= 2);
					printf(">");
				}
				break;
			}

			case DOWN: {
				if (y < 14) {
					MoveCursor(x - 2, y);
					printf(" ");

					MoveCursor(x - 2, y += 2);
					printf(">");
				}
				break;
			}

			case ENTER: {
				system("cls");

				y = (y - 2) / 2;

				if (y < 5) {
					InitGame(y);
				}

				else if(y == 5){
					page++;
					if (page == 4) {
						page--;

						printf("������ �������Դϴ�. \n");
						system("pause");
					}
				}

				else if (y == 6) {
					page--;

					if (page == -1) {
						return;
					}
				}
				}
			}
		}
	}
}

void Option()
{
	int key;
	int x, y;

	while (true) {
		key = 0;
		x = 2;
		y = 2;

		system("cls");

		printf("���� \n");

		MoveCursor(x - 2, y);
		printf("> ����1");

		MoveCursor(x, y + 2);
		printf("����2");

		MoveCursor(x, y + 4);
		printf("����3");

		MoveCursor(x, y + 6);
		printf("����");

		while (key != 4) {
			key = ControlKey();

			switch (key) {
			case UP: {
				if (y > 2) {
					MoveCursor(x - 2, y);
					printf(" ");
					MoveCursor(x - 2, y -= 2);
					printf(">");
				}
				break;
			}

			case DOWN: {
				if (y < 8) {
					MoveCursor(x - 2, y);
					printf(" ");

					MoveCursor(x - 2, y += 2);
					printf(">");
				}
				break;
			}

			case ENTER: {
				system("cls");

				switch ((y - 2) / 2) {
				case OPTION1: {
					break;
				}

				case OPTION2: {

					break;
				}

				case OPTION3: {
					break;
				}

				case EXIT: {
					return;
				}
				}
			}
			}
		}
	}
}