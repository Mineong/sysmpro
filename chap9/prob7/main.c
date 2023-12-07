#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024

void execute_command(char *command) {
    // 자식 프로세스를 생성하여 명령어 실행
    pid_t pid = fork();
    
    if (pid == -1) {
        perror("fork");
        exit(EXIT_FAILURE);
    } else if (pid == 0) {
        // 자식 프로세스
        char *args[MAX_INPUT_SIZE];
        int i = 0;
        char *token = strtok(command, " ");

        while (token != NULL) {
            args[i++] = token;
            token = strtok(NULL, " ");
        }

        args[i] = NULL;
        
        // 명령어 실행
        execvp(args[0], args);

        // execvp가 실패하면 아래 코드가 실행됨
        perror("execvp");
        exit(EXIT_FAILURE);
    } else {
        // 부모 프로세스
        wait(NULL); // 자식 프로세스의 종료를 기다림
    }
}

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        printf("[shell] ");
        fgets(input, sizeof(input), stdin);

        // 개행 문자 제거
        size_t len = strlen(input);
        if (len > 0 && input[len - 1] == '\n') {
            input[len - 1] = '\0';
        }

        // 종료 조건
        if (strcmp(input, "exit") == 0) {
            break;
        }

        // 명령어 실행
        execute_command(input);
    }

    return 0;
}

