#include <stdio.h>
#include <string.h>//strlen()

int main() {
    char word[1000000];
    scanf("%s",&word);

    int cnt[26]={0,};//알파벳 배열 A-Z a-z
    
    for (int i =0;i<strlen(word);i++){
        //A-Z
        if (word[i]<='Z') cnt[word[i]-'A']++;
        //a-z
        else if (word[i]>='a') cnt[word[i]-'a']++;
    }

    int max =0;//최댓값 index
    for (int j=0;j<26;j++){
        if (cnt[j]>cnt[max]) max = j;
    }
    //경우 1
    for(int k=0;k<26;k++){
        if ((cnt[k]==cnt[max])&& (k != max)){
            printf("?\n");
            return 0;
        }
    }
    //경우 2
    //대문자 A 65 a 97 
    printf("%c\n",max+65);
    return 0;
}