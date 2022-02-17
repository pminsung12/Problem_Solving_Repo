//map
#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;

pair<string,int> p;
map<string,int> m;
string str[100001];
int N,M;
string s;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>N>>M;
	for(int i=1;i<=N;i++){
	    cin>>s;
	    m.insert(make_pair(s,i));
	    str[i]=s;
	}
	for(int i=1;i<=M;i++){
	    cin>>s;
	    if (!isdigit(s[0])){//string
	        auto it=m.find(s);
	        cout<<it->second<<'\n';
	    }
	    else {//숫자
	        int  t=stoi(s);
	        cout<<str[t]<<'\n';
	    }
	}
	return 0;	
}