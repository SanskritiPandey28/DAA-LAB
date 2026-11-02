#include <stdio.h>

int partition(int arr[], int p, int q) {
    int x = arr[p];
    int i = p;

    for (int j = p + 1; j <= q; j++) {

        if (arr[j] <= x) {
            i = i + 1;

            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    // Put pivot in its correct position
    int temp = arr[i];
    arr[i] = arr[p];
    arr[p] = temp;

    return i;
}

void quickSort(int arr[], int p, int q) {

    if (p >= q) {
        return;
    }

    int m = partition(arr, p, q);

    quickSort(arr, p, m - 1);
    quickSort(arr, m + 1, q);
}

int main() {

    int n;

    printf("Enter no of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements of array: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}