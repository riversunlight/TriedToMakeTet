/* �I�[�v�j���O�V�[�� */
// �E�v���C�ւ̑J��
// �E�~�m�Â���
// �E�ݒ�

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "scene_macro.h"

int opening_operate(int sel) {
	if (_kbhit()) {
		int r = _getch();
		switch (r) {
		case 'w':
			sel--;
			break;
		case 's':
			sel++;
			break;
		}
		sel = (sel + 3) % 3;
	}
	return sel;
}

void opening_show(int sel) {
	system("cls");
	printf("===== �e�g����Ă݂� =====\n");
	printf("\t%s�v���C\n", (sel == 0) ? "��" : "  ");
	printf("\t%s�~�m���\n", (sel == 1) ? "��" : "  ");
	printf("\t%s�ݒ�\n", (sel == 2) ? "��" : "  ");
}

int opening(int status) {
	static int sel = 0;
	while (status == OP) {
		opening_show(sel);
		sel = opening_operate(sel);
	}
	return status;
}