/* オープニングシーン */
// ・プレイへの遷移
// ・ミノづくり
// ・設定

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "scene_macro.h"
#define ENTER 13

// 操作
int opening_operate(int sel, int *status) {
	if (_kbhit()) {
		int r = _getch();

		//カーソル(◎)の移動
		switch (r) {
		case 'w':
			sel--;
			break;
		case 's':
			sel++;
			break;
		}

		// statusをPLAY, MAKE, SETTINGに
		if (r == ENTER) {
			*status = sel + 1;
		}

		sel = (sel + 4) % 4; //ワープ
	}
	return sel;
}

// 表示
void opening_show(int sel) {
	system("cls");
	printf("===== テト作ってみた =====\n");
	printf("\t%sプレイ\n", (sel == 0) ? "◎" : "  ");
	printf("\t%sミノ作り\n", (sel == 1) ? "◎" : "  ");
	printf("\t%s設定\n", (sel == 2) ? "◎" : "  ");
	printf("\t%s終了\n", (sel == 3) ? "◎" : "  ");

}

// 流れ
int opening(int status) {
	static int sel = 0;
	while (status == OP) {
		opening_show(sel);
		sel = opening_operate(sel, &status);
	}
	sel = 0;
	system("cls");
	return status;
}
