#include "list_statik.h"
#include <stdio.h>

void CreateListStatik(ListStatik *l) {
    for (IdxType i = 0; i < STAT_CAPACITY; i++) {
        ELMTStat(*l, i) = STAT_MARK;
    }
}

int listLengthStatik(ListStatik l) {
    int count = 0;
    while (count < STAT_CAPACITY && ELMTStat(l, count) != STAT_MARK) {
        count++;
    }
    return count;
}

IdxType getFirstIdxStatik(ListStatik l) {
    return (listLengthStatik(l) > 0) ? 0 : IDX_UNDEF;
}

IdxType getLastIdxStatik(ListStatik l) {
    int len = listLengthStatik(l);
    return (len > 0) ? len - 1 : IDX_UNDEF;
}

boolean isEmptyStatik(ListStatik l) {
    return listLengthStatik(l) == 0;
}

boolean isFullStatik(ListStatik l) {
    return listLengthStatik(l) == STAT_CAPACITY;
}

void readListStatik(ListStatik *l) {
    // Membaca elemen-elemen list dari input
    IdxType idx = 0;
    while (idx < STAT_CAPACITY) {
        printf("Masukkan elemen ke-%d (masukkan %d untuk berhenti): ", idx + 1, STAT_MARK);
        scanf("%d", &ELMTStat(*l, idx));
        if (ELMTStat(*l, idx) == STAT_MARK) break;
        idx++;
    }
}

void printListStatik(ListStatik l) {
    // Mencetak semua elemen dalam list
    int len = listLengthStatik(l);
    if (len == 0) {
        printf("List kosong.\n");
    } else {
        for (int i = 0; i < len; i++) {
            printf("Elemen ke-%d: %d\n", i + 1, ELMTStat(l, i));
        }
    }
}

void insertAtStatik(ListStatik *l, ElType val, IdxType idx) {
    // Menyisipkan elemen pada posisi tertentu, dengan shift elemen setelahnya
    int len = listLengthStatik(*l);
    if (idx >= 0 && idx <= len && len < STAT_CAPACITY) {
        for (int i = len; i > idx; i--) {
            ELMTStat(*l, i) = ELMTStat(*l, i - 1);
        }
        ELMTStat(*l, idx) = val;
    }
}

void deleteAtStatik(ListStatik *l, ElType *val, IdxType idx) {
    // Menghapus elemen pada indeks tertentu, dengan shift elemen setelahnya
    int len = listLengthStatik(*l);
    if (idx >= 0 && idx < len) {
        *val = ELMTStat(*l, idx);
        for (int i = idx; i < len - 1; i++) {
            ELMTStat(*l, i) = ELMTStat(*l, i + 1);
        }
        ELMTStat(*l, len - 1) = STAT_MARK;  // Elemen terakhir di-set ke STAT_MARK
    }
}

void sortListStatik(ListStatik *l, boolean asc) {
    // Mengurutkan elemen dalam list
    int len = listLengthStatik(*l);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            boolean swapCondition = (asc) ? (ELMTStat(*l, i) > ELMTStat(*l, j)) : (ELMTStat(*l, i) < ELMTStat(*l, j));
            if (swapCondition) {
                // Swap elemen
                ElType temp = ELMTStat(*l, i);
                ELMTStat(*l, i) = ELMTStat(*l, j);
                ELMTStat(*l, j) = temp;
            }
        }
    }
}