#include "input_operations.hpp"

// Getting code word from keyboard
std::deque<int> getWord(int n) {
    std::deque<int> word;
    std::string input;
    std::cout << std::endl
              << "Please input codeword of length " << n
              << " in binary form: " << std::endl;
    std::cin >> input;
    while (input.length() != n) {
        std::cout << "The given codeword has wrong length, try again: "
                  << std::endl;
        input.clear();
        std::cin >> input;
    }
    bool pass = false;
    while (!pass) {
        for (int i = 0; i < input.length(); i++) {
            if (input[i] != '1' && input[i] != '0') {
                std::cout << "The codeword should be binary (only 1s and 0s): "
                          << std::endl;
                input.clear();
                std::cin >> input;
            } else
                pass = true;
        }
    }
    for (int i = 0; i < input.length(); i++) {
        word.push_back(input[i] - 48);
    }
    return word;
};
