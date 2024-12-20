// load_data.h

#ifndef LOAD_H
#define LOAD_H

#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"
#include "../ADT/stack.h"
#include "../ADT/map.h"
#include "../ADT/listlinier.h"
#include <stdio.h>
#include <stdlib.h> 


#define MAX_USER 50
#define MAX_BARANG 50

// Struktur Barang
typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
    Map keranjang;
    Stack riwayat_pembelian;
    List wishlist;
    boolean logged;
} User;

// Fungsi untuk mengkonversi Word ke integer
int wordToInt(Word word);

// Fungsi untuk mengkopi Word ke string
void wordToString(Word word, char* str);
void LoadRiwayat(Stack *riwayat_pembelian, int jumlahRiwayat);
// Fungsi untuk memuat data dari file
void Load(char *filename, Barang barang[], int *jumlahBarang, User user[], int *jumlahUser);

int startLoad(char * filename, Barang barang[], int * jumlahBarang, User user[], int * jumlahUser);

#endif
