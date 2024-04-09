#include <stdio.h>
#include <Windows.h>

#include "Init.h"
#include "game.h"
#include "system.h"

void InitGame(int save_num)
{
	system("cls");
	menu(s_saves[save_num].line);
}