#include <stdio.h>
#include <stdlib.h>
#include "list_dinamis.h"

// Fungsi untuk membuat list dinamis dengan kapasitas tertentu
void CreateListDin(ListDin *list, int capacity) {
    list->items = (char**)malloc(sizeof(char*) * capacity);
    list->size = 0;
    list->capacity = capacity;
}

void insertLast(ListDin *list, char *item) {
    if (list->size < list->capacity) {
        int length = 0;

        while (item[length] != '\0') {
            length++;
        }

        list->items[list->size] = (char *)malloc(length + 1);
        if (list->items[list->size] != NULL) {
            for (int i = 0; i < length; i++) {
                list->items[list->size][i] = item[i];
            }
            list->items[list->size][length] = '\0';
            list->size++;
        }
    }
}

int isEmpty(ListDin list) {
    return list.size == 0;
}

int listLength(ListDin list) {
    return list.size;
}

char* ELMT(ListDin list, int index) {
    if (index >= 0 && index < list.size) {
        return list.items[index];
    }
    return NULL;
}

void dealocateList(ListDin *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->items[i]);
    }
    free(list->items);
    list->size = 0;
    list->capacity = 0;
}

void copyFirst(ListDin list, char *variable) {
    if (list.size > 0) {
        int i = 0;
        while (list.items[0][i] != '\0') {
            variable[i] = list.items[0][i];
            i++;
        }
        variable[i] = '\0';
    } else {
        variable[0] = '\0';
    }
}

void deleteFirst(ListDin *list) {
    if (list->size > 0) {
        free(list->items[0]);

        for (int i = 1; i < list->size; i++) {
            list->items[i - 1] = list->items[i];
        }
        list->size--;
    }
}

void deleteAt(ListDin *list, int index) {
    if (list->size > 0 && index >= 0 && index < list->size) {
        free(list->items[index]);

        for (int i = index + 1; i < list->size; i++) {
            list->items[i - 1] = list->items[i];
        }

        list->size--;
    }
}
