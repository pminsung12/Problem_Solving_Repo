//v.0.3 깊은 복사 생성자 추가
#include <iostream>
#include <cstring>
#define SIZE 100
#define NAME_LEN 20
using namespace std;

enum{MAKEACCOUNT=1, DEPOSIT, WITHDRAW, SHOWALL, EXIT};
void makeAccount();
void depositMoney();
void withdrawMoney();
void showAll();
void showMenu();
void chooseMenu();

class Account{
private:
    int account_number;
    int balance;
    char *name;
public:
    Account(int _account_number, int _balance, char *_name){
        account_number=_account_number;
        balance=_balance;
        name=new char(strlen(_name)+1);
        strcpy(name, _name);
    }
    Account(){
        account_number=0;
        balance=0;
        name=NULL;
        cout<<"called Account()"<<endl;
    }
    //깊은 복사 생성자
    Account(Account& copy): account_number(copy.account_number), balance(copy.balance){
        name=new char(strlen(copy.name)+1);
        strcpy(name, copy.name);
    }
    int getID(){
       return account_number; 
    }
    void deposit(int money){
        balance+=money;
    }
    int withdraw(int money){
        if (balance<money){
            return 0;
        }
        balance-=money;
        return 1;
    }
    
    void showInfo(){
        cout<<"계좌 ID: "<<account_number<<endl;
        cout<<"이   름: "<<name<<endl;
        cout<<"입금액 : "<<balance<<endl<<endl;
    }
    
    ~Account(){
        delete []name;
    }
};

Account *member[SIZE];
int acc_cnt=0;

int main(void){
    chooseMenu();
    return 0;
}

//1.계좌 개설
void makeAccount(){
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
void depositMoney(){
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
void withdrawMoney(){
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
void showAll(){
    for(int i=0;i<acc_cnt;i++){
        member[i]->showInfo();
    }
}
//메뉴
void showMenu(){

    cout<<"-----------Menu---------"<<endl;
    cout<<" 1. 계좌개설"<<endl;
    cout<<" 2. 입 금"<<endl;
    cout<<" 3. 출 금"<<endl;
    cout<<" 4. 계좌정보 전체 출력"<<endl;
    cout<<" 5. 프로그램 종료"<<endl;
    cout<<"------------------------"<<endl<<endl;
    
}

void chooseMenu(){
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
