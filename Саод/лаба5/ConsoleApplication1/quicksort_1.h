#pragma once
int comparisons_4 = 0;
int swaps_4 = 0;
// Функция для разделения массива по опорному элементу
int partition_1(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // Опорный элемент
    int i = low - 1; // Индекс элемента, меньшего опорного
    auto start_time = std::chrono::high_resolution_clock::now(); // Запуск таймера
    for (int j = low; j <= high - 1; ++j) {
        comparisons_4++;
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            // Увеличиваем индекс меньшего элемента и меняем местами элементы
            ++i;
            swaps_4++;
            std::swap(arr[i], arr[j]);
        }
    }
    // Помещаем опорный элемент на правильное место
    swaps_4++;
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// Функция быстрой сортировки
void quickSort_1(std::vector<int>& arr, int low, int high) {
   
    if (low < high) {
        // Разделяем массив и получаем индекс опорного элемента
        int pi = partition_1(arr, low, high);

        // Рекурсивно сортируем элементы до опорного элемента и после него
        quickSort_1(arr, low, pi - 1);
        quickSort_1(arr, pi + 1, high);
    }
    
    
}

