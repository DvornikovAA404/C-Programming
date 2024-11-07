#include <stdio.h>


void show_mat(int N, float arr[N][N]){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            printf("%.2f  ", arr[i][j]);
        }
        printf("\n");
    }
}

float d2x2(int N, float arr[N][N]){
    return arr[0][0] * arr[1][1] - arr[0][1]*arr[1][0];
}

void trim_mat(int N, float b[N-1][N-1], float arr[N][N], int minor){
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

float test(int N, float arr[N][N], int num){
    float d = 0;
    if(N==1){
        return arr[0][0];
    }
    if(N==2){
        float d = d2x2(N, arr);
        // printf("D = %f\n", d);
        return d;
    }
    float s = 0;
    for(int i = 0; i<N; i++){
        float beta[N-1][N-1];
        // printf("===========%d%d=========\n", num, i);
        trim_mat(N, beta, arr, i);
        float det = arr[0][i];
        float d = det * test(N-1, beta, i);
        if(i%2==0){
            s += d;
        }
        else{
            s -= d;
        }
    }
    // printf("S = %f\n", s);
    return s;
}

void rep_mat(int N, float ret[N][N], float matrix[N][N], float rez[N][N], int col){
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
    printf("NxN: ");
    scanf("%d", &N);
    printf("\n");
    float matrix[N][N];
    float result[1][N];

    // result[0][0] = 1;
    // matrix[0][0] = 1;

    // matrix[0][0] = 3;   matrix[0][1] = 2;       result[0][0] = 0.5;
    // matrix[1][0] = 2;   matrix[1][1] = 5;       result[0][1] = 4;

    matrix[0][0] = 2;   matrix[0][1] = -3;   matrix[0][2] = 1;  result[0][0] = -7;   
    matrix[1][0] = 1;   matrix[1][1] = 2;   matrix[1][2] = -3;  result[0][1] = 14;   
    matrix[2][0] = -1;   matrix[2][1] = -1;   matrix[2][2] = 5;  result[0][2] = -18;   

    // matrix[0][0] = 3;   matrix[0][1] = 2;   matrix[0][2] = 1;  result[0][0] = 1;   
    // matrix[1][0] = 6;   matrix[1][1] = 5;   matrix[1][2] = 4;  result[0][1] = -2;   
    // matrix[2][0] = 9;   matrix[2][1] = 8;   matrix[2][2] = 7;  result[0][2] = 3;   

    // result[0][0] = 22;  result[0][1] = 39;  result[0][2] = 34;  result[0][3] = 23;  result[0][4] = 3;  result[0][5] = 26;  result[0][6] = 17;  result[0][7] = 37;

    // matrix[0][0] = 2;   matrix[0][1] = 6;   matrix[0][2] = -2;   matrix[0][3] = 3;    matrix[0][4] = 3;   matrix[0][5] = 6;   matrix[0][6] = 1;   matrix[0][7] = 6;       
    // matrix[1][0] = 1;   matrix[1][1] = 4;   matrix[1][2] = 4;   matrix[1][3] = 2;    matrix[1][4] = 4;   matrix[1][5] = 7;   matrix[1][6] = -2;   matrix[1][7] = 3;       
    // matrix[2][0] = 3;   matrix[2][1] = 6;   matrix[2][2] = 7;   matrix[2][3] = -1;    matrix[2][4] = 0;   matrix[2][5] = 5;   matrix[2][6] = 3;   matrix[2][7] = 1;       
    // matrix[3][0] = 7;   matrix[3][1] = 3;   matrix[3][2] = 6;   matrix[3][3] = 0;    matrix[3][4] = 7;   matrix[3][5] = 4;   matrix[3][6] = 2;   matrix[3][7] = 4;       
    // matrix[4][0] = 1;   matrix[4][1] = 0;   matrix[4][2] = -1;   matrix[4][3] = 2;    matrix[4][4] = 3;   matrix[4][5] = 6;   matrix[4][6] = 0;   matrix[4][7] = -2;       
    // matrix[5][0] = -1;   matrix[5][1] = 0;   matrix[5][2] = 2;   matrix[5][3] = 6;    matrix[5][4] = -2;   matrix[5][5] = 0;   matrix[5][6] = 5;   matrix[5][7] = -1;       
    // matrix[6][0] = 4;   matrix[6][1] = 5;   matrix[6][2] = -2;   matrix[6][3] = 7;    matrix[6][4] = 4;   matrix[6][5] = 4;   matrix[6][6] = 5;   matrix[6][7] = -2;       
    // matrix[7][0] = 3;   matrix[7][1] = 3;   matrix[7][2] = 4;   matrix[7][3] = 6;    matrix[7][4] = -2;   matrix[7][5] = 6;   matrix[7][6] = -2;   matrix[7][7] = 2;       

    show_mat(N, matrix);

    printf("\n======================================\n\n");

    float det = test(N, matrix, 0);
    for(int i = 0; i<N; i++){
        float beta[N][N];
        rep_mat(N, beta, matrix, result, i);
        float dx = test(N, beta, 0);
        float x = dx/det;
        if(isinf(x)){
            printf("Нет единственного решения!");
            break;
        }
        else if(N<=3){
            switch (i)
            {
            case 0:
                printf(" |  x = %.2f  | ", x);
                break;
            case 1:
                printf("y = %.2f  |  ", x);
                break;
            case 2:
                printf("z = %.2f  |  ", x);
                break;
            }
        }
        else{
            printf("x%d = %.2f  |  ", i+1, x);
        }
    }
    printf("\n\n======================================\n");
    
    // printf("%f\n", test(N, matrix, 0));
}