#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void ent_matrix(float **arr, int N){
    for(int x = 0; x<N; x++){
        for(int y = 0; y<N+1; y++){
            printf("[%d, %d] = ", x, y);
            scanf("%f", &arr[x][y]);
        }
    }
}

void crmat(float **arr, int n){
    for(int i = 0; i<n; i++){
        arr[i] = calloc(1, sizeof(float)*(n+1));
    }
}

void rep_matrix(int **b, int **arr, int N, int m){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            if(j == m){
                b[i][m] = arr[i][N];
            }
            else{
                b[i][j] = arr[i][j];
            }
        }
    }
}

void show_matrix(float **arr, int N){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N+1; j++){
            printf("%f ", arr[i][j]);
        }
        printf("\n");
    }
}

void trim_matrix(int **b, int **arr, int N, int m){
    int x = 0;
    int y = 0;
    for(int i = 0; i<N; i++){
        if(i!=m){
            for(int j=0; j<N; j++){
                if(j!=m){
                    b[y][x] = arr[i][j];
                    x += 1;
                    if(x==N-1){
                        x = 0;
                        y += 1;
                    }
                }
            }
        }
    }
}

float d2x2(float **arr){
    return arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
}

float d3x3(float **a){
    return a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[0][2]*a[1][0]*a[2][1]-a[0][2]*a[1][1]*a[2][0]-a[0][1]*a[1][0]*a[2][2]-a[0][0]*a[1][2]*a[2][1];
}

// int dnxn(int **a, int N){
//     int i = 0;
//     int sum = 0;
//     int k = 1;
//     for(int l = 0; l<N; l++){
//         k = k * a[l][l];
//     }
//     sum += k;

//     for(int u = 1; u<N; u++){
//         k = 1;
//         for(int l = u, i = 0; l<N; l++){
//             i = l-u;
//             k = k * a[i][l];
//         }
//         int x = N-u;
//         for(int ku = 0; ku<u; ku++){
//             k = k * a[x][ku];
//             x+=1;
//         }
//         sum += k;
//     }
//     k = 1;
//     for(int l = 0; l<N; l++){
//         k = k * a[(N-1)-l][l];
//     }
//     sum += k*(-1);

//     for(int u = 1; u<N; u++){
//         k = 1;
//         for(int l = u, i = 1; l<N; l++, i++){
//             k = k * a[(N)-l][N-1-l];
//         }
//         int x = N-u;
//         for(int ku = 0; ku<u; ku++){
//             k = k * a[x][(N-1)-ku];
//             x+=1;
//         }
//         sum += k*(-1);

//     }

//     return sum;
// }
//

float result(float **arr, int N, int m){
    if(N==1){
        return arr[0][0];
    }
    else if(N==2){
        float **array = calloc(1, sizeof(float*)*2);
        crmat(array, N);
        float d = d2x2(arr);
        rep_matrix(array, arr, N, m);
        float dx = d2x2(array);
        if(d == 0){
            printf("Нет единственного решения!\n");
            exit(0);
        }
        float x = dx / (float) d;
        return x;
    }
    else if(N==3){
        float **array = calloc(1, sizeof(float*)*2);
        crmat(array, N);
        rep_matrix(array, arr, N, m);
        float d = d3x3(arr);
        float dx = d3x3(array);
        if(d == 0){
            printf("Нет единственного решения!\n");
            exit(0);
        }
        float x = dx / (float) d;
        return x;
    }
    // else{
    //     int d = 0;
    //     int **array = calloc(1, sizeof(int*)*N);
    //     crmat(array, N);
    //     rep_matrix(array, arr, N, m);
    //     d = dnxn(arr, N);
    //     printf("!!! %d\n", d);
    // }
}

void shres(float **arr, int N){
    float ans;
    for(int i = 0; i<N; i++){
        ans = result(arr, N, i);
        if(N<=3){
            switch (i)
            {
            case 0:
                printf("x = %f; ", ans);
                break;
            case 1:
                printf("y = %f; ", ans);
                break;
            case 2:
                printf("z = %f; ", ans);
                break;
            default:
                break;
            }
        }
        else{
            printf("x%d = %f; ", i, ans);
        }
    }
    printf("\n");
}

int main(){
    int N = 1;
    printf("N: ");
    scanf("%d", &N);
    float **matrix = calloc(1, sizeof(float*)*N);
    crmat(matrix, N);
    ent_matrix(matrix, N);

    show_matrix(matrix, N);

    printf("========================\n");
    shres(matrix, N);
}