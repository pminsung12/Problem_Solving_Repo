#include <iostream>
#include <queue>
using namespace std;

int T,M,N,K;
int dx[]={-1,1,0,0};//xy묶어서 좌 우 상 하
int dy[]={0,0,-1,1};

void BFS(int G[50][50], int y, int x){//배추있는 곳
    queue<pair<int,int>> q;
    q.push(make_pair(y,x));//배추 위치에 대한 queue
    while(!q.empty()){
        int cur_x=q.front().first;
        int cur_y=q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nx=cur_x+dx[i];
            int ny=cur_y+dy[i];

            if(nx<0||nx>=N||ny<0||ny>=M) continue;
            if(G[nx][ny]==0) continue;
            if(G[nx][ny]==1){//인접한 곳에 배추가 있다면
                G[nx][ny]=0;//배추를 싹다 없애버려!
                q.push(make_pair(nx,ny));
            }
        }
    }
}

int main(){
    scanf("%d", &T);
    for(int i=0;i<T;i++){
        scanf("%d %d %d", &M,&N,&K);
        int G[50][50]={0,};
        for(int j=0;j<K;j++){
            int m,n;
            scanf("%d %d", &m, &n);
            G[n][m]=1;//배추 있는 곳은 1
        }

        int cnt=0;
        for(int m=0;m<M;m++){
            for(int n=0;n<N;n++){
                if(G[y][x]==0) continue;//배추 없는 곳 제외
                else{
                    BFS(G,y,x)//배추 있는 곳 검사
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}