#include <stdio.h>

int main(){
    int X;
    int count=0;
    int n=0;
    scanf("%d",&X);
    while(X>count){
        n++;
        count += n;
    }
    if(n%2) printf("%d/%d",count-X+1,n-(count-X));
    else printf("%d/%d",n-(count-X),count-X+1);
    return 0;
}