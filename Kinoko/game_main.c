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

		printf("Kinoko - 귀신의 아이 \n");

		MoveCursor(x - 2, y);
		printf("> 처음부터");

		MoveCursor(x, y + 2);
		printf("이어하기");

		MoveCursor(x, y + 4);
		printf("설정");

		MoveCursor(x, y + 6);
		printf("종료");

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

		printf("이어하기 \n");

		for (int i = 0; i < 5; i++) {
			sprintf(save_filename, "세이브 %02d", (page * 5) + i);

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
			printf("다음 페이지");

			MoveCursor(x, y + 12);
			printf("이전 페이지");

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

						printf("마지막 페이지입니다. \n");
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

		printf("설정 \n");

		MoveCursor(x - 2, y);
		printf("> 설정1");

		MoveCursor(x, y + 2);
		printf("설정2");

		MoveCursor(x, y + 4);
		printf("설정3");

		MoveCursor(x, y + 6);
		printf("이전");

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