#include <stdio.h>
#include <string.h>

int main(){
    char num1[4]; 
    char num2[4];
    char temp;
    scanf("%s %s", num1, num2);
    
    temp = num1[0];    
    num1[0]=num1[2];
    num1[2]=temp;
    
    temp = num2[0];    
    num2[0]=num2[2];
    num2[2]=temp;

    if(strcmp(num1,num2)>0) printf("%s", num1);
    else printf("%s", num2);

    return 0;
}