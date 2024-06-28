
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
        auto &slot = table[index];
        while (slot != nullptr) {
            slot = slot->next;
        }
        slot = node;
    }

    int getMatchCount(int key) override {
        int index = hashFunction(key);
        auto slot = table[index];
        int count = 0;

        while (slot != nullptr) {
            if (slot->key == key) {
                count += 1;
            }
            slot = slot->next;
        }

        return count;
    }
};
