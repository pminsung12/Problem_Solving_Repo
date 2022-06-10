#include <stdio.h>

int sum=1;
int factorial(int a){
    if(a==1) return sum;
    sum*=a;
    factorial(a-1);
}

int main(){

    int N;
    scanf("%d",&N);
    printf("%d\n",factorial(N));
    return 0;
}