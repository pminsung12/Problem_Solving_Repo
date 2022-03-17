#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 101

int N;
int reg[MAX][MAX];
int copyreg[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int max_val=0,min_val=101;
int cnt=0,res=0;

bool isValid(int x, int y){
    return x>=0&&x<N&&y>=0&&y<N&&!visited[x][y]&&copyreg[x][y]==1;
}

void bfs(){
    cnt=0;
    queue<pair<int,int>> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(copyreg[i][j]&&!visited[i][j]){
                q.push(make_pair(i,j));
                visited[i][j]=true;
                cnt++;
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for (int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(isValid(nx,ny)){
                            visited[nx][ny]=true;
                            q.push(make_pair(nx,ny));
                        }
                    }
                }
            }

        }
    }         
    
}



void solve(){
    for(int k=min_val-1;k<=max_val;k++){
        for(int i=0;i<N;i++){
            for(int j=0;j<N;j++){
                if(reg[i][j]<=k){
                    copyreg[i][j]=0;
                }
                else{
                    copyreg[i][j]=1;
                }
            }
        }
        bfs();
        res=max(cnt,res);
        memset(visited,false,sizeof(visited));
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    int a;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>a;  
            reg[i][j]=a;
            max_val=max(a,max_val);
            min_val=min(a,min_val);
        }
    }
    solve();
    cout<<res<<'\n';

    return 0;
}