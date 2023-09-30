#include "matrix_operations.hpp"

// Returns generating matrix
std::deque<std::deque<int>> generateMatrix(int n, int k, int value, bool draw) {
    std::deque<std::deque<int>> gen;
    std::deque<int> row = precisionDecimalToBinary(value, n);
    gen.push_back(row);
    for (int i = 0; i < k - 1; i++) {
        row = move_1_to_left(row);
        gen.push_back(row);
    }
    if (draw) {
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n; j++) {
                std::cout << gen[i][j];
            }
            std::cout << std::endl;
        }
    }
    return gen;
}

// Calculating syndrome
std::deque<int> syndrom(std::deque<std::deque<int>> htMatrix,
                        std::deque<int> input, int n, int k) {
    std::deque<int> syndrom;

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
int calculate_d_min(std::deque<std::deque<int>> matrix, int n, int k) {
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

// Multiplying matrix
std::deque<int> multiplyMatrix(std::deque<int> a, std::deque<std::deque<int>> b,
                               int n, int k) {
    std::deque<int> result;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < k; j++) {
            sum ^= (a[j] && b[j][i]);
        }
        result.push_back(sum);
    }

    for (int i = 0; i < result.size(); i++) {
        std::cout << result[result.size() - 1 - i];
    }
    std::cout << ", ";
    return result;
}