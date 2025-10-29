#include<stdio.h>
#define MAX 100
#define INF 999999

int main(){
	printf("Pratyush Rahul Ranjan C24 2403133\n\n");
	
	int n;
	printf("Enter number of vertices: ");
	scanf("%d", &n);
	
	int cost[MAX][MAX];
	printf("\nEnter the adjacency matrix:\n");
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d", &cost[i][j]);
			if(cost[i][j] == 0){
				cost[i][j] = INF;
			}
		}
	}
	
	int selected[MAX] = {0};
	selected[0] = 1;
	
	int edges=0, total=0;
	
	printf("\nEdges in MST:\n");
	while(edges < n-1){
		int min = INF;
		int x=0, y=0;
		
		for(int i=0; i<n; i++){
			if(selected[i]){
				for(int j=0; j<n; j++){
					if(!selected[j] && cost[i][j] < min){
						min = cost[i][j];
						x = i;
						y = j;
					}
				}
			}
		}
		
		printf("%d - %d : %d\n", x, y, min);
		total += min;
		selected[y] = 1;
		edges++;
	}
	
	printf("\nTotal cost of MST : %d\n", total);
	
	return 0;
}




























