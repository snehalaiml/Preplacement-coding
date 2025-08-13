#include <stdio.h>
#include <stdlib.h>
void sortArray(int arr[], int n) {
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void waveSort(int arr[], int n) {
    for(int i=0; i<n-1; i+=2) {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
}

int main() {
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int *arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d elements:\n", n);
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    sortArray(arr, n);
    waveSort(arr, n);

    printf("Wave form array:\n");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}