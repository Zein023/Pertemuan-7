#include <stdio.h>
#include <stdlib.h>
#include "linked.h"
#include "stack.h"
#include "boolean.h"

int main (){
	int number;
    
    printf("Masukkan bilangan desimal: ");
    scanf("%d", &number);

    if (number < 0) {
        printf("Bilangan harus positif!\n");
    } else if (number == 0) {
        printf("Hasil konversi biner: 0\n");
    } else {
        convertToBinary(number);
    }

    return 0;
}
