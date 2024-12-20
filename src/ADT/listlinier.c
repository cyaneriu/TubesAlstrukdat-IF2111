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
        if(P->info!=X){
            P = P->next;
        }
        else{
            return P;
        }
    }
    if(P->info==X){
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
    address P = SearchListLinier(*L, X);
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
            InsertFirst(L, temp);
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