//DFS, BFS
#include <iostream>
#include <vector>
#include<algorithm>
#include <stack> //DFS
#include <queue> //BFS
using namespace std;

int N,M,V;

void dfs(int x, vector<int> graph[], bool visited[]){
    stack<int> stk;
    stk.push(x);
    visited[x]=true;
    printf("%d ", x);
    while(!(stk.empty())){
        int current = stk.top();
        stk.pop();
        for(int i=0;i<graph[current].size();i++){
            int next=graph[current][i];
            if(visited[next]==false){
                printf("%d ", next);
                visited[next]=true;
                stk.push(current);
                stk.push(next);
                break;
            }
        }
    }
}

void bfs(int x, vector<int> graph[], bool visited[]){
    queue<int> q;
    q.push(x);
    visited[x]=true;
    while(!q.empty()){
        int current=q.front();
        q.pop();
        printf("%d ", current);
        for(int i=0;i<graph[current].size();i++){
            int next=graph[current][i];
            if(visited[next]==false){
                visited[next]=true;
                q.push(next);
            }
        }
    }
}

int main(){
    cin>>N>>M>>V;
    bool visited[N+1];
    vector<int> graph[N+1];
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
        sort(graph[i].begin(),graph[i].end());
    }
    dfs(V,graph,visited);
    printf("\n");
    fill(visited, visited+N+1,false);
    bfs(V,graph,visited);
    printf("\n");

    return 0;
}