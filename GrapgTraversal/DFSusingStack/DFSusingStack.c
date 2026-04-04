#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int n;

void dfs(int start)
{
    int stack[MAX];   
    int top = -1;
    int i;

  
    stack[++top] = start;

    while (top != -1)
    {
        int node = stack[top--];  

        if (visited[node] == 0)
        {
            printf("%d ", node);
            visited[node] = 1;

           
            for (i = n - 1; i >= 0; i--)
            {
                if (graph[node][i] == 1 && visited[i] == 0)
                {
                    stack[++top] = i;
                }
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
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    for (i = 0; i < n; i++)
        visited[i] = 0;

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    dfs(start);

    return 0;
}