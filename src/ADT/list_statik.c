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

// Implementasi fungsi lainnya dapat ditambahkan
