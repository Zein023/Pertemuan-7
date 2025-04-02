#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "linked.h"

int main() {
    Data kota;
    city k, newKota;
    address newNode;
    char tempNama[50];
    int count;
    char nama[50];
    int pilih;
    infotype x;
    
    CreateNKota(&k); // Inisialisasi linked list

    while (1) {
        printf("===== M E N U =====\n");
        printf("1. Tambah Kota\n");
        printf("2. Tambah Penduduk\n");
        printf("3. Hapus Kota\n");
        printf("4. Keluar!!!!\n");
        printf("Pilih : ");
        scanf("%d", &pilih);
        getchar();

        switch (pilih) {
            case 1:
                CreateNKota(&newKota); // Buat node baru, jangan overwrite `k`
                printf("Kota : ");
                fgets(nama, sizeof(nama), stdin);
                nama[strcspn(nama, "\n")] = '\0';
                isiKota(&newKota, nama);

                insertKota(&k, newKota); // Masukkan kota ke linked list

                printf("\nMasukkan nama-nama penduduk (ketik 'selesai' untuk mengakhiri):\n");
                newKota->nama = NULL;
                while (1) {
                    printf("Nama: ");
                    fgets(tempNama, sizeof(tempNama), stdin);
                    tempNama[strcspn(tempNama, "\n")] = '\0';

                    if (strcmp(tempNama, "selesai") == 0) {
                        break;
                    }

                    Create_Node(&newNode);
                    if (newNode != NULL) {
                        newNode->info = strdup(tempNama);
                        Ins_Awal(&newKota->nama, newNode);
                    }
                }
				system("cls");
                printf("List Kota: \n");
                Tampil_Kota(k); // Tampilkan semua kota
                printf("List Nama di kota %s: \n", newKota->kota);
                Tampil_List(newKota->nama);
                printf("\n");
                break;
                
            case 2:
                if (isKotaEmpty(k)) { 
                    printf("Belum ada kota yang diinputkan!\n");
                    break;
                }
                
                printf("List Kota yang ada:\n");
                Tampil_Kota(k);
                
                printf("\nKota ke - ");
                scanf("%d", &pilih);
                getchar();
                
                city temp = k;
                for (int i = 0; i < pilih; i++) {
                    if (temp == NULL) break;
                    temp = temp->pkota;
                }
                
                if (temp == NULL) {
                    printf("Kota dengan nomor tersebut tidak ditemukan!\n");
                    break;
                }

                printf("\nMasukkan nama-nama penduduk (ketik 'selesai' untuk mengakhiri):\n");
                while (1) {
                    printf("Nama: ");
                    fgets(tempNama, sizeof(tempNama), stdin);
                    tempNama[strcspn(tempNama, "\n")] = '\0';

                    if (strcmp(tempNama, "selesai") == 0) {
                        break;
                    }

                    Create_Node(&newNode);
                    if (newNode != NULL) {
                        newNode->info = strdup(tempNama);
                        Ins_Awal(&temp->nama, newNode);
                    }
                }
                
                printf("\nList Kota: \n");
                Tampil_Kota(k);
                printf("List Nama di kota %s: \n", temp->kota);
                Tampil_List(temp->nama);
                printf("\n");
                break;
                
            case 3:
            	printf("Hapus Kota ke - ");
            	scanf("%d", &pilih);
//            	city temp2 = k;
//            	for (int i = 0; i <= pilih; i++){
//            		temp2 = temp2->pkota;
//				}
				deleteKota(&k, pilih);
				Tampil_Kota(k);
				break;
            	
				
            case 4:
                printf("Keluar dari program.\n");
                while (k != NULL) {
                    city temp = k;
                    k = k->pkota;
                    free(temp->kota);
                    free(temp);
                }
                return 0;
        }
    }
}
