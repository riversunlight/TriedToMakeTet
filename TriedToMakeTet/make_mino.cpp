/* �~�m�Â���V�[�� */
// �E�~�m������ĕۑ��ł���(�ۑ����ꂽ�~�m�́A�ݒ肩��o�����邵�Ȃ���ύX�ł���)
// �E�~�m�Â����I������Ǝ��ۂɍ��Ƃ����
// �E�ݒ�͍��Ƃ��납����

#include <stdio.h>
#include <conio.h>
#include "scene_macro.h"
#include "mino.h"
#include "color.h"
#include "m_set.h"
#include "m_save.h"
#include "m_quit.h"

// ���W���Z�b�g
inline void sel_reset(int& sel_x, int& sel_y) {
	sel_x = 0; sel_y = 0;
}

// ����
void make_operate(Mino& mino, int& sel_x, int& sel_y, bool& no_change,  int& mode) {
	if (_kbhit()) {
		switch (_getch()) {
		case 'w': // �ړ�(��)
			sel_y--;
			break;
		case 'a': // �ړ�(��)
			sel_x--;
			break;
		case 's': // �ړ�(��)
			sel_y++;
			break;
		case 'd': // �ړ�(�E)
			sel_x++;
			break;
		case ' ': // �h��
			mino.paint(sel_x, sel_y);
			no_change = false;
			break;
		case 'T': // �ݒ�
		case 't':
			mode = M_SET;
			break;
		case 'X': // �ۑ�
		case 'x':
			mode = M_SAVE;
			break;
		case 'Q': // �I��
		case 'q':
			mode = M_QUIT;
			break;
		}
		sel_x = (sel_x + mino.w) % mino.w;
		sel_y = (sel_y + mino.h) % mino.h;
	}
}

// �\��
void make_show(Mino mino, int sel_x, int sel_y) {
	system("cls");
	for (int y = 0; y < mino.h; y++) {
		for (int x = 0; x < mino.w; x++) {
			// �F����
			if (mino.place[y][x])
				color_change(mino);
			

			// �\�����e
			if (sel_x == x && sel_y == y)
				printf("��");
			else
				printf("��");

			color_reset();  // �F���Z�b�g
		}
		if (y == 0) printf("\t�~�m�̐ݒ�: T�L�[");
		if (y == 1) printf("\t�~�m�̕ۑ�: X�L�[");
		if (y == 2) printf("\t�I��      : Q�L�[");

		printf("\n");
	}
	
}

// ����
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
