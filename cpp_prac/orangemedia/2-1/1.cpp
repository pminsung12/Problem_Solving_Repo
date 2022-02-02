#include <iostream>

using namespace std;

void plusOne(int& num){
    num++;
}

void changeSign(int& num){
    num=num-2*num;
}

int main(){
    int a=5;
    
    plusOne(a);
    cout<<"a: "<<a<<endl;
    changeSign(a);
    cout<<"a: "<<a<<endl;
    return 0;
}