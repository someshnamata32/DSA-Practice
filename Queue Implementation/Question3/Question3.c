#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int queue[MAX];
int front = -1;
int rear = -1;

void enqueue()
{
    int d;

    if ((rear + 1) % MAX == front)
    {
        printf("Queue is full\n");
        return;
    }

    printf("Enter data: ");
    scanf("%d", &d);

    if (front == -1)
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % MAX;
    }

    queue[rear] = d;
}

void dequeue()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Deleted: %d\n", queue[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % MAX;
    }
}

void size()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
    }
    else
    {
        int count = (rear - front + MAX) % MAX + 1;
        printf("Size: %d\n", count);
    }
}

void traverse()
{
    if (front == -1)
    {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");

    int temp = front;

    while (temp != rear)
    {
        printf("%d ", queue[temp]);
        temp = (temp + 1) % MAX;
    }

    printf("%d\n", queue[rear]);
}

int main()
{
    int choice;

    printf("\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Size\n");
    printf("4. Traverse\n");
    printf("5. Exit\n");

    while (1)
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                enqueue();
                break;

            case 2:
                dequeue();
                break;

            case 3:
                size();
                break;

            case 4:
                traverse();
                break;

            case 5:
                printf("Program exited.\n");
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}