#include "linked.h"
#include "boolean.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


Stack CreateStack (infotype nilai){
	Stack p;
	Create_Node(&p);
	Isi_Node(&p, nilai);
	return p;
}

boolean is_Empty (Stack s){
	return s == NULL;
}

void push(Stack * s, infotype nilai){
	Stack newNode;
    Create_Node(&newNode);
    if (newNode != NULL) {  // Pastikan node berhasil dibuat
        Isi_Node(&newNode, nilai); // Isi node dengan nilai baru
        Ins_Awal(s, newNode); // Masukkan node ke dalam stack
    }
}

void pop (Stack * s, infotype *X){
	Del_Awal(s, X);
} 

void convertToBinary(int n) {
    Stack s = NULL; // Inisialisasi stack kosong
    int remainder;

    // Step 1: Simpan hasil bagi dalam stack
    while (n > 0) {
        remainder = n % 2;
        push(&s, remainder);
        n /= 2;
    }

    // Step 2: Cetak hasil konversi dengan pop
    printf("Hasil konversi biner: ");
    while (!is_Empty(s)) {
        int bit;
        pop(&s, &bit);
        printf("%d", bit);
    }
    printf("\n");
}
