#ifndef INPUT_OPERATIONS_HPP
#define INPUT_OPERATIONS_HPP

#include <deque>
#include <iostream>
#include <string>

/**
 * @file input_operations.hpp
 * @brief Header file for input processing functions.
 */

/**
 * @brief Gets a binary codeword from the keyboard.
 *
 * This function prompts the user to input a binary codeword of a specified
 * length from the keyboard. It validates the input and ensures that it matches
 * the expected length.
 *
 * @param n The length of the codeword.
 * @return  A binary codeword as a deque.
 */
std::deque<int> getWord(int n);

#endif