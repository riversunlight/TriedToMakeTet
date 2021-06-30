#pragma once
#ifndef MINO_DEF
#define MINO_DEF
#include <vector>
using namespace std;
struct Mino {
	int h; // �c��
	int w; // ����
	vector<vector<int> > place; // h*w�̐����`�̃~�m�̈ʒu
	int color; //�F

	void init(int _h, int _w, int _color) {
		h = _h, w = _w;
		color = _color;
		place.resize(h);
		for (int i = 0; i < h; i++)
			place[i].resize(w);
	}

	void paint(int x, int y) {
		place[y][x] ^= 1;
	}

	void rotate() {
		vector<vector<int> > new_place(w, vector<int> (h));
		for (int y = 0; y < h; y++)
			for (int x = 0; x < w; x++)
				new_place[x][y] = place[y][x];
	}
};
#endif