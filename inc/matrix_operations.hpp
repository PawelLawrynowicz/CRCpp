#ifndef MATRIX_OPERATIONS_HPP
#define MATRIX_OPERATIONS_HPP

#include "binary_operations.hpp"
#include <iostream>

/**
 * @file matrix_operations.hpp
 * @brief Header file for matrix-related functions.
 */

/**
 * @brief Generates a parity-check matrix for error correction.
 *
 * This function generates a parity-check matrix for error correction with
 * specified parameters.
 *
 * @param n     The length of the codeword.
 * @param k     The dimension of the code.
 * @param value A value used for matrix generation.
 * @param draw  Whether to draw and display the matrix (for debugging).
 * @return      The generated parity-check matrix.
 */
std::deque<std::deque<int>> generateMatrix(int n, int k, int value,
                                           bool draw = true);

/**
 * @brief Calculates the syndrome of a codeword using the parity-check matrix.
 *
 * This function calculates the syndrome of a codeword using the provided
 * parity-check matrix.
 *
 * @param htMatrix The parity-check matrix (transpose).
 * @param input    The received codeword.
 * @param n        The length of the codeword.
 * @param k        The dimension of the code.
 * @return         The syndrome of the codeword.
 */
std::deque<int> syndrom(std::deque<std::deque<int>> htMatrix,
                        std::deque<int> input, int n, int k);

/**
 * @brief Calculates the minimum distance (d_min) of a code.
 *
 * This function calculates the minimum distance (d_min) of a code using its
 * parity-check matrix.
 *
 * @param matrix The parity-check matrix (transpose).
 * @param n      The length of the codeword.
 * @param k      The dimension of the code.
 * @return       The minimum distance (d_min) of the code.
 */
int calculate_d_min(std::deque<std::deque<int>> matrix, int n, int k);

/**
 * @brief Multiplies a binary vector by a binary matrix.
 *
 * This function multiplies a binary vector by a binary matrix, producing a
 * resulting binary vector.
 *
 * @param a The binary vector to multiply.
 * @param b The binary matrix to multiply by.
 * @param n The length of the codeword.
 * @param k The dimension of the code.
 * @return  The resulting binary vector after multiplication.
 */
std::deque<int> multiplyMatrix(std::deque<int> a, std::deque<std::deque<int>> b,
                               int n, int k);

#endif // MATRIX_OPERATIONS_HPP