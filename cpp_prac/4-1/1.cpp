//정보은닉과 const
#include <iostream>
using namespace std;

class FruitSeller{
private:
    int APPLE_PRICE;
    int numOfApplies;
    int myMoney;
    
public:
    void InitMembers(int price, int num, int money){
        APPLE_PRICE = price;
        numOfApplies=num;
        myMoney=money;
    }
    int SaleApples(int money){
        if (money<0){
            cout<<"사과의 구매를 목적으로 0보다 작은 수를 전달 할 수 없다."<<endl;
            return 0;
        }
        int num=money/APPLE_PRICE;
        numOfApplies-=num;
        myMoney+=money;
        return num;
    }
    void ShowSalesResult() const{
        cout<<"남은 사과: "<<numOfApplies<<endl;
        cout<<"판매 수익: "<<myMoney<<endl<<endl;
    }
};

class FruitBuyer{
    int myMoney;
    int numOfApples;
public:
    void InitMembers(int money){
        myMoney=money;
        numOfApples=0;
    }
    void BuyApples(FruitSeller &seller, int money){
        if(money<0) {//여기다 if(!seller.SaleApples(money))로 하면 파는걸 2번해버리는 결과가 나타남.
            cout<<"살수 없음"<<endl;
            return;
        }
        numOfApples+=seller.SaleApples(money);
        myMoney-=money;
    }
    void ShowBuyResult() const {
        cout<<"현재 잔액: "<<myMoney<<endl;
        cout<<"사과 개수: "<<numOfApples<<endl<<endl;
    }
};

int main(){
    FruitSeller seller;
    seller.InitMembers(1000, 20, 0);
    FruitBuyer buyer;
    buyer.InitMembers(5000);
    buyer.BuyApples(seller,-1000);
    buyer.BuyApples(seller,2000);
    
    cout<<"과일 판매자의 현황"<<endl;
    seller.ShowSalesResult();
    cout<<"과일 구매자의 현황"<<endl;
    buyer.ShowBuyResult();
    return 0;
}


