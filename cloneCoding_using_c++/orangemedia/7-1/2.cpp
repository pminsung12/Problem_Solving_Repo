//상속과 생성자, 소멸자의 호출
#include <iostream>
#include <cstring>
using namespace std;

class MyFriendInfo{
private:
    char *name;
    int age;
public:
    MyFriendInfo(char *myname, int myage):age(myage){
        name = new char[strlen(myname)+1];
        strcpy(name, myname);
    }
    ~MyFriendInfo(){
        delete []name;
    }
    void ShowMyFriendInfo() {
        cout<<"이름: "<<name<<endl;
        cout<<"나이: "<<age<<endl;
    }
};

class MyFriendDetailInfo: public MyFriendInfo{
private:
    char *addr;
    char *phone;
public:
    MyFriendDetailInfo(char *myname, int myage, char *myaddr, char *myphone) :
    MyFriendInfo(myname, myage){
        addr = new char[strlen(myaddr)+1];
        phone = new char[strlen(myphone)+1];
        strcpy(addr, myaddr);
        strcpy(phone, myphone);
    }
    ~MyFriendDetailInfo(){
        delete []addr;
        delete []phone;
    }
    void ShowMyFriendDetailInfo() {
        ShowMyFriendInfo();
        cout<<"주소: "<<addr<<endl;
        cout<<"전화: "<<phone<<endl<<endl;
    }
};

int main(){
    MyFriendDetailInfo f1("박민성", 23, "성남시 수정구", "010-1234-5678");
    f1.ShowMyFriendDetailInfo();
}
