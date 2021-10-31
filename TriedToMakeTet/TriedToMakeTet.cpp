/* ===== 「テト作ってみた」 ===== */
// テトリスとほぼ同じルール
// 著作権侵害しないようにところどころ変更

#include <stdio.h>
#include <Windows.h>
#include "scene_macro.h"
#include "mino.h"
#include "opening.h"
#include "make_mino.h"
#include "setting.h"

int main() {
	int status = OP;
	
	while (status != QUIT) {
		switch (status) {
		case OP:
			opening(status);
			break;
		case PLAY:
			break;
		case MAKE:
			make_mino(status);
			break;
		case SETTING:
			setting(status);
			break;
		case RESULT:
			break;
		}
	}

	printf("See You Next Time!!!");
	Sleep(1000 * 4);
	return 0;
}
