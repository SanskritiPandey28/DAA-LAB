#include <stdio.h>

void merge(int arr[], int p, int m, int q) {

    int n1 = m - p + 1;
    int n2 = q - m;

    int L[n1];
    int R[n2];

    // Copy left half
    for (int i = 0; i < n1; i++) {
        L[i] = arr[p + i];
    }

    // Copy right half
    for (int j = 0; j < n2; j++) {
        R[j] = arr[m + 1 + j];
    }

    int i = 0;
    int j = 0;
    int k = p;

    // Merge both sorted halves
    while (i < n1 && j < n2) {

        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }

        k++;
    }

    // Copy remaining elements of L
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int p, int q) {

    if (p < q) {

        int m = (p + q) / 2;

        // Sort left half
        mergeSort(arr, p, m);

        // Sort right half
        mergeSort(arr, m + 1, q);

        // Merge both sorted halves
        merge(arr, p, m, q);
    }
}


int main() {

    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}