#include <stdio.h>
#include <stdlib.h>
#include "mainprogram.h"

int main() {
    boolean program = true;
    boolean session = false;
    char * state;
    Barang barang[MAX_BARANG];
    ArrayDin item;
    User user[MAX_USER];
    User * currentUser;
    int jumlahBarang = 0; 
    int jumlahUser = 0;
    char * filename;
    int isiRekening = 0;

    while (program) {
        while (!state && !session) {
            welcome_perry();

            state = "Welcome Menu";
            help(state);

            printf(">> ");
            StartCommand2();
            printf("\n");

            char Command[NMax]; 
            wordToString(currentCommand, Command);
            char text[NMax];
            int i = 0;

            while(currentWord.TabWord[i] != ' ' && currentWord.TabWord[i] != '\0'){
                Command[i] = currentWord.TabWord[i];
                (&currentWord)->TabWord[i] = '\0';
                i++;
            }
            Command[i] = '\0';
            (&currentWord)->TabWord[i] = '\0';

            if (isEqual(Command, "START")) {
                session = true;
                filename = "default.txt";
                startLoad(filename, barang, &jumlahBarang, user, &jumlahUser);
            } else if (isEqual(Command, "LOAD")) {
                i++;
                int j = i;
                while(currentWord.TabWord[i] != '\0'){
                    text[i - j] = currentWord.TabWord[i];
                    (&currentWord)->TabWord[i] = '\0';
                    i++;
                }
                text[i-j] = '\0';
                startLoad(text, barang, &jumlahBarang, user, &jumlahUser);
                session = true;
            } else if (isEqual(Command, "HELP\0")) {
                help(state);
            } else if (isEqual(Command, "QUIT\0")) {
                quit(filename, barang, &jumlahBarang, user, &jumlahUser);
                program = false;
                printf("Keluar dari PURRMART.\n");
            } else {
                printf("Perintah tidak dikenali, silahkan coba lagi.\n");
            }
        }
        
        while (!user->logged && session){
            state = "Login Menu";
            help(state);
            
            printf(">> ");
            StartCommand2();
            printf("\n");

            char Command[NMax]; 
            wordToString(currentCommand, Command);

            if (isEqual(Command, "REGISTER\0")) {
                registeruser();
            } else if (isEqual(Command, "LOGIN\0")) {
                login(&user[jumlahUser], user, jumlahUser);
                user->logged = true;
            } else if (isEqual(Command, "QUIT\0")) {
                quit(filename, barang, &jumlahBarang, user, &jumlahUser);
                session = false;
                program = false;
                printf("Keluar dari PURRMART.\n");
            } else {
                printf("Perintah tidak dikenali, silahkan coba lagi.\n");
            }
        }

        while (user->logged && session) {
            state = "Main Menu";
            help(state);

            printf(">> ");
            StartCommand2();
            printf("\n");

            char C1[100], C2[100];
            int i = 0;
            int j = 0;
            int k = 0;
            while (currentWord.TabWord[k] != '\0') {
                C2[k] = currentWord.TabWord[k];
                k++;
            }
            C2[k] = '\0';

            while (1) {
                if (i == j) {
                    C1[i] = currentWord.TabWord[i];
                    C2[j] = currentWord.TabWord[i];
                    i++; 
                    j++;
                }

                if (currentWord.TabWord[i] == '\0') {
                    break;
                }

                if (currentWord.TabWord[i] == ' '){ 
                    i--;
                } else if (j > i) {
                    C2[j]=currentWord.TabWord[j];
                    j++;
                    if (currentWord.TabWord[j] == ' ') break;
                    if (currentWord.TabWord[j] == '\0') break;
                }
            }

            if (i < j) {
                i++;
            }
            C1[i] = '\0'; 
            C2[j] = '\0';
            i++; 
            j++;

            if (isEqual(C1, "STORE\0")) {
                store_running();
            } else if (isEqual(C1, "WORK\0")) {
                work(&isiRekening);
            } else if (isEqual(C2, "WORK CHALLENGE")) {
                workChallenge(&isiRekening);
            } else if (isEqual(C2, "SAVE")) {
                char text[50];
                int idx = 0;
                while(currentWord.TabWord[j] != '\0' && idx < 50) {
                    text[idx] = currentWord.TabWord[j];
                    idx++;
                    j++;
                }
                text[i] = '\0';
                
                int valid = 0;
                if (i >= 4) { 
                    if (text[idx - 4] == '.' && 
                        text[idx - 3] == 't' && 
                        text[idx - 2] == 'x' && 
                        text[idx - 1] == 't') {
                        valid = 1;
                    }
                }
                
                if (valid) {
                    printf("%s\n", text);
                    startSave(text, barang, &jumlahBarang, user, &jumlahUser);
                } else {
                    printf("File tidak valid! sertakan akhiran .txt\n");
                } 
            } else if (isEqual(C1, "LOGOUT")) {
                logout(user, filename);
                user->logged = false;
            } else if (isEqual(C1, "QUIT")) {
                quit(filename, barang, &jumlahBarang, user, &jumlahUser);
                program = false;
                printf("Keluar dari PURRMART.");
            
            } else if (isEqual(C2, "PROFILE")) {
                welcome_user();
            } else if (isEqual(C1, "HISTORY")) {
                printf("\n");
                int n, k = 0; char temp[100];
                while (currentWord.TabWord[j]!='\0')
                {
                    temp[k++]=currentWord.TabWord[j++];
                }
                temp[k]= '\0';
                stringtoint(temp, &n);
                history(currentUser, n);
            } else if (isEqual(C2, "CART ADD")) {
                printf("\n");
                char name[100], temp[100]; 
                int jumlah, k=j, space=0;

                while (currentWord.TabWord[j]!= '\0') {
                    if (currentWord.TabWord[j] ==' ') {
                        space++;
                        j++;
                    }
                }
                j = k; 
                k = 0;

                while (space!=0) {
                    name[k++] = currentWord.TabWord[j++];
                    if (currentWord.TabWord[j] == ' ') {
                        space--;
                    } if (currentWord.TabWord[j] == '\0') {
                        break;
                    }
                }
                
                name[k]='\0'; 
                j++; 
                k=0;

                while (currentWord.TabWord[j]!= '\0') {
                    temp[k++] = currentWord.TabWord[j++];
                }
                temp[k]='\0'; 

                stringtoint(temp, &jumlah);
                cartAdd(currentUser, item, name, jumlah);
            } else if (isEqual(C2, "CART REMOVE\0")) {
                printf("\n");
                char name[100], temp[100]; 
                int jumlah, k = j, space = 0;
                printf("%s", C2);

                while (currentWord.TabWord[j]!= '\0') {
                    if (currentWord.TabWord[j] ==' ') space++;
                    j++;
                }
                j= k; 
                k= 0;

                while (space!=0) {
                    name[k++] = currentWord.TabWord[j++];
                    if (currentWord.TabWord[j]==' ') space--;
                    if (currentWord.TabWord[j]=='\0') break;
                }
                
                name[k]='\0'; 
                j++; 
                k=0;

                while (currentWord.TabWord[j]!= '\0') {
                    temp[k++] = currentWord.TabWord[j++];
                }
                temp[k]='\0'; 
                stringtoint(temp, &jumlah);
                cartRemove(currentUser, name, jumlah);
            } else if (isEqual(C2, "CART PAY\0")) {
                printf("\n");
                cartPay(currentUser);
            } else if (isEqual(C2, "CART SHOW\0")) {
                printf("\n");
                cartShow(currentUser);
            } else if (isEqual(C1, "WISHLIST\0")) {
                driverWL();
            } else {
                printf("Perintah tidak dikenali, silahkan coba lagi.\n");
            }
        }
    } 
    return 0;
}