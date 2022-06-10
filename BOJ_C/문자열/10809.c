#include <stdio.h>
void show(char word[]){
    //a 97 z 122
    for(int i=97;i<123;i++){
    	int chk=0;
        for(int j=0;j<100;j++){
            if (word[j]=='\0') break;
            if (i==word[j]) {
                printf("%d ",j);
                chk++;
                break;
            }
        }
        if(!chk) printf("-1 ");
    }
}

int main(){
    char word[100];
    scanf("%s", &word);
    show(word);

    return 0;
}