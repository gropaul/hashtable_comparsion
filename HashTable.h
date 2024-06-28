#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>

class HTNode {
public:
    int key;
    HTNode* next;
    HTNode(int k) : key(k), next(nullptr) {}

    HTNode() : key(0), next(nullptr) {}

};

class HashTable {
protected:
    std::vector<HTNode*> table;
    int size;
    int hashFunction(int key) const {
        return key % size;
    }

public:
    explicit HashTable(int s) : size(s) {
        table.resize(size, nullptr);
    }

    void printChainLengths() {
        for (int i = 0; i < size; ++i) {
            auto slot = table[i];
            int count = 0;
            while (slot != nullptr) {
                count++;
                slot = slot->next;
            }
            std::cout << "Slot " << i << " has " << count << " elements" << std::endl;
        }
    }

    virtual void insert(HTNode* node) {
        int key = node->key;
        int index = hashFunction(key);
        auto &slot = table[index];
        node->next = slot;
        slot = node;
    }

    virtual int getMatchCount(int key) {
        int index = hashFunction(key);
        auto slot = table[index];
        int count = 0;

        while (slot != nullptr) {
            if (slot->key == key) {
                count+=1;
            }
            slot = slot->next;
        }
        return count;
    }
};

#endif // HASHTABLE_H
