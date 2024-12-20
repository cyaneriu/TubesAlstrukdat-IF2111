#ifndef QUEUE_H
#define QUEUE_H

#include "boolean.h"
#include "mesinkata.h"
#include "mesinkarakter.h"

#define CAPACITY_QUEUE 50
#define MAX_LEN_QUEUE 50
#define IDX_UNDEF -1

typedef char QueueElType[MAX_LEN_QUEUE]; 
typedef struct {
    QueueElType buffer[CAPACITY_QUEUE];
    int idxHead;
    int idxTail;
} Queue;

#define IDX_HEAD(q) (q).idxHead
#define IDX_TAIL(q) (q).idxTail
#define     HEAD(q) (q).buffer[(q).idxHead]
#define     TAIL(q) (q).buffer[(q).idxTail]

void CreateQueue(Queue *q);

boolean isEmptyQueue(Queue q);

boolean isFullQueue(Queue q);

int lengthQueue(Queue q);

void enqueue(Queue *q, QueueElType val);

void dequeue(Queue *q, QueueElType *val);

void displayQueue(Queue q);

void copyFirstQueue(Queue q, char *destChar);

#endif