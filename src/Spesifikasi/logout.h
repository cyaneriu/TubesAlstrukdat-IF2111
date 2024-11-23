#ifndef LOGOUT_H
#define LOGOUT_H
#include "login.h"
#include "../ADT/boolean.h" 

// Struktur User dari load
// typedef struct {
//     char name[MAX_LEN];
//     char password[MAX_LEN];
//     int money;
//     boolean logged;
// } User;
void logout(User *user, char *filename);

#endif