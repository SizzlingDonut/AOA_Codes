#include <stdio.h>

int pass = 1;

void printArr(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void merge(int arr[], int low, int mid, int high, int size) {
    int n = high - low + 1;
    int temp[n];
    int i = 0;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high) {
        if (arr[left] <= arr[right]) {
            temp[i++] = arr[left++];
        } else {
            temp[i++] = arr[right++];
        }
    }

    while (left <= mid) {
        temp[i++] = arr[left++];
    }

    while (right <= high) {
        temp[i++] = arr[right++];
    }

    for (i = 0; i < n; i++) {
        arr[low + i] = temp[i];
    }
    
    printf("Pass %d: ", pass++);
    printArr(arr, size);  
}

void mergesort(int arr[], int low, int high, int n) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergesort(arr, low, mid, n);
        mergesort(arr, mid + 1, high, n);
        merge(arr, low, mid, high, n);
    }
}

int main() {
    printf("\nPratyush Rahul Ranjan C24 2403133\n\n");
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter array elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("\n");
    mergesort(arr, 0, n - 1, n);
    printf("\nFinal Sorted array: ");
    printArr(arr, n);
    return 0;
}

