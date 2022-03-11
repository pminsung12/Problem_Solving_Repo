#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define MAX 1001
using namespace std;

int N,M;
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int tmt[1001][1001];
// bool visited[1001][1001];
// int level[1001][1001];
queue<pair<int,int>> q;

void bfs(){
    while(!q.empty()){
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        for(int k=0;k<4;k++){
            int new_x=x+dx[k];
            int new_y=y+dy[k];
            
            if(new_x>=0&&new_x<N&&new_y>=0&&new_y<M&&
                tmt[new_x][new_y]==0){
                tmt[new_x][new_y]=tmt[x][y]+1;
                q.push(make_pair(new_x,new_y));
            }
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>M>>N;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>tmt[i][j];
            if(tmt[i][j]==1) q.push(make_pair(i,j));
        }
    }
    bfs();

    // for(int i=0;i<N;i++){
    //     for(int j=0;j<M;j++){
    //         cout<<tmt[i][j]<<' ';
    //     }
    //     cout<<'\n';
    // }
    int max=0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(tmt[i][j]==0){
                cout<<"-1"<<'\n';
                return 0;
            }
            if(max<tmt[i][j]) max=tmt[i][j];
        }
    }
    
    cout<<max-1<<'\n';            
    return 0;
}