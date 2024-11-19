#ifndef __LIST__
#define __LIST__

// Memory Allocation Library
#include <stdlib.h>

// Constants
#define STRING_SIZE      20
#define LIST_STRING_SIZE 5

// Type Definition
typedef struct
{
    char* DATA;
    int   CAPACITY;
    int   NEFF;
}STRING; //Array of Char

typedef struct 
{
    STRING* DATA;
    int     CAPACITY;
    int     NEFF;
}LIST_STRING; //Array of STRING

// SELECTOR
#define Content(X) (X).DATA
#define Size(X)    (X).CAPACITY
#define Length(X)  (X).NEFF
#define Get(X, i)  (X).DATA[i]

// Functions Declaration
void Create_String       (STRING* X);
void Create_List_String  (LIST_STRING* X);

void Dealloc_String      (STRING* X);
void Dealloc_List_String (LIST_STRING* X);

void String_Append       (STRING* X, char C);
void List_String_Append  (LIST_STRING* X, STRING S);

#endif