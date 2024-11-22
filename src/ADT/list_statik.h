#ifndef LIST_STATIK_H
#define LIST_STATIK_H

#include "boolean.h"
#include "list.h"


#define STAT_CAPACITY 100
#define STAT_MARK -9999

// Struktur data list statik
typedef struct {
    ElType contents[STAT_CAPACITY];
} ListStatik;

// Makro akses elemen
#define ELMTStat(l, i) (l).contents[(i)]

// Fungsi-fungsi untuk list statik
void CreateListStatik(ListStatik *l);
int listLengthStatik(ListStatik l);
IdxType getFirstIdxStatik(ListStatik l);
IdxType getLastIdxStatik(ListStatik l);
boolean isEmptyStatik(ListStatik l);
boolean isFullStatik(ListStatik l);
void readListStatik(ListStatik *l);
void printListStatik(ListStatik l);
void insertAtStatik(ListStatik *l, ElType val, IdxType idx);
void deleteAtStatik(ListStatik *l, ElType *val, IdxType idx);
void sortListSTatik(ListStatik *l, boolean asc);

#endif
