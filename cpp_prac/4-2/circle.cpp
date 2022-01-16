//캡슐화!!
#include <iostream>
using namespace std;

class Point{
private:
    int xpos;
    int ypos;
public:
    void Init(int x, int y){
        xpos = x;
        ypos = y;
    }/*
    int getX() const{
        return xpos;
    }
    int getY() const{
        return ypos;
    }*/
    void ShowPointInfo() const {
        cout<<"["<<xpos<<", "<<ypos<<"]"<<endl;
    }
};

class Circle{
private:
    Point p1;
    int radius;
public:
    void Init(int x, int y, int r){
        p1.Init(x, y);
        radius=r;
    }
    /*int getX() const{
        return p1.getX();
    }
    int getY() const{
        return p1.getY();
    }
    int getR() const{
        return radius;
    }*/
    void ShowCircleInfo() const{
        cout<<"반지름: "<<radius<<endl;
        p1.ShowPointInfo();
    }
};

class Ring{
private:
    Circle c1;
    Circle c2;
public:
    void Init(int x1,int y1, int r1, int x2, int y2, int r2){
        c1.Init(x1, y1, r1);
        c2.Init(x2, y2, r2);
    }
    void ShowRingInfo() const {
        cout<<"Inner Circle Info..."<<endl;
        c1.ShowCircleInfo();
        cout<<"Outer Circle Info..."<<endl;
        c2.ShowCircleInfo();
    }
};

int main(){
    Ring ring;
    ring.Init(1,1,4,2,2,9);
    ring.ShowRingInfo();
    return 0;
}