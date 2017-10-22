#include "Field.h"

Field::Field()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (i == 0 || j == 0 || i == H - 1 || j == W - 1)
				GF[i][j].SetBlockType(Border);
			else
				GF[i][j].SetBlockType(Space);
			GF[i][j].SetX(j);
			GF[i][j].SetY(i);
		}
	}
}

Field::Field(Snake * snake, Apple * apple)
{
	this->snake = snake;
	this->apple = apple;

	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (i == 0 || j == 0 || i == H - 1 || j == W - 1)
				GF[i][j].SetBlockType(Border);
			else
				GF[i][j].SetBlockType(Space);
			GF[i][j].SetX(j);
			GF[i][j].SetY(i);
		}
	}
}

void Field::Draw()
{
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			GF[i][j].Draw();
}

void Field::RefreshField()
{
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
		{
			if (i == 0 || j == 0 || i == H - 1 || j == W - 1)
				continue;
			else if (GF[i][j].GetBlockType() != Space)
				GF[i][j].SetBlockType(Space);
		}
	}

	ListItem<Block> *tmp = snake->GetHead();

	while (tmp)
	{
		GF[tmp->item.GetY()][tmp->item.GetX()].SetBlockType(snakee);
		tmp = tmp->next;
	}

	GF[apple->GetApl().GetY()][apple->GetApl().GetX()].SetBlockType(appple);
}