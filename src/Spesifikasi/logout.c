#include <stdio.h>
#include "logout.h"

void logout(User *user, const char *filename) {
    if ((*user).logged) {
        printf(">>>> LOGOUT\n");
        printf("%s telah logout dari sistem PURRMART. Silakan REGISTER/LOGIN kembali untuk melanjutkan.\n", (*user).username);
        (*user).logged = false; 
    } else {
        printf("User belum melakukan login, silahkan login terlebih dahulu.\n");
    }
}
