#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr,n,i,key,found=0;

    printf("Enter size of array: ");
    scanf("%d",&n);

    arr=(int*)malloc(n*sizeof(int));

    printf("Enter elements:\n");

    for(i=0;i<n;i++)
    scanf("%d",&arr[i]);

    printf("Enter element to search: ");
    scanf("%d",&key);

    for(i=0;i<n;i++)
    {
        if(arr[i]==key)
        {
            found=1;
            break;
        }
    }

    if(found)
    printf("Element is present in array");
    else
    printf("Element is not present in array");

    free(arr);

    return 0;
}