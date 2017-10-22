#pragma once
#include "Snake.h"

class Apple
{
private:
	static int eatenCount;
	Block apl;
	bool eaten;
public:
	Apple();

	void Place(Snake * snake);
	void Delete();

	bool IsEaten() { return eaten; }
	void SetEaten(bool status) { eaten = status; }

	int GetEatenCount() { return eatenCount; }
	void IncrEatenCount() { eatenCount++; }

	void ShowEaten();

	Block GetApl() { return apl; }
};