#include <stdio.h>
#include <stdlib.h>
#include "spesifikasi/store.h"

void displayLandingPage() {
    printf("PURRMART"); //pake art ascii
}

//kalo udah login register dll
void displayMainMenu() {
    printf("\n=== WELCOME TO PURRMART! ===\n");
    printf(""); //buat opsi2 menu dll
}

int main() {
    boolean program = true;

    while (program) {
        StartWordInput();

        if (IsCommandEqual(currentWord, "STORE\0")) {
        }
    }
}