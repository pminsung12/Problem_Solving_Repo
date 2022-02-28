//dp
#include <iostream>
#include <algorithm>
#define MAX 301
using namespace std;

int main(){
    int st[MAX];//각계단 별 점수
    int dp[MAX];//최댓값

    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>st[i];
    }
    
    dp[1]=st[1];
    dp[2]=st[1]+st[2];
    dp[3]=max(st[1]+st[3],st[2]+st[3]);
    for(int i=4;i<=n;i++){
        dp[i]=max(dp[i-2]+st[i],dp[i-3]+st[i-1]+st[i]);
    }
    cout<<dp[n]<<'\n';
    
    //dp[4]=max(dp[2]+st[4],dp[1]+st[3]+dp[4]);
    //dp[5]=max(dp[3]+st[5],dp[2]+st[4]+st[5]);
    
    return 0;
}