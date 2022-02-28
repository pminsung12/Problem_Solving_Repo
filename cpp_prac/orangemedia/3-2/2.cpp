//주어진 문자열 프린트 프로그램
#include <iostream>
#include <cstring>
#define SIZE 100
using namespace std;

class Printer{
private:
    char sentence[SIZE];

public:
    void SetString(char a[]);//char *s
    void ShowString();
};

void Printer::SetString(char a[]){//char *s
    strcpy(sentence, a);
}

void Printer::ShowString(){
    cout<<sentence<<endl;
}


int main(void){
    Printer pnt;
    pnt.SetString("Hello World!");
    pnt.ShowString();
    
    pnt.SetString("I love C++");
    pnt.ShowString();
    return 0;
}