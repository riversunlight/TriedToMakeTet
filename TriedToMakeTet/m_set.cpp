/* ミノ作り用の設定 */
#include <conio.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include "mino.h"
#include "scene_macro.h"
#define ENTER 13
using namespace std;

void m_set_sel(int sel, int& num) {
	string obj, cho;
	int r = 0, range;

	// 表示内容の設定
	switch (sel) {
	case 0: obj = "縦幅"; range = 4; cho = "(1～4の数値を入力)"; break;
	case 1: obj = "横幅"; range = 4; cho = "(1～4の数値を入力)"; break;
	case 2: obj = " 色 "; range = 6; cho = "(1:赤  2:緑  3:黄  4:青  5:マゼンタ  6:シアン)"; break;
	}

	// 入力
	system("cls");
	while (!(r >= 1 && r <= range)) {
		cout << obj << "の設定" << cho << ">";
		scanf_s("%d", &r);
		system("cls");
		if (!(r >= 1 && r <= range)) {
			printf("1～%dの値を入力してください\n", range);
		}
	}
	num = r;
}

void m_set_exection(Mino& mino, int sel, int& mode) {
	static int h = 4, w = 4, color = 1;
	switch (sel) {
	case 0: // 縦選択
		m_set_sel(sel, h);
		break;
	case 1: // 横選択
		m_set_sel(sel, w);
		break;
	case 2: // 色選択
		m_set_sel(sel, color);
		break;
	case 3: // 反映(反映後戻る)
		mino.init(h, w, color);
	case 4: // キャンセル
		mode = M_MAKE;
		break;
	}
}

void m_set_operate(Mino& mino, int& sel, int& mode) {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			sel--;
			break;
		case 's':
			sel++;
			break;
		case ENTER:
			m_set_exection(mino, sel, mode);
			break;
		}
		sel = (sel + 5) % 5;
	}
}

void m_set_show(int sel) {
	system("cls");
	printf("==ミノの設定==\n");
	printf("   %s縦\n", (sel == 0) ? "◎" : "  ");
	printf("   %s横\n", (sel == 1) ? "◎" : "  ");
	printf("   %s色\n", (sel == 2) ? "◎" : "  ");
	printf("   %s反映\n", (sel == 3) ? "◎" : "  ");
	printf("   %sキャンセル\n", (sel == 4) ? "◎" : "  ");
}

void m_set(Mino& mino, int& mode) {
	int sel = 0;
	while (mode == M_SET) {
		m_set_show(sel);
		m_set_operate(mino, sel, mode);
	}
}