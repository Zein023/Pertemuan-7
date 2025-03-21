#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

void CreateQueue(Queue *Q) {
    *Q = NULL;  // Menginisialisasi queue kosong
}

boolean is_Empty(Queue Q) {
    return (Q == NULL);
}

boolean is_full(Queue Q) {
    return 0; // Queue linked list tidak pernah penuh kecuali memori habis
}

void EnQueue(Queue *Q, infotype X) {
    address newNode = (address) malloc(sizeof(newNode));
    if (newNode == NULL) {
        printf("Gagal alokasi memori!\n");
        return;
    }

    newNode->info = X;
    newNode->next = NULL;

    Ins_Akhir(Q, newNode);
}


void deQueue(Queue *Q, infotype *X) {
    if (is_Empty(*Q)) {
        printf("Antrian kosong, tidak ada yang diproses.\n");
        return;
    }

    address temp = *Q;
    *X = temp->info; // Mengambil nilai dari node pertama
    *Q = temp->next; // Menggeser head ke elemen berikutnya
    free(temp);      // Menghapus node pertama
}

void ambilAntrian(Queue *Q, infotype *antrian) {
    infotype X = *antrian + 1;
    EnQueue(Q, X);
    *antrian += 1;
    cetakAntrian(antrian);
}

void prosesAntrian(Queue *Q, infotype *X, infotype *antrian) {
    deQueue(Q, X);
    *antrian -= 1;
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
    
    address temp = Q;
    printf("Isi Queue: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

