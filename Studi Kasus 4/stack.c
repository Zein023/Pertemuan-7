#include "linked.h"
#include "boolean.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>


void CreateStack (Stack * s){
	Create_Node(s);
//	Isi_Node(&s, nilai);
}

void push(Stack * s, infotype nilai){
	Stack newNode;
    Create_Node(&newNode);
    if (!isEmpty(newNode)) {  // Pastikan node berhasil dibuat
        Isi_Node(&newNode, nilai); // Isi node dengan nilai baru
        Ins_Awal(s, newNode); // Masukkan node ke dalam stack
    }
}

void pop (Stack * s, infotype *X){
	Del_Awal(s, X);
} 