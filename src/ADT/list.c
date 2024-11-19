#include "list.h"
#include <stdio.h>

// Functions Definition

void Create_String(STRING* X)
{
    Content(*X) = (char*) malloc(STRING_SIZE*sizeof(char));
    Size(*X)    = STRING_SIZE;
    Length(*X)  = 0;
}

void Create_List_String (LIST_STRING* X)
{
    Content(*X) = (STRING*) malloc(LIST_STRING_SIZE*sizeof(STRING));
    Size(*X)    = LIST_STRING_SIZE;
    Length(*X)  = 0;
}

void Dealloc_String(STRING* X)
{
    free(Content(*X));
    Size(*X)   = 0;
    Length(*X) = 0;
}

void String_Append(STRING* X, char C)
{
    if(Length(*X) == Size(*X)) 
    {
        Content(*X) = (char*) realloc(Content(*X), 2*Size(*X)*sizeof(char));
        Size(*X) *= 2;
    }
    Get(*X, Length(*X)++) = C;
}

void List_String_Append (LIST_STRING* X, STRING S)
{
    if(Length(*X) == Size(*X))
    {
        Content(*X) = (STRING*) realloc(Content(*X), 2*Size(*X)*sizeof(STRING));
        Size(*X) *= 2;
    }
    Get(*X, Length(*X)++) = S;
}