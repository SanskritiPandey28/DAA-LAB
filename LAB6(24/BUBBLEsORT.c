#include<stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
//without flag
void bubbleSort(int arr[], int n){
    for(int i = 0;i<n;i++){
        for(int j = i; j = n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
            }
        }
    }
}


//with flag
void bubbleSortWithFlag(int arr[], int n){
    for(int i = 0;i<n;i++){
        int flag = 0;
        for(int j = i; j = n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                flag = 1;
            }
            if(flag== 0) return;
        }
    }
}
int main(){
    printf("enter the number of elements: ");
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bubbleSort(arr, n);
    
    printf("Sorted array: ");
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}