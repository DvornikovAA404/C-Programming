#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define M 10000
#ifndef DEBUG
#define DEBUG 0
#endif
#define PRINTD(msg, ...) \
        do { if(DEBUG) fprintf(stderr, "%s\n", msg); } while(0)
#define ARGD(msg, ...) \
        do { if(DEBUG) fprintf(stderr, "[%s] " msg "\n", __FUNCTION__, __VA_ARGS__); } while(0)
#define ARGS(msg, ...) \
        do { if(DEBUG) fprintf(stderr, "%s%c\n", msg, __VA_ARGS__); } while(0)


void show(int *a, int N){
    for(int i = 0; i<N; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
}

int append(int **a, int B, int N){
    *a = realloc(*a, (N+1)*sizeof(int));
    (*a)[N] = B;
    ARGD("APPEND: ", N+1);
    return N+1;
}

int range(int **a, int fst, int lst, int size){
    for(int i = fst; i<lst+1; i++){
        ARGD("I = ", i);
        size = append(a, i, size);
    }
    return size;
}

int Handler(int size, char s[size], int **a){
    int ArrSize=0;
    int cursor=0, lsm=0, r_check = 0;
    int P[2] = {0, 0};
    s[size-1] = ',';
    for(int i = 0; i<size-1; i++){
        if(s[i]=='-'){
            lsm = i;
            int num = 0;
            char g[lsm-cursor];
            for(int j = 0, u = cursor; j<lsm; j++, u++){
                g[j] = s[u];
            }
            num = atoi(g);
            cursor = i+1;
            ARGD("NUM: ", num);
            P[0] = num;
            r_check=1;
        }
        else if(s[i] == ',' || i == size-2){
            lsm = i;
            int num = 0;
            char g[lsm-cursor];
            for(int j = 0, u = cursor; j<lsm; j++, u++){
                g[j] = s[u];
            }
            num = atoi(g);
            cursor = i+1;
            ARGD("NUMB: ", num);
            P[1] = num;
            if(r_check!=1){
                P[0] = num;
            }
            ARGD("FST: ", P[0]);
            ARGD("LST: ", P[1]);
            if(P[1]>=P[0]){
                ArrSize = range(a, P[0], P[1], ArrSize);
                r_check = 0;
                if (DEBUG) printf("\n");
            }
            else{
                if(DEBUG) printf("Err in line %d!\n", __LINE__);
                printf("The first value must be greater than the second!\n");
                PRINTD(" === ERROR CODE: -1 ===");
                exit(-1);
            }
        }
        
    }
    return ArrSize;
}

int main(){
    PRINTD("===CODE RUNNING===", "");
    char S[M];
    int *a = calloc(0, sizeof(int));
    printf("Enter string: ");
    fgets(S, M, stdin);
    printf("Result: ");
    int size = Handler(strlen(S), S, &a);
    ARGD("SIZE = %d %d %d %d", size, 1, 7, 10);
    for(int i=0; i<size; i++){
        printf("%d ", a[i]);
    }
    printf("\n");
    PRINTD("Code: 0");
    
    free(a);
}