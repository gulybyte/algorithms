#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

int* selectSort(int list[], int listSize);
int findSmallIndex(int list[], int listSize);
void printArray(int list[], int listSize);

int main() {

    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Ordena e obtém o array ordenado
    int* sortedArr = selectSort(arr, n);

    printf("Array ordenado: \n");
    printArray(sortedArr, n);

    free(sortedArr); // Libera a memória alocada

    return 0;

}

int* selectSort(int list[], int listSize) {
    int* newList = malloc(listSize * sizeof(int));;
    for (int i = 0; i < listSize; i++) {
        int smallIndex = findSmallIndex(list, listSize - i);
        newList[i] = list[smallIndex];
    }

    return newList;
}

int findSmallIndex(int list[], int listSize) {
    int small = list[0];
    int smallIndex = 0;

    for (int i = 1; i < listSize; i++) {
        if(list[i] < small) {
            small = list[i];
            smallIndex = i;
        }
    }

    return smallIndex;
}

void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
