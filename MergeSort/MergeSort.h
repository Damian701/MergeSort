#pragma once
#include <vector>

template <typename T>
class MergeSort {
public:
    void sort(std::vector<T>& arr);
private:
    void merge(std::vector<T>& arr, int left, int mid, int right);
    void mergeSort(std::vector<T>& arr, int left, int right);
};
