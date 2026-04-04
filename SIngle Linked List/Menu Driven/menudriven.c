#include<stdio.h>
#include<stdlib.h>

struct node {
  int data;
  struct node *next;
};

struct node *head = NULL;
struct node *head2 = NULL;

struct node *cn(){
  struct node *k1;
  k1 = (struct node *)malloc(sizeof(struct node));
  printf("Enter data : ");
  scanf("%d",&k1->data);
  k1->next = NULL;
  return k1;
}       

void create(){
  int d,i;
  struct node *temp=NULL,*k1;
  printf("Enter no of nodes:");
  scanf("%d",&d);
  
  for(i=0; i<d; i++){
   k1=cn();
    if(head==NULL){
      head = temp = k1;
    }
    else {
      temp->next = k1;
      temp = k1;
    }
  }
  printf("list created successfully.\n");
}

void traverse(){
  struct node *k;
  printf("the list is: \n");
  if(head==NULL){
    printf("the list is empty.");
    return;
  }
  k=head;
  while(k!=NULL){
    printf("%d ",k->data);
    k = k->next;
  }               
}

void ib(){
  struct node *k1;
  k1 = cn();
  if(head==NULL)
  head = k1;

  else{
    k1->next = head;
    head = k1;
  }
  printf("data inserted at beginning successfully.");
  
}

int length(){
  struct node *k1;
  k1=head;
  int len=0;
  while(k1!=NULL){
    len++;
    k1=k1->next;
  }
  return len;
}

void is(){
  int loc,i=1;
  struct node *k1, *temp;
  printf("enter location:\n");
  scanf("%d",&loc);
  k1=cn();
  if(head==NULL){
    printf("the list is empty.\ndata inserted successfully\n");
    head=k1;
    return;
  }
  if(head!=NULL && loc==1){
    k1->next=head;
    head=k1;
    return;
  }
  if(loc>length()){
    printf("entered position is out of bound.");
    return;
  }
  temp=head;
  for(i=1; i<loc-1; i++){
    temp=temp->next;
  }
  k1->next=temp->next;
  temp->next=k1;
}

void ie(){
  struct node *k1, *temp;
  temp=head;
  k1=cn();
  if(head==NULL){
    head=k1;
    return;
  }
  while(temp->next!=NULL){
    temp=temp->next;
  }
  temp->next=k1;
  printf("data inserted frorm end.\n");
}

void db(){
  struct node *temp;
  temp=head;
  if(head==NULL){
    printf("the list is empty.\n");
    return;
  }
  head=head->next;
  free(temp);
  printf("data deleted from beginning of the node,\n");
}


void ds(){
  struct node *k1,*temp,*prev;
  int loc,i=1;

  if(head==NULL){
    printf("there is no any node to delete.\n");
    return;
  }

  printf("enter loc : ");
  scanf("%d",&loc);

  if(loc>length()){
    printf("entered position is out of bound.");
    return;
  }
  if(loc==1){
    temp = head;
    head=head->next;
    free(temp);
    return;
  }
  temp=head;
  for(i=1; i<loc; i++){
    prev=temp;
    temp=temp->next;
  }
  prev->next=temp->next;
  temp->next=NULL;
  free(temp);
  printf("data deleted from your entered location successfully.\n");
}

void de(){
  struct node *k1,*temp=head;
  if(head==NULL)
  {
    printf("there is no any node to delete");
    return;
  }
  if(head->next==NULL){
    free(head);
    head=NULL;
    return;
  }
  while(temp->next->next!=NULL){
    temp=temp->next;
  }
  k1=temp->next;
  temp->next=NULL;
  free(k1);
  printf("data deleted from end successfully.\n");
}

void sort(){
  struct node *i,*j;
  int temp;
  if(head==NULL){
    printf("list is empty\n");
    return;
  }
  for(i=head; i->next!=NULL; i=i->next)
  {
    for(j=i->next; j!=NULL; j=j->next)
  {
      if(i->data>j->data){
        temp=i->data;
        i->data=j->data;
        j->data=temp;
      }
    }
  }
  printf("data sorted successfully.\n");
}

void search(){
  struct node *temp=head;
  int loc=1,key;
  if(head==NULL){
    printf("the list is empty.\n");
    return;
  }

  printf("enter key:\n");
  scanf("%d",&key);
  while(temp != NULL){
    if(temp->data == key){
      printf("data is present at location %d\n", loc);
      return;
    }
    temp = temp->next;
    loc++;
  }

  printf("data not found.\n");
}


void create2(){
  int d,i;
  struct node *temp=NULL,*k1;

  printf("enter no of nodes for second list:");
  scanf("%d",&d);

  for(i=0; i<d; i++){
    k1 = cn();
    if(head2 == NULL){
      head2 = temp = k1;
    } else {
      temp->next = k1;
      temp = k1;
    }
  }
}

void merge(){
  struct node *temp;

  printf("create second list:\n");
  create2();

  if(head == NULL){
    head = head2;
    printf("list merged successfully.\n");
    return;
  }

  temp = head;
  while(temp->next != NULL){
    temp = temp->next;
  }

  temp->next = head2;
  printf("list merged successfully.\n");
}

void reverse(){
  struct node *prev = NULL;
  struct node *curr = head;
  struct node *next = NULL;
  if(head==NULL){
    printf("the list is empty.\n");
    return;
  }
  while(curr!=NULL){
    next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  head=prev;
  printf("list reversed successfully."); 
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
        printf("\n9. Sort");
        printf("\n10. Search");
        printf("\n11. Merge");
        printf("\n12. Reverse");
        printf("\n13. Exit");
        while (1) {
        printf("\nEnter your choice: ");
        scanf("%d", &d);

        switch (d) {
            case 1: create(); break;
            case 2: traverse(); break;
            case 3: ib(); break;
            case 4: is(); break;
            case 5: ie(); break;
            case 6: db(); break;
            case 7: ds(); break;
            case 8: de(); break;
            case 9: sort(); break;
            case 10: search(); break;
            case 11: merge(); break;
            case 12: reverse(); break;
            case 13:
            printf("Exiting program.\n");
            exit(0);
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}
