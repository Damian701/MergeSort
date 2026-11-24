/**
 * @file main.cpp
 * @brief Program główny demonstrujący działanie szablonu klasy MergeSort.
 */

#include <iostream>
#include <vector>
#include "MergeSort.h"

 /**
  * @brief Punkt wejścia programu.
  *
  * Tworzy dwie instancje klasy MergeSort (dla typów int oraz double),
  * sortuje przykładowe tablice i wypisuje wyniki w konsoli.
  *
  * @return Kod zakończenia programu (0 oznacza poprawne wykonanie).
  */
int main() {
    MergeSort<int> intSorter;
    std::vector<int> intArr = { 38, 27, 43, 3, 9, 82, 10 };

    std::cout << "Przed sortowaniem (int): ";
    for (int v : intArr) std::cout << v << " ";
    std::cout << "\n";

    intSorter.sort(intArr);

    std::cout << "Po sortowaniu (int): ";
    for (int v : intArr) std::cout << v << " ";
    std::cout << "\n\n";

    MergeSort<double> doubleSorter;
    std::vector<double> doubleArr = { 3.14, 1.59, -2.65, 3.58, 9.79 };

    std::cout << "Przed sortowaniem (double): ";
    for (double v : doubleArr) std::cout << v << " ";
    std::cout << "\n";

    doubleSorter.sort(doubleArr);

    std::cout << "Po sortowaniu (double): ";
    for (double v : doubleArr) std::cout << v << " ";
    std::cout << "\n";

    return 0;
}