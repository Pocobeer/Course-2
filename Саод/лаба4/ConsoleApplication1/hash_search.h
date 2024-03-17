#pragma once
#include <unordered_map>
#include <vector>
// Хеш-таблица для хранения четных чисел
std::unordered_map<int, bool> hashTable;

// Функция для вставки четного числа в хеш-таблицу
void insertIntoHashTable(int num) {
    if (num % 2 == 0) {
        hashTable[num] = true; // Здесь можно хранить любую необходимую информацию или просто флаг наличия числа
    }
}

// Функция для поиска четного числа в хеш-таблице
bool searchInHashTable(int num) {
    if (num % 2 == 0) {
        if (hashTable.find(num) != hashTable.end()) {
            return true; // Четное число найдено в таблице
        }
    }
    return false; // Четное число не найдено или не является четным числом
}