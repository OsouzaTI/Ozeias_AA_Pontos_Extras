#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include <string.h>
#include <stdlib.h>
#include <bsd/sys/queue.h>

#define MIN_HASH_TABLE_SIZE 10

typedef struct _hash_table
{
    int active;
    char data[255];
    // lista de colisoes
    LIST_ENTRY(_hash_table) pointers;
} HashTable;

int stringHash(const char* str, int M);

#endif