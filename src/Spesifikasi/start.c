#include <stdio.h>
#include <stdlib.h>
#include "start.h"

void start(){
    Barang barang[MAX_BARANG];
    User user[MAX_USER];
    char * filename;
    int jumlahBarang, jumlahUser;
    Load(filename, barang, &jumlahBarang, user, &jumlahUser);
    printf("File berhasil dimuat.\n");
}
 