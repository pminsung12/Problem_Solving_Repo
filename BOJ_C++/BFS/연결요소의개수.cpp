#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N,M;
bool visited[1001];
vector<int> graph[1001];
queue<int> q;

void bfs(int a){
    q.push(a);
    visited[a]=true;
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        for(int i=0;i<graph[cur].size();i++){
            int ne=graph[cur][i];
            if(!visited[ne]){
                visited[ne]=true;
                q.push(ne);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    int u,v;
    for(int i=0;i<M;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int cnt=0;
    for(int i=1;i<=N;i++){
        if(!visited[i]){
            bfs(i);
            cnt++;
        }
    }
    cout<<cnt<<'\n';

    return 0;
}