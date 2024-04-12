#pragma warning(disable:4996)

#include <stdio.h>
#include <stdbool.h>
#include <Windows.h>

#include "Init.h"
#include "cursor.h"
#include "system.h"

enum Option { OPTION1, OPTION2, OPTION3, EXIT };

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

		for (int i = 1; i < 5; i++) {
			sprintf(save_filename, "���̺� %02d", (page * 4) + i);

			MoveCursor(x - 2, y + i * 2 - 2);
			if (i == 1) {
				MoveCursor(x - 2, y);
				printf("> %s : %d��° ��", save_filename, s_saves[(page * 4) + i].line);
			}
			else {
				MoveCursor(x, y + i * 2 - 2);
				printf("%s : %d��° ��", save_filename, s_saves[(page * 4) + i].line);
			}

			MoveCursor(x, y + 8);
			printf("���� ������");

			MoveCursor(x, y + 10);
			printf("���� ������");

			MoveCursor(x, y + 12);
			printf("���� �޴�");

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
					s_saves[(page * 4 + y + 1)].line = line;
					sprintf(save_filename, "save\\save%02d.bin", (page * 4) + y + 1);

					FILE* sb = fopen(save_filename, "wb");

					fwrite(s_saves, sizeof(save_t), NUM_MAX_SAVES, sb);

					printf("���̺� ���� %02d���� �����Ͽ����ϴ�. \n", (page * 4 + y + 1));
					system("pause");

					fclose(sb);
					return;
				}

				else if (y == 4) {
					page++;
					if (page == 5) {
						page--;

						printf("������ �������Դϴ�. \n");
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

int Load()
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

		for (int i = 1; i < 5; i++) {
			sprintf(save_filename, "���̺� %02d", (page * 4) + i);

			MoveCursor(x - 2, y + i * 2 - 2);
			if (i == 1) {
				MoveCursor(x - 2, y);
				printf("> %s : %d��° ��", save_filename, s_saves[(page * 4) + i].line);
			}
			else {
				MoveCursor(x, y + i * 2 - 2);
				printf("%s : %d��° ��", save_filename, s_saves[(page * 4) + i].line);
			}

			MoveCursor(x, y + 8);
			printf("���� ������");

			MoveCursor(x, y + 10);
			printf("���� ������");

			MoveCursor(x, y + 12);
			printf("���� �޴�");

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
					printf("���� ���� %d���� �ҷ��ɴϴ�. \n", (page * 4 + y + 1));
					system("pause");

					return (page * 4 + y + 1);
				}

				else if (y == 4) {
					page++;
					if (page == 5) {
						page--;

						printf("������ �������Դϴ�. \n");
						system("pause");
					}
				}

				else if (y == 5) {
					page--;

					if (page == -1) {
						return -1;
					}
				}

				else if (y == 6) {
					return -1;
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
		printf("> ������ �ʱ�ȭ");

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
					char save_filename[16];

					for (int i = 1; i <= NUM_MAX_SAVES; i++) {
						sprintf(save_filename, "save\\save%02d.bin", i);
						remove(save_filename);

						FILE* sb = fopen(save_filename, "w+b");

						fread(s_saves, sizeof(save_t), NUM_MAX_SAVES, sb);

						fclose(sb);
					}

					printf("������ �ʱ�ȭ�� �����Ͽ����ϴ�. \n");
					system("pause");
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