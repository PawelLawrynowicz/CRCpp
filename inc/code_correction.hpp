#ifndef CODE_CORRECTION_HPP
#define CODE_CORRECTION_HPP

#include "input_operations.hpp"
#include "matrix_operations.hpp"

/**
 * @file code_correction.hpp
 * @brief Header file for error correction functions.
 */

/**
 * @brief Corrects errors in a codeword using the given parity-check matrix.
 *
 * This function attempts to correct errors in a codeword using the provided
 * parity-check matrix. If errors are detected and can be corrected, it modifies
 * the codeword accordingly.
 *
 * @param htMatrix The parity-check matrix (transpose).
 * @param n        The length of the codeword.
 * @param k        The dimension of the code.
 */
void correct(std::deque<std::deque<int>> htMatrix, int n, int k);

/**
 * @brief Generates the control matrix, minimum distance, and other properties
 * of a code.
 *
 * This function generates the control matrix, minimum distance,
 * error-detecting, and error-correcting capabilities of a code based on its
 * parameters.
 *
 * @param n     The length of the codeword.
 * @param k     The dimension of the code.
 * @param gx    The generator polynomial.
 * @param draw  Whether to draw and display matrices (for debugging).
 * @return      The parity-check matrix (transpose).
 */
std::deque<std::deque<int>> controlMatrix(int n, int k, int gx, bool draw);

/**
 * @brief Checks the correctness of the provided generator polynomial.
 *
 * This function checks the correctness of the provided generator polynomial
 * by dividing it with a predefined polynomial and verifying the remainder.
 *
 * @param n   The length of the codeword.
 * @param gen The generator polynomial represented as a binary sequence.
 * @return    True if the parameters are correct, false otherwise.
 */
bool check(int n, std::deque<int> gen);

#endif // CODE_CORRECTION_HPP