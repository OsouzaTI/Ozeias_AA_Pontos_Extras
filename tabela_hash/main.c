#include "hash_table.h"

int main() {    

    HashTable* hash = createHashTable(MIN_HASH_TABLE_SIZE);

    addHashMap(&hash, "Ozeias Silva Souza");
    addHashMap(&hash, "Ozeias Silva Souza");
    addHashMap(&hash, "Ozeias Silva Souza");
    addHashMap(&hash, "Ozeias Silva Souza");
    addHashMap(&hash, "Ozeias Silva Souza");
    addHashMap(&hash, "Ozeias Silva Souza");
    addHashMap(&hash, "Ozeias Silva Souza");

    HashNode *node;
    LIST_FOREACH(node, &collisions, pointers) {
        printf("Memory address: %p\n", node);
        printf("Nome: %s\n", node->data);
    }

    return 0;
}