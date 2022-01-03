#include <iostream>
#include <string>
#include <cstring>
#define SIZE 10
using namespace std;

void showMenu();
void makeAccount();
void deposit();
void withdraw();
void showAll();
enum{MAKEACCOUNT=1, DEPOSIT, WITHDRAW, SHOWALL, EXIT};

typedef struct{
    int account_number;
    int balance;
    string name;
}Banking;

int acc_cnt=0;//계좌 개수
Banking member[SIZE];

int main(void){
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
                deposit();
                break;

            case WITHDRAW:
                withdraw();
                break;

            case SHOWALL:
                showAll();
                break;

            case EXIT:
                cout<<"프로그램을 종료합니다."<<endl;
                return 0;

            default:
                cout<<"유효하지 않은 번호입니다."<<endl;
        }
    }
    return 0;
}

//Menu
void showMenu(){

    cout<<"-----------Menu---------"<<endl;
    cout<<" 1. 계좌개설"<<endl;
    cout<<" 2. 입 금"<<endl;
    cout<<" 3. 출 금"<<endl;
    cout<<" 4. 계좌정보 전체 출력"<<endl;
    cout<<" 5. 프로그램 종료"<<endl;
    cout<<"-----------------------"<<endl<<endl;
    
}

//1.계좌 개설
void makeAccount(){
    int id, money;
    string name;

    cout<<"[계좌 개설]"<<endl;
    cout<<"계좌ID: ";cin>>id;
    cin.ignore(256,'\n');
    cout<<"이름: ";cin>>name;
    cin.ignore(256,'\n');
    cout<<"입금액: ";cin>>money;
    cin.ignore(256,'\n');
    member[acc_cnt].account_number=id;
    member[acc_cnt].name=name;
    member[acc_cnt].balance=money;
    acc_cnt++;

    cout<<"계좌 개설 완료!!"<<endl<<endl;
}

//2.입금
void deposit(){
    int id,money;
    cout<<"[입   금]"<<endl;
    cout<<"계좌ID: ";cin>>id;
    cout<<"입금액";cin>>money;

    for(int i=0;i<acc_cnt;i++){
        if(id==member[i].account_number){
            member[i].balance+=money;
            cout<<"입금완료"<<endl<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID입니다."<<endl<<endl;
}

//3.출금
void withdraw(){
    int id,money;
    cout<<"[출   금]"<<endl;
    cout<<"계좌ID: ";cin>>id;
    cout<<"출금액";cin>>money;

    for(int i=0;i<acc_cnt;i++){
        if(id==member[i].account_number){
            if(money>member[i].balance){
                cout<<"잔액부족"<<endl<<endl;
                return;
            }
            member[i].balance-=money;
            cout<<"출금완료"<<endl<<endl;
            return;
        }
    }
    cout<<"유효하지 않은 ID입니다."<<endl<<endl;
}

//4.계좌정보 전체 출력
void showAll(){
    for(int i=0;i<acc_cnt;i++){
        cout<<"계좌 ID: "<<member[i].account_number<<endl;
        cout<<"이   름: "<<member[i].name<<endl;
        cout<<"입금액 : "<<member[i].balance<<endl<<endl;
    }
}