#include<stdio.h>
int gcd(int a,int b){
    if(a==0) return b;
    if(b== 0) return a;
    if(a==0&& b==0){
        return -1;
    }else{
       return(gcd(b%a, a)); 
    }
}
 int main(){
    int a,b;
    printf("Enter a ");
    scanf("%d", &a);
    printf("Enter b ");
    scanf("%d", &b);
    int ans = gcd(a,b);
    printf("GCD is is %d", ans);
    return 0;
 }
