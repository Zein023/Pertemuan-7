#ifndef stack_H
#define stack_H
#include <stdio.h>
#include "linked.h"
#include "boolean.h"

typedef address Stack;

void CreateStack (Stack * s); // membuat elemen stack

void push (Stack * s, infotype niali); // Menambahkan elemen ke stack

void pop (Stack * s, infotype *X); // Menghapus elemen dari stack

#endif