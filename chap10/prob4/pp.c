#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node **top, int data);
int pop(struct node **top);
void printStack(struct node *top);

int main() {
    struct node *top = NULL;
    int value;

    while (1) {
        if (scanf("%d", &value) == 1) {
            push(&top, value);
        } 
	else {
            printf("Print stack\n");
            break;
        }
    }

    printStack(top);
    printf("\n");

    return 0;
}

void push(struct node **top, int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (!newNode) {
        exit(EXIT_FAILURE);
    }

    newNode->data = data;
    newNode->next = *top;
    *top = newNode;
}

int pop(struct node **top) {
    if (*top == NULL) {
        printf("Stack is empty\n");
        exit(EXIT_FAILURE);
    }

    struct node *temp = *top;
    int popValue = temp->data;
    *top = temp->next;
    free(temp);

    return popValue;
}

void printStack(struct node *top) {
    if (top == NULL) {
        printf("Stack is empty.\n");
        return;
    }

    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }

    printf("\n");
}

