#include <iostream>
#include <cstring>
using namespace std;

int main(){
    char arr[6];
    while(1){
        cin>>arr;
        if(arr[0]=='0') break;
        int len=strlen(arr);
        int chk=1;
        for(int i=0;i<len/2;i++){
            if(arr[i]!=arr[len-i-1]) chk=0;
        }
        if(chk) cout<<"yes"<<'\n';
        else cout<<"no"<<'\n';
    }



    return 0;
}