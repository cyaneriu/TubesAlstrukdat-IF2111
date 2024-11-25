#include <stdio.h>
#include <stdlib.h>
#include "../ADT/mesinkata.h"

//TERMINAL COMMAND:
//gcc driver_mesinkata.c ../ADT/mesinkata.c ../ADT/mesinkarakter.c -o mesinkata
//./mesinkata

int main() {
    Word word1, word2, concatResult;
    char inputStr[100];

    // 1. StartWordInput
    printf("Test StartWordInput\n");
    printf("Masukkan kata (coba: STORE): ");
    StartWordInput();
    if (!EndWord) {
        printf("Kata yang dibaca: ");
        DisplayWord(currentWord);
        printf("\n\n");
    }

    // 2. ConcatWord
    printf("Test ConcatWord\n");
    word1 = stringToWord("Hello");
    word2 = stringToWord("World");
    concatResult = ConcatWord(word1, word2);
    printf("Concat 'Hello' dan 'World': ");
    DisplayWord(concatResult);
    printf("\n\n");

    // 3. SplitWordBlank
    printf("Test SplitWordBlank\n");
    Word splitResult = SplitWordBlank(stringToWord("Hello World"));
    printf("Kata setelah spasi: ");
    DisplayWord(splitResult);
    printf("\n\n");

    // 4. IsCommandEqual
    printf("Test IsCommandEqual\n");
    Word testCommand = stringToWord("STORE");
    printf("Apakah 'STORE' sama dengan 'STORE'? %s\n",
           IsCommandEqual(testCommand, "STORE") ? "Ya" : "Tidak");
    printf("Apakah 'STORE' sama dengan 'LIST'? %s\n\n",
           IsCommandEqual(testCommand, "LIST") ? "Ya" : "Tidak");

    // 5. CopyCommand
    printf("Test CopyCommand\n");
    printf("Masukkan command: ");
    StartCommand();
    if (!EndWord) {
        printf("Command yang dibaca: ");
        DisplayWord(currentCommand);
        printf("\n\n");
    }
    return 0;
}