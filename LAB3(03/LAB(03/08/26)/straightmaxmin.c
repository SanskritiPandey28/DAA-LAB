#include<stdio.h>

int main(){
   int n;
    
    printf("Enter no of elements");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of array");
    for(int i = 0; i<n;i++){
        scanf("%d", &arr[i]);
    }
    int max = arr[0];
    int min = arr[0];
    for(int i = 1; i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
        if(arr[i]<min){
            min = arr[i];
        }
    }
        printf("Minimum no %d ", min);
         printf("Maximum no %d ", max);
         return 0;
    
}