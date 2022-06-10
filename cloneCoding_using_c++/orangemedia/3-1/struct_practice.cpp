//구조체 안에 함수 넣는 연습, 안에 넣어도 되고 밖에 빼는게 더 좋을듯
#include <iostream>
using namespace std;

struct Point
{
    int xpos;
    int ypos;
    void MovePos(int x, int y);
    void AddPoint(const Point &pos);
    void ShowPosition();
};

int main() {
    Point pos1 = {12,4};
    Point pos2 = {20,30};
    
    pos1.MovePos(-7, 10);
    pos1.ShowPosition();
    
    pos1.AddPoint(pos2);
    pos1.ShowPosition();
    
    return 0;
}

void Point::MovePos(int x, int y){
        xpos += x;
        ypos += y;
}
void Point::AddPoint(const Point &pos){
    xpos += pos.xpos;
    ypos += pos.ypos;
}
void Point::ShowPosition(){
    cout<<"x: "<<xpos<<endl;
    cout<<"y: "<<ypos<<endl;
}