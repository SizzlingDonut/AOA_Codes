#include <stdio.h>
#define SIZE 10

int queue[SIZE], front = -1, rear = -1;

void enqueue(int value) {
    if (rear == SIZE - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isQueueEmpty() {
    return front == -1 || front > rear;
}

void bfs(int graph[][SIZE], int n, int start) {
    int visited[SIZE] = {0};
    front = rear = -1;

    enqueue(start);
    visited[start] = 1;

    printf("BFS traversal starting from node %d: ", start);

    while (!isQueueEmpty()) {
        int current = dequeue();
        printf("%d ", current);

        for (int i = 0; i < n; i++) {
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i] = 1;
            }
        }
    }
    printf("\n");
}

int main() {
    int graph[SIZE][SIZE], n, start;

    printf("Enter the number of nodes (max %d): ", SIZE);
    scanf("%d", &n);

    printf("Enter the adjacency matrix (%d x %d):\n", n, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting node (0 to %d): ", n - 1);
    scanf("%d", &start);

    bfs(graph, n, start);

    return 0;
}

