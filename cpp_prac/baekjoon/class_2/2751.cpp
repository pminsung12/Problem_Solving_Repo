//수 정렬하기 2
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int N;
    cin>>N;

    int arr[N+1];
    for(int i=0;i<N;i++){
        cin>>arr[i];
    }
    sort(arr, arr+N+1);
    for(int i=0;i<N;i++){
        cout<<arr[i]<<'\n';
    }
    return 0;
}