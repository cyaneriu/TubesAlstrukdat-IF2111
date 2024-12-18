#include "listlinier.h"

boolean IsEmptyLL(LinkedList L){
    return First(L) == NilLL;
}

void CreateEmptyLL(LinkedList *L){
    First(*L) = NilLL;
}

addressLL AlokasiLL(infotypeLL* X){
    addressLL P;
    P = (addressLL) malloc(504*MAX_LEN);
    if (P != NilLL){
        stringCopy(P->info, X);
        P->next = NilLL;
    }
    return P;
}

void Dealokasi(addressLL *P){
    free(*P);
}

boolean isMemberLL(LinkedList L, char* songName){
    addressLL p = L.First;
    boolean isFound = false;
    while (p != NilLL && !isFound){
        if (CompareString(p->info, songName)) isFound = true;
        p = p->next;
    }
    return isFound;
}

void InsertLastLL(LinkedList* L, infotypeLL* X){
    addressLL p = L->First;
    addressLL np = AlokasiLL(X);
    if (IsEmptyLL(*L))
    {
        L->First = np;
        return;
    }
    while (p->next != NilLL) p = p->next;
    p->next = np;
}

void InsertFirst(LinkedList *L, addressLL P){
    Next(P) = First(*L);
    First(*L) = P;
}

int NbElmt(LinkedList L){
    if (IsEmptyLL(L)) return 0;
    int count = 1;
    addressLL P = First(L);
    while (P->next != NilLL)
    {
        P = Next(P);
        count++;
    }
    return count;
}

void displayLinkedList(LinkedList L){
    int idx = 1;
    addressLL P = First(L);
    while (P != NilLL)
    {
        printf("  %d. %s\n", idx, P->info);
        idx++;
        P = P->next;
    }
}

void swapLinkedList(LinkedList* L, int x, int y){
    if (x > y){
        int temp = x;
        x = y;
        y = temp;
    }
    x--; y--;
    char temp[100][MAX_LEN];
    int n = 0;
    addressLL p = L->First;
    while (p != NULL){
        stringCopy(temp[n], p->info);
        n++;
        p = p->next;
    }
    CreateEmptyLL(L);
    for (int i = 0; i < n; ++i){
        if (i == x){
            InsertLastLL(L, temp[y]);
        }
        else if (i == y){
            InsertLastLL(L, temp[x]);
        }
        else{
            InsertLastLL(L, temp[i]);
        }
    }
}

char* GetLL(LinkedList L, int idx){
    int i = 1;
    addressLL P = First(L);
    while (i<=idx){
        i++;
        P = P->next;
    }
    return P->info;
}

void delLLidx(LinkedList* L, int idx){
    addressLL p = L->First;
    if (idx == 0){
        L->First = p->next;
        Dealokasi(&p);  
        return;
    }
    for (int i = 0; i < idx-1; ++i){
        p = p->next;
    }
    addressLL q = p->next;
    p->next = q->next;
    Dealokasi(&q);
}