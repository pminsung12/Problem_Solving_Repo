#include <iostream>
using namespace std;

int M,N,H;
int dx[5]={0,0,-1,1};//상,하,좌,우
int dy[5]={1,-1,0,0};

int solving(int x[][], bool visited[][]){

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //입력
    cin>>M>>N>>H;
    bool visited[N+1][M+1];
    int x[N+1][M+1];
    for(int i=0;i<N;i++){
        for(int j=0;i<M;i++){
            cin>>x[i][j];
        }
    }
    //visited 초기화
    for(int i=0;i<N;i++){
        for(int j=0;i<M;i++){
            visited[i][j]=false;
        }
    }
    int ans=solving(x,visited);
    cout<<ans<<'\n';



    return 0;
}