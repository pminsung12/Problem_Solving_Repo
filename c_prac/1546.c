#include <stdio.h>
 
int main(){

    int N;//과목 개수
    int M = 0;
    double avg = 0;
    int score[1000] = {0,};
    scanf("%d\n", &N);

    //최댓값 알아내기
    for (int i = 0; i<N;i++){
        scanf("%d\n", &score[i]);
        if (score[i] >= M){
            M = score[i];
        }
        //score초기화해야하나
    }

    //평균구하기
    for(int j = 0;j<N;j++){
        avg += score[j];
    } 

    //새로운 평균
    printf("%.4lf", avg/M/N*100);
    

    return 0;
}