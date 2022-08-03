#include "hash_table.h"

int stringHash (const char* str, int M) {
    unsigned h = 0;
    for (int i = 0; str[i] != '\0'; i++) 
        h = (h * 256 + str[i]) % M;
    return h;
}

HashTable* createHashNode() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    hashTable->active = 0;
    LIST_HEAD(collision_list, HashTable) cats;
}