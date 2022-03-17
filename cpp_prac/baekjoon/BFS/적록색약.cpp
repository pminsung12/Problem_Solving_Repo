#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
#define MAX 101

int N;
bool visited[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};

bool isValid(int x,int y){
    return x>=0&&x<N&&y>=0&&y<N&&!visited[x][y];
}

int bfs(char color[MAX][MAX]){
    int cnt=0;
    queue<pair<int,int>> q;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(!visited[i][j]){
                cnt++;
                char temp=color[i][j];
                
                q.push(make_pair(i,j));
                visited[i][j]=true;
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(isValid(nx,ny)&&color[nx][ny]==temp){
                            visited[nx][ny]=true;
                            q.push(make_pair(nx,ny));
                        }
                    }
                }
            }
        }
    }
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin>>N;
    string a;

    char color[MAX][MAX];//r g b
    char xcolor[MAX][MAX];//r b
    for(int i=0;i<N;i++){  
        cin>>a;
        color[i]=a;
        for(int j=0;j<N;j++){
            color[i][j]=a[j]
            if(a[j]=='G'){
                xcolor[i][j]='R';
            }
        }
    }
    int res=bfs(color);
    cout<<res<<'\n';
    res=bfs(xcolor);
    cout<<res<<'\n';

    return 0;
}