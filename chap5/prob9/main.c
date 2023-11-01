#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    FILE *fp;
    char line[100];
    char lines[100][100]; 
    int totalLines = 0;
    
    fp = fopen("test.txt", "r");

    if(fp == NULL) {
	    perror("Error");
	    return 1;
    }
    
    while (fgets(line, sizeof(line), fp) != NULL) {
        strcpy(lines[totalLines], line);
        totalLines++;
    }
    
    for (int i = totalLines - 1; i >= 0; i--) {
        printf("%s", lines[i]);
    }

    fclose(fp);

    return 0;
}

