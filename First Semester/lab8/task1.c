#include <stdio.h>


void show(int N, float arr[N][N]){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            printf("%.2f  ", arr[i][j]);
        }
        printf("\n");
    }
}

float det2(int N, float arr[N][N]){
    return arr[0][0] * arr[1][1] - arr[0][1]*arr[1][0];
}

void trim(int N, float b[N-1][N-1], float arr[N][N], int minor){
    int x = 0;
    int y = 0;
    for (int i = 0; i<N; i++){
        if(i != 0){
            for(int j = 0; j<N; j++){
                if(j != minor){
                    b[y][x] = arr[i][j];
                    x++;
                    if(x==N-1){
                        x = 0;
                        y += 1;
                    }
                }
            }
        }
    }
}

float results(int N, float arr[N][N], int num){
    float d = 0;
    if(N==1){
        return arr[0][0];
    }
    if(N==2){
        float d = det2(N, arr);
        return d;
    }
    float s = 0;
    for(int i = 0; i<N; i++){
        float second[N-1][N-1];
        trim(N, second, arr, i);
        float det = arr[0][i];
        float d = det * results(N-1, second, i);
        if(i%2==0){
            s += d;
        }
        else{
            s -= d;
        }
    }
    return s;
}

void replace(int N, float ret[N][N], float matrix[N][N], float rez[N][N], int col){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(j==col){
                ret[i][j] = rez[0][i];
            }
            else{
                ret[i][j] = matrix[i][j];
            }
        }
    }
}

float calculate(int N, float matrix[N][N]){

}

int main(){
    int N;
    printf("N: ");
    scanf("%d", &N);
    printf("\n");
    float matrix[N][N];
    float result[1][N];
    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float a = 0;
            scanf("%f", &a);
            matrix[i][j] = a;
        }
    }

    printf("Введите элементы после равно:\n");
    for (int i = 0; i < N; i++) {
        scanf("%f", &result[0][i]);
    }

    show(N, matrix);

    printf("\n======================================\n\n");

    float det = results(N, matrix, 0);
    for(int i = 0; i<N; i++){
        float second[N][N];
        replace(N, second, matrix, result, i);
        float dx = results(N, second, 0);
        float x = dx/det;
        if(isinf(x)){
            printf("Нет единственного решения!");
            break;
        }
        else{
            printf("x%d = %.2f  |  ", i+1, x);
        }
    }
    printf("\n\n======================================\n");
    
}