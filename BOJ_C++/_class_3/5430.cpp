#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,n;
    string p,arr;
    
    deque<int> dq;
    cin>>T;
    for(int i=0;i<T;i++){
        bool reverse =false;
    	bool error=false;
        dq.clear();
        cin>>p>>n>>arr;
        string temp;
        //배열 저장
        for(int j=0;j<arr.length();j++){
            if(arr[j]=='[') continue;
            else if(arr[j]>='0'&&arr[j]<='9') temp+=arr[j];
            else if(arr[j]==','||arr[j]==']'){
                if(!temp.empty()){
                    dq.push_back(stoi(temp));
                    temp.clear();
                }
            }
        }
        //명령어 수행
        for(int k=0;k<p.length();k++){
            // if(p[k]=='R'&&p[k+1]=='R'){
            //     k++;
            //     continue;
            // }
            if(p[k]=='R') {
                reverse = !reverse;
            }
            else if(p[k]=='D') {
                if(dq.empty()){
                    cout<<"error"<<'\n';
                    error=true;
                    break;
                }
                else {
                    if(reverse) dq.pop_back();
                    else dq.pop_front();
                }
            }
        }
        if(error) continue;
        else{
            cout<<'[';
            if(!reverse){
                for(int m=0;m<dq.size();m++){
                    if(m==dq.size()-1) cout<<dq[m];
                    else cout<<dq[m]<<',';
                }
                
            }
            else{
                for(int n=dq.size()-1;n>=0;n--){
                    if(n==0) cout<<dq[n];
                    else cout<<dq[n]<<',';
                }
            }
            cout<<']'<<'\n';
        }
    }
    return 0;
}