#include <iostream>
using namespace std;

int n;
int cnt=1;
int arr[n+1][n+1];
int cutting(int x,int y,int size){//한변의길이
    // int a=n-x;
    // int b=n-y;
    for(int i=x;i<size;i++){
        for(int j=y;j<size;j++){
            if(arr[x][y]!=arr[x+1][y+1]){
                cnt+=3;
                cutting(x,y,size/2);
                cutting(x+y/2,y,size/2);
                cutting(x,y+size/2,size/2);
                cutting(x+size/2,y+size/2,size/2);
            }
        }
    }
    
    return cnt;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n;
    int ans=cutting(0,0,n);
    cout<<ans<<'\n';

    return 0;
}