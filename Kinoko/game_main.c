#pragma warning(disable:4996)

#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "Init.h"
#include "game.h"
#include "system.h"
#include "cursor.h"

enum Menu { START, CONTINUE, OPTION, EXIT };

void Continue();

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
					int load;

					load = menu(0);

					while (true) {
						if (load == -1) {
							break;
						}

						else {
							load = menu(s_saves[load].line);
						}
					}

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

		for (int i = 1; i < 5; i++) {
			sprintf(save_filename, "세이브 %02d", (page * 4) + i);

			MoveCursor(x - 2, y + (i - 1) * 2);
			if (i == 1) {
				MoveCursor(x - 2, y);
				printf("> %s : %d번째 줄", save_filename, s_saves[(page * 4) + i].line);
			}
			else {
				MoveCursor(x, y + (i - 1) * 2);
				printf("%s : %d번째 줄", save_filename, s_saves[(page * 4) + i].line);
			}
			
			MoveCursor(x, y + 8);
			printf("다음 페이지");

			MoveCursor(x, y + 10);
			printf("이전 페이지");

			MoveCursor(x, y + 12);
			printf("이전 메뉴");

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

				if (y < 4) {
					int load = (page * 4) + y + 1;

					while (true) {
						load = menu(s_saves[load].line);
						if (load == -1) {
							return;
						}
					}
				}

				else if(y == 4){
					page++;
					if (page == 5) {
						page--;

						printf("마지막 페이지입니다. \n");
						system("pause");
					}
				}

				else if (y == 5) {
					page--;

					if (page == -1) {
						return;
					}
				}

				else if (y == 6) {
					return;
				}
				}
			}
		}
	}
}