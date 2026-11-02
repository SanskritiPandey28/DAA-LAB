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

int selectionProcedure(int arr[], int p, int q, int k){
     if (p > q) {
        return -1;
    }

    else{
        int m = partition(arr,p,q);
        if(m==k){
            return (arr[m]);
        }else{
            if(m<k){
                return selectionProcedure(arr, m+1,q,k);
            }else{
                return selectionProcedure(arr,p,m-1,k);
            }
        }
    }
}

int main(){
    int n;

    printf("Enter no of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements of array: ");

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = selectionProcedure(arr, 0, n - 1, 2);

    printf("%d  is the kth smaleest element" , result);

   

    return 0;
}