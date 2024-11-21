#ifndef QUIT_H
#define QUIT_H

#include "save.h"
#include "load.h"
#include <stdio.h>

void quit(char * filename, Barang barang[MAX_BARANG], int *jumlahBarang, User user[MAX_USER], int *jumlahUser);

#endif