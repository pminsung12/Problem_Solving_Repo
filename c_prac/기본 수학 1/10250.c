#include <stdio.h>

int main(){
    int T, H, W, N;
    scanf("%d\n", &T);
    for(int i=0;i<T;i++){
        scanf("%d %d %d",&H,&W,&N);
        if(N/H+1<10) printf("%d0%d\n",N%H,N/H+1);
        else printf("%d%d\n",N%H,N/H+1);
    }
    return 0;
}