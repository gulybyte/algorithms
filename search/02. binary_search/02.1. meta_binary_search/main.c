#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

char* binarySearch(int list[], int listSize, int value);
void testBinarySearch();
int log2_floor(int a);
char* intToString(int number);
void metadataBinarySearch(int list[], int listSize, int val, char* response);

int main() {

    testBinarySearch();

    return 0;

}

char* binarySearch(int list[], int listSize, int value) {

    int lg = log2_floor(listSize - 1) + 1;

    int pos = 0;
    for(int i = lg - 1; i >= 0; i--) {
        if(list[pos] == value)
            return intToString(pos);
        int new_pos = pos | (1 << i);
        if((new_pos < listSize) && (list[new_pos] <= value))
            pos = new_pos;
    }

    return ((list[pos] == value) ? intToString(pos) : "NOT FOUND");

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

int log2_floor(int a) {
    int lg = -1;
    while (a > 0) {
        a >>= 1;
        lg++;
    }
    return lg;
}

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

