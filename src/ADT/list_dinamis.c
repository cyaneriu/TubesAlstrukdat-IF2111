#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list_dinamis.h"

// Fungsi untuk membuat list dinamis dengan kapasitas tertentu
void CreateListDin(ListDin *list, int capacity) {
    list->items = (char**)malloc(sizeof(char*) * capacity);
    list->size = 0;
    list->capacity = capacity;
}

// Fungsi untuk menambah item pada list
void insertLast(ListDin *list, char *item) {
    if (list->size < list->capacity) {
        list->items[list->size] = (char*)malloc(strlen(item) + 1);
        strcpy(list->items[list->size], item);
        list->size++;
    }
}

// Fungsi untuk mengecek apakah list kosong
int isEmpty(ListDin list) {
    return list.size == 0;
}

// Fungsi untuk mendapatkan panjang list
int listLength(ListDin list) {
    return list.size;
}

// Fungsi untuk mengakses elemen list
char* ELMT(ListDin list, int index) {
    if (index >= 0 && index < list.size) {
        return list.items[index];
    }
    return NULL;
}

// Fungsi untuk menghapus list dan membebaskan memori
void dealocateList(ListDin *list) {
    for (int i = 0; i < list->size; i++) {
        free(list->items[i]);
    }
    free(list->items);
    list->size = 0;
    list->capacity = 0;
}