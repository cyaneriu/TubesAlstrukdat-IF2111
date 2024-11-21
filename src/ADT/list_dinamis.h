#ifndef LIST_DINAMIS_H
#define LIST_DINAMIS_H

#include <stdlib.h>
#include <stdio.h>

#define CAPACITY 999

// Definisi struktur ListDin
typedef struct {
    char **items;
    int size;
    int capacity;
} ListDin;

// Fungsi untuk membuat list dinamis
void CreateListDin(ListDin *list, int capacity);

// Fungsi untuk menambah item pada list
void insertLast(ListDin *list, char *item);

// Fungsi untuk mengecek apakah list kosong
int isEmpty(ListDin list);

// Fungsi untuk mendapatkan panjang list
int listLength(ListDin list);

// Fungsi untuk mengakses elemen list
char* ELMT(ListDin list, int index);

// Fungsi untuk menghapus list
void dealocateList(ListDin *list);

void copyFirst(ListDin list, char *variable);

void deleteFirst(ListDin *list);

void deleteAt(ListDin *list, int index);

#endif
