#include <stdio.h>
#include <string.h>
#include "queue.h"
#include "mesinkata.h"

/* *** Kreator *** */
void CreateQueue(Queue *q){
    q->idxHead = IDX_UNDEF;
    q->idxTail = IDX_UNDEF;
}

boolean isEmptyQueue(Queue q){
    return q.idxHead == IDX_UNDEF && q.idxTail == IDX_UNDEF;
}

boolean isFullQueue(Queue q){
    return (q.idxTail + 1) % CAPACITY_QUEUE == q.idxHead;
}

int lengthQueue(Queue q){
    if (isEmptyQueue(q)){
        return 0;
    }
    else{
        return (CAPACITY_QUEUE - q.idxHead + q.idxTail + 1) % CAPACITY_QUEUE;
    }
}

/* *** Primitif Add/Delete *** */
void enqueue(Queue *q, QueueElType val){
    if(isEmptyQueue(*q)){
        q->idxHead = 0;
        q->idxTail = 0;
    }
    else{
        q->idxTail = (q->idxTail + 1) % CAPACITY_QUEUE;
    }
    copyString(q->buffer[q->idxTail], val, MAX_LEN_QUEUE);
}

void dequeue(Queue *q, QueueElType *val){
    if (isEmptyQueue(*q)){
        return;
    }
    copyString(*val, q->buffer[q->idxHead], MAX_LEN_QUEUE);
    if (q->idxHead == q->idxTail){
        q->idxHead = IDX_UNDEF;
        q->idxTail = IDX_UNDEF;
    }
    else{
        q->idxHead = (q->idxHead + 1) % CAPACITY_QUEUE;
    }
}

/* *** Display Queue *** */
void displayQueue(Queue q){
    if (isEmptyQueue(q)){
        printf("[]\n");
    }
    else{
        printf("[");
        int i = q.idxHead;
        while (true){
            printf("\"%s\"", q.buffer[i]);
            if (i == q.idxTail) break;
            printf(", ");
            i = (i + 1) % CAPACITY_QUEUE;
        }
        printf("]\n");
    }
}

void copyFirstQueue(Queue q, char *destChar) {
    if (!isEmptyQueue(q)) {
        copyString(destChar, q.buffer[q.idxHead], MAX_LEN_QUEUE);
    } else {
        destChar[0] = '\0';
    }
}

/*void expandQueue(Queue *q) {
    QueueElType *newBuffer = (QueueElType *)malloc(2 * CAPACITY_QUEUE * sizeof(QueueElType));
    int newCapacity = 2 * CAPACITY_QUEUE;
    int i = 0;

    if (!isEmptyQueue(*q)) {
        int idx = q->idxHead;
        do {
            copyString(newBuffer[i], q->buffer[idx], MAX_LEN_QUEUE);
            idx = (idx + 1) % CAPACITY_QUEUE;
            i++;
        } while (idx != (q->idxTail + 1) % CAPACITY_QUEUE);
    }

    free(q->buffer);
    q->buffer = newBuffer;
    q->idxHead = 0;
    q->idxTail = i - 1;
    CAPACITY_QUEUE = newCapacity;
}*/