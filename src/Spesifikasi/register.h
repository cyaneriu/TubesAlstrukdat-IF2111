#ifndef REGISTER_H
#define REGISTER_H

#include <stdio.h>
#include "mesinkarakter.h"
#include "mesinkata.h"
#include "boolean.h"
#include "load.h"


#define MAX_USER 100
#define FILENAME "user_data.txt"

boolean usernamevalid(char usernames[][MAX_LEN], int userCount, Word usernameword);
boolean satukata(Word masukan) ;
void registeruser();

#endif
