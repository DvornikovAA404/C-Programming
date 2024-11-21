#include <stdio.h>
<<<<<<< HEAD
<<<<<<< HEAD
#include "t_head.h"


=======
#include <math.h>
#include <stdlib.h>
=======
#include "t_head.h"
>>>>>>> 58b6079 (lab10 completed)


<<<<<<< HEAD
void ent_point(struct point *A){
    float X, Y, Z;
    printf("X = ");
    if (scanf("%f", &X) != 1){
        printf("Invalid value!\n");
        exit(-1);
    }
    printf("Y = ");
    if (scanf("%f", &Y) != 1){
        printf("Invalid value!\n");
        exit(-1);
    }
    printf("Z = ");
    if (scanf("%f", &Z) != 1){
        printf("Invalid value!\n");
        exit(-1);
    }
    A->x = X;
    A->y = Y;
    A->z = Z;
}

void print_point(struct point x){
    printf("( %.2f, %.2f, %.2f )\n", x.x, x.y, x.z);
}

float Distance(struct point A, struct point B){
    return sqrt(pow((A.x-B.x), 2)+pow((A.y-B.y), 2)+pow((A.z-B.z), 2));
}
>>>>>>> 654face (lab10 in progress)
=======
>>>>>>> 58b6079 (lab10 completed)

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