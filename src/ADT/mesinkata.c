#include <stdio.h>

#include "mesinkata.h"

boolean EndWord;
Word currentWord;
Word currentCommand;
Word hasil;

void IgnoreBlank()
{
    while (currentChar == BLANK || currentChar == MARK)
    {
        ADV();
    }
}

void IgnoreNewline()
{
    while (currentChar == NEWLINE)
    {
        ADV();
    }
}


void StartWordInput()
{
    START(); // Mulai membaca input
    currentWord.Length = 0; // Reset panjang kata
    
    IgnoreBlank(); // Abaikan spasi di awal

    // Jika input diawali dengan newline
    if (currentChar == NEWLINE)
    {
        EndWord = true; // Tandai akhir kata
        printf("Input tidak boleh diawali newline.\n");
        return;
    }
    
    // Jika input kosong setelah newline
    if (IsEOP())
    {
        EndWord = true; // Tandai akhir kata
    }
    else
    {
        EndWord = false;
        CopyWordinput(); // Salin kata dari input
    }
}

void StartWordFile(char *filename, int type)
{
    StartFile(filename);
    IgnoreBlank(); // Abaikan spasi awal

    // Tambahkan logika untuk mengabaikan newline
    if (currentChar == NEWLINE)
    {
        AdvFile(); // Lewati karakter newline
    }

    if (currentChar == '\0' || EOP) // Jika file kosong atau selesai
    {
        EndWord = true;
    }
    else
    {
        EndWord = false;
        CopyWord(type); // Salin kata pertama
    }
}

void ADVWord()
{
    IgnoreBlank();
    if (currentChar == BLANK)
    {
        EndWord = true;
    }
    else
    {
        CopyWord();
        //IgnoreBlank();
    }
}

void StartCommand() {
    START();
    IgnoreNewline();
    if (currentChar == MARK){
        EndWord = true;
    } else {
        EndWord = false;
        CopyCommand();
    }
}

void StartCommand2(){
    START(); 
    IgnoreBlank();  
    
    currentWord.Length = 0;
    
    while (currentChar != MARK && currentChar != '\n') {
        if (currentWord.Length < NMax) {
            currentWord.TabWord[currentWord.Length] = currentChar;
            currentWord.Length++;
        }
        ADV();  
    }
    
    EndWord = (currentChar == MARK);
}

void CopyCommand() {
    ResetCommand(); 
    int i = 0;
    while ((currentChar != BLANK) && (currentChar != MARK) && (currentChar != EOF))
    {
        currentCommand.TabWord[i] = currentChar;
        i+= 1;
        ADV();
    }
    currentCommand.Length = i;
}

void ResetCommand() {
    for (int i = 0; i < sizeof(currentCommand.TabWord); i++) {
        currentCommand.TabWord[i] = '\0';
        currentCommand.Length = 0;
    }
}

void ADVInput(){
    IgnoreBlank();
    if (currentChar == MARK){
        EndWord = true;
    } else {
        EndWord = false;
        CopyCommand();
    }
}

boolean IsCommandEqual(Word Input, char * kata)
{   
    boolean equal = true;
    if (Input.Length == stringLen(kata))
    {
        int i = 0;
        while (i < Input.Length && equal)
        {
            if (Input.TabWord[i] != kata[i])
            {
                equal = false;
            } else {
                i++;
            }
        }
        return equal;
    }
    else
    {
        return false;
    }
}

boolean isEqual(char x[100], char y[100]){
    boolean cek = true;
    if(stringLen(x) != stringLen(y)){
        cek = false;
        return cek;
    } else {
        for(int i = 0; x[i] != '\0'; i++){
            if(x[i] != y[i]){
                cek = false;
            }
        }
        return cek;
    }
}

void copyString(char dest[], const char src[], int max_length) {
    int i = 0;
    while (*src != '\0' && i < max_length - 1) {
        dest[i] = *src;
        i++;
        src++;
    }
    dest[i] = '\0';
}

int stringLen(char *string)
{
    int i = 0;
    int count = 0;
    while (string[i]!='\0') {
        count++;
        i++;
    }
    return count;
}

void stringtoint(char *str, int *result) {
    *result = 0;
    int i = 0;
    while (str[i] != '\0') {
        *result = (*result * 10) + (str[i] - '0');
        i++;
    }
}

Word stringToWord(char* str) {
    Word word;
    copyString(word.TabWord, str, MAX_LEN);
    word.Length = stringLen(str);
    return word;
}

void ADVLine()
{
    if (currentChar == NEWLINE)
    {
        EndWord = true;
    }
    else
    {
        CopyWordFile();
        IgnoreNewline();
    }
}

void CopyWord()
{
    int i = 0;

    while ((!IsEOP()) && (currentChar != BLANK)&& (currentChar!= '\n'))
    {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
    if (currentChar == '\n')
    {
        AdvFile();
    }
}

Word CopyWordFile()
{
    int i = 0;

    while ((!EOP) && currentChar != NEWLINE)
    {
        currentWord.TabWord[i] = currentChar;
        AdvFile();
        i++;
    }
    currentWord.Length = i;
}

void CopyWordinput() {
    int i = 0;
    while (!IsEOP() && currentChar != NEWLINE) {
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}


void ADVSemicolon(){
    hasil.Length = 0;
    while((currentChar != MARK) && (currentChar != NEWLINE) && (currentChar != STRIP) && (currentChar != STOP)){
        hasil.TabWord[hasil.Length] = currentChar;
        hasil.Length++;
        ADV();
    }
    if(currentChar == MARK){ 
        ADV();
    }
}

boolean CekWord(Word hasil){
    boolean ada = false;
    if(hasil.Length != 0){
        ada = true;
    }
    return ada;
}

void DisplayWord (Word Word)
{
    {
    for (int i = 0; i < Word.Length; i++)
    {
        printf("%c", Word.TabWord[i]);
    }
}
}

Word SplitWordBlank(Word word)
{
    Word temp;
    int sum = 0, idx;
    for (int i = 0; i < word.Length; i++)
    {
        if (word.TabWord[i] == BLANK)
        {
            idx = i;
            break;
        }
    }

    for (int i = (idx + 1); i < word.Length; i++)
    {
        temp.TabWord[sum] = word.TabWord[i];
        sum++;
    }
    temp.Length = sum;

    return (temp);
}

Word ConcatWord(Word word_1, Word word_2)
{
    Word word;
    int count = 0;
    for(int i=0; i<word_1.Length; i++)
    {
        word.TabWord[count] = word_1.TabWord[i];
        count++;
    }

    for(int i=0; i<word_2.Length; i++)
    {
        word.TabWord[count] = word_2.TabWord[i];
        count++;
    }
    word.Length = word_1.Length + word_2.Length;

    return (word);
}

Word SplitWordMark(Word word)
{
    Word temp;
    int sum = 0, idx;
    for (int i = 0; i < word.Length; i++)
    {
        if (word.TabWord[i] == MARK)
        {
            idx = i;
            break;
        }
    }

    for (int i = (idx + 1); i < word.Length; i++)
    {
        temp.TabWord[sum] = word.TabWord[i];
        sum++;
    }
    temp.Length = sum;

    return (temp);
}

Word SplitWordLeftBlank(Word word)
{
    Word temp;
    int sum = 0, idx;
    for (int i = 0; i < word.Length; i++)
    {
        if (word.TabWord[i] == BLANK)
        {
            idx = i;
            break;
        }
    }

    for (int i = 0; i < idx; i++)
    {
        temp.TabWord[sum] = word.TabWord[i];
        sum++;
    }
    temp.Length = sum;

    return (temp);
}

Word SplitWordLeftMark(Word word)
{
    Word temp;
    int sum = 0, idx;
    for (int i = 0; i < word.Length; i++)
    {
        if (word.TabWord[i] == MARK)
        {
            idx = i;
            break;
        }
    }

    for (int i = 0; i < idx; i++)
    {
        temp.TabWord[sum] = word.TabWord[i];
        sum++;
    }
    temp.Length = sum;

    return (temp);
}

boolean isEqualWords(Word word1, char *str) {
    int i = 0;
    while (i < word1.Length && str[i] != '\0' && word1.TabWord[i] == str[i]) {
        i++;
    }
    return (i == word1.Length && str[i] == '\0');
}