#include <stdio.h>
#define INF 999999
#define SIZE 100

int minDistance(int dist[], int visited[], int V) {
	int min = INF, min_index = -1;
	for (int v = 0; v < V; v++) {
		if (!visited[v] && dist[v] <= min) {
			min = dist[v];
			min_index = v;
		}
	}
	return min_index;
}

void printPath(int parent[], int j) {
	if (parent[j] == -1){
		return;
	}
	printPath(parent, parent[j]);
	printf(" -> %d", j);
}

void dijkstra(int graph[][SIZE], int V, int src) {
	int dist[SIZE];
	int visited[SIZE];
	int parent[SIZE];

	for (int i = 0; i < V; i++) {
		dist[i] = INF;
		visited[i] = 0;
		parent[i] = -1;
	}
	dist[src] = 0;

	for (int count = 0; count < V - 1; count++) {
		int u = minDistance(dist, visited, V);
		if (u == -1){
			break;
		}
		visited[u] = 1;

		for (int v = 0; v < V; v++) {
			if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
				dist[v] = dist[u] + graph[u][v];
				parent[v] = u;
			}
		}
	}

	printf("\nVertex\tDistance (D)\tPredecessor (Pi)\n");
	for (int i = 0; i < V; i++) {
		if (dist[i] == INF){
			printf("%d\tINF\t\t%d\n", i, parent[i]);
		}
		else{
			printf("%d\t%d\t\t%d\n", i, dist[i], parent[i]);
		}
	}

	printf("\nPaths from source vertex %d:\n", src);
	for (int i = 0; i < V; i++) {
		if (i != src) {
			printf("Path to vertex %d: %d", i, src);
			if (dist[i] == INF) {
				printf(" -> (no path)\n");
			} else {
				printPath(parent, i);
				printf(" | Total cost = %d\n", dist[i]);
			}
		}
	}
}

int main() {
	int V, E;
	int graph[SIZE][SIZE];
	printf("Enter the number of vertices (max %d): ", SIZE);
	scanf("%d", &V);

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			graph[i][j] = 0;
		}
	}

	printf("Enter the number of edges: ");
	scanf("%d", &E);

	printf("Enter each edge as: u v w (for an undirected weighted edge)\n");
	for (int i = 0; i < E; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		if (u >= 0 && u < V && v >= 0 && v < V) {
			graph[u][v] = w;
			graph[v][u] = w;
		} else {
			printf("Invalid edge (%d, %d) ignored.\n", u, v);
		}
	}

	int src;
	printf("Enter the source vertex (0 to %d): ", V - 1);
	scanf("%d", &src);

	dijkstra(graph, V, src);

	return 0;
}
