#ifndef MATRIX_OPERATIONS_HPP
#define MATRIX_OPERATIONS_HPP

#include "binary_operations.hpp"
#include <iostream>

std::deque<std::deque<int>> generateMatrix(int n, int k, int value,
                                           bool draw = true);
std::deque<int> syndrom(std::deque<std::deque<int>> htMatrix,
                        std::deque<int> input, int n, int k);
int calculate_d_min(std::deque<std::deque<int>> matrix, int n, int k);
std::deque<int> multiplyMatrix(std::deque<int> a, std::deque<std::deque<int>> b,
                               int n, int k);

#endif // MATRIX_OPERATIONS_HPP