#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

struct node* createNode(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next = NULL;
    return newnode;
}

void create(){
    int n,i;
    printf("How many nodes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        struct node *newnode = createNode();

        if(head==NULL){
            head = newnode;
            head->next = head;
        }
        else{
            struct node *temp = head;
            while(temp->next != head)
                temp = temp->next;

            temp->next = newnode;
            newnode->next = head;
        }
    }
}

void insertBeginning(){
    struct node *newnode = createNode();

    if(head==NULL){
        head = newnode;
        head->next = head;
    }
    else{
        struct node *temp = head;
        while(temp->next != head)
            temp = temp->next;

        newnode->next = head;
        temp->next = newnode;
        head = newnode;
    }
}

void insertEnd(){
    struct node *newnode = createNode();

    if(head==NULL){
        head = newnode;
        head->next = head;
    }
    else{
        struct node *temp = head;
        while(temp->next != head)
            temp = temp->next;

        temp->next = newnode;
        newnode->next = head;
    }
}

void insertPosition(){
    int pos,i;
    printf("Enter position: ");
    scanf("%d",&pos);

    if(head==NULL || pos<=1){
        insertBeginning();
        return;
    }

    struct node *newnode = createNode();
    struct node *temp = head;

    for(i=1; i<pos-1; i++){
        if(temp->next == head){
            printf("Invalid position\n");
            free(newnode);
            return;
        }
        temp = temp->next;
    }

    newnode->next = temp->next;
    temp->next = newnode;
}

void deleteBeginning(){
    if(head==NULL){
        printf("List empty\n");
        return;
    }

    if(head->next == head){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp = head;
        while(temp->next != head)
            temp = temp->next;

        struct node *del = head;
        head = head->next;
        temp->next = head;
        free(del);
    }
}

void deleteEnd(){
    if(head==NULL){
        printf("List empty\n");
        return;
    }

    if(head->next == head){
        free(head);
        head = NULL;
    }
    else{
        struct node *temp = head;
        while(temp->next->next != head)
            temp = temp->next;

        struct node *del = temp->next;
        temp->next = head;
        free(del);
    }
}

void deletePosition()
{
    int pos, i;
    printf("Enter position: ");
    scanf("%d", &pos);

    if(head == NULL)
    {
        printf("List empty\n");
        return;
    }

    if(pos == 1)
    {
        deleteBeginning();
        return;
    }

    struct node *temp = head;

    for(i = 1; i < pos - 1; i++)
    {
        if(temp->next == head)
        {
            printf("Invalid position\n");
            return;
        }
        temp = temp->next;
    }

    if(temp->next == head)
    {
        printf("Invalid position\n");
        return;
    }

    struct node *del = temp->next;
    temp->next = del->next;
    free(del);

    printf("Node deleted successfully\n");
}


void display(){
    if(head==NULL){
        printf("List empty\n");
        return;
    }

    struct node *temp = head;
    do{
        printf("%d ",temp->data);
        temp = temp->next;
    }while(temp != head);

    printf("\n");
}

int main(){
    int ch;

   
        printf("\n1.Create");
        printf("\n2.Insert Beginning");
        printf("\n3.Insert End");
        printf("\n4.Insert Position");
        printf("\n5.Delete Beginning");
        printf("\n6.Delete End");
        printf("\n7.Delete Position");
        printf("\n8.Display");
        printf("\n9.Exit");
         while(1){
        printf("\nEnter choice: ");
        scanf("%d",&ch);

        switch(ch){
            case 1: create(); break;
            case 2: insertBeginning(); break;
            case 3: insertEnd(); break;
            case 4: insertPosition(); break;
            case 5: deleteBeginning(); break;
            case 6: deleteEnd(); break;
            case 7: deletePosition(); break;
            case 8: display(); break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
