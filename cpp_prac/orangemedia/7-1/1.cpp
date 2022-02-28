//상속과 생성자의 호출
#include <iostream>
using namespace std;

class Car{
private:
    int gasolineGauge;
public:
    Car(int gaso):gasolineGauge(gaso){}
    int GetGasGauge() {return gasolineGauge;}
};

class HybridCar: public Car{
private:
    int electricGauge;
public:
    HybridCar(int gaso, int elec):Car(gaso), electricGauge(elec){}
    int GetElecGauge() {return electricGauge;}
};

class HybridWaterCar:public HybridCar{
private:
    int waterGauge;
public:
    HybridWaterCar(int gaso, int elec, int water):HybridCar(gaso, elec), waterGauge(water){}
    void ShowCurrentGauge(){
        cout<<"잔여 가솔린: "<<GetGasGauge()<<endl;
        cout<<"잔여 전기량: "<<GetElecGauge()<<endl;
        cout<<"잔여 워터량: "<<waterGauge<<endl;
    }
};

int main(){
    HybridWaterCar h1(20,30,50);
    h1.ShowCurrentGauge();
}
