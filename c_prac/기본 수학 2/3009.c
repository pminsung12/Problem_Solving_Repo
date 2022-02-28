#include <stdio.h>

int dif(int a, int b, int c){
    if(a==c){
        return b;
    }
    else if(b==c){
        return a;
    }
    else{//a==b
        return c;
    }
}


int main(){
    int a,b,c,d,e,f;
    scanf("%d %d", &a, &b);
    scanf("%d %d", &c, &d);
    scanf("%d %d", &e, &f);

    printf("%d %d",dif(a,c,e), dif(b,d,f));
    
    return 0;
}