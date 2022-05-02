#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    int dp[1001];
    dp[1]=1;
    dp[2]=2;
    cin>>n;

    for(int i=3;i<=n;i++){
        dp[i]=(dp[i-1]+dp[i-2])%10007;
    }
    cout<<dp[n]<<'\n';
    return 0;
}

// 3 3  4 5      5 8      6 13  21  34   55
// 111 1111    11111   111111
// 12  121     1211    12111
// 21  211     2111    21111
//     22      221     2211               
//     112     1112    11121
//             122     1221
//             212     2121
//             1121    11112
//                     1212
//                     2112
//                     222
//                     11211
//                     1122         1+6+10+4   1+7+ 15+ 10+1