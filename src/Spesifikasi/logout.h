#ifndef LOGOUT_H
#define LOGOUT_H
#include "../ADT/boolean.h" 

typedef struct {
    char username[100];
    boolean logged; 
} User;

void logout(User *user, const char *filename);

#endif