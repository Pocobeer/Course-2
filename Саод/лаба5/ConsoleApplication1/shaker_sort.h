#pragma once
int comparisons_3 = 0;
int swaps_3 = 0;
void shakerSort(std::vector<int>& arr, int& comparisons_3, int& swaps_3) {
    bool swapped = true;
    int start = 0;
    int end = arr.size() - 1;
    auto start_time = std::chrono::high_resolution_clock::now(); // ������ �������
    while (swapped) {
        swapped = false;

        // ������ ������
        for (int i = start; i < end; ++i) {
            comparisons_3++;
            if (arr[i] > arr[i + 1]) {
                swaps_3++;
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
                
            }
        }

        // ���� ��� �������, ������ ��� ������������
        if (!swapped)
            break;

        // ��������� �������, ��� ��� ����� ������� ������� ��� ��������� �� �����
        --end;

        // ������ �����
        for (int i = end - 1; i >= start; --i) {
            comparisons_3++;
            if (arr[i] > arr[i + 1]) {
                swaps_3++;
                std::swap(arr[i], arr[i + 1]);
                swapped = true;
               
            }
        }

        // ����������� �������, ��� ��� ����� ��������� ������� ��� ��������� � ������
        ++start;
    }
    auto end_1 = std::chrono::high_resolution_clock::now(); // ��������� �������
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end_1 - start_time); // ���������� ������� ���������� � ������������
    std::cout << "Shaker sort" << "             " << comparisons_3 << "             " <<
        swaps_3 << "       " << duration.count() / std::pow(10, 9) << std::endl;
}
