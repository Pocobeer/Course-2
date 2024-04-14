#pragma once
int comparisons_5 = 0;
int swaps_5 = 0;
// ������� ��� ���������� ������� �� �������� ��������
int partition_2(std::vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    int pivot = arr[high]; // ������� �������
    int i = low - 1; // ������ ��������, �������� ��������
    auto start_time = std::chrono::high_resolution_clock::now(); // ������ �������
    for (int j = low; j <= high - 1; ++j) {
        comparisons_5++;
        // ���� ������� ������� ������ ��� ����� ��������
        if (arr[j] <= pivot) {
            // ����������� ������ �������� �������� � ������ ������� ��������
            ++i;
            swaps_5++;
            std::swap(arr[i], arr[j]);
        }
    }
    // �������� ������� ������� �� ���������� �����
    swaps_5++;
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// ������� ������� ����������
void quickSort_2(std::vector<int>& arr, int low, int high, int& comparisons, int& swaps) {
    std::stack<std::pair<int, int>> stack;
    stack.push({ low, high });

    while (!stack.empty()) {
        int start = stack.top().first;
        int end = stack.top().second;
        stack.pop();

        int pivotIndex = partition_2(arr, start, end, comparisons, swaps);

        // ���� ���� �������� ����� �� ��������, ��������� �� � ����
        if (pivotIndex - 1 > start)
            stack.push({ start, pivotIndex - 1 });

        // ���� ���� �������� ������ �� ��������, ��������� �� � ����
        if (pivotIndex + 1 < end)
            stack.push({ pivotIndex + 1, end });
    }
}