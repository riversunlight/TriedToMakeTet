/* ミノづくりシーン */
// ・ミノを作って保存できる(保存されたミノは、設定から出現するしないを変更できる)
// ・ミノづくりを選択すると実際に作るところへ
// ・設定は作るところから飛ぶ

#include <stdio.h>
#include <conio.h>
#include "scene_macro.h"
#include "mino.h"

// 表示
void make_show(Mino mino) {
	system("cls");
	for (int y = 0; y < mino.h; y++) {
		for (int x = 0; x < mino.w; x++) {
			if (mino.place[y][x])
				printf("□");
			else
			    printf("□");
		}
		printf("\n");
	}
}

// 流れ
void make_mino(int &status) {
	Mino new_mino;
	new_mino.init(4, 4, 0);
	while (status == MAKE) {
		make_show(new_mino);
	}
	system("cls");
}
