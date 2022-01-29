//v.0.5 Control Class 정의
#include <iostream>
#include <cstring>
#define SIZE 100
#define NAME_LEN 20
using namespace std;

enum{MAKEACCOUNT=1, DEPOSIT, WITHDRAW, SHOWALL, EXIT};

/*
 * 클래스 이름: Account
 * 클래스 유형: Entity 클래스
 */

class Account{
private:
    int account_number;
    int balance;
    char *name;
public:
    Account(int _account_number, int _balance, char *_name);
    Account();
    //깊은 복사 생성자
    Account(Account& copy);
    int getID() const;
    void deposit(int money);
    int withdraw(int money);
    void showInfo() const;
    ~Account();
};

Account::Account(int _account_number, int _balance, char *_name){
        account_number=_account_number;
        balance=_balance;
        name=new char(strlen(_name)+1);
        strcpy(name, _name);
}
Account::Account(){
        account_number=0;
        balance=0;
        name=NULL;
        cout<<"called Account()"<<endl;
}
Account::Account(Account& copy): account_number(copy.account_number), balance(copy.balance){
        name=new char(strlen(copy.name)+1);
        strcpy(name, copy.name);
}
int Account::getID() const {
       return account_number; 
}
void Account::deposit(int money){
        balance+=money;
}
int Account::withdraw(int money){
        if (balance<money){
            return 0;
        }
        balance-=money;
        return 1;
}  
void Account::showInfo() const {
        cout<<"계좌 ID: "<<account_number<<endl;
        cout<<"이   름: "<<name<<endl;
        cout<<"입금액 : "<<balance<<endl<<endl;
} 
Account::~Account(){
        delete []name;
}

/*
 * 클래스 이름: AccountHandler
 * 클래스 유형: Control 클래스
 */

class AccountHandler{//contrl class
private:
    Account *member[SIZE];
    int acc_cnt;
public:
    AccountHandler(): acc_cnt(0){}
    void makeAccount();
    void depositMoney();
    void withdrawMoney();
    void showAll();
    void showMenu() const;
    void chooseMenu();
};

int main(void){
    AccountHandler ac;
    ac.chooseMenu();

    return 0;
}

//1.계좌 개설
void AccountHandler::makeAccount(){
    int id, money;
    char name[NAME_LEN];

    cout<<"[계좌 개설]"<<endl;
    cout<<"계좌ID: ";
    cin>>id;
    cout<<"이름: ";
    cin>>name;
    cout<<"입금액: ";
    cin>>money;
    
    member[acc_cnt]=new Account(id, money, name);
    acc_cnt++;
    cout<<"계좌 개설 완료!!"<<endl<<endl;
}

//2.입금
void AccountHandler::depositMoney(){
    int id,money;
    cout<<"[입   금]"<<endl;
    cout<<"계좌ID: ";cin>>id;
    cout<<"입금액";cin>>money;

    for(int i=0;i<acc_cnt;i++){
        if(id==member[i]->getID()){
            member[i]->deposit(money);
            cout<<"입금완료"<<endl<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID입니다."<<endl<<endl;
}

//3.출금
void AccountHandler::withdrawMoney(){
    int id,money;
    cout<<"[출   금]"<<endl;
    cout<<"계좌ID: ";cin>>id;
    cout<<"출금액";cin>>money;

    for(int i=0;i<acc_cnt;i++){
        if(id==member[i]->getID()){
            if(!member[i]->withdraw(money)){
                cout<<"잔액부족"<<endl<<endl;
                return;
            }
            cout<<"출금완료"<<endl<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID입니다."<<endl<<endl;
}
//4.계좌 정보 전체 출력
void AccountHandler::showAll(){
    for(int i=0;i<acc_cnt;i++){
        member[i]->showInfo();
    }
}
//메뉴
void AccountHandler::showMenu() const {

    cout<<"-----------Menu---------"<<endl;
    cout<<" 1. 계좌개설"<<endl;
    cout<<" 2. 입 금"<<endl;
    cout<<" 3. 출 금"<<endl;
    cout<<" 4. 계좌정보 전체 출력"<<endl;
    cout<<" 5. 프로그램 종료"<<endl;
    cout<<"------------------------"<<endl<<endl;
    
}

void AccountHandler::chooseMenu(){
    int a;
    while(1){
        showMenu();
        cout<<"선택: ";
        cin>>a;
        cout<<endl;
        switch (a){
            case MAKEACCOUNT:
                makeAccount();
                break;

            case DEPOSIT:
                depositMoney();
                break;

            case WITHDRAW:
                withdrawMoney();
                break;

            case SHOWALL:
                showAll();
                break;

            case EXIT:
                for(int i =0;i<acc_cnt;i++){
                    delete member[i];
                }
                cout<<"프로그램을 종료합니다."<<endl;
                return ;
                
            default:
                cout<<"유효하지 않은 번호입니다."<<endl;
        }
    }
}
