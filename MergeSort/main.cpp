#include <iostream>
#include <vector>
#include "MergeSort.h"

int main() {
    MergeSort<int> intSorter;
    std::vector<int> intArr = { 12, 11, 13, 5, 6, 7 };
    intSorter.sort(intArr);

    std::cout << "Posortowane int: ";
    for (int i : intArr) std::cout << i << " ";
    std::cout << std::endl;

    MergeSort<double> doubleSorter;
    std::vector<double> doubleArr = { 3.14, 1.59, 2.65, 5.35, 8.97 };
    doubleSorter.sort(doubleArr);

    std::cout << "Posortowane double: ";
    for (double d : doubleArr) std::cout << d << " ";
    std::cout << std::endl;

    return 0;
}