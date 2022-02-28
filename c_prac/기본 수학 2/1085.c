#include <stdio.h>
#include <stdlib.h> //abs()

int main(){

    int x,y,w,h;
    int sero=0, garo=0, min=0;
    scanf("%d %d %d %d", &x, &y, &w, &h);
    
    sero=abs(h-y)<y?abs(h-y):y;
    garo=abs(w-x)<x?abs(w-x):x;
    min=sero<garo?sero:garo;

    printf("%d\n", min);
    
    return 0;
}