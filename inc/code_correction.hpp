#ifndef CODE_CORRECTION_HPP
#define CODE_CORRECTION_HPP

#include "input_operations.hpp"
#include "matrix_operations.hpp"

void correct(std::deque<std::deque<int>> htMatrix, int n, int k);
std::deque<std::deque<int>> controlMatrix(int n, int k, int gx, bool draw);
bool check(int n, std::deque<int> gen);

#endif // CODE_CORRECTION_HPP