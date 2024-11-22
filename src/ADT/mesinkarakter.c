#include <stdio.h>
#include "mesinkarakter.h"

char currentChar;
boolean EOP;

FILE *pita;
static int retval;

void START()
{
    pita = stdin;
    ADV();
}

void StartFile(char *filename)
{
    if (filename == NULL){
        pita = stdin;
    } else {
        pita = fopen(filename, "r");
    }
    ADV();
}
 
void ADV()
{
    if (pita == NULL)
    {
        EOP = true;
    }
    else
    {
        retval = fscanf(pita, "%c", &currentChar);
        EOP = (currentChar == MARK) || feof(pita); // MARK di sini adalah '\n'
        if (feof(pita))
        {
            fclose(pita);
        }
    }
}


void AdvFile()
{
    if (pita == NULL)
    {
        EOP = true;
    }
    else
    {
        retval = fscanf(pita, "%c", &currentChar);
        EOP = (currentChar == MARK) || feof(pita);
        if (feof(pita))
        {
            fclose(pita);
        }
    }
}


char GetCC()
{
    return (currentChar);
}

boolean IsEOP()
{
    return (currentChar == MARK);
}