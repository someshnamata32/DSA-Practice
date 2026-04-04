#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

void bfs(int start)
{
    int arr[MAX];   
    int i;
    int index = 0;  
    int size = 0;  

    arr[size++] = start;  
    visited[start] = 1;

    while(index < size)
    {
        int node = arr[index++];  
        printf("%d ", node);

        for(i = 0; i < n; i++)
        {
            if(graph[node][i] == 1 && visited[i] == 0)
            {
                arr[size++] = i;   
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    int i, j, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for(i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}