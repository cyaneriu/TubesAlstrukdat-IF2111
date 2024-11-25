#include <stdio.h>
#include <stdlib.h>
#include "mainprogram.h"

int main() {
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
            printf("%d\n", jumlahBarang);
            printf("%d\n", jumlahUser);
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
                help("Login Menu");
            } else if (IsCommandEqual(currentCommand, "LOGIN\0")) {
                login(user, filename);
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
                StartCommand();

                if (IsCommandEqual(currentCommand, "STORE\0")) {
                    store_running();
                } else if (IsCommandEqual(currentCommand, "WORK\0")) {
                    work(isiRekening);
                } else if (IsCommandEqual(currentCommand, "WORK CHALLENGE\0")) {
                    workChallenge(isiRekening);
                } else if (IsCommandEqual(currentCommand, "SAVE\0")) {
                    ADVInput();
                    wordToStringWork(&currentCommand, temporary);
                    filename = temporary;
                    startSave(filename, barang, &jumlahBarang, user, &jumlahUser);
                } else if (IsCommandEqual(currentCommand, "LOGOUT\0")) {
                    logout(user, filename);
                    user->logged = false;
                    help("Welcome Menu");}
                else if (IsCommandEqual(currentCommand, "QUIT\0")) {
                    quit(filename, barang, &jumlahBarang, user, &jumlahUser);
                    program = false;
                    printf("Keluar dari PURRMART.\n");
                } else {
                    printf("Perintah tidak dikenali, silahkan coba lagi.\n");
                }
            }
        
        }
    
    }
    return 0;
}
