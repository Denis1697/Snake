#pragma once
#include "Includes.h"

class Block
{
private:
	int _x;
	int _y;
	char _blocktype;
	int _direction;
public:
	Block() { _x = 0; _y = 0; _blocktype = Space; _direction = Left; }
	Block(int y, int x, char blocktype, int direct) { _x = x; _y = y; _blocktype = blocktype; _direction = direct; }

	int GetX() { return _x; }
	int GetY() { return _y; }
	char GetBlockType() { return _blocktype; }
	int GetDirection() { return _direction; }

	void SetX(int x) { _x = x; }
	void SetY(int y) { _y = y; }
	void SetBlockType(char blocktype) { _blocktype = blocktype; }
	void SetDirection(int direct) { _direction = direct; }

	void Draw() { WriteChar(_x, _y, _blocktype); }
};