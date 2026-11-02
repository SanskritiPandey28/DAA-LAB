// write a pgm for linear search using recursion and without recursion


//without recursion
#include<stdio.h>
 int linearSearchWithoutRecursion(int arr[], int n, int target){
    for(int i = 0; i<n; i++){
        if(arr[i] == target){
            return i;
        }
        
    }
    return -1;
 }
 
int linearSearch(int arr[], int n, int key, int i) {
    if (i == n) {
        return -1;  // Base case: element not found
    }

    if (arr[i] == key) {
        return i;   // Element found
    }

    return linearSearch(arr, n, key, i + 1);
}

 
 int main(){
    int n;
    int target;
    printf("Enter number of elements");
    scanf("%d", &n);
        printf("Enter number to search");
    scanf("%d", &target);
    int arr[n];
    for(int i = 0; i<n;i++){
        printf("Enter %d index  elemnt", i);
        scanf("%d", arr[i]);
    }
    int ans = linearSearchWithoutRecursion(arr,n, target);
    printf("Element is %d", ans);
    return 0;
 }
