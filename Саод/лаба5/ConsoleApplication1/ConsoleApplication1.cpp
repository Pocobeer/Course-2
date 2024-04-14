#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <chrono>
#include <random>
#include"Insertion_sort.h"
#include"binaryinsertionsort.h"
#include"shaker_sort.h"
#include"quicksort_1.h"
#include"quicksort_2.h"
#include"selectionsort.h"
#include"counting_sort.h"
#include"naturalmergesort.h"
#include"mergeSort.h"
using namespace std;
int comparisons_9 = 0;
int swaps_9 = 0;
// Функция для слияния двух отсортированных списков
vector<int> merge_2(const vector<int>& left, const vector<int>& right, int& comparisons, int& swaps) {
    vector<int> merged;
    int leftSize = left.size();
    int rightSize = right.size();
    int i = 0, j = 0;

    // Слияние элементов из двух списков
    while (i < leftSize && j < rightSize) {
        comparisons_9++;
        if (left[i] <= right[j]) {
            merged.push_back(left[i]);
            ++i;
        }
        else {
            merged.push_back(right[j]);
            ++j;
        }
    }

    // Добавление оставшихся элементов из левого списка
    while (i < leftSize) {
        merged.push_back(left[i]);
        ++i;
        swaps_9++;
    }

    // Добавление оставшихся элементов из правого списка
    while (j < rightSize) {
        merged.push_back(right[j]);
        ++j;
        swaps_9++;
    }

    return merged;
}

// Функция для сортировки слиянием
std::vector<int> mergeSort(const std::vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();

    // Базовый случай: если список пустой или содержит один элемент, он уже отсортирован
    if (n <= 1)
        return arr;

    // Разделение списка на два подсписка
    int mid = n / 2;
    std::vector<int> left(arr.begin(), arr.begin() + mid);
    std::vector<int> right(arr.begin() + mid, arr.end());

    // Рекурсивное применение сортировки слиянием к двум подспискам
    left = mergeSort(left, comparisons, swaps);
    right = mergeSort(right, comparisons, swaps);

    // Слияние отсортированных подсписков
    return merge_2(left, right, comparisons, swaps);
}
vector<int> generateRandomVector(int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 1000); // Генерация случайных чисел от 1 до 100

    std::vector<int> randomVector(size);
    for (int i = 0; i < size; ++i) {
        randomVector[i] = dis(gen);
    }
    return randomVector;
}

int main() {
    int size = 10000;
    int test_count = 1000;
    vector<int> original_arr;
    for (int i = 2000; i <= size; i += 2000) {
        original_arr.clear();
		original_arr = generateRandomVector(i);
        cout << "N = " << i << endl;
        cout << "Sort method: " << "          " << "Compressions: " << "       " <<
            "Swaps: " << "        " << "Time: " << endl;

        vector<int> arr_1 = original_arr;
        vector<int> arr_2 = original_arr;
        vector<int> arr_3 = original_arr;
        vector<int> arr_4 = original_arr;
        vector<int> arr_5 = original_arr;
        vector<int> arr_6 = original_arr;
        vector<int> arr_7 = original_arr;
        vector<int> arr_8 = original_arr;
        vector<int> arr_9 = original_arr;
        insertionSort(arr_1, comparisons_1, swaps_1);
        binaryInsertionSort(arr_2, comparisons_2, swaps_2);
        //vector<int> arr_test = { 898,52,96,232,85,3,3,5,6 };
        shakerSort(arr_3, comparisons_3, swaps_3);
        int n = original_arr.size();
        auto start_time_1 = std::chrono::high_resolution_clock::now(); // Запуск таймера
        quickSort_1(arr_4, 0, n - 1);
        auto end_time_1 = std::chrono::high_resolution_clock::now(); // Остановка таймера
        auto duration_1 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_1 - start_time_1); // Вычисление времени выполнения в наносекундах
        std::cout << "Quick sort(rec)" << "         " << comparisons_4 << "               " <<
            swaps_4 << "         " << duration_1.count() / std::pow(10, 9) << std::endl;
        auto start_time_2 = std::chrono::high_resolution_clock::now(); // Запуск таймера
        quickSort_2(arr_5, 0, n - 1, comparisons_5, swaps_5);
        auto end_time_2 = std::chrono::high_resolution_clock::now(); // Остановка таймера
        auto duration_2 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_2 - start_time_2); // Вычисление времени выполнения в наносекундах
        std::cout << "Quick sort(iter)" << "        " << comparisons_5 << "               " <<
            swaps_5 << "         " << duration_2.count() / std::pow(10, 9) << std::endl;
        selectionSort(arr_6, comparisons_6, swaps_6);

        countingSort(arr_7);
        auto start_time_3 = std::chrono::high_resolution_clock::now(); // Запуск таймера
        naturalMergeSort(arr_8, comparisons_8, swaps_8);
        auto end_time_3 = std::chrono::high_resolution_clock::now(); // Остановка таймера
        auto duration_3 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_3 - start_time_3); // Вычисление времени выполнения в наносекундах

        std::cout << "Natural merge sort" << "      " << comparisons_8 << "                " <<
            swaps_8 << "          " << duration_3.count() / std::pow(10, 9) << std::endl;
        auto start_time_4 = std::chrono::high_resolution_clock::now(); // Запуск таймера
        vector<int> sortedArr = mergeSort(arr_9, comparisons_9, swaps_9);
        auto end_time_4 = std::chrono::high_resolution_clock::now(); // Остановка таймера
        auto duration_4 = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time_4 - start_time_4); // Вычисление времени выполнения в наносекундах
        std::cout << "Second merge sort" << "       " << comparisons_9 << "               " <<
            swaps_9 << "          " << duration_4.count() / std::pow(10, 9) << std::endl;
        //comparisons_1, comparisons_2, comparisons_3, comparisons_4, comparisons_5, comparisons_6 = 0;
        //comparisons_7, comparisons_8, comparisons_9 = 0;
        //swaps_1, swaps_2, swaps_3, swaps_4, swaps_5, swaps_6, swaps_7, swaps_8, swaps_9 = 0;
    }
    return 0;
}
