#include<stdio.h>
int main(){
int a;
printf("Enter number");
scanf("%d", &a);
int n;
printf("Enter power");
scanf("%d", &n);
int f = 1;
for(int i = 0;i<n;i++){
    f = f*a;
}
printf("Result is %d", f);
return 0;
}
