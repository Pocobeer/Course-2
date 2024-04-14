#pragma once
int comparisons_5 = 0;
int swaps_5 = 0;
// Функция для разделения массива по опорному элементу
int partition_2(std::vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    int pivot = arr[high]; // Опорный элемент
    int i = low - 1; // Индекс элемента, меньшего опорного
    auto start_time = std::chrono::high_resolution_clock::now(); // Запуск таймера
    for (int j = low; j <= high - 1; ++j) {
        comparisons_5++;
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            // Увеличиваем индекс меньшего элемента и меняем местами элементы
            ++i;
            swaps_5++;
            std::swap(arr[i], arr[j]);
        }
    }
    // Помещаем опорный элемент на правильное место
    swaps_5++;
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Функция быстрой сортировки
void quickSort_2(std::vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    std::stack<std::pair<int, int>> stack;
    stack.push({ low, high });

    while (!stack.empty()) {
        int start = stack.top().first;
        int end = stack.top().second;
        stack.pop();

        int pivotIndex = partition_2(arr, start, end, comparisons, swaps);

        // Если есть элементы слева от опорного, добавляем их в стек
        if (pivotIndex - 1 > start)
            stack.push({ start, pivotIndex - 1 });

        // Если есть элементы справа от опорного, добавляем их в стек
        if (pivotIndex + 1 < end)
            stack.push({ pivotIndex + 1, end });
    }
}