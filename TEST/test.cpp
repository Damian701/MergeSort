#include "pch.h"
#include <vector>
#include "../MergeSort/MergeSort.h" // Zmieñ "Project1" na nazwê folderu g³ównego projektu

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