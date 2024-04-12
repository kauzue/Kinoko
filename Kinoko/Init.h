#pragma once

#include <stdbool.h>

#define NUM_MAX_SAVES 20
#define NUM_MAX_SAVE_PER_ITEMS 5

typedef struct item {
	int number;
} item_t;

typedef struct save {
	int item_num;
	item_t items[NUM_MAX_SAVE_PER_ITEMS];
	int line;
} save_t;

item_t s_items[NUM_MAX_SAVE_PER_ITEMS];
save_t s_saves[NUM_MAX_SAVES];

bool Init();