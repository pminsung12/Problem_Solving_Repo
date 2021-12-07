#include <stdio.h>

int han(int n){
    int count=0;
    if (n<100) return n;
    else{//n이 100~1000
        for(int i=100;i<n+1;i++){
            if(i/10%10-i%10== i/100-i/10%10) count++;
        }
        return 99+count;
    }
}

int main(){
    int n;
    scanf("%d",&n);
    printf("%d", han(n));
    return 0;
}

