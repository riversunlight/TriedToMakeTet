/* �~�m���p�̐ݒ� */
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

	// �\�����e�̐ݒ�
	switch (sel) {
	case 0: obj = "�c��"; range = 4; cho = "(1�`4�̐��l�����)"; break;
	case 1: obj = "����"; range = 4; cho = "(1�`4�̐��l�����)"; break;
	case 2: obj = " �F "; range = 6; cho = "(1:��  2:��  3:��  4:��  5:�}�[���^  6:�V�A��)"; break;
	}

	// ����
	system("cls");
	while (!(r >= 1 && r <= range)) {
		cout << obj << "�̐ݒ�" << cho << ">";
		scanf_s("%d", &r);
		system("cls");
		if (!(r >= 1 && r <= range)) {
			printf("1�`%d�̒l����͂��Ă�������\n", range);
		}
	}
	num = r;
}

void m_set_exection(Mino& mino, int sel, int& mode) {
	static int h = 4, w = 4, color = 1;
	switch (sel) {
	case 0: // �c�I��
		m_set_sel(sel, h);
		break;
	case 1: // ���I��
		m_set_sel(sel, w);
		break;
	case 2: // �F�I��
		m_set_sel(sel, color);
		break;
	case 3: // ���f(���f��߂�)
		mino.init(h, w, color);
	case 4: // �L�����Z��
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
	printf("==�~�m�̐ݒ�==\n");
	printf("   %s�c\n", (sel == 0) ? "��" : "  ");
	printf("   %s��\n", (sel == 1) ? "��" : "  ");
	printf("   %s�F\n", (sel == 2) ? "��" : "  ");
	printf("   %s���f\n", (sel == 3) ? "��" : "  ");
	printf("   %s�L�����Z��\n", (sel == 4) ? "��" : "  ");
}

void m_set(Mino& mino, int& mode) {
	int sel = 0;
	while (mode == M_SET) {
		m_set_show(sel);
		m_set_operate(mino, sel, mode);
	}
}