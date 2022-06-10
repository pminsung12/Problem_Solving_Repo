//풀이1
#include <iostream>
#include <algorithm>
using namespace std;

void checking(string num[], int n){
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            int t=min(num[i].length(),num[j].length());
            for(int k=0;k<t;k++){
                if(num[i][k]!=num[j][k]) break;
                else{
                    if(k==t-1){
                        cout<<"NO"<<'\n';
                        return;
                    }
                }
            }
        }
    }
    cout<<"YES"<<'\n';
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T,n;
    cin>>T;

    string num[10001];
    while(T--){
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>num[i];
        }
        sort(num,num+n);
        checking(num,n);
    }
    return 0;
}
//풀이 2 substr()
/*
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T;
    cin >> T;
    
    string num[10001];
    int n;
    
    while(T--) {
        bool isValid = true;
        cin >> n;
        
        for (int i = 0; i < n; i++) {
            cin >> num[i];
        }
 
        sort(num, num+n);
 
        for (int j = 0; j < n-1; j++) {
            int current = num[j].length();
            int next = num[j+1].length();
 
            if (current >= next) continue;
            if (num[j + 1].substr(0, current)== num[j]) {
                isValid = false;
                cout << "NO" << '\n';
                break;
            }
        }
 
        if (isValid) cout << "YES" << '\n';
    }
    return 0;
}
*/