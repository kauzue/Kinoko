#pragma warning(disable:4996)

#include <stdio.h>
#include <Windows.h>

#include "Init.h"

void Init()
{
	char save_filename[16];
	for (int i = 0; i <= NUM_MAX_SAVES; i++) {
		sprintf(save_filename, "save%02d.bin", i);

		FILE* sb = fopen(save_filename, "rb");
		if (sb == NULL) {
			sb = fopen(save_filename, "w+b");
		}

		fread(s_saves, sizeof(save_t), NUM_MAX_SAVES, sb);

		fclose(sb);
	}
}