#ifndef BINARY_OPERATIONS_HPP
#define BINARY_OPERATIONS_HPP

#include <cmath>
#include <deque>
#include <string>

/**
 * @file binary_operations.hpp
 * @brief Header file for binary operation functions.
 */

/**
 * @brief Converts a decimal number to binary representation.
 *
 * This function takes a decimal number and returns a deque representing its
 * binary form.
 *
 * @param decimal The decimal number to convert.
 * @return A deque representing the binary representation of the input decimal
 * number.
 */
std::deque<int> decimalToBinary(int decimal);

/**
 * @brief Converts a binary representation to a decimal number.
 *
 * This function takes a deque representing a binary number and converts it to
 * its decimal form.
 *
 * @param binary The binary number to convert.
 * @return The decimal representation of the input binary number.
 */
int binaryToDecimal(std::deque<int> binary);

/**
 * @brief Adds zero bits to the beginning of a binary sequence.
 *
 * This function appends zero bits to the beginning of the input binary
 * sequence.
 *
 * @param a The binary sequence to which zeros should be added.
 * @param c The number of zeros to add.
 * @return The binary sequence with zeros added to the beginning.
 */
std::deque<int> addZero(std::deque<int> &a, int c);

/**
 * @brief Converts a decimal number to a binary representation with a specified
 * precision.
 *
 * This function converts a decimal number to a binary representation with a
 * specified precision (k).
 *
 * @param dec The decimal number to convert.
 * @param k   The desired precision of the binary representation.
 * @return    A deque representing the binary representation with the specified
 * precision.
 */
std::deque<int> precisionDecimalToBinary(int dec, int k);

/**
 * @brief Shifts the bits of a binary sequence to the left.
 *
 * This function shifts the bits of a binary sequence to the left, with the most
 * significant bit becoming the least significant.
 *
 * @param a The binary sequence to shift.
 * @return  The binary sequence after left shifting.
 */
std::deque<int> move_1_to_left(std::deque<int> a);

/**
 * @brief Shifts the bits of a binary sequence to the right.
 *
 * This function shifts the bits of a binary sequence to the right, with the
 * least significant bit becoming the most significant.
 *
 * @param a The binary sequence to shift.
 * @return  The binary sequence after right shifting.
 */
std::deque<int> move_1_to_right(std::deque<int> a);

/**
 * @brief Counts the number of ones in a binary sequence.
 *
 * This function counts and returns the number of ones in a binary sequence.
 *
 * @param syndrome The binary sequence to count ones in.
 * @return         The count of ones in the binary sequence.
 */
int howManyOnes(std::deque<int> syndrome);

/**
 * @brief Calculates the division remainder between two binary sequences.
 *
 * This function calculates the remainder of the division between two binary
 * sequences (a / b) in GF(2).
 *
 * @param a The dividend binary sequence.
 * @param b The divisor binary sequence.
 * @return  The remainder of the division.
 */
std::deque<int> divisionRemainer(std::deque<int> a, std::deque<int> b);

/**
 * @brief Checks if a string is a valid binary number.
 *
 * This function checks whether a given string is a valid binary number
 * (contains only '0' and '1').
 *
 * @param str The string to check.
 * @return    True if the string is a valid binary number, false otherwise.
 */
bool binaryCheck(std::string str);

#endif // BINARY_OPERATIONS_HPP
