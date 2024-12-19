#include <stdio.h>
#include <stdlib.h>
#include "load.h"

int wordToInt(Word word) {
    char str[MAX_LEN];
    int i;
    for (i = 0; i < word.Length; i++) {
        str[i] = word.TabWord[i];
    }
    str[i] = '\0';
    return atoi(str);
}

void wordToString(Word word, char* str) {
    int i;
    for (i = 0; i < word.Length; i++) {
        str[i] = word.TabWord[i];
    }
    str[i] = '\0';
}

void LoadRiwayat(Stack *riwayat_pembelian, int jumlahRiwayat) {
    for (int i = 0; i < jumlahRiwayat; i++) {
        ADVLine();
        Word nama = SplitWordBlank(currentWord);
        char jumlahBarang;
        wordToString(nama, &jumlahBarang);
        Word namaBarang = SplitWordLeftBlank(currentWord);
        int harga = wordToInt(namaBarang);

        // Memasukkan data ke stack
        infotypeStack item;
        wordToString(nama, item.name);
        item.harga = harga;
        Push(riwayat_pembelian, item);
    }
}
void Load(char *filename, Barang barang[], int *jumlahBarang, User user[], int *jumlahUser) {
    char fullPath[100];
    char directory[100] = "../save";
    sprintf(fullPath, "%s/%s", directory, filename);
    StartWordFile(fullPath, 0);

    if (EndWord) {
        printf("Save file tidak ditemukan. PURRMART gagal dijalankan.\n");
        return;
    }
    *jumlahBarang = wordToInt(currentWord);
    for (int i = 0; i < *jumlahBarang; i++) {
        ADVLine(); 
        barang[i].price = wordToInt(currentWord);
        Word namaBarang = SplitWordBlank(currentWord);
        wordToString(namaBarang, barang[i].name);
    }

    ADVLine();

    *jumlahUser = wordToInt(currentWord);

   
    for (int i = 0; i < *jumlahUser; i++) {
        ADVLine();  
        user[i].money = wordToInt(currentWord);

        Word temp = SplitWordBlank(currentWord);
        Word nama = SplitWordLeftBlank(temp);
        wordToString(nama, user[i].name);

        temp = SplitWordBlank(temp);
        wordToString(temp, user[i].password);
        user[i].logged = false;
        CreateEmptyStack(&user[i].riwayat_pembelian);

        ADVLine();
        int jumlahRiwayat = wordToInt(currentWord);
        LoadRiwayat(&(user[i].riwayat_pembelian), jumlahRiwayat);
    
        CreateEmptyListLinier(&user[i].wishlist); 
        ADVLine();
        int wishlistCount = wordToInt(currentWord);
        for (int j = 0; j < wishlistCount; j++) {
            ADVLine();
            char wishlistItem[50];
            wordToString(currentWord, wishlistItem);               
            InsVFirst(&user[i].wishlist, wishlistItem);
        }
    }
    printf("Save file berhasil dibaca. PURRMART berhasil dijalankan.\n");
}

int startLoad(char * filename, Barang barang[], int * jumlahBarang, User user[], int * jumlahUser) {
    Load(filename, barang, jumlahBarang, user, jumlahUser);
    printf("File berhasil dimuat.\n");
    return *jumlahBarang;
}