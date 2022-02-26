#include <iostream>
#include <vector>
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    int N,a;
    int chk=0;
    vector<int> v;
    cin>>N;
    for(int i=0;i<N;i++){
        cin>>a;
        v.push_back(a);
    }
    int cnt=0;
    for(int i=0;i<N-1;i++){
        chk=0;
        if(v[i]==v[i+1]){
            cnt++;
        }
        else{
            for(int j=0;j<cnt+1;j++){
                cout<<i+2<<' ';
            }
            cnt=0;
        }
    }
    cout<<"-1"<<' ';
    if(cnt!=0) {
        for(int i=0;i<cnt;i++){
            cout<<"-1"<<' ';
        }
        
    }
    return 0;
}