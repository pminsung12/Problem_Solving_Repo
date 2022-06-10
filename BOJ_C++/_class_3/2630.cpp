#include <iostream>
using namespace std;

int n;
int blue=0,white=0;
int arr[129][129];
void cutting(int x,int y,int size){//한변의길이
    int chk=0;
    int dontcount=0;
    int a=arr[x][y];
    //cout<<'('<<x<<','<<y<<','<<size<<')'<<' ';
    for(int i=x;i<x+size;i++){
        for(int j=y;j<y+size;j++){
            if(arr[i][j]!=a){
                chk=1;
                dontcount=1;
                //cout<<'\n'<<x<<','<<y<<','<<size/2;
                cutting(x,y,size/2);
                
                //cout<<'\n'<<x+size/2<<','<<y<<','<<size/2;
                cutting(x+size/2,y,size/2);
                
                //cout<<'\n'<<x<<','<<y+size/2<<','<<size/2;
                cutting(x,y+size/2,size/2);
                
                //cout<<'\n'<<x+size/2<<','<<y+size/2<<','<<size/2;
                cutting(x+size/2,y+size/2,size/2);
                
                break;
            }
            a=arr[i][j];
        }
        if(chk) break;
    }
    if(!dontcount){
        if(arr[x][y]==1) blue++;
        else white++;    
    }
    
    
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>arr[j][i];
        }
    }

    cutting(0,0,n);
    cout<<white<<'\n'<<blue<<'\n';

    return 0;
}