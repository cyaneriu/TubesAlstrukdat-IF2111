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

void deleteAt(ListDin *list, const char *item) {
    if (list->size == 0) {
        printf("List kosong. Tidak ada yang dapat dihapus.\n");
        return;
    }
    int idx = -1;
    for (int i = 0; i < list->size; i++) {
        int j = 0;
        while (list->items[i][j] == item[j] && list->items[i][j] != '\0') {
            j++;
        }
        if (list->items[i][j] == '\0' && item[j] == '\0') {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        printf("Item '%s' tidak ditemukan dalam list.\n", item);
        return;
    }
    free(list->items[idx]);
    for (int i = idx + 1; i < list->size; i++) {
        list->items[i - 1] = list->items[i];
    }
    list->size--;
}