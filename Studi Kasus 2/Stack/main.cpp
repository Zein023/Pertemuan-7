#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main (){
	infotype pilih;
	infotype antrian;
	Queue Q1, Q2;
	
	printf("Pilih No Loket (1/2) : ");
	scanf("%d", &pilih);
	
	if (pilih == 1){
		CreateQueue(&Q1)
		printf("1. Ambil Antrian\n");
		printf("2. Proses Antrian\n");
		printf("3. Cetak Antrian\n");
		infotype pilih1;
		printf("Pilih (1/2/3) : ");
		scanf("%d", &pilih1);
		if (pilih1 == 1){
			ambilAntrian(&Q1, &antrian);
		}else if (pilih1 == 2){
			ambilAntrian(&Q1, &antrian);
		}else if (pilih1 == 3){
			cetakAntrian(Q1, &antrian);
		} else {
			printf("Pilihan tidak valid!\n");
			return (1);
		}
	} else if (pilih == 2){
		CreateQueue(&Q2)
		printf("1. Ambil Antrian\n");
		printf("2. Proses Antrian\n");
		printf("3. Cetak Antrian\n");
		infotype pilih1;
		printf("Pilih (1/2/3) : ");
		scanf("%d", &pilih1);
		if (pilih1 == 1){
			ambilAntrian(&Q2, &antrian);
		}else if (pilih1 == 2){
			ambilAntrian(&Q2, &antrian);
		}else if (pilih1 == 3){
			cetakAntrian(Q2, &antrian);
		} else {
			printf("Pilihan tidak valid!\n");
			return (1);
		}
	} else {
		printf("Pilihan tidak valid!\n");
		return (1);
	}
}