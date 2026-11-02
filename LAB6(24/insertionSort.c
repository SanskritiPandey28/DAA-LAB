#include <stdio.h>

void insertionSort(int arr[], int n) {

    for (int i = 1; i < n; i++) {

        for (int j = i; j > 0; j--) {

            if (arr[j] < arr[j - 1]) {

                // swap
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {

    int arr[] = {12, 20, 30, 25, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    insertionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}