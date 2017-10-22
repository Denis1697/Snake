#pragma once
#include "Block.h"

class Snake
{
private:
	List<Block> snake;
	ListItem<Block> * Head;

	int _length;

	void TurnLeft();
	void TurnRight();
	void TurnDown();
	void TurnUp();

	bool CrossItSelf();
	bool CrossBorder();
	bool CrossBackBlock(int side);
public:
	Snake();	

	int Move(int side);

	int Move();

	void Draw();

	ListItem<Block> * GetHead() { return Head; }
};