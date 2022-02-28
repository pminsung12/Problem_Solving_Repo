//이진탐색
#include <iostream>
#include <algorithm>
using namespace std;

void BinarySearch(int num, int arr[], int N){
    int top=N-1, bottom=0;
    int mid;
    while(top>=bottom){
        mid=(top+bottom)/2;
        if(arr[mid]==num){
            cout<<"1"<<'\n';
            return;
        }
        else if(arr[mid]<num) bottom = mid+1;
        else if(arr[mid]>num) top = mid-1;
    }
    cout<<'0'<<'\n';
    return;
}

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int N;
    cin>>N;

    int arr[N];
    for(int i=0;i<N;i++) cin>>arr[i];
    sort(arr, arr+N);
    int M;
    cin>>M;

    int arr2[M];
    for(int i=0;i<M;i++) {
        cin>>arr2[i];
        BinarySearch(arr2[i], arr, N);
    }

    return 0;
}