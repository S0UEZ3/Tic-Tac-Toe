#pragma once
#include <vector>
#include <string>
#include "Window.h"

class Game {
public:
	Game();

	void start();

private:
	void create_field(); 
	int check_win(); // 0 - win o, 1 - win x, 2 - draw, 3 - continue 
	void set_field_cell();


private:
	Window window;
	std::vector<std::vector<int>> field; // 0 - o, 1 - x, 2 - none
	int n;
	bool turn = 1;
};