// load_data.h

#ifndef LOAD_H
#define LOAD_H

#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"
#include <stdio.h>
#include <stdlib.h> 


#define MAX_USER 100
#define MAX_BARANG 100

// Struktur Barang
typedef struct {
    char name[MAX_LEN];
    int price;
} Barang;

// Struktur User
typedef struct {
    char name[MAX_LEN];
    char password[MAX_LEN];
    int money;
    boolean logged;
} User;

// Fungsi untuk mengkonversi Word ke integer
int wordToInt(Word word);

// Fungsi untuk mengkopi Word ke string
void wordToString(Word word, char* str);

// Fungsi untuk memuat data dari file
void Load(char *filename, Barang barang[], int *jumlahBarang, User user[], int *jumlahUser);

void startLoad(char *filename);

#endif // LOAD_H
