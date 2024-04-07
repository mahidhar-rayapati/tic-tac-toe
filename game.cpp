#include "game.h"

game::game()
{
	table.push_back({ ".",".","." });
	table.push_back({ ".",".","." });
	table.push_back({ ".",".","." });
	int x = 0;
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m[++x] = std::to_string(i) + std::to_string(j);
		}
	}
	available.clear();
}

void game::gotoxy(int a, int b)
{
	COORD c;
	c.X = a;
	c.Y = b;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void game::color(int p)
{
	HANDLE console_color;
	console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, p);
}

void game::display()
{
	color(15);
	int y = 10;
	for (int i = 0; i < 3; i++)
	{
		int x = 60;
		for (int j = 0; j < 3; j++)
		{
			x += 9;
			gotoxy(x,y);
			std::cout << table[i][j];
		}
		y += 3;
	}
}

void game::getPossiblePlaces()
{
	gotoxy(60, 20);
	std::cout << "Possible places are: ";
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (table[i][j] == ".")
			{
				std::string random = std::to_string(i) + std::to_string(j);
				for (auto keys : m)
				{
					if (keys.second == random)
					{
						available.push_back(keys.first);
						std::cout << keys.first << ",";
					}
				}
			}
		}
	}
}

void game::player1()
{
	getPossiblePlaces();
	while (true)
	{
		gotoxy(27, 22);
		color(11);
		std::cout << "Player-1";
		gotoxy(25, 23);
		std::cout << "Enter choice : ";
		std::string choice;
		std::cin >> choice;
		std::regex check("[1-9]");
		try {
			if (!std::regex_match(choice,check)) throw "Please input single digit !!!";
		}
		catch(const char *e)
		{
			gotoxy(65, 19);
			color(12);
			std::cout << e;
			continue;
		}
		bool found = false;
		for (int i = 0; i < available.size(); i++)
		{
			if (stoi(choice) == available[i])
			{
				int q = m[stoi(choice)][0] - '0';
				int w = m[stoi(choice)][1] - '0';
				if (table[q][w] == ".")
				{
					table[q][w] = "x";
					found = true;
				}
			}
		}
		if (!found)
		{
			gotoxy(60, 19);
			color(12);
			std::cout << "Can't insert please select available places";
		}
		else break;
	}
	system("cls");
	display();
}

void game::player2()
{
	getPossiblePlaces();
	while (true)
	{
		gotoxy(122, 22);
		color(13);
		std::cout << "Player-2";
		gotoxy(120, 23);
		std::cout << "Enter choice : ";
		std::string choice;
		std::cin >> choice;
		std::regex check("[1-9]");
		try {
			if (!std::regex_match(choice, check)) throw "Please input single digit !!!";
		}
		catch (const char* e)
		{
			gotoxy(65, 19);
			color(12);
			std::cout << e;
			continue;
		}

		bool found = false;
		for (int i = 0; i < available.size(); i++)
		{
			if (stoi(choice) == available[i])
			{
				int q = m[stoi(choice)][0] - '0';
				int w = m[stoi(choice)][1] - '0';
				if (table[q][w] == ".")
				{
					table[q][w] = "O";
					found = true;
				}
			}
		}
		if (!found)
		{
			gotoxy(60, 19);
			color(12);
			std::cout << "Can't insert please select available places";
		}
		else break;
	}
	system("cls");
	display();
}

bool game::isP1Win()
{
	if (table[0][0] == "x" && table[1][1] == "x" && table[2][2] == "x") return true;
	if (table[2][0] == "x" && table[1][1] == "x" && table[0][2] == "x") return true;
	for (int i = 0; i < 3; i++)
	{
		if (table[i][0] == "x" && table[i][1] == "x" && table[i][2] == "x") return true;
	}
	for (int i = 0; i < 3; i++)
	{
		if (table[0][i] == "x" && table[1][i] == "x" && table[2][i] == "x") return true;
	}
	return false;
}

bool game::isP2Win()
{
	if (table[0][0] == "O" && table[1][1] == "O" && table[2][2] == "O") return true;
	if (table[2][0] == "O" && table[1][1] == "O" && table[0][2] == "O") return true;
	for (int i = 0; i < 3; i++)
	{
		if (table[i][0] == "O" && table[i][1] == "O" && table[i][2] == "O") return true;
	}
	for (int i = 0; i < 3; i++)
	{
		if (table[0][i] == "O" && table[1][i] == "O" && table[2][i] == "O") return true;
	}
	return false;
}