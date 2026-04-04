#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL,*tail=NULL;

struct node* cn(){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next = newnode;
    newnode->prev = newnode;
    return newnode;
}

void create(){
    int n,i;
    printf("How many nodes you want to create: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        struct node *newnode = cn();
        if(head==NULL){
            head = tail = newnode;
        }else{
            newnode->prev = tail;
            newnode->next = head;
            tail->next = newnode;
            head->prev = newnode;
            tail = newnode;
        }
    }
}

void ib(){
    struct node *n = cn();
    if(head==NULL){
        head=tail=n;
    }else{
        n->next=head;
        n->prev=tail;
        head->prev=n;
        tail->next=n;
        head=n;
    }
}

void ie(){
    struct node *n = cn();
    if(head==NULL){
        head=tail=n;
    }else{
        n->prev=tail;
        n->next=head;
        tail->next=n;
        head->prev=n;
        tail=n;
    }
}

void is(){
    int pos,i;
    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos<=1){
        ib();
        return;
    }

    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    struct node *temp=head;

    for(i=1;i<pos-1;i++){
        if(temp->next==head)
            break;
        temp=temp->next;
    }

    if(temp->next==head){
        ie();
        return;
    }

    struct node *n = cn();

    n->next=temp->next;
    n->prev=temp;
    temp->next->prev=n;
    temp->next=n;
}

void db(){
    if(head==NULL){
        printf("List empty\n");
        return;
    }

    if(head==tail){
        free(head);
        head=tail=NULL;
    }else{
        struct node *temp=head;
        head=head->next;
        head->prev=tail;
        tail->next=head;
        free(temp);
    }
}

void de(){
    if(head==NULL){
        printf("List empty\n");
        return;
    }

    if(head==tail){
        free(head);
        head=tail=NULL;
    }else{
        struct node *temp=tail;
        tail=tail->prev;
        tail->next=head;
        head->prev=tail;
        free(temp);
    }
}

void ds(){
    int pos,i;
    printf("Enter position: ");
    scanf("%d",&pos);

    if(head==NULL){
        printf("List empty\n");
        return;
    }

    if(pos<=1){
        db();
        return;
    }

    struct node *temp=head;

    for(i=1;i<pos;i++){
        if(temp->next==head){
            printf("Invalid position\n");
            return;
        }
        temp=temp->next;
    }

    if(temp==tail){
        de();
        return;
    }

    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}

void display(){
    if(head==NULL){
        printf("List empty\n");
        return;
    }

    struct node *temp=head;

    do{
        printf("%d ",temp->data);
        temp=temp->next;
    }while(temp!=head);

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
            case 2: ib(); break;
            case 3: ie(); break;
            case 4: is(); break;
            case 5: db(); break;
            case 6: de(); break;
            case 7: ds(); break;
            case 8: display(); break;
            case 9: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}
