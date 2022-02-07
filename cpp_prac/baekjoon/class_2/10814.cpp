#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int,string> a,pair<int,string> b){
    return a.first<b.first;
}

int main(){
    int N;
    cin>>N;
    pair<int,string> tmp;
    vector<pair<int,string>> arr;
    for(int i=0;i<N;i++){
        cin>>tmp.first>>tmp.second;
        arr.push_back(tmp);
    }
    stable_sort(tmp.begin(),tmp.end(), cmp);
    for(int i=0;i<N;i++){
        cout<<arr[i].first()<<' '<<arr[i].second<<'\n';
    }
    return 0;
}