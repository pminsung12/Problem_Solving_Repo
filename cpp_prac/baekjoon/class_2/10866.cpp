#include <iostream>
#include <deque>
#include <cstdio>
using namespace std;

int main(){
    int N;
    cin>>N;
    cin.ignore();
    deque<int> dq;
    string k;
    
    for(int i=0;i<N;i++){
        getline(cin,k,'\n');
        if(k[5]=='b'){
            string sub = k.substr(10, k.length()-9);
            int n=stoi(sub);
            dq.push_back(n);
        }
        else if(k[5]=='f'){
            string sub = k.substr(10, k.length()-9);
            int n=stoi(sub);
            dq.push_front(n);
        }
        else if(k=="empty"){
            if(dq.empty()) cout<<'1'<<'\n';
            else cout<<'0'<<'\n';
        }
        else if(k=="front"){
            if(dq.empty()) cout<<"-1"<<'\n';
            else
                cout<<dq.front()<<'\n';
        }
        else if(k=="back"){
            if(dq.empty()) cout<<"-1"<<'\n';
            else
                cout<<dq.back()<<'\n';
        }
        else if(k=="size"){
            cout<<dq.size()<<'\n';
        }
        else if(k[7]=='k'){//pop_back()
            if(dq.empty()) cout<<"-1"<<'\n';
            else{
                int num=dq.back();
                dq.pop_back();
                cout<<num<<'\n';
            }
        }
        else if(k[6]== 'o'&& k[7]=='n'){//pop_front
            if(dq.empty()) cout<<"-1"<<'\n';
            else{
                int num=dq.front();
                dq.pop_front();
                cout<<num<<'\n';
            }
        }
        else{
            cout<<"error happened"<<'\n';
        }
        
    }
    return 0;
}