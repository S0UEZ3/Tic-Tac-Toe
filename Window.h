#pragma once

#include <iostream>
#include <vector>
#include <string>

class Game;

class Window { 
    friend Game;
public:
    void clear_screen() {
        system("cls");//apple
    }

    void print(const std::string& message) {
        std::cout << message << std::endl;
    }

    void print_field() {
        if (!board) {
            return;
        }

        for (const auto& row : *board) {
            for (const auto& cell : row) {
                char symbol;
                switch (cell) {
                case 0: symbol = 'o'; break;
                case 1: symbol = 'x'; break;
                default: symbol = '.';
                }
                std::cout << symbol << " ";
            }
            std::cout << std::endl;
        }
    }

    std::string get_line() {
        std::string input;
        std::getline(std::cin, input);
        return input;
    }


private:
    std::vector<std::vector<int>>* board = nullptr;
};