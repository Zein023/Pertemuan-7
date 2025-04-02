#ifndef data_H
#define data_H
#include "linked.h"
#include <string.h>

#define MAX_KOTA 100
#define MAX_NAMA 100

#define nama(p) p.nama->info
#define next(p) p.nama->next

typedef struct nodeKota *city;
typedef struct nodeKota {
    char *kota;
    address nama;
    city pkota;
} Data;

boolean isKotaEmpty(city k);

void CreateNKota(city *k);

void isiKota(city * k, char * nilai);

void insertKota(city * k, city KNew);

void Tampil_Kota(city k);

void deleteKota(city *k, int index);

#endif