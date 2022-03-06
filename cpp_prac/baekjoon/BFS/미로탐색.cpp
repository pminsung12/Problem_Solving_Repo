#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
int N,M;
int cnt=0;


int solving(int a, int b,vector<char> graph[N]){
    cnt++;
    if(a==N-1 && b== M-1){
        return cnt;
    }
    //오른쪽으로
    if(graph[a][b+1]=='1'){
        
        cnt+=solving(a,b+1,graph);
    }
    //아래로
    if(graph[a+1][b]=='1'){
        int res=solving(a+1,b,graph);
        cnt=min(cnt,res);
    }
    //위로
    else if(graph[a-1][b]=='1'){
        int res=solving(a-1,b,graph);
        cnt=min(cnt,res);
    }
    //왼쪽으로
    else if(graph[a][b-1]=='1'){
        int res=solving(a,b-1,graph);
        cnt=min(cnt,res);
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    string s[N=1];
    vector<char> graph[N];
    
    for(int i=0;i<N;i++){
        cin>>s[i];
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            graph[i][j]=s[i][j];
        }
    }

    int ans=solving(0,0,graph);
    cout<<ans<<'\n';
                
    return 0;
}