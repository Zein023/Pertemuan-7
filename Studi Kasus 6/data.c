#include <stdio.h>
#include "data.h"
#include "boolean.h"

boolean isKotaEmpty(city k){
	return k == NULL;
}

void CreateNKota(city *k){
	*k = (city)malloc(sizeof(Data));

    if (*k == NULL) {
        printf("Alokasi tidak berhasil!\n");
    } else {
    	(*k)->kota = NULL;
        (*k)->pkota = NULL;
        (*k)->nama = NULL;
    }
}

void isiKota(city * k, char * nilai){
	if (!isKotaEmpty(*k)) {
        (*k)->kota = strdup(nilai);
        (*k)->pkota = NULL;
    } else {
        printf("Node belum dialokasikan!\n");
    }
//	char tempNama[50];
//	fgets(tempNama, sizeof(tempNama), stdin);
//	tempNama[strcspn(tempNama, "\n")] = '\0';
//	
//	(*k)->kota = strdup(tempNama);
}

void insertKota(city * k, city KNew){
	if (isKotaEmpty(*k)) {
        *k = KNew;
    } else {
        city temp = *k;
        while (!isKotaEmpty(temp->pkota)) {
            temp = temp->pkota;
        }
        temp->pkota = KNew;
    }
    KNew->pkota = NULL;
}

void Tampil_Kota(city k) {
    int count = 0;
    while (!isKotaEmpty(k)) {
        if (k->kota != NULL) { 
            printf("Kota ke-%d (%s)\n", count, k->kota);
        } 
        k = k->pkota;
        count++;
    }
}

void deleteKota(city *k, int index) {
    if (isKotaEmpty(*k)) {
        printf("List kota kosong!\n");
        return;
    }

    city temp = *k;
    city prev = NULL;

//    if (temp == *k) {
//        *k = temp->pkota;
//        DeAlokasi(&(temp->nama));
//        if (temp->kota != NULL) {
//            free(temp->kota);
//        }
//        free(temp);
//        return;
//    }
//    
    for (int i = 0; i < index; i++) {
        prev = temp;
        temp = temp->pkota;
    }

    if (prev != NULL) {
        prev->pkota = temp->pkota;
        DeAlokasi(&(temp->nama));
        if (temp->kota != NULL) {
            free(temp->kota);
        }
    }
}

