#include <iostream>
#include <string>
using namespace std;

string white[8]={
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW"
};

string black[8]={
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB",
    "BWBWBWBW",
    "WBWBWBWB"
};

string board[50];

int checkWhite(int x, int y){
    int cnt=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[x+i][y+j]!=white[i][j]) cnt++;
        }
    }
    return cnt;
}

int checkBlack(int x, int y){
    int cnt=0;
    for(int i=0;i<8;i++){
        for(int j=0;j<8;j++){
            if(board[x+i][y+j]!=black[i][j]) cnt++;
        }
    }
    return cnt;
}

int main(){

    int tmp;
    int min_val=12345;
    pair<int , int>p1;
    cin>>p1.first>>p1.second;

    for(int i=0;i<p1.first;i++){
        cin>>board[i];
    }
    for(int i=0;i<=p1.first-8;i++){
        for(int j=0;j<=p1.second-8;j++){
            tmp = min(checkWhite(i,j), checkBlack(i,j));
            if(tmp<min_val) min_val=tmp;
        }
    }
    cout<<min_val<<endl;

    return 0;
}