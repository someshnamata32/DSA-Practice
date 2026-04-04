#include <stdio.h>

#define MAX 10

int graph[MAX][MAX];
int visited[MAX];
int queue[MAX];
int front = -1, rear = -1;
int n;

void enqueue(int v)
{
    if (front == -1)
        front = 0;

    queue[++rear] = v;
}

int dequeue()
{
    return queue[front++];
}

void bfs(int start)
{
    int i;

    enqueue(start);
    visited[start] = 1;

    while (front <= rear)
    {
        int node = dequeue();
        printf("%d ", node);

        for (i = 0; i < n; i++)
        {
            if (graph[node][i] == 1 && visited[i] == 0)
            {
                enqueue(i);
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

    printf("BFS Traversal: ");
    bfs(start);

    return 0;
}