#include <iostream>
#include "scene_macro.h"
#include "mino.h"
using namespace std;

// 勝手に終了してよいか
bool m_quit_can(Mino mino, bool no_change) {
	bool can = true;
	for (int y = 0; y < mino.h; y++)
		for (int x = 0; x < mino.w; x++)
			if (mino.place[y][x] != 0) can = false;

	return can || no_change;
}

// 終了するかの入力
bool m_quit_ask() {
	bool res;
	cout << "変更した内容が保存されていません。" << endl;
	cout << "ミノ作りを終了しますか?(1: 終了する 0: 終了しない)>";
	cin >> res;
	return res;
}

// ミノ作り終了
void m_quit(Mino mino, bool no_change, int& mode, int& status) {
	bool quit;
	if (m_quit_can(mino, no_change) || (quit = m_quit_ask()))
		status = OP;
	mode = M_MAKE;
}