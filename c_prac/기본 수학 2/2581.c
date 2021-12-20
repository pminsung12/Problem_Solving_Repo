#include <stdio.h>
int main(){

    int M,N;
    int chk=0, sum=0,first=0,res=0;

    scanf("%d %d", &M, &N);
    if(M==1) M=2;
    for(int j=M;j<=N;j++){
        for(int i=2;i<N;i++){
            if(j%i==0 && j!=i) {//소수 x
                chk=1;
            }
        }
        
        if(chk==0) {//소수면
            if(!first) {//처음이면
                first=1;
                res=j;//res는 첫소수값
            }
            sum+= j;
        }
        chk=0;
    }
    if(res==0 || N==1) printf("-1");
    else {
        printf("%d\n", sum);
        printf("%d\n", res);
    }

    return 0;
}