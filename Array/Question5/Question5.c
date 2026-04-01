#include <stdio.h>

int largest(int a[], int n)
{
    int i, max;

    max = a[0];

    for(i = 1; i < n; i++)
    {
        if(a[i] > max)
        {
            max = a[i];
        }
    }

    return max;
}

int main()
{
    int arr[100], n, i, max;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements of array:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    max = largest(arr, n);

    printf("Largest element of array = %d", max);

    return 0;
}
