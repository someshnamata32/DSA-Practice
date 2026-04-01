#include <stdio.h>

int main()
{
    int arr[100], n, pos, element, i;
    char choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    do
    {
        printf("\nEnter position to insert: ");
        scanf("%d", &pos);

        if(pos < 1 || pos > n + 1)
        {
            printf("Invalid position\n");
        }
        else
        {
            printf("Enter element to insert: ");
            scanf("%d", &element);

            for(i = n - 1; i >= pos - 1; i--)
            {
                arr[i + 1] = arr[i];
            }

            arr[pos - 1] = element;
            n++;

            printf("Element inserted successfully\n");
        }

        printf("Do you want to insert more element (Y/N): ");
        scanf(" %c", &choice);

    } while(choice == 'Y' || choice == 'y');

    printf("\nThe new array:\n");

    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
