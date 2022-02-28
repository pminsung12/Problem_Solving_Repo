#include <stdio.h>
#include <string.h>

int main(){
    char word[16];
    int time=0;;
    scanf("%s", &word);

    for(int i =0;i<strlen(word);i++){
        //A~C 65 67
        if (word[i]<68) time +=3;//ABC
        else if(word[i]<71) time +=4;//DEF
        else if(word[i]<74) time +=5;//GHI
        else if (word[i]<77) time +=6;//JKL
        else if(word[i]<80) time +=7;//MNO
        else if(word[i]<84) time +=8;//PQRS
        else if (word[i]<87)time +=9;//TUV
        else time +=10;//WXYZ
    }
    printf("%d\n",time);
    return 0;
}