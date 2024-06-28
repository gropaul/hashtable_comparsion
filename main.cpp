#include <iostream>
#include "HashTable.h"
#include "LPHashTable.h"


void testHashTable(int N, int M, int VALUE_RANGE, int SEED, HashTable &hashTable) {

    // Seed random number generator
    std::srand(SEED);

    // allocate N nodes
    auto *nodes = new HTNode[N];
    for (int i = 0; i < N; ++i) {
        auto key = std::rand() % VALUE_RANGE;
        nodes[i] = HTNode(key);
    }

    // time the insertion
    clock_t start = clock();

    // Insert N random values
    for (int i = 0; i < N; ++i) {
        auto node = &nodes[i];
        hashTable.insert(node);
    }

    clock_t end = clock();
    double elapsed = double(end - start) / CLOCKS_PER_SEC;
    printf("Insertion duration=%f\n", elapsed);

    // Probe the hash table

    clock_t start_probe = clock();

    int n_found = 0;
    for (int i = 0; i < M; ++i) {
        int value = std::rand() % VALUE_RANGE; // Random value between 0 and VALUE_RANGE - 1
        int matches = hashTable.getMatchCount(value);
        n_found += matches;
    }

    clock_t end_probe = clock();
    double elapsed_probe = double(end_probe - start_probe) / CLOCKS_PER_SEC;

    printf("Probe duration=%f\n", elapsed_probe);
    printf("Found %d matches for %d probes\n", n_found, M);
}


int main() {
    int N = 100; // Number of values to insert
    int M = 10;  // Number of values to probe
    int VALUE_RANGE = 10; // Range of random values
    int SEED = 42;

    float loadFactor = 2.0; // Load factor for the hash table
    int tableSize = (int) ((float) N / loadFactor); // Size of the hash table (number of slots

    HashTable hashTable(tableSize);
    LPHashTable lpHashTable(tableSize);

    testHashTable(N, M, VALUE_RANGE, SEED, hashTable);

}

