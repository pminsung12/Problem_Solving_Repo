//난수 생성기 0이상 100이하 5개
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main(void){
    srand(time(NULL));
    for(int i=0;i<5;i++){
        int random = rand()%100;
        cout<<random<<endl;
    }
    return 0;
}