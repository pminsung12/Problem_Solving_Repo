<<<<<<< HEAD
//이문제는 bfs로 풀어야함. dfs로 풀면 모든 탐색을 다해야하는데 
//시간초과가 나올 수 밖에 없음.
#include <iostream>
using namespace std;
#define MAX 101

int N,M;
int map[MAX][MAX];
//int cnt[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int min_value=10001;

void dfs(int x, int y,int dist){
    
    if(x==N-1&&y==M-1){
        if(min_value>dist) min_value=dist;
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<100&&ny>=0&&ny<100&&map[nx][ny]&&!visited[nx][ny]){
            //cnt[nx][ny]=cnt[x][y]+1;
            visited[x][y]=true;
            dfs(nx,ny,dist+1);
            visited[x][y]=false;//완전 탐색을 위해
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    string s;
    for(int i=0;i<N;i++){
        cin>>s;
        for(int j=0;j<M;j++){
            map[i][j]=s[j]-'0';
        }
    }
    dfs(0,0,1);
    cout<<min_value<<'\n';

    return 0;
=======
//이문제는 bfs로 풀어야함. dfs로 풀면 모든 탐색을 다해야하는데 
//시간초과가 나올 수 밖에 없음.
#include <iostream>
using namespace std;
#define MAX 101

int N,M;
int map[MAX][MAX];
//int cnt[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int min_value=10001;

void dfs(int x, int y,int dist){
    
    if(x==N-1&&y==M-1){
        if(min_value>dist) min_value=dist;
        return;
    }
    for(int i=0;i<4;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
        if(nx>=0&&nx<100&&ny>=0&&ny<100&&map[nx][ny]&&!visited[nx][ny]){
            //cnt[nx][ny]=cnt[x][y]+1;
            visited[x][y]=true;
            dfs(nx,ny,dist+1);
            visited[x][y]=false;//완전 탐색을 위해
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N>>M;
    string s;
    for(int i=0;i<N;i++){
        cin>>s;
        for(int j=0;j<M;j++){
            map[i][j]=s[j]-'0';
        }
    }
    dfs(0,0,1);
    cout<<min_value<<'\n';

    return 0;
>>>>>>> solved
}