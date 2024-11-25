#include <stdio.h>
#include <stdlib.h>
#include "../ADT/list_statik.h"

//TERMINAL COMMAND:
//gcc driver_list_statik.c ../ADT/list_statik.c -o list_statik
//./list_statik

int main() {
    ListStatik list;
    ElType val;
    IdxType idx;

    // 1. CreateListStatik
    printf("CreateListStatik\n");
    CreateListStatik(&list);
    printf("List telah dibuat, kapasitas: %d\n\n", STAT_CAPACITY);

    // 2. isEmptyStatik
    printf("isEmptyStatik\n");
    printf("Apakah list kosong? %s\n\n", isEmptyStatik(list) ? "Ya" : "Tidak");

    // 3. isFullStatik
    printf("isFullStatik\n");
    printf("Apakah list penuh? %s\n\n", isFullStatik(list) ? "Ya" : "Tidak");

    // 4. listLengthStatik
    printf("listLengthStatik\n");
    printf("Panjang list: %d\n\n", listLengthStatik(list));

    // 5. getFirstIdxStatik
    printf("getFirstIdxStatik\n");
    printf("Indeks pertama: %d\n\n", getFirstIdxStatik(list));

    // 6. getLastIdxStatik
    printf("getLastIdxStatik\n");
    printf("Indeks terakhir: %d\n\n", getLastIdxStatik(list));

    // 7. insertAtStatik
    printf("insertAtStatik\n");
    printf("Masukkan elemen 10 di indeks 0\n");
    insertAtStatik(&list, 10, 0);
    printf("Masukkan elemen 20 di indeks 1\n");
    insertAtStatik(&list, 20, 1);
    printf("Panjang list sekarang: %d\n\n", listLengthStatik(list));

    // 8. printListStatik
    printf("printListStatik\n");
    printf("Isi list:\n");
    printListStatik(list);
    printf("\n");

    // 9. deleteAtStatik
    printf("deleteAtStatik\n");
    printf("Hapus elemen di indeks 0\n");
    deleteAtStatik(&list, &val, 0);
    printf("Elemen yang dihapus: %d\n", val);
    printf("Isi list sekarang:\n");
    printListStatik(list);
    printf("\n");

    // 10. sortListStatik
    printf("sortListStatik\n");
    printf("Masukkan elemen 30 di indeks 1\n");
    insertAtStatik(&list, 30, 1);
    printf("Masukkan elemen 100 di indeks 0\n");
    insertAtStatik(&list, 100, 0);
    printf("Sebelum sort:\n");
    printListStatik(list);
    printf("Setelah sort:\n");
    sortListStatik(&list, true);
    printListStatik(list);
    printf("\n");

    return 0;
}
