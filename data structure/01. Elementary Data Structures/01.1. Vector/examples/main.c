#include <stdio.h>
#include <stdlib.h>

void main() {

    int dynamicMutableVector[] = {42, 7, 33, 81};
    int size = sizeof(dynamicMutableVector) / sizeof(dynamicMutableVector[0]);

    printf("\nValue of indice 0: %d", dynamicMutableVector[0]);
    printf("\nSize: %d", size);

    dynamicMutableVector[0] = 35;
    dynamicMutableVector[4] = 27;
    dynamicMutableVector[42] = 402;

    int newSize = sizeof(dynamicMutableVector) / sizeof(dynamicMutableVector[0]);

    printf("\nValue of indice 0: %d", dynamicMutableVector[0]);
    printf("\nValue of indice 4: %d", dynamicMutableVector[4]);
    printf("\nValue of indice 42: %d", dynamicMutableVector[42]);
    printf("\nValue of indice 100: %d", dynamicMutableVector[100]);
    printf("\nNew size: %d", newSize);

    int arr[2];
    for (size_t i = 0; i < 50; i++){
        arr[i] = i;
    }

    arr[420] = 68;
    printf("\nValue of indice 420: %d", arr[420]);

    for (size_t i = 0; i < 5000; i++){
        printf("\n%d", arr[i]);
    }


}
