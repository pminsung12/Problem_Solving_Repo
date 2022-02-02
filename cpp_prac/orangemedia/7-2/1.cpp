//IS-A 관계의 상속
#include <iostream>
using namespace std;

class Rectangle{
private:
    int wid;
    int leng;
public:
    Rectangle(int _wid, int _leng): wid(_wid), leng(_leng){ }
    void showAreaInfo(){
        cout<<"면적: "<<wid*leng<<endl;
    }
};

class Square: public Rectangle{
public:
    Square(int _leng): Rectangle(_leng, _leng){}
    
};

int main() {
    Rectangle rec(4,3);
    rec.showAreaInfo();
    
    Square sqr(7);
    sqr.showAreaInfo();
    return 0;
}