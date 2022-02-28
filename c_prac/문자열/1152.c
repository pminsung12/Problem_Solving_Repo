#include <stdio.h>
#include <string.h>
#define LEN 1000000

int main(){
    char stc[LEN];
    int count=0;
    scanf("%[^\n]s",stc);
    //fgets(stc,LEN,stdin);
    
    for(int i=0;i<strlen(stc);i++){
        if (stc[i]==' ') count++;
    }
    //Case 1 문자열이 시작& 끝 공백
    if ((stc[0]==' ' )&&(stc[strlen(stc)-1]==' ')) printf("%d", count-1);
    //Case 2 문자열이 시작할 때 공백
    else if (stc[0]==' ') printf("%d", count);
    //Case 3 문자열이 끝날 때 공백 
    else if (stc[strlen(stc)-1]==' ') printf("%d", count);
    //Case 4 일반적인 문장
    else printf("%d", count+1);
    
    return 0;
}
