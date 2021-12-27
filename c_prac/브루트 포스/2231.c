#include <stdio.h>

int main(){

    int N,k,min;
    int i=0,chk=0, res=0;
    scanf("%d", &N);
    k=N;
    min=N;
    while(k>1){
        i++;
        k/=10;
    }
    //printf("i: %d\n", i);

    for(int j= N-9*i;j<N;j++){
        int t=j;
        res+=j;
        while(t >1){
            res+=t%10;
            t/=10;
        }
        res+=t;
        //printf("%d : %d\n", j, res);
        if (res==N){
            printf("%d\n",j);
            N=0;
            break;
        }
        res=0;
    }
    if(N!=0) printf("0\n");

    return 0;
}