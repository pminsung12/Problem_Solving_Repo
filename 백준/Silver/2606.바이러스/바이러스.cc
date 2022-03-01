//BFS
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


int bfs(bool visited[], int n, vector<int> graph[],int size){
    int cnt=0;
    queue<int> q;
    visited[n]=true;
    q.push(n);
    //cout<<n<<' ' ;
    while(!q.empty()){
        int current = q.front();
        cnt++;
        q.pop();
        for(int i=0;i<graph[current].size();i++){
            int next = graph[current][i];
            if(visited[next]==false){
                q.push(next);
                visited[next]=true;
            }
        }
    }
    
    return cnt-1;//1제외 
}


int main(){
    int n,m,u,v;
    cin>>n>>m;
    bool visited[n+1];
    fill(visited, visited+n+1,false);

    vector<int> graph[n+1];
    for(int i=0;i<n+1;i++){
        graph[i].clear();
    }

    for(int i=0;i<m;i++){
        cin>>u>>v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    int ans=bfs(visited, 1, graph,n);
    cout<<ans<<'\n';

    return 0;
}