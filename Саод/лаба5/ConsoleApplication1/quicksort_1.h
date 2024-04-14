#pragma once
int comparisons_4 = 0;
int swaps_4 = 0;
// ������� ��� ���������� ������� �� �������� ��������
int partition_1(std::vector<int>& arr, int low, int high) {
    int pivot = arr[high]; // ������� �������
    int i = low - 1; // ������ ��������, �������� ��������
    auto start_time = std::chrono::high_resolution_clock::now(); // ������ �������
    for (int j = low; j <= high - 1; ++j) {
        comparisons_4++;
        // ���� ������� ������� ������ ��� ����� ��������
        if (arr[j] <= pivot) {
            // ����������� ������ �������� �������� � ������ ������� ��������
            ++i;
            swaps_4++;
            std::swap(arr[i], arr[j]);
        }
    }
    // �������� ������� ������� �� ���������� �����
    swaps_4++;
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// ������� ������� ����������
void quickSort_1(std::vector<int>& arr, int low, int high) {
   
    if (low < high) {
        // ��������� ������ � �������� ������ �������� ��������
        int pi = partition_1(arr, low, high);

        // ���������� ��������� �������� �� �������� �������� � ����� ����
        quickSort_1(arr, low, pi - 1);
        quickSort_1(arr, pi + 1, high);
    }
    
    
}

