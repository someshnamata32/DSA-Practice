#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int stack[MAX];
int top = -1;

void push() {
    int data;
    if (top == MAX - 1) {
        printf("\nStack is Full");
        return;
    }
    printf("\nEnter element: ");
    scanf("%d", &data);
    stack[++top] = data;
    printf("\nElement pushed successfully");
}

void pop() {
    if (top == -1) {
        printf("\nStack is Empty");
        return;
    }
    printf("\nDeleted element: %d", stack[top--]);
}

void traverse() {
    if (top == -1) {
        printf("\nStack is Empty");
        return;
    }
    printf("\nStack elements:\n");
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }
}

void isEmpty() {
    if (top == -1)
        printf("\nStack is Empty");
    else
        printf("\nStack is Not Empty");
}

void isFull() {
    if (top == MAX - 1)
        printf("\nStack is Full");
    else
        printf("\nStack is Not Full");
}

void peek() {
    if (top == -1) {
        printf("\nStack is Empty");
        return;
    }
    printf("\nTop element: %d", stack[top]);
}

int main() {
    int choice;

    while (1) {
        printf("\n\n--- STACK MENU ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Traverse");
        printf("\n4. Check Empty");
        printf("\n5. Check Full");
        printf("\n6. Peek");
        printf("\n7. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: traverse(); break;
            case 4: isEmpty(); break;
            case 5: isFull(); break;
            case 6: peek(); break;
            case 7: exit(0);
            default: printf("\nInvalid choice");
        }
    }

    return 0;
}