#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

char* binarySearch(int list[], int listSize, int value);
void testBinarySearch();
char* intToString(int number);
void metadataBinarySearch(int list[], int listSize, int val, char* response);

int main() {

    testBinarySearch();

    return 0;

}

char* binarySearch(int list[], int listSize, int value) {

    int low = 0;
    int high = listSize - 1;
    int mid, try;

    while (low <= high) {
        mid = (low + high) / 2;
        try = list[mid];

        if(try == value)
            return intToString(mid);
        else if (try > value)
            high = mid - 1;
        else
            low = mid + 1;
    }


    return "NOT FOUND";
}

void testBinarySearch() {
    int list[] = {-80, -42, 0, 2, 3, 5, 7, 11, 41, 57, 70}; // it's necessary to be orderly
    int listSize = sizeof(list) / sizeof(list[0]);

    int values[] = {7, 42, 80, 1, 0, 70, -1, -42, -80, -81}; // numbers to test
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; i++) {
        char* result = binarySearch(list, listSize, values[i]);
        metadataBinarySearch(list, listSize, values[i], result);
    }
}


/* UTILS */

char* intToString(int number) {
    char* str = malloc(sizeof(char) * MAX_LENGTH);
    if (str == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    snprintf(str, MAX_LENGTH, "%d", number);
    return str;
}


void metadataBinarySearch(int list[], int listSize, int val, char* response) {
    printf("\n__________________________________________________________\nThe elements of the array are: ");
    for (int i = 0; i < listSize; i++)
        printf("%d ", list[i]);
        printf("\nElement to be searched is: %d", val);
    if (strcmp(response, "NOT FOUND") == 0)
        printf("\nElement is not present in the array");
    else
        printf("\nElement is present at %s position of array", response);
}

