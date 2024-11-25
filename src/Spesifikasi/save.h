#ifndef SAVE_H
#define SAVE_H

#include "../ADT/mesinkarakter.h"
#include "../ADT/mesinkata.h"
#include <stdio.h>
#include <stdlib.h> 
#include"load.h"
//#include "../Spesifikasi/load.h"


//Fungsi Untuk Memulai menulis file txt
void startWriteFile(char *filename);
//Fungsi Untuk Menyimpan data ke file txt
void Save(char *filename, Barang barang[], int *jumlahBarang, User user[], int *jumlahUser);

int startSave(char * filename, Barang barang[], int * jumlahBarang, User user[], int * jumlahUser);
#endif