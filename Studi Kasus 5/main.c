#include <stdio.h>
#include <stdlib.h>
#include "data.h"
#include "linked.h"

int main() {
    Data kota[20];
    address newNode;
    char tempNama[50];
    int count;
    
    printf("Jumlah Kota : ");
    scanf("%d", &count);
    getchar(); // Clear the newline
    
    for (int i = 0; i < count; i++) {
        // Input kota
        printf("\nKota ke-%d\n", i+1);
        printf("Masukkan nama kota: ");
        fgets(kota[i].kota, sizeof(kota[i].kota), stdin);
        kota[i].kota[strcspn(kota[i].kota, "\n")] = '\0';
    
        // Initialize linked list head
        kota[i].nama = NULL;
    
        // Input nama
        printf("Masukkan nama-nama penduduk (ketik 'selesai' untuk mengakhiri):\n");
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
                Ins_Awal(&kota[i].nama, newNode);
            }
        }
    
        // Menampilkan info
        printf("\nData kota : %s\n", kota[i].kota);
        printf("Daftar nama:\n");
        Tampil_List(kota[i].nama);
    }
    
    // Cleanup seluruh kota
    for (int i = 0; i < count; i++) {
        DeAlokasi(&kota[i].nama);
    }
    
    return 0;
}