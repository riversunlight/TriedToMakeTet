/* ===== �u�e�g����Ă݂��v ===== */
// �e�g���X�Ƃقړ������[��
// ���쌠�N�Q���Ȃ��悤�ɂƂ���ǂ���ύX

#include <stdio.h>
#include <Windows.h>
#include "scene_macro.h"
#include "mino.h"
#include "opening.h"
#include "make_mino.h"

int main() {
	int status = OP;
	
	while (status != QUIT) {
		switch (status) {
		case OP:
			status = opening(status);
			break;
		case MAKE:
			status = make_mino(status);
			break;
		case SETTING:
			break;
		case RESULT:
			break;
		}
	}

	printf("See You Next Time!!!");
	Sleep(1000 * 4);
	return 0;
}
