#include <iostream>
#include <string>

using namespace std;

class Banking{
private:
    int account_number;
    string name;
    int balance;

public:
    Banking(int num, string name, int balance): account_number(num), name(name), balance(balance){}
    void showMenu();
    void makeAccount();
    void deposit();
    void withdraw();
    void showAll();
};

int main(void){


    system("pause");
}
//Menu
Banking::showMenu(){
    int a;
    cout<<"-----Menu-----"<<endl;
    cout<<"1. 계좌개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 계좌정보 전체 출력"<<endl;
    cout<<"5. 프로그램 종료"<<endl;

    cin>>int a;
    if(a) this.makeAccount();
    else if(a-1) this.deposit();
    else if(a-2) this.withdraw();
    else if(a-3) this.showAll();
    else if(a-4) // 종료?
}
//1.계좌 개설
Banking::makeAccount(){
    int id, name, money;
    cout<<"[입   금]";
    cin>>id;
    cout<<"이름: ";
    cin>>name;
    cout<<"입금액: ";
    cin>>money;
}
//2.입금
Banking::deposit(){
    int money;
    cout<<"[입   금]"<<endl;
    cout<<"계좌ID: ";
    cin>>money;
    this->balance+=money;
    cout<<"입금완료"<<endl;
}
//3.출금
Banking::withdraw(){

}
//4.계좌번호 전체 출력
Banking::showAll(){

}