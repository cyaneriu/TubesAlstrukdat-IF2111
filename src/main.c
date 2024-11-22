#include <stdio.h>
#include <stdlib.h>
#include "ADT/boolean.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"
#include "welcome_perry.h"

void displayMainMenu() { //kalo udah login register dll
    printf("\n=== WELCOME TO PURRMART! ===\n");
    printf("menu"); //buat opsi2 menu dll
}

int main() {
    boolean program = true;
    while (program) {
        welcome_perry();
        //load
        //login/register

        if (IsCommandEqual(currentWord, "REGISTER\0")) {
        } else if (IsCommandEqual(currentWord, "LOGIN\0")) {
        } else if (IsCommandEqual(currentWord, "HELP\0")) {
        } else if (IsCommandEqual(currentWord, "LOGOUT\0")) {
        } else if (IsCommandEqual(currentWord, "EXIT\0")) {
            program = false;
            printf("Keluar dari PURRMART.\n");
        } else if (IsCommandEqual(currentWord, "STORE REQUEST\0")) {
        } else {
            printf("Perintah tidak dikenali. Silakan coba lagi.\n");
        }

        //kalau udah login
        displayMainMenu();
        printf(">> ");

        StartWordInput();

        if (IsCommandEqual(currentWord, "STORE\0")) {
            #include "store.h"
            #include "store_run.h"
            store_running();
        } else if (IsCommandEqual(currentWord, "WORK\0")) {
        } else if (IsCommandEqual(currentWord, "SAVE\0")) {
        } else if (IsCommandEqual(currentWord, "STORE REMOVE\0")) {
        } else if (IsCommandEqual(currentWord, "EXIT")) {
        } else {
            printf("Perintah tidak dikenali. Silakan coba lagi.\n");
        }
    }
}