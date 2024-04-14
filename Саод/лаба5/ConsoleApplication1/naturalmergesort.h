#pragma once
int comparisons_8 = 0;
int swaps_8 = 0;
// ������� ��� ������� ���� �������� ��������������� ����������
void merge_1(std::vector<int>&arr, int left, int mid, int right, int& comparisons, int& swaps) {
    int n1 = mid - left + 1; // ������ ������� ���������
    int n2 = right - mid;    // ������ ������� ���������

    // ������� ��������� ������� ��� �������� ��������� ����������
    std::vector<int> leftArr(n1);
    std::vector<int> rightArr(n2);

    // �������� ������ �� ��������� �������
    for (int i = 0; i < n1; ++i) {
        leftArr[i] = arr[left + i];
    }
    for (int j = 0; j < n2; ++j) {
        rightArr[j] = arr[mid + 1 + j];
    }

    // �������������� ������� ��� ����� ��������� �������� � ��������� �������
    int i = 0, j = 0, k = left;

    // ������� ��������� �������� ������� � �������� ������
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

    // �������� ���������� �������� leftArr (���� ��� ����) ������� � arr
    while (i < n1) {
        arr[k] = leftArr[i];
        ++i;
        ++k;
        swaps_8++;
    }

    // �������� ���������� �������� rightArr (���� ��� ����) ������� � arr
    while (j < n2) {
        arr[k] = rightArr[j];
        ++j;
        ++k;
        swaps_8++;
    }
    
}

// ������� ��� ���������� ������������ ����������� ��������
void naturalMergeSort(std::vector<int>& arr, int& comparisons, int& swaps) {
    int n = arr.size();
    int left, mid, right;
    auto start_time = std::chrono::high_resolution_clock::now(); // ������ �������
    // ���� ���� ��������������� ��������� � �������
    while (true) {
        left = 0;

        // ������� ������ � ����� ������� ���������
        while (left < n - 1) {
            int i = left;
            while (i < n - 1 && arr[i] <= arr[i + 1]) {
                ++i;
            }
            mid = i;

            // ���� �� �������� ����� �������, ������, ������ ��� ������������
            if (mid == n - 1) {
                return;
            }

            // ������� ������ � ����� ������� ���������
            while (i < n - 1 && arr[i] > arr[i + 1]) {
                ++i;
            }
            right = i;

            // ��������� ������� ���� ����������
            merge_1(arr, left, mid, right, comparisons, swaps);

            // ��������� � ���������� ���������
            left = right + 1;
        }
    }
    std::cout << "jmfewikosjfveiowjfiowo" << std::endl;
    auto end = std::chrono::high_resolution_clock::now(); // ��������� �������
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start_time); // ���������� ������� ���������� � ������������
    std::cout << "Natural merge sort" << "   " << comparisons_8 << "         " <<
        swaps_8 << "    " << duration.count() / std::pow(10, 9) << std::endl;
}