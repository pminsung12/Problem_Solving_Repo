#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int N,M;
    cin>>N;
    vector<int> arr;

    for(int i=0;i<N;i++){
        int num;
        cin>>num;
        arr.push_back(num);
    }
    sort(arr.begin(), arr.end());
    cin>>M;
    for(int i=0;i<M;i++){
        int num;
        cin>>num;
        int answer = upper_bound(arr.begin(), arr.end(),num)-lower_bound(arr.begin(), arr.end(),num);
        cout<<answer<<" ";
    }
    return 0;
}