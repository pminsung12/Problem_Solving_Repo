#include <iostream>
using namespace std;

int N,r,c;
int cnt=0;
void z(int y, int x, int size){
	if(y==r && x==c){
		cout<<cnt<<'\n';
		return;
	}
	if(r>=y && r<y+size&&c>=x&&c<x+size){
		z(y, x, size/2);//1사분면
		z(y,x+size/2, size/2);//2사분면
		z(y+size/2,x,size/2);//3사분면
		z(y+size/2,x+size/2, size/2);//4사분면
	}
	else{//r,c가 사분면에 없을 때
		cnt+=size*size;
	}
}

int main(){
	scanf("%d %d %d", &N, &r, &c);
	z(0,0,(1<<N));//<<는 비트이동 연산자 2의n제곱이랑 같음
	return 0;
	
}

