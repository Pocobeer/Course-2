#pragma once
int comparisons_7 = 0;
int swaps_7 = 0;
void countingSort(std::vector<int>& arr) {
    auto start_time = std::chrono::high_resolution_clock::now(); // Запуск таймера

    int maxElement = *std::max_element(arr.begin(), arr.end());
    int minElement = *std::min_element(arr.begin(), arr.end());
    int range = maxElement - minElement + 1;

    // Создаем временный вектор для подсчета вхождений каждого элемента
    std::vector<int> count(range, 0);

    // Подсчитываем вхождения каждого элемента
    for (int num : arr) {
        ++count[num - minElement];
    }

    // Строим отсортированный массив из подсчетов
    int index = 0;
    for (int i = 0; i < range; ++i) {
        for (int j = 0; j < count[i]; ++j) {
            arr[index++] = i + minElement;
            swaps_7++;
        }
    }
    auto end_time = std::chrono::high_resolution_clock::now(); // Остановка таймера
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_time - start_time); // Вычисление времени выполнения в наносекундах
    std::cout << "Counting sort" << "           " << comparisons_7 << "                   " << swaps_7 << "          " << duration.count() / std::pow(10, 9) << std::endl;
}
