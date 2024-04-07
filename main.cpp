#include "game.h"


int main()
{
	game obj;
	obj.gotoxy(73, 5);
	obj.color(15);
	std::cout << "TIC TAC TOE";
	obj.display();
	obj.gotoxy(65, 21);
	obj.color(14);
	std::cout << "Press Enter to start the game";
	system("pause>0");
	system("cls");
	obj.display();
	int t = 4;
	bool win;
	while (t--)
	{
		obj.player1();
		if (t < 3)
		{
			win = obj.isP1Win();
			if (win)
			{
				obj.gotoxy(70, 5);
				obj.color(10);
				std::cout << "Winner player-1 !!!";
				system("pause>0");
				return 0;
			}
		}
		obj.player2();
		if (t < 3)
		{
			win = obj.isP2Win();
			if (win)
			{
				obj.gotoxy(70, 5);
				obj.color(10);
				std::cout << "Winner player-2 !!!";
				system("pause>0");
				return 0;
			}
		}
	}
	obj.player1();
	win = obj.isP1Win();
	if (win)
	{
		obj.gotoxy(70, 5);
		obj.color(10);
		std::cout << "Winner player-1 !!!";
		system("pause>0");
		return 0;
	}
	obj.gotoxy(65, 5);
	obj.color(14);
	std::cout << "OOPS the game is Drawn...";
	system("pause>0");
	return 0;
}