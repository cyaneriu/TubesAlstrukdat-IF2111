#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"

boolean IsEmptyListLinier(List L){
    return First(L) == Nil;
}

void CreateEmptyListLinier(List *L){
    L->First = Nil;
}

address AlokasiListLinier(nama_barang X){
     address P = (address) malloc (sizeof(ElmtList));
     if (P!=NULL){
        CopyStringMap(P->info, X);
        P->next = Nil;
        return P;
     }
     else{
        return Nil;
     }
}

void DealokasiListLinier(address *P){
    free(*P);
}

address SearchListLinier(List L, nama_barang X){
    address P = First(L);
    while(P->next!=Nil){
        if(strCompare(P->info, X) != 1){
            P = P->next;
        }
        else{
            return P;
        }
    }
    if(strCompare(P->info, X) == 1){
        return P;
    }
    return Nil;
}

void InsVFirstListLinier(List *L, nama_barang X){
    address P = AlokasiListLinier(X);
    if(P!=Nil){
        if(IsEmptyListLinier(*L)){
            L->First = P;
        }
        else{
            P->next = L->First;
            L->First = P;
        }
    }
}

void InsVLastListLinier (List *L, nama_barang X){
    address P = AlokasiListLinier(X);
    if(P!=Nil){
        InsertLastListLinier(L, P);
    }
}

void DelVFirstListLinier (List *L, nama_barang *X){
    address P;
    DelFirstListLinier(L, &P);
    CopyStringMap(*X, P->info);
    DealokasiListLinier (&P);
}

void DelVLastListLinier (List *L, nama_barang *X){
    address P;
    DelLastListLinier(L, &P);
    CopyStringMap(*X, P->info);
    DealokasiListLinier (&P);
}

void InsertFirstListLinier (List *L, address P){
    P->next = First(*L);
    First(*L) = P;
}

void InsertAfterListLinier (List *L, address P, address Prec){
    P->next = Prec->next;
    Prec->next = P;
}

void InsertLastListLinier (List *L, address P){
    if(IsEmptyListLinier(*L)){
        InsertFirstListLinier(L, P);
    }
    else{
        address Prec = L->First;
        while(Prec->next!=Nil){
            Prec = Prec->next;
        }
        InsertAfterListLinier(L, P, Prec);
    }
}

void DelFirstListLinier (List *L, address *P){
    *P = First(*L);
    First(*L) = First(*L)->next;
    (*P)->next = Nil;
}

void DelPListLinier (List *L, nama_barang X){
    address Pdel = SearchListLinier(*L, X);
    if(Pdel!=Nil){
        address Prec = First(*L);
        if(Pdel == Prec){
            DelFirstListLinier(L, &Pdel);
        }
        else{
            while(Prec->next!=Pdel){
                Prec = Prec->next;
            }
            DelAfterListLinier(L, &Pdel, Prec);
        }
    }
}

void DelAddrListLinier (List *L, address P){
    if(P!=Nil){
        address P = First(*L);
        if(P == P){
            DelFirstListLinier(L, &P);
        }
        else{
            while(P->next!=P){
                P = P->next;
            }
            DelAfterListLinier(L, &P, P);
        }
    }
}

void DelLastListLinier (List *L, address *P){
	address last = First(*L);
	address prec = Nil;
	while (Next(last) != Nil){
		prec = last;
		last = Next(last);
	}
	*P = last;
	if (prec == Nil){
		First(*L) = Nil; 
	} else {
		Next(prec) = Nil;
	}
}

void DelAfterListLinier (List *L, address *Pdel, address Prec){
    *Pdel = Prec->next;
    if(Prec->next!=Nil){
        Prec->next = Prec->next->next;
        (*Pdel)->next = Nil;
    }
}

void PrintInfoListLinier(List L){
    printf("[");
    if(!IsEmptyListLinier(L)){
        address Q = First(L);
        while(Q->next!=Nil){
            printf("%s,", Q->info);
            Q = Q->next;
        }
        printf("%s", Q->info);
    }
    printf("]\n");
}

int NbElmtListLinier(List L){
    if(IsEmptyListLinier(L)){
        return 0;
    }
    else{
        int total = 1;
        address P = First(L);
        while(P->next!=Nil){
            total++;
            P = P->next;
        }
        return total;
    }
}

void InversListLinier(List *L){
   if(!IsEmptyListLinier(*L)){
        address P = First(*L);
        address After = P->next;
        while(After!=Nil){
            address temp = After;
            After = After->next;
            InsertFirstListLinier(L, temp);
            P->next = After;
        }
   }
}

void KonkatListLinier(List *L1, List *L2, List *L3){
    CreateEmptyListLinier(L3);
    if(IsEmptyListLinier(*L1)){
        First(*L3) = First(*L2);
    }
    else{
        First(*L3) = First(*L1);
        address P = First(*L1);
        while(P->next!=Nil){
            P = P->next;
        }
        P->next = First(*L2);
    }
    CreateEmptyListLinier(L2);
    CreateEmptyListLinier(L1);
}

int strCompare(char *string1, char *string2){
    boolean equal = true;

    int len1 = stringLen(string1);
    int len2 = stringLen(string2);

    // TES : cek panjang masing-masing string
    // printf("Len1, Len2\n");
    // printf("%d\n", len1);
    // printf("%d\n", len2);

    if (len1 == len2){
        for (int i = 0; i < len1; i++){
            // TES : cek setiap karakter string
            // printf("%c", string1[i]);
            // printf("%c", string2[i]);
            // printf("\n");
            if (string1[i] != string2[i]){
                equal = false;
                break;
            }
        }   
    } else {
        equal = false;
    }

    return equal;
}

void SwapNodeListLinier(List *L, address P1, address P2) {
    /*
    if (P1 == Nil || P2 == Nil || P1 == P2) {
        return;
    }

    address Prec1 = Nil, Prec2 = Nil, temp;
    address Curr = First(*L);

    while (Curr != Nil && Next(Curr) != P1 && Next(Curr) != P2) {
        Curr = Next(Curr);
    }

    if (Next(Curr) == P1) {
        Prec1 = Curr;
    } else if (Next(Curr) == P2) {
        Prec2 = Curr;
    }

    // Kasus salah satu node adalah first
    if (First(*L) == P1 || First(*L) == P2) {
        if (First(*L) == P1) {
            Prec2 = P1;
            P1 = P2;
        } else {
            Prec1 = P2;
            P2 = P1;
        }
    }

    // Tukar node
    if (Prec1 != Nil) {
        Next(Prec1) = P2;
    }
    if (Prec2 != Nil) {
        Next(Prec2) = P1;
    }

    temp = Next(P1);
    Next(P1) = Next(P2);
    Next(P2) = temp;

    // Ganti first apabila salah satu node adalah first
    if (First(*L) == P1) {
        First(*L) = P2;
    } else if (First(*L) == P2) {
        First(*L) = P1;
    }
    */
    if (P1 == Nil || P2 == Nil || P1 == P2) {
        // No swap needed if either node is Nil or both are the same
        return;
    }

    address Prev1 = Nil, Prev2 = Nil, temp;
    address Curr = First(*L);

    // Find predecessors of P1 and P2
    if (First(*L) != P1 && First(*L) != P2) {
        while (Curr != Nil && Next(Curr) != P1 && Next(Curr) != P2) {
            Curr = Next(Curr);
        }

        if (Next(Curr) == P1) {
            Prev1 = Curr;
        } else if (Next(Curr) == P2) {
            Prev2 = Curr;
        }
    }

    // Handle case where one of the nodes is the head
    if (First(*L) == P1) {
        Prev2 = P1;  // P1 is the head
    } else if (First(*L) == P2) {
        Prev1 = P2;  // P2 is the head
    }

    // If P1 and P2 are adjacent, handle specially
    if (Next(P1) == P2 || Next(P2) == P1) {
        if (Next(P1) == P2) {
            if (Prev1 != Nil) {
                Next(Prev1) = P2;
            } else {
                First(*L) = P2;
            }
            Next(P1) = Next(P2);
            Next(P2) = P1;
        } else {
            if (Prev2 != Nil) {
                Next(Prev2) = P1;
            } else {
                First(*L) = P1;
            }
            Next(P2) = Next(P1);
            Next(P1) = P2;
        }
        return;
    }

    // Swap for non-adjacent nodes
    if (Prev1 != Nil) {
        Next(Prev1) = P2;
    } else {
        First(*L) = P2;
    }

    if (Prev2 != Nil) {
        Next(Prev2) = P1;
    } else {
        First(*L) = P1;
    }

    // Swap their next pointers
    temp = Next(P1);
    Next(P1) = Next(P2);
    Next(P2) = temp;
}