#include <stdio.h>
#include "wishlist.h"
#include "../ADT/list_dinamis.h"
#include "work.h"

int main(){
    Word input;
    Word cekWishlist;
    StartWordInput;
    input = currentWord;

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
            // semua segmen berikutnya dijadikan nama barang
            // perlu dicek barangnya:
            // 1. Apakah memang ada di toko?
            // 2. Sudah ada di wishlist?
            // jika jawaban salah satunya "ya" berarti gak boleh ditambahin
            // kalau tidak tambahin saja
            wlAdd();
        } else if (commandWL.Length == 4 && commandWL.TabWord[0] == 'S' && commandWL.TabWord[1] == 'H' && commandWL.TabWord[2] == 'O' && commandWL.TabWord[3] == 'W')
        {
            // setiap barang di wishlist diprint
            // jika kosong bilang aja wishlist kosong
            wlShow();
        } else if (commandWL.Length == 5 && commandWL.TabWord[0] == 'C' && commandWL.TabWord[1] == 'L' && commandWL.TabWord[2] == 'E' && commandWL.TabWord[3] == 'A' && commandWL.TabWord[3] == 'R')
        {
            // semua barang di wishlist dihapus
            wlClear();
        } else if (commandWL.Length >= 4 && commandWL.TabWord[0] == 'S' && commandWL.TabWord[1] == 'W' && commandWL.TabWord[2] == 'A' && commandWL.TabWord[3] == 'P')
        {
            // siap2 swap
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
        }
        
        
        
        
        
    }
    
    
    return 0;
}

void driverWL(){

}

int wishlist(Word command){
    ListDin wishlist;
    CreateListDin(&wishlist, 100);

    char commandString;
    wordToStringWork(&command, &commandString);
    
    if (stringCompare(commandString, "WISHLIST ADD") == 1)
    {
        
    } else if (stringCompare(commandString, "WISHLIST SWAP I J") == 1)
    {
        /* code */
    } else if (stringCompare(commandString, "WISHLIST REMOVE I") == 1)
    {
        /* code */
    } else if (stringCompare(commandString, "WISHLIST REMOVE") == 1)
    {
        /* code */
    } else if (stringCompare(commandString, "WISHLIST CLEAR") == 1)
    {
        /* code */
    } else if (stringCompare(commandString, "WISHLIST SHOW") == 1)
    {
        /* code */
    } else {
        // input tidak valid
    }
    
}