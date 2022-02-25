//dp
#include <iostream>
#include <vector>
using namespace std;

int main(){

    int N;
    cin>>N;
    vector<int> dp(1000001,0);
    dp[2]=1;
    dp[3]=1;
    dp[4]=2;
    for(int i=2;i<=N;i++){
        if(i%3!=0 &&i%2!=0){//2와3 모두 나누어 떨어지지 않는 경우
            dp[i]=1+dp[i-1];
        }
        else if(i%3==0&&i%2==0){//2와 3으로 모두 나누어 떨어지는 경우
            dp[i]=min(1+dp[i/3], 1+dp[i/2]);
        }
        else if(i%2==0){//2로만 나누어 떨어지는 경우
            dp[i]=min(1+dp[i/2],1+dp[i-1]);
        }
        else if(i%3==0){//3으로만 나누어 떨어지는 경우
            dp[i]=min(1+dp[i/3],1+dp[i-1]);
        }
    }
    printf("%d", dp[N]);
    return 0;
}


/*
1   2   2 1
1   3   3 1
2   4   4 2 1
3   5   5 4 2 1
2   6   6 3 1   6 2 1
3   7   7 6 3 1     7 6 2 1
3   8   8 4 2 1
2   9   9 3 1
3   10  10 9 3 1
4   11  11 10 9 3 1
*/