#ifndef WorkFunction
#define WorkFunction
void work(int *isiRekening);

int driverWork();

void workChallenge(int *isiRekening);
/*
Challenge Tebak Angka merupakan permainan yang meminta pemain menebak sebuah angka yang ditentukan oleh program. 
Pemain memiliki 10 (sepuluh) kesempatan untuk menebak angka yang benar. 
Program akan memberikan feedback apakah angka tebakan lebih besar, lebih kecil, atau sama dengan angka target. 
Jumlah kesempatan yang dipakai oleh pengguna akan mempengaruhi uang yang didapatkan.
*/

void tebakAngka(int *isiRekening);

void wordl3(int *isiRekening);

void sleep(double seconds);

int stringCompare(char *string1, char *string2);

char wordToString(Word *kata, char *string);

#endif