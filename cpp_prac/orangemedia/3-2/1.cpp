//계산기 프로그램
#include <iostream>
using namespace std;

class Calculator{
private:
    int add_count;
    int div_count;
    int min_count;
    int mult_count;

public:
    void Init();
    double Add(double num1, double num2);
    double Div(double num1, double num2);
    double Min(double num1, double num2);
    double Mult(double num1, double num2);
    void ShowOpCount();
};

void Calculator::Init(){
    add_count=0;
    div_count=0;
    min_count=0;
    mult_count=0;
}

double Calculator::Add(double num1, double num2){
    add_count++;
    return num1+num2;
}

double Calculator::Div(double num1, double num2){
    div_count++;
    return num1/num2;
}

double Calculator::Min(double num1, double num2){
    min_count++;
    return num1-num2;
}

double Calculator::Mult(double num1, double num2){
    mult_count++;
    return num1*num2;
}

void Calculator::ShowOpCount(){
    cout<<"덧셈: "<<add_count<<" 뺄셈: "<<min_count<<" 곱셈: "<<mult_count<<" 나눗셈: "<<div_count<<endl;
}

int main(void){
    Calculator cal;
    cal.Init();
    cout<<"3.2 + 2.4 = "<<cal.Add(3.2, 2.4)<<endl;
    cout<<"3.5 / 1.7 = "<<cal.Div(3.5, 1.7)<<endl;
    cout<<"2.2 - 1.5 = "<<cal.Min(2.2, 1.5)<<endl;
    cout<<"4.9 / 1.2 = "<<cal.Div(4.9, 1.2)<<endl;
    cal.ShowOpCount();
    return 0;
}