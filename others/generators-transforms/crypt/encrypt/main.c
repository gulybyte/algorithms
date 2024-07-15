#include <stdio.h>
#include <stdlib.h>

void main() {
    int arrMutable[] = {42, 7, 33, 81};

    arrMutable[4] = 35;

    printf("\nValue of indice 4: %d", arrMutable[4]);

}
