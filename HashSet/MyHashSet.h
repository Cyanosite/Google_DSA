//
// Created by Zsombor Szenyán on 2022. 12. 26..
//

#ifndef HASHSET_MYHASHSET_H
#define HASHSET_MYHASHSET_H


class MyHashSet {
    struct Node {
        int data;
        Node* next;
        explicit Node(int key = 0) {
            data = key;
            next = nullptr;
        }
    };
    Node* data[10];
    static int hash(int key) {
        return key % 10;
    }

public:
    void add(int key) {
        int index = hash(key);
        Node* first = data[index];
        if (first == nullptr) {
            data[index] = new Node(key);
            return;
        }
        if (first->data == key) return;
        for(; first->next != nullptr && first->data != key; first = first->next);
        if (first->data == key) return;
        first->next = new Node(key);
    }
    bool contains(int key) {
        int index = hash(key);
        Node* first = data[index];
        if (first == nullptr) return false;
        if (first->data == key) return true;
        for(; first->next != nullptr && first->data != key; first = first->next);
        return first->data == key;
    }
    void remove(int key) {
        int index = hash(key);
        Node* first = data[index];
        if (first == nullptr) return;
        if (first->data == key) {
            data[index] = first->next;
            return;
        }
        for(; first->next != nullptr; first = first->next) {
            if (first->next->data == key) {
                Node* toRemove = first->next;
                first->next = first->next->next;
                delete toRemove;
                return;
            }
        }
    }
    ~MyHashSet() {
        for (auto* list: data) {
            for(; list != nullptr;) {
                Node* toRemove = list;
                list = list->next;
                delete toRemove;
            }
        }
    }
};


#endif //HASHSET_MYHASHSET_H
