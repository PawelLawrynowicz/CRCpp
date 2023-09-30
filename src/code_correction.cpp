#include "code_correction.hpp"

// For a given codeword, checks for error and if it can be corrected.
// Error is corrected if possible.
void correct(std::deque<std::deque<int>> htMatrix, int n, int k) {
    int t = (calculate_d_min(htMatrix, n, k) - 1) / 2;
    int tilt = 0;
    std::deque<int> input = getWord(n);
    std::deque<int> syn = syndrom(htMatrix, input, n, k);

    std::cout << std::endl << "Syndrome before shift: ";
    for (int i = 0; i < syn.size(); i++) {
        std::cout << syn[i];
    }
    std::cout << std::endl;
    if (howManyOnes(syndrom(htMatrix, input, n, k)) == 0) {
        std::cout << "Given string is a codeword!" << std::endl;
    } else {
        while (howManyOnes(syndrom(htMatrix, input, n, k)) > t) {
            tilt++;
            input = move_1_to_left(input);
            syn = syndrom(htMatrix, input, n, k);
            std::cout << "Syndrome after " << tilt << " shift: ";
            for (int i = 0; i < syn.size(); i++) {
                std::cout << syn[i];
            }
            std::cout << std::endl;
            if (tilt == n - 1) {
                std::cout << std::endl
                          << "Error cannot be corrected" << std::endl;
                return;
            }
        }
        addZero(syn, k);
        std::deque<int> ans;
        for (int i = 0; i < input.size(); i++) {
            ans.push_back((input[i] ^ syn[i]));
        }
        for (int i = 0; i < tilt; i++) {
            ans = move_1_to_right(ans);
        }
        std::cout << std::endl << "After error correction: ";
        for (int i = 0; i < ans.size(); i++) {
            std::cout << ans[i];
        }
    }
}

// Counts and prints u_i matrix, generating matrix, systematic matrix, corrected
// matrix and prints code properties
std::deque<std::deque<int>> controlMatrix(int n, int k, int gx, bool draw) {
    std::deque<std::deque<int>> uMatrix;
    std::deque<std::deque<int>> gMatrix;
    std::deque<std::deque<int>> htMatrix;

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
    std::deque<int> tempMatrix;
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
        std::cout << std::endl
                  << "Systematic generator matrix Gs: " << std::endl
                  << std::endl;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << gMatrix[i][j];
            }
            std::cout << std::endl;
        }

        std::cout << std::endl
                  << "Control matrix H^T: " << std::endl
                  << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - k; j++) {
                std::cout << htMatrix[i][j];
            }
            std::cout << std::endl;
        }
        int d_min = calculate_d_min(htMatrix, n, k);
        int e = (d_min - 1);
        int t = (d_min - 1) / 2;
        std::cout << std::endl << "Minimum distance: " << d_min << std::endl;
        std::cout << "Error-detecting capability: " << e << std::endl;
        std::cout << "Error-correcting capability: " << t << std::endl;
    }

    return htMatrix;
}

// Checking code correctness, matrix division
bool check(int n, std::deque<int> gen) {

    std::deque<int> a;
    for (int i = 0; i < n + 1; i++) {
        if (i == 0 || i == n)
            a.push_back(1);
        else
            a.push_back(0);
    }
    std::deque<int> result;
    result = divisionRemainer(a, gen);
    std::cout << std::endl
              << "Remainder x^" << n
              << " + x^0 of division by generator polynomial: ";
    int ones = howManyOnes(gen);
    for (int i = 0; i < result.size(); i++)
        std::cout << result[i];
    if (binaryToDecimal(result) == 0) {
        std::cout << std::endl << "The entered parameters are correct.";
        return true;
    }
    return false;
}