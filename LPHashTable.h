
#include <vector>
#include <list>
#include <iostream>
#include <cstdlib>
#include <ctime>

#include "HashTable.h"

// inherit from HashTable
class LPHashTable : public HashTable {
public:
    explicit LPHashTable(int s) : HashTable(s) {}

    void insert(HTNode *node) override {
        int key = node->key;
        int index = hashFunction(key);
        for (;;) {
            auto &slot = table[index];
            if (slot == nullptr) {
                slot = node;
                return;
            } else {
                if (slot->key == key) {
                    node->next = slot;
                    slot = node;
                    return;
                } else {
                    index = (index + 1) % size;
                }
            }

        }
    }

    int getMatchCount(int key) override {
        int index = hashFunction(key);
        auto slot = table[index];

        // todo: implement the linear probing search

        return 0;
    }
};
