#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "../ADT/boolean.h"

#include "work.h"

// CATATAN : BELUM ADA VALIDASI
// 1. User tak boleh main jika biaya main > isiRekening
// 2. Validasi input agar sesuai dengan format yang diperbolehkan
// (misalnya tidak boleh langsung enter, tidak boleh mengisi kata > 5 huruf di wordl3, dll)

int driverWok()
{
    work(100);
    workChallenge(1000);
    tebakAngka(100);
    wordl3(1000);

    return 0;
}

void work(int isiRekening)
{

    // TODO: (kalau mau lebih dinamis)
    // 1 - bikin tipe data bentukan "pekerjaan"
    // 2 - simpan ke dalam array of "pekerjaan"
    // 3 - menampilkan daftar "pekerjaan" pake looping aja

    // 1. tampilkan daftar pekerjaan
    printf("Daftar pekerjaan:\n");
    printf("1. Evil Lab Assistant (pendapatan=100, durasi=14s)\n");
    printf("2. OWCA Hiring Manager (pendapatan=4200, durasi=21s)\n");
    printf("3. Cikapundunginator Caretaker (pendapatan=7000, durasi=30s)\n");
    printf("4. Mewing Specialist (pendapatan=10000, durasi=22s)\n");
    printf("5. Inator Connoisseur (pendapatan=997, durasi=15s)\n");

    // 2. Input pekerjaan yang dipilih
    char pilihanKerja[100];
    printf("Masukkan pekerjaan yang dipilih: ");
    scanf("%[^\n]%*c", pilihanKerja);

    int durasiKerja, pendapatan;

    // diperlukan fungsi strcmp alias string compare
    
    if (strcmp(pilihanKerja, "Evil Lab Assistant") == 0)
    {
        pendapatan = 100;
        durasiKerja = 14;
    } else if (strcmp(pilihanKerja, "OWCA Hiring Manager") == 0)
    {
        pendapatan = 4200;
        durasiKerja = 21;
    } else if (strcmp(pilihanKerja, "Cikapundunginator") == 0)
    {
        pendapatan = 7000;
        durasiKerja = 30;
    } else if (strcmp(pilihanKerja, "Mewing Specialist") == 0)
    {
        pendapatan = 10000;
        durasiKerja = 22;
    } else if (strcmp(pilihanKerja, "Inator Connoisseur") == 0)
    {
        pendapatan = 997;
        durasiKerja = 15;
    }

    // TES : Cek pendapatan dan durasiKerja
    printf("Pendapatan : %d\n", pendapatan);
    printf("Durasi Kerja : %d\n", durasiKerja);
    
    
    // 3. Tunggu sampai pekerjaan selesai
    printf("Anda sedang bekerja sebagai %s... harap tunggu.\n", pilihanKerja);
    printf("\n");
    
    sleep(durasiKerja);


    // 4. Tambahkan uang ke rekening dan beri notifikasi
    isiRekening += pendapatan;
    printf("Pekerjaan selesai, +%d rupiah telah ditambahkan ke akun Anda.\n", pendapatan);
    printf("Isi Rekening : %d\n", isiRekening);
}

void workChallenge(int isiRekening)
{
    int pilihanPermainan;

    printf("Daftar challenge yang tersedia:\n");
    printf("1. Tebak Angka (biaya main=200)\n");
    printf("2. W0RDL399 (biaya main=500)\n");
    printf("\n");
    
    printf("Masukan challenge yang hendak dimainkan: ");
    scanf("%d", &pilihanPermainan);
    printf("\n");
    
    // Kurangi uang sesuai pilihan permainan, berikan pesan permainan, dan jalankan permainan
    int biayaMain = 0;
    switch (pilihanPermainan)
    {
    case 1:
        tebakAngka(isiRekening);
        break;
    case 2:
        wordl3(isiRekening);
        break;
    default:
        break;
    }
}

void tebakAngka(int isiRekening)
{

    int biayaMain = 200;
    isiRekening -= biayaMain;

    // 1. Buat angka acak [0..99]
    srand(time(NULL));
    int kunciJawaban = rand() % 100;

    // TES : cetak kunci jawaban
    // printf("%d\n", kunciJawaban);

    // 2. Mulai permainan
    int percobaan = 0, jawaban, hadiah = 500;
    while (percobaan < 11)
    {
        printf("Tebak angka: ");
        scanf(" %d", &jawaban);
        printf("\n");
        if (jawaban == kunciJawaban)
        {
            hadiah -= 50 * percobaan;
            isiRekening += hadiah;
            printf("Tebakanmu benar! +%d rupiah telah ditambahkan ke akun anda.\n", hadiah);
            break;
        }
        else {
            // printf("Salah!\n");
            if (jawaban > kunciJawaban)
            {
                printf("Tebakanmu lebih besar!\n");
            }
            else
            {
                printf("Tebakanmu lebih kecil!\n");
            }
        }
        percobaan++;
    }
    // Pesan apabila pemain gagal setelah 10 percobaan
    if (percobaan > 10)
    {
        printf("Sayang sekali... Anda gagal, silahkan mencoba lain kali\n");
    }
    
    // TES : PRINT ISI REKENING
    // printf("%d\n", isiRekening);
}
/*
Challenge Tebak Angka merupakan permainan yang meminta pemain menebak sebuah angka yang ditentukan oleh program. Pemain memiliki 10 (sepuluh) kesempatan untuk menebak angka yang benar. Program akan memberikan feedback apakah angka tebakan lebih besar, lebih kecil, atau sama dengan angka target. Jumlah kesempatan yang dipakai oleh pengguna akan mempengaruhi uang yang didapatkan.

1 - TEBAK ANGKA
Tebakan & uang yang didapat
1x = 500
2x = 450
3x = 400
4x = 350
5x = 300
6x = 250
7x = 200
8x = 150
9x = 100
10x = 50
Lebih dari itu maka gagal
setiap salah sekali hadiah dikurangi 50
*/

void wordl3(int isiRekening)
{
    // Cetak pesan permainan
    printf("\n");
    printf("WELCOME TO W0RDL3, YOU HAVE 5 CHANCES TO ANSWER BEFORE YOU LOSE!\n");
    printf("\n");

    int biayaMain = 500;
    isiRekening -= biayaMain;

    // 1. Buat kunci jawaban berisi kata-kata yang bisa dipilih
    // Supaya mudah setiap huruf alfabet akan muncul sebagai inisial persis 2 kali
    char *kata[52] = {
    "APPLE", "BREAD", "CANDY", "DANCE", "EAGLE", 
    "FLAME", "GRAPE", "HORSE", "IGLOO", "JOLLY",
    "KEBAB", "LEMON", "MANGO", "NACHO", "OCEAN", 
    "PEARL", "QUILT", "RAVEN", "SHINE", "TIGER",
    "URBAN", "VIVID", "WHALE", "XENON", "YEARN", "ZEBRA",
    "ANGEL", "BISON", "COBRA", "DRAMA", "EMBER", 
    "FEAST", "GLOVE", "HIKER", "INFER", "JUMPS", 
    "KOALA", "LYRIC", "MAGIC", "NOISY", "OPERA", 
    "PIANO", "QUEEN", "ROBOT", "SUGAR", "TRACK", 
    "UNION", "VAPOR", "WITTY", "XENOS", "YACHT", "ZONES"
    };

    // Pilih suatu kata secara acak dari kumpulan kata yang ada
    srand(time(NULL));
    int index = rand() % 52;
    // TES : PRINT INDEX
    // printf("INDEX = %d\n", index);
    char *kunciJawaban = kata[index];

    // Kunci jawaban untuk debugging
    // kunciJawaban = "APPLE";

    // TES : PRINT KUNCI JAWABAN
    // printf("%s\n", kunciJawaban);

    // 2. Mulai permainan
    int hadiah = 1500;
    printf("_ _ _ _ _\n");
    printf("_ _ _ _ _\n");
    printf("_ _ _ _ _\n");
    printf("_ _ _ _ _\n");
    printf("_ _ _ _ _\n");
    printf("\n");

    char jawaban[5];
    boolean benar = false;

    char arrayKebenaran[5][5] =  {
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' '}
    };

    char arrayJawaban[5][5] = 
    {
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'},
        {'_', '_', '_', '_', '_'}
    };


    // Buat while loop & gunakan counter kesempatan
    int kesempatan = 0;
    while (kesempatan < 5)
    {
        printf("Masukan kata tebakan Anda: ");
        for (int i = 0; i < 5; i++)
        {
            scanf(" %c", &jawaban[i]);
            arrayJawaban[kesempatan][i] = jawaban[i];

            // TES : cetak arrayJawaban setelah diberi jawaban
            // printf("%c\n", arrayJawaban[kesempatan][i]);
        }
    
        // TES : mencetak jawaban dan kunci jawaban
        // for (int i = 0; i < 5; i++)
        // {
        //     printf("%c", jawaban[i]);
        // }
        // printf("\n");

        // for (int i = 0; i < 5; i++)
        // {
        //     printf("%c", kunciJawaban[i]);
        // }
        // printf("\n");

        // masukkan jawaban ke dalam arrayJawaban
        
        
        // if (strcmp(jawaban, kunciJawaban) == 0)
        for (int i = 0; i < 5; i++)
        {
            if (jawaban[i] == kunciJawaban[i])
            {
                benar = true;
            }
            else
            {
                benar = false;
            }
        }
        
        if (benar)
        {
            break; // langsung break, jawaban sudah benar dan akan ditampilkan
        }

        // TES : mencetak nilai benar
        // printf("%d\n", benar);
        
        for (int i = 0; i < 5; i++)
        {
            // masukkan nilai kebenaran ke dalam arrayKebenaran
            // % = salah, * = benar
            if (jawaban[i] == kunciJawaban[0] || jawaban[i] == kunciJawaban[1] || jawaban[i] == kunciJawaban[2] || jawaban[i] == kunciJawaban[3] || jawaban[i] == kunciJawaban[4])
            {
                arrayKebenaran[kesempatan][i] = '*';
            } 
            else
            {
                arrayKebenaran[kesempatan][i] = '%';
            }
        }
        // Di akhir setiap tebakan kita ingin menuliskan jawaban-kebenaran-spasi
        // A% D% I% E% U*

        // berarti dalam loop 5 kali kita tuliskan jawaban, kebenaran, lalu spasi
        // kebenaran hanya ditulis jika ada nilainya (tidak berupa spasi)
    
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%c", arrayJawaban[i][j]);
                if (arrayKebenaran[i][j] != ' ')
                {
                    printf("%c", arrayKebenaran[i][j]);
                }
                printf(" ");
            }
            printf("\n");
        }
        kesempatan++;
        printf("\n");
    }
    
    // Jika ternyata jawaban benar didapat sebelum percobaan habis, kita tetap ingin menulis
    // jawaban-kebenaran-spasi

    if (kesempatan < 5)
    {
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                printf("%c", arrayJawaban[i][j]);
                if (arrayKebenaran[i][j] != ' ')
                {
                    printf("%c", arrayKebenaran[i][j]);
                }
                printf(" ");
            }
            printf("\n");
        }
        printf("\n");
    }
    
    // Pesan hasil permainan
    if (benar)
    {
        printf("Selamat, Anda menang!\n\n");
        printf("+1500 rupiah telah ditambahkan ke akun Anda.\n");
        isiRekening += hadiah;
        printf("Isi Rekening : %d\n", isiRekening);
    }
    else
    {
        printf("Boo! Anda kalah.");
    }

}
/*
2 - WORDL3
Challenge W0RDL3 merupakan permainan tebak kata berjumlah lima karakter. Pemain memiliki 5 (lima) kesempatan untuk menebak kata yang benar.  Kata harus berupa kata valid, tidak boleh sekadar string acak, bahasa dibebaskan (disarankan bahasa Indonesia/Inggris). Pada setiap giliran, program akan mencetak ulang kata yang dimasukan, tetapi dengan penanda tertentu. Huruf yang benar dan berada pada tempat yang tepat dicetak biasa. Huruf yang benar, tetapi berada di tempat yang salah diberi tanda “*” setelah hurufnya. Huruf yang tidak ada sama sekali pada kata diberi tanda “%” setelah hurufnya.

>Kita pakai bahasa Inggris saja

*/
