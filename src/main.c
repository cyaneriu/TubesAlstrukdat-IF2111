#include <stdio.h>
#include <stdlib.h>
#include "spesifikasi/store.h"

void displayLandingPage() {
    printf("PURRMART");
}

int main() {
    boolean program = true;

    while (program) {
        StartWordInput();

        if (IsCommandEqual(currentWord, "STORE\0")) {
        }
    }
}