#include <conio.h>
#include <stdio.h>

void StayForAnyKey() {
	while (!_kbhit());
	rewind(stdin);
}