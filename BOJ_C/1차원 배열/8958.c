#include <stdio.h>

int main(){

    int N;//테스트 케이스 개수
    char test[80] = {0,};
    int sum = 0;//각 점수
    int check = 1;//똑같은게 몇갠지

    scanf("%d\n", &N);
    int score[100] = {0,};//점수 저장용 배열

    for(int i = 0;i<N;i++){
        scanf("%s\n", &test);
        for(int j=0;j<80;j++){
            if (test[j]=='O'){
                sum += check;
                check += 1;
            }
            else if(test[j]=='X'){
                check = 1;
            }
            else break;
        }
        score[i] = sum;
        sum = 0;//초기화
        test[0] = '\0';
        check=1;
    }

    for (int m = 0;m<N;m++){
        printf("%d\n",m, score[m]);
    }

    return 0;
}
