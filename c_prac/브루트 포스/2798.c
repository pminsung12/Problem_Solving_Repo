#include <stdio.h>

int main(){
    int a,b;
    int sum=0, min=21, res=0;
    int card[101];
    scanf("%d %d", &a, &b);
    getchar();

    for (int i=0;i<a;i++){
        scanf("%d", &card[i]);
        //printf("[%d]: %d\n", i,card[i]);
    }
    for(int i=0;i<a;i++){
        for(int j=i+1;j<a;j++){
            for (int k=j+1;k<a;k++){
                sum=card[i]+card[j]+card[k];
                if(sum <= b){
                    if(21-sum<min){
                        min=21-sum;
                        res=sum;
                    }
                }
            }
        }
    }
    printf("%d\n",res);

    return 0;
}