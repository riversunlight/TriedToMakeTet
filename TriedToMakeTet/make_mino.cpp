/* �~�m�Â���V�[�� */
// �E�~�m������ĕۑ��ł���(�ۑ����ꂽ�~�m�́A�ݒ肩��o�����邵�Ȃ���ύX�ł���)
// �E�~�m�Â����I������Ǝ��ۂɍ��Ƃ����
// �E�ݒ�͍��Ƃ��납����

#include <stdio.h>
#include <conio.h>
#include "scene_macro.h"
#include "mino.h"

// �\��
void make_show(Mino mino) {
	system("cls");
	for (int y = 0; y < mino.h; y++) {
		for (int x = 0; x < mino.w; x++) {
			if (mino.place[y][x])
				printf("��");
			else
			    printf("��");
		}
		printf("\n");
	}
}

// ����
void make_mino(int &status) {
	Mino new_mino;
	new_mino.init(4, 4, 0);
	while (status == MAKE) {
		make_show(new_mino);
	}
	system("cls");
}
