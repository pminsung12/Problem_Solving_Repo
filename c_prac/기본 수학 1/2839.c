#include <stdio.h>

int main(){
    int candy[1001][5]={0,};
    int N;
    int isPossible=0;
    int max1=0;
    int max2=0;
    scanf("%d",&N);

    for(int i=0;i<1001;i++){
        if (5*i>N) break;
        for(int j=0;j<5;j++){
            if(i*5+3*j==N){
                isPossible =1;
                if(max1+max2<i+j){
                    max1 = i;
                    max2 = j;
                }
            }
        }
    }
    if (!isPossible) printf("-1");
    else printf("%d",max1+max2);
    
    return 0;
}