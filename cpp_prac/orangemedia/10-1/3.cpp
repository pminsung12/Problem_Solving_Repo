//==, != operator
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

    friend bool operator==(Point &pos1, Point &pos2);
    friend bool operator!=(Point &pos1, Point &pos2);
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

bool operator==(Point &pos1, Point &pos2){
    if(pos1.xpos==pos2.xpos && pos1.ypos==pos2.ypos) return true;
    return false;
}
bool operator!=(Point &pos1, Point &pos2){
    if(pos1.xpos==pos2.xpos && pos1.ypos==pos2.ypos) return false;
    return true;
}

int main(){
    Point pos1(3,4);
    Point pos2(6,8);
    pos1.ShowPosition();
    pos2.ShowPosition();
    cout<<"+= <<";
    (pos1+=pos2).ShowPosition();

    cout<<"-= <<";
    (pos1-=pos2).ShowPosition();
    
    if(pos1==pos2) cout<<"true"<<endl;
    else cout<<"false"<<endl;
    
    if(pos1!=pos2) cout<<"false"<<endl;
    else cout<<"true"<<endl;
    return 0;
    

}