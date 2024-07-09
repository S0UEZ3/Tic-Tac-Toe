#include "Game.h"


Game::Game() {
	window.board = &field;
}

void Game::start() {
	create_field();
	while (true) {
		window.clear_screen();
		window.print_field();
		window.print("turn: " + std::string(turn ? "x" : "o"));
		set_field_cell();
		int win = check_win();
		if (win == 3) {
			turn ^= 1;
			continue;
		}
		window.clear_screen();
		if(win == 0){
			window.print("o's win");
		}
		if (win == 1) {
			window.print("x's win");
		}
		if (win == 2) {
			window.print("draw!");
		}
		return;
	}
};

void Game::create_field() {
	while (true) {
		window.clear_screen();
		window.print("Enter integer field size: ");
		std::string line = window.get_line();
		try {
			n = stoi(line);
		}
		catch (std::exception &e) {
			continue;
		}
		if (n >= 3 && n < 100) {
			break;
		}
	}
	field.resize(n, std::vector<int>(n, 2));
};

int Game::check_win() {
	for (int i = 0; i < n - 2; ++i) {
		for (int j = 0; j < n; ++j) {
			if (field[i][j] == turn && field[i + 1][j] == turn && field[i + 2][j] == turn) {
				return turn;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n - 2; ++j) {
			if (field[i][j] == turn && field[i][j + 1] == turn && field[i][j + 2] == turn) {
				return turn;
			}
		}
	}

	for (int i = 0; i < n - 2; ++i) {
		for (int j = 0; j < n - 2; ++j) {
			if (field[i][j] == turn && field[i + 1][j + 1] == turn && field[i + 2][j + 2] == turn) {
				return turn;
			}
		}
	}

	for (int i = 0; i < n - 2; ++i) {
		for (int j = n - 1; j > 1; --j) { 
			if (field[i][j] == turn && field[i + 1][j - 1] == turn && field[i + 2][j - 2] == turn) {
				return turn;
			}
		}
	}

	int count = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (field[i][j] != 2) {
				count++;
			}
		}
	}
	if (count == n * n) {
		return 2;
	}
	return 3;
}

void Game::set_field_cell() {
	while (true) {
		window.print("Enter row and column (separated by space): ");
		std::string line = window.get_line();

		size_t space_pos = line.find(' ');
		if (space_pos == std::string::npos) {
			window.print("Invalid input format. Try again.");
			continue;
		}

		std::string row_str = line.substr(0, space_pos);
		std::string col_str = line.substr(space_pos + 1);

		int row, col;
		try {
			row = std::stoi(row_str) - 1;  
			col = std::stoi(col_str) - 1;  
		}
		catch (std::exception& e) {
			window.print("Invalid input. Please enter valid integers.");
			continue;
		}

		if (row < 0 || row >= n || col < 0 || col >= n) {
			window.print("Invalid position. Try again.");
			continue;
		}

		if (field[row][col] != 2) {
			window.print("Cell is already occupied. Try again.");
			continue;
		}

		field[row][col] = turn;
		break;
	}
}