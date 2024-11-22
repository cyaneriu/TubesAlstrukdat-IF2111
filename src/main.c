#include <stdio.h>
#include <stdlib.h>
#include "ADT/boolean.h"
#include "ADT/mesinkarakter.h"
#include "ADT/mesinkata.h"

void displayLandingPage() {
    printf("PURRMART"); //pake art ascii
}

//kalo udah login register dll
void displayMainMenu() {
    printf("\n=== WELCOME TO PURRMART! ===\n");
    printf("menu"); //buat opsi2 menu dll
}

int main() {
    boolean program = true;

    while (program) {
        StartWordInput();

        if (IsCommandEqual(currentWord, "STORE\0")) {
            #include "store_run.h"
            store_running();
        }
    }
}