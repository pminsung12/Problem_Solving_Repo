#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;

int main(){
    int N;
    cin>>N;
    cin.ignore();
    stack<int> stk;
    string k;
    
    for(int i=0;i<N;i++){
        getline(cin,k,'\n');
        if(k[3]=='h'){
            string sub = k.substr(5, k.length()-5);
            int n=stoi(sub);
            stk.push(n);
        }
        else if(k=="top"){
            if(stk.empty()) cout<<"-1"<<'\n';
            else
                cout<<stk.top()<<'\n';
        }
        else if(k=="size"){
            cout<<stk.size()<<'\n';
        }
        else if(k=="pop"){
            if(stk.empty()) cout<<"-1"<<'\n';
            else{
                int num=stk.top();
                stk.pop();
                cout<<num<<'\n';
            }
        }
        else if(k=="empty"){
            if(stk.empty()) cout<<'1'<<'\n';
            else cout<<'0'<<'\n';
        }
    }
    return 0;
}