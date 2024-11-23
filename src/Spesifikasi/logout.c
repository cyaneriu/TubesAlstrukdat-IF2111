#include <stdio.h>
#include "logout.h"

// Struktur User dari load 
// typedef struct {
//     char name[MAX_LEN];
//     char password[MAX_LEN];
//     int money;
//     boolean logged;
// } User;
void logout(User *user, char *filename) {
    if ((*user).logged) {
        printf(">>>> LOGOUT\n");
        printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", (*user).name);
        (*user).logged = false; 
    } else {
        printf("User belum melakukan login, silahkan login terlebih dahulu.\n");
    }
}
