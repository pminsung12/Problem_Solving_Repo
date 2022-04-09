#include <iostream>
#include <vector>
using namespace std;

int N,M,cnt=0;
bool visited[101];
void dfs(int n,vector<int> graph[]){
    visited[n]=true;
    for(int i=0;i<graph[n].size();i++){
        int x=graph[n][i];
        if(!visited[x]) {
            cnt++;
            dfs(x,graph);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    int u,v;
    vector<int> graph[N+1];
    for(int i=0;i<N+1;i++){
        graph[i].clear();
    }

    for(int i=0;i<M;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    dfs(1,graph);
    cout<<cnt<<'\n';
    return 0;
}