#include <stdio.h>
#define SIZE 50

int main(){
    int N;
    int rank;
    int info[SIZE][2];
    scanf("%d", &N);

    for(int i = 0;i<N;i++){
        scanf("%d %d", &info[i][0], &info[i][1]);
    }

    for(int i = 0;i<N;i++){
        rank=1;
        int a = info[i][0];
        int b = info[i][1];
        for(int j= 0;j<N;j++){
            if(a<info[j][0] && b<info[j][1]) rank++;
        }
        printf("%d\n", rank);
    }

    return 0;
}
