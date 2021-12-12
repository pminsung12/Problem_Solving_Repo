#include <stdio.h>

int main(){
    int A,B,V;
    int height=0;
    int day=1;
    scanf("%d %d %d",&A, &B,&V);
    day = (V-A)/(A-B);//최대한 근삿값 구해주고
    height = day*(A-B);
    
    while(V>=height){
        height+= A;
        day++;
        if(V<=height) break;
        height-=B;
    }
    printf("%d", day);
    return 0;
}