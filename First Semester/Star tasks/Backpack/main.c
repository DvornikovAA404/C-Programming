#include <stdio.h>
#include <stdlib.h>

#define T 100
#ifndef DEBUG
#define DEBUG 0
#endif

#define DEB(fmt, ...) \
        do { if(DEBUG) fprintf(stderr, "[%s] " msg "\n", __FUNCTION__, __VA_ARGS__); } while(0)

void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void bubble_sort(int *array, int size)
{
    int i, j;
    for (i = 1; i < size; ++i)
    {
        for (j = 0; j < size - i; ++j)
        {
            if (array[j] > array[j+1])
            {
                swap(&array[j], &array[j + 1]);
            }
        }
    }
}

int Handler(int N, int arr[N], int W){
    int G = 0;
    bubble_sort(arr, N);
    if(DEBUG){
        for(int i = 0; i<N; i++){
        printf("%d ", arr[i]);
        }
        printf("\n");
    }
    for(int z = 1; z < T; z++){
        for(int i = 0; i < N; i++){
            int k = 0;
            for(int j = i; j<N; j=j+z){
                k += arr[j];
            }
            if(G<k && k<=W){
                G = k;
            }
        }
    }
    return G;
}

int main(){
    int W, n;
    printf("W = ");
    if((scanf("%d", &W) != 1)|| W <= 0){
        printf("Invalid input! Error code: -1\n");
        exit(-1);
    }
    printf("N = ");
    if((scanf("%d", &n) != 1)|| n <= 0){
        printf("Invalid input! Error code: -1\n");
        exit(-1);
    }
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    int U = Handler(n, arr, W);
    printf("max = %d\n", U);
}