#include "binary_operations.hpp"
#include <deque>
#include <gtest/gtest.h>

TEST(CyclicCodeTest, DecimalToBinaryTest) {
    // Test decimal to binary conversion
    std::deque<int> binary = decimalToBinary(5);
    ASSERT_EQ(binary.size(), 3);
    ASSERT_EQ(binary[0], 1);
    ASSERT_EQ(binary[1], 0);
    ASSERT_EQ(binary[2], 1);
}

TEST(DecimalToBinaryTest, Test5) {
    // Test decimal to binary conversion
    std::deque<int> binary = decimalToBinary(5);
    ASSERT_EQ(binary.size(), 3);
    ASSERT_EQ(binary[0], 1);
    ASSERT_EQ(binary[1], 0);
    ASSERT_EQ(binary[2], 1);
}

TEST(BinaryToDecimalTest, Test5) {
    // Test binary to decimal conversion
    std::deque<int> binary = {1, 0, 1};
    int decimal = binaryToDecimal(binary);
    ASSERT_EQ(decimal, 5);
}

TEST(AddZeroTest, Test5) {
    // Test adding zeroes to the beginning of a binary sequence
    std::deque<int> binary = {1, 0, 1};
    std::deque<int> result = addZero(binary, 2);
    ASSERT_EQ(result.size(), 5);
    ASSERT_EQ(result[0], 0);
    ASSERT_EQ(result[1], 0);
    ASSERT_EQ(result[2], 1);
    ASSERT_EQ(result[3], 0);
    ASSERT_EQ(result[4], 1);
}

TEST(PrecisionDecimalToBinaryTest, Test5WithPrecision4) {
    // Test precisionDecimalToBinary
    std::deque<int> binary = precisionDecimalToBinary(5, 4);
    ASSERT_EQ(binary.size(), 4);
    ASSERT_EQ(binary[0], 0);
    ASSERT_EQ(binary[1], 1);
    ASSERT_EQ(binary[2], 0);
    ASSERT_EQ(binary[3], 1);
}

TEST(MoveOneToLeftTest, Test5) {
    // Test move_1_to_left
    std::deque<int> binary = {1, 0, 1};
    std::deque<int> result = move_1_to_left(binary);
    ASSERT_EQ(result.size(), binary.size());
    ASSERT_EQ(result[0], 0);
    ASSERT_EQ(result[1], 1);
    ASSERT_EQ(result[2], 1);
}

TEST(MoveOneToRightTest, Test5) {
    // Test move_1_to_right
    std::deque<int> binary = {1, 0, 1};
    std::deque<int> result = move_1_to_right(binary);
    ASSERT_EQ(result.size(), binary.size());
    ASSERT_EQ(result[0], 1);
    ASSERT_EQ(result[1], 1);
    ASSERT_EQ(result[2], 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}