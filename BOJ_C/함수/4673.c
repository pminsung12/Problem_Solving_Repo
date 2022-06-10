#include <stdio.h>

int sum(int n){
    int s =n;
    while(n>0){
        s += n%10;
        n=n/10;
    }
    return s;
}

int main(){
    int n;
    int sn[10001];
    for(int i=1;i<10001;i++){
        n=sum(i);
        if (n<10001) sn[n]=1; 
    }
    for(int j=1;j<10001;j++){
        if(sn[j]!=1) printf("%d\n", j);
    }

    return 0;
}
