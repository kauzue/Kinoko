#include <stdio.h>
#include <Windows.h>

#include "Init.h"
#include "game.h"
#include "cursor.h"
#include "system.h"

enum Menu { SAVE, LOAD, OPTION, BACK, NEXT, LOG, BACK_MENU, EXIT };

int menu(int line)
{
	int key;
	int x, y;

	while (true) {
		system("cls");

		key = 0;
		x = 2;
		y = 2;

		Story(line);

		MoveCursor(x - 2, y);
		printf("> ����");

		MoveCursor(x, y + 2);
		printf("�ҷ�����");

		MoveCursor(x, y + 4);
		printf("����");

		MoveCursor(x, y + 6);
		printf("����");

		MoveCursor(x, y + 8);
		printf("����");

		MoveCursor(x, y + 10);
		printf("�α�");

		MoveCursor(x, y + 12);
		printf("���� �޴�");

		MoveCursor(x, y + 14);
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
				if (y < 16) {
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
				case SAVE: {
					Save(line);
					break;
				}

				case LOAD: {
					int load = Load();
					if (load == -1) {
						break;
					}
					else {
						return load;
					}
				}

				case OPTION: {
					Option();
					break;
				}

				case BACK: {
					line--;
					if (line == -1) {
						printf("ù �����Դϴ�. \n");
						system("pause");

						line++;
					}
					break;
				}
				case NEXT: {
					line++;
					break;
				}

				case LOG: {
					Log(line);
					break;
				}

				case BACK_MENU: {
					return -1;
				}

				case EXIT: {
					exit(0);
				}
				}
			}
			}
		}
	}
}