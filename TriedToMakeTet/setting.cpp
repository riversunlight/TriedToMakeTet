/* 設定シーン */
// ミノの管理
// プレイ時間の管理
// ランキングの管理
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include "scene_macro.h"
using namespace std;

#define ENTER 13

const vector<string> choices = { "画面サイズ", "ミノの出現", "ミノの削除", "プレイ時間", "ランキング削除", "戻る" };

void set_operate(int& sel, int& mode) {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w':
			sel--;
			break;
		case 's':
			sel++;
			break;
		case ENTER:
			mode = 1 + sel;
			break;
		}
		sel = (sel + choices.size()) % choices.size();
	}
}

void set_show(int sel) {
	system("cls");
	cout << "==========設定==========" << endl;
	for (unsigned int i = 0; i < choices.size(); i++)
		cout << "    " << ((sel == i) ? "◎" : "  ") << choices[i] << endl;
}

void setting(int& status) {
	int mode = S_SET, sel = 0;
	while (status == SETTING) {
		switch (mode) {
		case S_SET:
			set_show(sel);
			set_operate(sel, mode);
			break;
		case S_SIZE:
			break;
		case S_MAPP:
			break;
		case S_MDEL:
			break;
		case S_TIME:
			break;
		case S_RDEL:
			break;
		case S_QUIT:
			break;
		}
	}
}