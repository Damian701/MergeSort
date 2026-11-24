/**
 * @file MergeSort.h
 * @brief Definicja i implementacja szablonowej klasy MergeSort.
 */

#pragma once
#include <vector>

 /**
  * @class MergeSort
  * @brief Klasa szablonowa implementuj¹ca algorytm sortowania przez scalanie (Merge Sort).
  *
  * Algorytm dzia³a w oparciu o metodê "dziel i zwyciê¿aj", osi¹gaj¹c z³o¿onoœæ
  * obliczeniow¹ O(n log n) w ka¿dym przypadku.
  *
  * @tparam T Typ danych przechowywanych w sortowanym wektorze (np. int, double, float).
  */
template <typename T>
class MergeSort {
private:
    /**
     * @brief Scala dwie posortowane podtablice w jedn¹ posortowan¹ ca³oœæ.
     *
     * @param arr Referencja do sortowanego wektora.
     * @param left Indeks pocz¹tkowy lewej podtablicy.
     * @param mid Indeks koñcowy lewej podtablicy (œrodek).
     * @param right Indeks koñcowy prawej podtablicy.
     */
    void merge(std::vector<T>& arr, int left, int mid, int right) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        std::vector<T> L(n1);
        std::vector<T> R(n2);

        for (int i = 0; i < n1; ++i) L[i] = arr[left + i];
        for (int j = 0; j < n2; ++j) R[j] = arr[mid + 1 + j];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                arr[k] = L[i];
                i++;
            }
            else {
                arr[k] = R[j];
                j++;
            }
            k++;
        }

        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    /**
     * @brief Rekurencyjnie dzieli wektor na mniejsze podtablice i wywo³uje ich scalanie.
     *
     * @param arr Referencja do sortowanego wektora.
     * @param left Indeks pocz¹tkowy aktualnego zakresu.
     * @param right Indeks koñcowy aktualnego zakresu.
     */
    void sortRecursive(std::vector<T>& arr, int left, int right) {
        if (left >= right) return;
        int mid = left + (right - left) / 2;
        sortRecursive(arr, left, mid);
        sortRecursive(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }

public:
    /**
     * @brief Sortuje przekazany wektor rosn¹co.
     *
     * Metoda jest bezpieczna dla pustych wektorów (nie rzuca wyj¹tków).
     *
     * @param arr Referencja do wektora, który ma zostaæ posortowany.
     */
    void sort(std::vector<T>& arr) {
        if (arr.empty()) return;
        sortRecursive(arr, 0, static_cast<int>(arr.size()) - 1);
    }
};