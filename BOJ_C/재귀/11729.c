#include <stdio.h>

int total(int n){

    if (n==1) return 1;
    else{
        return 2*total(n-1) +1;
    }
}

void hanoi(int n, int a,int b,int c){
    if(n==1){
        printf("%d %d\n", a,c);
        return;
    }
    hanoi(n-1, a,c,b);
    printf("%d %d\n", a, c);
    hanoi(n-1, b,a,c);
}

int main(){

    int x;
    scanf("%d", &x);
    printf("%d\n", total(x));
    hanoi(x,1,2,3);


    return 0;
}