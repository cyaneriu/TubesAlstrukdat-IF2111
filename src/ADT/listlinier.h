#ifndef listlinier_H
#define listlinier_H

#include <stdlib.h>
#include "mesinkata.h"
#include "boolean.h"

#define NilLL NULL

typedef char infotypeLL;
typedef struct tElmtlist *addressLL;
typedef struct tElmtlist { 
	infotypeLL info[MAX_LEN];
	addressLL next;
} ElmtList;

typedef struct {
	addressLL First;
	char Name[MAX_LEN];
} LinkedList;

/* Definisi list : */
/* List kosong : First(L) = Nil */
/* Setiap elemen dengan address P dapat diacu Info(P), Next(P) */
/* Elemen terakhir list : jika addressnya Last, maka Next(Last)=Nil */
#define Info(P) (P)->info
#define Next(P) (P)->next
#define First(L) ((L).First)

/* PROTOTYPE */
boolean IsEmptyLL (LinkedList L);
/* Mengirim true jika list kosong */

void CreateEmptyLL (LinkedList *L);
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

addressLL AlokasiLL (infotypeLL* X);
/* Mengirimkan address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka address tidak nil, dan misalnya */
/* menghasilkan P, maka info(P)=X, Next(P)=Nil */
/* Jika alokasi gagal, mengirimkan Nil */
void Dealokasi (addressLL *P);
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
boolean isMemberLL(LinkedList L, char* songName);

/****************** PRIMITIF BERDASARKAN NILAI ******************/

void InsertLastLL(LinkedList* L, infotypeLL* X);

int NbElmt (LinkedList L);

void displayLinkedList(LinkedList L);

void swapLinkedList(LinkedList* L, int x, int y);

char* GetLL(LinkedList L, int idx);

void delLLidx(LinkedList* L, int idx);

#endif