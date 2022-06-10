#include <stdio.h>
#include <string.h>
void reverse(char arr[]){
    int len=strlen(arr);
    for(int i=0;i<len/2;i++){
        char temp=arr[i];
        arr[i]=arr[len-i-1];
        arr[len-i-1]=temp;
    }
}

int main()
{
    char num1[10002]={0,}, num2[10002]={0,}, sum[10003]={0,};
    int carry=0;
    int i;

    scanf("%s %s", &num1, &num2);
    reverse(num1);
    reverse(num2);
    
    int len = strlen(num1)>strlen(num2) ? strlen(num1):strlen(num2);

    for(i=0;i<len;i++){
        //그 자릿수 덧셈(캐리는 올림용)
        int a = num1[i] - '0' + num2[i] -'0' +carry;
        //둘중에 하나라도 null 이면 '0'한번 빼줬으니까 한번 더해야 하고 
        //둘다 null이면 두번 더해줘야 하니 0이 될때까지 while문으로 처리
        while(a<0) a+='0';
        if(a>9) carry=1;
        else carry=0;
        sum[i]=a%10+'0';

    }
    //가장 큰 자릿수 받아올림 발생하는 경우
    if(carry==1) sum[len]='1';
    reverse(sum);
    printf("%s\n",sum);

    return 0;
}