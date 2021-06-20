/* ===== 「テト作ってみた」 ===== */
// テトリスとほぼ同じルール
// 著作権侵害しないようにところどころ変更

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
