#include<stdio.h>
int DACPower(int a, int n){
    int b;
    if(n==1){
        return a;
    }else{
        b = DACPower(a,n/2);
        b = b*b;
        if(n%2!= 0){
            return b*a;
        }else{
            return b;
        }
    }
}
int main(){
int a;
printf("Enter number");
scanf("%d", &a);
int n;
printf("Enter power");
scanf("%d", &n);
int result = DACPower(a,n);
printf("Result is %d", result);
}