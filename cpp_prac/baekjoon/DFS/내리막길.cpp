#include <iostream>
using namespace std;
#define MAX 501

int N,M;
int map[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int cnt=0;

bool isValid(int a, int b){
    if(a>=0&&a<N&&b>=0&&b<M) return true;
    return false;
}

void dfs(int x, int y){
    //visited[x][y]=true;
    if(x==N-1&&y==M-1){
        cnt++;
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(isValid(nx,ny)){
            if(map[nx][ny]<map[x][y]){
                visited[nx][ny]=true;
                dfs(nx,ny);
                visited[nx][ny]=false;
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
            cin>>map[i][j];
        }
    }
    visited[0][0]=true;
    dfs(0,0);
    cout<<cnt<<'\n';
    return 0;
}