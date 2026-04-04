#include <stdio.h>

void input(int mat[20][20], int r, int c)
{
    int i, j;

    printf("Enter elements:\n");
    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

void display(int mat[20][20], int r, int c)
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int sparseToTriplet(int mat[20][20], int trip[20][3], int r, int c)
{
    int i, j, k = 1, nz = 0;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(mat[i][j] != 0)
                nz++;
        }
    }

    trip[0][0] = r;
    trip[0][1] = c;
    trip[0][2] = nz;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(mat[i][j] != 0)
            {
                trip[k][0] = i;
                trip[k][1] = j;
                trip[k][2] = mat[i][j];
                k++;
            }
        }
    }

    return nz + 1;
}

void displayTriplet(int trip[20][3], int n)
{
    int i;

    printf("\nTriplet Representation:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d %d %d\n", trip[i][0], trip[i][1], trip[i][2]);
    }
}

int main()
{
    int mat[20][20], trip[20][3];
    int r, c, n;

    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);

    input(mat, r, c);

    printf("\nThe Sparse Matrix:\n");
    display(mat, r, c);

    n = sparseToTriplet(mat, trip, r, c);

    displayTriplet(trip, n);

    return 0;
}