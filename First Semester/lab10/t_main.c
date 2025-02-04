#include <stdio.h>
#include "t_head.h"



int main(){
    struct point A;
    struct point B;
    printf("A: \n");
    ent_point(&A);
    printf("B: \n");
    ent_point(&B);
    print_point(A);
    print_point(B);
    printf("Distance = %.3f\n", Distance(A, B));
}