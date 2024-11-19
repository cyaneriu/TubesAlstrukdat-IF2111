#include <stdio.h>
#include "queue.h"

/* *** Kreator *** */
void CreateQueue(Queue *q){
    q->idxHead = IDX_UNDEF;
    q->idxTail = IDX_UNDEF;
}

/* ********* Prototype ********* */
boolean isEmpty(Queue q){
    return q.idxHead == IDX_UNDEF && q.idxTail == IDX_UNDEF;
}

boolean isFull(Queue q){
    return (q.idxTail + 1) % CAPACITY == q.idxHead;
}

int length(Queue q){
    if (isEmpty(q)){
        return 0;
    }
    else{
        return (CAPACITY - q.idxHead + q.idxTail + 1) % CAPACITY;
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, ElType val){
    if(isEmpty(*q)){
        q->idxHead = 0;
        q->idxTail = 0;
    }
    else{
        q->idxTail = (q->idxTail + 1) % CAPACITY;
    }
    q->buffer[q->idxTail] = val;
}

void dequeue(Queue *q, ElType *val){
    if (isEmpty(*q)){
        return;
    }
    *val = HEAD(*q);
    if (q->idxHead == q->idxTail){
        q->idxHead = IDX_UNDEF;
        q->idxTail = IDX_UNDEF;
    }
    else{
        q->idxHead = (q->idxHead + 1) % CAPACITY;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q){
    if (isEmpty(q)){
        printf("[]\n");
    }
    else{
        printf("[");
        int i = q.idxHead;
        while (true){
            printf("%d", q.buffer[i]);
            if (i == q.idxTail) break;
            printf(",");
            i = (i + 1) % CAPACITY;
        }
    }
    printf("]\n");
}