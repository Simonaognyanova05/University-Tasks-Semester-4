#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;           
    struct node* next;  
};

int main() {
    struct node* head = NULL, * temp = NULL, * newNode = NULL;
    int n, i, value;

    printf("Input the number of nodes: ");
    if (scanf_s("%d", &n) != 1 || n <= 0) {
        printf("Invalid number of nodes.\n");
        return 1;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct node*)malloc(sizeof(struct node));
        if (newNode == NULL) {
            printf("Memory allocation failed!\n");
            return 1;
        }

        printf("Input data for node %d: ", i);
        scanf_s("%d", &value);

        newNode->data = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
            temp = newNode;
        }
        else {
            temp->next = newNode;
            temp = newNode;
        }
    }

    printf("\nData entered in the list:\n");
    temp = head; 
    while (temp != NULL) {
        printf("Data = %d\n", temp->data);
        temp = temp->next; 
    }

    temp = head;
    struct node* nextNode;
    while (temp != NULL) {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    return 0;
}