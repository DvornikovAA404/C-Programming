#include <stdio.h>
#include <stdbool.h>

#define N 4

bool isPrime(int n)
{
    for (int i = 2; i < n; i++)
            if (n % i == 0)
                return false;
        return true;
}

void printArr(int a[N]){
    for(int i = 0; i<N; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

void pop(int a[N], int i, int k){
    for(int n = i; n<N-1; n++){
        a[n] = a[n+1];
    }
    a[N-1] = 0;
}

int main(){
    int a[N] = {22, 19, 52, 31};
    int k = N;
    printArr(a);
    for(int i = 0; i < 12; i++){
        if(a[i]/(float)N >= 1 && isPrime(a[i])){
            k = k-1;
            a[i] = 0;
            pop(a, i, k);
        }
    }
    printArr(a);
}