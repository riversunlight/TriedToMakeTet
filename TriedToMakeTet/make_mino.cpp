/* ミノづくりシーン */
// ・ミノを作って保存できる(保存されたミノは、設定から出現するしないを変更できる)
// ・ミノづくりを選択すると実際に作るところへ
// ・設定は作るところから飛ぶ

#include <stdio.h>
#include <conio.h>
#include "scene_macro.h"
#include "mino.h"
#include "color.h"
#include "m_set.h"
#include "m_save.h"
#include "m_quit.h"

// 座標リセット
inline void sel_reset(int& sel_x, int& sel_y) {
	sel_x = 0; sel_y = 0;
}

// 操作
void make_operate(Mino& mino, int& sel_x, int& sel_y, bool& no_change,  int& mode) {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w': // 移動(上)
			sel_y--;
			break;
		case 'a': // 移動(左)
			sel_x--;
			break;
		case 's': // 移動(下)
			sel_y++;
			break;
		case 'd': // 移動(右)
			sel_x++;
			break;
		case ' ': // 塗る
			mino.paint(sel_x, sel_y);
			no_change = false;
			break;
		case 'T': // 設定
		case 't':
			mode = M_SET;
			break;
		case 'X': // 保存
		case 'x':
			mode = M_SAVE;
			break;
		case 'Q': // 終了
		case 'q':
			mode = M_QUIT;
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
			

			// 表示内容
			if (sel_x == x && sel_y == y)
				printf("■");
			else
				printf("□");

			color_reset();  // 色リセット
		}
		if (y == 0) printf("\tミノの設定: Tキー");
		if (y == 1) printf("\tミノの保存: Xキー");
		if (y == 2) printf("\t終了      : Qキー");

		printf("\n");
	}
	
}

// 流れ
void make_mino(int &status) {
	Mino new_mino;
	int sel_x = 0, sel_y = 0, mode = M_MAKE;
	bool no_change = true;
	new_mino.init(4, 4, 1);
	while (status == MAKE) {
		switch (mode) {
		case M_MAKE:
			make_show(new_mino, sel_x, sel_y);
			make_operate(new_mino, sel_x, sel_y, no_change, mode);
			break;
		case M_SET:
			m_set(new_mino, mode);
			sel_reset(sel_x, sel_y);
			break;
		case M_SAVE:
			m_save(new_mino, mode);
			no_change = true;
			break;
		case M_QUIT:
			m_quit(new_mino, no_change, mode, status);
			break;
		}
	}
	system("cls");
}
