//문자열 관련 함수들 사용해보기
#include <iostream>
#include <cstring>

using namespace std;

int main(){
    char a[100] = "Our ";
    char b[] = "Beloved Summer";
    char c[50]={0,};
    
    cout<<"len of array a: "<< strlen(a)<<endl;
    cout<<"len of array b: "<< strlen(b)<<endl;
    cout<<"len of array c: "<< strlen(c)<<endl;
    
    if(strcmp(a,b)==0){
        cout<<"SAME!!"<<endl;
    }
    else{
        cout<<"different!!"<<endl;
        if(strcmp(a,b)>0){
            cout<<"a>b"<<endl;
        }
        else cout<<"a<b"<<endl;
    }
    
    strcat(a,b);
    cout<<"a + b: "<<a<<endl;
    
    strcpy(c, a);
    cout<<"c: "<<a<<endl;

    return 0;
}