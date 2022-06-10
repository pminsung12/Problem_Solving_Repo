//+=, -= operator
#include <iostream>
using namespace std;

class Point{
private:
    int xpos,ypos;
public:
    Point(int x=0, int y=0):xpos(x), ypos(y)
    {}
    void ShowPosition() const{
        cout<<'['<<xpos<<", "<<ypos<<']'<<endl;
    }
    Point& operator+=(Point &pos2);
    Point& operator-=(Point &pos2);
};

Point& Point::operator+=(Point &pos2){
    xpos+=pos2.xpos;
    ypos+=pos2.ypos;
    return *this;
}

Point& Point::operator-=(Point &pos2){
    xpos-=pos2.xpos;
    ypos-=pos2.ypos;
    return *this;
}

int main(){
    Point pos1(3,4);
    Point pos2(10,20);
    pos1.ShowPosition();
    pos2.ShowPosition();
    pos1+=pos2;
    cout<<"+= <<";
    pos1.ShowPosition();
    Point pos3=pos1-=pos2;
    cout<<"-= <<";
    pos1.ShowPosition();

}