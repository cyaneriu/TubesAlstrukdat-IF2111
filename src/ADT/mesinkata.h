#ifndef MESIN_KATA_H
#define MESIN_KATA_H

#include "mesinkarakter.h"

#define MAX_LEN 50
#define BLANK ' '
#define NEWLINE '\n'
#define STRIP '-'
#define STOP '\0'

typedef struct
{
   char TabWord[MAX_LEN]; /* container penyimpan kata, indeks yang dipakai [0..NMax-1] */
   int Length;
} Word;

/* State Mesin Kata */
extern boolean EndWord;
extern Word currentWord;
extern Word currentCommand;
extern Word hasil;

void IgnoreBlank();

void IgnoreNewline();

void StartWordInput();

Word ConcatWord(Word word_1, Word word_2);

void StartWordFile(char *filename, int type);

void StartCommand();

void CopyCommand();

void ResetCommand();

void ADVWord();

void ADVInput();

boolean IsCommandEqual(Word Input, char * kata);

void copyString(char dest[], const char src[], int max_length);

int stringLen(char *string);

Word stringToWord(char* str);

void ADVLine();

void CopyWord();

Word CopyWordFile();

void CopyWordinput();

void ADVSemicolon();

void DisplayWord (Word Word);

boolean CekWord(Word hasil);

Word ConcatWord(Word word_1, Word word_2);

Word SplitWordBlank(Word word);

Word SplitWordMark(Word word);

Word SplitWordLeftBlank(Word word);

Word SplitWordLeftMark(Word word);

boolean isEqualWords(Word word1, char *str);

#endif