/* êFï™ÇØ */
#include "color_macro.h"
#include "mino.h"

void color_change(Mino mino) {
	switch (mino.color) {
	case RED:
		printf("\033[31m");
		break;
	case GREEN:
		printf("\033[32m");
		break;
	case YELLOW:
		printf("\033[33m");
		break;
	case BLUE:
		printf("\033[34m");
		break;
	case MAGENTA:
		printf("\033[35m");
		break;
	case CYAN:
		printf("\033[36m");
		break;
	}
}

void color_reset() {
	printf("\033[m");
}
