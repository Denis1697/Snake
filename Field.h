#pragma once
#include "Apple.h"

class Field
{
private:
	Block GF[H][W];
	Snake * snake;
	Apple * apple;
public:
	Field();
	Field(Snake * snake, Apple * apple);

	void SetFieldBlock(int y, int x, int blocktype) { GF[y][x].SetBlockType(blocktype); }
	void DeleteFieldBlock(int y, int x) { GF[y][x].SetBlockType(Space); }
	Block & GetFieldBlock(int y, int x) { return GF[y][x]; }

	void RefreshField();

	void Draw();
};