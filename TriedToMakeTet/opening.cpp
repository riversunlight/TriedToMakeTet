/* �I�[�v�j���O�V�[�� */
// �E�v���C�ւ̑J��
// �E�~�m�Â���
// �E�ݒ�

#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "scene_macro.h"
#define ENTER 13

// ����
int opening_operate(int sel, int *status) {
	if (_kbhit()) {
		int r = _getch();

		//�J�[�\��(��)�̈ړ�
		switch (r) {
		case 'w':
			sel--;
			break;
		case 's':
			sel++;
			break;
		}

		// status��PLAY, MAKE, SETTING��
		if (r == ENTER) {
			*status = sel + 1;
		}

		sel = (sel + 4) % 4; //���[�v
	}
	return sel;
}

// �\��
void opening_show(int sel) {
	system("cls");
	printf("===== �e�g����Ă݂� =====\n");
	printf("\t%s�v���C\n", (sel == 0) ? "��" : "  ");
	printf("\t%s�~�m���\n", (sel == 1) ? "��" : "  ");
	printf("\t%s�ݒ�\n", (sel == 2) ? "��" : "  ");
	printf("\t%s�I��\n", (sel == 3) ? "��" : "  ");

}

// ����
int opening(int status) {
	static int sel = 0;
	while (status == OP) {
		opening_show(sel);
		sel = opening_operate(sel, &status);
	}
	sel = 0;
	system("cls");
	return status;
}
