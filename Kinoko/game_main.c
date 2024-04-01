#include <stdio.h>
#include <stdbool.h>
#include <windows.h>

#include "Init.h"
#include "cursor.h"

enum Menu { START, CONTINUE, OPTION, EXIT };
enum Option { OPTION1, OPTION2, OPTION3};

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
					break;
				}

				case CONTINUE: {

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