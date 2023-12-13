#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

void addq(struct node **head, struct node **tail, int data);
int delete(struct node **head, struct node **tail);;
void printQueue(struct node *head);

int main() {
	struct node *head = NULL;
	struct node *tail = NULL;

	int value;
	int c;

	while(1) {
		if (scanf("%d", &value) == 1) {
			addq(&head, &tail, value);
		}
		else {
			printf("Print queue\n");

			while ((c = getchar()) != '\n' && c != EOF);
			break;
		}
	}
	printQueue(head);;

	return 0;
}

void addq(struct node **head, struct node **tail, int data) {
	struct node* temp = (struct node *)malloc(sizeof(struct node));
	temp->data = data;
	temp->next = NULL;

	if(*tail == NULL) {
		*head = *tail = temp;
	}
	else {
		(*tail)->next = temp;
		*tail = temp;
	}
}

void printQueue(struct node *head) {
	if (head == NULL) {
		printf("Queue is empty\n");
		return;
	}
	while (head != NULL) {
		printf("%d\n", head->data);
		head = head->next;
	}
}

