#include <stdio.h>
#include "wishlist.h"
#include "../ADT/listlinier.h"
#include "work.h"

int mainWL(){
    // Nanti untuk di driver perlu buat user dan store
    // driverWL();
    return 0;
}

void driverWL(User *currentUser, Store *store, Word currentCommand){
    List wishlist = currentUser->wishlist;
    ListDin daftarBarang = store->barang;
    Word commandWL;
    commandWL.Length = currentCommand.Length - 9;
    for (int i = 0; i < commandWL.Length; i++)
    {
        commandWL.TabWord[i] = currentCommand.TabWord[i+9];
    }

    // Cek perintah apa yang dipanggil
    if (commandWL.Length == 3 && commandWL.TabWord[0] == 'A' && commandWL.TabWord[1] == 'D' && commandWL.TabWord[2] == 'D'){
        wlAdd(&wishlist, &daftarBarang);
        wlShow(&wishlist);

    } else if (commandWL.Length == 4 && commandWL.TabWord[0] == 'S' && commandWL.TabWord[1] == 'H' && commandWL.TabWord[2] == 'O' && commandWL.TabWord[3] == 'W')
    {   
        wlShow(&wishlist);

    } else if (commandWL.Length == 5 && commandWL.TabWord[0] == 'C' && commandWL.TabWord[1] == 'L' && commandWL.TabWord[2] == 'E' && commandWL.TabWord[3] == 'A' && commandWL.TabWord[4] == 'R')
    {
        wlClear(&wishlist);
        wlShow(&wishlist);

    } else if (commandWL.Length >= 4 && commandWL.TabWord[0] == 'S' && commandWL.TabWord[1] == 'W' && commandWL.TabWord[2] == 'A' && commandWL.TabWord[3] == 'P')
    {
        wlSwap(&wishlist, commandWL);
        wlShow(&wishlist);
        // pastikan dulu hanya ada 2 segmen setelah ini
        // kalau lebih otomatis dianggap tak valid
        // setelah itu masing2 segmen dicek murni angka atau tidak (jika tidak jadi invalid)
        // terakhir segmen yang valid sudah boleh dijadikan indeks

    } else if (commandWL.Length >= 6 && commandWL.TabWord[0] == 'R' && commandWL.TabWord[1] == 'E' && commandWL.TabWord[2] == 'M' && commandWL.TabWord[3] == 'O' && commandWL.TabWord[4] == 'V' && commandWL.TabWord[5] == 'E')
    {
        // ada 2 kemungkinan:
        // 1. Remove pake indeks (berarti inputnya angka saja dan 1 "segmen" saja)
        // 2. Remove pake nama (berarti inputnya tidak hanya angka dan bisa >1 "segmen")

        if (commandWL.Length == 6)
        {
            wlRemove(&wishlist, &daftarBarang);
            wlShow(&wishlist);
        } else
        {   
            wlRemoveI(&wishlist, commandWL);
            wlShow(&wishlist);
        }
        
        
    } else {
        printf("Input tak valid!\n");
    }

    // TES: print commandWL
    printf("\nCommand Wish List: |");
    for (int i = 0; i < commandWL.Length; i++)
    {
        printf("%c", commandWL.TabWord[i]);
    }
    printf("|\n\n");
}

/*void wlAdd(List *wishlist, ListDin *daftarBarang){
    // perlu dicek barangnya:
    // 1. Apakah memang ada di toko?
    // 2. Sudah ada di wishlist?
    // jika jawaban salah satunya "ya" berarti gak boleh ditambahin
    // kalau tidak tambahin saja

    // Ambil input nama barang
    Word namaBarang;
    printf("Masukkan nama barang: ");
    StartWordInput();

    // Dipastikan tak ada barang dengan nama > 50 karakter
    if (currentWord.Length > 50)
    {
        printf("Nama barang terlalu panjang!\n");
        printf("Silahkan menginput ulang\n");
        return;
    }
    namaBarang = currentWord;

    // Konversi nama barang dari Word ke string
    char stringBarang[50];
    wordToStringWork(&namaBarang, stringBarang);

    // Cek apakah barang ada dalam daftar barang yang ada di toko
    boolean barangAda = false;
    for (int i = 0; i < daftarBarang->size; i++)
    {
        if (stringCompare(stringBarang, ELMTDin(*daftarBarang, i)) == 1)
        {
            barangAda = true;
            break;
        }
    }

    // Jika tak ada input tak valid dan ditolak
    if (!barangAda)
    {
        printf("Tidak ada barang dengan nama ");
        for (int i = 0; i < stringLen(stringBarang); i++)
        {
            printf("%c", stringBarang[i]);
        }
        printf("!\n");
        return;
    }

    // Cek apakah barang memang ada di wishlist
    address alamatbarang = SearchListLinier(*wishlist, stringBarang);
    
    // Jika barang ada di wishlist
    // penambahan tak akan dilakukan
    if (alamatbarang != Nil)
    {
        printf(" sudah ada dalam wishlist!\n");
        return;
    }
    
    InsVLastListLinier(wishlist, stringBarang);
}

void wlClear(List *wishlist){
    // Semua barang di wishlist dihapus
    while (!IsEmptyListLinier(*wishlist))
    {
        address P = wishlist->First;
        DelFirstListLinier(wishlist, P);
    }
}

void wlSwap(List *wishlist, Word commandWL){
    
}

void wlRemove(List *wishlist, ListDin *daftarBarang){
    // Ambil input nama barang
    Word namaBarang;
    printf("Masukkan nama barang yang akan dihapus: ");
    StartWordInput();
    namaBarang = currentWord;

    char stringBarang[50];
    wordToStringWork(&namaBarang, stringBarang);

    // TES: cek string barang
    // for (int i = 0; i < stringLen(stringBarang); i++)
    // {
    //     printf("%c", stringBarang[i]);
    // }
    // printf("|\n");

    // Cek apakah barang ada dalam daftar barang yang ada di toko
    boolean barangAda = false;
    for (int i = 0; i < daftarBarang->size; i++)
    {
        if (stringCompare(stringBarang, ELMTDin(*daftarBarang, i)) == 1)
        {
            barangAda = true;
            break;
        }
    }

    // Jika tak ada input tak valid dan ditolak
    if (!barangAda)
    {
        printf("Tidak ada barang dengan nama ");
        for (int i = 0; i < stringLen(stringBarang); i++)
        {
            printf("%c", stringBarang[i]);
        }
        printf("!\n");
        return;
    }

    // Cek apakah barang memang ada di wishlist
    address alamatbarang = SearchListLinier(*wishlist, stringBarang);
    
    // Jika barang tak ada di wishlist
    // penambahan tak akan dilakukan
    if (alamatbarang == Nil)
    {
        printf(" tak ada dalam wishlist!\n");
        return;
    }

    // Setelah input valid, penghapusan dilakukan
    DelPListLinier(&wishlist, stringBarang);
    printf("Barang telah dihapus\n");
}

void wlRemoveI(List *wishlist, Word commandWL){
    // Cek input perintah (commandWL)
    if (commandWL.Length < 8 || commandWL.TabWord[7] == '0' || segmentCounter(commandWL) > 1)
    {
        printf("Indeks tak valid!\n");
        return;
    }

    // Masukkan bagian indeks dari input ke dalam word index
    Word index;
    index.Length = commandWL.Length - 7;
    for (int i = 0; i < commandWL.Length ; i++)
    {
        index.TabWord[i] = commandWL.TabWord[i+7];
    }

    // Cek apakah indeks hanya berisi angka saja
    boolean idxValid = true;
    for (int i = 0; i < index.Length; i++)
    {
        if (!(index.TabWord[i] == '0' || index.TabWord[i] == '1' || index.TabWord[i] == '2' || index.TabWord[i] == '3' || index.TabWord[i] == '4' || index.TabWord[i] == '5' || index.TabWord[i] == '6' || index.TabWord[i] == '7' || index.TabWord[i] == '8' || index.TabWord[i] == '9'))
        {
            idxValid = false;
            break;
        }
    }
    if (!idxValid)
    {
        printf("Indeks tak valid!\n");
        return;
    }
    
    // Apabila indeks sudah pasti berisi angka, ubah menjadi integer
    char stringIndex[100];
    wordToStringWork(&index, stringIndex);
    int angkaIndex = 0;
    for (int i = 0; stringIndex[i] != '\0'; i++) {
    angkaIndex = angkaIndex * 10 + (stringIndex[i] - '0');
    }

    // Cek apakah indeks valid (berada dalam wishlist)
    // Indeks harus dikurangi 1 karena merupakan urutan barang di wishlist
    // yang dimulai dari 1 (sementara indeks dalam struktur data dimulai dari 0)

    if (angkaIndex-1 > NbElmtListLinier(*wishlist))
    {
        printf("Indeks tak valid!\n");
        return;
    }
    angkaIndex--;
    
    // Cari barang secara traversal
    // angkaIndex sudah pasti valid
    int idxWL = 0;
    address alamatBarang = Nil;
    address P = wishlist->First;
    while (idxWL != angkaIndex)
    {
        P = P->next;
        idxWL++;
    }
    DelPListLinier(wishlist, P->info);
}

void wlShow(List *wishlist){
    PrintInfoListLinier(*wishlist);
}
*/