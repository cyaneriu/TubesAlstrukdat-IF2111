#ifndef LIST_STATIK_H
#define LIST_STATIK_H

#include "boolean.h"

#define CAPACITY 100

#define IDX_MIN 0

#define IDX_UNDEF -1

#define MARK -9999

typedef int ElType; 
typedef int IdxType;
typedef struct {
   ElType contents[CAPACITY];
} ListStatik;

#define ELMT(l, i) (l).contents[(i)]

void CreateListStatik(ListStatik *l);

int listLength(ListStatik l);

IdxType getFirstIdx(ListStatik l);

IdxType getLastIdx(ListStatik l);

boolean isIdxValid(ListStatik l, IdxType i);

boolean isIdxEff(ListStatik l, IdxType i);

boolean isEmpty(ListStatik l);

boolean isFull(ListStatik l);

void readList(ListStatik *l);

void printList(ListStatik l);

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus);

boolean isListEqual(ListStatik l1, ListStatik l2);

int indexOf(ListStatik l, ElType val);

void extremeValues(ListStatik l, ElType *max, ElType *min);

void insertFirst(ListStatik *l, ElType val);

void insertAt(ListStatik *l, ElType val, IdxType idx);

void insertLast(ListStatik *l, ElType val);

void deleteFirst(ListStatik *l, ElType *val);

void deleteAt(ListStatik *l, ElType *val, IdxType idx);

void deleteLast(ListStatik *l, ElType *val);

void sortList(ListStatik *l, boolean asc);

#endif