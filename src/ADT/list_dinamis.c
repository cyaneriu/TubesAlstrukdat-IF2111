#include "list_dinamis.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void CreateListDin(ListDin *list, int capacity) {
    list->items = (char **)malloc(sizeof(char *) * capacity);
    list->size = 0;
    list->capacity = capacity;
}

void dealocateListDin(ListDin *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->items[i]);
    }
    free(list->items);
    list->size = 0;
    list->capacity = 0;
}

int listLengthDin(ListDin list) {
    return list.size;
}

int isEmptyDin(ListDin list) {
    return list.size == 0;
}

void insertLastDin(ListDin *list, char *item) {
    if (list->size < list->capacity) {
        list->items[list->size] = (char *)malloc(strlen(item) + 1);
        strcpy(list->items[list->size], item);
        list->size++;
    }
}

void deleteAtDin(ListDin *list, int index) {
    if (index >= 0 && index < list->size) {
        free(list->items[index]);
        for (int i = index + 1; i < list->size; i++) {
            list->items[i - 1] = list->items[i];
        }
        list->size--;
    }
}

void deleteFirstDin(ListDin *list) {
    if (list->size > 0) {
        deleteAtDin(list, 0);
    }
}

char* ELMTDin(ListDin list, int index) {
    if (index >= 0 && index < list.size) {
        return list.items[index];
    }
    return NULL;
}

void copyFirstDin(ListDin list, char *variable) {
    if (list.size > 0) {
        strcpy(variable, list.items[0]);
    } else {
        variable[0] = '\0';
    }
}