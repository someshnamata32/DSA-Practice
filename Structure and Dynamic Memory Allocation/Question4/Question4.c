#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *arr,i,sum=0;

    arr = (int*)malloc(10*sizeof(int));

    printf("Enter 10 elements:\n");

    for(i=0;i<10;i++)
    {
        scanf("%d",&arr[i]);
        sum += arr[i];
    }

    printf("Sum = %d",sum);

    free(arr);

    return 0;
}