#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* front = NULL;
struct Node* rear = NULL;

void enqueue() {
    int d;
    printf("Enter data: ");
    scanf("%d", &d);

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = d;
    newNode->next = NULL;

    if (front == NULL && rear == NULL) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
}

void dequeue() {
    if (front == NULL) {
        printf("Underflow\n");
        return;
    } else {
        struct Node* temp = front;
        printf("Deleted: %d\n", temp->data);
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }
        free(temp);
    }
}

void size() {
    int count = 0;
    struct Node* temp = front;
    while (temp != NULL) {
        count++;
        temp = temp->next;
    }
    printf("Size: %d\n", count);
}

void traverse() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main() {
    int choice;
    
        printf("\n1. Enqueue\n2. Dequeue\n3. Size\n4. Traverse\n5. Exit\n");
        while(1){
	printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: size(); break;
            case 4: traverse(); break;
            case 5: printf("Program exited.\n"); exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}