#include <stdio.h>

int sumarray(int a[], int n)
{
    int i, sum = 0;

    for(i = 0; i < n; i++)
    {
        sum = sum + a[i];
    }

    return sum;
}

int main()
{
    int arr[100], n, i, result;

    printf("Enter the size of array: ");
    scanf("%d", &n);

    printf("Enter elements of array:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    result = sumarray(arr, n);

    printf("Sum of elements of array = %d", result);

    return 0;
}
