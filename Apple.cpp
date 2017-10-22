#include "Apple.h"



Apple::Apple()
{
	apl.SetBlockType(Space);

	apl.SetX(0);
	apl.SetY(0);

	eaten = true;
	eatenCount = 0;
}

void Apple::Place(Snake * snake)
{
	ListItem<Block> *tmp = snake->GetHead();

	eaten = false;

	bool Free = false;

	int y = rand() % 23 + 1;
	int x = rand() % 48 + 1;
	
	while (!Free)
	{
		while (tmp)
		{
			if (tmp->item.GetX() != x && tmp->item.GetY() != y)
			{
				Free = true;
				break;
			}
			else
			{
				y = rand() % 23 + 1;
				x = rand() % 48 + 1;
			}
			tmp = tmp->next;
		}
		tmp = snake->GetHead();
	}

	apl.SetY(y);
	apl.SetX(x);
	apl.SetBlockType(Apfel);
	apl.SetDirection(Apfel);

	IncrEatenCount();

	apl.Draw();
}

void Apple::Delete()
{
	apl.SetX(0);
	apl.SetY(0);
	eaten = true;
}

void Apple::ShowEaten()
{
	GotoXY(60, 11);
	cout << "Eaten Apples: " << eatenCount;
}