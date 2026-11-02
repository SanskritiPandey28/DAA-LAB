#include <stdio.h>

void DACmaxmin(int arr[], int i, int j, int *max, int *min)
{
    if (i == j)
    {
        *max = arr[i];
        *min = arr[i];
        return;
    }

    if (i == j - 1)
    {
        if (arr[i] > arr[j])
        {
            *max = arr[i];
            *min = arr[j];
        }
        else
        {
            *max = arr[j];
            *min = arr[i];
        }
        return;
    }

    int mid = (i + j) / 2;

    int max1, min1, max2, min2;

    DACmaxmin(arr, i, mid, &max1, &min1);
    DACmaxmin(arr, mid + 1, j, &max2, &min2);

    if (max1 > max2)
        *max = max1;
    else
        *max = max2;

    if (min1 < min2)
        *min = min1;
    else
        *min = min2;
}

int main()
{
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int max, min;

    DACmaxmin(arr, 0, n - 1, &max, &min);

    printf("Maximum = %d\n", max);
    printf("Minimum = %d\n", min);

    return 0;
}