#include "Init.h"
#include "game_main.h"

int main(void)
{
	if (Init() == false) {
		return 0;
	}
	screen();

	return 0;
}