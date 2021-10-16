/* ミノづくりシーン */
// ・ミノを作って保存できる(保存されたミノは、設定から出現するしないを変更できる)
// ・ミノづくりを選択すると実際に作るところへ
// ・設定は作るところから飛ぶ

#include <stdio.h>
#include <conio.h>
#include "scene_macro.h"
#include "mino.h"
#include "color.h"

// 操作
void make_operate(Mino& mino, int& sel_x, int& sel_y) {
	if (_kbhit()) {
		int r = _getch();
		switch (r) {
		case 'w':
			sel_y--;
			break;
		case 'a':
			sel_x--;
			break;
		case 's':
			sel_y++;
			break;
		case 'd':
			sel_x++;
			break;
		case ' ':
			mino.paint(sel_x, sel_y);
			break;
		}
		sel_x = (sel_x + mino.w) % mino.w;
		sel_y = (sel_y + mino.h) % mino.h;
	}
}

// 表示
void make_show(Mino mino, int sel_x, int sel_y) {
	system("cls");
	for (int y = 0; y < mino.h; y++) {
		for (int x = 0; x < mino.w; x++) {
			// 色分け
			if (mino.place[y][x])
				color_change(mino);
			else
				color_reset();
			

			// 表示内容
			if (sel_x == x && sel_y == y)
				printf("■");
			else
				printf("□");
		}
		printf("\n");
	}
}

// 流れ
void make_mino(int &status) {
	Mino new_mino;
	int sel_x = 0, sel_y = 0;
	new_mino.init(4, 4, 0);
	while (status == MAKE) {
		make_show(new_mino, sel_x, sel_y);
		make_operate(new_mino, sel_x, sel_y);
	}
	system("cls");
}
