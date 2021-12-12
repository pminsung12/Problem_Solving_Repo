#include <stdio.h>

int main(){
    int A,B,V;
    int height=0;
    int day=1;
    scanf("%d %d %d",&A, &B,&V);

    while(V>=height){
        height+= A;
        if (V<=height) break;
        height-=B;
        day++;
    }
    printf("%d", day);
    return 0;
}