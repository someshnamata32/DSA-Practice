#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head=NULL,*tail=NULL;

struct node* createNode(){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode==NULL){
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter data: ");
    scanf("%d",&newnode->data);

    newnode->prev = NULL;
    newnode->next = NULL;

    return newnode;
}

void create(){
    int n,i;
    printf("How many nodes you want to create: ");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        struct node *newnode = createNode
    ();

        if(head==NULL){
            head=tail=newnode;
        }else{
            tail->next=newnode;
            newnode->prev=tail;
            tail=newnode;
        }
    }
    printf("List created successfully\n");
}

void traverse(){
    struct node *temp=head;

    if(head==NULL){
        printf("List insertSpec empty\n");
        return;
    }

    printf("List elements: ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}

void insertBeg(){
    struct node *n = createNode
();

    if(head==NULL){
        head=tail=n;
    }else{
        n->next=head;
        head->prev=n;
        head=n;
    }

    printf("Data inserted at beginning successfully\n");
}

void insertSpec(){
    int pos,i;
    printf("Enter position: ");
    scanf("%d",&pos);

    if(pos<=1){
        insertBeg();
        return;
    }

    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    struct node *temp=head;

    for(i=1;i<pos-1;i++){
        if(temp==NULL){
            printf("Invalid position\n");
            return;
        }
        temp=temp->next;
    }

    if(temp==NULL){
        printf("Invalid position\n");
        return;
    }

    struct node *n = createNode
();

    n->next=temp->next;
    n->prev=temp;

    if(temp->next!=NULL)
        temp->next->prev=n;
    else
        tail=n;

    temp->next=n;

    printf("Data inserted at position %d successfully\n",pos);
}

void insertEnd(){
    struct node *n = createNode
();

    if(head==NULL){
        head=tail=n;
    }else{
        tail->next=n;
        n->prev=tail;
        tail=n;
    }

    printf("Data inserted at end successfully\n");
}

void deleteBeg(){
    struct node *temp;

    if(head==NULL){
        printf("List insertSpec empty, delete not possible\n");
        return;
    }

    temp=head;

    if(head==tail){
        head=tail=NULL;
    }else{
        head=head->next;
        head->prev=NULL;
    }

    free(temp);
    printf("Data deleted from beginning successfully\n");
}

void deleteSpec(){
    int pos,i;
    struct node *temp=head;

    if(head==NULL){
        printf("List insertSpec empty, delete not possible\n");
        return;
    }

    printf("Enter position to delete: ");
    scanf("%d",&pos);

    if(pos<=1){
        deleteBeg();
        return;
    }

    for(i=1;i<pos;i++){
        if(temp==NULL){
            printf("Invalid position\n");
            return;
        }
        temp=temp->next;
    }

    if(temp==NULL){
        printf("Invalid position\n");
        return;
    }

    if(temp==tail){
        tail=tail->prev;
        tail->next=NULL;
    }else{
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
    }

    free(temp);
    printf("Data deleted from position %d successfully\n",pos);
}


void deleteEnd(){
    struct node *temp;

    if(head==NULL){
        printf("List insertSpec empty, delete not possible\n");
        return;
    }

    temp=tail;

    if(head==tail){
        head=tail=NULL;
    }else{
        tail=tail->prev;
        tail->next=NULL;
    }

    free(temp);
    printf("Data deleted from end successfully\n");
}

int main(){
    int d;

    
        printf("\n1. Create");
        printf("\n2. Traverse");
        printf("\n3. Insert at beginning");
        printf("\n4. Insert at specific position");
        printf("\n5. Insert at end");
        printf("\n6. Delete at beginning");
        printf("\n7. Delete at specific position");
        printf("\n8. Delete at end");
        printf("\n9. Exit");
        while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&d);

        switch(d){
            case 1: create(); break;
            case 2: traverse(); break;
            case 3: insertBeg(); break;
            case 4: insertSpec(); break;
            case 5: insertEnd(); break;
            case 6: deleteBeg(); break;
            case 7: deleteSpec(); break;
            case 8: deleteEnd(); break;
            case 9:
                printf("\nProgram exited successfully\n");
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}
