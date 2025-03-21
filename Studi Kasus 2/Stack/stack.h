#ifndef stack_H
#define stack_H
#include <stdio.h>
#include "linked.h"
#include "boolean.h"

typedef address Stack;

Stack CreateStack (infotype nilai); // membuat elemen stack

boolean is_Empty (Stack s); // Mengecek apakah stack kosong

void push (Stack * s, infotype niali); // Menambahkan elemen ke stack

void pop (Stack * s, infotype *X); // Menghapus elemen dari stack

#endif