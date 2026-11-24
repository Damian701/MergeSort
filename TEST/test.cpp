#include "pch.h"
#include <vector>
#include <cstdlib>
#include "../MergeSort/MergeSort.h"

template<typename T>
bool isSorted(const std::vector<T>& arr) {
    for (size_t i = 1; i < arr.size(); ++i) {
        if (arr[i - 1] > arr[i]) return false;
    }
    return true;
}

class MergeSortTest : public ::testing::Test {
protected:
    MergeSort<int> sorter;
};

TEST_F(MergeSortTest, AlreadySortedAscending) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, ReverseSorted) {
    std::vector<int> arr = { 5, 4, 3, 2, 1 };
    std::vector<int> expected = { 1, 2, 3, 4, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, RandomArray) {
    std::vector<int> arr = { 12, 4, 7, 2, 19, 1, 8 };
    sorter.sort(arr);
    EXPECT_TRUE(isSorted(arr));
}

TEST_F(MergeSortTest, OnlyNegativeNumbers) {
    std::vector<int> arr = { -5, -1, -9, -3, -7 };
    std::vector<int> expected = { -9, -7, -5, -3, -1 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, NegativeAndPositiveNumbers) {
    std::vector<int> arr = { -5, 3, 0, -2, 8, -1 };
    std::vector<int> expected = { -5, -2, -1, 0, 3, 8 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, EmptyArrayDoesNotThrow) {
    std::vector<int> arr = {};
    EXPECT_NO_THROW(sorter.sort(arr));
    EXPECT_TRUE(arr.empty());
}

TEST_F(MergeSortTest, SingleElement) {
    std::vector<int> arr = { 42 };
    std::vector<int> expected = { 42 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, WithDuplicates) {
    std::vector<int> arr = { 3, 1, 2, 3, 1, 5 };
    std::vector<int> expected = { 1, 1, 2, 3, 3, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, NegativeWithDuplicates) {
    std::vector<int> arr = { -2, -1, -2, -3, -1 };
    std::vector<int> expected = { -3, -2, -2, -1, -1 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, NegativePositiveAndDuplicates) {
    std::vector<int> arr = { -2, 5, -2, 0, 5, 0, -7 };
    std::vector<int> expected = { -7, -2, -2, 0, 0, 5, 5 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, TwoElementsAscending) {
    std::vector<int> arr = { 1, 2 };
    std::vector<int> expected = { 1, 2 };
    sorter.sort(arr);
    EXPECT_EQ(arr, expected);
}

TEST_F(MergeSortTest, LargeArray) {
    std::vector<int> arr(150);
    for (int i = 0; i < 150; ++i) {
        arr[i] = std::rand() % 1000;
    }
    sorter.sort(arr);
    EXPECT_TRUE(isSorted(arr));
}

TEST_F(MergeSortTest, LargeArrayMixed) {
    std::vector<int> arr(200);
    for (int i = 0; i < 200; ++i) {
        arr[i] = (std::rand() % 2000) - 1000;
    }
    arr[10] = 42; arr[11] = 42; arr[12] = 42;
    arr[100] = -100; arr[101] = -100;
    sorter.sort(arr);
    EXPECT_TRUE(isSorted(arr));
}