#include "binary_operations.hpp"

std::deque<int> decimalToBinary(int decimal) {
    std::deque<int> binary;

    for (int i = 0; decimal > 0; i++) {
        binary.push_front(decimal % 2);
        decimal = decimal / 2;
    }
    return binary;
}

int binaryToDecimal(std::deque<int> binary) {
    int decimal = 0;
    int j = binary.size();
    for (int i = 0; i < j; i++) {
        if (binary.back() == 1) {
            decimal += pow(2, i);
        }
        binary.pop_back();
    }
    return decimal;
}

std::deque<int> addZero(std::deque<int> &a, int c) {
    for (int i = 0; i < c; i++) {
        a.push_front(0);
    }
    return a;
}

std::deque<int> precisionDecimalToBinary(int dec, int k) {
    std::deque<int> bin;
    std::deque<int> temp;
    for (int i = 0; i < k; i++) {
        temp.push_back(0);
    }
    int binLength = 0;
    for (int i = 0; dec > 0; i++) {
        bin.push_front(dec % 2);
        dec = dec / 2;
        binLength++;
    }
    for (int i = 0; i < binLength; i++) {
        temp[abs(i - k + 1)] = bin[binLength - i - 1];
    }
    return temp;
}

std::deque<int> move_1_to_left(std::deque<int> a) {
    int temp = a.front();
    a.pop_front();
    a.push_back(temp);
    return a;
}

std::deque<int> move_1_to_right(std::deque<int> a) {
    int temp = a.back();
    a.pop_back();
    a.push_front(temp);
    return a;
}
int howManyOnes(std::deque<int> syndrome) {
    int one = 0;
    for (int i = 0; i < syndrome.size(); i++) {
        if (syndrome[i] == 1)
            one++;
    }
    return one;
}

std::deque<int> divisionRemainer(std::deque<int> a, std::deque<int> b) {
    std::deque<int> result;
    while (b.size() <= a.size() && a.size() != 0) {
        if (a[0] == '1' || a[0] == 1) {
            a.pop_front();
            for (int i = 0; i < b.size() - 1; i++) {
                a[i] ^= b[i + 1];
            }
            if (a.size() > 0) {
                result.push_back(1);
            }
        } else {
            a.pop_front();
            result.push_back(0);
        }
    }
    return a;
}

bool binaryCheck(std::string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '1' && str[i] != '0') {
            return false;
        }
    }
    return true;
}