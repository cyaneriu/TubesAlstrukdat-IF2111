#include <stdio.h>
#include "wishlist.h"
#include "../ADT/list_dinamis.h"
#include "work.h"

int main(){
    driverWL();
    
    return 0;
}

void driverWL(){
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

    char nama[] = "Doom Inator";
    
    insertLastDin(&wishlist, nama);

    for (int i = 0; i < listLengthDin(wishlist); i++)
    {
        printf("%d. %s\n", i+1, ELMTDin(wishlist, i));
    }
    

    // return;

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
        // quitTest(&test);

        printf("lanjutkan? [Y/N]\n");
        Word lanjut;
        lanjut.Length = 1;
        StartWordInput();
        lanjut.TabWord[0] = currentChar;
        printf("%c\n", lanjut.TabWord[0]);

        if (lanjut.TabWord[0] == 'X' || lanjut.TabWord[0] == 'x')
        {
            break;
        } else {
            printf("Silahkan menginput perintah Wishlist\n\n");
        }
    }
}

// void quitTest(int *test){
//     // int test = 0;
//     char jawab;
//     printf("Lanjutkan tes? [y/n]\n");
//     // scanf("%d", &test);
//     scanf("%c", jawab);
//     while (getchar() != '\n');
//     printf("%c\n", jawab);

//     if (jawab == 'y' || jawab == 'Y')
//     {
//         *test = 1;
//     }
//     // printf("%d\n", *test);
//     printf("Silahkan menginput perintah WISHLIST\n");
// }

void wishlistTest(ListDin *wishlist, ListDin *daftarBarang){
    Word input;
    Word cekWishlist;
    StartWordInput();
    input = currentWord;
    // int cnt = segmentCounter(input);
    // printf("%d\n", cnt);
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
        nextCharacter = kata.TabWord[idx+1];
        // printf("Current Character: %c || Next Character: %c\n", currentCharacter, nextCharacter);
        if (currentCharacter == ' ' && segmenCount == 0){
            idx++;
            continue;
        }

        if (currentCharacter != ' ')
        {
            isInSegment = true;
        }
        if (isInSegment == true && (nextCharacter == ' ' || nextCharacter == '\0'))
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

    // printf("wlAdd\n");
    Word namaBarang;
    printf("Masukkan nama barang: ");
    StartWordInput();
    namaBarang = currentWord;

    char stringBarang[150];
    wordToStringWork(&namaBarang, stringBarang);
    boolean barangAda = false;
    for (int i = 0; i < daftarBarang->size; i++)
    {
        if (stringCompare(stringBarang, ELMTDin(*daftarBarang, i)) == 1)
        {
            barangAda = true;
            break;
        }
    }

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

    boolean barangDiWishlist = false;
    for (int i = 0; i < wishlist->size; i++)
    {
        if (stringCompare(stringBarang, ELMTDin(*wishlist, i)) == 1)
        {
            barangDiWishlist = true;
            break;
        }
    }
    
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

    // printf("wlClear\n");
    for (int i = 0; i < listLengthDin(*wishlist); i++)
    {
        deleteFirstDin(wishlist);
    }
}

void wlSwap(ListDin *wishlist, Word commandWL){
    // int segmentCount = segmentCounter(commandWL);
    // printf("%d\n", segmentCount);
}

void wlRemove(ListDin *wishlist, ListDin *daftarBarang){
    Word namaBarang;
    printf("Masukkan nama barang yang akan dihapus: ");
    StartWordInput();
    namaBarang = currentWord;

    char stringBarang[150];
    wordToStringWork(&namaBarang, stringBarang);

    for (int i = 0; i < stringLen(stringBarang); i++)
    {
        printf("%c", stringBarang[i]);
    }
    printf("|\n");
    // return;

    boolean barangAda = false;
    for (int i = 0; i < daftarBarang->size; i++)
    {
        if (stringCompare(stringBarang, ELMTDin(*daftarBarang, i)) == 1)
        {
            barangAda = true;
            break;
        }
    }

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
    
    if (!barangDiWishlist)
    {
        for (int i = 0; i < stringLen(stringBarang); i++)
        {
            printf("%c", stringBarang[i]);
        }
        printf(" tak ada dalam wishlist!\n");
        return;
    }
    printf("Urutan barang: %d\n", indexBarang);
    deleteAtDin(wishlist, indexBarang);
}

void wlRemoveI(ListDin *wishlist, Word commandWL){
    if (commandWL.Length < 8)
    {
        printf("Indeks tak valid!\n");
        return;
    } else if (commandWL.TabWord[7] == '0')
    {
        printf("Indeks tak valid\n");
        return;
    } else if (segmentCounter(commandWL) > 1)
    {
        printf("Indeks tak valid\n");
        return;
    }
    
    
    Word index;
    index.Length = commandWL.Length - 7;
    for (int i = 0; i < commandWL.Length ; i++)
    {
        index.TabWord[i] = commandWL.TabWord[i+7];
    }

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
    
    char stringIndex[100];
    wordToStringWork(&index, stringIndex);
    int angkaIndex = 0;
    for (int i = 0; stringIndex[i] != '\0'; i++) {
    angkaIndex = angkaIndex * 10 + (stringIndex[i] - '0');
    }

    if (angkaIndex > wishlist->size)
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