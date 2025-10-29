#include<stdio.h>
#include<string.h>

int max(int a, int b){
	return (a>b) ? a:b;
}

void LCS(char X[], char Y[], int m, int n){
	int L[m+1][n+1];
	char B[m+1][n+1];
	
	for(int i=0; i<=m; i++){
		for(int j=0; j<=n; j++){
			if(i==0 || j==0){
				L[i][j] = 0;
				B[i][j] = '-';
			}
			else if(X[i-1] == Y[j-1]){
				L[i][j] = 1 + L[i-1][j-1];
				B[i][j] = 'D';
			}
			else if(L[i-1][j] >= L[i][j-1]){
				L[i][j] = L[i-1][j];
				B[i][j] = 'U';
			}
			else{
				L[i][j] = L[i][j-1];
				B[i][j] = 'L';
			}
		}
	}
	
	printf("\nBackpointer Table:\n");
	printf("    ");
	for(int j=0; j<n; j++){
		printf(" %c", Y[j]);
	}
	printf("\n");
	
	for(int i=0; i<=m; i++){
		if(i > 0){
			printf("%c ", X[i-1]);
		}
		else{
			printf("  ");
		}
		for(int j=0; j<=n; j++){
			printf(" %c", B[i][j]);
		}
		printf("\n");
	}
	
	int index = L[m][n];
	char lcs[index+1];
	lcs[index] = '\0';
	
	int i=m, j=n;
	while(i>0 && j>0){
		if(B[i][j] == 'D'){
			lcs[index-1] = X[i-1];
			index--;
			i--;
			j--;
		}
		else if(B[i][j] == 'U'){
			i--;
		}
		else{
			j--;
		}
	}
	
	printf("\nLCS of %s and %s is %s.\n", X, Y, lcs);
}

int main(){
	printf("Pratyush Rahul Ranjan C24 2403133\n\n");
	
	char X[100], Y[100];
	
	printf("Enter first string: ");
	scanf("%s", X);
	
	printf("Enter second string: ");
	scanf("%s", Y);
	
	int m = strlen(X);
	int n = strlen(Y);
	
	LCS(X, Y, m, n);
	
	return 0;
}




























