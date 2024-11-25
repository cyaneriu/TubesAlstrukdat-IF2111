#include <stdio.h>
#include <stdlib.h>
#include "../ADT/queue.h"

//TERMINAL COMMAND:
//gcc driver_queue.c ../ADT/queue.c ../ADT/mesinkata.c ../ADT/mesinkarakter.c -o queue
//./queue

int main() {
    Queue q;
    QueueElType temp[MAX_LEN_QUEUE];

    // 1. CreateQueue
    printf("CreateQueue\n");
    CreateQueue(&q);
    printf("Queue telah dibuat.");

    // 2. isEmptyQueue
    printf("isEmptyQueue\n");
    printf("Apakah queue kosong? %s\n\n", isEmptyQueue(q) ? "Ya" : "Tidak");

    // 3. enqueue
    printf("enqueue\n");
    enqueue(&q, "x");
    enqueue(&q, "y");
    enqueue(&q, "z");
    printf("Queue: ");
    displayQueue(q);
    printf("\n");

    // 4. lengthQueue
    printf("lengthQueue\n");
    printf("Panjang queue: %d\n\n", lengthQueue(q));

    // 5. dequeue
    printf("dequeue\n");
    dequeue(&q, temp);
    printf("Dequeued item: \"%s\"\n", temp);
    printf("Queue: ");
    displayQueue(q);
    printf("\n");

    // 6. copyFirstQueue
    printf("copyFirstQueue\n");
    char firstItem[MAX_LEN_QUEUE];
    copyFirstQueue(q, firstItem);
    printf("First item: \"%s\"\n\n", firstItem);

    // 7. isFullQueue
    printf("isFullQueue\n");
    printf("Apakah queue penuh? %s\n\n", isFullQueue(q) ? "Ya" : "Tidak");

    // 8. displayQueue
    printf("displayQueue\n");
    printf("Queue: ");
    displayQueue(q);
    printf("\n");
}
