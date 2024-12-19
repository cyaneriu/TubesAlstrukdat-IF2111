// #include <stdio.h>
// #include <stdlib.h>
// #include "./Spesifikasi/load.h"
// #include "./Spesifikasi/save.h"
// #include "./Spesifikasi/quit.h"
// #include "./Spesifikasi/work.h"

// #include <stdio.h>
// #include <stdlib.h>
// void PopRiwayat(Stack *S, infotypeStack *item) {
//     Pop(S, item);
// }


// void DisplayRiwayat(Stack S) {
//     printf("  Riwayat Pembelian:\n");
//     if (IsEmptyStack(S)) {
//         printf("    (Tidak ada riwayat pembelian)\n");
//     } else {
//         while (!IsEmptyStack(S)) {
//             infotypeStack item;
//             PopRiwayat(&S, &item); // Pop elemen dari stack
//             printf("    - Barang: %s, Harga: %d\n", item.name, item.harga);
//         }
//     }
// }

// int main() {
//     boolean program = true;
//     boolean session = false;
//     char * state;
//     Barang barang[MAX_BARANG];
//     User user[MAX_USER];
//     int input;
//     int jumlahBarang = 0; 
//     int jumlahUser = 0;
//     char * filename;
//     char * item;
//     int isiRekening = 0;
//     char temporary[100];

//     while (program) {
        

//         printf(">> ");
//         StartCommand();

//         if (IsCommandEqual(currentCommand, "START\0")) {
//             session = true;
//             filename = "default.txt";
//             startLoad(filename, barang, &jumlahBarang, user, &jumlahUser);
//             // Menampilkan data barang
//             printf("Daftar Barang di PURRMART:\n");
//             for (int i = 0; i < jumlahBarang; i++) {
//                 printf("  %d. Nama: %s, Harga: %d\n", i + 1, barang[i].name, barang[i].price);
//             }
//             printf("\n");

//             // Menampilkan data pengguna beserta riwayat pembeliannya
//             printf("Daftar Pengguna dan Riwayat Pembeliannya:\n");
//             for (int i = 0; i < jumlahUser; i++) {
//                 printf("- Nama: %s\n", user[i].name);
//                 printf("  Password: %s\n", user[i].password);
//                 printf("  Uang: %d\n", user[i].money);

//             // Menampilkan riwayat pembelian
//                 DisplayRiwayat(user[i].riwayat_pembelian);

//                 printf("\n");
//                 printf("  Wishlist:\n");
//                 PrintInfoListLinier(user[i].wishlist);
//         }
//         } else if (IsCommandEqual(currentCommand, "LOAD\0")) {
//             ADVInput();
//             wordToStringWork(&currentCommand, temporary);
//             filename = temporary;
//             //Load(&filename, barang, &jumlahBarang, user, &jumlahUser);
//             startLoad(filename, barang, &jumlahBarang, user, &jumlahUser);
//             printf("%d\n", jumlahBarang);
//             printf("%d\n", jumlahUser);
//             // Menampilkan data barang
//             printf("Daftar Barang di PURRMART:\n");
//             for (int i = 0; i < jumlahBarang; i++) {
//                 printf("  %d. Nama: %s, Harga: %d\n", i + 1, barang[i].name, barang[i].price);
//             }
//             printf("\n");

//             // Menampilkan data pengguna beserta riwayat pembeliannya
//             printf("Daftar Pengguna dan Riwayat Pembeliannya:\n");
//             for (int i = 0; i < jumlahUser; i++) {
//                 printf("- Nama: %s\n", user[i].name);
//                 printf("  Password: %s\n", user[i].password);
//                 printf("  Uang: %d\n", user[i].money);

//             // // Menampilkan riwayat pembelian
//                 DisplayRiwayat(user[i].riwayat_pembelian);

//                 printf("\n");
//                 printf("  Wishlist:\n");
//                 PrintInfoListLinier(user[i].wishlist);
//             }
//         }
//         else if (IsCommandEqual(currentCommand, "SAVE\0")) {
//             ADVInput();
//             wordToStringWork(&currentCommand, temporary);
//             filename = temporary;
//             //Load(&filename, barang, &jumlahBarang, user, &jumlahUser);
//             startSave(filename, barang, &jumlahBarang, user, &jumlahUser);
//         } 
//     }
//     return 0;
// }
// //  gcc -o p coba_load_save.c ./ADT/stack.c ./ADT/mesinkata.c ./ADT/mesinkarakter.c ./Spesifikasi/load.c ./Spesifikasi/work.c ./ADT/listlinier.c ./ADT/map.c ./Spesifikasi/save.c