#include <stdio.h>
#include <stdlib.h>
#include "../ADT/list_dinamis.h"

//TERMINAL COMMAND:
//gcc driver_list_dinamis.c ../ADT/list_dinamis.c -o list_dinamis
//./list_dinamis

int main() {
    ListDin list;
    int capacity = 5;

    // 1. CreateListDin
    printf("CreateListDin\n");
    CreateListDin(&list, capacity);
    printf("List telah dibuat, kapasitas: %d\n\n", capacity);

    // 2. isEmptyDin
    printf("isEmptyDin\n");
    printf("Apakah list kosong? %s\n\n", isEmptyDin(list)? "Ya" : "Tidak");

    // 3. insertLastDin
    printf("insertLastDin\n");
    insertLastDin(&list, "x");
    insertLastDin(&list, "y");
    insertLastDin(&list, "z");
    printf("Masukkan item x, y, z\n");
    printf("Panjang list sekarang: %d\n\n", listLengthDin(list));

    // 4. ELMTDin
    printf("ELMTDin\n");
    for (int i = 0; i < listLengthDin(list); i++) {
        printf("Element at index %d: %s\n", i, ELMTDin(list, i));
    }
    printf("\n");

    // 5. deleteAtDin
    printf("deleteAtDin\n");
    printf("Hapus item di index 1\n");
    deleteAtDin(&list, 1);
    printf("Hasil:\n");
    for (int i = 0; i < listLengthDin(list); i++) {
        printf("Element at index %d: %s\n", i, ELMTDin(list, i));
    }
    printf("\n");

    // 6. deleteFirstDin
    printf("deleteFirstDin\n");
    deleteFirstDin(&list);
    printf("Hasil:\n");
    for (int i = 0; i < listLengthDin(list); i++) {
        printf("Element at index %d: %s\n", i, ELMTDin(list, i));
    }
    printf("\n");

    // 7. copyFirstDin
    printf("copyFirstDin\n");
    char firstItem[100];
    copyFirstDin(list, firstItem);
    printf("First item copied to: %s\n\n", firstItem);

    // 8. dealocateListDin
    printf("dealocateListDin\n");
    dealocateListDin(&list);
    printf("List deallocated. Apakah list kosong? %s\n", isEmptyDin(list) ? "Ya" : "Tidak");

    return 0;
}
