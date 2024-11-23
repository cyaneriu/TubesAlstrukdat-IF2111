#include <stdio.h>
#include <stdlib.h>
#include "mainprogram.h"

int main() {
    boolean program = true;
    boolean session = false;
    char * state[100];
    Store store;
    Barang barang[MAX_BARANG];
    User user[MAX_USER];
    int input;
    int *jumlahBarang; 
    int *jumlahUser;
    char * filename;
    char * item;

    while (program) {
        welcome_perry();

        state = "Welcome Menu";
        help(state);

        printf(">> ");
        StartWordInput();

        if (IsCommandEqual(currentWord, "START\0")) {
            start();
            session = true;
        } else if (IsCommandEqual(currentWord, "LOAD\0")) {
            Load(filename, barang, jumlahBarang, user, jumlahUser);
            session = true;
        } else if (IsCommandEqual(currentWord, "HELP\0")) {
            help(state);
        } else if (IsCommandEqual(currentWord, "QUIT\0")) {
            quit(filename, barang, jumlahBarang, user, jumlahUser);
            program = false;
            printf("Keluar dari PURRMART.\n");
        } else {
            printf("Perintah tidak dikenali, silahkan coba lagi.\n");
        }
        
        while (session){
            state = "Login Menu";
            help(state);
            
            printf(">> ");
            StartWordInput();

            if (IsCommandEqual(currentWord, "REGISTER\0")) {
                registeruser();
                help("Login Menu");
            } else if (IsCommandEqual(currentWord, "LOGIN\0")) {
                login();
            } else if (IsCommandEqual(currentWord, "QUIT\0")) {
                quit(filename, barang, jumlahBarang, user, jumlahUser);
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
                    store();
                } else if (IsCommandEqual(currentWord, "WORK\0")) {
                    work();
                } else if (IsCommandEqual(currentWord, "WORK CHALLENGE\0")) {
                    work_challenge();
                } else if (IsCommandEqual(currentWord, "SAVE\0")) {
                    save();
                } else if (IsCommandEqual(currentWord, "LOGOUT\0")) {
                    logout();
                    user->logged = false;
                    help("Welcome Menu")}
                else if (IsCommandEqual(currentWord, "QUIT\0")) {
                    quit(filename, barang, jumlahBarang, user, jumlahUser);
                    program = false;
                    printf("Keluar dari PURRMART.\n");
                } else {
                    printf("Perintah tidak dikenali, silahkan coba lagi.\n");
                }
            }
        
        }
    
    }
}
