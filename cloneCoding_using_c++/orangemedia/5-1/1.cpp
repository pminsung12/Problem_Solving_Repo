//복사 생성자의 정의
#include <iostream>
#include <cstring>
using namespace std;

namespace COMP_POS{
    enum{CLERK, SENIOR, ASSIST, MANAGER};
    void ShowPositionInfo(int pos){
        switch (pos){
            case CLERK:
                cout<<"사원"<<endl;
                break;
            case SENIOR:
                cout<<"주임"<<endl;
                break;
            case ASSIST:
                cout<<"대리"<<endl;
                break;
            case MANAGER:
                cout<<"과장"<<endl;
                break;
        }
    }
}

class NameCard{
private:
    char *name;
    char *com_name;
    char *num;
    int rank;
public:
    NameCard(char *_name, char *_com_name, char *n, int r){
        name = new char[strlen(_name)+1];
        strcpy(name, _name);
        
        com_name = new char[strlen(_com_name)+1];
        strcpy(com_name,_com_name);
        
        num = new char[strlen(n)+1];
        strcpy(num,n);
        
        rank=r;
    }

    NameCard(const NameCard& copy):rank(copy.rank){
        name = new char[strlen(copy.name)+1];
        strcpy(name, copy.name);
        
        com_name = new char[strlen(copy.com_name)+1];
        strcpy(com_name,copy.com_name);
        
        num = new char[strlen(copy.num)+1];
        strcpy(num,copy.num);
    }
    
    void ShowNameCardInfo(){
        cout<<"이름: "<<name<<endl;
        cout<<"회사: "<<com_name<<endl;
        cout<<"전화번호: "<<num<<endl;
        cout<<"직급: ";
        COMP_POS::ShowPositionInfo(rank);
        cout<<endl;
        /*if(rank == COMP_POS::CLERK) cout<<"사원"<<endl<<endl;
        else if(rank == COMP_POS::SENIOR) cout<<"주임"<<endl<<endl;
        else if(rank == COMP_POS::ASSIST) cout<<"대리"<<endl<<endl;
        else if(rank == COMP_POS::MANAGER) cout<<"과장"<<endl<<endl;
        */
    }
    ~NameCard(){
        delete []name;
        delete []com_name;
        delete []num;
    }
    
};

int main(void){
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1=manClerk;
    NameCard manSenior("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2=manSenior;
    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();
    return 0;
}