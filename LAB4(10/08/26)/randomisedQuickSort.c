#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int arr[], int p, int q) {

    int randomIndex = p + rand() % (q - p + 1);


    int temp = arr[p];
    arr[p] = arr[randomIndex];
    arr[randomIndex] = temp;


    int x = arr[p];
    int i = p;

    for (int j = p + 1; j <= q; j++) {

        if (arr[j] <= x) {
            i++;

            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    temp = arr[p];
    arr[p] = arr[i];
    arr[i] = temp;

    return i;
}

void quickSort(int arr[], int p, int q) {

    if (p < q) {

        int m = partition(arr, p, q);

        quickSort(arr, p, m - 1);
        quickSort(arr, m + 1, q);
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

    // Seed random number generator
    srand(time(NULL));

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
