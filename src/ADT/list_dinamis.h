#ifndef LIST_DINAMIS_H
#define LIST_DINAMIS_H

#include "list.h"
#include <stdlib.h>

typedef struct {
    char **items;
    int size;
    int capacity;
} ListDin;

void CreateListDin(ListDin *list, int capacity);
void dealocateListDin(ListDin *list);
int listLengthDin(ListDin list);
int isEmptyDin(ListDin list);
void insertLastDin(ListDin *list, char *item);
void deleteAtDin(ListDin *list, int index);
void deleteFirstDin(ListDin *list);
char* ELMTDin(ListDin list, int index);
void copyFirstDin(ListDin list, char *variable);

#endif