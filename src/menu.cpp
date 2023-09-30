#include "menu.hpp"

// Clears terminal window
void clear_terminal() { std::cout << "\033[2J\033[1;1H"; }

// Prints all code words
void printCodeWords(std::deque<std::deque<int>> gen, int n, int k) {
    std::deque<int> codeWord;
    for (int c = 0; c < pow(2, 8); c++) {
        multiplyMatrix(precisionDecimalToBinary(c, k), gen, n, k);
    }
    std::cout << std::endl;
}

// Printing polynominal
void printPoly(std::deque<int> poly) {
    int ones = howManyOnes(poly);
    for (int i = 0; i < poly.size(); i++) {
        if (poly[i] == 1) {
            std::cout << "x^" << poly.size() - i - 1;
            ones--;
            if (ones > 0)
                std::cout << "+";
        }
    }
}

// Printing currect code in plaintext
void printPlainText(int n, int k, std::deque<int> poly) {
    std::cout << "Current code:(" << n << ", " << k << ") ";
    int ones = howManyOnes(poly);
    for (int i = 0; i < poly.size(); i++) {
        if (poly[i] == 1) {
            std::cout << poly.size() - i - 1;
            ones--;
            if (ones > 0)
                std::cout << " ";
        }
    }
}

// Adding custom code parameters
void getNewPoly(int &n, int &k, int &value) {
    std::deque<int> temp;
    std::string str;

    std::cout << "Input new n value: ";
    std::cin >> n;

    std::cout << "Input new k value: ";
    std::cin >> k;

    std::cout << "Input new generator polynomial (as binary number): ";
    std::cin >> str;
    while (!binaryCheck(str)) {
        std::cout
            << "The polynomial should be a binary number (only 1 and 0), try "
               "again:";
        std::cin >> str;
    }
    for (int i = 0; i < str.length(); i++) {
        temp.push_back(str[i] - 48);
    }
    value = binaryToDecimal(temp);
}

// Printing menu
void initMenu(int n, int k, int gx) {
    clear_terminal();
    std::cout << "-- Cyclic coder --" << std::endl << std::endl;
    printPlainText(n, k, decimalToBinary(gx));
    std::cout << std::endl << std::endl;
    std::cout << "Generator polynomial: ";
    printPoly(decimalToBinary(gx));
    std::cout << std::endl << std::endl;
    std::cout << "MENU: " << std::endl;
    std::cout << "1. Generator matrix" << std::endl;
    std::cout
        << "2. Systematic generator matrix, control matrix, minimum distance, "
           "Error-detecting and correction capability"
        << std::endl;
    std::cout << "3. Codeword table" << std::endl;
    std::cout << "4. Detection and correction of errors" << std::endl;
    std::cout
        << "5. Checking the correctness with the method of dividing polynomials"
        << std::endl;
    std::cout << "6. Change code parameters" << std::endl;
    std::cout << "0. Exit program" << std::endl;
}

// Handling menu options
void optMenu() {
    int n = 18;    // 18
    int k = 8;     // 8
    int gx = 1533; // 1533
    while (1) {
        switch (getchar()) {
        case '1':
            clear_terminal();
            initMenu(n, k, gx);
            std::cout << std::endl;
            generateMatrix(n, k, gx);
            break;
        case '2':
            clear_terminal();
            initMenu(n, k, gx);
            controlMatrix(n, k, gx, true);
            break;
        case '3':
            clear_terminal();
            initMenu(n, k, gx);
            printCodeWords(generateMatrix(n, k, gx, false), n, k);
            break;
        case '4':
            clear_terminal();
            initMenu(n, k, gx);
            correct(controlMatrix(n, k, gx, false), n, k);
            break;
        case '5':
            clear_terminal();
            initMenu(n, k, gx);
            check(n, decimalToBinary(gx));
            break;
        case '6': {
            clear_terminal();
            getNewPoly(n, k, gx);
            bool correct = check(n, decimalToBinary(gx));
            int chances = 10;
            while (!correct) {
                chances--;
                std::cout << "Input data is not correct, chances left: ("
                          << chances << ")" << std::endl;
                getNewPoly(n, k, gx);
                correct = check(n, decimalToBinary(gx));
                if (chances == 0) {
                    std::cout << "You ran out of chances ... exiting"
                              << std::endl;
                    getchar();
                    exit(0);
                }
            }
            getchar();
            initMenu(n, k, gx);
            break;
        }
        case '0':
            exit(0);
            break;
        default:
            clear_terminal();
            initMenu(n, k, gx);
            break;
        }
    }
}

void menu() {
    initMenu();
    optMenu();
}