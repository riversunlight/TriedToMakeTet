#include <iostream>
#include "scene_macro.h"
#include "mino.h"
using namespace std;

// ����ɏI�����Ă悢��
bool m_quit_can(Mino mino, bool no_change) {
	bool can = true;
	for (int y = 0; y < mino.h; y++)
		for (int x = 0; x < mino.w; x++)
			if (mino.place[y][x] != 0) can = false;

	return can || no_change;
}

// �I�����邩�̓���
bool m_quit_ask() {
	bool res;
	cout << "�ύX�������e���ۑ�����Ă��܂���B" << endl;
	cout << "�~�m�����I�����܂���?(1: �I������ 0: �I�����Ȃ�)>";
	cin >> res;
	return res;
}

// �~�m���I��
void m_quit(Mino mino, bool no_change, int& mode, int& status) {
	bool quit;
	if (m_quit_can(mino, no_change) || (quit = m_quit_ask()))
		status = OP;
	mode = M_MAKE;
}