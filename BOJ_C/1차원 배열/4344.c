#include <stdio.h>

int main(){

    int C;//테스트 케이스의 개수
    scanf("%d\n", &C);
    
    
    
    for (int i=0;i<C;i++){
        int N;//학생 수
        scanf("%d", &N);
        
        int score[1000];//테스트케이스당 점수
        int sum = 0;//평균을 위한 합계
        double avg= 0.0;//굳이 안에 넣는 이유는 초기화
        
        for(int j=0;j<N;j++){
            scanf("%d", &score[j]);
            sum += score[j];
        }
        avg = (double)sum/N;
        int count = 0;//평균 넘은 학생수
        for(int m=0;m<N;m++){//평균넘는 학생수
            if(score[m]>avg){
                count ++;
            }
        }
        printf("%.3f%%\n",(double)count*100/N);
        
    }

    return 0;
}
