#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include "stack.h"
#include "linked.h"

int main (){
	infotype pilih;
	infotype nilai;
	infotype antrian1 = 0;
	infotype antrian = 0;
	Queue Q1, Q2;
	Stack S1, S2;
	
	printf("Pilih No Loket (1/2) : ");
	scanf("%d", &pilih);
	
	CreateQueue(&Q1);
	CreateQueue(&Q2);
	CreateStack(&S1);
	CreateStack(&S2);
	
	while (1){
		if (pilih == 1){
		printf("1. Ambil Antrian\n");
		printf("2. Proses Antrian\n");
		printf("3. Cetak Antrian\n");
		printf("4. Riwayat Antrian\n");
		printf("5. Hapus Riwayat\n");
		printf("5. Keluar\n");
		infotype pilih1;
		printf("Pilih : ");
		scanf("%d", &pilih1);
		if (pilih1 == 1){
			ambilAntrian(&Q1, &antrian);
			printQueue(Q1);
		}else if (pilih1 == 2){
			prosesAntrian(&Q1, &nilai,&antrian);
			push(&S1, nilai);
			printf("Riwayat telah ditambahkan!\n");
			printQueue(Q1);
		}else if (pilih1 == 3){
			cetakAntrian(&antrian);
		} else if (pilih1 == 4){
			Tampil_List(S1);
		} else if (pilih1 == 5){
			pop(&S1, &nilai);
			printf("Riwayat antrian telah dihapus!\n");
			Tampil_List(S1);
			printf("Nilai yang dihapus adalah : %d", nilai);
		}else if (pilih1 == 6){
			return 0;
		}else {
			printf("Pilihan tidak valid!\n");
			return (1);
		}
	} else if (pilih == 2){
		printf("1. Ambil Antrian\n");
		printf("2. Proses Antrian\n");
		printf("3. Cetak Antrian\n");
		printf("4. Riwayat Antrian\n");
		printf("5. Hapus Riwayat\n");
		printf("6. Keluar\n");
		infotype pilih2;
		printf("Pilih : ");
		scanf("%d", &pilih2);
		if (pilih2 == 1){
			ambilAntrian(&Q2, &antrian);
			printQueue(Q2);
		}else if (pilih2 == 2){
			prosesAntrian(&Q2, &nilai,&antrian);
			push(&S1, nilai);
			printf("Riwayat telah ditambahkan!\n");
			printQueue(Q2);
		}else if (pilih2 == 3){
			cetakAntrian(&antrian);
		} else if(pilih2 == 4){
			Tampil_List(S2);
		} else if (pilih2 == 5){
			pop(&S1, &nilai);
			printf("Riwayat antrian telah dihapus!\n");
			Tampil_List(S2);
			printf("Nilai yang dihapus adalah : %d", nilai);
		}else if (pilih2 == 6){
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