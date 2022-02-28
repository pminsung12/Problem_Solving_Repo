#include <stdio.h>
#include <math.h>
int right_triangle(int a, int b, int c){
    int x, y ,z;
    if(a>b){
        if(a>c) {
            x=a;
            y=b>c?b:c;
            z=b>c?c:b;
        }
        else if (c>a) {
            x =c;
            y=a>b?a:b;
            z=a>b?b:a;
        }
    }
    if(b>a){
        if(b>c) {
            x=b;
            y=a>c?a:c;
            z=a>c?c:a;
        }
        else if(c>b) {
            x=c;
            y=a>b?a:b;
            z=a>b?b:a;
        }
    }
    if(x*x==y*y+z*z) return 1;
    else return 0;
}

int main(){
    int a,b,c;

    while(1){
        scanf("%d %d %d", &a, &b, &c);
        if(a==0&&b==0&&c==0) break;
        if(right_triangle(a,b,c)) printf("right\n");
        else printf("wrong\n");
    }
    return 0;
}