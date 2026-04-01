#include <stdio.h>

int main()
{
    int arr1[50], arr2[50], arr3[100];
    int n1, n2, i, j;

    printf("Enter size of first array: ");
    scanf("%d", &n1);

    printf("Enter size of second array: ");
    scanf("%d", &n2);

    printf("Enter elements of first array:\n");
    for(i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter elements of second array:\n");
    for(j = 0; j < n2; j++)
    {
        scanf("%d", &arr2[j]);
    }

    for(i = 0; i < n1; i++)
    {
        arr3[i] = arr1[i];
    }

    for(j = 0; j < n2; j++)
    {
        arr3[i + j] = arr2[j];
    }

    printf("Merged array:\n");

    for(i = 0; i < n1 + n2; i++)
    {
        printf("%d ", arr3[i]);
    }

    return 0;
}
