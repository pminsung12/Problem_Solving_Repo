//0의 개수는 결국 2와 5의 곱이다.
//항상 개수가 적은 5의 개수로 0의 개수가 정해진다.
#include <iostream>
#include <string>
using namespace std;

int fact(int n){
    if(n==0) return 0;
    int cnt=0;
    for(int i=5;i<=n;i*=5){
        cnt+=n/i;
    }
    return cnt;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int N;
    cin>>N;
    cout<<fact(N)<<'\n';

    return 0;
}