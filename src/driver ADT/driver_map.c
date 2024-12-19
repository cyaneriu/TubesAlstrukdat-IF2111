#include <stdio.h>
#include "../ADT/map.h"

int main(){
    Map M;
    CreateEmptyMap(&M);
    // cek map kosong
    printf("Apakah map kosong? %s\n", IsMapEmpty(M) ? "Ya" : "Tidak");
    // testing insert element
    keytype key1 = "Key1";
    keytype key2 = "Key2";
    InsertMap(&M, key1, 10);
    InsertMap(&M, key2, 20);
    // print isi map
    printf("Isi map setelah penambahan:\n");
    for (int i = 0; i < M.Count; i++) {
        printf("Key: %s, Value: %d\n", M.Elements[i].Key, M.Elements[i].Value);
    }
    // tes insert nilai pada key yg udh ada
    InsertMap(&M, key1, 5);
    printf("Isi map setelah menambahkan nilai pada Key1:\n");
    for (int i = 0; i < M.Count; i++) {
        printf("Key: %s, Value: %d\n", M.Elements[i].Key, M.Elements[i].Value);
    }
    // tes delete element
    DeleteMap(&M, key1, 15);
    printf("Isi map setelah penghapusan Key1:\n");
    for (int i = 0; i < M.Count; i++) {
        printf("Key: %s, Value: %d\n", M.Elements[i].Key, M.Elements[i].Value);
    }
    // testing ismember
    printf("Apakah Key1 ada? %s\n", IsMemberMap(M, key1) ? "Ya" : "Tidak");
    printf("Apakah Key2 ada? %s\n", IsMemberMap(M, key2) ? "Ya" : "Tidak");
    // testing boolean map penuh
    printf("Apakah map penuh? %s\n", IsMapFull(M) ? "Ya" : "Tidak");
    return 0;
}
