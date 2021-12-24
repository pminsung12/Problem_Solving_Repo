//구글링해봐도 모르겠다
#include <stdio.h>


void square(int n){
    
    while(n!=1){
        while(n--){
            printf("*");
        }
        printf("\n");
        while((n-2))--{
            printf("*");
            while((n-2)--){
                printf(" ");
            }
            printf("*")
        }
        while(n--){
            printf("*");
        }
        n/=3
    }

    square(n/3);
}

int main(){

    int N;
    scanf("%d", &N);
    squre(N);

    return 0;
}