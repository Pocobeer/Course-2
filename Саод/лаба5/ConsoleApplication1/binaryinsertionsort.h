#pragma once
int comparisons_2 = 0;
int swaps_2 = 0;
// Функция для бинарного поиска места вставки элемента в упорядоченном массиве
int binarySearch(const std::vector<int>& arr, int key, int low, int high, int& comparisons_2) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        comparisons_2++;
        if (arr[mid] == key)
            return mid;
        else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}

// Сортировка бинарными вставками
void binaryInsertionSort(std::vector<int>& arr, int& comparisons_2, int& swaps_2) {
    int n = arr.size();
    auto start = std::chrono::high_resolution_clock::now(); // Запуск таймера
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        // Используем бинарный поиск для нахождения позиции вставки
        int j = binarySearch(arr, key, 0, i - 1, comparisons_2);
        // Перемещаем все элементы с позиции j до i на одну позицию вправо
        for (int k = i - 1; k >= j; --k) {
            arr[k + 1] = arr[k];
            swaps_2++;
        }
        // Вставляем key на найденную позицию
        arr[j] = key;
    }
    auto end = std::chrono::high_resolution_clock::now(); // Остановка таймера
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start); // Вычисление времени выполнения в наносекундах
    std::cout << "Binary Insertion sort" << "   " << comparisons_2 << "               " <<
        swaps_2 << "       " << duration.count() / std::pow(10, 9)  << std::endl;
}