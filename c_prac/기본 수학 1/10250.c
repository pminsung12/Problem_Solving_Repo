#include <stdio.h>

int main(){
    int T, H, W, N;
    scanf("%d\n", &T);
    for(int i=0;i<T;i++){
        scanf("%d %d %d",&H,&W,&N);
        printf("%d %d %d\n", H, W, N);
        printf("%d%d\n",N%W,N/H+1);
    }
    return 0;
}