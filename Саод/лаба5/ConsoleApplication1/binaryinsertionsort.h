#pragma once
int comparisons_2 = 0;
int swaps_2 = 0;
// ������� ��� ��������� ������ ����� ������� �������� � ������������� �������
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

// ���������� ��������� ���������
void binaryInsertionSort(std::vector<int>& arr, int& comparisons_2, int& swaps_2) {
    int n = arr.size();
    auto start = std::chrono::high_resolution_clock::now(); // ������ �������
    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        // ���������� �������� ����� ��� ���������� ������� �������
        int j = binarySearch(arr, key, 0, i - 1, comparisons_2);
        // ���������� ��� �������� � ������� j �� i �� ���� ������� ������
        for (int k = i - 1; k >= j; --k) {
            arr[k + 1] = arr[k];
            swaps_2++;
        }
        // ��������� key �� ��������� �������
        arr[j] = key;
    }
    auto end = std::chrono::high_resolution_clock::now(); // ��������� �������
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start); // ���������� ������� ���������� � ������������
    std::cout << "Binary Insertion sort" << "   " << comparisons_2 << "               " <<
        swaps_2 << "       " << duration.count() / std::pow(10, 9)  << std::endl;
}