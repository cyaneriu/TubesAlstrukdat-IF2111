#include "boolean.h"

#ifndef map_H
#define map_H

#define Nil 0
#define MaxElm 100
#define Undef -9999

// typedef int bool;
typedef char keytype[MaxElm];
typedef int valuetype;
typedef int map_address;

typedef struct {
	keytype Key;
	valuetype Value;
} infotype;

typedef struct {
	infotype Elements[MaxElm];
	map_address Count;
} Map;

/* Definisi Map M kosong : M.Count = Nil */
/* M.Count = jumlah element Map */
/* M.Elements = tempat penyimpanan element Map */

void CopyStringMap(char *dest, const char *src);

int CompareStrings(const char *key1, const char *key2);

void CreateEmptyMap(Map *M);
/* I.S. Sembarang */
/* F.S. Membuat sebuah Map M kosong berkapasitas MaxElm */
/* Ciri Map kosong : count bernilai Nil */

boolean IsMapEmpty(Map M);
/* Mengirim true jika Map M kosong*/
/* Ciri Map kosong : count bernilai Nil */

boolean IsMapFull(Map M);
/* Mengirim true jika Map M penuh */
/* Ciri Map penuh : count bernilai MaxElm */

valuetype ValueMap(Map M, keytype k);
/* Mengembalikan nilai value dengan key k dari M */
/* Jika tidak ada key k pada M, akan mengembalikan Undef */

void InsertMap(Map *M, keytype k, valuetype v);
/* Menambahkan Elmt sebagai elemen Map M dengan value v
apabila k sudah ada maka ditambahkan valuenya dengan v */
/* I.S. M mungkin kosong, M tidak penuh
        M mungkin sudah beranggotakan v dengan key k */
/* F.S. v menjadi anggota dari M dengan key k. Jika k sudah ada, value ditambah dengan nilai v */

void DeleteMap(Map *M, keytype k, valuetype v);
/* Menghapus Elmt dari Map M*/
/* I.S. M tidak kosong
        element dengan key k mungkin anggota / bukan anggota dari M */
/* F.S. element dengan key k valuenya dikurangi v
        jika kurang dari 1 maka dihapuskan dari M.*/

boolean IsMemberMap(Map M, keytype k);
/* Mengembalikan true jika k adalah member dari M */

int GetIdxMap(Map M, keytype k);
/* Mengembalikan Indeks dari key pada M*/
#endif
