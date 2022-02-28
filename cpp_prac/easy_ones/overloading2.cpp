#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int box_volume(int a,int b, int c){
    return a*b*c;
}

int box_volume(int a, int b){
    return a*b*1;
}

int box_volume(int a){
    return a*1*1;
}

int box_volume(){
    return 1*1*1;
}

int main(){
    cout<<"[3,3,3} : "<<box_volume(3,3,3)<<endl;
    cout<<"[5,5,D} : "<<box_volume(5,5)<<endl;
    cout<<"[7,D,D} : "<<box_volume(7)<<endl;
    cout<<"[D,D,D} : "<<box_volume()<<endl;
    return 0;
}