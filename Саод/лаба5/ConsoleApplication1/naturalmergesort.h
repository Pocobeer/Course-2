#pragma once
int comparisons_8 = 0;
int swaps_8 = 0;
// Функция для слияния двух соседних отсортированных подсписков
void merge_1(std::vector<int>&arr, int left, int mid, int right, int& comparisons, int& swaps) {
    int n1 = mid - left + 1; // Размер первого подсписка
    int n2 = right - mid;    // Размер второго подсписка

    // Создаем временные векторы для хранения элементов подсписков
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // Копируем данные во временные векторы
    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // Инициализируем индексы для обоих временных векторов и исходного массива
    int i = 0, j = 0, k = left;

    // Слияние временных векторов обратно в исходный массив
    while (i < n1 && j < n2) {
        comparisons_8++;
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            ++i;
        }
        else {
            arr[k] = rightArr[j];
            ++j;
        }
        ++k;
    }

    // Копируем оставшиеся элементы leftArr (если они есть) обратно в arr
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
        swaps_8++;
    }

    // Копируем оставшиеся элементы rightArr (если они есть) обратно в arr
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
        swaps_8++;
    }
    
}

// Функция для сортировки естественным двухпутевым слиянием
void naturalMergeSort(std::vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    int left, mid, right;
    auto start_time = std::chrono::high_resolution_clock::now(); // Запуск таймера
    // Пока есть несортированные подсписки в массиве
    while (true) {
        left = 0;

        // Находим начало и конец первого подсписка
        while (left < n - 1) {
            int i = left;
            while (i < n - 1 && arr[i] <= arr[i + 1]) {
                ++i;
            }
            mid = i;

            // Если мы достигли конца массива, значит, массив уже отсортирован
            if (mid == n - 1) {
                return;
            }

            // Находим начало и конец второго подсписка
            while (i < n - 1 && arr[i] > arr[i + 1]) {
                ++i;
            }
            right = i;

            // Выполняем слияние двух подсписков
            merge_1(arr, left, mid, right, comparisons, swaps);

            // Переходим к следующему подсписку
            left = right + 1;
        }
    }
    std::cout << "jmfewikosjfveiowjfiowo" << std::endl;
    auto end = std::chrono::high_resolution_clock::now(); // Остановка таймера
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start_time); // Вычисление времени выполнения в наносекундах
    std::cout << "Natural merge sort" << "   " << comparisons_8 << "         " <<
        swaps_8 << "    " << duration.count() / std::pow(10, 9) << std::endl;
}