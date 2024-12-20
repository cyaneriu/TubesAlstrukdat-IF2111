#include <stdio.h>
#include <stdlib.h>
#include "arraydin.h"

/**
 * Konstruktor
 * I.S. sembarang
 * F.S. Terbentuk ArrayDin kosong dengan ukuran InitialSize
 */
ArrayDin MakeArrayDin() {
    ArrayDin Ad;
    Ad.A = (Barang *) malloc(InitialSize * sizeof(Barang));
    Ad.Capacity = InitialSize;
    Ad.Neff = 0;
    return Ad;
}

void DeallocateArrayDin(ArrayDin *Ad) {
    free(Ad->A);
}

/**
 * Fungsi untuk mengetahui apakah suatu array kosong.
 * Prekondisi: array terdefinisi
 */
boolean IsEmpty(ArrayDin Ad) {
    return Ad.Neff == 0;
}

/**
 * Fungsi untuk mendapatkan banyaknya elemen efektif array, 0 jika tabel kosong.
 * Prekondisi: array terdefinisi
 */
int Length(ArrayDin Ad) {
    return Ad.Neff;
}

/**
 * Mengembalikan elemen array L yang ke-I (indeks lojik).
 * Prekondisi: array tidak kosong, i di antara 0..Length(array).
 */
Barang Get(ArrayDin Ad, IdxType i) {
    return Ad.A[i];
}

/**
 * Fungsi untuk mendapatkan kapasitas yang tersedia.
 * Prekondisi: array terdefinisi
 */
int GetCapacity(ArrayDin Ad) {
    return Ad.Capacity;
}

/**
 * Fungsi untuk menambahkan elemen baru di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 * Jika array penuh, maka array akan diperbesar sebanyak InitialSize.
 */
void InsertAt(ArrayDin *Ad, Barang el, IdxType i) {
    int length = Length(*Ad);
    int capacity = GetCapacity(*Ad);

    if (length == capacity) {
        int desiredCapacity = capacity + InitialSize;
        Barang *arr = (Barang *) malloc(desiredCapacity * sizeof(Barang));
        for (int a = 0; a < length; a++) {
            arr[a] = Get(*Ad, a);
        }
        free(Ad->A);
        
        Ad->A = arr;
        Ad->Capacity = desiredCapacity;
    }

    for (int a = length - 1; a >= i; a--) {
        Ad->A[a + 1] = Ad->A[a];
    }

    Ad->A[i] = el;
    Ad->Neff++;
}

/**
 * Fungsi untuk menambahkan elemen baru di akhir array.
 * Prekondisi: array terdefinisi
 */
void InsertLast(ArrayDin *Ad, Barang el) {
    int insertAt = Length(*Ad);
    InsertAt(Ad, el, insertAt);
}

/**
 * Fungsi untuk menambahkan elemen baru di awal array.
 * Prekondisi: array terdefinisi
 */
void InsertFirst(ArrayDin *Ad, Barang el) {
    InsertAt(Ad, el, 0);
}

/**
 * Fungsi untuk menghapus elemen di index ke-i
 * Prekondisi: array terdefinisi, i di antara 0..Length(array).
 */
void DeleteAt(ArrayDin *Ad, IdxType i) {
    int length = Length(*Ad);
    for (int a = i; a < length - 1; a++) {
        Ad->A[a] = Ad->A[a + 1];
    }
    Ad->Neff--;
}

/**
 * Fungsi untuk menghapus elemen terakhir ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteLast(ArrayDin *Ad) {
    int deleteAt = Length(*Ad) - 1;
    DeleteAt(Ad, deleteAt);
}

/**
 * Fungsi untuk menghapus elemen pertama ArrayDin
 * Prekondisi: array tidak kosong
 */
void DeleteFirst(ArrayDin *Ad) {
    DeleteAt(Ad, 0);
}

/**
 * Fungsi untuk melakukan print suatu ArrayDin.
 * Print dilakukan dengan format: [elemen-1, elemen-2, ..., elemen-n]
 * dan diakhiri newline.
 * Prekondisi: array terdefinisi
 */
void PrintArrayDin(ArrayDin Ad) {
    if (IsEmpty(Ad)) {
        printf("[]\n");
    } else {
        printf("[");
        for (int i = 0; i < Ad.Neff; i++) {
            printf("%d", Ad.A[i]);
            if (i < Ad.Neff - 1) {
                printf(", ");
            }
        }
        printf("]\n");
    }
}

/**
 * Fungsi untuk melakukan reverse suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
void ReverseArrayDin(ArrayDin *Ad) {
    int length = Length(*Ad);
    for (int i = 0; i < length / 2; i++) {
        Barang temp = Ad->A[i];
        Ad->A[i] = Ad->A[length - i - 1];
        Ad->A[length - i - 1] = temp;
    }
}

/**
 * Fungsi untuk melakukan copy suatu ArrayDin.
 * Prekondisi: array terdefinisi
 */
ArrayDin CopyArrayDin(ArrayDin Ad) {
    ArrayDin copy = MakeArrayDin();
    for (int i = 0; i < Ad.Neff; i++) {
        InsertLast(&copy, Ad.A[i]);
    }
    return copy;
}

/**
 * Fungsi untuk melakukan search suatu ArrayDin.
 * Index pertama yang ditemukan akan dikembalikan.
 * Jika tidak ditemukan, akan mengembalikan -1.
 * Prekondisi: array terdefinisi
 */
IdxType SearchArrayDin(ArrayDin Ad, char *el) {
    Word word = stringToWord(el); 
    for (int i = 0; i < Ad.Neff; i++) {
        Word currentItem;
        copyString(currentItem.TabWord, Ad.A[i].name, MAX_LEN);
        currentItem.Length = stringLen(Ad.A[i].name);
        if (isEqualWords(currentItem, word.TabWord)) {
            return i; 
        }
    }
    return -1; 
}
