#include <stdio.h>

int main(){
    int n;
    int count=0;
    int arr[246913]={0,};
    while(1){
        count=0;
        scanf("%d", &n);
        if(n==0) break;
        
        
        for(int i=2;i<=2*n;i++){
            if(!arr[i]){
                for(int j=i+i;j<=2*n;j+=i) arr[j]=1;
            }
            if(i>n && arr[i]==0) count++;
        }
        printf("%d\n", count);
    }
    return 0;
}
