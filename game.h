#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <windows.h>
#include <regex>

class game
{
private:
	std::vector < std::vector<std::string>> table;
	std::map<int, std::string> m;
	std::vector<int> available;

public:
	game();
	void gotoxy(int,int);
	void color(int);
	void display();
	void getPossiblePlaces();
	void player1();
	void player2();
	bool isP1Win();
	bool isP2Win();
};