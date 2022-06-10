#include <stdio.h>

int main(){
    int T, H, W, N;
    scanf("%d\n", &T);
    for(int i=0;i<T;i++){
        scanf("%d %d %d",&H,&W,&N);
        int a = N%H;
        int b = N/H+1;//1~6 1 7~12 2 13~18 3
        if(N%H==0) {
            a = H;
            b = N/H;
        }
        if(b<10) printf("%d0%d\n",a,b);
        else printf("%d%d\n",a,b);
    }
    return 0;
}