#pragma once
int comparisons_6 = 0;
int swaps_6 = 0;
void selectionSort(std::vector<int>& arr, int& comparisons_6, int& swaps_6) {
    int n = arr.size();
    auto start = std::chrono::high_resolution_clock::now(); // ������ �������
    for (int i = 0; i < n - 1; ++i) {
        // ������� ������ ������������ �������� � ���������� ����� �������
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            comparisons_6++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // �������� ������� ������� � �����������
        if (i != minIndex) {
            std::swap(arr[i], arr[minIndex]);
            ++swaps_6; // ����������� ������� ������������
        }
    }
    auto end = std::chrono::high_resolution_clock::now(); // ��������� �������
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start); // ���������� ������� ���������� � ������������
    std::cout << "Simple Selection sort" << "   " << comparisons_6 << "             " <<
        swaps_6 << "          " << duration.count() / std::pow(10, 9) << std::endl;
}
