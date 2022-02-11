//deque
#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int main(){
    int N,K;
    cin>>N>>K;
    deque<int> dq;
    vector<int> v;
    for(int i=1;i<=N;i++){
        dq.push_back(i);
    }


    while(1){
        if(dq.empty()) break;
        for(int i=0;i<K-1;i++){
            dq.push_back(dq.front());
            dq.pop_front();
        }

        v.push_back(dq.front());
        dq.pop_front();
    }

    cout<<'<';
    for(int i=0;i<N-1;i++){
        cout<<v[i]<<", ";
    }
    cout<<v[N-1]<<'>'<<'\n';
    return 0;
}