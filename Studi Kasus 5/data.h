#ifndef data_H
#define data_H
#include "linked.h"
#include <string.h>

#define MAX_KOTA 100
#define MAX_NAMA 100

#define nama(p) p.nama->info
#define next(p) p.nama->next

typedef struct {
    char kota[MAX_KOTA];
    address nama;
} Data;

#endif