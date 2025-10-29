#include <stdio.h>
#define SIZE 10

int stack[SIZE], top = -1;

void push(int value) {
    if (top == SIZE - 1)
        return;
    stack[++top] = value;
}

int pop() {
    if (top == -1)
        return -1;
    return stack[top--];
}

int isStackEmpty() {
    return top == -1;
}

void dfs(int graph[][SIZE], int n, int start) {
    int visited[SIZE] = {0};
    top = -1;

    push(start);

    printf("DFS traversal starting from node %d: ", start);

    while (!isStackEmpty()) {
        int current = pop();

        if (!visited[current]) {
            printf("%d ", current);
            visited[current] = 1;

            for (int i = n - 1; i >= 0; i--) {
                if (graph[current][i] == 1 && !visited[i]) {
                    push(i);
                }
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

    dfs(graph, n, start);

    return 0;
}

