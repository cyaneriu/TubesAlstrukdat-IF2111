#include <stdio.h>
#include "list_statik.h"

#include "boolean.h"

void CreateListStatik(ListStatik *l){
    for (int i = IDX_MIN; i<=CAPACITY-1; i++){
        ELMT(*l,i)=MARK;
    }
}

int listLength(ListStatik l){
    int jumlah = 0;
    for (int i=IDX_MIN;i<=CAPACITY-1;i++){
        if (ELMT (l,i)!=MARK){
            jumlah++;
        }
    }
    return jumlah;
}

IdxType getFirstIdx(ListStatik l){
    return IDX_MIN;
}

IdxType getLastIdx(ListStatik l){
    return (listLength(l)-1);
}

boolean isIdxValid(ListStatik l, IdxType i){
    return (i<CAPACITY && i>=IDX_MIN);
}

boolean isIdxEff(ListStatik l, IdxType i){
    return (i>=IDX_MIN && listLength(l)>i);
}

boolean isEmpty(ListStatik l){
    return (listLength (l) == IDX_MIN);
}

boolean isFull(ListStatik l){
    return (listLength (l) == CAPACITY);
}

void readList(ListStatik *l){
    int n,x;
    CreateListStatik (l);
    scanf ("%d",&n);
    while (n<IDX_MIN || n> CAPACITY) {
        scanf ("%d",&n);
    }
    if (n!=0){
        for (int i = 0; i<n; i++){
            scanf("%d",&x);
            ELMT (*l,i)= x;
        }
    }
}

void printList(ListStatik l){
    printf ("[");
    for (int i = IDX_MIN; i<=listLength(l)-1;i++){
        if (i == listLength (l)-1){
            printf("%d",ELMT (l,i));
        } else{
            printf("%d,",ELMT (l,i));
        }
    }
    printf("]");
}

ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
    ListStatik l;
    CreateListStatik (&l);
    if (plus){
        for (int i = 0; i<=listLength(l1)-1;i++){
            ELMT(l,i) = ELMT (l1,i)+ELMT (l2,i);
        }
    } else{
        for (int i = 0; i<=listLength(l1)-1;i++){
            ELMT(l,i) = ELMT (l1,i)-ELMT (l2,i);
        }
    }
    return l;
}

boolean isListEqual(ListStatik l1, ListStatik l2){
    if (listLength(l1)==listLength(l2)){
        for (int i= IDX_MIN ;i<=listLength(l1)-1;i++){
            if (ELMT (l1,i)!=ELMT (l2,i)){
                return false;
            } else if (i == listLength(l1)-1){
                return true;
            }
        }
    } else {
        return false;
    }
}

int indexOf(ListStatik l, ElType val){
    for (int i=0;i<=listLength(l)-1;i++){
        if (ELMT (l,i)==val){
            return i;
        }
    }
    return IDX_UNDEF;
}

void extremeValues(ListStatik l, ElType *max, ElType *min){
    for (int i = 0; i<=listLength(l)-1;i++){
        if (ELMT(l,i)>*max){
            *max = ELMT (l,i);
        } 
        if (ELMT (l,i)<*min){
            *min = ELMT (l,i);
        }
    }
}

void insertFirst(ListStatik *l, ElType val){
    for (int i = listLength(*l)-1; i>=0;i--){
        ELMT (*l,i+1)= ELMT (*l,i);
    }
    ELMT (*l,0)=val;
}

void insertAt(ListStatik *l, ElType val, IdxType idx){
    int temp = ELMT (*l,idx);
    for (int i=idx; i<=listLength(*l)-1;i++){
        int temp1 = ELMT (*l, i+1);
        ELMT (*l,i+1)= temp;
        temp=temp1;
    }
    ELMT (*l,idx)= val;
}

void insertLast(ListStatik *l, ElType val){
    ELMT (*l,listLength(*l))=val;
}

void deleteFirst(ListStatik *l, ElType *val){
    *val = ELMT (*l,0);
    for (int i=0;i<=listLength(*l)-2;i++){
        ELMT (*l,i)=ELMT (*l,i+1);
    }
    ELMT (*l,listLength(*l)-1)=MARK;
}

void deleteAt(ListStatik *l, ElType *val, IdxType idx){
    *val = ELMT (*l,idx);
    int temp = ELMT (*l,idx+1);
    for (int i = idx+1; i<=listLength(*l)-1;i++){
        int temp1 = ELMT (*l,i+1);
        ELMT (*l,i-1)= temp;
        temp = temp1;
    }
    ELMT (*l,listLength(*l)-1)= MARK;
}

void deleteLast(ListStatik *l, ElType *val){
    *val = ELMT(*l, listLength(*l)-1);
    ELMT (*l,listLength(*l)-1)=MARK;
}

void sortList(ListStatik *l, boolean asc){
    int temp;
    int a = listLength(*l)-1;
    if (asc){
        while (a>=1){
            for(int i =0;i<a;i++){
                if (ELMT (*l,i)>ELMT (*l,i+1)){
                    temp = ELMT (*l, i);
                    ELMT (*l,i)= ELMT (*l,i+1);
                    ELMT (*l,i+1)=temp;
                }
            }
        a--;
        }
    } else {
        while (a>=0){
            for (int i=0; i<a;i++){
                if (ELMT (*l,i)<ELMT (*l,i+1)){
                    temp = ELMT (*l,i);
                    ELMT (*l,i)= ELMT (*l,i+1);
                    ELMT (*l,i+1)=temp;
                }
            }
            a--;
        }
    }
}
