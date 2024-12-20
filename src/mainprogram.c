#include <stdio.h>
#include <stdlib.h>
#include "mainprogram.h"

int main() {
    printf("mulai plis stop segmentation fault");
    boolean program = true;
    boolean session = false;
    char * state;
    Store store;
    Barang barang[MAX_BARANG];
    User user[MAX_USER];
    int input;
    int jumlahBarang = 0; 
    int jumlahUser = 0;
    char * filename;
    char * item;
    int isiRekening = 0;
    char temporary[100];

    while (program) {
        welcome_perry();

        state = "Welcome Menu";
        help(state);

        printf(">> ");
        StartCommand();

        if (IsCommandEqual(currentCommand, "START\0")) {
            session = true;
            filename = "default.txt";
            startLoad(filename, barang, &jumlahBarang, user, &jumlahUser);
            printf("%d\n", jumlahBarang);
            printf("%d\n", jumlahUser);
        } else if (IsCommandEqual(currentCommand, "LOAD\0")) {
            ADVInput();
            wordToStringWork(&currentCommand, temporary);
            filename = temporary;
            //Load(&filename, barang, &jumlahBarang, user, &jumlahUser);
            startLoad(filename, barang, &jumlahBarang, user, &jumlahUser);
            session = true;
        } else if (IsCommandEqual(currentCommand, "HELP\0")) {
            help(state);
        } else if (IsCommandEqual(currentCommand, "QUIT\0")) {
            quit(filename, barang, &jumlahBarang, user, &jumlahUser);
            program = false;
            printf("Keluar dari PURRMART.\n");
        } else {
            printf("Perintah tidak dikenali, silahkan coba lagi.\n");
        }
        
        while (session){
            state = "Login Menu";
            help(state);
            
            printf(">> ");
            StartCommand();

            if (IsCommandEqual(currentCommand, "REGISTER\0")) {
                registeruser();
            } else if (IsCommandEqual(currentCommand, "LOGIN\0")) {
                login(&user[jumlahUser], user, jumlahUser);
                user->logged = true;
            } else if (IsCommandEqual(currentCommand, "QUIT\0")) {
                quit(filename, barang, &jumlahBarang, user, &jumlahUser);
                session = false;
                program = false;
                printf("Keluar dari PURRMART.\n");
            } else {
                printf("Perintah tidak dikenali, silahkan coba lagi.\n");
            }

            while (user->logged){
                state = "Main Menu";
                help(state);

                printf(">> ");
                StartWordInput();

                if (IsCommandEqual(currentWord, "STORE\0")) {
                    store_running();
                } else if (IsCommandEqual(currentWord, "WORK\0")) {
                    work(isiRekening);
                } else if (IsCommandEqual(currentWord, "WORK CHALLENGE\0")) {
                    workChallenge(isiRekening);
                } else if (IsCommandEqual(currentWord, "SAVE\0")) {
                    ADVInput();
                    wordToStringWork(&currentWord, temporary);
                    filename = temporary;
                    startSave(filename, barang, &jumlahBarang, user, &jumlahUser);
                } else if (IsCommandEqual(currentWord, "LOGOUT\0")) {
                    logout(user, filename);
                    user->logged = false;
                } else if (IsCommandEqual(currentWord, "QUIT\0")) {
                    quit(filename, barang, &jumlahBarang, user, &jumlahUser);
                    program = false;
                    printf("Keluar dari PURRMART.\n");
                
                } else if (IsCommandEqual(currentWord, "PROFILE\0")) {
                    welcome_user();
                    //user_profile(*currentUser);
                } else if (IsCommandEqual(currentWord, "HISTORY\0")) {
                   // history(Stack *S);
                } else if (IsCommandEqual(currentWord, "CART\0")) {
                    //
                } else if (IsCommandEqual(currentWord, "WISHLIST\0")) {
                    driverWL();
                } else {
                    printf("Perintah tidak dikenali, silahkan coba lagi.\n");
                }
            }
        
        }
    
    }
    return 0;
}
