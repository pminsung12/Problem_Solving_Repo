//좌표끼리 합 출력
#include <iostream>
using namespace std;

typedef struct __Point
{
    int xpos;
    int ypos;
}Point;

Point& PntAdder(const Point &p1, const Point &p2){
    Point *p3=new Point;
    p3->xpos = p1.xpos+p2.xpos;
    p3->ypos = p1.ypos+p2.ypos;
    
    return *p3;
}

int main() {
    Point *p1 = new Point;
    Point *p2 = new Point;
    p1->xpos = 3;
    p1->ypos = 5;
    p2->xpos = 4;
    p2->ypos = 6;
    
    //Point &cp1 = *p1;
    //Point &cp2 = *p2;
    
    Point &cp3 = PntAdder(cp1, cp2);
    cout<<"["<<cp3.xpos<<","<<cp3.ypos<<"]"<<endl;
    
    delete p1;
    delete p2;
    delete &cp3;
    
    return 0;
}