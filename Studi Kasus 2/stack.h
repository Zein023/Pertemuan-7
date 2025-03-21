#ifndef stack_H
#define stack_H
#include <stdio.h>
#include "linked.h"
#include "boolean.h"

typedef address Stack;

void initStack (Stack * s); // Menginisialisasi top

Stack* CreateStack (Stack * s); // membuat elemen stack

boolean isEmpty (Stack s); // Mengecek apakah stack kosong

void push (Stack * s, stack SNew); // Menambahkan elemen ke stack

void pop (Stack * s, infotype *X); // Menghapus elemen dari stack

void peek (Stack * s); // Melihat value elemen di top tanpa menghapusnya

#endif