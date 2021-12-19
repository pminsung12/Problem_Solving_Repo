#include <stdio.h>

int main() { // 테스트 케이스를 입력받는다.
  int t; // 여러 개의 테스트 케이스를 입력 받기 위한 변수
  scanf("%d\n", &t);
  
  for(int testCase=0; testCase<t; testCase++) {
    unsigned int x, y, distance;
    int count = 0;
    int move = 1;
    
    scanf("%u %u\n", &x, &y); // 출발점과 도착점 입력 받음
    distance = y - x;
    
    while(distance / 2 >= move) {
      distance -= move * 2;//대칭으로 움직이니까 한번에 계산
      count += 2;
      move++;
    }

    if (1 <= distance && distance <= move) 
      count++;
    else if (move < distance) 
      count += 2;
    
    printf("%d\n", count);
  }
  
  return 0;
}