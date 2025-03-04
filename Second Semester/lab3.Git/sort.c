#include <stdio.h>

int Selection(int N, int Arr[N]){
    for(int i = 0; i < N; i++){
        int min = 0;
        int mind = 0;
        for(int j = i; j < N; j++){
            if(Arr[j].total > min){
                min = Arr[j].total;
                mind = j;
                int buffer = Arr[i];
                Arr[i] = Arr[j];
                Arr[j] = buffer;
            }
        }
    }
}

int main(){
    int a[3] = {4, 0};
    Selection(3, Arr);
}