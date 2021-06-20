/* オープニングシーン */
// ・プレイへの遷移
// ・ミノづくり
// ・設定

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "scene_macro.h"

int opening_operate(int sel) {
	if (_kbhit()) {
		int r = _getch();
		switch (r) {
		case 'w':
			sel--;
			break;
		case 's':
			sel++;
			break;
		}
		sel = (sel + 3) % 3;
	}
	return sel;
}

void opening_show(int sel) {
	system("cls");
	printf("===== テト作ってみた =====\n");
	printf("\t%sプレイ\n", (sel == 0) ? "◎" : "  ");
	printf("\t%sミノ作り\n", (sel == 1) ? "◎" : "  ");
	printf("\t%s設定\n", (sel == 2) ? "◎" : "  ");
}

int opening(int status) {
	static int sel = 0;
	while (status == OP) {
		opening_show(sel);
		sel = opening_operate(sel);
	}
	return status;
}
