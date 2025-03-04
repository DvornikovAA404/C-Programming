#ifndef FUNC
#define FUNC

#include <math.h>
#include <stdlib.h>

struct point{
        float x;
        float y;
        float z;
};

void ent_point(struct point *A);
void print_point(struct point x);
float Distance(struct point A, struct point B);

#endif