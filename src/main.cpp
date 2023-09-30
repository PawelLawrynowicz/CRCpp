#include <deque>
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void clear_terminal() { std::cout << "\033[2J\033[1;1H"; }
// decimal to binary conversion
deque<int> decimalToBinary(int decimal) {
    deque<int> binary;

    for (int i = 0; decimal > 0; i++) {
        binary.push_front(decimal % 2);
        decimal = decimal / 2;
    }
    return binary;
}

// binary to decimal conversion
int binaryToDecimal(deque<int> binary) {
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

// puts the necessary zeroes on the beginning of the number
deque<int> addZero(deque<int> &a, int c) {
    for (int i = 0; i < c; i++) {
        a.push_front(0);
    }
    return a;
}

// Does what two above does, but at once
deque<int> precisionDecimalToBinary(int dec, int k) {
    deque<int> bin;
    deque<int> temp;
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

// Shifts the bits to the left, most significant bit becomes least significant
deque<int> move_1_to_left(deque<int> a) {
    int temp = a.front();
    a.pop_front();
    a.push_back(temp);
    return a;
}

// Shifts the bits to the right, least significant bit becomes most significant
deque<int> move_1_to_right(deque<int> a) {
    int temp = a.back();
    a.pop_back();
    a.push_front(temp);
    return a;
}

// Returns generating matrix
deque<deque<int>> generateMatrix(int n, int k, int value, bool draw = true) {
    deque<deque<int>> gen;
    deque<int> row = precisionDecimalToBinary(value, n);
    gen.push_back(row);
    for (int i = 0; i < k - 1; i++) {
        row = move_1_to_left(row);
        gen.push_back(row);
    }
    if (draw) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                cout << gen[i][j];
            }
            cout << endl;
        }
    }
    return gen;
}

// Counts division remainder and result in CG(2)
deque<int> divisionRemainer(deque<int> a, deque<int> b) {
    deque<int> result;
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

// Counts ones in a binary number
int howManyOnes(deque<int> syndrom) {
    int one = 0;
    for (int i = 0; i < syndrom.size(); i++) {
        if (syndrom[i] == 1)
            one++;
    }
    return one;
}

// Calculating syndrome
deque<int> syndrom(deque<deque<int>> htMatrix, deque<int> input, int n, int k) {
    deque<int> syndrom;

    for (int i = 0; i < n - k; i++) {
        int value = 0;
        for (int j = 0; j < n; j++) {
            value ^= (input[j] && htMatrix[j][i]);
        }
        syndrom.push_back(value);
    }
    return syndrom;
}

// Counting d_minimum
int calculate_d_min(deque<deque<int>> matrix, int n, int k) {
    int d_min;
    int counter = 0;
    for (int i = 0; i < n - k; i++) {
        if (matrix[0][i] == 1)
            counter++;
    }
    d_min = counter + 1;
    for (int i = 1; i < k; i++) {
        counter = 0;
        for (int j = 0; j < n - k; j++) {
            if (matrix[i][j] == 1)
                counter++;
        }
        if (counter < d_min)
            d_min = counter + 1;
    }
    return d_min;
}

// Getting code word from keyboard
deque<int> getWord(int n) {
    deque<int> word;
    string input;
    cout << endl
         << "Please input codeword of length " << n
         << " in binary form: " << endl;
    cin >> input;
    while (input.length() != n) {
        cout << "The given codeword has wrong length, try again: " << endl;
        input.clear();
        cin >> input;
    }
    bool pass = false;
    while (!pass) {
        for (int i = 0; i < input.length(); i++) {
            if (input[i] != '1' && input[i] != '0') {
                cout << "The codeword should be binary (only 1s and 0s): "
                     << endl;
                input.clear();
                cin >> input;
            } else
                pass = true;
        }
    }
    for (int i = 0; i < input.length(); i++) {
        word.push_back(input[i] - 48);
    }
    return word;
};

// Multiplying matrix
deque<int> multiplyMatrix(deque<int> a, deque<deque<int>> b, int n, int k) {
    deque<int> result;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < k; j++) {
            sum ^= (a[j] && b[j][i]);
        }
        result.push_back(sum);
    }

    for (int i = 0; i < result.size(); i++) {
        cout << result[result.size() - 1 - i];
    }
    cout << ", ";
    return result;
}

// Prints all code words
void printCodeWords(deque<deque<int>> gen, int n, int k) {
    deque<int> codeWord;
    for (int c = 0; c < pow(2, 8); c++) {
        multiplyMatrix(precisionDecimalToBinary(c, k), gen, n, k);
    }
    cout << endl;
}

// For a given codeword, checks for error and if it can be corrected.
// Error is corrected if possible.
void correct(deque<deque<int>> htMatrix, int n, int k) {
    int t = (calculate_d_min(htMatrix, n, k) - 1) / 2;
    int tilt = 0;
    deque<int> input = getWord(n);
    deque<int> syn = syndrom(htMatrix, input, n, k);

    cout << endl << "Syndrome before shift: ";
    for (int i = 0; i < syn.size(); i++) {
        cout << syn[i];
    }
    cout << endl;
    if (howManyOnes(syndrom(htMatrix, input, n, k)) == 0) {
        cout << "Given string is a codeword!" << endl;
    } else {
        while (howManyOnes(syndrom(htMatrix, input, n, k)) > t) {
            tilt++;
            input = move_1_to_left(input);
            syn = syndrom(htMatrix, input, n, k);
            cout << "Syndrome after " << tilt << " shift: ";
            for (int i = 0; i < syn.size(); i++) {
                cout << syn[i];
            }
            cout << endl;
            if (tilt == n - 1) {
                cout << endl << "Error cannot be corrected" << endl;
                return;
            }
        }
        addZero(syn, k);
        deque<int> ans;
        for (int i = 0; i < input.size(); i++) {
            ans.push_back((input[i] ^ syn[i]));
        }
        for (int i = 0; i < tilt; i++) {
            ans = move_1_to_right(ans);
        }
        cout << endl << "After error correction: ";
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i];
        }
    }
}

// Counts and prints u_i matrix, generating matrix, systematic matrix, corrected
// matrix and prints code properties
deque<deque<int>> controlMatrix(int n, int k, int gx, bool draw) {
    deque<deque<int>> uMatrix;
    deque<deque<int>> gMatrix;
    deque<deque<int>> htMatrix;

    for (int i = n - 1; i >= n - k; i--) {
        int xi = 0;
        xi = 1 << i;
        uMatrix.push_back(
            divisionRemainer(decimalToBinary(xi), decimalToBinary(gx)));
    }

    gMatrix = uMatrix;
    for (int i = 0; i < k; i++) {
        for (int j = k - 1; j > -1; j--) {
            if (j == i)
                gMatrix[i].push_front(1);
            else
                gMatrix[i].push_front(0);
        }
    }

    htMatrix = uMatrix;
    deque<int> tempMatrix;
    for (int i = 0; i < n - k; i++) {
        for (int j = 0; j < n - k; j++) {
            if (i == j)
                tempMatrix.push_back(1);
            else
                tempMatrix.push_back(0);
        }
        htMatrix.push_back(tempMatrix);
        tempMatrix.clear();
    }

    if (draw) {
        cout << endl << "Systematic generator matrix Gs: " << endl << endl;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                cout << gMatrix[i][j];
            }
            cout << endl;
        }

        cout << endl << "Control matrix H^T: " << endl << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - k; j++) {
                cout << htMatrix[i][j];
            }
            cout << endl;
        }
        int d_min = calculate_d_min(htMatrix, n, k);
        int e = (d_min - 1);
        int t = (d_min - 1) / 2;
        cout << endl << "Minimum distance: " << d_min << endl;
        cout << "Error-detecting capability: " << e << endl;
        cout << "Error-correcting capability: " << t << endl;
    }

    return htMatrix;
}

// Checking code correctness, matrix division
bool check(int n, deque<int> gen) {

    deque<int> a;
    for (int i = 0; i < n + 1; i++) {
        if (i == 0 || i == n)
            a.push_back(1);
        else
            a.push_back(0);
    }
    deque<int> result;
    result = divisionRemainer(a, gen);
    cout << endl
         << "Remainder x^" << n
         << " + x^0 of division by generator polynomial: ";
    int ones = howManyOnes(gen);
    for (int i = 0; i < result.size(); i++)
        cout << result[i];
    if (binaryToDecimal(result) == 0) {
        cout << endl << "The entered parameters are correct.";
        return true;
    }
    return false;
}

// Checking if given string is a binary number
bool binaryCheck(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] != '1' && str[i] != '0') {
            return false;
        }
    }
    return true;
}

// Adding custom code parameters
void getNewPoly(int &n, int &k, int &value) {
    deque<int> temp;
    string str;

    cout << "Input new n value: ";
    cin >> n;

    cout << "Input new k value: ";
    cin >> k;

    cout << "Input new generator polynomial (as binary number): ";
    cin >> str;
    while (!binaryCheck(str)) {
        cout << "The polynomial should be a binary number (only 1 and 0), try "
                "again:";
        cin >> str;
    }
    for (int i = 0; i < str.length(); i++) {
        temp.push_back(str[i] - 48);
    }
    value = binaryToDecimal(temp);
}

// Printing menu
void printPoly(deque<int> poly) {
    int ones = howManyOnes(poly);
    for (int i = 0; i < poly.size(); i++) {
        if (poly[i] == 1) {
            cout << "x^" << poly.size() - i - 1;
            ones--;
            if (ones > 0)
                cout << "+";
        }
    }
}
// more menu printing
void printPlainText(int n, int k, deque<int> poly) {
    cout << "Current code:(" << n << ", " << k << ") ";
    int ones = howManyOnes(poly);
    for (int i = 0; i < poly.size(); i++) {
        if (poly[i] == 1) {
            cout << poly.size() - i - 1;
            ones--;
            if (ones > 0)
                cout << " ";
        }
    }
}

// menu function
void mainMenu(int n = 18, int k = 8, int gx = 1533) {
    clear_terminal();
    cout << "-- Cyclic coder --" << endl << endl;
    printPlainText(n, k, decimalToBinary(gx));
    cout << endl << endl;
    cout << "Generator polynomial: ";
    printPoly(decimalToBinary(gx));
    cout << endl << endl;
    cout << "MENU: " << endl;
    cout << "1. Generator matrix" << endl;
    cout << "2. Systematic generator matrix, control matrix, minimum distance, "
            "Error-detecting and correction capability"
         << endl;
    cout << "3. Codeword table" << endl;
    cout << "4. Detection and correction of errors" << endl;
    cout
        << "5. Checking the correctness with the method of dividing polynomials"
        << endl;
    cout << "6. Change code parameters" << endl;
    cout << "0. Exit program" << endl;
}

// more menu function
void optMenu() {
    int n = 18;    // 18
    int k = 8;     // 8
    int gx = 1533; // 1533
    while (1) {
        switch (getchar()) {
        case '1':
            clear_terminal();
            mainMenu(n, k, gx);
            cout << endl;
            generateMatrix(n, k, gx);
            break;
        case '2':
            clear_terminal();
            mainMenu(n, k, gx);
            controlMatrix(n, k, gx, true);
            break;
        case '3':
            clear_terminal();
            mainMenu(n, k, gx);
            printCodeWords(generateMatrix(n, k, gx, false), n, k);
            break;
        case '4':
            clear_terminal();
            mainMenu(n, k, gx);
            correct(controlMatrix(n, k, gx, false), n, k);
            break;
        case '5':
            clear_terminal();
            mainMenu(n, k, gx);
            check(n, decimalToBinary(gx));
            break;
        case '6': {
            clear_terminal();
            getNewPoly(n, k, gx);
            bool correct = check(n, decimalToBinary(gx));
            int chances = 10;
            while (!correct) {
                chances--;
                cout << "Input data is not correct, chances left: (" << chances
                     << ")" << endl;
                getNewPoly(n, k, gx);
                correct = check(n, decimalToBinary(gx));
                if (chances == 0) {
                    cout << "You ran out of chances ... exiting" << endl;
                    getchar();
                    exit(0);
                }
            }
            getchar();
            mainMenu(n, k, gx);
            break;
        }
        case '0':
            exit(0);
            break;
        default:
            clear_terminal();
            mainMenu(n, k, gx);
            break;
        }
    }
}
void menu() {
    mainMenu();
    optMenu();
}

int main() {

    menu();

    return 0;
}
