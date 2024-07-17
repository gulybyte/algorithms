#include <stdio.h>
#include <stdlib.h>

void main() {

    int dynamicMutableVector[] = {42, 7, 33, 81};

    printf("\nValue of indice 0: %d", dynamicMutableVector[0]);

    dynamicMutableVector[0] = 35;
    dynamicMutableVector[4] = 27;
    dynamicMutableVector[42] = 402;

    printf("\nValue of indice 0: %d", dynamicMutableVector[0]);
    printf("\nValue of indice 4: %d", dynamicMutableVector[4]);
    printf("\nValue of indice 42: %d", dynamicMutableVector[42]);

}
