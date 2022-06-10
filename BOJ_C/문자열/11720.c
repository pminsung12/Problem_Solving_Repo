#include <stdio.h>
#define SIZE 101
int sum(int N, char M[]){
    int s=0;
    for(int i=0;i<SIZE;i++){
        if(M[i]=='\0') break;
        s+=M[i]-'0';
    }
    return s;
}

int main(){
    int N;
    scanf("%d\n",&N);
    char M[SIZE];
    scanf("%s\n",&M);
    printf("%d\n",sum(N,M));
    return 0;
}
