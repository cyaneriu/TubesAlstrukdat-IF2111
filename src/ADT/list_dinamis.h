#ifndef LIST_DINAMIS_H
#define LIST_DINAMIS_H

#include <stdlib.h>
#include <stdio.h>

#define CAPACITY 999

typedef struct {
    char **items;
    int size;
    int capacity;
} ListDin;

void CreateListDin(ListDin *list, int capacity);

void insertLast(ListDin *list, char *item);

int isEmpty(ListDin list);

int listLength(ListDin list);

char* ELMT(ListDin list, int index);

void dealocateList(ListDin *list);

void copyFirst(ListDin list, char *variable);

void deleteFirst(ListDin *list);

void deleteAt(ListDin *list, int index);

#endif
