//vector로 구현하다가 시간초과 메모리초과 나가지고 비트마스킹을 구글링함
//[출처](https://donggoolosori.github.io/2020/09/24/boj-11723/).
//비트마스크설명잘되어있음
#include <iostream>
#include <string>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int m;
	cin>>m;
	
	string s;
	int val, BIT=0;//bit를 반드시 0으로 초기화
	//intrk 32비트이니까 자리순서와 입력되는 수를 매칭
	while(m--){
		s.clear();
		cin>>s;
		if(s=="add"){
			cin>>val;
			 // or 연산자를 통해 val번째 자리수를 1로 채운다.
			BIT |=(1<<val); 
		}
		
		else if(s=="remove"){
			cin>>val;
			// ex) 1000 & ~(1000) = 0000
			BIT &= ~(1<<val); 
		}
		
		else if(s=="check"){
			cin>>val;
			if(BIT & (1<<val)) cout<<1<<'\n';
			else cout<<0<<'\n'; 
		}
		
		else if(s=="toggle"){
			cin>>val;
			// BIT의 val번째 자리가 1이라면 1^1=0이 되어 1->0이 되고
            // val번째 자리가 0이라면 0^1=1 이 되어 0 -> 1이 된다.
			BIT ^=(1<<val); 
		}
		
		else if(s=="all"){
		    // ex) 10000 - 1 = 1111
			BIT =(1<<21)-1; 
		}
		
		else if(s=="empty"){
			BIT =0;
		}
	}
	return 0;
}