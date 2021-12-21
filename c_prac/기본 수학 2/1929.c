#include <stdio.h>

int main(){

    int M,N;

    scanf("%d %d", &M, &N);
    
    int arr[1000001];
    
    for(int i=2;i<=N;i++){
        if(!arr[i]){
            for(int j=i+i;j<=N;j+=i) arr[j]=1;
        }
        if(i>=M && arr[i]==0) printf("%d\n",i);
    }
    
    return 0;
}