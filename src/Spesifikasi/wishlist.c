#include <stdio.h>
#include "wishlist.h"


int main(){
    // Nanti untuk di driver perlu buat user dan store
    List L;
    CreateEmptyListLinier(&L);

    // Insert some values
    nama_barang value1 = "10";
    nama_barang value2 = "20";
    nama_barang value3 = "30";
    nama_barang value4 = "40";
    InsVLastListLinier(&L, value1);
    InsVLastListLinier(&L, value2);
    InsVLastListLinier(&L, value3);
    InsVLastListLinier(&L, value4);

    printf("Original list: ");
    PrintInfoListLinier(L);

    // return 0;
    // Find nodes to swap
    address P1 = SearchListLinier(L, value2);
    address P2 = SearchListLinier(L, value4);
    

    // Swap nodes
    SwapNodeListLinier(&L, P1, P2);

    printf("List after swapping 20 and 40: ");
    PrintInfoListLinier(L);
    // driverWL();
    return 0;
}

void driverWL(){
    // Inisialisasi
    printf("TES WISHLIST DIMULAI\n\n");
    printf("Inisialisasi\n");
    printf("-------------------------------------------------------\n");
    User userTestWL;
    Store storeTestWL;
    CreateEmptyListLinier(&userTestWL.wishlist);
    CreateListDin(&storeTestWL.barang, 100);

    printf("Wishlist kosong:\n");
    wlShow(&userTestWL.wishlist);
    printf("\n\n");

    printf("Barang Store kosong:\n");
    // displayStore(storeTestWL);
    if (listLengthDin(storeTestWL.barang) == 0)
    {
        printf("Store kosong!\n");
    } else {
        printf("Store:\n");
        for (int i = 0; i < listLengthDin(storeTestWL.barang); i++){
            printf("%d. %s\n", i+1, ELMTDin(storeTestWL.barang, i));
        }
        printf("---------------\n\n");
    }
    printf("\n\n");

    printf("Wishlist seharusnya berisi:\n");
    printf("1. Doom Inator\n");
    printf("2. Restoran Najwa Shihab\n");
    Barang barang1;
    Barang barang2;
    Barang barang3;
    Barang barang4;
    nama_barang namaBarang1 = "Doom Inator";
    nama_barang namaBarang2 = "Payung Platipus";
    nama_barang namaBarang3 = "Bendungan Cikapundung";
    nama_barang namaBarang4 = "Restoran Najwa Shihab";
    InsVFirstListLinier(&userTestWL.wishlist, namaBarang1);
    InsVFirstListLinier(&userTestWL.wishlist, namaBarang4);
    wlShow(&userTestWL.wishlist);

    printf("Store seharusnya berisi:\n");
    printf("1. Doom Inator\n");
    printf("2. Payung Platipus\n");
    printf("3. Bendungan Cikapundung\n");
    printf("4. Restoran Najwa Shihab\n");
    
    wordToString(stringToWord(namaBarang1), barang1.name);
    barang1.price = 1;
    addItemToStore(&storeTestWL, barang1);

    wordToString(stringToWord(namaBarang2), barang2.name);
    barang2.price = 2;
    addItemToStore(&storeTestWL, barang2);

    wordToString(stringToWord(namaBarang3), barang3.name);
    barang3.price = 3;
    addItemToStore(&storeTestWL, barang3);

    wordToString(stringToWord(namaBarang4), barang4.name);
    barang4.price = 4;
    addItemToStore(&storeTestWL, barang4);

    // displayStore(storeTestWL);
    if (listLengthDin(storeTestWL.barang) == 0)
    {
        printf("Store kosong!\n");
    } else {
        printf("Store:\n");
        for (int i = 0; i < listLengthDin(storeTestWL.barang); i++){
            printf("%d. %s\n", i+1, ELMTDin(storeTestWL.barang, i));
        }
        printf("-------------------------------------------------------\n\n");
    }

    printf("-------------------------------------------------------\n\n");
    Word command;
    StartWordInput();
    command = currentWord;
    wishlist(&userTestWL, &storeTestWL, command);
    return;

    // TES SHOW
    /*
    // Menampilkan isi wishlist
    printf("TES SHOW\n");
    printf("-------------------------------------------------------\n");
    wlShow(&userTestWL.wishlist);
    printf("-------------------------------------------------------\n\n");
    */

    // TES ADD
    /*
    // Menambahkan barang ke wishlist
    printf("TES ADD\n");
    printf("-------------------------------------------------------\n");
    // 1. Input valid
    printf("Uji ADD dengan input valid:\n");
    wlAdd(&userTestWL.wishlist, &storeTestWL.barang);
    wlShow(&userTestWL.wishlist);

    // 2. Input invalid (barang tak ada di store)
    printf("Uji ADD dengan input invalid (barang tak ada di store):\n");
    wlAdd(&userTestWL.wishlist, &storeTestWL.barang);
    wlShow(&userTestWL.wishlist);

    // 3. Input invalid (barang sudah ada di wishlist)
    printf("Uji ADD dengan input invalid (barang sudah ada di wishlist):\n");
    wlAdd(&userTestWL.wishlist, &storeTestWL.barang);
    wlShow(&userTestWL.wishlist);
    printf("-------------------------------------------------------\n\n");
    */

    // TES SWAP
    
    // Menukar 2 barang di wishlist menggunakan indeks keduanya
    printf("TES SWAP\n");
    printf("-------------------------------------------------------\n");
    Word swap1 = stringToWord("SWAP 1 2");
    Word swap2 = stringToWord("SWAP 1");
    Word swap3 = stringToWord("SWAP 1 2 3");
    Word swap4 = stringToWord("SWAP 1 200");
    Word swap5 = stringToWord("SWAP 1 1");
    
    printf("TES SWAP 1: Input valid -> |WISHLIST SWAP 1 2|\n");
    wlSwap(&userTestWL.wishlist, swap1);
    wlShow(&userTestWL.wishlist);

    printf("TES SWAP 2: Input invalid -> |WISHLIST SWAP 1|\n");
    wlSwap(&userTestWL.wishlist, swap2);
    wlShow(&userTestWL.wishlist);

    printf("TES SWAP 3: Input invalid -> |WISHLIST SWAP 1 2 3|\n");
    wlSwap(&userTestWL.wishlist, swap3);
    wlShow(&userTestWL.wishlist);

    printf("TES SWAP 4: Input invalid -> |WISHLIST SWAP 1 200|\n");
    wlSwap(&userTestWL.wishlist, swap4);
    wlShow(&userTestWL.wishlist);

    printf("TES SWAP 5: Input invalid -> |WISHLIST SWAP 1 1|\n");
    wlSwap(&userTestWL.wishlist, swap5);
    wlShow(&userTestWL.wishlist);
    printf("-------------------------------------------------------\n\n");
    

    // TES REMOVE
    /*
    // Menghapus barang dari wishlist menggunakan namanya
    printf("TES REMOVE\n");
    printf("-------------------------------------------------------\n");
    // 1. Input valid
    printf("Uji REMOVE dengan input valid:\n");
    wlRemove(&userTestWL.wishlist, &storeTestWL.barang);
    wlShow(&userTestWL.wishlist);
    return;

    // 2.Input invalid (barang tak ada di store)
    printf("Uji REMOVE dengan input invalid (barang tak ada di store):\n");
    wlRemove(&userTestWL.wishlist, &storeTestWL.barang);
    wlShow(&userTestWL.wishlist);

    // 3.Input invalid (barang tak ada di wishlist)
    printf("Uji REMOVE dengan input invalid (barang tak ada di wishlist):\n");
    wlRemove(&userTestWL.wishlist, &storeTestWL.barang);
    wlShow(&userTestWL.wishlist);
    printf("-------------------------------------------------------\n\n");
    */

    // TES REMOVE I
    /*
    // Menghapus barang dari wishlist menggunakan indeksnya
    printf("TES REMOVE I\n");
    printf("-------------------------------------------------------\n");
    Word remove1 = stringToWord("REMOVE 1");
    Word remove2 = stringToWord("REMOVE");
    Word remove3 = stringToWord("REMOVE 1 2");
    Word remove4 = stringToWord("REMOVE 200");
    Word remove5 = stringToWord("REMOVE xy");


    printf("TES REMOVE I 1: Input valid -> |REMOVE 1|\n");
    wlRemoveI(&userTestWL.wishlist, remove1);
    wlShow(&userTestWL.wishlist);

    printf("TES REMOVE I 2: Input invalid -> |REMOVE|\n");
    wlRemoveI(&userTestWL.wishlist, remove2);
    wlShow(&userTestWL.wishlist);

    printf("TES REMOVE I 3: Input invalid -> |REMOVE 1 2|\n");
    wlRemoveI(&userTestWL.wishlist, remove3);
    wlShow(&userTestWL.wishlist);

    printf("TES REMOVE I 4: Input invalid -> |REMOVE 200|\n");
    wlRemoveI(&userTestWL.wishlist, remove4);
    wlShow(&userTestWL.wishlist);

    printf("TES REMOVE I 5: Input invalid -> |REMOVE xy|\n");
    wlRemoveI(&userTestWL.wishlist, remove5);
    wlShow(&userTestWL.wishlist);
    printf("-------------------------------------------------------\n\n");
    */

    // TES CLEAR
    /**/
    // Menghapus semua barang di wishlist
    printf("TES CLEAR\n");
    printf("-------------------------------------------------------\n");
    wlClear(&userTestWL.wishlist);
    wlShow(&userTestWL.wishlist);
    printf("-------------------------------------------------------\n\n");

    printf("TES WISHLIST SELESAI\n\n");
}

void wishlist(User *currentUser, Store *store, Word currentCommand){
    List wishlist = currentUser->wishlist;
    ListDin daftarBarang = store->barang;
    Word commandWL;
    commandWL.Length = currentCommand.Length - 9;
    for (int i = 0; i < commandWL.Length; i++)
    {
        commandWL.TabWord[i] = currentCommand.TabWord[i+9];
    }
    // Kosongkan sisa buffer commandWL
    for (int i = commandWL.Length; i < 50; i++)
    {
        commandWL.TabWord[i] = '\0';
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
        // pastikan dulu hanya ada 2 segmen indeks
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

void wlAdd(List *wishlist, ListDin *daftarBarang){
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
    // char stringBarang[50];
    nama_barang stringBarang;
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
        for (int i = 0; i < stringLen(stringBarang); i++)
        {
            printf("%c", stringBarang[i]);
        }
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
        DelFirstListLinier(wishlist, &P);
    }
}

void wlSwap(List *wishlist, Word commandWL){
    // Ambil input perintah
    // Cek apakah hanya terdiri atas 3 segmen
    // segmen "SWAP", "<i>", "<j>"
    int segmentCount = segmentCounter(commandWL);

    printf("commandWL |");
    for (int i = 0; i < stringLen(commandWL.TabWord); i++)
    {
        printf("%c", commandWL.TabWord[i]);
    }
    printf("|\n");
    printf("segmentCount for commandWl:%d\n", segmentCount);

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
        // printf("idxWordI: %d\n", idxWordI);
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
        // printf("idxWordJ: %d\n", idxWordJ);
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
    printf("idxI: %d | idxJ: %d\n\n", idxI, idxJ);

    // Pastikan idx i dan j:
    // 1. Valid (dalam rentang ukuran wishlist)
    // 2. Merupakan angka yang berbeda
    if (idxI > NbElmtListLinier(*wishlist) || idxJ > NbElmtListLinier(*wishlist) || idxI == idxJ){
        printf("Indeks tak valid!\n");
        return;
    }

    // Setelah indeks valid, cari pointer ke masing-masing barang
    address alamatBarang;
    int idxWL;

    idxWL = 0;
    address PI = wishlist->First;
    while (idxWL != idxI)
    {
        PI = PI->next;
        idxWL++;
    }
    printf("Info(PI): |");
    for (int i = 0; i < stringLen(PI->info); i++)
    {
        printf("%c", PI->info[i]);
    }
    printf("|\n");

    idxWL = 0;
    address PJ = wishlist->First;
    while (idxWL != idxJ)
    {   
        PJ = PJ->next;
        idxWL++;
    }
    printf("Info(PJ): |");
    for (int i = 0; i < stringLen(PJ->info); i++)
    {
        printf("%c", PJ->info[i]);
    }
    printf("|\n");

    SwapNodeListLinier(wishlist, PI, PJ);
    wlShow(wishlist);
    printf("Berhasil?\n");

    // nama_barang barangI;
    // nama_barang barangJ;
    // for (int i = 0; i < 50; i++)
    // {
    //     barangI[i] = PI->info[i];
    //     barangJ[i] = PJ->info[i];
    // }
    
    // address Ibaru = AlokasiListLinier(barangI);
    // address Jbaru = AlokasiListLinier(barangJ);
    // DelPListLinier(wishlist, barangI);
    // InsertAfterListLinier(wishlist, Ibaru, PrecJ);
    // wlShow(wishlist);
    // DelPListLinier(wishlist, barangJ);
    // InsertAfterListLinier(wishlist, Jbaru, PrecI);
    // wlShow(wishlist);
}

void wlRemove(List *wishlist, ListDin *daftarBarang){
    // Ambil input nama barang
    Word namaBarang;
    printf("Masukkan nama barang yang akan dihapus: ");
    StartWordInput();
    namaBarang = currentWord;

    nama_barang stringBarang;
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
    
    // Jika barang tak ada di wishlist
    // penambahan tak akan dilakukan
    if (alamatbarang == Nil)
    {
        for (int i = 0; i < stringLen(stringBarang); i++)
        {
            printf("%c", stringBarang[i]);
        }
        printf(" tak ada dalam wishlist!\n");
        return;
    }

    // Setelah input valid, penghapusan dilakukan
    DelPListLinier(wishlist, stringBarang);
    printf("Barang telah dihapus\n");
}

void wlRemoveI(List *wishlist, Word commandWL){
    // Cek input perintah (commandWL)
    if (commandWL.Length < 8 || commandWL.TabWord[7] == '0' || segmentCounter(commandWL) != 2)
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

    if (angkaIndex > NbElmtListLinier(*wishlist))
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
    if (IsEmptyListLinier(*wishlist))
    {
        printf("Wishlist kosong!\n");
    } else {
        printf("Wishlist:\n");
        address Q = First(*wishlist);
        int idx = 0;
        while(Q!=Nil){
            printf("%d. %s\n", idx+1, Q->info);
            Q = Q->next;
            idx++;
        }
        printf("\n");
    }
}