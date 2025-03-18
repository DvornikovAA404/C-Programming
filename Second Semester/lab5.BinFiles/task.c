#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Worker {
    char fio[20];
    char number[20];
    int bd[3];
};

typedef struct Worker Worker;

void enter(int N, Worker A[N]){
    char recording[2048];
    FILE *out = fopen("Worker.dat", "w");
    for(int i = 0; i<N; i++){

        strcat(recording, A[i].fio);
        strcat(recording, A[i].number);

        fwrite(recording, sizeof recording, sizeof(recording), out);
    }
    fclose(out);
}

void reading(){
    FILE *in = fopen("Worker.dat", "r");
    while(in){
        char data[20] = fgets(in, 20, data);
    }
}

int main(){
    int N = 1;
    Worker Team[N];
    memcpy(Team[0].fio, "ABCD", sizeof(char)*20);
    memcpy(Team[0].number, "+7xxxxxxxxx", sizeof(char)*20);
    Team[0].number[0] = 12;
    Team[0].number[1] = 2;
    Team[0].number[2] = 2002;

    enter(N, Team);
}
