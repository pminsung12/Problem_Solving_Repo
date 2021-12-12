#include <stdio.h>

int main(){
    //1 1개 1
    //2~7 2개 6
    //8~19 3개 12
    //20~37 4개 18
    //38~61 5개 24 6n
    int N;
    int i=0;
    int count=1;
    scanf("%d",&N);
    while(N>count){
        count+=6*i;
        //printf("count: %d\n", count);
        //printf("i: %d\n", i);
        i++; 
    }
    if(N==1) printf("1");
    else printf("%d\n", i);
    return 0;
}