#include <stdio.h>

int primeNumber(int a){
    int chk=0;
    for(int i=2;i<1000;i++){
        if(a%i==0 && a!=i) chk=1;
    }
    if(chk) return 0;
    else if(a==1) return 0;
    else return 1;
}
//1은 소수 아님
int main(){

    int N,a;
    int count=0;

    scanf("%d", &N);

    while(N--){
        scanf("%d",&a);
        int n=primeNumber(a);
        count+=n;
    }
    printf("%d", count);
    return  0;
}