//스택문제 괄호는 스택이다!
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool IsValid(string str){
    stack<char> stk;
    for(int i=0;i<str.length();i++){
        if(str[i]=='(') stk.push(str[i]);
        else {
            if(stk.empty()) return false;
            stk.pop();
        }
    }
    if(stk.empty()) return true;
    else return false;
}

int main(){
    int T;
    cin>>T;
    
    string str;
    while(T--){
        cin>>str;
        if(IsValid(str)) cout<<"YES"<<'\n';
        else cout<<"NO"<<'\n';
    }
    return 0;
}