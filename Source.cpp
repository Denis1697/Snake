#include "Includes.h"
#include "Field.h"

int Apple::eatenCount = 0;

void main()
{
	int delay = 0;
	int key = 0;

	srand(unsigned(time(NULL)));

	ShowCursor(false);

	Snake * snake = new Snake;
	Apple * apple = new Apple;

	Field field(snake, apple);

	field.Draw();

	while (true)
	{
		field.RefreshField();

		if(apple->IsEaten())
			apple->Place(snake);

		cout << flush;

		snake->Draw();

		while (!_kbhit())
		{
			if (delay == 10000)
			{
				delay = 0;
				snake->Move();
				snake->Draw();
			}
			delay++;
		}

		key = _getch();

		if (!snake->Move(key))
			exit(1);
	}
}