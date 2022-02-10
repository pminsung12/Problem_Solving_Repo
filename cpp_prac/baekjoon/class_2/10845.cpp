#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

int main(){
    int N;
    cin>>N;
    cin.ignore();
    queue<int> q;
    string k;
    
    for(int i=0;i<N;i++){
        getline(cin,k,'\n');
        if(k[3]=='h'){
            string sub = k.substr(5, k.length()-5);
            int n=stoi(sub);
            q.push(n);
        }
        else if(k=="front"){
            if(q.empty()) cout<<"-1"<<'\n';
            else
                cout<<q.front()<<'\n';
        }
        else if(k=="back"){
            if(q.empty()) cout<<"-1"<<'\n';
            else
                cout<<q.back()<<'\n';
        }
        else if(k=="size"){
            cout<<q.size()<<'\n';
        }
        else if(k=="pop"){
            if(q.empty()) cout<<"-1"<<'\n';
            else{
                int num=q.front();
                q.pop();
                cout<<num<<'\n';
            }
        }
        else if(k=="empty"){
            if(q.empty()) cout<<'1'<<'\n';
            else cout<<'0'<<'\n';
        }
    }
    return 0;
}