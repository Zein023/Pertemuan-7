#include <stdio.h>
#include <stdlib.h>
#include "linked.h"

boolean isEmpty(address p) {
    return p == NULL;
}

void Create_Node(address *p) {
    *p = (address)malloc(sizeof(ElmtList));

    if (*p == NULL) {
        printf("Alokasi tidak berhasil!\n");
    } else {
        (*p)->info = "";
        (*p)->next = NULL;
    }
}

void Isi_Node(address *p, char nilai) {
    if (!isEmpty(*p)) {
        (*p)->info = nilai;
        (*p)->next = NULL;
    } else {
        printf("Node belum dialokasikan!\n");
    }
}

void Tampil_List(address p) {
    while (!isEmpty(p)) {
        printf("%s -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

void Ins_Awal(address *p, address PNew) {
    if (!isEmpty(PNew)) {
        PNew->next = *p;
        *p = PNew;
    }
}

void Ins_Akhir(address *p, address PNew) {
    if (isEmpty(*p)) {
        *p = PNew;
    } else {
        address temp = *p;
        while (!isEmpty(temp->next)) {
            temp = temp->next;
        }
        temp->next = PNew;
    }
    PNew->next = NULL;
}

address Search(address p, infotype nilai) {
    while (!isEmpty(p)) {
        if (p->info == nilai) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void InsertAfter(address *pBef, address PNew) {
    if (!isEmpty(*pBef)) {
        PNew->next = (*pBef)->next;
        (*pBef)->next = PNew;
    } else {
        printf("Error: pBef adalah NULL\n");
    }
}

void Del_Awal(address *p, infotype *X) {
    if (!isEmpty(*p)) {
        address temp = *p;
        *X = temp->info;
        *p = temp->next;
        free(temp);
    } else {
        printf("List kosong!\n");
    }
}

void Del_Akhir(address *p, infotype *X) {
    if (isEmpty(*p)) {
        printf("List kosong!\n");
        return;
    }

    address temp = *p;
    address prev = NULL;

    while (!isEmpty(temp->next)) {
        prev = temp;
        temp = temp->next;
    }

    *X = temp->info;
    free(temp);

    if (prev == NULL) {
        *p = NULL;
    } else {
        prev->next = NULL;
    }
}

void Del_After(address *pBef, infotype *X) {
    if (!isEmpty((*pBef)->next)) {
        address temp = (*pBef)->next;
        *X = temp->info;
        (*pBef)->next = temp->next;
        free(temp);
    } else {
        printf("Node yang ditunjuk pBef adalah NULL\n");
    }
}

void DeAlokasi(address *p) {
    address temp;
    while (!isEmpty(*p)) {
        temp = *p;
        *p = (*p)->next;
        free(temp);
    }
    printf("Semua node sudah di-dealokasi!\n");
}

int NbElmt(address p) {
    int count = 0;
    while (!isEmpty(p)) {
        count++;
        p = p->next;
    }
    return count;
}

infotype Min(address p) {
    if (isEmpty(p)) {
        printf("List kosong!\n");
        return -1; // Nilai default jika list kosong
    }

    infotype minVal = p->info;
    while (!isEmpty(p)) {
        if (p->info < minVal) {
            minVal = p->info;
        }
        p = p->next;
    }
    return minVal;
}

infotype Rerata(address p) {
    if (isEmpty(p)) {
        printf("List kosong!\n");
        return -1;
    }

    int sum = 0, count = 0;
    while (!isEmpty(p)) {
        sum += p->info;
        count++;
        p = p->next;
    }
    return (count > 0) ? sum / count : 0;
}

address BalikList(address p) {
    address prev = NULL;
    address current = p;
    address after = NULL;

    while (!isEmpty(current)) {
        after = current->next;
        current->next = prev;
        prev = current;
        current = after;
    }

    return prev;
}

void Del_Value(address *p, infotype *X) {
    int value;
    printf("Masukkan value yang ingin dicari: ");
    scanf("%d", &value);

    address target = Search(*p, value);
    if (target == NULL) {
        printf("Nilai tidak ditemukan!\n");
        return;
    }

    if (target == *p) {
        Del_Awal(p, X);
    } else {
        address prev = *p;
        while (prev->next != target) {
            prev = prev->next;
        }
        Del_After(&prev, X);
    }
}
