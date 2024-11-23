#include <stdio.h>
#include "help.h"

void help(char * state[100]){
    
    if (state == "Welcome Menu"){
        printf(">> HELP\n");
        printf("=====[ Welcome Menu Help PURRMART]=====");
        printf("   1. START --> Untuk masuk sesi baru\n");
        printf("   2. LOAD --> Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("   3. HELP --> Untuk menampilkan bantuan\n");
        printf("   4. QUIT --> Untuk keluar dari program\n");
    }
    else if (state == "Login Menu"){
        printf(">>>> HELP\n");
        printf("=====[ Welcome Menu Help PURRMART]=====");
        printf("   1. REGISTER --> Untuk melakukan pendaftaran akun baru\n");
        printf("   2. LOGIN --> Untuk masuk ke dalam akun dan memulai sesi\n");
        printf("   3. QUIT --> Untuk keluar dari program\n");
    }
    else if (state == "Main Menu"){
        printf(">>>> HELP\n");
        printf("=====[ Welcome Menu Help PURRMART]=====");
        printf("   1. WORK --> Untuk bekerja dan mendapatkan uang\n");
        printf("   2. WORK CHALLENGE --> Untuk mengerjakan challenge\n");
        printf("   3. STORE --> Untuk mengakses menu store\n");
        printf("   4. LOGOUT --> Untuk keluar dari sesi\n");
        printf("   5. SAVE --> Untuk menyimpan state ke dalam file\n");
        printf("   6. QUIT --> Untuk keluar dari program\n");
    }
}