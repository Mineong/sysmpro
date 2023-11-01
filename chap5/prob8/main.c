#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

    char savedText[10][100];
    int fd, saveText, lineCount = 0, lineNumber;
    char buf;

    fd = open("test.txt", O_RDONLY);


    while ((saveText = read(fd, &buf, 1)) > 0) {
        if (buf != '\n') {
            savedText[lineCount][lineNumber++] = buf;
        } 
	else {
            savedText[lineCount][lineNumber] = '\0'; 
            lineCount++;
            lineNumber = 0;
        }
    }

    close(fd);

    printf("File read success.\n");
    printf("Total lines: %d\n", lineCount);
    
    printf("You can choose 1~%d Line\n", lineCount);
    printf("Pls 'Enter' the line to select: ");
    scanf("%d", &lineNumber);

    
    if (lineNumber >= 1 && lineNumber <= lineCount) {
        printf("%s\n", savedText[lineNumber - 1]);
    } 

    return 0;
}


