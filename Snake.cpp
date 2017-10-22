#include "Snake.h"

Snake::Snake()
{
	ListItem<Block> *tmp = new ListItem<Block>;

	tmp->item.SetBlockType(Snake_BodyH);
	tmp->item.SetDirection(Right);
	tmp->item.SetX(W / 2 - 1);
	tmp->item.SetY(H / 2);
	
	tmp->next = NULL;

	ListItem<Block> *tmp2 = new ListItem<Block>;

	tmp2->item.SetBlockType(Snake_HeadR);
	tmp2->item.SetDirection(Right);
	tmp2->item.SetX(W / 2);
	tmp2->item.SetY(H / 2);

	Head = tmp2;
	Head->next = tmp;

	_length = 2;
}

void Snake::Draw()
{
	ListItem<Block> * tmp = Head;

	while (tmp)
	{
		tmp->item.Draw();
		tmp = tmp->next;
	}
}

void Snake::TurnLeft()
{
	ListItem<Block> * tmp = Head;
	ListItem<Block> * tmp3 = Head;

	while (tmp->next)
	{
		tmp->item.SetDirection(Left);
		tmp = tmp->next;
	}

	while (tmp3->next->next)
	{
		tmp3 = tmp3->next;
	}
	
	tmp->item.SetBlockType(Space);
	tmp->item.Draw();
	delete tmp;
	tmp = NULL;
	tmp3->next = NULL;

	Head->item.SetBlockType(Snake_BodyH);

	ListItem<Block> *tmp2 = new ListItem<Block>;

	tmp2->item.SetBlockType(Snake_HeadL);
	tmp2->item.SetDirection(Left);
	tmp2->item.SetX(Head->item.GetX() - 1);
	tmp2->item.SetY(Head->item.GetY());
	tmp2->next = Head;

	Head = tmp2;
}

void Snake::TurnRight()
{
	ListItem<Block> * tmp = Head;
	ListItem<Block> * tmp3 = Head;

	while (tmp->next)
	{
		tmp->item.SetDirection(Right);
		tmp = tmp->next;
	}

	while (tmp3->next->next)
	{
		tmp3 = tmp3->next;
	}

	tmp->item.SetBlockType(Space);
	tmp->item.Draw();
	delete tmp;
	tmp = NULL;
	tmp3->next = NULL;

	Head->item.SetBlockType(Snake_BodyH);

	ListItem<Block> *tmp2 = new ListItem<Block>;

	tmp2->item.SetBlockType(Snake_HeadR);
	tmp2->item.SetDirection(Right);
	tmp2->item.SetX(Head->item.GetX() + 1);
	tmp2->item.SetY(Head->item.GetY());
	tmp2->next = Head;

	Head = tmp2;
}

void Snake::TurnDown()
{
	ListItem<Block> * tmp = Head;
	ListItem<Block> *tmp3 = Head;

	while (tmp->next)
	{
		tmp->item.SetDirection(Down);
		tmp = tmp->next;
	}

	while (tmp3->next->next)
	{
		tmp3 = tmp3->next;
	}

	tmp->item.SetBlockType(Space);
	tmp->item.Draw();
	delete tmp;
	tmp = NULL;
	tmp3->next = NULL;

	Head->item.SetBlockType(Snake_BodyV);

	ListItem<Block> *tmp2 = new ListItem<Block>;

	tmp2->item.SetBlockType(Snake_HeadD);
	tmp2->item.SetDirection(Down);
	tmp2->item.SetX(Head->item.GetX());
	tmp2->item.SetY(Head->item.GetY() + 1);
	tmp2->next = Head;

	Head = tmp2;
}

void Snake::TurnUp()
{
	ListItem<Block> * tmp = Head;

	ListItem<Block> *tmp3 = Head;

	while (tmp->next)
	{
		tmp->item.SetDirection(Up);
		tmp = tmp->next;
	}

	while (tmp3->next->next)
	{
		tmp3 = tmp3->next;
	}

	tmp->item.SetBlockType(Space);
	tmp->item.SetDirection(Space);
	tmp->item.Draw();
	delete tmp;
	tmp = NULL;
	tmp3->next = NULL;

	Head->item.SetBlockType(Snake_BodyV);

	ListItem<Block> *tmp2 = new ListItem<Block>;

	tmp2->item.SetBlockType(Snake_HeadU);
	tmp2->item.SetDirection(Up);
	tmp2->item.SetX(Head->item.GetX());
	tmp2->item.SetY(Head->item.GetY() - 1);
	tmp2->next = Head;
	
	Head = tmp2;
}

int Snake::Move(int side)
{
	if (CrossBackBlock(side))
		return 2;

	if (CrossItSelf() || CrossBorder())
		return 0;

	switch (side)
	{
	case Up:
		TurnUp();
		break;
	case Down:
		TurnDown();
		break;
	case Left:
		TurnLeft();
		break;
	case Right:
		TurnRight();
		break;
	}

	return 1;
}

int Snake::Move()
{
	if (CrossBorder())
		return 0;


	switch (Head->item.GetDirection())
	{
	case Up:
		TurnUp();
		break;
	case Down:
		TurnDown();
		break;
	case Left:
		TurnLeft();
		break;
	case Right:
		TurnRight();
		break;
	}
}

bool Snake::CrossItSelf()
{
	ListItem<Block> *tmp = Head->next;
	
	while (tmp)
	{
		if (tmp->item.GetX() == Head->item.GetX() && tmp->item.GetY() == Head->item.GetY())
			return true;

		tmp = tmp->next;
	}

	return false;
}

bool Snake::CrossBorder()
{
	ListItem<Block> *tmp = Head;

	if (Head->item.GetX() == 0 || Head->item.GetX() == W - 1 || Head->item.GetY() == 0 || Head->item.GetY() == H - 1)
		return true;

	return false;
}

bool Snake::CrossBackBlock(int side)
{
	switch (side)
	{
	case Up:
		if (Head->item.GetDirection() == Down)
			return true;
		break;
	case Down:
		if (Head->item.GetDirection() == Up)
			return true;
		break;
	case Left:
		if (Head->item.GetDirection() == Right)
			return true;
		break;
	case Right:
		if (Head->item.GetDirection() == Left)
			return true;
		break;
	}

	return false;
}