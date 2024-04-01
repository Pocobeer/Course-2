#pragma once

#include "all_includes.h"

class Dig_search : public BASIC_CLASS{
private:
    struct Node {
        Node* q;
        Node* w;
        Node* e;
        Node* r;
        Node* t;
        Node* y;
        Node* u;
        Node* i;
        Node* o;
        Node* p;
        bool kon;
        char data;
        string res;
        int res_;
        Node(char _key) : data(_key), res(""), res_(0),kon(false), q(nullptr), w(nullptr), e(nullptr), r(nullptr), t(nullptr), y(nullptr), u(nullptr), i(nullptr), o(nullptr), p(nullptr) {}
    };
    string NAME = "Цифровой поиск";
    Node* root = new Node('\0');
    int search(Node* kor, string c, int isk_) {
        if (c.size() == 0) {
            if (kor!=nullptr && kor->kon && stoi(kor->res) == isk_) {
                return isk_;
            }
            return -1;
        }
        else {
            ITER_COUNT++;
            if (c[0] == '0') {
                c = string(c.begin() + 1, c.end());
                return search(kor->q, c, isk_);
            }
            else if (c[0] == '1') {
                c = string(c.begin() + 1, c.end());
                return search(kor->w, c, isk_);
            }
            else if (c[0] == '2') {
                c = string(c.begin() + 1, c.end());
                return search(kor->e, c, isk_);
            }
            else if (c[0] == '3') {
                c = string(c.begin() + 1, c.end());
                return search(kor->r, c, isk_);
            }
            else if (c[0] == '4') {
                c = string(c.begin() + 1, c.end());
                return search(kor->t, c, isk_);
            }
            else if (c[0] == '5') {
                c = string(c.begin() + 1, c.end());
                return search(kor->y, c, isk_);
            }
            else if (c[0] == '6') {
                c = string(c.begin() + 1, c.end());
                return search(kor->u, c, isk_);
            }
            else if (c[0] == '7') {
                c = string(c.begin() + 1, c.end());
                return search(kor->i, c, isk_);
            }
            else if (c[0] == '8') {
                c = string(c.begin() + 1, c.end());
                return search(kor->o, c, isk_);
            }
            else if (c[0] == '9') {
                c = string(c.begin() + 1, c.end());
                return search(kor->p, c, isk_);
            }
        }
    }
    void insert(Node* kor, string c) {
        if (c.size() != 0) {
            if (c[0] == '0') {
                if (kor->q == nullptr) {
                    kor->q = new Node(c[0]);
                }
                c = string(c.begin() + 1, c.end());
                kor->q->res = kor->res + "0";
                if (c.size() == 0) {
                    kor->q->kon = true;
                }
                insert(kor->q, c);
            }
            else if (c[0] == '1') {
                if (kor->w == nullptr) {
                    kor->w = new Node(c[0]);
                }
                c = string(c.begin() + 1, c.end());
                kor->w->res = kor->res + "1";
                if (c.size() == 0) {
                    kor->w->kon = true;
                }
                insert(kor->w, c);
            }
            else if (c[0] == '2') {
                if (kor->e == nullptr) {
                    kor->e = new Node(c[0]);
                }
                c = string(c.begin() + 1, c.end());
                kor->e->res = kor->res + "2";
                if (c.size() == 0) {
                    kor->e->kon = true;
                }
                insert(kor->e, c);
            }
            else if (c[0] == '3') {
                if (kor->r == nullptr) {
                    kor->r = new Node(c[0]);
                }
                c = string(c.begin() + 1, c.end());
                kor->r->res = kor->res + "3";
                if (c.size() == 0) {
                    kor->r->kon = true;
                }
                insert(kor->r, c);
            }
            else if (c[0] == '4') {
                if (kor->t == nullptr) {
                    kor->t = new Node(c[0]);
                }
                c = string(c.begin() + 1, c.end());
                kor->t->res = kor->res + "4";
                if (c.size() == 0) {
                    kor->t->kon = true;
                }
                insert(kor->t, c);
            }
            else if (c[0] == '5') {
                if (kor->y == nullptr) {
                    kor->y = new Node(c[0]);
                }
                c = string(c.begin() + 1, c.end());
                kor->y->res = kor->res + "5";
                if (c.size() == 0) {
                    kor->y->kon = true;
                }
                insert(kor->y, c);
            }
            else if (c[0] == '6') {
                if (kor->u == nullptr) {
                    kor->u = new Node(c[0]);
                }
                c = string(c.begin() + 1, c.end());
                kor->u->res = kor->res + "6";
                if (c.size() == 0) {
                    kor->u->kon = true;
                }
                insert(kor->u, c);
            }
            else if (c[0] == '7') {
                if (kor->i == nullptr) {
                    kor->i = new Node(c[0]);
                }
                c = string(c.begin() + 1, c.end());
                kor->i->res = kor->res + "7";
                if (c.size() == 0) {
                    kor->i->kon = true;
                }
                insert(kor->i, c);
            }
            else if (c[0] == '8') {
                if (kor->o == nullptr) {
                    kor->o = new Node(c[0]);
                }
                c = string(c.begin() + 1, c.end());
                kor->o->res = kor->res + "8";
                if (c.size() == 0) {
                    kor->o->kon = true;
                }
                insert(kor->o, c);
            }
            else if (c[0] == '9') {
                if (kor->p == nullptr) {
                    kor->p = new Node(c[0]);
                }
                c = string(c.begin() + 1, c.end());
                kor->p->res = kor->res + "9";
                if (c.size() == 0) {
                    kor->p->kon = true;
                }
                insert(kor->p, c);
            }
            c = "";
        }
    }
    int ISKOMOE = -1;
    int ITER_COUNT = 0;
public:
    Dig_search(vector<int> &in) {
        for (const auto& a : in) {
            string temp_s = to_string(a);
            insert(root, temp_s);
        }
    }
    Dig_search() {}
    int solve(int isk_) override {
        return search(root, to_string(isk_), isk_);
    }
    int solve() override {
        return search(root, to_string(ISKOMOE), ISKOMOE);
    }
    void change_isk(int isk_) {
        ISKOMOE = isk_;
    }
    string get_name() {
        return NAME;
    }
    int get_iter() {
        int temp_i = ITER_COUNT;
        ITER_COUNT = 0;
        return temp_i;
    }
    void restruct(vector<int>& in) {
        for (const auto& a : in) {
            string temp_s = to_string(a);
            insert(root, temp_s);
        }
    }
};
