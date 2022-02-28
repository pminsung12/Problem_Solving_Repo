#include <iostream>
using namespace std;

int main(){
    int a[9];
    int chk=0;
    for(int i=0;i<8;i++){
        cin>>a[i];
    }
    for(int i=0;i<7;i++){
        if(a[i]>a[i+1]) chk++;
        else if(a[i]<a[i+1]) chk--;
    }
    if(chk==7) cout<<"descending"<<'\n';
    else if(chk==-7) cout<<"ascending"<<'\n';
    else cout<<"mixed"<<'\n';

    return 0;
}