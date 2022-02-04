#include <iostream>
#include <algorithm>
using namespace std;
bool compare(string a, string b){
    if(a.length()==b.length())
        return a<b;
    return a.length()<b.length();
}
string word[20000];

int main(){
    int N;
    cin>>N;

    for(int i=0;i<N;i++){
        cin>>word[i];
    }
    sort(word, word+N,compare);

    for(int i=0;i<N;i++){
        if(word[i]==word[i-1]) continue;
        cout<<word[i]<<endl;
        
    }
    return 0;
}