//유클리드 호제법
#include <iostream>
using namespace std;

int gcd(int a, int b) {
    int tmp=a%b;
    while(tmp!=0){
        a=b;
        b=tmp;
        tmp=a%b;
    }
    return b;
}

int lcm(int a, int b) {
	return (a * b) / gcd(a, b);
}

int main() {
	int n1, n2;
	cin >> n1 >> n2;
	cout << gcd(n1, n2) << "\n" << lcm(n1, n2);
}