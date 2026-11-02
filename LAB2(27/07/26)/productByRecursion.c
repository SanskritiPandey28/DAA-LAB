#include<stdio.h>
int productByRecursion(int a, int b){
    if(a<= 0|| b<=0) return 0;
    else{
        return(a+ productByRecursion(a,b-1));
    }
}
 int main(){
    int a,b;
    printf("Enter a ");
    scanf("%d", &a);
    printf("Enter b ");
    scanf("%d", &b);
    int ans = productByRecursion(a,b);
    printf("Product is is %d", ans);
    return 0;
 }
