#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 64
#define MAX_BG_JOBS 10

void execute_command(char *command, int background) {
    pid_t pid = fork();

    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {

        char *args[MAX_ARG_SIZE];
        int i = 0;
        char *token = strtok(command, " ");

        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;


        execvp(args[0], args);


        perror("execvp");
        exit(EXIT_FAILURE);
    } 
}

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("[Shell] ");
        fgets(input, sizeof(input), stdin);


        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }


        if (strcmp(input, "exit") == 0) {
            break;
        }


        int background = 0;
        if (input[len - 1] == '&') {
            background = 1;
            input[len - 1] = '\0'; 
        }

        execute_command(input, background);
    }

    return 0;
}

