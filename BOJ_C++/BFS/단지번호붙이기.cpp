#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#define MAX 26
using namespace std;

int N;
int house[MAX][MAX];
bool visited[MAX][MAX];
int dx[4]={0,0,-1,1};
int dy[4]={1,-1,0,0};
queue<pair<int,int>> q;
int count_house[313];//단지별 집 수
int cnt=0;//전체 단지 수

void bfs(){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            if(house[i][j]&&!visited[i][j]){
                q.push(make_pair(i,j));
                visited[i][j]=true;
                count_house[cnt]++;
                cnt++;
                while(!q.empty()){
                    int x=q.front().first;
                    int y=q.front().second;
                    q.pop();
                    for(int i=0;i<4;i++){
                        int new_x=x+dx[i];
                        int new_y=y+dy[i];
                        if(new_x>=0&&new_x<N&&new_y>=0&&new_y<N&&
                            !visited[new_x][new_y]&&house[new_x][new_y]){
                            q.push(make_pair(new_x,new_y));
                            visited[new_x][new_y]=true;
                            count_house[cnt-1]++;
                        }
                    }
                }
            }
        }
    }
    return;
    
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>N;
    for(int i=0;i<N;i++){
        string s;
        cin>>s;
        for(int j=0;j<N;j++){
            house[i][j]=s[j]-'0';
        }
    }
    bfs();
    sort(count_house,count_house+cnt);
    cout<<cnt<<'\n';
    for(int i=0;i<cnt;i++){
        cout<<count_house[i]<<'\n';
    }


    return 0;
}