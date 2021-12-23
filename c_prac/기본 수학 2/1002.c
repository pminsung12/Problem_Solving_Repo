#include <stdio.h>
#include <math.h>
int main(){
    
    int T;
    int  x1, y1, r1, x2, y2, r2;

    double dist, subt;
    scanf("%d", &T);

    while(T--){
        scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
        dist = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
        subt = r1 > r2 ? r1 - r2 : r2 - r1;
        if(dist==0 && r1 == r2) printf("-1\n");
        else if(dist>subt && dist<r1+r2) printf("2\n");
        else if(dist == r1+r2 || dist==subt) printf("1\n");
        else printf("0\n");
    }
    return 0;
}

