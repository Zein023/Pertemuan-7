#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "linked.h"

void CreateQueue(Queue *Q) {
    (*Q).front = NULL;  // Menginisialisasi queue kosong
    (*Q).rear = NULL;
}

boolean is_Empty(Queue Q) {
    return (Q.front == NULL);
}

boolean is_full(Queue Q) {
    return 0; // Queue linked list tidak pernah penuh kecuali memori habis
}

void EnQueue(Queue *Q, infotype X) {
	address newNode;
    Create_Node(&newNode);
    if (newNode == NULL) {
        printf("Gagal alokasi memori!\n");
        return;
    }
	if (!isEmpty(newNode)){
		Isi_Node(&newNode, X);
		if (is_Empty(*Q)){
			Q->front = newNode;
			Q->rear = newNode;
		} else {
			Ins_Akhir(&(Q->rear), newNode);
    		Q->rear = newNode;
		}
	}
    
}


void deQueue(Queue *Q, infotype *X) {
    if (is_Empty(*Q)) {
        printf("Antrian kosong, tidak ada yang diproses.\n");
        return;
    }
	Del_Awal(&(Q->front), X);
}

void ambilAntrian(Queue *Q, infotype *antrian) {
    infotype X = *antrian + 1;
    EnQueue(Q, X);
    *antrian += 1;
    cetakAntrian(antrian);
}

void prosesAntrian(Queue *Q, infotype *X, infotype *antrian) {
    deQueue(Q, X);
    if (*antrian != 0){
    	*antrian -= 1;
	}
    cetakAntrian(antrian);
}

void cetakAntrian(infotype *antrian) {
    printf("Jumlah Antrian Sekarang : %d\n", *antrian);
}

void printQueue(Queue Q) {
    if (is_Empty(Q)) {
        printf("Queue kosong!\n");
        return;
    }
    
    address temp = Q.front;
    printf("Isi Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

