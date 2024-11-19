#ifndef REGISTER_H
#define REGISTER_H

#include <stdio.h>
#include <stdlib.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "boolean.h"
#include "load.h"
#include "save.h"


#define MAX_USER 100
#define FILENAME "user_data.txt"

boolean usernamevalid(char usernames[][NMax], int userCount, const char *username);
boolean satukata(const char *input) ;
void registeruser();

#endif
