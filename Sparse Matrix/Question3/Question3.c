#include<stdio.h>

void inputTriplet(int t[20][3], int nz);
void tripletToSparse(int t[20][3], int a[20][20]);
void transpose(int a[20][20], int tr[20][20], int r, int c);
void display(int a[20][20], int r, int c);

int main()
{
    int triplet[20][3];
    int sparse[20][20], trans[20][20];
    int nz, r, c;

    printf("Enter number of non-zero elements: ");
    scanf("%d",&nz);

    printf("Enter triplet matrix:\n");
    inputTriplet(triplet, nz);

    r = triplet[0][0];
    c = triplet[0][1];

    tripletToSparse(triplet, sparse);

    printf("\nOriginal Sparse Matrix:\n");
    display(sparse, r, c);

    transpose(sparse, trans, r, c);

    printf("\nTranspose of Sparse Matrix:\n");
    display(trans, c, r);

    return 0;
}

void inputTriplet(int t[20][3], int nz)
{
    int i,j;
    for(i=0;i<=nz;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&t[i][j]);
        }
    }
}

void tripletToSparse(int t[20][3], int a[20][20])
{
    int i,j;
    int r = t[0][0];
    int c = t[0][1];
    int nz = t[0][2];

    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            a[i][j]=0;

    for(i=1;i<=nz;i++)
    {
        a[t[i][0]][t[i][1]] = t[i][2];
    }
}

void transpose(int a[20][20], int tr[20][20], int r, int c)
{
    int i,j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            tr[j][i] = a[i][j];
}

void display(int a[20][20], int r, int c)
{
    int i,j;
    for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}