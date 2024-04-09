#pragma warning(disable:4996)

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

#include "Init.h"
#include "cursor.h"
#include "system.h"

enum Menu { SAVE, LOAD, OPTION, NEXT, LOG, EXIT };

void Story(int);
void Save(int);
void Log(int);

void menu(int line)
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
		printf("�α�");

		MoveCursor(x, y + 10);
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
				if (y < 12) {
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
					break;
				}

				case OPTION: {
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

				case EXIT: {
					exit(0);
				}
				}
			}
			}
		}
	}
}

void Story(int line)
{
	char story[MAX_MSG_LEN] = "";

	FILE* st = fopen("story\\story.txt", "r");

	for (line; line >= 0; line--) {
		fgets(story, MAX_MSG_LEN, st);
	}

	printf("%s", story);

	fclose(st);
	return;
}

void Save(int line)
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

		printf("���� \n");

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
					save_t save;

					s_saves[(page * 5 + y)].line = line;
					sprintf(save_filename, "save\\save%02d.bin", (page * 5) + y);

					FILE* sb = fopen(save_filename, "wb");

					fwrite(s_saves, sizeof(save_t), NUM_MAX_SAVES, sb);

					printf("���̺� ���� %02d���� �����Ͽ����ϴ�. \n", (page * 5 + y));
					system("pause");

					fclose(sb);
					return;
				}

				else if (y == 5) {
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

void Log(int line) {
	char story[MAX_MSG_LEN] = "";
	int i = line - MAX_LOG;
	if (line < MAX_LOG) {
		i = 0;
	}

	printf("�α� \n \n");

	FILE* st = fopen("story\\story.txt", "r");

	for (i; i <= line; i++) {
		fgets(story, MAX_MSG_LEN, st);
		printf("%s", story);
	}

	printf("\n");
	system("pause");

	fclose(st);
	return;
}