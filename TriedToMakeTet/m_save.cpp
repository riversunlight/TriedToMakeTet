#include <iostream>
#include <string>
#include <stdlib.h>
#include "lib.h"
#include "mino.h"
#include "scene_macro.h"
using namespace std;

// ����(���O�A�g�����ǂ���)
void m_save_input(char name[], int use) {
	printf("�~�m�̖��O(���p20�������ȓ�)>");
	cin >> name;
	strcat_s(name, 21, ".txt");
	printf("�o��(0: ������ 1: �����Ȃ�)>");
	cin >> use;
}

void m_save_output(Mino mino, char name[], int use) {
	FILE* fp;
	errno_t err;

	err = fopen_s(&fp, name, "w");
	fprintf(fp, "%d %d % d\n", mino.h, mino.w, mino.color);
	for (int y = 0; y < mino.h; y++) {
		for (int x = 0; x < mino.w; x++) {
			fprintf(fp, "%d", mino.place[y][x]);

			if (x != mino.w - 1) fprintf(fp, " ");
			else fprintf(fp, "\n");
		}
	}
	fprintf(fp, "%d\n", use);
	fclose(fp);
}

// ����
void m_save(Mino mino, int& move) {
	char name[2*10 + 1];
	int use = 0;

	m_save_input(name, use);
	m_save_output(mino, name, use);
	printf("�ۑ����܂���!!");
	StayForAnyKey();
	move = M_MAKE;
}