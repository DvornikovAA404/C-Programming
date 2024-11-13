// Получить матрицу C[m,k] путем умножения матрицы А[m,n] на матрицу B[n,k] и определить в результирующей матрице строку с 
// наибольшим количеством отрицательных элементов. 
// Заменить в полученной матрице отрицательные элементы на их количество и записать в обратном порядке любую строку матрицы.

#include <stdio.h>
#include <stdlib.h>

int show(int **A, int m, int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int ent(int **A, int m, int n){
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            printf("[%d, %d] = ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}

void freemat(int **a, int n){
    for(int i = 0; i<n; i++){
        free(a[i]);
    }
}

void Multmat(int **C, int **A, int **B, int m, int n, int k){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < k; j++) {
            for (int d = 0; d < n; d++) {
                C[i][j] += A[i][d] * B[d][j]; 
            }
        }
    }
}

<<<<<<< HEAD
void Copy(int **D, int **C, int m, int k){
    for(int i=0; i<m; i++){
        for(int j=0; j<k; j++){
            D[i][j] = C[i][j];
        }
    }
}

void Invert(int **D, int **C, int m, int k, int line){
    for(int j = 0; j<k; j++){
        D[line][j] = C[line][k-1-j];
    }
}

void FindZero(int **D, int **C, int m, int k){
    int max = 0;
    int indy = -1;
    for(int i = 0; i<m; i++){
        int d = 0;
        for(int j = 0; j<k; j++){

            if(C[i][j]<0){
                d += 1;
                // printf("[%d %d] = %d\nk = %d\n", i, j, C[i][j], d);
            }
        }
        // printf("%d\n", k);
        if(max < d){
            max = d;
            indy = i;
        }
    }
    if(indy >= 0){
        for(int j = 0; j<k; j++){
            C[indy][j] = max;
        }
    }
}

=======
>>>>>>> 3e13dd4 (Lab9 completed)
int main(){
    // Sizing
    int m, n, k;
    printf("M: ");
    scanf("%d", &m);
    printf("N: ");
    scanf("%d", &n);
    printf("K: ");
    scanf("%d", &k);
    // Create matrixs
    int **A = calloc(m, sizeof(int*));
    for(int i = 0; i<m; i++){
        A[i] = calloc(n, sizeof(int));
    }
    
    int **B = calloc(n, sizeof(int*));
    for(int i = 0; i<n; i++){
        B[i] = calloc(k, sizeof(int));
    }

    int **C = calloc(m, sizeof(int*));
    for(int i = 0; i<m; i++){
        C[i] = calloc(k, sizeof(int));
    }

<<<<<<< HEAD
    int **D = calloc(m, sizeof(int*));
    for(int i = 0; i<m; i++){
        D[i] = calloc(k, sizeof(int));
    }

=======
>>>>>>> 3e13dd4 (Lab9 completed)
    // Debug show matrixs
    show(A, n, m);
    printf("============ × ============\n");
    show(B, k, n);
    
    // Enter matrixs
    printf("============ A ============\n");
    ent(A, n, m);
    show(A, n, m);
    printf("============ B ============\n");
    ent(B, k, n);
    show(B, k, n);

    // =========== Equal ============

    printf("============ = ============\n");
    Multmat(C, A, B, m, n, k);
    show(C, k, m);

<<<<<<< HEAD
    // =========== FIND ============

    printf("============ - ============\n");
    FindZero(D, C, m, k);
    show(C, k, m);

    // =========== Invt ============
    
    printf("=========== INV ============\n");
    Copy(D, C, m, k);
    Invert(D, C, m, k, 1);
    show(D, k, m);

=======
>>>>>>> 3e13dd4 (Lab9 completed)
    // =========== FREE ============
    freemat(A, n);
    free(A);
    A = NULL;
    freemat(B, k);
    free(B);
    B = NULL;
    freemat(C, k);
    free(C);
    C = NULL;
<<<<<<< HEAD
    freemat(D, k);
    free(D);
    D = NULL;
=======
>>>>>>> 3e13dd4 (Lab9 completed)
}