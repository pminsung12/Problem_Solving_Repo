#include <iostream>
#include <string>
#define SiZE 10
using namespace std;

void showMenu();
void makeAccount();
void deposit();
void withdraw();
void showAll();
enum{MAKEACCOUNT=1, DEPOSIT, WITHDRAW, SHOWALL, EXIT};

class Banking{
private:
    int account_number;
    string name;
    int balance;

public:
    Banking(){}

    ~Banking() {
        std::cout << "소멸되었습니다." << std::endl;
    }
};

int acc_cnt=0;//계좌 개수
Banking member[SIZE];

int main(void){
    
    
    while(1){
        int a;
        showMenu();
        cin>>a;
        switch (a){
            case(MAKEACCOUNT):

        }




    }
    showMenu();


    system("pause");
}

//Menu
void showMenu(){

    cout<<"-------Menu-----"<<endl;
    cout<<" 1. 계좌개설"<<endl;
    cout<<" 2. 입 금"<<endl;
    cout<<" 3. 출 금"<<endl;
    cout<<" 4. 계좌정보 전체 출력"<<endl;
    cout<<" 5. 프로그램 종료"<<endl;
    count<<"---------------"<<endl;
    
}

//1.계좌 개설
Banking::makeAccount(){
    int id, name, money;
    cout<<"[입   금]";
    cin>>id;
    this->account_number = id;
    cout<<"이름: ";
    cin>>name;
    this->name = name;
    cout<<"입금액: ";
    cin>>money;
    this->balance = money;
    cout<<"계좌 개설 완료!!"<<endl;
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
    int money;
    cout<<"[출   금]"<<endl;
    cout<<"계좌ID: ";
    cin>>money;
    this->balance-=money;
    cout<<"출금완료"<<endl;
}

//4.계좌정보 전체 출력
Banking::showAll(){

}