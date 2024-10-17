#include <stdio.h>

#define N 10

int main(){
    int a[N] = {5, 2, 3, 6, 8, 9, 7, 2, 5, 1};
    int b[N] = {7, -3, 1, -6, 5, 5, 1, -2, 4, 9};
    int z[N];
    int max = 0;
    int k = 0;
    int sum = 0;
    printf("C: ");
    for(int i = 0; i < N; i++){
        z[i] = a[i] + b[i];
        printf("%d ", z[i]);
        if (i%2==0 && max < a[i]){
            max = a[i];
        }
        if (i%2!=0 && b[i]<0){
            k+=1;    
        }
    }
    for(int i = 0; i < N; i++){
        sum += z[i];
    }
    printf("\nMax Real A: %d\nCount of IM B < 0: %d\nSum of C: %d\n", max, k, sum);
}