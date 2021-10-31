/* �ݒ�V�[�� */
// �~�m�̊Ǘ�
// �v���C���Ԃ̊Ǘ�
// �����L���O�̊Ǘ�
#include <iostream>
#include <vector>
#include <string>
#include <conio.h>
#include "scene_macro.h"
using namespace std;

#define ENTER 13

const vector<string> choices = { "��ʃT�C�Y", "�~�m�̏o��", "�~�m�̍폜", "�v���C����", "�����L���O�폜", "�߂�" };

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
	cout << "==========�ݒ�==========" << endl;
	for (unsigned int i = 0; i < choices.size(); i++)
		cout << "    " << ((sel == i) ? "��" : "  ") << choices[i] << endl;
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