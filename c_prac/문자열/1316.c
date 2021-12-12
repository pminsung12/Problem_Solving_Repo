#include <stdio.h>
#include <string.h>

int main() {
    int N;
    int count =0;
    char word[100];
    scanf("%d",&N);

    for (int i=0;i<N;i++){
        int chk=0;
        int temp[26]={0,};
        scanf("%s",word);
        for(int j=0;j<strlen(word);j++){
            if(temp[word[j]-97] != 0 && word[j] != word[j-1]) chk=1;
            temp[word[j]-97]++;
        }
        if(!chk) count++;
    }
    printf("%d\n", count);
    return 0;
}