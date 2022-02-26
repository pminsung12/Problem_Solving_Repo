#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int N,M;
vector<int> v;
bool bfs(int x, vector<int> graph[], bool visited[]){
    queue<int> q;
    q.push(x);
    visited[x]=true;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        v.push_back(current);
        for(int i=0;i<graph[current].size();i++){
            int next=graph[current][i];
            if(visited[next]==false){
                visited[next]=true;
                q.push(next);
            }
        }
    }
    if(v.size()==N) return true;
    return false;
}

int main(){
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    cin>>N>>M;
    bool visited[N+1];
    vector<int> graph[N+1];
    int cnt=0;
    fill(visited, visited+N+1,false);
    for(int i=0;i<N+1;i++){
        graph[i].clear();
    }
    for(int i=0;i<M;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i=1;i<=N;i++){
        if(bfs(i,graph,visited)) cnt++;
        fill(visited, visited+N+1,false);
    }
    cout<<cnt<<'\n';



    return 0;
}