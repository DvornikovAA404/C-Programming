#include <stdio.h>


void show(int N, int a[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%02d ", a[i][j]);
        }
        printf("\n");
    }
}

void func(int N, int a[N][N]){
    int top = 0, bottom = N - 1;
    int left = 0, right = N - 1;
    int num = 1;

    while (num <= N * N) {
        for (int i = left; i <= right; i++) {
            a[top][i] = num++;
        }
        top++;

        for (int i = top; i <= bottom; i++) {
            a[i][right] = num++;
        }
        right--;

        for (int i = right; i >= left; i--) {
            if (top <= bottom) {
                a[bottom][i] = num++;
            }
        }
        bottom--;

        for (int i = bottom; i >= top; i--) {
            if (left <= right) {
                a[i][left] = num++;
            }
        }
        left++;
    }
}

int main(){
    int N = 1;
    printf("N: ");
    scanf("%d", &N);

    int a[N][N];
    func(N, a);
    show(N, a);
}