#ifndef LOGIN_H
#define LOGIN_H

#include "../ADT/mesinkata.h"
#include "../ADT/boolean.h"
#include "load.h"
#include <stdio.h>

typedef struct {
    char username[MAX_LEN];
    char password[MAX_LEN];
    boolean logged;
} User;

void login(User *user, const char *filename);


#endif
