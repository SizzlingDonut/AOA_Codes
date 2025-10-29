#include<stdio.h>

void printArr(int arr[], int n){
	for(int i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void selectionSort(int arr[], int n){
	int i, j, min, temp;
	for(i=0; i<n-1; i++){
		min = i;
		for(j=i+1; j<n; j++){
			if(arr[j] < arr[min]){
				min = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;
		printf("Pass %d: ", i+1);
		printArr(arr, n);
	}
}

int main(){
	printf("Pratyush Rahul Ranjan C24 2403133\n\n");
	
	int n;
	printf("Enter number of elements: ");
	scanf("%d", &n);
	
	int arr[n];
	printf("\nEnter the elements: ");
	for(int i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	printf("\n");
	selectionSort(arr, n);
	printf("\nFinal Sorted Array: ");
	printArr(arr, n);
	
	return 0;
}




























