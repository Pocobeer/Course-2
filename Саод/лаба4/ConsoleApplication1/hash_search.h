#pragma once
#include <unordered_map>
#include <vector>
// ���-������� ��� �������� ������ �����
std::unordered_map<int, bool> hashTable;

// ������� ��� ������� ������� ����� � ���-�������
void insertIntoHashTable(int num) {
    if (num % 2 == 0) {
        hashTable[num] = true; // ����� ����� ������� ����� ����������� ���������� ��� ������ ���� ������� �����
    }
}

// ������� ��� ������ ������� ����� � ���-�������
bool searchInHashTable(int num) {
    if (num % 2 == 0) {
        if (hashTable.find(num) != hashTable.end()) {
            return true; // ������ ����� ������� � �������
        }
    }
    return false; // ������ ����� �� ������� ��� �� �������� ������ ������
}