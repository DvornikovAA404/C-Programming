#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define E pow(10, -3)

// cos x
float factor(int N) {
    if (N < 1) return 1; 
    return N * factor(N - 1); 
}

float fcos(float x, int N){
    float u;
    u = pow(-1, N) * (pow(x, 2*N)/factor(2*N));
    if(fabs(u)<=E){
        return u;
    }
    else{
        return u + fcos(x, N+1);
    }
}

int main(){
    float cs, x;
    printf("X = ");
    if((scanf("%f", &x) != 1)|| x < 0){
        printf("Invalid input! Error code: -1\n");
        exit(-1);
    }
    
    float mx = cosf(x);
    printf("%.20f ≈ %.20f\n", mx, fcos(x, 0));
}