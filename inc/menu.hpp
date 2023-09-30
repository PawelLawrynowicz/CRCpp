#ifndef MENU_HPP
#define MENU_HPP

#include "code_correction.hpp"
#include "matrix_operations.hpp"

#define CLEAR_SCREEN "\033[2J\033[1;1H"

void clear_terminal();

void printCodeWords(std::deque<std::deque<int>> gen, int n, int k);
void printPoly(std::deque<int> poly);
void printPlainText(int n, int k, std::deque<int> poly);
void getNewPoly(int &n, int &k, int &value);
void initMenu(int n = 18, int k = 8, int gx = 1533);
void optMenu();
void menu();

#endif // MENU_HPP