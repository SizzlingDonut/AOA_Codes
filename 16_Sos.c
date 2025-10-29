#include<stdio.h>

int callCount = 0;
int W[100];
int X[100];
int n_sos;
int M;

void printSolution(){
	printf("Subset found: {");
	for(int i=0; i<n_sos; i++){
		if(X[i]==1){
			printf("%d ", W[i]);
		}
	}
	printf("}\n");
}

void sumOfSubsets(int s, int k, int r){
	callCount++;
	if(s+W[k] <= M){
		X[k] = 1;
		if(s+W[k] == M){
			printSolution();
		}
		else if(k+1 < n_sos){
			sumOfSubsets(s+W[k], k+1, r-W[k]);
		}
		X[k]=0;
	}
	if(k+1<n_sos && s+r-W[k] >= M){
		X[k] = 0;
		sumOfSubsets(s, k+1, r-W[k]);
	}
}

int main(){
	printf("Pratyush Rahul Ranjan C24 2403133\n\n");
	
	printf("Enter the number of elements: ");
	scanf("%d", &n_sos);
	
	printf("Enter the elements: ");
	for(int i=0; i<n_sos; i++){
		scanf("%d", &W[i]);
	}
	
	printf("Enter the target sum: ");
	scanf("%d", &M);
	
	for(int i=0; i<n_sos; i++){
		for(int j=i+1; j<n_sos; j++){
			if(W[i] > W[j]){
				int temp = W[i];
				W[i] = W[j];
				W[j] = temp;
			}
		}
	}
	
	int total_sum = 0;
	for(int i=0; i<n_sos; i++){
		total_sum += W[i];
	}
	
	printf("\nGiven set of numbers: ");
	for(int i=0; i<n_sos; i++){
		printf("%d ", W[i]);
	}
	printf("\nTarget sum: %d\n\n", M);
	
	if(total_sum < M){
		printf("No subsets possible!\n");
	}else{
		sumOfSubsets(0, 0, total_sum);
	}
	
	printf("\nNo. of calls to Sum of subsets function: %d\n", callCount);
	
	return 0;
}




























