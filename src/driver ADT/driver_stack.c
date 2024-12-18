#include <stdio.h>
#include "../ADT/stack.h"

int main() {
    Stack S;
    Word word1, word2, poppedWord;

    // Inisialisasi stack kosong
    CreateEmptyStack(&S);

    printf("Stack berhasil dibuat.\n");

    // Cek apakah stack kosong
    if (IsEmptyStack(S)) {
        printf("Stack dalam keadaan kosong.\n");
    }

    // Memasukkan elemen ke stack
    word1 = stringToWord("Hello");
    word2 = stringToWord("World");

    Push(&S, word1);
    printf("Elemen '%s' ditambahkan ke stack.\n", word1.TabWord);

    Push(&S, word2);
    printf("Elemen '%s' ditambahkan ke stack.\n", word2.TabWord);

    // Menampilkan jumlah elemen dalam stack
    printf("Jumlah elemen dalam stack: %d\n", NbElmtStack(S));

    // Menghapus elemen dari stack
    Pop(&S, &poppedWord);
    printf("Elemen '%s' dihapus dari stack.\n", poppedWord.TabWord);

    // Menampilkan elemen teratas
    if (!IsEmptyStack(S)) {
        printf("Elemen teratas: %s\n", InfoTop(S).TabWord);
    }

    return 0;
}
