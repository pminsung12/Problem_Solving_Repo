#include <iostream>
#include <stack>
using namespace std;

int main(){
    int N;
    cin>>N;

    stack<int> stk;
    string k;
    cin>>k;
    if(k=="push"){
        int k;
        cin>>k;
        stk.push(k);
    }
    else if(k=="top"){
        cout<<stk.top();
        if(stk.empty()) cout<<"-1";
    }
    else if(k=="size"){
        cout<<stk.size();
    }
    else if(k=="pop"){
        cout<<stk.pop();
    }
    else if(k=="empty"){
        if(stk.empty()) cout<<'1';
        else cout<<'0';
    }

    return 0;
}