#include <iostream>
#include <cstring>
using namespace std;

class Employee{//추상 클래스(객체 생성이 불가능한 클래스)
private:
    char name[100];
public:
    Employee(char *name){
        strcpy(this->name, name);
    }
    void ShowYourName() const{
        cout<<"name: "<<name<<endl;
    }
    virtual int GetPay() const=0;//순수가상함수:함수의 몸체가 정의되지 않은 함수(Employee 객체 생성을 막음-> 여기서는 기초 클래스로만 역할하기 때문)
    virtual void ShowSalaryInfo() const=0;//순수가상함수
};

class PermanentWorker:public Employee{
private:
    int salary;
public:
    PermanentWorker(char* name, int money):Employee(name), salary(money){}
    int GetPay() const{
        return salary;
    }
    void ShowSalaryInfo() const{
        ShowYourName();
        cout<<"Salary: "<<GetPay()<<endl<<endl;
    }
};

class TemporaryWorker: public Employee{
private:
    int workTime;
    int payPerHour;
public:
    TemporaryWorker(char *name, int pay):Employee(name), workTime(0), payPerHour(pay){}
    void AddWorkTime(int time){
        workTime += time;
    }
    int GetPay() const{
        return workTime*payPerHour;
    }
    void ShowSalaryInfo() const {
        ShowYourName();
        cout<<"Salary: "<<GetPay()<<endl<<endl;
    }
};

class SalesWorker: public PermanentWorker{
private:
    int salesResult;
    double bonusRatio;
public:
    SalesWorker(char *name, int pay, double ratio):PermanentWorker(name, pay), salesResult(0), bonusRatio(ratio){}
    void AddSalesResult(int value){
        salesResult+=value;
    }
    int GetPay() const{
        return PermanentWorker::GetPay()+(int)(salesResult*bonusRatio);
    }
    void ShowSalaryInfo() const {
        ShowYourName();
        cout<<"Salary: "<<GetPay()<<endl<<endl;
    }
};

class EmployeeHandler{
private:
//Employee 객체의 주소 값을 저장하는 방식으로 객체를 저장한다. 따라서 Employee 클래스를 상속하는 클래스의 객체도 이 배열에 함께 저장이 가능하다.
    Employee *empList[50];
    int empNum;
public:
    EmployeeHandler():empNum(0){}
    void AddEmployee(Employee *emp){
        empList[empNum++]=emp;
    }
    void ShowAllSalaryInfo() const{
        
        for(int i=0;i<empNum;i++){
            empList[i]->ShowSalaryInfo();
        }
        
    }
    void ShowTotalSalary() const{
       int sum=0;
       
        for(int i=0;i<empNum;i++){
            sum+=empList[i]->GetPay();
        }
        
        cout<<"salary sum: "<<sum<<endl;
    }
    ~EmployeeHandler(){
        for(int i =0;i<empNum;i++){
            delete empList[i];
        }
    }
};
int main() {
    EmployeeHandler handler;
    handler.AddEmployee(new PermanentWorker("Kim", 1000));
    handler.AddEmployee(new PermanentWorker("Lee", 1500));
    
    TemporaryWorker *alba=new TemporaryWorker("Jung", 700);
    alba->AddWorkTime(5);
    handler.AddEmployee(alba);
    
    SalesWorker *seller=new SalesWorker("Hong", 1000, 0.1);
    seller->AddSalesResult(7000);
    handler.AddEmployee(seller);
    
    handler.ShowAllSalaryInfo();
    
    handler.ShowTotalSalary();

    return 0;
}