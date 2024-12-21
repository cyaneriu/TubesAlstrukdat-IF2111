#include <stdio.h>
#include "wishlist_ld.h"
#include "../ADT/list_dinamis.h"
#include "work.h"

// int main(){
//     driverWLLD1();
//     return 0;
// }

void driverWLLD1(){
    // Word testSC;
    // StartWordInput();
    // testSC = currentWord;
    // int segmenCount = segmentCounter(testSC);
    
    // return;

    ListDin wishlist;
    CreateListDin(&wishlist, 100);

    // TES: mengecek apakah alokasi wishlist berhasil
    // if (isEmptyDin(wishlist))
    // {
    //     printf("Wishlist Kosong\n");
    // }

    char itemTes1[] = "Doom Inator";
    char itemTes2[] = "Restoran Najwa Shihab";
    insertLastDin(&wishlist, itemTes1);
    insertLastDin(&wishlist, itemTes2);

    for (int i = 0; i < listLengthDin(wishlist); i++)
    {
        printf("%d. %s\n", i+1, ELMTDin(wishlist, i));
    }

    // DAFTAR BARANG DI TOKO
    ListDin daftarBarang;
    CreateListDin(&daftarBarang, 100);

    insertLastDin(&daftarBarang, "Doom Inator");
    insertLastDin(&daftarBarang, "Payung Platipus");
    insertLastDin(&daftarBarang, "Bendungan Cikapundung");
    insertLastDin(&daftarBarang, "Restoran Najwa Shihab");

    // int counterDrive = 0;

    int test = 1;
    while (test)
    {
        wishlistTest(&wishlist, &daftarBarang);
    }
}

void wishlistTest(ListDin *wishlist, ListDin *daftarBarang){
    Word input;
    Word cekWishlist;
    StartWordInput();
    input = currentWord;
    // int cnt = segmentCounter(input);
    // printf("%d\n", cnt);

    // input.TabWord[length] = '\0'
    // return;

    // for (int i = 0; i < input.Length; i++)
    // {
    //     printf("%c", input.TabWord[i]);
    // }
    // printf("|\n");
    // return;

    cekWishlist.Length = 8;
    cekWishlist.TabWord[0] = 'W';
    cekWishlist.TabWord[1] = 'I';
    cekWishlist.TabWord[2] = 'S';
    cekWishlist.TabWord[3] = 'H';
    cekWishlist.TabWord[4] = 'L';
    cekWishlist.TabWord[5] = 'I';
    cekWishlist.TabWord[6] = 'S';
    cekWishlist.TabWord[7] = 'T';

    boolean isWL = true;
    for (int i = 0; i < 8; i++)
    {
        if (cekWishlist.TabWord[i] != input.TabWord[i]) isWL = false;
    }
    // TES: print isWL
    // printf("Is WL: %d\n", isWL);

    if (isWL)
    {
        Word commandWL;
        commandWL.Length = input.Length - 9;
        for (int i = 0; i < commandWL.Length; i++)
        {
            commandWL.TabWord[i] = input.TabWord[i+9];
        }
        

        if (commandWL.Length == 3 && commandWL.TabWord[0] == 'A' && commandWL.TabWord[1] == 'D' && commandWL.TabWord[2] == 'D')
        {
            wlAdd(wishlist, daftarBarang);
            wlShow(wishlist);

        } else if (commandWL.Length == 4 && commandWL.TabWord[0] == 'S' && commandWL.TabWord[1] == 'H' && commandWL.TabWord[2] == 'O' && commandWL.TabWord[3] == 'W')
        {   
            wlShow(wishlist);

        } else if (commandWL.Length == 5 && commandWL.TabWord[0] == 'C' && commandWL.TabWord[1] == 'L' && commandWL.TabWord[2] == 'E' && commandWL.TabWord[3] == 'A' && commandWL.TabWord[4] == 'R')
        {
            wlClear(wishlist);
            wlShow(wishlist);

        } else if (commandWL.Length >= 4 && commandWL.TabWord[0] == 'S' && commandWL.TabWord[1] == 'W' && commandWL.TabWord[2] == 'A' && commandWL.TabWord[3] == 'P')
        {
            // siap2 swap

            // printf("wlSwap\n");
            wlSwap(wishlist, commandWL);
            wlShow(wishlist);
            // pastikan dulu hanya ada 2 segmen setelah ini
            // kalau lebih otomatis dianggap tak valid
            // setelah itu masing2 segmen dicek murni angka atau tidak (jika tidak jadi invalid)
            // terakhir segmen yang valid sudah boleh dijadikan indeks

        } else if (commandWL.Length >= 6 && commandWL.TabWord[0] == 'R' && commandWL.TabWord[1] == 'E' && commandWL.TabWord[2] == 'M' && commandWL.TabWord[3] == 'O' && commandWL.TabWord[4] == 'V' && commandWL.TabWord[5] == 'E')
        {
            // siap2 remove
            // ada 2 kemungkinan:
            // 1. Remove pake indeks (berarti inputnya angka saja dan 1 "segmen" saja)
            // 2. Remove pake nama (berarti inputnya tidak hanya angka dan bisa >1 "segmen")

            // printf("wlRemove\n");
            if (commandWL.Length == 6)
            {
                wlRemove(wishlist, daftarBarang);
                wlShow(wishlist);
            } else
            {   
                wlRemoveI(wishlist, commandWL);
                wlShow(wishlist);
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
    } else {
        printf("Input tak valid!\n");
        return;
    }
}

int segmentCounter(Word kata){
    int segmenCount = 0;
    int idx = 0;
    char currentCharacter;
    char nextCharacter;
    currentCharacter = kata.TabWord[idx];
    // printf("%d\n", kata.Length);
    // return kata.Length;

    while (idx < kata.Length)
    {
        boolean isInSegment = false;
        if (idx == kata.Length - 1) {
            nextCharacter = '\0';
        } else {
            nextCharacter = kata.TabWord[idx+1];
        }
        // printf("Current Character: %c || Next Character: %c\n", currentCharacter, nextCharacter);
        if (currentCharacter == ' ' && segmenCount == 0){
            idx++;
            continue;
        }

        if (currentCharacter != ' ')
        {
            isInSegment = true;
        }
        if (isInSegment == true && (nextCharacter == ' ' || nextCharacter == '\0' || nextCharacter == '\n'))
        {
            isInSegment = false;
            segmenCount++;
        }
        
        idx++;
        currentCharacter = kata.TabWord[idx];
        // printf("IsInSegment: %d\n\n", isInSegment);
    }
    // printf("Segmen:  %d\n", segmenCount);
    return segmenCount;
}

void wlAdd(ListDin *wishlist, ListDin *daftarBarang){
    // perlu dicek barangnya:
    // 1. Apakah memang ada di toko?
    // 2. Sudah ada di wishlist?
    // jika jawaban salah satunya "ya" berarti gak boleh ditambahin
    // kalau tidak tambahin saja

    // Ambil input nama barang
    Word namaBarang;
    printf("Masukkan nama barang: ");
    StartWordInput();
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
    boolean barangDiWishlist = false;
    for (int i = 0; i < wishlist->size; i++)
    {
        if (stringCompare(stringBarang, ELMTDin(*wishlist, i)) == 1)
        {
            barangDiWishlist = true;
            break;
        }
    }
    
    // Jika barang ada di wishlist
    // penambahan tak akan dilakukan
    if (barangDiWishlist)
    {
        for (int i = 0; i < stringLen(stringBarang); i++)
        {
            printf("%c", stringBarang[i]);
        }
        printf(" sudah ada dalam wishlist!\n");
        return;
    }

    insertLastDin(wishlist, stringBarang);
}

void wlClear(ListDin *wishlist){
    // semua barang di wishlist dihapus
    for (int i = 0; i < listLengthDin(*wishlist); i++)
    {
        deleteFirstDin(wishlist);
    }
}

void wlSwap(ListDin *wishlist, Word commandWL){    
    // Ambil input perintah
    // Cek apakah hanya terdiri atas 3 segmen
    // segmen "SWAP", "<i>", "<j>"
    int segmentCount = segmentCounter(commandWL);
    printf("%d\n", segmentCount);

    // Jika input tak terdiri atas 3 segmen, ditolak
    if (segmentCount != 3)
    {
        printf("Indeks tak valid!\n");
        return;
    }

    // Setelah divalidasi, segmen <i> dan <j> akan diambil
    Word indexSwap;
    indexSwap.Length = commandWL.Length - 5;
    // printf("indexSwap length: %d\n\n", indexSwap.Length);

    for (int i = 0; i < indexSwap.Length; i++)
    {
        indexSwap.TabWord[i] = commandWL.TabWord[i+5];
    }
    indexSwap.TabWord[indexSwap.Length] = '\0';

    // TES: cek isi commandWL
    // for (int i = 0; i < commandWL.Length; i++)
    // {
    //     printf("%c", commandWL.TabWord[i]);
    // }
    // printf("\n");
    
    // TES: Cek isi indexSwap keseluruhan (indeks i dan j)
    // printf("|");
    // for (int i = 0; i < indexSwap.Length; i++)
    // {
    //     printf("%c", indexSwap.TabWord[i]);
    // }
    // printf("|\n");

    // Ada 3 tahap pengambilan
    // 1. Masukkan tiap segmen indeks ke word indeks masing2
    // 2. Ubah word menjadi string
    // 3. Ubah string menjadi integer
    Word indeksI;
    Word indeksJ;
    char strI[100];
    char strJ[100];
    for (int i = 0; i < 100; i++)
    {
        strI[i] = ' ';
        strJ[i] = ' ';
    }
    
    // Langkah 1. Masukkan segmen indeks ke word
    int idxWordI = 0, idxI = 0;
    int idxWordJ = 0, idxJ = 0;
    indeksI.Length = idxWordI;
    indeksJ.Length = idxWordJ;

    boolean inSegment = false;

    int idx = 0;
    char currentCharacter = indexSwap.TabWord[idx];
    char nextCharacter = indexSwap.TabWord[idx+1];

    // TES: cek karakter saat ini dan selanjutnya
    // printf("currentCharacter: |%c|\n", currentCharacter);
    // printf("nextCharacter: |%c|\n", nextCharacter);

    // Abaikan semua spasi sebelum indeks i
    while (currentCharacter == ' ')
    {
        idx++;
        currentCharacter = indexSwap.TabWord[idx];
        nextCharacter = indexSwap.TabWord[idx+1];
    }

    // Akuisisi semua string di indeks i
    while (currentCharacter != ' ')
    {
        printf("idxWordI: %d\n", idxWordI);
        indeksI.TabWord[idxWordI] = currentCharacter;
        idxWordI++;
        indeksI.Length = idxWordI;
        indeksI.TabWord[idxWordI] = '\0';
        
        idx++;
        currentCharacter = indexSwap.TabWord[idx];
        nextCharacter = indexSwap.TabWord[idx+1];

        // TES: cek currentCharacter dan nextCharacter
        // printf("currentCharacter: |%c|\n", currentCharacter);
        // printf("nextCharacter: |%c|\n", nextCharacter);
    }

    // TES: cek isi indeksI
    // printf("\nIndeksI: ");
    // for (int i = 0; i < idxWordI; i++)
    // {
    //     printf("%c", indeksI.TabWord[i]);
    // }
    // printf("\n\n");

    // TES: cek karakter saat ini dan selanjutnya setelah akuisisi i
    // printf("currentCharacter: |%c|\n", currentCharacter);
    // printf("nextCharacter: |%c|\n", nextCharacter);

    // Abaikan semua spasi sebelum indeks j
    while (currentCharacter == ' ')
    {
        idx++;
        currentCharacter = indexSwap.TabWord[idx];
        nextCharacter = indexSwap.TabWord[idx+1];
    }

    // TES: cek karakter saat ini dan selanjutnya
    // setelah mengabaikan spasi
    // printf("\n------------------\n");
    // printf("currentCharacter: |%c|\n", currentCharacter);
    // printf("nextCharacter: |%c|\n", nextCharacter);
    // printf("------------------\n");

    // Akuisisi semua string di indeks j
    while (currentCharacter != ' ' && currentCharacter != '\0')
    {
        printf("idxWordJ: %d\n", idxWordJ);
        indeksJ.TabWord[idxWordJ] = currentCharacter;
        idxWordJ++;
        indeksJ.Length = idxWordJ;
        indeksJ.TabWord[idxWordJ] = '\0';
        
        idx++;
        currentCharacter = indexSwap.TabWord[idx];
        nextCharacter = indexSwap.TabWord[idx+1];

        // TES: cek currentCharacter dan nextCharacter
        // printf("currentCharacter: |%c|\n", currentCharacter);
        // printf("nextCharacter: |%c|\n", nextCharacter);

        // TES: cek isi indeksj
        // printf("\nIndeksJ: ");
        // for (int i = 0; i < idxWordJ; i++)
        // {
        //     printf("%c", indeksJ.TabWord[i]);
        // }
        // printf("\n\n");
    }

    // Konversi word indeksI dan indeksJ ke string
    wordToStringWork(&indeksI, strI);
    wordToStringWork(&indeksJ, strJ);

    // TES: cek isi string setiap indeks
    // printf("strI: ");
    // for (int i = 0; i < stringLen(strI); i++)
    // {
    //     printf("%c", strI[i]);
    // }
    // printf("\n");
    // printf("strJ: ");
    // for (int i = 0; i < stringLen(strJ); i++)
    // {
    //     printf("%c", strJ[i]);
    // }
    // printf("\n");

    // Konversi string indeks menjadi integer
    for (int i = 0; strI[i] != '\0'; i++) {
        idxI = idxI * 10 + (strI[i] - '0');
    }
    idxI--;
    for (int i = 0; strJ[i] != '\0'; i++) {
        idxJ = idxJ * 10 + (strJ[i] - '0');
    }
    idxJ--;
    
    // TES: cek hasil konversi indeks menjadi integer
    // printf("idxI: %d | idxJ: %d\n\n", idxI, idxJ);

    // Tukar item di indeks i dan indeks j
    char *tempI = wishlist->items[idxI];
    char *tempJ = wishlist->items[idxJ];
    wishlist->items[idxI] = tempJ;
    wishlist->items[idxJ] = tempI;
}

void wlRemove(ListDin *wishlist, ListDin *daftarBarang){
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
    int indexBarang = IDX_UNDEF;
    boolean barangDiWishlist = false;
    for (int i = 0; i < wishlist->size; i++)
    {
        if (stringCompare(stringBarang, ELMTDin(*wishlist, i)) == 1)
        {
            barangDiWishlist = true;
            indexBarang = i;
            break;
        }
    }
    
    // Jika barang tak ada di wishlist
    // penghapusan tak akan dilakukan
    if (!barangDiWishlist)
    {
        for (int i = 0; i < stringLen(stringBarang); i++)
        {
            printf("%c", stringBarang[i]);
        }
        printf(" tak ada dalam wishlist!\n");
        return;
    }

    // Setelah input valid, penghapusan dilakukan
    // Ditampilkan urutan barang yang akan dihapus
    printf("Urutan barang yang dihapus: %d\n", indexBarang);
    deleteAtDin(wishlist, indexBarang);
}

void wlRemoveI(ListDin *wishlist, Word commandWL){
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
    if (angkaIndex-1 > wishlist->size)
    {
        printf("Indeks tak valid!\n");
        return;
    }
    
    deleteAtDin(wishlist, angkaIndex-1);
}


void wlShow(ListDin *wishlist){
    // setiap barang di wishlist diprint
    // jika kosong bilang aja wishlist kosong

    if (listLengthDin(*wishlist) == 0)
    {
        printf("Wishlist kosong!\n");
    } else {
        printf("Wishlist:\n");
        for (int i = 0; i < listLengthDin(*wishlist); i++){
            printf("%d. %s\n", i+1, ELMTDin(*wishlist, i));
        }
        printf("---------------\n\n");
    }
}