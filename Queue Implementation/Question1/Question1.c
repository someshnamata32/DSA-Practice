#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int rear = -1;
int front = -1;

void enqueue() {
    int d;
    printf("Enter data: ");
    scanf("%d", &d);
    if (rear == MAX - 1) {
        printf("Overflow\n");
    } else if (front == -1 && rear == -1) {
        front = rear = 0;
        queue[rear] = d;
    } else {
        rear++;
        queue[rear] = d;
    }
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Underflow\n");
    } else {
        printf("Deleted: %d\n", queue[front]);
        front++;
    }
}

void size() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Size: %d\n", rear - front + 1);
    }
}

void traverse() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
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