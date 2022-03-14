/*
    다시한번 풀어보자...

*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int N,M,ans;
int board[8][8], copied[8][8];
bool checked[8][8];
const int dy[4]={-1,1,0,0};
const int dx[4]={0,0,-1,1};



vector<pair<int,int>> virus;

// 안전지역 카운트
int cntZero(){
    int ret=0;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            if(copied[i][j]==0)
                ++ret;
    return ret;
}

// 좌표 유효성 검사
bool isValid(int y, int x){
    return y>=0 && x>=0 && y<N && x<M && copied[y][x]==0;
}

// BFS 탐색
void virusBFS(){
    memset(checked,false,sizeof(checked));

    queue<pair<int,int>> q;
    for(int i=0;i<virus.size();i++){
        checked[virus[i].first][virus[i].second]=true;
        q.push(make_pair(virus[i].first,virus[i].second));
    }

    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            copied[i][j]=board[i][j];

    while(!q.empty()){
        int x = q.front().first;
        int y= q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int ny = x+dy[i];
            int nx = y+dx[i];
            if(isValid(ny,nx) && !checked[ny][nx]){
                copied[ny][nx]=2;
                checked[ny][nx]=true;
                q.push(make_pair(ny,nx));
            }
        }
    }
}

// 벽 세우기 백트래킹
void setWall(int n){
    // 3개를 모두 세우면 전파 시작 및 최댓값 갱신
    if(n==3){
        virusBFS();
        ans = max(ans, cntZero());
        return;
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(board[i][j]==0){
                board[i][j]=1;
                setWall(n+1);
                board[i][j]=0;
            }
        }
    }
}

int main(){
    cin>>N>>M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>board[i][j];
            if(board[i][j]==2)
                virus.push_back(make_pair(i,j));
        }
    }

    setWall(0);

    cout<<ans;

    return 0;
}