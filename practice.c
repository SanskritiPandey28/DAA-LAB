#include<stdio.h>

//fa torial with call by reference
void  fact(int n , int *fact){
    if(n==0||n==1) *fact = 1;
    else{
        factorial(n-1,*fact);
        *fact = (*fact)*n
    }
}

//factorial with recursion
int factorial(int n){
    int fact = 1;
    if(n==0||n==1) return 1;
    else{
        factorial(n-1);
        fact = (fact)*n
    }
}

//fibonnaci 
void fibonacci(int )