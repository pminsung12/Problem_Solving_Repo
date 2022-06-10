<<<<<<< HEAD
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 26
int N;
int house[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int cnt;
int count_house[313];

void dfs(int x,int y){
    visited[x][y]=true;
    count_house[cnt-1]++;
    for(int k=0;k<4;k++){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(!visited[nx][ny]&&nx>=0&&nx<N&&ny>=0&&ny<N&&house[nx][ny]==1){
            dfs(nx,ny);
        }
    }
}

void solve(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(house[i][j]==1&&!visited[i][j]){
                cnt++;
                dfs(i,j);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;

    string s;
    for(int i=0;i<N;i++){
        cin>>s;
        for(int j=0;j<N;j++){
            house[i][j]=s[j]-'0';
        }
    }
    solve();
    sort(count_house,count_house+cnt);
    cout<<cnt<<'\n';
    for(int i=0;i<cnt;i++){
        cout<<count_house[i]<<'\n';
    }

    return 0;
=======
#include <iostream>
#include <algorithm>
using namespace std;
#define MAX 26
int N;
int house[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
int cnt;
int count_house[313];

void dfs(int x,int y){
    visited[x][y]=true;
    count_house[cnt-1]++;
    for(int k=0;k<4;k++){
        int nx=x+dx[k];
        int ny=y+dy[k];
        if(!visited[nx][ny]&&nx>=0&&nx<N&&ny>=0&&ny<N&&house[nx][ny]==1){
            dfs(nx,ny);
        }
    }
}

void solve(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(house[i][j]==1&&!visited[i][j]){
                cnt++;
                dfs(i,j);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;

    string s;
    for(int i=0;i<N;i++){
        cin>>s;
        for(int j=0;j<N;j++){
            house[i][j]=s[j]-'0';
        }
    }
    solve();
    sort(count_house,count_house+cnt);
    cout<<cnt<<'\n';
    for(int i=0;i<cnt;i++){
        cout<<count_house[i]<<'\n';
    }

    return 0;
>>>>>>> solved
}