#include <stdio.h>
#define MAX 100
#define INF 999999

int find(int parent[], int i) {
    while (parent[i] != i) {
        i = parent[i];
    }
    return i;
}

void union_set(int parent[], int i, int j) {
    int a = find(parent, i);
    int b = find(parent, j);
    parent[a] = b;
}

int main() {
    printf("Pratyush Rahul Ranjan C24 2403133\n\n");

    int n;
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int cost[MAX][MAX];
    printf("Enter adjacency matrix (0 for no edge):\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0) {
                cost[i][j] = INF;
            }
        }
    }

    int parent[MAX];
    for (int i = 0; i < n; i++) {
        parent[i] = i;
    }

    int edges = 0, total = 0;
    printf("Edges in MST:\n");

    while (edges < n - 1) {
        int min = INF;
        int a = -1, b = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (cost[i][j] < min) {
                    int u = find(parent, i);
                    int v = find(parent, j);
                    if (u != v) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            printf("%d - %d : %d\n", a, b, min);
            total += min;
            union_set(parent, a, b);
            edges++;
        }

        cost[a][b] = cost[b][a] = INF;
    }

    printf("Total weight of MST = %d\n", total);
    return 0;
}
