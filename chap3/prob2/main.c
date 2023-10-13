#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "copy.h"

#define MAX_LINES 100

int compare_strings(const void *a, const void *b) {
    return strlen(*(char **)b) - strlen(*(char **)a);
}

int main() {
    char *lines[MAX_LINES];
    char buffer[MAXLINE];
    int num_lines = 0;

    

    
    while (num_lines < MAX_LINES && fgets(buffer, MAXLINE, stdin) != NULL) {
        lines[num_lines] = malloc(strlen(buffer) + 1);
        copy(buffer, lines[num_lines]);
        num_lines++;
    }

    
    qsort(lines, num_lines, sizeof(char *), compare_strings);

    
    
    for (int i = 0; i < num_lines; i++) {
        printf("%s", lines[i]);
        free(lines[i]);  
    }

    return 0;
}

