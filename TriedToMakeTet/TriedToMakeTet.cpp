/* ===== �u�e�g����Ă݂��v ===== */
// �e�g���X�Ƃقړ������[��
// ���쌠�N�Q���Ȃ��悤�ɂƂ���ǂ���ύX

#include <stdio.h>
#include <Windows.h>
#include "scene_macro.h"
#include "opening.h"

int main() {
	int status = OP;
	
	switch (status) {
	case OP:
		opening(status);
		break;
	}

	printf("See You Next Time!!!");
	Sleep(1000 * 4);
	return 0;
}
