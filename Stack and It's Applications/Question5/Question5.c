#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;

void push() {
    struct node *newnode;
    int value;

    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL) {
        printf("\nStack Overflow");
        return;
    }

    printf("\nEnter element: ");
    scanf("%d", &value);

    newnode->data = value;
    newnode->next = top;
    top = newnode;

    printf("\nElement pushed successfully");
}

void pop() {
    struct node *temp;

    if(top == NULL) {
        printf("\nStack is Empty");
        return;
    }

    temp = top;
    printf("\nDeleted element: %d", top->data);
    top = top->next;
    free(temp);
}

void traverse() {
    struct node *temp;

    if(top == NULL) {
        printf("\nStack is Empty");
        return;
    }

    temp = top;
    printf("\nStack elements: ");

    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main() {
    int choice;

    
        printf("\n\n--- STACK USING LINKED LIST ---");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Traverse");
        printf("\n4. Exit");
        while(1) {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: traverse(); break;
            case 4: exit(0);
            default: printf("\nInvalid Choice");
        }
    }

    return 0;
}
