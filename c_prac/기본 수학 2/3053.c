#include <stdio.h>
#include <math.h>
#define _USE_MATH_DEFINES


int main(){
    
    int R;
    scanf("%d", &R);

    printf("%.6lf\n", M_PI*R*R);
    printf("%d\n", 2*R*R);

    return 0;
}