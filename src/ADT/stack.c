#include <stdio.h>
#include "stack.h"

void CreateEmptyStack(Stack *S)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas MaxEl */
/* jadi indeksnya antara 0.. MaxEl */
/* Ciri stack kosong : TOP berUndefai Undef */
{
    Top(*S) = Undef;
}

/* ************ Predikat Untuk test keadaan KOLEKSI ************ */
boolean IsEmptyStack(Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{
    return Top(S) == Undef;
}
boolean IsFullStack(Stack S)
/* Mengirim true jika tabel penampung Undefai elemen stack penuh */
{
    return Top(S) == MaxEl - 1;
}

/****************** Proses semua elemen Stack ******************/
int NbElmtStack(Stack S)
/* Mengirimkan banyaknya elemen Stack; mengirimkan 0 jika Stack kosong */
{
    int count = 0;
    infotypeStack dump;
    while (!IsEmptyStack(S)) {
        Pop(&S, &dump);
        count++;
    }
    return count;
}

/* ************ Menambahkan sebuah elemen ke Stack ************ */
void Push(Stack * S, infotypeStack X)
/* Menambahkan X sebagai elemen Stack S. */
/* I.S. S mungkin kosong, tabel penampung elemen stack TIDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
{
    if (!IsFullStack(*S)) {
        if (IsEmptyStack(*S)) {
            S->TOP = 0;
        } else {
            S->TOP++;
        }
        copyString(S->T[S->TOP].name, X.name, MAX_LEN);
        S->T[S->TOP].harga = X.harga;
    }
}

/* ************ Menghapus sebuah elemen Stack ************ */
void Pop(Stack * S, infotypeStack* X)
/* Menghapus X dari Stack S. */
/* I.S. S  tidak mungkin kosong */
/* F.S. X adalah Undefai elemen TOP yang lama, TOP berkurang 1 */
{
    (*X) = InfoTop(*S);
    Top(*S)--;
}
