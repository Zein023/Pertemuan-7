#ifndef queue_H
#define queue_H
#include "boolean.h"
#include "linked.h"

typedef struct{
	address front;
	address rear;
} Queue;

void CreateQueue (Queue *Q);

boolean is_Empty (Queue Q);

boolean is_full (Queue Q);

void EnQueue (Queue * Q, infotype X);

void deQueue (Queue * Q, infotype *X);

void ambilAntrian(Queue * Q, infotype *antrian);

void prosesAntrian (Queue * Q, infotype *nilai, infotype *antrian);

void cetakAntrian (infotype *antrian);

void printQueue(Queue Q);

#endif