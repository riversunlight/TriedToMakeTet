#include <iostream>
#include <string>
#include <stdlib.h>
#include "lib.h"
#include "mino.h"
#include "scene_macro.h"
using namespace std;

// 入力(名前、使うかどうか)
void m_save_input(char name[], int use) {
	printf("ミノの名前(半角20文字分以内)>");
	cin >> name;
	strcat_s(name, 21, ".txt");
	printf("出現(0: させる 1: させない)>");
	cin >> use;
}

void m_save_output(Mino mino, char name[], int use) {
	FILE* fp;
	errno_t err;

	err = fopen_s(&fp, name, "w");
	fprintf(fp, "%d %d % d\n", mino.h, mino.w, mino.color);
	for (int y = 0; y < mino.h; y++) {
		for (int x = 0; x < mino.w; x++) {
			fprintf(fp, "%d", mino.place[y][x]);

			if (x != mino.w - 1) fprintf(fp, " ");
			else fprintf(fp, "\n");
		}
	}
	fprintf(fp, "%d\n", use);
	fclose(fp);
}

// 流れ
void m_save(Mino mino, int& move) {
	char name[2*10 + 1];
	int use = 0;

	m_save_input(name, use);
	m_save_output(mino, name, use);
	printf("保存しました!!");
	StayForAnyKey();
	move = M_MAKE;
}