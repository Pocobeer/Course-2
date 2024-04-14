#pragma once
#include "all_includes.h"

class linked_list_sort : public BASIC_CLASS {
private:
    struct Node {
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* head = nullptr;

    void insert(int value) {
        Node* new_node = new Node(value);
        if (head == nullptr || head->data >= value) {
            new_node->next = head;
            head = new_node;
        }
        else {
            Node* current = head;
            while (current->next != nullptr && current->next->data < value) {
                current = current->next;
            }
            new_node->next = current->next;
            current->next = new_node;
        }
    }
    void show() {
        printf("Имя: %s\n", name.c_str());
        while (head != nullptr) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }
public:

    linked_list_sort(vector<int>& arr) {
        for (const auto& a : arr) {
            insert(a);
        }
    }
    string name = "Вставки в связанный список";
    string get_name() {
        return name;
    }
    data sort() override {
        Timer timer;
        Node* sorted = nullptr;
        Node* current = head;


        data mydata = data();

        while (current != nullptr) {
            Node* next = current->next;

            Node* sorted_current = sorted;
            Node* sorted_prev = nullptr;

            mydata.count_of_compare++;
            while (sorted_current != nullptr && sorted_current->data < current->data) {
                sorted_prev = sorted_current;
                sorted_current = sorted_current->next;
                mydata.count_of_compare++;
            }

            if (sorted_prev == nullptr) {
                current->next = sorted;
                sorted = current;
            }
            else {
                sorted_prev->next = current;
                current->next = sorted_current;
            }

            current = next;
        }

        head = sorted;

        mydata.time += timer.elapsed();
        if (DEBUG) show();
        return mydata;
    }
};
