#include <iostream>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    string s;
    while(1){
        getline(cin,s);
        if(s=="") break;
        cout<<s<<endl;
    }
    
    return 0;
}