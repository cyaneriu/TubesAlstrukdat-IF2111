#ifndef LOGOUT_H
#define LOGOUT_H
#include "login.h"
#include "../ADT/boolean.h" 

typedef struct {
    char username[MAX_LEN];
    boolean logged; 
} User;

void logout(User *user, const char *filename);

#endif