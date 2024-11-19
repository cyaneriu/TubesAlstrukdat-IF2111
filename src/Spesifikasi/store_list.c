#include "store_list.h"
#include "store.h"

int main() {
    Store myStore;
    initStore(&myStore, 10);

    // Tambahkan barang ke toko
    insertLast(&(myStore.barang), "Platypus Laser");
    insertLast(&(myStore.barang), "Shrink Ray");
    insertLast(&(myStore.barang), "Net Shooter");

    // Tampilkan barang di toko
    printf(">> STORE LIST\n");
    displayStore(myStore);

    // Toko kosong
    dealocateList(&(myStore.barang));
    printf("\n>> STORE LIST\n");
    displayStore(myStore);

    return 0;
}
