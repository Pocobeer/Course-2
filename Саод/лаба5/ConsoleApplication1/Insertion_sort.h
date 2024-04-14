#pragma once
int comparisons_1 = 0;
int swaps_1 = 0;
void insertionSort(std::vector<int>& arr, int& comparisons_1, int& swaps_1) {
    int n = arr.size();
    auto start = std::chrono::high_resolution_clock::now(); // ������ �������

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
            swaps_1++; // ���������� �������� ������������
            comparisons_1++; // ���������� �������� ���������
        }
        arr[j + 1] = key;
        swaps_1++; // ���������� �������� ������������
    }
    auto end = std::chrono::high_resolution_clock::now(); // ��������� �������
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start); // ���������� ������� ���������� � ������������
    std::cout << "Insertion sort" << "          " << comparisons_1 << "             " <<
        swaps_1 << "       " << duration.count()/std::pow(10,9) << std::endl;
}