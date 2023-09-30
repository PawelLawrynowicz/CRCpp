#ifndef BINARY_OPERATIONS_HPP
#define BINARY_OPERATIONS_HPP

#include <cmath>
#include <deque>
#include <string>

std::deque<int> decimalToBinary(int decimal);
int binaryToDecimal(std::deque<int> binary);
std::deque<int> addZero(std::deque<int> &a, int c);
std::deque<int> precisionDecimalToBinary(int dec, int k);
std::deque<int> move_1_to_left(std::deque<int> a);
std::deque<int> move_1_to_right(std::deque<int> a);
int howManyOnes(std::deque<int> syndrome);
std::deque<int> divisionRemainer(std::deque<int> a, std::deque<int> b);
bool binaryCheck(std::string str);

#endif // BINARY_OPERATIONS_HPP
