#include<stdio.h>

int n;
int callcount = 0;

void printSolution(int board[n][n]){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%d ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

int isSafe(int board[n][n], int row, int col){
	int i, j;
	
	for(i=0; i<col; i++){
		if(board[row][i]){
			return 0;
		}
	}
	for(i=row, j=col; i>=0 && j>=0; i--, j--){
		if(board[i][j]){
			return 0;
		}
	}
	for(i=row, j=col; i<n && j>=0; i++, j--){
		if(board[i][j]){
			return 0;
		}
	}
	return 1;
}

int solveNQueens(int board[n][n], int col){
	callcount++;
	if(col>=n){
		printSolution(board);
		return 1;
	}
	int res = 0;
	for(int i=0; i<n; i++){
		if(isSafe(board, i, col)){
			board[i][col] = 1;
			res = solveNQueens(board, col+1) || res;
			board[i][col] = 0;
		}
	}
	return res;
}

int main(){
	printf("Pratyush Rahul Ranjan C24 2403133\n\n");
	printf("Enter the value of n for n-queens: ");
	scanf("%d", &n);
	printf("\n");
	
	int board[n][n];
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			board[i][j] = 0;
		}
	}
	
	if(!solveNQueens(board, 0)){
		printf("Solution does not exist\n");
	}
	
	printf("Total number of calls to queens pocedure: %d\n", callcount);
	
	return 0;
}





























