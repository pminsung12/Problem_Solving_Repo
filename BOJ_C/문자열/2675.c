#include <stdio.h>
#include <string.h>

int main(){
    int T,R;
    char S[20];
    scanf("%d\n",&T);
    if (T>1000 || T<1) return 0;
    for(int i=0;i<T;i++){
        scanf("%d %s",&R, &S);
        if(!(R>=1 && R<=8)) break;
        for(int k=0;k<strlen(S);k++)
            for(int j=0;j<R;j++) printf("%c",S[k]);
        printf("\n");
    }
    return 0;
}