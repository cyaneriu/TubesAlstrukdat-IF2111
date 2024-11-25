#include <stdio.h>
#include "help.h"

boolean isEqualStrings(const char *str1, const char *str2) {
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return false;
        }
        str1++;
        str2++;
    }
    return *str1 == '\0' && *str2 == '\0';
}

void help(char *state){
    
    if (isEqualStrings(state, "Welcome Menu")){
        printf(">> HELP\n");
        printf("=====[ Welcome Menu Help PURRMART]=====\n");
        printf("   1. START --> Untuk masuk sesi baru\n");
        printf("   2. LOAD --> Untuk memulai sesi berdasarkan file konfigurasi\n");
        printf("   3. HELP --> Untuk menampilkan bantuan\n");
        printf("   4. QUIT --> Untuk keluar dari program\n");
    }
    else if (isEqualStrings(state, "Login Menu")) {
        printf(">> HELP\n");
        printf("=====[ Welcome Menu Help PURRMART]=====\n");
        printf("   1. REGISTER --> Untuk melakukan pendaftaran akun baru\n");
        printf("   2. LOGIN --> Untuk masuk ke dalam akun dan memulai sesi\n");
        printf("   3. QUIT --> Untuk keluar dari program\n");
    }
    else if (isEqualStrings(state, "Main Menu")){
        printf(">> HELP\n");
        printf("=====[ Welcome Menu Help PURRMART]=====\n");
        printf("   1. WORK --> Untuk bekerja dan mendapatkan uang\n");
        printf("   2. WORK CHALLENGE --> Untuk mengerjakan challenge\n");
        printf("   3. STORE --> Untuk mengakses menu store\n");
        printf("   4. LOGOUT --> Untuk keluar dari sesi\n");
        printf("   5. SAVE --> Untuk menyimpan state ke dalam file\n");
        printf("   6. QUIT --> Untuk keluar dari program\n");
    }
}