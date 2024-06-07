#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 20

char* selectSort(int list[], int listSize, int value);
char* intToString(int number);

int main() {


    return 0;

}

char* selectSort() {

    

    return "NOT FOUND";
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
