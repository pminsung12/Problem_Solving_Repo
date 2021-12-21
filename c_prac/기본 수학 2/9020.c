#include <stdio.h>

int main(){

    int T,n;
    int max=0;
    scanf("%d",&T);
    int arr[10001];
    while(T--){
        max=0;
        scanf("%d",&n);
        for(int i=2;i<=n;i++){
            if(!arr[i]){
                for(int j=i+i;j<=n;j+=i) arr[j]=1;
            }
        }
        for(int j=2;j<=n/2;j++){
            if(arr[j]==0 && arr[n-j]==0) {//둘다 소수이고
                if(j>max) max=j;
            }
        }
        printf("%d %d\n", max, n-max);
    }
    return 0;
}