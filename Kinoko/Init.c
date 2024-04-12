#pragma warning(disable:4996)

#include <stdio.h>
#include <Windows.h>

#include "Init.h"

bool Init()
{

	FILE* st = fopen("story\\story.txt", "r");
	if (st == NULL) {
		puts("스토리 파일이 존재하지 않습니다.");
		system("pause");

		return false;
	}

	char save_filename[16];
	for (int i = 1; i <= NUM_MAX_SAVES; i++) {
		sprintf(save_filename, "save\\save%02d.bin", i);

		FILE* sb = fopen(save_filename, "rb");
		if (sb == NULL) {
			sb = fopen(save_filename, "w+b");
		}

		fread(s_saves, sizeof(save_t), NUM_MAX_SAVES, sb);

		fclose(sb);
	}

	return true;
}