#include <iostream>
#include <cstring>
using namespace std;
#define MAX 301

int N,M;
int glacier[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

void dfs(int x, int y){
    visited[x][y]=true;
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=1&&nx<N-1&&ny>=1&&ny<M-1&&glacier[nx][ny]!=0&&!visited[nx][ny]){
            dfs(nx,ny);
        }
    }
}

void melting(){
    int copied[MAX][MAX];
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            copied[i][j]=glacier[i][j];
        }
    }
    for(int i=1;i<N-1;i++){
        for(int j=1;j<M-1;j++){
            int cnt=0;
            if(copied[i][j]>0){
                for(int k=0;k<4;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(copied[nx][ny]==0) cnt++;
                }
                glacier[i][j]-=cnt;
                if(glacier[i][j]<0) glacier[i][j]=0;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>glacier[i][j];
        }
    }
    int year=0;
    while(1){
        int glacier_cnt=0;
        bool chk=false;
        memset(visited,false,sizeof(visited));
        for(int i=1;i<N-1;i++){
            for(int j=1;j<M-1;j++){
                if(glacier[i][j]>0 && !visited[i][j]){
                    glacier_cnt++;
                    cout<<glacier_cnt<<'\n';
                    if(glacier_cnt==2){
                        chk=true;
                        break;
                    }
                    dfs(i,j);
                }
                
            }
        }
        if(chk) break;
        if(glacier_cnt==0){
            cout<<'0'<<'\n';
            return 0;
        }
        melting();
        year++;
    }
    cout<<year<<'\n';
    return 0;
}