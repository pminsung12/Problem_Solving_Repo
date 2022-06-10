#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 51

int w,h;
int land[MAX][MAX];
bool visited[MAX][MAX];
int dx[8]={0,0,-1,1,-1,-1,1,1};
int dy[8]={1,-1,0,0,1,-1,1,-1};
int cnt=0;

bool isValid(int x, int y){
    return x>=0&&x<h&&y>=0&&y<w&&!visited[x][y]&&land[x][y]==1;
}

void bfs(){
    queue<pair<int,int>> q;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(land[i][j]&&!visited[i][j]){
                q.push(make_pair(i,j));
                visited[i][j]=true;
                cnt++;
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for (int k=0;k<8;k++){
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

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    while(1){
        cnt=0;
        memset(visited,false,sizeof(visited));
        cin>>w>>h;
        if(w==0&&h==0) break;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                cin>>land[i][j];
            }
        }
        bfs();
        cout<<cnt<<'\n';
    }
    return 0;
}