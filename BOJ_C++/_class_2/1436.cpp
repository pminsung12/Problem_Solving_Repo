#include <iostream>
#include <string>
using namespace std;


int main(){
    int a=666,cnt=0,N;
    cin>>N;
    string six;

    while(1){
        six=to_string(a);
        for(int i=0;i<six.length()-2;i++){
            if(six[i]=='6'&&six[i+1]=='6'&&six[i+2]=='6'){
                cnt++;
                if(cnt==N) goto EXIT;
                break;
            }
        }
        a++;
    }
    EXIT:
        cout<<a<<endl;
        return 0;
}