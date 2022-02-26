#include <iostream>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
	string s,t;
    cin>>s>>t;

    bool chk[s.length()+1]={0,};
    int c[27]={0,};
    int cnt=0;
    int j=0;
    for(int i=0;i<s.length();i++){ 
        if(s[i]==t[j]&&chk[i]==false){
            chk[i]=true;//한번 쓴다.
            c[j]=i;
            if(j==t.length()-1) {//만들었을 때
                cnt++;
                j=-1;
                continue;
            }
            j++;
            i=c[j];
        }
    }
    cout<<cnt<<'\n';
    return 0;
}

