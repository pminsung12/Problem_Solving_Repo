#include <iostream>

using namespace std;

int main(){
    const int num=12;
    const int* a = &num;
    cout<<"num의 포인터 a: "<<*a<<endl;
    const int *(&b)= a;
    cout<<"a의 참조자 b: "<<*b<<endl;
    return 0;
}