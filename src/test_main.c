#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ADT/list_dinamis.h"
#include "Spesifikasi/store.h"
#include "Spesifikasi/store_list.h"

int main() {
    Store store;
    createStore(&store);
    displayStore(store);

    return 0;
}