#pragma once
int comparisons_3 = 0;
int swaps_3 = 0;
void shakerSort(std::vector<int>& arr, int& comparisons_3, int& swaps_3) {
    bool swapped = true;
    int start = 0;
    int end = arr.size() - 1;
    auto start_time = std::chrono::high_resolution_clock::now(); // Запуск таймера
    while (swapped) {
        swapped = false;

        // Проход вперед
        for (int i = start; i < end; ++i) {
            comparisons_3++;
            if (arr[i] > arr[i + 1]) {
                swaps_3++;
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
                
            }
        }

        // Если нет обменов, массив уже отсортирован
        if (!swapped)
            break;

        // Уменьшаем область, так как самый большой элемент уже находится на конце
        --end;

        // Проход назад
        for (int i = end - 1; i >= start; --i) {
            comparisons_3++;
            if (arr[i] > arr[i + 1]) {
                swaps_3++;
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
               
            }
        }

        // Увеличиваем область, так как самый маленький элемент уже находится в начале
        ++start;
    }
    auto end_1 = std::chrono::high_resolution_clock::now(); // Остановка таймера
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_1 - start_time); // Вычисление времени выполнения в наносекундах
    std::cout << "Shaker sort" << "             " << comparisons_3 << "             " <<
        swaps_3 << "       " << duration.count() / std::pow(10, 9) << std::endl;
}
