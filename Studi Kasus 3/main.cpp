#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main (){
	infotype pilih;
	infotype nilai;
	infotype antrian1 = 0;
	infotype antrian = 0;
	Queue Q1, Q2;
	
	printf("Pilih No Loket (1/2) : ");
	scanf("%d", &pilih);
	
	CreateQueue(&Q1);
	CreateQueue(&Q2);
	
	while (1){
		if (pilih == 1){
		printf("1. Ambil Antrian\n");
		printf("2. Proses Antrian\n");
		printf("3. Cetak Antrian\n");
		printf("4. Keluar\n");
		infotype pilih1;
		printf("Pilih (1/2/3/4) : ");
		scanf("%d", &pilih1);
		if (pilih1 == 1){
			ambilAntrian(&Q1, &antrian);
			printQueue(Q1);
		}else if (pilih1 == 2){
			prosesAntrian(&Q1, &nilai,&antrian);
			printQueue(Q1);
		}else if (pilih1 == 3){
			cetakAntrian(&antrian);
		} else if (pilih1 == 4){
			return 0;
		}else {
			printf("Pilihan tidak valid!\n");
			return (1);
		}
	} else if (pilih == 2){
		printf("1. Ambil Antrian\n");
		printf("2. Proses Antrian\n");
		printf("3. Cetak Antrian\n");
		printf("4. Keluar\n");
		infotype pilih1;
		printf("Pilih (1/2/3/4) : ");
		scanf("%d", &pilih1);
		if (pilih1 == 1){
			ambilAntrian(&Q2, &antrian);
			printQueue(Q2);
		}else if (pilih1 == 2){
			prosesAntrian(&Q1, &nilai,&antrian);
			printQueue(Q2);
		}else if (pilih1 == 3){
			cetakAntrian(&antrian);
		} else if(pilih1 == 4){
			return 0;
		} else {
			printf("Pilihan tidak valid!\n");
			return (1);
		}
	} else {
		printf("Pilihan tidak valid!\n");
		return (1);
	}
	}
	return 0;
}