#include <stdio.h>
#include <stdlib.h>

void main() {

    const int arrImutable[] = {42, 7, 33, 81};

    printf("\nValue of indice 0: %d", arrImutable[0]);

    /* Impossible operation */
    // arrImutable[0] = 32;

    int arrMutable[] = {42, 7, 33, 81};

    printf("\nValue of indice 0: %d", arrMutable[0]);

    arrMutable[0] = 35;

    printf("\nValue of indice 0: %d", arrMutable[0]);

}