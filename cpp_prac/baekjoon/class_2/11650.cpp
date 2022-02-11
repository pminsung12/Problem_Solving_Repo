//vector, pair
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;

    pair<int,int> tmp;
    vector<pair<int,int>> v;
    for(int i=0;i<N;i++){
        cin>>tmp.first>>tmp.second;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for(int i=0;i<N;i++){
        cout<<v[i].first<<' '<<v[i].second<<'\n';
    }

    return 0;
}