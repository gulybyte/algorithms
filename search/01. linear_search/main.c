#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

char* linearSearch(int list[], int listSize, int value);
void testLinearSearch();
char* intToString(int number);
void metadataLinearSearch(int list[], int listSize, int val, char* response);

int main() {

    testLinearSearch();

    return 0;

}

char* linearSearch(int list[], int listSize, int value) {

    int i;
    for(i = 0; i < listSize; i++) {
        if(list[i] == value) {
            return intToString(i);
        }
    }

    return "NOT FOUND";
}

void testLinearSearch() {
    int list[] = {11, 7, 41, 3, 2, -80, 5, 0, 70, -42, 57};
    int listSize = sizeof(list) / sizeof(list[0]);

    int values[] = {7, 42, 80, 1, 0, 70, -1, -42, -80, -81}; // numbers to test
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; i++) {
        char* result = linearSearch(list, listSize, values[i]);
        metadataLinearSearch(list, listSize, values[i], result);
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


void metadataLinearSearch(int list[], int listSize, int val, char* response) {
    printf("\n__________________________________________________________\nThe elements of the array are: ");
    for (int i = 0; i < listSize; i++)
        printf("%d ", list[i]);
        printf("\nElement to be searched is: %d", val);
    if (strcmp(response, "NOT FOUND") == 0)
        printf("\nElement is not present in the array");
    else
        printf("\nElement is present at %s position of array", response);
}

