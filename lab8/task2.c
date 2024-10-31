#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ent_matrix(int **arr, int N){
    for(int x = 0; x<N; x++){
        for(int y = 0; y<N+1; y++){
            printf("[%d, %d] = ", x, y);
            scanf("%d", &arr[x][y]);
        }
    }
}

void crmat(int **arr, int n){
    for(int i = 0; i<n; i++){
        arr[i] = calloc(1, sizeof(int)*(n+1));
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

void show_matrix(int **arr, int N){
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int d2x2(int **arr){
    return arr[0][0]*arr[1][1]-arr[0][1]*arr[1][0];
}

int d3x3(int **a){
    return a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[0][2]*a[1][0]*a[2][1]-a[0][2]*a[1][1]*a[2][0]-a[0][1]*a[1][0]*a[2][2]-a[0][0]*a[1][2]*a[2][1];

}

float result(int **arr, int N, int m){
    if(N==1){
        return arr[0][0];
    }
    else if(N==2){
        int **array = calloc(1, sizeof(int*)*2);
        crmat(array, N);
        int d = d2x2(arr);
        rep_matrix(array, arr, N, m);
        int dx = d2x2(array);
        float x = dx / (float) d;
        return x;
    }
    else if(N==3){
        int **array = calloc(1, sizeof(int*)*2);
        crmat(array, N);
        rep_matrix(array, arr, N, m);
        int d = d3x3(arr);
        int dx = d3x3(array);
        float x = dx / (float) d;
        return x;
    }
}

void shres(int **arr, int N){
    int ans;
    for(int i = 0; i<N; i++){
        ans = result(arr, N, i);
        if(N<=3){
            switch (i)
            {
            case 0:
                printf("x = %d; ", ans);
                break;
            case 1:
                printf("y = %d; ", ans);
                break;
            case 2:
                printf("z = %d; ", ans);
                break;
            default:
                break;
            }
        }
        else{
            printf("x%d = %d; ", i, ans);
        }
    }
    printf("\n");
}

int main(){
    int N = 1;
    printf("N: ");
    scanf("%d", &N);
    int **matrix = calloc(1, sizeof(int*)*N);
    crmat(matrix, N);
    ent_matrix(matrix, N);
    show_matrix(matrix, N);
    printf("========================\n");
    shres(matrix, N);
}