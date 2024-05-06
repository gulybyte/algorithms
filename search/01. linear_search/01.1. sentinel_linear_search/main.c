#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

char* sentinelLinearSearch(int list[], int listSize, int value);
void testSentinelLinearSearch();
char* intToString(int number);
void metadataSentinelLinearSearch(int list[], int listSize, int val, char* response);

int main() {

    testSentinelLinearSearch();

    return 0;

}

char* sentinelLinearSearch(int list[], int listSize, int value) {

    int last = list[listSize - 1];

    list[listSize - 1] = value; // sentinel value
    int i = 0;

    while(list[i] != value)
        i++;
    
    list[listSize - 1] = last;

    if((i < (listSize - 1)) || (list[listSize - 1] == value))
        return intToString(i);
    else
        return "NOT FOUND";

}

void testSentinelLinearSearch() {
    int list[] = {11, 7, 41, 3, 2, -80, 5, 0, 70, -42, 57};
    int listSize = sizeof(list) / sizeof(list[0]);

    int values[] = {7, 42, 80, 1, 0, 70, -1, -42, -80, -81, 57}; // numbers to test
    int numValues = sizeof(values) / sizeof(values[0]);

    for (int i = 0; i < numValues; i++) {
        char* result = sentinelLinearSearch(list, listSize, values[i]);
        metadataSentinelLinearSearch(list, listSize, values[i], result);
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


void metadataSentinelLinearSearch(int list[], int listSize, int val, char* response) {
    printf("\n__________________________________________________________\nThe elements of the array are: ");
    for (int i = 0; i < listSize; i++)
        printf("%d ", list[i]);
        printf("\nElement to be searched is: %d", val);
    if (strcmp(response, "NOT FOUND") == 0)
        printf("\nElement is not present in the array");
    else
        printf("\nElement is present at %s position of array", response);
}

