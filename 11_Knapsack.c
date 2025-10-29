#include <stdio.h>
#define MAX_ITEMS 100
#define MAX_CAPACITY 1000

int max(int a, int b) {
	return (a > b) ? a : b;
}

void knapsack(int W, int wt[], int val[], int n) {
	int dp[MAX_ITEMS + 1][MAX_CAPACITY + 1];
	int solution[MAX_ITEMS] = {0};

	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			if (i == 0 || w == 0){
				dp[i][w] = 0;
			}
			else if (wt[i - 1] <= w){
				dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], dp[i - 1][w]);
			}
			else{
				dp[i][w] = dp[i - 1][w];
			}
		}
	}

	printf("DP Matrix:\n");
	for (int i = 0; i <= n; i++) {
		for (int w = 0; w <= W; w++) {
			printf("%4d", dp[i][w]);
		}
		printf("\n");
	}

	printf("\nTotal Profit Earned = %d\n", dp[n][W]);

	int w = W;
	for (int i = n; i > 0 && dp[i][w] > 0; i--) {
		if (dp[i][w] != dp[i - 1][w]) {
			solution[i - 1] = 1;
			w = w - wt[i - 1];
		}
	}

	printf("Solution Vector (1 = included, 0 = not included):\n");
	for (int i = 0; i < n; i++) {
		printf("%d", solution[i]);
	}
	printf("\n");
}

int main () {
	printf("Pratyush Rahul Ranjan C24 2403133\n\n");
	
	int n, W;
	int val[MAX_ITEMS], wt[MAX_ITEMS];

	printf("Enter the number of items (max %d) : ", MAX_ITEMS);
	scanf("%d", &n);

	printf("Enter the values of items:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &val[i]);
	}

	printf("Enter the weights of items:\n");
	for (int i = 0; i < n; i++) {
		scanf("%d", &wt[i]);
	}

	printf("Enter the capacity of the knapsack :");
	scanf("%d", &W);

	knapsack(W, wt, val, n);

	return 0;
}




























