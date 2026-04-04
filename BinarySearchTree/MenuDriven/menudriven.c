#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node *root = NULL;

struct node* createNode(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));

    if(newnode == NULL){
        printf("Memory allocation failed\n");
        return NULL;
    }

    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;

    return newnode;
}

struct node* insert(struct node *root, int value){

    if(root == NULL)
        return createNode(value);

    if(value < root->data)
        root->left = insert(root->left, value);

    else if(value > root->data)
        root->right = insert(root->right, value);

    return root;
}

struct node* search(struct node *root, int key){

    if(root == NULL || root->data == key)
        return root;

    if(key < root->data)
        return search(root->left, key);

    else
        return search(root->right, key);
}

struct node* findMin(struct node* root){

    while(root->left != NULL)
        root = root->left;

    return root;
}

struct node* findMax(struct node* root){

    while(root->right != NULL)
        root = root->right;

    return root;
}

struct node* deleteNode(struct node* root, int key){
  
    if(root == NULL)
        return root;

    if(key < root->data)
        root->left = deleteNode(root->left, key);

    else if(key > root->data)
        root->right = deleteNode(root->right, key);

    else{

        if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = findMin(root->right);

        root->data = temp->data;

        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

void preorder(struct node* root){

    if(root == NULL)
        return;

    printf("%d ", root->data);

    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root){

    if(root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);

    printf("%d ", root->data);
}
void inorder(struct node* root){

    if(root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main(){

    int choice, value, key;

    printf("---Binary Search Tree---\n");
    printf("1.Insert\n");
    printf("2.Delete\n");
    printf("3.Search\n");
    printf("4.FindMax\n");
    printf("5.FindMin\n");
    printf("6.PreOrder Traversal\n");
    printf("7.InOrder Traversal\n");
    printf("8.PostOrder Traversal\n");
    printf("9.Exit\n");

    while(1){

        printf("\nEnter choice: ");
        scanf("%d",&choice);

        switch(choice){

            case 1:

                printf("Enter data: ");
                scanf("%d",&value);

                root = insert(root,value);

                break;

            case 2:

                printf("Enter data to delete: ");
                scanf("%d",&value);

                root = deleteNode(root,value);

                break;

            case 3:

                printf("Enter element to search: ");
                scanf("%d",&key);

                if(search(root,key) != NULL)
                    printf("Element found\n");
                else
                    printf("Element not found\n");

                break;

            case 4:

                if(root != NULL)
                    printf("Max element: %d\n", findMax(root)->data);
                else
                    printf("Tree is empty\n");

                break;

            case 5:

                if(root != NULL)
                    printf("Min element: %d\n", findMin(root)->data);
                else
                    printf("Tree is empty\n");

                break;

            case 6:

                printf("PreOrder Traversal: ");
                preorder(root);
                printf("\n");

                break;

            case 7:

                printf("InOrder Traversal: ");
                inorder(root);
                printf("\n");

                break;

            case 8:

                printf("PostOrder Traversal: ");
                postorder(root);
                printf("\n");

                break;

            case 9 :
                printf("Exiting...\n");
                exit(0);   

            default:
                printf("Invalid choice\n");
        }
    }
}