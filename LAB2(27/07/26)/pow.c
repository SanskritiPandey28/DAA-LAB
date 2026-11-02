#include<stdio.h>
int powerOfNo(int a, int b){
    if(a==0) return 0;
    if(b==0) return 1;
    else{
        return(a*powerOfNo(a,b-1));
    }
}
 int main(){
    int a,b;
    printf("Enter number");
    scanf("%d", &a);
    printf("Enter power ");
    scanf("%d", &b);
    int ans = powerOfNo(a,b);
    printf("Result is is %d", ans);
    return 0;
 }
